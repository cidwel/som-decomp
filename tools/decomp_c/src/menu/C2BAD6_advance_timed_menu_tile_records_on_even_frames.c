#include "som_c.h"

/* C2BAD6 advance_timed_menu_tile_records_on_even_frames   [class B, 57 bytes, 30 instructions]
 * Source: src/rom/advance_timed_menu_tile_records_on_even_frames.s
 * Documented in docs/map-main-frame-menu-records.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_timed_menu_tile_records_on_even_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x00F4);
    if (value & 0x01) {
        r->c = value & 0x01;
        RETURN_RTL(c);
    }
    uint8_t value2 = RAM8(0x009B);
    if (value2 != 0) {
        RAM8(0x0000) = value2;
        RAM8(0x0001) = 0;
        uint8_t a_hi1 = a_hi;
        uint8_t x1 = x;
        uint8_t y1 = y;
        bool carry1 = value & 0x01;
        bool overflow1 = overflow;
        do {
            uint8_t value3 = RAM8(0x0001);
            RAM8(0xD202 + value3)--;
            uint8_t a_hi2;
            uint8_t x2;
            uint8_t y2;
            if (!(RAM8(0xD202 + value3) & 0x80)) {
                a_hi2 = a_hi1;
                x2 = value3;
                y2 = y1;
            } else {
                RAM8(0xD202 + value3) = RAM8(0xD203 + value3);
                r->a = (a_hi1 << 8) | RAM8(0xD200 + value3);
                r->x = value3;
                r->y = y1;
                r->mf = 1;
                r->xf = 1;
                r->db = 0x7E;
                r->dp = 0;
                r->sp -= 1;
                JSR(c, 0xBAFF, 0xC2BB0F); /* advance_one_timed_menu_tile_record_and_publish_native_tiles */
                r->sp += 1;
                uint16_t a_all = r->a;
                uint8_t x_ret = r->x;
                uint8_t y_ret = r->y;
                a_hi2 = a_all >> 8;
                x2 = x_ret;
                y2 = y_ret;
            }
            uint8_t value6 = RAM8(0x0001);
            RAM8(0x0001) = (uint8_t)(value6 + 0x10);
            RAM8(0x0000)--;
            a_hi1 = a_hi2;
            x1 = x2;
            y1 = y2;
            carry1 = value6 + 0x10 > 0xFF;
            overflow1 = ((value6 ^ (uint8_t)(value6 + 0x10)) & ((uint8_t)(value6 + 0x10) ^ 0x10) & 0x80) != 0;
        } while (RAM8(0x0000) != 0);
        r->a = (a_hi1 << 8) | a;
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
    r->c = value & 0x01;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2BAD6, SOM_RTL, "gen", advance_timed_menu_tile_records_on_even_frames, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 57, 30)
