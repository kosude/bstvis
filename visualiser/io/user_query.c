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

#include "user_query.h"

#include <stdio.h>

char visPromptUserMode(void) {
    // print dialogue message
    printf(""
        "\n | Select user mode"
        "\n |     (i): Insert an entry into the binary search tree"
        "\n |     (q): Quit the program"
        "\n |   > ");

    // get user input
    char line[4096];

    // check if input is EOF
    // if it is then 'q' is returned to quit the application
    if (!fgets(line, sizeof(line), stdin)) {
        printf("\n"); // newline so PS1 is on a new line
        return 'q';
    }

    // parse the user input into the resultant variable r
    char r;
    sscanf(line, "%c", &r);

    return r;
}
