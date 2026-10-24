#include "som_c.h"

/* C02BEA adjust_native_selector_component_zero   [class C, 17 bytes, 7 instructions]
 * Source: src/rom/adjust_native_selector_component_zero.s
 * Documented in docs/ui-native-settings-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void adjust_native_selector_component_zero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->y = 0;
    JSR(c, 0x2BF9, 0xC02BBA); /* adjust_native_three_component_selector_from_current_left_right */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02BEA, SOM_RTS, "gen", adjust_native_selector_component_zero, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 17, 7)
