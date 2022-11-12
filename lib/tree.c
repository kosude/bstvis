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

#include "bstvis.h"

#include <stdlib.h>

bvNode *bvCreateNode(BV_TREE_VALUE_TYPE value) {
    bvNode *r = malloc(sizeof(bvNode));

    r->value = value;
    r->left = NULL;
    r->right = NULL;

    return r;
}

bvNode *bvInsertValue(bvNode *node, BV_TREE_VALUE_TYPE value) {
    // if the tree is empty then create a new node
    if (!node) {
        return bvCreateNode(value);
    }

    // if value is below the node value
    if (value < node->value) {
        node->left = bvInsertValue(node->left, value);
    } else if (value > node->value) {
        node->right = bvInsertValue(node->right, value);
    }

    return node;
}
