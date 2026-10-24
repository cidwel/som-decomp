#include "som_c.h"

/* C756D0 write_current_map_word_to_both_saved_slot_copies   [class A, 17 bytes, 6 instructions]
 * Source: src/rom/write_current_map_word_to_both_saved_slot_copies.s
 * Documented in docs/ui-native-loaded-game-save-write.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYV.
 */
static void write_current_map_word_to_both_saved_slot_copies(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0108);
    BUS16_SET(c, 0x3062B9 + x, value);
    BUS16_SET(c, 0x3072B9 + x, value);
    r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC756D0, SOM_RTS, "gen", write_current_map_word_to_both_saved_slot_copies, 0, L_B | L_Y | L_V, 1, 1, 0, 17, 6)
