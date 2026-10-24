#include "som_c.h"

/* C00FD5 request_audio_macro_eighty_with_parameter_thirty_two   [class A, 12 bytes, 4 instructions]
 * Source: src/rom/request_audio_macro_eighty_with_parameter_thirty_two.s
 * Documented in docs/audio-native-wrappers.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void request_audio_macro_eighty_with_parameter_thirty_two(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x1E00, 0x2080);
    r->a = 0x2080;
    r->z = 0;
    r->n = 0;
    JSL(c, 0x0FDF, 0xC30004); /* audio_command_sender_public_jump */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00FD5, SOM_RTS, "gen", request_audio_macro_eighty_with_parameter_thirty_two, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 12, 4)
