#include "som_c.h"

/* C2BEB1 scan_map_palette_animation_color_span   [class B, 76 bytes, 47 instructions]
 * Source: src/rom/scan_map_palette_animation_color_span.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: XY.
 */
static void scan_map_palette_animation_color_span(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 2) = y >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)y;
    uint8_t value = RAM8(0xD204 + y);
    uint8_t a_hi1 = 0;
    uint16_t x1 = (uint8_t)(value + 2);
    uint16_t y1 = 1;
    for (;;) {
        uint8_t value2 = RAM8(0x0601 + x1);
        uint8_t a_hi3;
        uint16_t y4;
        if (!(value2 & 0x80)) {
            uint8_t a_hi2 = (uint8_t)y1;
            uint16_t x2 = (uint16_t)(x1 + 2);
            uint16_t y2 = (uint16_t)(y1 + 1);
            for (;;) {
                uint8_t value3 = RAM8(0x0601 + x2);
                uint16_t y3;
                if (value3 & 0x80) {
                    y3 = y2;
                } else {
                    if ((uint16_t)(y2 + 1) < 0x10) {
                        x2 = (uint16_t)(x2 + 2);
                        y2 = (uint16_t)(y2 + 1);
                        continue;
                    }
                    y3 = (uint16_t)(y2 + 1);
                }
                y2 = y3;
                break;
            }
            a_hi3 = a_hi2;
            y4 = y2;
        } else {
            if ((uint16_t)(y1 + 1) < 0x10) {
                x1 = (uint16_t)(x1 + 2);
                y1 = (uint16_t)(y1 + 1);
                continue;
            }
            a_hi3 = 1;
            y4 = (uint16_t)(y1 + 1);
        }
        a_hi1 = a_hi3;
        y1 = y4;
        break;
    }
    BUS16_SET(c, (uint16_t)(dp + 2), ((uint8_t)((uint8_t)y1 - 1) << 8) | a_hi1);
    RAM16_SET(0xD20A + y, (uint16_t)((((uint8_t)((uint8_t)y1 - 1) << 8) | a_hi1) << 1));
    uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp + 3));
    uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 2));
    RAM8(0xD20C + y) = (uint8_t)(value4 - value5);
    r->x = x;
    r->y = y;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2BEB1, SOM_RTS, "gen", scan_map_palette_animation_color_span, 0, L_X | L_Y, 4, 1, 0, 76, 47)
