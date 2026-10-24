#include "som_c.h"

/* C0008C forward_saved_game_menu_request_to_saved_word_entry   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/forward_saved_game_menu_request_to_saved_word_entry.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=16 bit X=8 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void forward_saved_game_menu_request_to_saved_word_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC000BA, SOM_RTL); /* save_incoming_menu_word_and_open_native_save_page */
}
SOM_REGISTER(0xC0008C, SOM_RTL, "gen", forward_saved_game_menu_request_to_saved_word_entry, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 1, 3, 1)
