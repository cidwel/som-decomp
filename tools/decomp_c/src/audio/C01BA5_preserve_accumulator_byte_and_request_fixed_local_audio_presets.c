#include "som_c.h"

/* C01BA5 preserve_accumulator_byte_and_request_fixed_local_audio_presets   [class C, 18 bytes, 11 instructions]
 * Source: src/rom/preserve_accumulator_byte_and_request_fixed_local_audio_presets.s
 * Documented in docs/audio-native-wrappers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void preserve_accumulator_byte_and_request_fixed_local_audio_presets(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 6;
    r->sp -= 1;
    JSR(c, 0x1BB4, 0xC029D2); /* expand_local_audio_preset_and_send_four_byte_request */
    r->sp += 1;
    SET_A8(r, a);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01BA5, SOM_RTS, "gen", preserve_accumulator_byte_and_request_fixed_local_audio_presets, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 18, 11)
