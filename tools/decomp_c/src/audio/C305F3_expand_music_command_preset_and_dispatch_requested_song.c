#include "som_c.h"

/* C305F3 expand_music_command_preset_and_dispatch_requested_song   [class A, 23 bytes, 10 instructions]
 * Source: src/rom/expand_music_command_preset_and_dispatch_requested_song.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void expand_music_command_preset_and_dispatch_requested_song(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint16_t value = BUS16(c, 0xC306CA + ((((a_hi << 8) | a) & 0x0F) << 1 << 1));
    BUS16_SET(c, (uint16_t)(dp + 2), value);
    uint16_t value2 = BUS16(c, 0xC306C8 + ((((a_hi << 8) | a) & 0x0F) << 1 << 1));
    BUS16_SET(c, dp, value2);
    r->a = value2;
    r->x = (((a_hi << 8) | a) & 0x0F) << 1 << 1;
    r->c = (((a_hi << 8) | a) & 0x0F) << 1 & 0x8000;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0;
    TAIL_CALL(c, 0xC30175, SOM_RTS); /* external */
}
SOM_REGISTER(0xC305F3, SOM_RTS, "gen", expand_music_command_preset_and_dispatch_requested_song, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 23, 10)
