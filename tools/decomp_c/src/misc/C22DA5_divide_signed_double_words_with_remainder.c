#include "som_c.h"

/* C22DA5 divide_signed_double_words_with_remainder   [class B, 84 bytes, 47 instructions]
 * Source: src/rom/divide_signed_double_words_with_remainder.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYCV.
 */
static void divide_signed_double_words_with_remainder(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0248);
    uint16_t value2 = RAM16(0x0250);
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    if (!(value & 0x8000)) {
        a_hi1 = value >> 8;
        carry1 = carry;
        overflow1 = overflow;
    } else {
        uint16_t value3 = RAM16(0x02C5);
        uint16_t value4 = RAM16(0x0246);
        RAM16_SET(0x0246, (uint16_t)(value3 - value4));
        RAM16_SET(0x0248, (uint16_t)(value3 - value - (value3 >= value4 ^ 1)));
        a_hi1 = (uint16_t)(value3 - value - (value3 >= value4 ^ 1)) >> 8;
        carry1 = value3 - value >= (value3 >= value4 ^ 1);
        overflow1 = ((value3 ^ value) & (value3 ^ (uint16_t)(value3 - value - (value3 >= value4 ^ 1))) & 0x8000) != 0;
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
        uint16_t value5 = RAM16(0x02C5);
        uint16_t value6 = RAM16(0x024E);
        RAM16_SET(0x024E, (uint16_t)(value5 - value6));
        RAM16_SET(0x0250, (uint16_t)(value5 - value2 - (value5 >= value6 ^ 1)));
        a_hi2 = (uint16_t)(value5 - value2 - (value5 >= value6 ^ 1)) >> 8;
        carry2 = value5 - value2 >= (value5 >= value6 ^ 1);
        zero1 = (uint16_t)(value5 - value2 - (value5 >= value6 ^ 1)) == 0;
        overflow2 = ((value5 ^ value2) & (value5 ^ (uint16_t)(value5 - value2 - (value5 >= value6 ^ 1))) & 0x8000) != 0;
    }
    r->a = (a_hi2 << 8) | (uint8_t)a;
    r->c = carry2;
    r->v = overflow2;
    r->sp -= 4;
    JSR(c, 0x2DCF, 0xC22CE6); /* divide_unsigned_double_words_in_software */
    r->sp += 4;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool overflow_ret = r->v;
    if (!zero_ret) {
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t a_hi3;
    bool carry3;
    bool overflow3;
    if (!((value ^ value2) & 0x8000)) {
        a_hi3 = (value ^ value2) >> 8;
        carry3 = carry_ret;
        overflow3 = overflow_ret;
    } else {
        uint16_t value7 = RAM16(0x02C5);
        uint16_t value8 = RAM16(0x0256);
        RAM16_SET(0x0256, (uint16_t)(value7 - value8));
        uint16_t value9 = RAM16(0x0258);
        RAM16_SET(0x0258, (uint16_t)(value7 - value9 - (value7 >= value8 ^ 1)));
        a_hi3 = (uint16_t)(value7 - value9 - (value7 >= value8 ^ 1)) >> 8;
        carry3 = value7 - value9 >= (value7 >= value8 ^ 1);
        overflow3 = ((value7 ^ value9) & (value7 ^ (uint16_t)(value7 - value9 - (value7 >= value8 ^ 1))) & 0x8000) != 0;
    }
    bool carry4;
    bool overflow4;
    if (!(value & 0x8000)) {
        carry4 = carry3;
        overflow4 = overflow3;
    } else {
        uint16_t value10 = RAM16(0x02C5);
        uint16_t value11 = RAM16(0x025E);
        RAM16_SET(0x025E, (uint16_t)(value10 - value11));
        uint16_t value12 = RAM16(0x0260);
        RAM16_SET(0x0260, (uint16_t)(value10 - value12 - (value10 >= value11 ^ 1)));
        carry4 = value10 - value12 >= (value10 >= value11 ^ 1);
        overflow4 = ((value10 ^ value12) & (value10 ^ (uint16_t)(value10 - value12 - (value10 >= value11 ^ 1))) & 0x8000) != 0;
    }
    r->c = carry4;
    r->v = overflow4;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22DA5, SOM_RTS, "gen", divide_signed_double_words_with_remainder, 0, L_X | L_Y | L_C | L_V, 4, 0, 0, 84, 47)
