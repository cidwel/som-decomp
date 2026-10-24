#include "som_c.h"

/* C22BC3 multiply_signed_double_words_to_quad_word   [class B, 71 bytes, 38 instructions]
 * Source: src/rom/multiply_signed_double_words_to_quad_word.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: CV.
 */
static void multiply_signed_double_words_to_quad_word(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
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
    bool negative1;
    bool overflow2;
    if (!(value2 & 0x8000)) {
        a_hi2 = value2 >> 8;
        carry2 = carry1;
        zero1 = value2 == 0;
        negative1 = value2 & 0x8000;
        overflow2 = overflow1;
    } else {
        uint16_t value5 = RAM16(0x02C5);
        uint16_t value6 = RAM16(0x024E);
        RAM16_SET(0x024E, (uint16_t)(value5 - value6));
        RAM16_SET(0x0250, (uint16_t)(value5 - value2 - (value5 >= value6 ^ 1)));
        a_hi2 = (uint16_t)(value5 - value2 - (value5 >= value6 ^ 1)) >> 8;
        carry2 = value5 - value2 >= (value5 >= value6 ^ 1);
        zero1 = (uint16_t)(value5 - value2 - (value5 >= value6 ^ 1)) == 0;
        negative1 = (uint16_t)(value5 - value2 - (value5 >= value6 ^ 1)) & 0x8000;
        overflow2 = ((value5 ^ value2) & (value5 ^ (uint16_t)(value5 - value2 - (value5 >= value6 ^ 1))) & 0x8000) != 0;
    }
    r->c = carry2;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow2;
    r->sp -= 2;
    JSR(c, 0x2BEC, 0xC22B2F); /* multiply_unsigned_double_words_in_software */
    r->sp += 2;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    bool carry3;
    bool overflow3;
    if (!((value ^ value2) & 0x8000)) {
        carry3 = carry_ret;
        overflow3 = overflow_ret;
    } else {
        uint16_t value7 = RAM16(0x02C5);
        uint16_t value8 = RAM16(0x0256);
        RAM16_SET(0x0256, (uint16_t)(value7 - value8));
        uint16_t value9 = RAM16(0x0258);
        RAM16_SET(0x0258, (uint16_t)(value7 - value9 - (value7 >= value8 ^ 1)));
        uint16_t value10 = RAM16(0x025A);
        RAM16_SET(0x025A, (uint16_t)(value7 - value10 - (value7 - value9 >= (value7 >= value8 ^ 1) ^ 1)));
        uint16_t value11 = RAM16(0x025C);
        RAM16_SET(0x025C, (uint16_t)(value7 - value11 - (value7 - value10 >= (value7 - value9 >= (value7 >= value8 ^ 1) ^ 1) ^ 1)));
        carry3 = value7 - value11 >= (value7 - value10 >= (value7 - value9 >= (value7 >= value8 ^ 1) ^ 1) ^ 1);
        overflow3 = ((value7 ^ value11) & (value7 ^ (uint16_t)(value7 - value11 - (value7 - value10 >= (value7 - value9 >= (value7 >= value8 ^ 1) ^ 1) ^ 1))) & 0x8000) != 0;
    }
    r->c = carry3;
    r->v = overflow3;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22BC3, SOM_RTS, "gen", multiply_signed_double_words_to_quad_word, 0, L_C | L_V, 2, 0, 0, 71, 38)
