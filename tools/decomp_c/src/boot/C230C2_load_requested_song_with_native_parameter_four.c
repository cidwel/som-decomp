#include "som_c.h"

/* C230C2 load_requested_song_with_native_parameter_four   [class A, 33 bytes, 13 instructions]
 * Source: src/rom/load_requested_song_with_native_parameter_four.s
 * Documented in docs/boss-native-alternate-death.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: BYV.
 */
static void load_requested_song_with_native_parameter_four(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t a = r->a;
    RAM8(0x1E00) = 1;
    RAM8(0x1E01) = (uint8_t)a;
    RAM8(0x1E02) = 4;
    RAM8(0x1E03) = 0x0F;
    r->a = 0x010F;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x30DF, 0xC30004); GUARD_JSL(c, sp_call, 0x30DF); } /* audio_command_sender_public_jump */
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC230C2, SOM_RTS, "gen", load_requested_song_with_native_parameter_four, 0, L_B | L_Y | L_V, 1, -1, 0, 33, 13)
