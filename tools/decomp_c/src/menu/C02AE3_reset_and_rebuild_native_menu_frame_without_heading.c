#include "som_c.h"

/* C02AE3 reset_and_rebuild_native_menu_frame_without_heading   [class A, 7 bytes, 3 instructions]
 * Source: src/rom/reset_and_rebuild_native_menu_frame_without_heading.s
 * Documented in docs/ui-native-spell-item-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BY.
 */
static void reset_and_rebuild_native_menu_frame_without_heading(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0xA200) = 0;
    JSR(c, 0x2AE8, 0xC021F9); /* external */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC02AE3, SOM_RTL, "gen", reset_and_rebuild_native_menu_frame_without_heading, 0, L_B | L_Y, 1, 1, 0, 7, 3)
