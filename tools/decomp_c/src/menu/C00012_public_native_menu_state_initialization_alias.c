#include "som_c.h"

/* C00012 public_native_menu_state_initialization_alias   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/public_native_menu_state_initialization_alias.s
 * Documented in docs/event-menu-state-api.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void public_native_menu_state_initialization_alias(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC06400, SOM_RTL); /* forward_native_menu_state_initialization */
}
SOM_REGISTER(0xC00012, SOM_RTL, "gen", public_native_menu_state_initialization_alias, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 3, 1)
