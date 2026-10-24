#include "som_c.h"

/* C2310A request_audio_macro_eighty_with_operand_byte   [class A, 19 bytes, 7 instructions]
 * Source: src/rom/request_audio_macro_eighty_with_operand_byte.s
 * Documented in docs/audio-native-callers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void request_audio_macro_eighty_with_operand_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x1E01) = a;
    RAM8(0x1E00) = 0x80;
    r->a = (a_hi << 8) | 0x80;
    r->z = 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x3119, 0xC30004); GUARD_JSL(c, sp_call, 0x3119); } /* audio_command_sender_public_jump */
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2310A, SOM_RTS, "gen", request_audio_macro_eighty_with_operand_byte, 0, 0, 1, 1, 0, 19, 7)
