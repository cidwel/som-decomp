#include "som_c.h"

/* C01F88 reset_native_menu_publication_and_scroll_state   [class A, 15 bytes, 7 instructions]
 * Source: src/rom/reset_native_menu_publication_and_scroll_state.s
 * Documented in docs/event-menu-controller.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: B.
 */
static void reset_native_menu_publication_and_scroll_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0xA20A) &= 0x7F;
    RAM8(0xA20C) = 0;
    RAM8(0xA201) = 0;
    r->a = (r->a & 0x00FF) | (0 << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01F88, SOM_RTS, "gen", reset_native_menu_publication_and_scroll_state, 0, L_B, 1, 1, 0, 15, 7)
