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

#ifndef __BSTVIS_TREE_H
#define __BSTVIS_TREE_H

#include "structs.h"
#include "type.h"

/**
 * @brief Create a new node with the given value
 *
 * @param value The value to store in the returned node.
 * @return The new node
 *
 */
bvNode *bvCreateNode(BV_TREE_VALUE_TYPE value);

/**
 * @brief Creates a new node storing `value` and inserts it into `tree` at the correct position.
 *
 * @param node The tree to update
 * @param value The value to insert
 * @return The unchanged node pointer
 *
 */
bvNode *bvInsertValue(bvNode *node, BV_TREE_VALUE_TYPE value);

#endif // !__BSTVIS_TREE_H
