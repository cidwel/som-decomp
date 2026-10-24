#include "som_c.h"

/* C22B2F multiply_unsigned_double_words_in_software   [class A, 57 bytes, 31 instructions]
 * Source: src/rom/multiply_unsigned_double_words_in_software.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: CV.
 */
static void multiply_unsigned_double_words_in_software(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x0256, 0);
    RAM16_SET(0x0258, 0);
    RAM16_SET(0x025A, 0);
    RAM16_SET(0x025C, 0);
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = 0x20;
    for (;;) {
        uint16_t value = RAM16(0x0256);
        RAM16_SET(0x0256, (uint16_t)(RAM16(0x0256) << 1));
        uint16_t value2 = RAM16(0x0258);
        RAM16_SET(0x0258, (uint16_t)((RAM16(0x0258) << 1) | (value >> 0x0F)));
        uint16_t value3 = RAM16(0x025A);
        RAM16_SET(0x025A, (uint16_t)((RAM16(0x025A) << 1) | (value2 >> 0x0F)));
        RAM16_SET(0x025C, (uint16_t)((RAM16(0x025C) << 1) | (value3 >> 0x0F)));
        uint16_t value5 = RAM16(0x024E);
        RAM16_SET(0x024E, (uint16_t)(RAM16(0x024E) << 1));
        uint16_t value6 = RAM16(0x0250);
        RAM16_SET(0x0250, (uint16_t)((RAM16(0x0250) << 1) | (value5 >> 0x0F)));
        uint8_t a_hi2;
        if (!(value6 & 0x8000)) {
            a_hi2 = a_hi1;
        } else {
            uint16_t value7 = RAM16(0x0256);
            uint16_t value8 = RAM16(0x0246);
            RAM16_SET(0x0256, (uint16_t)(value7 + value8));
            uint16_t value9 = RAM16(0x0258);
            uint16_t value10 = RAM16(0x0248);
            RAM16_SET(0x0258, (uint16_t)(value9 + value10 + (value7 + value8 > 0xFFFF)));
            uint16_t value11 = RAM16(0x025A);
            uint16_t value12 = RAM16(0x02C5);
            RAM16_SET(0x025A, (uint16_t)(value11 + value12 + (value9 + value10 + (value7 + value8 > 0xFFFF) > 0xFFFF)));
            uint16_t value13 = RAM16(0x025C);
            RAM16_SET(0x025C, (uint16_t)(value13 + value12 + (value11 + value12 + (value9 + value10 + (value7 + value8 > 0xFFFF) > 0xFFFF) > 0xFFFF)));
            a_hi2 = (uint16_t)(value13 + value12 + (value11 + value12 + (value9 + value10 + (value7 + value8 > 0xFFFF) > 0xFFFF) > 0xFFFF)) >> 8;
        }
        a_hi1 = a_hi2;
        x1 = (uint8_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22B2F, SOM_RTS, "gen", multiply_unsigned_double_words_in_software, 0, L_C | L_V, 1, 0, 0, 57, 31)
