#include "som_c.h"

/* C0C692 upload_pending_map_tile_rows_and_columns   [class D, 305 bytes, 124 instructions]
 * Source: src/rom/upload_pending_map_tile_rows_and_columns.s
 * Documented in docs/maps.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void upload_pending_map_tile_rows_and_columns(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    BUS8_SET(c, 0x004376, 0);
    BUS8_SET(c, 0x004374, 0x7F);
    BUS16_SET(c, 0x004370, 0x1801);
    BUS8_SET(c, 0x002115, 0x81);
    uint8_t value = RAM8(0x002F);
    uint8_t a1;
    if (!(value & 0x80)) {
        a1 = value;
    } else {
        BUS16_SET(c, 0x004372, 0xD200);
        uint16_t value2 = RAM16(0x0078);
        BUS16_SET(c, 0x002116, value2);
        BUS8_SET(c, 0x004375, 0x40);
        BUS8_SET(c, 0x00420B, 0x80);
        BUS16_SET(c, 0x002116, (uint16_t)(value2 + 1));
        BUS8_SET(c, 0x004375, 0x40);
        BUS8_SET(c, 0x00420B, 0x80);
        a1 = 0x80;
    }
    if (value & 0x40) {
        BUS16_SET(c, 0x004372, 0xD280);
        uint16_t value3 = RAM16(0x00A6);
        BUS16_SET(c, 0x002116, value3);
        BUS8_SET(c, 0x004375, 0x40);
        BUS8_SET(c, 0x00420B, 0x80);
        BUS16_SET(c, 0x002116, (uint16_t)(value3 + 1));
        BUS8_SET(c, 0x004375, 0x40);
        BUS8_SET(c, 0x00420B, 0x80);
    }
    RAM8(0x002F) = 0;
    BUS8_SET(c, 0x002115, 0x80);
    uint8_t value4 = RAM8(0x002E);
    uint8_t a2;
    uint8_t a_hi1;
    if (!(value4 & 0x80)) {
        a2 = value4;
        a_hi1 = a >> 8;
    } else {
        BUS16_SET(c, 0x004372, 0xD000);
        uint16_t value5 = RAM16(0x0076);
        BUS16_SET(c, 0x002116, value5);
        uint8_t value6 = RAM8(0x006C);
        BUS8_SET(c, 0x004375, value6);
        BUS8_SET(c, 0x00420B, 0x80);
        RAM16_SET(0x0076, value5 | 0x20);
        BUS16_SET(c, 0x002116, ((value5 | 0x20) ^ 0x0420) & 0xFFE0);
        uint8_t value7 = RAM8(0x006D);
        BUS8_SET(c, 0x004375, value7);
        BUS8_SET(c, 0x00420B, 0x80);
        uint16_t value8 = RAM16(0x0076);
        BUS16_SET(c, 0x002116, value8);
        BUS8_SET(c, 0x004375, value6);
        BUS8_SET(c, 0x00420B, 0x80);
        BUS8_SET(c, 0x004375, value7);
        BUS16_SET(c, 0x002116, (value8 ^ 0x0400) & 0xFFE0);
        BUS8_SET(c, 0x00420B, 0x80);
        a2 = 0x80;
        a_hi1 = ((value8 ^ 0x0400) & 0xFFE0) >> 8;
    }
    uint8_t a_hi2;
    if (!(value4 & 0x40)) {
        a_hi2 = a_hi1;
    } else {
        BUS16_SET(c, 0x004372, 0xD100);
        uint16_t value9 = RAM16(0x00A4);
        BUS16_SET(c, 0x002116, value9);
        uint8_t value10 = RAM8(0x006E);
        BUS8_SET(c, 0x004375, value10);
        BUS8_SET(c, 0x00420B, 0x80);
        RAM16_SET(0x00A4, value9 | 0x20);
        BUS16_SET(c, 0x002116, ((value9 | 0x20) ^ 0x0420) & 0xFFE0);
        uint8_t value11 = RAM8(0x006F);
        BUS8_SET(c, 0x004375, value11);
        BUS8_SET(c, 0x00420B, 0x80);
        uint16_t value12 = RAM16(0x00A4);
        BUS16_SET(c, 0x002116, value12);
        BUS8_SET(c, 0x004375, value10);
        BUS8_SET(c, 0x00420B, 0x80);
        BUS8_SET(c, 0x004375, value11);
        BUS16_SET(c, 0x002116, (value12 ^ 0x0400) & 0xFFE0);
        BUS8_SET(c, 0x00420B, 0x80);
        a_hi2 = ((value12 ^ 0x0400) & 0xFFE0) >> 8;
    }
    RAM8(0x002E) = 0;
    r->a = (r->a & 0x00FF) | (a_hi2 << 8);
    r->v = value4 & 0x40;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C692, SOM_RTS, "gen", upload_pending_map_tile_rows_and_columns, 0, L_B | L_Y | L_C | L_V, 1, -1, 0, 305, 124)
