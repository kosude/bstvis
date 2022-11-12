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

#include "../control/control.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char visPromptUserMode(void) {
    // print dialogue message
    printf(""
        "\n | Select user mode"
        "\n |     (i): Insert an entry into the binary search tree"
        "\n |     (q): Quit the program"
        "\n |   > ");

    char line[4096];

    // get user input and check if it is EOF
    // if it is then 'q' is returned to quit the application
    if (!fgets(line, sizeof(line), stdin)) {
        visQuit();
        return '\0';
    }

    // parse the user input into the resultant variable r
    char r;
    sscanf(line, "%c", &r);

    return r;
}

int *visPromptEntryInsertion(unsigned int *countOut) {
    // print dialogue message
    printf(""
        "\n | Input entries to INSERT, or leave input empty to finish:"
        "\n");

    char line[4096];

    // resultant array elements and size
    int r[256];
    unsigned int count = 0;

    while (1) {
        // if count has exceded the allocated size of the array then exit insertion mode
        if (count >= 256) {
            break;
        }

        printf(" |  > ");

        // get user input
        if (!fgets(line, sizeof(line), stdin)) {
            visQuit();
            return NULL;
        }

        // if input is empty then exit insertion mode
        if (!strcmp(line, "\n")) {
            break;
        }

        // parse the user input
        int entry;
        if (!sscanf(line, "%d", &entry)) {
            // if the input is not a numerical value then notify the user and skip it
            printf("Non-numerical value; skipped\n");
            continue;
        }

        // append the entry to the array's contents
        r[count] = entry;
        count++;
    }

    // allocate the resultant array based on now-recieved contents and size
    int *r_alloc = malloc(sizeof(int) * count);
    for (unsigned int i = 0; i < count; i++) {
        r_alloc[i] = r[i];
    }

    // return count if applicable
    if (countOut) {
        *countOut = count;
    }

    return r_alloc;
}
