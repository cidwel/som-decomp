#include "som_c.h"

/* C30004 audio_command_sender_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/audio_command_sender_public_jump.s
 * Documented in docs/graphics.md
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCZNV.
 */
static void audio_command_sender_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    TAIL_CALL(c, 0xC30160, SOM_RTL); /* audio_command_sender_save_dispatch_restore */
}
SOM_REGISTER(0xC30004, SOM_RTL, "gen", audio_command_sender_public_jump, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, -1, 3, 1)
