#include "som_c.h"

/* C2BC7E initialize_map_palette_animation   [class B, 91 bytes, 46 instructions]
 * Source: src/rom/initialize_map_palette_animation.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BX.
 */
static void initialize_map_palette_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x009B) = 0;
    uint8_t value = RAM8(0x001C);
    if (value & 0x80) {
        uint8_t a_hi1 = a_hi;
        uint8_t y1 = 0;
        for (;;) {
            RAM16_SET(0xDE00 + y1, RAM16(0x0600 + y1));
            uint16_t value3 = RAM16(0x0700 + y1);
            RAM16_SET(0xDF00 + y1, value3);
            a_hi1 = value3 >> 8;
            y1 = (uint8_t)(y1 + 2);
            if (!(y1 != 0)) break;
        }
        uint8_t value4 = BUS8(c, 0xC80803 + (uint8_t)(a_hi << 8 | (value & 0x7F)));
        RAM8(0x0010) = value4;
        RAM8(0x0011) = 0;
        uint8_t value5 = BUS8(c, 0xC80802 + (uint8_t)(a_hi << 8 | (value & 0x7F)));
        RAM16_SET(0x0012, 0xD300);
        uint8_t a_hi2 = 0xD3;
        uint16_t x1 = (uint8_t)((a_hi1 << 8) | value5);
        uint16_t y2 = y1;
        for (;;) {
            uint8_t value6 = BUS8(c, 0xC8087B + x1);
            r->a = (a_hi2 << 8) | value6;
            r->x = x1;
            r->y = y2;
            r->n = value6 & 0x80;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            r->sp -= 1;
            JSR(c, 0xBCC5, 0xC2BCD9); /* decode_map_palette_animation_record */
            r->sp += 1;
            uint16_t x_ret = r->x;
            uint16_t y_ret = r->y;
            RAM8(0x009B)++;
            uint16_t value7 = RAM16(0x0010);
            a_hi2 = (uint16_t)(y_ret + 0x10) >> 8;
            x1 = (uint16_t)(x_ret + 1);
            y2 = (uint16_t)(y_ret + 0x10);
            if (!(x1 < value7)) break;
        }
        r->a = (a_hi2 << 8) | a;
        r->x = x1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        RETURN_RTL(c);
    }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2BC7E, SOM_RTL, "gen", initialize_map_palette_animation, 0, L_B | L_X, 2, 1, 1, 91, 46)
