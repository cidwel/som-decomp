#include "som_c.h"

/* C3067E transfer_fixed_extra_music_data_to_apu_address_2c00   [class D, 74 bytes, 35 instructions]
 * Source: src/rom/transfer_fixed_extra_music_data_to_apu_address_2c00.s
 * Documented in docs/boss-native-music-dependencies.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: AB.
 */
static void transfer_fixed_extra_music_data_to_apu_address_2c00(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM16_SET(0x2142, 0x2C00);
    RAM8(0x2140) = a_hi;
    for (;;) {
        if (!(a_hi != RAM8(0x2140))) break;
    }
    uint8_t value2 = BUS8(c, 0xC32137);
    RAM8(0x0310) = value2;
    uint8_t value3 = BUS8(c, 0xC32138);
    RAM8(0x0311) = value3;
    uint8_t a_hi1 = (uint8_t)(a_hi + 1);
    uint16_t x1 = 0;
    for (;;) {
        uint8_t value4 = BUS8(c, 0xC32139 + x1);
        RAM8(0x2142) = value4;
        uint8_t value5 = BUS8(c, 0xC3213A + x1);
        RAM8(0x2143) = value5;
        RAM8(0x2140) = a_hi1;
        for (;;) {
            if (!(a_hi1 != RAM8(0x2140))) break;
        }
        uint8_t a1;
        if ((uint8_t)(a_hi1 + 1) != 0) {
            a1 = (uint8_t)(a_hi1 + 1);
        } else {
            a1 = (uint8_t)(a_hi1 + 2);
        }
        uint16_t value7 = RAM16(0x0310);
        a_hi1 = a1;
        x1 = (uint16_t)(x1 + 2);
        if (!(x1 != value7)) break;
    }
    r->a = a_hi1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC3067E, SOM_RTS, "gen", transfer_fixed_extra_music_data_to_apu_address_2c00, 0, L_A | L_B, 1, 1, 0, 74, 35)
