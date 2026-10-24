#include "som_c.h"

/* C2BCD9 decode_map_palette_animation_record   [class C, 180 bytes, 94 instructions]
 * Source: src/rom/decode_map_palette_animation_record.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void decode_map_palette_animation_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool negative = r->n;
    uint16_t x1;
    if (!negative) {
        x1 = x;
    } else {
        uint8_t value = BUS8(c, 0xC8087B + (uint16_t)(x + 1));
        BUS8_SET(c, 0x004202, value);
        BUS8_SET(c, 0x004203, 0x1E);
        x1 = (uint16_t)(x + 1);
    }
    RAM8(0xD204 + y) = (a & 7) << 1 << 1 << 1 << 1 << 1;
    RAM8(0xD205 + y) = 0;
    RAM8(0xD202 + y) = (a >> 3) & 3;
    RAM8(0xD203 + y) = (a >> 3) & 3;
    RAM16_SET(0xD206 + y, 0);
    uint16_t value2 = BUS16(c, 0x004216);
    uint16_t value3 = BUS16(c, 0xC80800);
    RAM16_SET(0xD208 + y, (uint16_t)(value2 + value3));
    RAM8(0xD201 + y) = 0;
    RAM8(0xD200 + y) = a >> 5;
    if (a >> 5 == 4) {
        RAM16_SET(0x0014, RAM16(0xD208 + y));
        RAM16_SET(0x0016, 0xC8);
        uint16_t value5 = RAM16(0xD204 + y);
        uint8_t a_hi1 = 0;
        uint16_t x2 = (uint16_t)(value5 + 2);
        uint16_t y1 = 0;
        for (;;) {
            uint16_t value6 = BUS16(c, (RAM8(0x0016) << 0x10) + RAM16(0x0014) + y1);
            RAM16_SET(0x0000, value6);
            RAM16_SET(0x0002, RAM16(0x0600 + x2));
            uint16_t value8 = RAM16(0x0012);
            RAM16_SET(0x0018, (uint16_t)(y1 + value8));
            r->a = (uint16_t)(y1 + value8);
            r->y = y1;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            r->sp -= 8;
            JSR(c, 0xBD71, 0xC2BD8D); /* build_map_palette_color_ramp */
            r->sp += 8;
            uint16_t a_all = r->a;
            a_hi1 = a_all >> 8;
            x2 = (uint16_t)(x2 + 2);
            y1 = (uint16_t)(y1 + 2);
            if (!(y1 < 0x1E)) break;
        }
        uint16_t value9 = RAM16(0x0012);
        RAM16_SET(0xD208 + y, value9);
        RAM16_SET(0x0012, (uint16_t)(value9 + 0x01E0));
        r->x = x1;
        r->y = y;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    if (a >> 5 == 3) {
        RAM16_SET(0x0014, 0xBEFD);
        RAM16_SET(0x0016, 1);
        uint16_t value10 = RAM16(0xD204 + y);
        uint8_t a_hi2 = 0;
        uint16_t x3 = (uint16_t)(value10 + 2);
        uint16_t y2 = 0;
        for (;;) {
            uint16_t value11 = BUS16(c, (RAM8(0x0016) << 0x10) + RAM16(0x0014) + y2);
            RAM16_SET(0x0000, value11);
            RAM16_SET(0x0002, RAM16(0x0600 + x3));
            uint16_t value13 = RAM16(0x0012);
            RAM16_SET(0x0018, (uint16_t)(y2 + value13));
            r->a = (uint16_t)(y2 + value13);
            r->y = y2;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            r->sp -= 8;
            JSR(c, 0xBD71, 0xC2BD8D); /* build_map_palette_color_ramp */
            r->sp += 8;
            uint16_t a_all2 = r->a;
            a_hi2 = a_all2 >> 8;
            x3 = (uint16_t)(x3 + 2);
            y2 = (uint16_t)(y2 + 2);
            if (!(y2 < 0x1E)) break;
        }
        uint16_t value14 = RAM16(0x0012);
        RAM16_SET(0xD208 + y, value14);
        RAM16_SET(0x0012, (uint16_t)(value14 + 0x01E0));
        r->x = x1;
        r->y = y;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    if (a >> 5 >= 3) {
        r->x = x1;
        RETURN_RTS(c);
    }
    r->a = ((uint16_t)(value2 + value3) >> 8 << 8) | (a >> 5);
    r->x = x1;
    TAIL_CALL(c, 0xC2BEB1, SOM_RTS); /* scan_map_palette_animation_color_span */
}
SOM_REGISTER(0xC2BCD9, SOM_RTS, "gen", decode_map_palette_animation_record, 0, L_X | L_Y, 8, 1, 0, 180, 94)
