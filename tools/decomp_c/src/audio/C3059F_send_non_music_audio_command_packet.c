#include "som_c.h"

/* C3059F send_non_music_audio_command_packet   [class D, 64 bytes, 30 instructions]
 * Source: src/rom/send_non_music_audio_command_packet.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$1E00.  Callers read: ABXYCZNV.
 */
static void send_non_music_audio_command_packet(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x1E00) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    BUS8_SET(c, 0x002143, RAM8(0x1E03));
    BUS8_SET(c, 0x002142, RAM8(0x1E02));
    uint8_t value3 = RAM8(0x1E01);
    BUS8_SET(c, 0x002141, value3);
    for (;;) {
        uint8_t value4 = BUS8(c, 0x002140);
        if (!(a == value4)) break;
    }
    BUS8_SET(c, 0x002140, a);
    uint8_t a_hi2;
    uint16_t x3;
    if (a < 0xF0) {
        a_hi2 = value3;
        x3 = x;
    } else {
        uint8_t a_hi1;
        uint16_t x2;
        if (a >= 0xF2) {
            a_hi1 = value3;
            x2 = x;
        } else {
            uint8_t value5 = RAM8(0x1E05);
            uint16_t x1;
            if (value5 & 0x80) {
                x1 = x;
            } else {
                RAM8(0x1E09) = value5;
                uint16_t value6 = RAM16(0x1E06);
                RAM16_SET(0x1E0A, value6);
                x1 = value6;
            }
            RAM8(0x1E05) = 0xFF;
            a_hi1 = 0xFF;
            x2 = x1;
        }
        a_hi2 = a_hi1;
        x3 = x2;
    }
    bool carry1 = 0;
    for (;;) {
        uint8_t value7 = BUS8(c, 0x002140);
        carry1 = a >= value7;
        if (!(a != value7)) break;
    }
    BUS8_SET(c, 0x002140, 0);
    r->a = (a_hi2 << 8) | 0;
    r->x = x3;
    r->y = y;
    r->c = carry1;
    r->z = 1;
    r->n = 0;
    r->v = overflow;
    TAIL_CALL(c, 0xC3018D, SOM_RTS); /* external */
}
SOM_REGISTER(0xC3059F, SOM_RTS, "gen", send_non_music_audio_command_packet, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 64, 30)
