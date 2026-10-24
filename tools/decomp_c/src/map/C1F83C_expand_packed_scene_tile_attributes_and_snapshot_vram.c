#include "som_c.h"

/* C1F83C expand_packed_scene_tile_attributes_and_snapshot_vram   [class D, 107 bytes, 57 instructions]
 * Source: src/rom/expand_packed_scene_tile_attributes_and_snapshot_vram.s
 * Entry: M=8 bit X=8 bit DB=any D=any.  Callers read: BYCV.
 */
static void expand_packed_scene_tile_attributes_and_snapshot_vram(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a_hi1 = a_hi;
    uint8_t x1 = 0;
    uint8_t y1 = 0;
    for (;;) {
        uint8_t value = BUS8(c, 0xC67D80 + x1);
        RAM8(0x0000 + sp0) = value;
        BUS8_SET(c, (db << 0x10) + 0x0600 + y1, (uint8_t)(value << 4));
        BUS8_SET(c, (db << 0x10) + 0x0600 + (uint8_t)(y1 + 1), RAM8(0x0000 + sp0) & 0xF0);
        x1 = (uint8_t)(x1 + 1);
        y1 = (uint8_t)(y1 + 2);
        if (!(y1 != 0)) break;
    }
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x0600);
    BUS8_SET(c, (uint16_t)(dp + 4), value3);
    BUS8_SET(c, (uint16_t)(dp + 3), 0);
    BUS8_SET(c, dp, 0);
    BUS8_SET(c, (uint16_t)(dp + 1), 0);
    BUS8_SET(c, (db << 0x10) + 0x2116, 0);
    BUS8_SET(c, (db << 0x10) + 0x2117, 0);
    BUS8_SET(c, (uint16_t)(dp + 2), 0xC6);
    BUS8_SET(c, (db << 0x10) + 0x2115, 0x80);
    uint8_t a_hi2 = a_hi1;
    uint8_t x2 = 0x20;
    uint8_t y2 = (uint8_t)((a_hi1 << 8) | 0);
    bool carry1 = 0;
    for (;;) {
        uint8_t value4 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 2)) << 0x10) + BUS16_RDP(c, dp) + y2, BUS8_RDP(c, (uint16_t)(dp + 2)));
        RAM8(0x0000 + sp0) = value4;
        uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 4));
        BUS8_SET(c, (db << 0x10) + 0x2119, (value4 & 0x0F) | value5);
        uint8_t value6 = RAM8(0x0000 + sp0);
        uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp + 4));
        BUS8_SET(c, (db << 0x10) + 0x2119, (value6 >> 4) | value7);
        uint8_t x3;
        if ((uint8_t)(x2 - 1) != 0) {
            x3 = (uint8_t)(x2 - 1);
        } else {
            uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp + 3));
            BUS8_SET(c, (uint16_t)(dp + 3), (uint8_t)(value8 + 1));
            uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp + 3));
            uint8_t value10 = BUS8_RDP(c, (db << 0x10) + 0x0600 + value9);
            BUS8_SET(c, (uint16_t)(dp + 4), value10);
            x3 = 0x20;
        }
        if ((uint8_t)(y2 + 1) != 0) {
            x2 = x3;
            y2 = (uint8_t)(y2 + 1);
            carry1 = value6 >> 3 & 0x01;
            continue;
        }
        uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp + 1));
        BUS8_SET(c, (uint16_t)(dp + 1), (uint8_t)(value11 + 1));
        uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp + 1));
        x2 = x3;
        y2 = (uint8_t)(y2 + 1);
        carry1 = value12 >= 0x20;
        if (!(value12 < 0x20)) break;
    }
    r->a = (a_hi2 << 8) | a;
    r->x = x2;
    r->y = y2;
    r->c = carry1;
    r->v = overflow;
    TAIL_CALL(c, 0xC1FA10, SOM_RTS); /* snapshot_tile_attributes_and_apply_character_row_exchange */
}
SOM_REGISTER(0xC1F83C, SOM_RTS, "gen", expand_packed_scene_tile_attributes_and_snapshot_vram, 0, L_B | L_Y | L_C | L_V, 1, 1, 1, 107, 57)
