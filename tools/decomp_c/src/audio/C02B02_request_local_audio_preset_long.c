#include "som_c.h"

/* C02B02 request_local_audio_preset_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/request_local_audio_preset_long.s
 * Documented in docs/audio-native-wrappers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void request_local_audio_preset_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x2B04, 0xC029D2); /* expand_local_audio_preset_and_send_four_byte_request */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC02B02, SOM_RTL, "gen", request_local_audio_preset_long, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
