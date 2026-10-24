#include "som_c.h"

/* C7626A snapshot_native_shop_item_selection_records   [class A, 40 bytes, 19 instructions]
 * Source: src/rom/snapshot_native_shop_item_selection_records.s
 * Documented in docs/event-menu-shop-tiles.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYC.
 */
static void snapshot_native_shop_item_selection_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    RAM8(0xA24E) = RAM8(0xA222);
    uint8_t a1 = 0x10;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    for (;;) {
        uint8_t value2 = RAM8(0xA136 + x1);
        RAM8(0xA23E + x1) = value2;
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value2;
        x1 = (uint16_t)(x1 + 1);
        if (!(a1 != 0)) break;
    }
    uint8_t a_hi2 = a_hi1;
    uint16_t x2 = 0;
    uint16_t y1 = 8;
    for (;;) {
        RAM8(0xA24F + x2) = RAM8(0xA223 + x2);
        x2 = (uint16_t)(x2 + 1);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    r->a = (a_hi2 << 8) | a;
    r->x = x2;
    r->y = y1;
    r->c = carry;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC7626A, SOM_RTL, "gen", snapshot_native_shop_item_selection_records, 0, L_B | L_X | L_Y | L_C, 1, 1, 0, 40, 19)
