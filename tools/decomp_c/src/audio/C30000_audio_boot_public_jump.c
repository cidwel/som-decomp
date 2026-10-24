#include "som_c.h"

/* C30000 audio_boot_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/audio_boot_public_jump.s
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCZNV.
 */
static void audio_boot_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    TAIL_CALL(c, 0xC3002C, SOM_RTL); /* upload_six_spc_blocks_or_reset_ready_audio_metadata */
}
SOM_REGISTER(0xC30000, SOM_RTL, "gen", audio_boot_public_jump, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, -1, 3, 1)
