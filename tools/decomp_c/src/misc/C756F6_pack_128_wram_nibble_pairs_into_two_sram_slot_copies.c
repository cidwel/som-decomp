#include "som_c.h"

/* C756F6 pack_128_wram_nibble_pairs_into_two_sram_slot_copies   [class A, 40 bytes, 19 instructions]
 * Source: src/rom/pack_128_wram_nibble_pairs_into_two_sram_slot_copies.s
 * Documented in docs/ui-native-loaded-game-save-write.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXV.
 */
static void pack_128_wram_nibble_pairs_into_two_sram_slot_copies(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM8(0xA175) = 0x80;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    do {
        RAM8(0xA1CB) = (uint8_t)(RAM8(0x0000 + y1) << 4);
        uint8_t value2 = RAM8(0x0001 + y1);
        uint8_t value3 = RAM8(0xA1CB);
        BUS8_SET(c, 0x306000 + x1, (value2 & 0x0F) | value3);
        BUS8_SET(c, 0x307000 + x1, (value2 & 0x0F) | value3);
        RAM8(0xA175)--;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 2);
    } while (RAM8(0xA175) != 0);
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC756F6, SOM_RTS, "gen", pack_128_wram_nibble_pairs_into_two_sram_slot_copies, 0, L_B | L_X | L_V, 1, 1, 0, 40, 19)
