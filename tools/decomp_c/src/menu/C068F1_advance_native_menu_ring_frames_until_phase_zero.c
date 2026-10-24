#include "som_c.h"
#include "som_hand_d.h"
/* The wait routine below may unwind to the caller of this one (task switch): the plain call protocol returns at once, like the CPU. */
#undef JSR
#undef JSL
#define JSR(c, retpc, target) I_JSR((c), (retpc), (target))
#define JSL(c, retpc, target) I_JSL((c), (retpc), (target))

/* C068F1 advance_native_menu_ring_frames_until_phase_zero   [class A, 14 bytes, 6 instructions]
 * Source: src/rom/advance_native_menu_ring_frames_until_phase_zero.s
 * Documented in docs/event-menu-ring-waits.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void advance_native_menu_ring_frames_until_phase_zero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
L_C068F1:;
    JSR(c, 0x68f3, 0xC06943);
    JSR(c, 0x68f6, 0xC06BF8);
    i_rep(r, 0x30);
    LDA(c, ABS, 0x1812);
    if (!r->z) goto L_C068F1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC068F1, SOM_RTS, "hand", advance_native_menu_ring_frames_until_phase_zero, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 14, 6)
