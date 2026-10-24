#include "som_c.h"

/* 7EB96B restore_stopped_first_warm_scene_worker   [class A, 15 bytes, 12 instructions]
 * Source: src/boot/restore_stopped_first_warm_scene_worker.s
 * Documented in docs/boot-native-warm-integrated-runtime.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void restore_stopped_first_warm_scene_worker(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    SET_A8(r, 0x7F);
    r->z = dp == 0;
    r->n = dp & 0x8000;
    RETURN_RTL(c);
}
SOM_REGISTER(0x7EB96B, SOM_RTL, "gen", restore_stopped_first_warm_scene_worker, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 15, 12)
