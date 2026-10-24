#include "som_c.h"

/* C22CE6 divide_unsigned_double_words_in_software   [class B, 72 bytes, 39 instructions]
 * Source: src/rom/divide_unsigned_double_words_in_software.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCZV.
 */
static void divide_unsigned_double_words_in_software_m16x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x024E);
    uint16_t value2 = RAM16(0x0250);
    if ((value | value2) == 0) {
        r->a = 0xFFFF;
        r->z = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0256, 0);
    RAM16_SET(0x0258, 0);
    RAM16_SET(0x025E, 0);
    RAM16_SET(0x0260, 0);
    uint8_t a_hi1 = (value | value2) >> 8;
    uint8_t x1 = 0x20;
    for (;;) {
        uint16_t value3 = RAM16(0x0256);
        RAM16_SET(0x0256, (uint16_t)(RAM16(0x0256) << 1));
        RAM16_SET(0x0258, (uint16_t)((RAM16(0x0258) << 1) | (value3 >> 0x0F)));
        uint16_t value5 = RAM16(0x0246);
        RAM16_SET(0x0246, (uint16_t)(RAM16(0x0246) << 1));
        uint16_t value6 = RAM16(0x0248);
        RAM16_SET(0x0248, (uint16_t)((RAM16(0x0248) << 1) | (value5 >> 0x0F)));
        uint16_t value7 = RAM16(0x025E);
        RAM16_SET(0x025E, (uint16_t)((RAM16(0x025E) << 1) | (value6 >> 0x0F)));
        RAM16_SET(0x0260, (uint16_t)((RAM16(0x0260) << 1) | (value7 >> 0x0F)));
        uint16_t value9 = RAM16(0x025E);
        uint16_t value10 = RAM16(0x024E);
        uint16_t value11 = RAM16(0x0260);
        uint16_t value12 = RAM16(0x0250);
        if (value11 - value12 >= (value9 >= value10 ^ 1)) {
            RAM16_SET(0x025E, (uint16_t)(value9 - value10));
            RAM16_SET(0x0260, (uint16_t)(value11 - value12 - (value9 >= value10 ^ 1)));
            RAM16_SET(0x0256, (uint16_t)(RAM16(0x0256) + 1));
            if (RAM16(0x0256) == 0) {
                RAM16_SET(0x0258, (uint16_t)(RAM16(0x0258) + 1));
            }
        }
        a_hi1 = (uint16_t)(value11 - value12 - (value9 >= value10 ^ 1)) >> 8;
        x1 = (uint8_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    uint16_t value13 = RAM16(0x02C5);
    r->a = value13;
    r->x = x1;
    r->y = (uint8_t)y;
    r->c = carry;
    r->z = value13 == 0;
    r->v = overflow;
    RETURN_RTS(c);
}

/* C22CE6 divide_unsigned_double_words_in_software   [class B, 72 bytes, 39 instructions]
 * Source: src/rom/divide_unsigned_double_words_in_software.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCZV.
 */
static void divide_unsigned_double_words_in_software_m8x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    if ((RAM8(0x024E) | RAM8(0x0250)) == 0) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    }
    RAM8(0x0256) = 0;
    RAM8(0x0258) = 0;
    RAM8(0x025E) = 0;
    RAM8(0x0260) = 0;
    uint8_t a_hi1 = a_hi;
    uint8_t x1 = 0x20;
    for (;;) {
        uint8_t value3 = RAM8(0x0256);
        RAM8(0x0256) <<= 1;
        RAM8(0x0258) = (uint8_t)((RAM8(0x0258) << 1) | (value3 >> 7));
        uint8_t value5 = RAM8(0x0246);
        RAM8(0x0246) <<= 1;
        uint8_t value6 = RAM8(0x0248);
        RAM8(0x0248) = (uint8_t)((RAM8(0x0248) << 1) | (value5 >> 7));
        uint8_t value7 = RAM8(0x025E);
        RAM8(0x025E) = (uint8_t)((RAM8(0x025E) << 1) | (value6 >> 7));
        RAM8(0x0260) = (uint8_t)((RAM8(0x0260) << 1) | (value7 >> 7));
        uint8_t value9 = RAM8(0x025E);
        uint8_t value10 = RAM8(0x024E);
        uint8_t value11 = RAM8(0x0260);
        uint8_t value12 = RAM8(0x0250);
        if (value11 - value12 >= (value9 >= value10 ^ 1)) {
            RAM8(0x025E) = (uint8_t)(value9 - value10);
            RAM8(0x0260) = (uint8_t)(value11 - value12 - (value9 >= value10 ^ 1));
            RAM8(0x0256)++;
            if (RAM8(0x0256) == 0) {
                RAM8(0x0258)++;
            }
        }
        x1 = (uint8_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    uint8_t value13 = RAM8(0x02C5);
    r->a = (a_hi1 << 8) | value13;
    r->x = x1;
    r->y = (uint8_t)y;
    r->c = carry;
    r->z = value13 == 0;
    r->v = overflow;
    RETURN_RTS(c);
}

/* C22CE6 divide_unsigned_double_words_in_software   [class B, 72 bytes, 39 instructions]
 * Source: src/rom/divide_unsigned_double_words_in_software.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0200.  Callers read: BXYCZV.
 */
static void divide_unsigned_double_words_in_software_m8x8(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    if ((RAM8(0x024E) | RAM8(0x0250)) == 0) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    }
    RAM8(0x0256) = 0;
    RAM8(0x0258) = 0;
    RAM8(0x025E) = 0;
    RAM8(0x0260) = 0;
    uint8_t a_hi1 = a_hi;
    uint8_t x1 = 0x20;
    for (;;) {
        uint8_t value3 = RAM8(0x0256);
        RAM8(0x0256) <<= 1;
        RAM8(0x0258) = (uint8_t)((RAM8(0x0258) << 1) | (value3 >> 7));
        uint8_t value5 = RAM8(0x0246);
        RAM8(0x0246) <<= 1;
        uint8_t value6 = RAM8(0x0248);
        RAM8(0x0248) = (uint8_t)((RAM8(0x0248) << 1) | (value5 >> 7));
        uint8_t value7 = RAM8(0x025E);
        RAM8(0x025E) = (uint8_t)((RAM8(0x025E) << 1) | (value6 >> 7));
        RAM8(0x0260) = (uint8_t)((RAM8(0x0260) << 1) | (value7 >> 7));
        uint8_t value9 = RAM8(0x025E);
        uint8_t value10 = RAM8(0x024E);
        uint8_t value11 = RAM8(0x0260);
        uint8_t value12 = RAM8(0x0250);
        if (value11 - value12 >= (value9 >= value10 ^ 1)) {
            RAM8(0x025E) = (uint8_t)(value9 - value10);
            RAM8(0x0260) = (uint8_t)(value11 - value12 - (value9 >= value10 ^ 1));
            RAM8(0x0256)++;
            if (RAM8(0x0256) == 0) {
                RAM8(0x0258)++;
            }
        }
        x1 = (uint8_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    uint8_t value13 = RAM8(0x02C5);
    r->a = (a_hi1 << 8) | value13;
    r->x = x1;
    r->y = y;
    r->c = carry;
    r->z = value13 == 0;
    r->v = overflow;
    RETURN_RTS(c);
}

/* Entered with M16/X16, M8/X16, M8/X8 accumulator/index widths: one body per width pair. */
static void divide_unsigned_double_words_in_software(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { divide_unsigned_double_words_in_software_m16x16(c); return; }
    if (r->mf == 1 && r->xf == 0) { divide_unsigned_double_words_in_software_m8x16(c); return; }
    if (r->mf == 1 && r->xf == 1) { divide_unsigned_double_words_in_software_m8x8(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0xC22CE6, SOM_RTS, "gen", divide_unsigned_double_words_in_software, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, -1, -1, 72, 39)
