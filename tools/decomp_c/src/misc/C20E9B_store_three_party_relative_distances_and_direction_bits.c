#include "som_c.h"

/* C20E9B store_three_party_relative_distances_and_direction_bits   [class B, 140 bytes, 62 instructions]
 * Source: src/rom/store_three_party_relative_distances_and_direction_bits.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABYCV.
 */
static void store_three_party_relative_distances_and_direction_bits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x0052 + x, 0);
    RAM16_SET(0x0055 + x, 0);
    RAM16_SET(0x0246, RAM16(0x002B + x));
    uint16_t value2 = RAM16(0x0032 + x);
    RAM16_SET(0x024E, value2);
    uint8_t a1 = (uint8_t)value2;
    uint8_t a_hi1 = value2 >> 8;
    uint16_t x1 = x;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value3 = RAM16(0x0246);
        uint16_t value4 = RAM16(0xE002 + y1);
        uint8_t a_hi4;
        if ((uint16_t)(value3 - value4) & 0x8000) {
            uint8_t a2;
            uint8_t a_hi2;
            if ((uint16_t)(((uint16_t)(value3 - value4) ^ 0xFFFF) + 1) < 0x80) {
                a2 = (uint8_t)(((uint16_t)(value3 - value4) ^ 0xFFFF) + 1);
                a_hi2 = (uint16_t)(((uint16_t)(value3 - value4) ^ 0xFFFF) + 1) >> 8;
            } else {
                a2 = 0x80;
                a_hi2 = 0;
            }
            RAM8(0x0050 + x1) = a2;
            RAM8(0x0052 + x1) = 0x80;
            a_hi4 = a_hi2;
        } else {
            uint8_t a3;
            uint8_t a_hi3;
            if ((uint16_t)(value3 - value4) < 0x80) {
                a3 = (uint8_t)(value3 - value4);
                a_hi3 = (uint16_t)(value3 - value4) >> 8;
            } else {
                a3 = 0x80;
                a_hi3 = 0;
            }
            RAM8(0x0050 + x1) = a3;
            a_hi4 = a_hi3;
        }
        uint16_t value5 = RAM16(0x024E);
        uint16_t value6 = RAM16(0xE004 + y1);
        uint8_t a_hi7;
        if ((uint16_t)(value5 - value6) & 0x8000) {
            uint8_t a4;
            uint8_t a_hi5;
            if ((uint16_t)(((uint16_t)(value5 - value6) ^ 0xFFFF) + 1) < 0x80) {
                a4 = (uint8_t)(((uint16_t)(value5 - value6) ^ 0xFFFF) + 1);
                a_hi5 = (uint16_t)(((uint16_t)(value5 - value6) ^ 0xFFFF) + 1) >> 8;
            } else {
                a4 = 0x80;
                a_hi5 = 0;
            }
            RAM8(0x0051 + x1) = a4;
            RAM8(0x0052 + x1) |= 0x40;
            a_hi7 = a_hi5;
        } else {
            uint8_t a5;
            uint8_t a_hi6;
            if ((uint16_t)(value5 - value6) < 0x80) {
                a5 = (uint8_t)(value5 - value6);
                a_hi6 = (uint16_t)(value5 - value6) >> 8;
            } else {
                a5 = 0x80;
                a_hi6 = 0;
            }
            RAM8(0x0051 + x1) = a5;
            a_hi7 = a_hi6;
        }
        uint8_t a1_next = (uint8_t)(y1 + 0x0200);
        uint8_t a_hi1_next = (uint16_t)(y1 + 0x0200) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 3);
        uint16_t y1_next = (uint16_t)(y1 + 0x0200);
        bool carry1_next = (uint16_t)(y1 + 0x0200) >= 0x0600;
        bool overflow1_next = ((y1 ^ (uint16_t)(y1 + 0x0200)) & ((uint16_t)(y1 + 0x0200) ^ 0x0200) & 0x8000) != 0;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!(y1 < 0x0600)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20E9B, SOM_RTS, "gen", store_three_party_relative_distances_and_direction_bits, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 0, 140, 62)
