#include "som_c.h"

/* C02AFA long_call_native_menu_actor_text_and_palette   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/long_call_native_menu_actor_text_and_palette.s
 * Documented in docs/settings-actor-text-bridge.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCZV.
 */
static void long_call_native_menu_actor_text_and_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x2AFC, 0xC02082); /* publish_native_menu_actor_text_and_palette */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC02AFA, SOM_RTL, "gen", long_call_native_menu_actor_text_and_palette, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 4, 2)
