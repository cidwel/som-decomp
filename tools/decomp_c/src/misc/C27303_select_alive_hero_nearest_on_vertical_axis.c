#include "som_c.h"

/* C27303 select_alive_hero_nearest_on_vertical_axis   [class B, 72 bytes, 35 instructions]
 * Source: src/rom/select_alive_hero_nearest_on_vertical_axis.s
 * Documented in docs/boss-descriptor-seven.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BX.
 */
static void select_alive_hero_nearest_on_vertical_axis(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0295, RAM16(0x0032 + x));
    RAM16_SET(0x0297, 0x07FF);
    RAM16_SET(0x0299, 0);
    uint8_t a_hi1 = 7;
    uint16_t y1 = 0;
    for (;;) {
        uint16_t value2 = RAM16(0x0000 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
        uint8_t a_hi4;
        if ((value2 & 0xFF) != 1) {
            a_hi4 = 0;
        } else {
            uint16_t value3 = RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
            uint8_t a_hi3;
            if (value3 & 0x8000) {
                a_hi3 = value3 >> 8;
            } else {
                uint16_t value4 = RAM16(0x0004 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
                uint16_t value5 = RAM16(0x0295);
                uint8_t a1;
                uint8_t a_hi2;
                if (!((uint16_t)(value4 - value5) & 0x8000)) {
                    a1 = (uint8_t)(value4 - value5);
                    a_hi2 = (uint16_t)(value4 - value5) >> 8;
                } else {
                    uint16_t value6 = RAM16(0x02C7);
                    a1 = (uint8_t)(((uint16_t)(value4 - value5) ^ value6) + 1);
                    a_hi2 = (uint16_t)(((uint16_t)(value4 - value5) ^ value6) + 1) >> 8;
                }
                if (((a_hi2 << 8) | a1) < RAM16(0x0297)) {
                    RAM16_SET(0x0297, (a_hi2 << 8) | a1);
                    RAM16_SET(0x0299, y1);
                }
                a_hi3 = a_hi2;
            }
            a_hi4 = a_hi3;
        }
        a_hi1 = a_hi4;
        y1 = (uint16_t)(y1 + 1);
        if (!(y1 < 3)) break;
    }
    uint16_t value8 = RAM16(0x0287);
    uint16_t value9 = RAM16(0x0299);
    RAM16_SET(0x00A9 + value8, value9);
    r->a = value9;
    r->x = value8;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27303, SOM_RTS, "gen", select_alive_hero_nearest_on_vertical_axis, 0, L_B | L_X, 1, 0, 0, 72, 35)
