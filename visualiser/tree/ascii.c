// -----------------------------------------------------------------------------
// Copyright (c) 2022 Jack Bennett
// -----------------------------------------------------------------------------
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY  KIND,  EXPRESS  OR
// IMPLIED, INCLUDING BUT NOT LIMITED  TO  THE  WARRANTIES  OF  MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT  SHALL  THE
// AUTHORS OR COPYRIGHT HOLDERS BE  LIABLE  FOR  ANY  CLAIM,  DAMAGES  OR  OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// -----------------------------------------------------------------------------

#include "ascii.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// BST ASCII printing adapted from http://www.openasthra.com/c-tidbits/printing-binary-trees-in-ascii/.
// (The link is very old, so see http://web.archive.org/web/20090617110918/http://www.openasthra.com/c-tidbits/printing-binary-trees-in-ascii/)
// Linked from https://stackoverflow.com/a/801794/12980669

/**
 * @brief Gap between left and right nodes
 *
 */
#define PRINT_GAP 3

/**
 * @brief Maximum height to visualise binary search tree
 *
 */
#define MAX_HEIGHT 1000

/**
 * @brief A high number
 *
 */
#define INFINITY (1 << 20)

/**
 * @brief Counter used for printing the next node in the same level.
 *
 * This is the X coordinate of the next char to be printed.
 *
 */
static int printNext;

/**
 * @brief These variables do something important, I have no idea what. (5)
 *
 */
static int lProfile[MAX_HEIGHT];
static int rProfile[MAX_HEIGHT];

/**
 * @brief Return the lower of the two arguments
 *
 * @param x Argument 1
 * @param y Argument 2
 * @return Lower argument
 *
 */
static int Min(int x, int y) {
    return (x < y) ? x : y;
}

/**
 * @brief Return the higher of the two arguments
 *
 * @param x Argument 1
 * @param y Argument 2
 * @return Higher argument
 *
 */
static int Max(int x, int y) {
    return (x > y) ? x : y;
}

visAsciiNode *visBuildAsciiNode(bvNode *node, int root) {
    if (!node) {
        return NULL;
    }

    visAsciiNode *r = malloc(sizeof(visAsciiNode));
    r->left = visBuildAsciiNode(node->left, 0);
    r->right = visBuildAsciiNode(node->right, 0);

    if (r->left) {
        r->left->parentDir = -1;
    }

    if (r->right) {
        r->right->parentDir = 1;
    }

    sprintf(r->label, "%d", node->value);
    r->lablen = strlen(r->label);

    if (root) {
        r->parentDir = 0;
    }

    return r;
}

void visDeleteAsciiNode(visAsciiNode *node) {
    if (!node) {
        return;
    }

    visDeleteAsciiNode(node->left);
    visDeleteAsciiNode(node->right);

    free(node);
}

void visComputeLProfile(visAsciiNode *node, int x, int y) {
    if (!node) {
        return;
    }

    // is the given node on the left side of its parent?
    int isLeft = (node->parentDir == -1);

    lProfile[y] = Min(lProfile[y], x - ((node->lablen - isLeft) / 2));

    if (node->left) {
        for (int i = 1; i < node->edgeLength && y + i < MAX_HEIGHT; i++) {
            lProfile[y + i] = Min(lProfile[y + i], x - i);
        }
    }

    visComputeLProfile(
        node->left,
        x - node->edgeLength - 1,
        y + node->edgeLength + 1
    );

    visComputeLProfile(
        node->right,
        x + node->edgeLength + 1,
        y + node->edgeLength + 1
    );
}

void visComputeRProfile(visAsciiNode *node, int x, int y) {
    if (!node) {
        return;
    }

    // is the given node NOT on the left side of its parent?
    int notLeft = (node->parentDir != -1);

    rProfile[y] = Max(rProfile[y], x + ((node->lablen - notLeft) / 2));

    if (node->right) {
        for (int i = 1; i < node->edgeLength && y + i < MAX_HEIGHT; i++) {
            rProfile[y + i] = Max(rProfile[y + i], x + i);
        }
    }

    visComputeRProfile(
        node->left,
        x - node->edgeLength - 1,
        y + node->edgeLength + 1
    );

    visComputeRProfile(
        node->right,
        x + node->edgeLength + 1,
        y + node->edgeLength + 1
    );
}

