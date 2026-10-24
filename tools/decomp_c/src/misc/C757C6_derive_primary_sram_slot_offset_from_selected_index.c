#include "som_c.h"

/* C757C6 derive_primary_sram_slot_offset_from_selected_index   [class A, 15 bytes, 9 instructions]
 * Source: src/rom/derive_primary_sram_slot_offset_from_selected_index.s
 * Documented in docs/ui-native-loaded-game-save-write.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void derive_primary_sram_slot_offset_from_selected_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0xA211);
    r->a = (r->a & 0x00FF) | (((uint16_t)((((value & 0xFF) << 8) | 0) << 2) >> 8) << 8);
    r->x = (uint16_t)((((value & 0xFF) << 8) | 0) << 2);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC757C6, SOM_RTS, "gen", derive_primary_sram_slot_offset_from_selected_index, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 15, 9)
