#include "som_c.h"

/* C02AC7 reset_native_menu_publication_long_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/reset_native_menu_publication_long_wrapper.s
 * Documented in docs/ui-native-name-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: B.
 */
static void reset_native_menu_publication_long_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x2AC9, 0xC01F88); /* reset_native_menu_publication_and_scroll_state */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC02AC7, SOM_RTL, "gen", reset_native_menu_publication_long_wrapper, 0, L_B, 1, 1, 0, 4, 2)
