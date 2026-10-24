#include "som_c.h"

/* C2C4C9 prepare_auxiliary_sprite_screen_position   [class B, 93 bytes, 44 instructions]
 * Source: src/rom/prepare_auxiliary_sprite_screen_position.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void prepare_auxiliary_sprite_screen_position(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0xD001 + y);
    uint8_t a_hi5;
    bool overflow3;
    if ((value & 0x80) == 0) {
        uint16_t value2 = RAM16(0xD002 + y);
        uint16_t value3 = RAM16(0x00A8);
        RAM16_SET(0x0004, (uint16_t)(value2 - value3));
        uint8_t a_hi1;
        if (value2 >= value3) {
            a_hi1 = (uint16_t)(value2 - value3) >> 8;
        } else {
            uint16_t value4 = RAM16(0x00C0);
            if ((uint16_t)((uint16_t)(value2 - value3) + value4 + (value2 >= value3)) < 0x0180) {
                RAM16_SET(0x0004, (uint16_t)((uint16_t)(value2 - value3) + value4 + (value2 >= value3)));
            }
            a_hi1 = (uint16_t)((uint16_t)(value2 - value3) + value4 + (value2 >= value3)) >> 8;
        }
        uint16_t value5 = RAM16(0xD004 + y);
        uint16_t value6 = RAM16(0x00AA);
        RAM16_SET(0x0006, (uint16_t)(value5 - value6));
        uint8_t a_hi2;
        bool overflow1;
        if (value5 >= value6) {
            a_hi2 = (uint16_t)(value5 - value6) >> 8;
            overflow1 = ((value5 ^ value6) & (value5 ^ (uint16_t)(value5 - value6)) & 0x8000) != 0;
        } else {
            uint16_t value7 = RAM16(0x00C2);
            if ((uint16_t)((uint16_t)(value5 - value6) + value7 + (value5 >= value6)) < 0x0140) {
                RAM16_SET(0x0006, (uint16_t)((uint16_t)(value5 - value6) + value7 + (value5 >= value6)));
            }
            a_hi2 = (uint16_t)((uint16_t)(value5 - value6) + value7 + (value5 >= value6)) >> 8;
            overflow1 = (((uint16_t)(value5 - value6) ^ (uint16_t)((uint16_t)(value5 - value6) + value7 + (value5 >= value6))) & (value7 ^ (uint16_t)((uint16_t)(value5 - value6) + value7 + (value5 >= value6))) & 0x8000) != 0;
        }
        a_hi5 = a_hi2;
        overflow3 = overflow1;
    } else {
        uint16_t value8 = RAM16(0xD002 + y);
        uint16_t value9 = RAM16(0x00AC);
        RAM16_SET(0x0004, (uint16_t)(value8 - value9));
        uint8_t a_hi3;
        if (value8 >= value9) {
            a_hi3 = (uint16_t)(value8 - value9) >> 8;
        } else {
            uint16_t value10 = RAM16(0x00C0);
            if ((uint16_t)((uint16_t)(value8 - value9) + value10 + (value8 >= value9)) < 0x0180) {
                RAM16_SET(0x0004, (uint16_t)((uint16_t)(value8 - value9) + value10 + (value8 >= value9)));
            }
            a_hi3 = (uint16_t)((uint16_t)(value8 - value9) + value10 + (value8 >= value9)) >> 8;
        }
        uint16_t value11 = RAM16(0xD004 + y);
        uint16_t value12 = RAM16(0x00AE);
        RAM16_SET(0x0006, (uint16_t)(value11 - value12));
        uint8_t a_hi4;
        bool overflow2;
        if (value11 >= value12) {
            a_hi4 = (uint16_t)(value11 - value12) >> 8;
            overflow2 = ((value11 ^ value12) & (value11 ^ (uint16_t)(value11 - value12)) & 0x8000) != 0;
        } else {
            uint16_t value13 = RAM16(0x00C2);
            if ((uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12)) < 0x0140) {
                RAM16_SET(0x0006, (uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12)));
            }
            a_hi4 = (uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12)) >> 8;
            overflow2 = (((uint16_t)(value11 - value12) ^ (uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12))) & (value13 ^ (uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12))) & 0x8000) != 0;
        }
        a_hi5 = a_hi4;
        overflow3 = overflow2;
    }
    r->a = (a_hi5 << 8) | a;
    r->v = overflow3;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C4C9, SOM_RTS, "gen", prepare_auxiliary_sprite_screen_position, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 93, 44)
