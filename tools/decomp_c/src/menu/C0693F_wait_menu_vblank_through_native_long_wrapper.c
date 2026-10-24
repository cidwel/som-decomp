#include "som_c.h"

/* C0693F wait_menu_vblank_through_native_long_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/wait_menu_vblank_through_native_long_wrapper.s
 * Documented in docs/event-menu-vblank.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void wait_menu_vblank_through_native_long_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x6941, 0xC06943); GUARD_JSR(c, sp_call, 0x6941); } /* await_vblank_edge_and_run_complete_menu_text_frame */
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0693F, SOM_RTL, "gen", wait_menu_vblank_through_native_long_wrapper, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 4, 2)
