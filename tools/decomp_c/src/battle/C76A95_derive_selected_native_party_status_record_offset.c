#include "som_c.h"

/* C76A95 derive_selected_native_party_status_record_offset   [class A, 15 bytes, 8 instructions]
 * Source: src/rom/derive_selected_native_party_status_record_offset.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void derive_selected_native_party_status_record_offset(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x19FE);
    r->a = (r->a & 0x00FF) | (((uint16_t)((((value & 0xFF) << 8) | 0) << 1) >> 8) << 8);
    r->y = (uint16_t)((((value & 0xFF) << 8) | 0) << 1);
    r->c = (((value & 0xFF) << 8) | 0) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76A95, SOM_RTS, "gen", derive_selected_native_party_status_record_offset, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 15, 8)
