#include "som_c.h"

/* C3060A configure_music_echo_and_evict_samples_above_echo_limit   [class D, 116 bytes, 61 instructions]
 * Source: src/rom/configure_music_echo_and_evict_samples_above_echo_limit.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BCV.
 */
static void configure_music_echo_and_evict_samples_above_echo_limit(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = 0;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 2));
    RAM8(0x0000 + sp0 - 2) = (value & 0x0F) << 1 << 1;
    uint8_t value2 = BUS8(c, 0xC30708 + ((value & 0x0F) << 1 << 1));
    BUS8_SET(c, (db << 0x10) + 0x2142, value2);
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp + 0xF0));
    uint8_t a_hi2;
    if (value2 == value3) {
        a_hi2 = a_hi;
    } else {
        BUS8_SET(c, (uint16_t)(dp + 0xF0), value2);
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp + 0xF0));
        uint8_t a1;
        if (value4 != 0) {
            a1 = value4;
        } else {
            a1 = (uint8_t)(value4 + 1);
        }
        BUS8_SET(c, (uint16_t)(dp + 0xF2), (uint8_t)(((uint8_t)(a1 << 3) ^ 0xFF) + 0xFB));
        uint8_t a_hi1 = a_hi;
        uint16_t x1 = 0;
        for (;;) {
            uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 0x4B + x1));
            uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp + 0xF2));
            if (value5 >= value6) {
                uint16_t x2 = x1;
                for (;;) {
                    BUS8_SET(c, (uint16_t)(dp + 0x28 + x2), 0);
                    x2 = (uint16_t)(x2 + 1);
                    if (!(x2 != 0x20)) break;
                }
            } else {
                if ((uint16_t)(x1 + 2) != 0x20) {
                    x1 = (uint16_t)(x1 + 2);
                    continue;
                }
            }
            break;
        }
        a_hi2 = a_hi1;
    }
    uint8_t value7 = BUS8(c, 0xC30709 + ((value & 0x0F) << 1 << 1));
    BUS8_SET(c, (db << 0x10) + 0x2143, value7);
    BUS8_SET(c, (db << 0x10) + 0x2140, a_hi2);
    for (;;) {
        uint8_t value8 = BUS8_RDP(c, (db << 0x10) + 0x2140);
        if (!(a_hi2 != value8)) break;
    }
    uint8_t value9 = BUS8(c, 0xC3070A + ((value & 0x0F) << 1 << 1));
    BUS8_SET(c, (db << 0x10) + 0x2142, value9);
    uint8_t value10 = BUS8(c, 0xC3070B + ((value & 0x0F) << 1 << 1));
    BUS8_SET(c, (db << 0x10) + 0x2143, value10);
    BUS8_SET(c, (db << 0x10) + 0x2140, (uint8_t)(a_hi2 + 1));
    for (;;) {
        uint8_t value11 = BUS8_RDP(c, (db << 0x10) + 0x2140);
        if (!((uint8_t)(a_hi2 + 1) != value11)) break;
    }
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->a = ((uint8_t)(a_hi2 + 2) << 8) | value10;
    r->c = value12 & 0x01;
    r->v = value12 & 0x40;
    r->mf = value12 & 0x20;
    r->xf = value12 & 0x10;
    r->i = value12 & 0x04;
    r->d = value12 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC3060A, SOM_RTS, "gen", configure_music_echo_and_evict_samples_above_echo_limit, 0, L_B | L_C | L_V, 3, 1, 0, 116, 61)
