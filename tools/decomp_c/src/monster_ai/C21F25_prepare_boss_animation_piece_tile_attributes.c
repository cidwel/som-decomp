#include "som_c.h"

/* C21F25 prepare_boss_animation_piece_tile_attributes   [class B, 91 bytes, 47 instructions]
 * Source: src/rom/prepare_boss_animation_piece_tile_attributes.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0200.  Callers read: Y.
 */
static void prepare_boss_animation_piece_tile_attributes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint8_t value = RAM8(0x028E);
    uint8_t a_hi1;
    if ((value & 0x80) != 0) {
        uint16_t value2;
        BUS16_OK(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + 2, value2);
        RAM16_SET(0x026E, value2);
        RAM16_SET(0x026A, (value2 & 0x0F) >> 1);
        uint16_t value3 = RAM16(0x026E);
        uint16_t value5 = RAM16(0x0ED5 + (uint8_t)(((value3 & 0x01E0) >> 2) | RAM16(0x026A)));
        RAM16_SET(0x026E, value3 & 0xFE00);
        uint16_t value6;
        BUS16_OK(c, 0xD97F35 + (uint8_t)(value5 << 1), value6);
        uint16_t value7 = RAM16(0x026E);
        RAM16_SET(0x026C, value6 | value7);
        a_hi1 = (value6 | value7) >> 8;
    } else {
        uint16_t value8;
        BUS16_OK(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + 2, value8);
        RAM16_SET(0x026C, value8);
        a_hi1 = value8 >> 8;
    }
    uint16_t value10 = RAM16(0x00A3 + RAM16(0x0287));
    RAM16_SET(0x026C, (uint16_t)((uint16_t)((((uint8_t)value10 << 8) | (value10 >> 8)) << 1) + RAM16(0x026C)));
    uint16_t value12 = RAM16(0x028D);
    BUS16_SET(c, RAM16(0x027C) + 0x7E0002, ((((uint8_t)value12 << 8) | (value12 >> 8)) & 0xC000) ^ RAM16(0x026C));
    r->y = 2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21F25, SOM_RTS, "hand", prepare_boss_animation_piece_tile_attributes, 0, L_Y, 1, 1, 1, 91, 47)
