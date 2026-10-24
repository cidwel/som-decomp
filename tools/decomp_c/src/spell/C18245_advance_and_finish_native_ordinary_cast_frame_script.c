#include "som_c.h"

/* C18245 advance_and_finish_native_ordinary_cast_frame_script   [class A, 9 bytes, 4 instructions]
 * Source: src/rom/advance_and_finish_native_ordinary_cast_frame_script.s
 * Documented in docs/actor-visual-effect-scripts.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void advance_and_finish_native_ordinary_cast_frame_script(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x8247, 0xC18276); /* consume_native_visual_frame_script_pose_or_terminator */
    bool carry_ret = r->c;
    if (carry_ret) {
        r->mf = 1;
        r->xf = 0;
        TAIL_CALL(c, 0xC18775, SOM_RTS); /* execute_ordinary_actor_cast_presentation */
    }
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC18245, SOM_RTS, "gen", advance_and_finish_native_ordinary_cast_frame_script, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 9, 4)
