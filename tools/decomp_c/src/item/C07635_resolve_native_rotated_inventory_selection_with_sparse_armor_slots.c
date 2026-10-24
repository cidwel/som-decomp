#include "som_c.h"

/* C07635 resolve_native_rotated_inventory_selection_with_sparse_armor_slots   [class B, 100 bytes, 53 instructions]
 * Source: src/rom/resolve_native_rotated_inventory_selection_with_sparse_armor_slots.s
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCV.
 */
static void resolve_native_rotated_inventory_selection_with_sparse_armor_slots(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x182E);
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x180B);
    uint16_t x2;
    if ((uint8_t)((uint8_t)a + value) < value2) {
        x2 = (a >> 8 << 8) | (uint8_t)((uint8_t)a + value);
    } else {
        uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x180B);
        uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0x1809);
        uint16_t x1;
        if (value4 < 4) {
            x1 = (a >> 8 << 8) | (uint8_t)((uint8_t)((uint8_t)a + value) - value3);
        } else {
            x1 = (uint16_t)(((a >> 8 << 8) | (uint8_t)((uint8_t)((uint8_t)a + value) - value3)) + 1);
        }
        x2 = x1;
    }
    uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0x1809);
    uint8_t a_hi2;
    uint16_t x6;
    uint16_t y2;
    if (value5 != 3) {
        uint16_t x4;
        if (value5 < 4) {
            x4 = x2;
        } else {
            uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 0x180B);
            uint16_t x3;
            if ((uint8_t)((uint8_t)x2 + 1) != value6) {
                x3 = x2;
            } else {
                x3 = 0;
            }
            x4 = x3;
        }
        a_hi2 = a >> 8;
        x6 = x4;
        y2 = y;
    } else {
        RAM8(0x0000 + sp0 - 2) = x2 >> 8;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)x2;
        uint16_t value7 = BUS16_RDP(c, (db << 0x10) + 0x186A);
        uint8_t a_hi1 = a >> 8;
        uint16_t x5 = value7;
        uint16_t y1 = (uint8_t)x2;
        for (;;) {
            if (RAM8(0xCC00 + x5) == 0xFF) {
                x5 = (uint16_t)(x5 + 1);
                continue;
            }
            x5 = (uint16_t)(x5 + 1);
            y1 = (uint16_t)(y1 - 1);
            if (!(!(y1 & 0x8000))) break;
        }
        uint16_t value9 = BUS16_RDP(c, (db << 0x10) + 0x1820);
        RAM16_SET(0x0000 + sp0 - 3, (uint16_t)((uint16_t)(x5 - 1) - value9));
        uint8_t value10 = RAM8(0x0000 + sp0 - 3);
        uint8_t value11 = RAM8(0x0000 + sp0 - 2);
        a_hi2 = (uint16_t)((uint16_t)(x5 - 1) - value9) >> 8;
        x6 = (value11 << 8) | value10;
        y2 = y1;
    }
    uint16_t value12 = BUS16_RDP(c, (db << 0x10) + 0x1820);
    BUS16_SET(c, (db << 0x10) + 0x182C, (uint16_t)((((a_hi2 << 8) | (uint8_t)x6) & 0xFF) + value12));
    uint8_t value13 = RAM8(0x0000 + sp0 - 1);
    uint8_t value14 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)((((a_hi2 << 8) | (uint8_t)x6) & 0xFF) + value12);
    r->x = (value14 << 8) | value13;
    r->y = y2;
    r->c = (((a_hi2 << 8) | (uint8_t)x6) & 0xFF) + value12 > 0xFFFF;
    r->v = (((((a_hi2 << 8) | (uint8_t)x6) & 0xFF) ^ (uint16_t)((((a_hi2 << 8) | (uint8_t)x6) & 0xFF) + value12)) & (value12 ^ (uint16_t)((((a_hi2 << 8) | (uint8_t)x6) & 0xFF) + value12)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07635, SOM_RTS, "gen", resolve_native_rotated_inventory_selection_with_sparse_armor_slots, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 4, 0, 0, 100, 53)