void visComputeAsciiEdgeLengths(visAsciiNode *node) {
    if (!node) {
        return;
    }

    visComputeAsciiEdgeLengths(node->left);
    visComputeAsciiEdgeLengths(node->right);

    // fill in the edge length of the node...

    int hMin;
    int delta;

    if (!node->right && !node->left) {
        node->edgeLength = 0;
    } else {
        if (node->left) {
            for (int i = 0; i < node->left->height && i < MAX_HEIGHT; i++) {
                rProfile[i] = -INFINITY;
            }

            visComputeRProfile(node->left, 0, 0);
            hMin = node->left->height;
        } else {
            hMin = 0;
        }

        if (node->right) {
            for (int i = 0; i < node->right->height && i < MAX_HEIGHT; i++) {
                lProfile[i] = INFINITY;
            }

            visComputeLProfile(node->right, 0, 0);
            hMin = Min(node->right->height, hMin);
        } else {
            hMin = 0;
        }

        delta = 4;

        for (int i = 0; i < hMin; i++) {
            delta = Max(delta, PRINT_GAP + 1 + rProfile[i] - lProfile[i]);
        }

        // if the node has two children of height 1 then we allow the two
        // leaves to be within 1 instead of 2
        if (((node->left && node->left->height == 1) || (node->right && node->right->height == 1)) && delta > 4) {
            delta--;
        }

        node->edgeLength = ((delta + 1) / 2) - 1;
    }

    // now fill in the height of the node ...

    int h = 1;

    if (node->left) {
        h = Max(h, node->left->height + node->edgeLength + 1);
    }
    if (node->right) {
        h = Max(h, node->right->height + node->edgeLength + 1);
    }

    node->height = h;
}

void visPrintLevel(visAsciiNode *node, int x, int level) {
    if (!node) {
        return;
    }

    int i = 0;

    // is the given node on the left side of its parent?
    int isLeft = (node->parentDir == -1);

    if (level == 0) {
        // print spacing
        for (i = 0; i < (x - printNext - ((node->lablen - isLeft) / 2)); i++) {
            printf(" ");
        }

        // print the node label, keeping the next's X coordinate updated
        printNext += i;
        printf("%s", node->label);
        printNext += node->lablen;
    } else if (node->edgeLength >= level) {
        if (node->left) {
            // spacing
            for (i = 0; i < (x - printNext - level); i++) {
                printf(" ");
            }

            // since the node is on the left, we print a line (forward slash).
            // we keep the next's X coordinate updated
            printNext += i;
            printf("/");
            printNext++;
        }
        if (node->right) {
            // spacing
            for (i = 0; i < (x - printNext + level); i++) {
                printf(" ");
            }

            // since the node is on the left, we print a line (backslash).
            // we keep the next's X coordinate updated
            printNext += i;
            printf("\\");
            printNext++;
        }
    } else {
        visPrintLevel(
            node->left,
            x - node->edgeLength - 1,
            level - node->edgeLength - 1
        );

        visPrintLevel(
            node->right,
            x + node->edgeLength + 1,
            level - node->edgeLength - 1
        );
    }
}

void visPrintTree(bvNode *node) {
    if (!node) {
        return;
    }

    // build ascii tree and compute its display values
    visAsciiNode *ascii = visBuildAsciiNode(node, 1);
    visComputeAsciiEdgeLengths(ascii);

    for (int i = 0; i < ascii->height && i < MAX_HEIGHT; i++) {
        lProfile[i] = INFINITY;
    }

    visComputeLProfile(ascii, 0, 0);

    int xMin = 0;
    for (int i = 0; i < ascii->height && i < MAX_HEIGHT; i++) {
        xMin = Min(xMin, lProfile[i]);
    }

    // print each level of the tree
    for (int i = 0; i < ascii->height; i++) {
        printNext = 0;

        printf(" | ");
        visPrintLevel(ascii, -xMin, i);

        printf("\n");
    }

    if (ascii->height >= MAX_HEIGHT) {
        printf(" | This tree is taller than %d and so it may be drawn incorrectly.\n", MAX_HEIGHT);
    }

    visDeleteAsciiNode(ascii);
}
