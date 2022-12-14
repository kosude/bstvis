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

#include "tree.h"
#include "bstvis.h"

#include "ascii.h"

#include <stdio.h>

/**
 * @brief The binary search tree to be visualised.
 *
 */
static bvNode *tree = NULL;

void visInsert(int *entries, unsigned int count) {
    for (unsigned int i = 0; i < count; i++) {
        tree = bvInsertValue(tree, entries[i]);
    }

    printf(" | Entry insertion successful\n");
}

void visView(void) {
    printf("\n");

    if (!tree) {
        printf(" | No entries yet!\n");
        return;
    }

    visPrintTree(tree);
}

void visClean(void) {
    bvDeleteNode(tree);
}
