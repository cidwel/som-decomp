#include "som_c.h"

/* C02642 consume_native_menu_party_variant_rectangle   [class B, 43 bytes, 22 instructions]
 * Source: src/rom/consume_native_menu_party_variant_rectangle.s
 * Entry: M=8 bit X=16 bit DB=$C7 D=$0000.  Callers read: ABXYCZNV.
 */
static void consume_native_menu_party_variant_rectangle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0xC7, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = BUS16(c, 0xC70000 + y);
    RAM8(0x0000 + sp0) = (uint16_t)(y + 2) >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)(y + 2);
    RAM8(0x0000 + sp0 - 2) = value >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)value;
    uint8_t value2 = RAM8(0x19FE);
    uint16_t x1 = 0xFFFF;
    bool carry1 = carry;
    for (;;) {
        bool carry2;
        if ((uint16_t)(x1 + 1) == 3) {
            carry2 = (uint16_t)(x1 + 1) >= 3;
        } else {
            uint8_t value3 = BUS8_RDP(c, (uint16_t)(x1 + 0xDA));
            if ((uint8_t)(value2 + 1) != value3) {
                x1 = (uint16_t)(x1 + 1);
                carry1 = (uint8_t)(value2 + 1) >= value3;
                continue;
            }
            carry2 = (uint8_t)(value2 + 1) >= value3;
        }
        x1 = (uint16_t)(x1 + 1);
        carry1 = carry2;
        break;
    }
    uint8_t value4 = BUS8_RDP(c, (uint16_t)(x1 + 0xEE));
    uint16_t y1;
    if ((value4 & 3) == 0) {
        y1 = 0x7703;
    } else {
        y1 = 0x7765;
    }
    r->a = a_hi << 8 | (value4 & 3);
    r->x = value;
    r->y = y1;
    r->c = carry1;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->v = overflow;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x266A, 0xC0272B); GUARD_JSR(c, sp_call, 0x266A); } /* expand_native_menu_counted_rom_tile_rectangle */
    r->sp += 2;
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->y = (value6 << 8) | value5;
    r->z = ((value6 << 8) | value5) == 0;
    r->n = ((value6 << 8) | value5) & 0x8000;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02642, SOM_RTS, "gen", consume_native_menu_party_variant_rectangle, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, 1, 0, 43, 22)
