#include "som_c.h"

/* C06400 forward_native_menu_state_initialization   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/forward_native_menu_state_initialization.s
 * Documented in docs/event-menu-state-api.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void forward_native_menu_state_initialization(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC06433, SOM_RTL); /* initialize_native_menu_hero_categories_with_saved_context */
}
SOM_REGISTER(0xC06400, SOM_RTL, "gen", forward_native_menu_state_initialization, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 3, 1)
