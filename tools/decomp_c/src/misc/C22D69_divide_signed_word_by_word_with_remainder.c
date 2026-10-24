#include "som_c.h"

/* C22D69 divide_signed_word_by_word_with_remainder   [class B, 60 bytes, 35 instructions]
 * Source: src/rom/divide_signed_word_by_word_with_remainder.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=8 bit DB=$7E D=$0200.  Callers read: BXY.
 */
static void divide_signed_word_by_word_with_remainder(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0246);
    uint16_t value2 = RAM16(0x024E);
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    if (!(value & 0x8000)) {
        a_hi1 = value >> 8;
        carry1 = carry;
        overflow1 = overflow;
    } else {
        uint16_t value3 = RAM16(0x02C5);
        RAM16_SET(0x0246, (uint16_t)(value3 - value));
        a_hi1 = (uint16_t)(value3 - value) >> 8;
        carry1 = value3 >= value;
        overflow1 = ((value3 ^ value) & (value3 ^ (uint16_t)(value3 - value)) & 0x8000) != 0;
    }
    uint8_t a_hi2;
    bool carry2;
    bool zero1;
    bool overflow2;
    if (!(value2 & 0x8000)) {
        a_hi2 = value2 >> 8;
        carry2 = carry1;
        zero1 = value2 == 0;
        overflow2 = overflow1;
    } else {
        uint16_t value4 = RAM16(0x02C5);
        RAM16_SET(0x024E, (uint16_t)(value4 - value2));
        a_hi2 = (uint16_t)(value4 - value2) >> 8;
        carry2 = value4 >= value2;
        zero1 = (uint16_t)(value4 - value2) == 0;
        overflow2 = ((value4 ^ value2) & (value4 ^ (uint16_t)(value4 - value2)) & 0x8000) != 0;
    }
    r->a = (a_hi2 << 8) | (uint8_t)a;
    r->c = carry2;
    r->v = overflow2;
    r->sp -= 4;
    JSR(c, 0x2D87, 0xC22CBF); /* divide_unsigned_word_by_word_in_software */
    r->sp += 4;
    uint16_t a_all = r->a;
    bool zero_ret = r->z;
    if (!zero_ret) {
        r->a = 0xFFFF;
        r->mf = 0;
        r->xf = 1;
        RETURN_RTS(c);
    }
    uint8_t a_hi3;
    if (!((value ^ value2) & 0x8000)) {
        a_hi3 = (value ^ value2) >> 8;
    } else {
        uint16_t value5 = RAM16(0x02C5);
        uint16_t value6 = RAM16(0x0256);
        RAM16_SET(0x0256, (uint16_t)(value5 - value6));
        a_hi3 = (uint16_t)(value5 - value6) >> 8;
    }
    uint8_t a_hi4;
    if (!(value & 0x8000)) {
        a_hi4 = value >> 8;
    } else {
        uint16_t value7 = RAM16(0x02C5);
        uint16_t value8 = RAM16(0x025E);
        RAM16_SET(0x025E, (uint16_t)(value7 - value8));
        a_hi4 = (uint16_t)(value7 - value8) >> 8;
    }
    r->a = (a_hi4 << 8) | (uint8_t)a_all;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22D69, SOM_RTS, "gen", divide_signed_word_by_word_with_remainder, 0, L_B | L_X | L_Y, 4, 0, 1, 60, 35)
