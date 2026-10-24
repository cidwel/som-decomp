#include "som_c.h"

/* C068EA open_native_menu_ring_and_wait_for_phase_zero_public   [class A, 7 bytes, 3 instructions]
 * Source: src/rom/open_native_menu_ring_and_wait_for_phase_zero_public.s
 * Documented in docs/event-menu-ring-waits.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXY.
 */
static void open_native_menu_ring_and_wait_for_phase_zero_public(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x68EC, 0xC06906); /* request_native_menu_ring_open_and_build_selected_list */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x68EF, 0xC068F1); /* advance_native_menu_ring_frames_until_phase_zero */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC068EA, SOM_RTL, "gen", open_native_menu_ring_and_wait_for_phase_zero_public, 0, L_A | L_B | L_X | L_Y, 1, 0, 0, 7, 3)
