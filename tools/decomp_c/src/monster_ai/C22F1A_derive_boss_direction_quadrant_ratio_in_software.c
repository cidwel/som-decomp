#include "som_c.h"

/* C22F1A derive_boss_direction_quadrant_ratio_in_software   [class B, 71 bytes, 34 instructions]
 * Source: src/rom/derive_boss_direction_quadrant_ratio_in_software.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XY.
 */
static void derive_boss_direction_quadrant_ratio_in_software(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x026C, 0x1F);
    uint16_t value = RAM16(0x0246);
    uint16_t value2 = RAM16(0x024E);
    if (value < value2) {
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x1;
        if (value == 0) {
            a2 = 0x1F;
            a_hi2 = 0;
            x1 = x;
        } else {
            RAM16_SET(0x0256, value);
            RAM16_SET(0x0246, value2);
            uint16_t value3 = RAM16(0x0256);
            RAM16_SET(0x024E, value3);
            r->a = value3;
            r->c = value >= value2;
            JSR(c, 0x2F4C, 0xC22CBF); /* divide_unsigned_word_by_word_in_software */
            uint16_t x_ret = r->x;
            uint16_t value4 = RAM16(0x0256);
            uint8_t a1;
            uint8_t a_hi1;
            if (value4 < 0x20) {
                a1 = (uint8_t)value4;
                a_hi1 = value4 >> 8;
            } else {
                a1 = 0x1F;
                a_hi1 = 0;
            }
            a2 = a1;
            a_hi2 = a_hi1;
            x1 = x_ret;
        }
        RAM16_SET(0x0256, (a_hi2 << 8) | a2);
        RAM16_SET(0x026C, (uint16_t)(RAM16(0x026C) + RAM16(0x0256)));
        r->x = x1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value;
    r->c = value >= value2;
    JSR(c, 0x2F27, 0xC22CBF); /* divide_unsigned_word_by_word_in_software */
    uint16_t value7 = RAM16(0x0256);
    uint8_t a3;
    uint8_t a_hi3;
    if (value7 < 0x20) {
        a3 = (uint8_t)value7;
        a_hi3 = value7 >> 8;
    } else {
        a3 = 0x1F;
        a_hi3 = 0;
    }
    RAM16_SET(0x0256, (a_hi3 << 8) | a3);
    RAM16_SET(0x026C, (uint16_t)(RAM16(0x026C) - RAM16(0x0256)));
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22F1A, SOM_RTS, "gen", derive_boss_direction_quadrant_ratio_in_software, 0, L_X | L_Y, 1, 0, 0, 71, 34)
