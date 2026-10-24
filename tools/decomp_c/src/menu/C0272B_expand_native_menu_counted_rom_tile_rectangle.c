#include "som_c.h"

/* C0272B expand_native_menu_counted_rom_tile_rectangle   [class B, 86 bytes, 33 instructions]
 * Source: src/rom/expand_native_menu_counted_rom_tile_rectangle.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=8 bit X=16 bit DB=$C7 D=$0000.  Callers read: BCV.
 */
static void expand_native_menu_counted_rom_tile_rectangle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0xC7, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = BUS8(c, 0xC70001 + y);
    RAM8(0xA174) = value;
    uint8_t value2 = BUS8(c, 0xC70000 + y);
    RAM8(0xA173) = value2;
    RAM8(0xA176) = RAM8(0xA174);
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        RAM8(0xA171) = RAM8(0xA173);
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        for (;;) {
            uint8_t value5 = BUS8(c, 0xC70002 + y2);
            RAM8(0x9000 + x2) = value5;
            uint8_t value6 = BUS8(c, 0xC70003 + y2);
            RAM8(0x9001 + x2) = value6 | RAM8(0xA198);
            uint8_t value8 = RAM8(0xA171);
            RAM8(0xA171) = (uint8_t)(value8 - 1);
            x2 = (uint16_t)(x2 + 2);
            y2 = (uint16_t)(y2 + 2);
            if (!((uint8_t)(value8 - 1) != 0)) break;
        }
        uint8_t value9 = RAM8(0xA176);
        RAM8(0xA176) = (uint8_t)(value9 - 1);
        uint8_t a_hi1_next = (uint16_t)(x1 + 0x40) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 0x40);
        uint16_t y1_next = y2;
        bool carry1_next = x1 + 0x40 > 0xFFFF;
        bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x40)) & ((uint16_t)(x1 + 0x40) ^ 0x40) & 0x8000) != 0;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!((uint8_t)(value9 - 1) != 0)) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0272B, SOM_RTS, "gen", expand_native_menu_counted_rom_tile_rectangle, 0, L_B | L_C | L_V, 2, 1, 0, 86, 33)
