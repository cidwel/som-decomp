#include "som_c.h"

/* C2C485 animate_auxiliary_sprite_tile_orientation   [class C, 68 bytes, 35 instructions]
 * Source: src/rom/animate_auxiliary_sprite_tile_orientation.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void animate_auxiliary_sprite_tile_orientation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0xD00F + y);
    uint8_t value2 = RAM8(0xD00E + y);
    RAM8(0x0000 + sp0) = value2 & 0xFC;
    uint8_t value3 = RAM8(0x00F4);
    uint8_t a3;
    uint8_t a_hi3;
    if (((value3 >> 2) & 3) == 0) {
        a3 = (uint8_t)((value << 8 | (value2 & 0xFC)) & 0x3FFC);
        a_hi3 = ((value << 8 | (value2 & 0xFC)) & 0x3FFC) >> 8;
    } else {
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint8_t)(((value3 >> 2) & 3) - 1) == 0) {
            a2 = (uint8_t)((((value << 8 | (value2 & 0xFC)) & 0x3FFC) | 0x8000) + 2);
            a_hi2 = (uint16_t)((((value << 8 | (value2 & 0xFC)) & 0x3FFC) | 0x8000) + 2) >> 8;
        } else {
            uint8_t a1;
            uint8_t a_hi1;
            if ((uint8_t)(((value3 >> 2) & 3) - 2) == 0) {
                a1 = (uint8_t)(((value << 8 | (value2 & 0xFC)) & 0x3FFC) | 0x4000);
                a_hi1 = (((value << 8 | (value2 & 0xFC)) & 0x3FFC) | 0x4000) >> 8;
            } else {
                a1 = (uint8_t)(((value << 8 | (value2 & 0xFC)) & 0x3FFC) + 2);
                a_hi1 = ((value << 8 | (value2 & 0xFC)) & 0x3FFC) + 2 >> 8;
            }
            a2 = a1;
            a_hi2 = a_hi1;
        }
        a3 = a2;
        a_hi3 = a_hi2;
    }
    RAM16_SET(0xD00E + y, (a_hi3 << 8) | a3);
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C485, SOM_RTS, "gen", animate_auxiliary_sprite_tile_orientation, 0, L_X | L_Y, 1, 1, 0, 68, 35)
