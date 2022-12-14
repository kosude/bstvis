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
#ifndef __VIS_TREE_H
#define __VIS_TREE_H

/**
 * @brief Insert the given values into the binary search tree.
 *
 * @param entries the entry array to insert
 * @param count the amount of entries in array `entries`
 *
 */
void visInsert(int *entries, unsigned int count);

/**
 * @brief Display the contents of the binary search tree.
 *
 */
void visView(void);

/**
 * @brief Deallocate the binary search tree.
 *
 */
void visClean(void);

#endif // __VIS_TREE_H
