#include "som_c.h"

/* C230FD request_boss_audio_command_byte   [class A, 13 bytes, 5 instructions]
 * Source: src/rom/request_boss_audio_command_byte.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void request_boss_audio_command_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint8_t a = r->a & 0xFF;
    RAM8(0x1E00) = a;
    { const uint16_t sp_call = r->sp; JSL(c, 0x3106, 0xC30004); GUARD_JSL(c, sp_call, 0x3106); } /* audio_command_sender_public_jump */
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC230FD, SOM_RTS, "gen", request_boss_audio_command_byte, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 13, 5)
