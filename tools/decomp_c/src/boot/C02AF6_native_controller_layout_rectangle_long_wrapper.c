#include "som_c.h"

/* C02AF6 native_controller_layout_rectangle_long_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/native_controller_layout_rectangle_long_wrapper.s
 * Documented in docs/ui-native-controller-layout.md
 * Entry: M=8 bit X=16 bit DB=$C7 D=$0000.  Callers read: BYCV.
 */
static void native_controller_layout_rectangle_long_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0xC7, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x2AF8, 0xC02697); /* consume_native_menu_rectangle_76f5 */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC02AF6, SOM_RTL, "gen", native_controller_layout_rectangle_long_wrapper, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
