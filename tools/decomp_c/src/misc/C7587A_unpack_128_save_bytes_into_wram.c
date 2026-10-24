#include "som_c.h"

/* C7587A unpack_128_save_bytes_into_wram   [class A, 17 bytes, 10 instructions]
 * Source: src/rom/unpack_128_save_bytes_into_wram.s
 * Documented in docs/ui-native-loaded-game-save-load.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void unpack_128_save_bytes_into_wram(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a1 = 0x80;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    for (;;) {
        uint8_t value = BUS8(c, 0x306000 + x1);
        BUS8_SET(c, (db << 0x10) + y1, value);
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 1);
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7587A, SOM_RTS, "gen", unpack_128_save_bytes_into_wram, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 17, 10)
