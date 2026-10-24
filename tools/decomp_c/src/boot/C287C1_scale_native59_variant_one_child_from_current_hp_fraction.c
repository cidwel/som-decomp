#include "som_c.h"

/* C287C1 scale_native59_variant_one_child_from_current_hp_fraction   [class B, 86 bytes, 38 instructions]
 * Source: src/rom/scale_native59_variant_one_child_from_current_hp_fraction.s
 * Documented in docs/boss-native59-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void scale_native59_variant_one_child_from_current_hp_fraction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0246, 0);
    RAM16_SET(0x0248, 0);
    RAM16_SET(0x0250, 0);
    RAM16_SET(0x0247, RAM16(0x0182 + value));
    uint16_t value3 = RAM16(0x0184 + value);
    RAM16_SET(0x024E, value3);
    r->a = value3;
    r->x = value;
    JSR(c, 0x87D5, 0xC22CE6); /* divide_unsigned_double_words_in_software */
    uint16_t value4 = RAM16(0x0256);
    RAM16_SET(0x0295, value4);
    RAM16_SET(0x0246, value4);
    RAM16_SET(0x024E, 0xCC);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x87E3, 0xC22AC3); /* multiply_unsigned_words_with_four_hardware_products */
    RAM16_SET(0x0295, (uint16_t)(RAM16(0x0257) + 0x33));
    uint16_t value7 = RAM16(0x00B4 + RAM16(0x0287));
    RAM16_SET(0x00B8 + value7, RAM16(0x0295));
    RAM16_SET(0x0246, 4);
    RAM16_SET(0x024E, RAM16(0x0295));
    r->x = value7;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8802, 0xC22AC3); /* multiply_unsigned_words_with_four_hardware_products */
    uint16_t value10 = RAM16(0x0257);
    uint8_t a1;
    uint8_t a_hi1;
    if (value10 < 4) {
        a1 = (uint8_t)value10;
        a_hi1 = value10 >> 8;
    } else {
        a1 = 4;
        a_hi1 = 0;
    }
    uint16_t value11 = RAM16(0x0287);
    RAM16_SET(0x001E + value11, (uint16_t)(((a_hi1 << 8) | a1) + 0x0C));
    r->a = (uint16_t)(((a_hi1 << 8) | a1) + 0x0C);
    r->x = value11;
    r->c = ((a_hi1 << 8) | a1) + 0x0C > 0xFFFF;
    r->z = (uint16_t)(((a_hi1 << 8) | a1) + 0x0C) == 0;
    r->n = (uint16_t)(((a_hi1 << 8) | a1) + 0x0C) & 0x8000;
    r->v = ((((a_hi1 << 8) | a1) ^ (uint16_t)(((a_hi1 << 8) | a1) + 0x0C)) & ((uint16_t)(((a_hi1 << 8) | a1) + 0x0C) ^ 0x0C) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC287C1, SOM_RTS, "gen", scale_native59_variant_one_child_from_current_hp_fraction, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 86, 38)
