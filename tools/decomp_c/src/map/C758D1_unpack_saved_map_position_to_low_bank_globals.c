#include "som_c.h"

/* C758D1 unpack_saved_map_position_to_low_bank_globals   [class A, 26 bytes, 16 instructions]
 * Source: src/rom/unpack_saved_map_position_to_low_bank_globals.s
 * Documented in docs/ui-native-loaded-game-save-load.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void unpack_saved_map_position_to_low_bank_globals(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = db;
    RAM8(0x0000 + sp0 - 1) = 0;
    uint8_t a1 = 3;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = 0;
    for (;;) {
        uint8_t value = BUS8(c, 0x306000 + x1);
        BUS8_SET(c, 0x0000EE + y1, value);
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
    r->c = carry;
    r->v = overflow;
    r->db = value2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC758D1, SOM_RTS, "gen", unpack_saved_map_position_to_low_bank_globals, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 26, 16)
