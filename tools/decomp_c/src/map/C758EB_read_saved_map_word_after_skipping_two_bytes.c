#include "som_c.h"

/* C758EB read_saved_map_word_after_skipping_two_bytes   [class A, 15 bytes, 7 instructions]
 * Source: src/rom/read_saved_map_word_after_skipping_two_bytes.s
 * Documented in docs/ui-native-loaded-game-save-load.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BYCV.
 */
static void read_saved_map_word_after_skipping_two_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t x = r->x;
    uint16_t value = BUS16(c, 0x306000 + (uint16_t)(x + 2));
    RAM16_SET(0x0108, value);
    r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC758EB, SOM_RTS, "gen", read_saved_map_word_after_skipping_two_bytes, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 15, 7)
