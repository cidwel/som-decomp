#include "som_c.h"

/* C75D00 derive_selected_save_slot_primary_or_backup_offset   [class A, 23 bytes, 14 instructions]
 * Source: src/rom/derive_selected_save_slot_primary_or_backup_offset.s
 * Documented in docs/ui-native-loaded-game-slot-descriptions.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void derive_selected_save_slot_primary_or_backup_offset(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool overflow = r->v;
    uint16_t value = RAM16(0xA162);
    uint16_t value2 = RAM16(0xA216);
    uint8_t a_hi1;
    uint16_t x1;
    bool carry1;
    bool overflow1;
    if (!(value2 & 0x01)) {
        a_hi1 = value2 >> 1 >> 8;
        x1 = (uint16_t)((((value & 0xFF) << 8) | 0) << 2);
        carry1 = value2 & 0x01;
        overflow1 = overflow;
    } else {
        a_hi1 = (uint16_t)((uint16_t)((((value & 0xFF) << 8) | 0) << 2) + 0x1000) >> 8;
        x1 = (uint16_t)((uint16_t)((((value & 0xFF) << 8) | 0) << 2) + 0x1000);
        carry1 = (uint16_t)((((value & 0xFF) << 8) | 0) << 2) + 0x1000 > 0xFFFF;
        overflow1 = (((uint16_t)((((value & 0xFF) << 8) | 0) << 2) ^ (uint16_t)((uint16_t)((((value & 0xFF) << 8) | 0) << 2) + 0x1000)) & ((uint16_t)((uint16_t)((((value & 0xFF) << 8) | 0) << 2) + 0x1000) ^ 0x1000) & 0x8000) != 0;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = x1;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75D00, SOM_RTS, "gen", derive_selected_save_slot_primary_or_backup_offset, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 23, 14)
