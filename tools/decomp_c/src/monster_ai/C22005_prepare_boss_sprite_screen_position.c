#include "som_c.h"

/* C22005 prepare_boss_sprite_screen_position   [class B, 104 bytes, 50 instructions]
 * Source: src/rom/prepare_boss_sprite_screen_position.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void prepare_boss_sprite_screen_position(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x002B + x);
    RAM16_SET(0x028F, value);
    RAM16_SET(0x0002 + x, value);
    uint16_t value2 = RAM16(0x028D);
    uint8_t a_hi1;
    uint16_t y1;
    bool overflow1;
    if ((value2 & 3) == 0) {
        a_hi1 = 0;
        y1 = y;
        overflow1 = overflow;
    } else {
        uint16_t value3 = RAM16(0x028F);
        uint16_t value4 = RAM16(0x00A8 + (uint16_t)((uint16_t)((value2 & 3) - 1) << 2));
        RAM16_SET(0x028F, (uint16_t)(value3 - value4));
        a_hi1 = (uint16_t)(value3 - value4) >> 8;
        y1 = (uint16_t)((uint16_t)((value2 & 3) - 1) << 2);
        overflow1 = ((value3 ^ value4) & (value3 ^ (uint16_t)(value3 - value4)) & 0x8000) != 0;
    }
    RAM16_SET(0x0020 + x, RAM16(0x028F));
    uint16_t value6 = RAM16(0x0032 + x);
    RAM16_SET(0x0291, value6);
    RAM16_SET(0x0004 + x, value6);
    uint16_t value7 = RAM16(0x028D);
    uint8_t a_hi3;
    uint16_t y2;
    bool overflow3;
    if ((value7 & 3) == 0) {
        a_hi3 = 0;
        y2 = y1;
        overflow3 = overflow1;
    } else {
        RAM16_SET(0x0291, (uint16_t)(RAM16(0x0291) - RAM16(0x00AA + (uint16_t)((uint16_t)((value7 & 3) - 1) << 2))));
        uint16_t value10 = RAM16(0x00C2 + (uint16_t)((uint16_t)((value7 & 3) - 1) << 2));
        uint16_t value11 = RAM16(0x00AA + (uint16_t)((uint16_t)((value7 & 3) - 1) << 2));
        uint8_t a_hi2;
        bool overflow2;
        if ((uint16_t)(value10 - 0x70) >= value11) {
            a_hi2 = (uint16_t)(value10 - 0x70) >> 8;
            overflow2 = ((value10 ^ 0x70) & (value10 ^ (uint16_t)(value10 - 0x70)) & 0x8000) != 0;
        } else {
            uint16_t value12 = RAM16(0x0291);
            RAM16_SET(0x0291, (uint16_t)(value12 + value10));
            a_hi2 = (uint16_t)(value12 + value10) >> 8;
            overflow2 = ((value12 ^ (uint16_t)(value12 + value10)) & (value10 ^ (uint16_t)(value12 + value10)) & 0x8000) != 0;
        }
        a_hi3 = a_hi2;
        y2 = (uint16_t)((uint16_t)((value7 & 3) - 1) << 2);
        overflow3 = overflow2;
    }
    uint16_t value13 = RAM16(0x0098 + x);
    uint8_t a_hi4;
    if ((value13 & 0x20) != 0) {
        a_hi4 = value13 >> 8;
    } else {
        uint16_t value14 = RAM16(0x0291);
        RAM16_SET(0x0022 + x, value14);
        a_hi4 = value14 >> 8;
    }
    uint16_t value15 = RAM16(0x0066 + x);
    RAM8(0x0045 + x) = (uint8_t)(value15 >> 1);
    r->a = value15 >> 1;
    r->y = y2;
    r->v = overflow3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22005, SOM_RTS, "gen", prepare_boss_sprite_screen_position, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 104, 50)
