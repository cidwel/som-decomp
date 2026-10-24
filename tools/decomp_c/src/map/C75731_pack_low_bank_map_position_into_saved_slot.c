#include "som_c.h"

/* C75731 pack_low_bank_map_position_into_saved_slot   [class A, 30 bytes, 17 instructions]
 * Source: src/rom/pack_low_bank_map_position_into_saved_slot.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void pack_low_bank_map_position_into_saved_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0;
    uint8_t a1 = 3;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = 0;
    for (;;) {
        uint8_t value = BUS8(c, 0x0000EE + y1);
        BUS8_SET(c, 0x306000 + x1, value);
        BUS8_SET(c, 0x307000 + x1, value);
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 1);
        if (!(a1 != 0)) break;
    }
    uint8_t value2 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->v = overflow;
    r->db = value2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75731, SOM_RTS, "gen", pack_low_bank_map_position_into_saved_slot, 0, L_B | L_X | L_Y | L_V, 2, 1, 0, 30, 17)
