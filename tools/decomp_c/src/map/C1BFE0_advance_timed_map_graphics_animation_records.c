#include "som_c.h"

/* C1BFE0 advance_timed_map_graphics_animation_records   [class B, 70 bytes, 35 instructions]
 * Source: src/rom/advance_timed_map_graphics_animation_records.s
 * Documented in docs/map-graphics-runtime-animation.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_timed_map_graphics_animation_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x009A);
    if (value != 0) {
        RAM8(0x0000) = value & 0x0F;
        RAM8(0x0004) = 0x7F;
        RAM8(0x0001) = 0;
        uint8_t a_hi1 = a_hi;
        uint8_t x1 = x;
        uint8_t y1 = y;
        bool carry1 = carry;
        bool overflow1 = overflow;
        do {
            uint8_t value2 = RAM8(0x0001);
            RAM8(0x18200 + value2) = 0;
            RAM8(0x18208 + value2)--;
            uint8_t a_hi2;
            uint8_t y2;
            if (!(RAM8(0x18208 + value2) & 0x80)) {
                a_hi2 = a_hi1;
                y2 = y1;
            } else {
                RAM8(0x18208 + value2) = RAM8(0x18209 + value2);
                RAM8(0x18200 + value2)++;
                uint8_t value4 = RAM8(0x18201 + value2);
                r->x = value2;
                r->y = value4;
                r->mf = 1;
                r->xf = 1;
                r->db = 0x7F;
                r->dp = 0;
                r->sp -= 1;
                JSR(c, 0xC010, 0xC1C026); /* advance_map_graphics_animation_record_by_motion_type */
                r->sp += 1;
                uint16_t a_all = r->a;
                uint8_t y_ret = r->y;
                a_hi2 = a_all >> 8;
                y2 = y_ret;
            }
            uint8_t value5 = RAM8(0x0001);
            RAM8(0x0001) = (uint8_t)(value5 + 0x10);
            RAM8(0x0000)--;
            a_hi1 = a_hi2;
            x1 = value2;
            y1 = y2;
            carry1 = value5 + 0x10 > 0xFF;
            overflow1 = ((value5 ^ (uint8_t)(value5 + 0x10)) & ((uint8_t)(value5 + 0x10) ^ 0x10) & 0x80) != 0;
        } while (RAM8(0x0000) != 0);
        uint8_t value6 = RAM8(0x009A);
        RAM8(0x009A) = value6 | 0x80;
        r->a = (a_hi1 << 8) | (value6 | 0x80);
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 1;
        r->db = 0;
        r->dp = 0;
        RETURN_RTL(c);
    }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1BFE0, SOM_RTL, "gen", advance_timed_map_graphics_animation_records, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 70, 35)
