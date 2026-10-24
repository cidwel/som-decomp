#include "som_c.h"

/* C22B94 multiply_signed_words_to_double_word   [class B, 47 bytes, 26 instructions]
 * Source: src/rom/multiply_signed_words_to_double_word.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void multiply_signed_words_to_double_word(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
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
    bool overflow2;
    if (!(value2 & 0x8000)) {
        a_hi2 = value2 >> 8;
        carry2 = carry1;
        overflow2 = overflow1;
    } else {
        uint16_t value4 = RAM16(0x02C5);
        RAM16_SET(0x024E, (uint16_t)(value4 - value2));
        a_hi2 = (uint16_t)(value4 - value2) >> 8;
        carry2 = value4 >= value2;
        overflow2 = ((value4 ^ value2) & (value4 ^ (uint16_t)(value4 - value2)) & 0x8000) != 0;
    }
    r->sp -= 2;
    JSR(c, 0x2BB1, 0xC22AC3); /* multiply_unsigned_words_with_four_hardware_products */
    r->sp += 2;
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    uint8_t a_hi3;
    bool carry3;
    bool overflow3;
    if (!((value ^ value2) & 0x8000)) {
        a_hi3 = (value ^ value2) >> 8;
        carry3 = carry_ret;
        overflow3 = overflow_ret;
    } else {
        uint16_t value5 = RAM16(0x02C5);
        uint16_t value6 = RAM16(0x0256);
        RAM16_SET(0x0256, (uint16_t)(value5 - value6));
        uint16_t value7 = RAM16(0x0258);
        RAM16_SET(0x0258, (uint16_t)(value5 - value7 - (value5 >= value6 ^ 1)));
        a_hi3 = (uint16_t)(value5 - value7 - (value5 >= value6 ^ 1)) >> 8;
        carry3 = value5 - value7 >= (value5 >= value6 ^ 1);
        overflow3 = ((value5 ^ value7) & (value5 ^ (uint16_t)(value5 - value7 - (value5 >= value6 ^ 1))) & 0x8000) != 0;
    }
    r->a = (a_hi3 << 8) | (uint8_t)a_all;
    r->c = carry3;
    r->v = overflow3;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22B94, SOM_RTS, "gen", multiply_signed_words_to_double_word, 0, L_B | L_X | L_Y | L_C | L_V, 2, 0, 0, 47, 26)
