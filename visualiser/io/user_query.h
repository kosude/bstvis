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
#ifndef __VIS_USER_QUERY_H
#define __VIS_USER_QUERY_H

/**
 * @brief Ask the user to input the user mode to switch to.
 *
 * @return The user's response
 *
 */
char visPromptUserMode(void);

/**
 * @brief Ask the user to input an entry to insert into the tree.
 *
 * This function will allocate the array of integers to be returned.
 *
 * @param countOut the length of the returned array will be returned into this location if it is not NULL.
 *
 * @return The user's response(s)
 *
 */
int *visPromptEntryInsertion(unsigned int *countOut);

#endif // __VIS_USER_QUERY_H
