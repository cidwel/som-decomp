#include "som_c.h"

/* C757B1 pack_six_party_name_bytes_into_two_slot_copies   [class A, 21 bytes, 11 instructions]
 * Source: src/rom/pack_six_party_name_bytes_into_two_slot_copies.s
 * Documented in docs/ui-native-loaded-game-save-write.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void pack_six_party_name_bytes_into_two_slot_copies(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a1 = 6;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    for (;;) {
        uint8_t value = RAM8(0x0000 + y1);
        BUS8_SET(c, 0x306000 + x1, value);
        BUS8_SET(c, 0x307000 + x1, value);
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 1);
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC757B1, SOM_RTS, "gen", pack_six_party_name_bytes_into_two_slot_copies, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 21, 11)
