#include "som_c.h"

/* C000BA save_incoming_menu_word_and_open_native_save_page   [class A, 15 bytes, 6 instructions]
 * Source: src/rom/save_incoming_menu_word_and_open_native_save_page.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=16 bit X=8 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void save_incoming_menu_word_and_open_native_save_page(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    RAM16_SET(0xA25A, a);
    r->a = 7;
    TAIL_CALL(c, 0xC01D97, SOM_RTL); /* run_native_menu_coordinator_before_exceptional_callback */
}
SOM_REGISTER(0xC000BA, SOM_RTL, "gen", save_incoming_menu_word_and_open_native_save_page, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 1, 15, 6)
