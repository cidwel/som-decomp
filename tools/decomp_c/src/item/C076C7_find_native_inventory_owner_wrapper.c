#include "som_c.h"

/* C076C7 find_native_inventory_owner_wrapper   [class B, 78 bytes, 39 instructions]
 * Source: src/rom/find_native_inventory_owner_wrapper.s
 * Documented in docs/event-menu-inventory-ownership.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCV.
 */
static void find_native_inventory_owner_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = ((((uint8_t)(a + 1) << 8) | a_hi) >> 2) & 0xC0;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x186A);
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x1809);
    uint8_t y1;
    if (value2 != 3) {
        y1 = 0x0B;
    } else {
        y1 = 8;
    }
    uint8_t a_hi1 = 0;
    uint8_t x1 = value;
    uint8_t y2 = y1;
    for (;;) {
        uint8_t value3 = RAM8(0xCC00 + x1);
        uint8_t x3;
        uint8_t y4;
        if (value3 == 0xFF) {
            if ((uint8_t)(y2 - 1) != 0) {
                x1 = (uint8_t)(x1 + 1);
                y2 = (uint8_t)(y2 - 1);
                continue;
            }
            x3 = (uint8_t)(x1 + 1);
            y4 = (uint8_t)(y2 - 1);
        } else {
            uint8_t value4 = RAM8(0x0000 + sp0 - 1);
            uint8_t x2;
            uint8_t y3;
            if ((value3 & 0xC0) == value4) {
                uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0x1820);
                if (value5 != 0) {
                    RAM8(0xCC00 + x1) = value3 & 0x3F;
                }
                x2 = x1;
                y3 = y2;
            } else {
                if ((uint8_t)(y2 - 1) != 0) {
                    x1 = (uint8_t)(x1 + 1);
                    y2 = (uint8_t)(y2 - 1);
                    continue;
                }
                x2 = (uint8_t)(x1 + 1);
                y3 = (uint8_t)(y2 - 1);
            }
            x3 = x2;
            y4 = y3;
        }
        x1 = x3;
        y2 = y4;
        break;
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value6;
    r->x = x1;
    r->y = y2;
    r->c = value7 & 0x01;
    r->v = value7 & 0x40;
    r->mf = value7 & 0x20;
    r->xf = value7 & 0x10;
    r->i = value7 & 0x04;
    r->d = value7 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC076C7, SOM_RTS, "gen", find_native_inventory_owner_wrapper, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 78, 39)
