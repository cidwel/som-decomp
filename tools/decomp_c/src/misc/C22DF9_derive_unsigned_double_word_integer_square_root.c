#include "som_c.h"

/* C22DF9 derive_unsigned_double_word_integer_square_root   [class B, 49 bytes, 25 instructions]
 * Source: src/rom/derive_unsigned_double_word_integer_square_root.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYCV.
 */
static void derive_unsigned_double_word_integer_square_root(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x024E, 0);
    RAM16_SET(0x024A, 0);
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = 0x10;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value = RAM16(0x0248);
        uint16_t value2 = RAM16(0x024A);
        uint16_t value3 = RAM16(0x024E);
        uint8_t a_hi2;
        bool carry2;
        bool overflow2;
        if (value2 - value3 < (value >= 0x4000 ^ 1)) {
            a_hi2 = (uint16_t)(value2 - value3 - (value >= 0x4000 ^ 1)) >> 8;
            carry2 = value2 - value3 >= (value >= 0x4000 ^ 1);
            overflow2 = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3 - (value >= 0x4000 ^ 1))) & 0x8000) != 0;
        } else {
            RAM16_SET(0x024A, (uint16_t)(value2 - value3 - (value >= 0x4000 ^ 1)));
            RAM16_SET(0x0248, (uint16_t)(value - 0x4000 - (value2 - value3 >= (value >= 0x4000 ^ 1) ^ 1)));
            a_hi2 = (uint16_t)(value - 0x4000 - (value2 - value3 >= (value >= 0x4000 ^ 1) ^ 1)) >> 8;
            carry2 = 1;
            overflow2 = ((value ^ 0x4000) & (value ^ (uint16_t)(value - 0x4000 - (value2 - value3 >= (value >= 0x4000 ^ 1) ^ 1))) & 0x8000) != 0;
        }
        RAM16_SET(0x024E, (uint16_t)((RAM16(0x024E) << 1) | carry2));
        uint16_t value5 = RAM16(0x0246);
        RAM16_SET(0x0246, (uint16_t)(RAM16(0x0246) << 1));
        uint16_t value6 = RAM16(0x0248);
        RAM16_SET(0x0248, (uint16_t)((RAM16(0x0248) << 1) | (value5 >> 0x0F)));
        RAM16_SET(0x024A, (uint16_t)((RAM16(0x024A) << 1) | (value6 >> 0x0F)));
        uint16_t value8 = RAM16(0x0246);
        RAM16_SET(0x0246, (uint16_t)(RAM16(0x0246) << 1));
        uint16_t value9 = RAM16(0x0248);
        RAM16_SET(0x0248, (uint16_t)((RAM16(0x0248) << 1) | (value8 >> 0x0F)));
        uint16_t value10 = RAM16(0x024A);
        RAM16_SET(0x024A, (uint16_t)((RAM16(0x024A) << 1) | (value9 >> 0x0F)));
        a_hi1 = a_hi2;
        x1 = (uint8_t)(x1 - 1);
        carry1 = value10 & 0x8000;
        overflow1 = overflow2;
        if (!(x1 != 0)) break;
    }
    r->x = x1;
    r->y = (uint8_t)y;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22DF9, SOM_RTS, "gen", derive_unsigned_double_word_integer_square_root, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 49, 25)
