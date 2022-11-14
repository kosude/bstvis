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

#include "io/mode.h"
#include "io/user_query.h"
#include "control/control.h"
#include "tree/tree.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Entrypoint function.
 *
 */
int main(void) {
    visPrintOpener();

    visUserMode userMode;

    while (1) {
        // get user mode
        userMode = visEnumerateUserMode(visPromptUserMode());

        switch (userMode) {
            // used in INSERT mode
            int *entryInsertArray;
            unsigned int entryInsertCount;

            case VIS_USER_MODE_NONE:
                printf(" | Invalid input\n");

                continue;

            case VIS_USER_MODE_INSERT:
                // get entry or entries to insert
                entryInsertArray = visPromptEntryInsertion(&entryInsertCount);

                visInsert(entryInsertArray, entryInsertCount);

                free(entryInsertArray);
                entryInsertArray = NULL;

                continue;

            case VIS_USER_MODE_VIEW:
                visView();

                continue;

            case VIS_USER_MODE_QUIT:
                break;

            default:
                continue;
        }

        break;
    }
    visClean();
    
    visPrintCloser(0);
    return 0;
}
