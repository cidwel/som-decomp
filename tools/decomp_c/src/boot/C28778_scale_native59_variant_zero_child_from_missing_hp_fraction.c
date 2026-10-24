#include "som_c.h"

/* C28778 scale_native59_variant_zero_child_from_missing_hp_fraction   [class B, 73 bytes, 33 instructions]
 * Source: src/rom/scale_native59_variant_zero_child_from_missing_hp_fraction.s
 * Documented in docs/boss-native59-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void scale_native59_variant_zero_child_from_missing_hp_fraction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0246, 0);
    RAM16_SET(0x0248, 0);
    RAM16_SET(0x0250, 0);
    uint16_t value2 = RAM16(0x0184 + value);
    RAM16_SET(0x024E, value2);
    uint16_t value3 = RAM16(0x0182 + value);
    RAM16_SET(0x0247, (uint16_t)(value2 - value3));
    r->a = (uint16_t)(value2 - value3);
    r->x = value;
    r->c = value2 >= value3;
    r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
    JSR(c, 0x878D, 0xC22CE6); /* divide_unsigned_double_words_in_software */
    RAM16_SET(0x0295, (uint16_t)(RAM16(0x0256) + 0x80));
    uint16_t value6 = RAM16(0x00B4 + RAM16(0x0287));
    RAM16_SET(0x00B8 + value6, RAM16(0x0295));
    RAM16_SET(0x0246, 4);
    RAM16_SET(0x024E, RAM16(0x0256));
    r->x = value6;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x87AC, 0xC22AC3); /* multiply_unsigned_words_with_four_hardware_products */
    uint16_t value9 = RAM16(0x0257);
    uint8_t a1;
    uint8_t a_hi1;
    if (value9 < 4) {
        a1 = (uint8_t)value9;
        a_hi1 = value9 >> 8;
    } else {
        a1 = 4;
        a_hi1 = 0;
    }
    uint16_t value10 = RAM16(0x0287);
    RAM16_SET(0x001E + value10, (uint16_t)(((a_hi1 << 8) | a1) + 8));
    r->a = (uint16_t)(((a_hi1 << 8) | a1) + 8);
    r->x = value10;
    r->c = ((a_hi1 << 8) | a1) + 8 > 0xFFFF;
    r->z = (uint16_t)(((a_hi1 << 8) | a1) + 8) == 0;
    r->n = (uint16_t)(((a_hi1 << 8) | a1) + 8) & 0x8000;
    r->v = ((((a_hi1 << 8) | a1) ^ (uint16_t)(((a_hi1 << 8) | a1) + 8)) & ((uint16_t)(((a_hi1 << 8) | a1) + 8) ^ 8) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28778, SOM_RTS, "gen", scale_native59_variant_zero_child_from_missing_hp_fraction, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 73, 33)
