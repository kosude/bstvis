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

#include <stdio.h>

/**
 * @brief Entrypoint function.
 *
 */
int main(void) {
    printf("\n==== BSTvis ========================================================= START ====\n");

    visUserMode userMode;

    while ((userMode = visEnumerateUserMode(visPromptUserMode())) != VIS_USER_MODE_QUIT) {
        switch (userMode) {
            case VIS_USER_MODE_NONE:
                printf("Invalid input\n");
                continue;
            default:
                continue;
        }
    }

    printf("\n==== BSTvis =========================================================== END ====\n\n");
    return 0;
}
