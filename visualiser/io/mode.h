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
#ifndef __VIS_MODE_H
#define __VIS_MODE_H

/**
 * @brief Enumerator containing possible user modes of command.
 *
 */
typedef enum visUserMode {
    VIS_USER_MODE_INSERT    = 0x01,
    VIS_USER_MODE_VIEW      = 0x02,
    VIS_USER_MODE_QUIT      = 0xFF,

    VIS_USER_MODE_NONE      = 0x00
} visUserMode;

/**
 * @brief Convert from the given user mode character to its respective enumerator.
 *
 * @param mode Mode to convert as a character (e.g. 'i' = INSERT)
 * @return Respective visUserMode entry.
 *
 */
visUserMode visEnumerateUserMode(const char mode);

#endif // __VIS_MODE_H
