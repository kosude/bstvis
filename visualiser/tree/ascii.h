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

#pragma once
#ifndef __VIS_ASCII_H
#define __VIS_ASCII_H

#include "bstvis.h"

// BST ASCII printing adapted from http://www.openasthra.com/c-tidbits/printing-binary-trees-in-ascii/.
// (The link is very old, so see http://web.archive.org/web/20090617110918/http://www.openasthra.com/c-tidbits/printing-binary-trees-in-ascii/)
// Linked from https://stackoverflow.com/a/801794/12980669

/**
 * @brief A structure to represent a binary search tree node in ASCII format.
 *
 */
typedef struct visAsciiNode {
    struct visAsciiNode *left;
    struct visAsciiNode *right;

    // length of the edge from this node to its children
    int edgeLength;

    int height;

    // length of the label
    int lablen;

    // -1: I am left
    //  0: I am root
    //  1: I am right
    int parentDir;

    // 10 digits max
    char label[11];
} visAsciiNode;

/**
 * @brief Allocate, build, and return an ASCII representation of the given tree.
 *
 * @param node The tree to copy
 * @param root True if `node` is the root node in the tree, false if otherwise.
 * @return The new ASCII tree structure
 *
 */
visAsciiNode *visBuildAsciiNode(bvNode *node, int root);

/**
 * @brief Recursively deallocates memory allocated for the given node.
 *
 * @param node The node to destroy
 *
 */
void visDeleteAsciiNode(visAsciiNode *node);

/**
 * @brief I don't know what these functions do.
 * I have really tried to understand them but whoever originally wrote this is probably in their 80s now
 *
 */
void visComputeLProfile(visAsciiNode *node, int x, int y);
void visComputeRProfile(visAsciiNode *node, int x, int y);

/**
 * @brief Computes and fills in the edge length and height fields of the given node structure.
 *
 * @param node The node to update.
 *
 */
void visComputeAsciiEdgeLengths(visAsciiNode *node);

/**
 * @brief Print the given level of the given tree
 *
 * @param node The tree to print
 * @param x X coordinate
 * @param level The level of the tree to print
 *
 */
void visPrintLevel(visAsciiNode *node, int x, int level);

/**
 * @brief Print the given tree structure.
 *
 * @param node The tree to print.
 *
 */
void visPrintTree(bvNode *node);

#endif // __VIS_ASCII_H
