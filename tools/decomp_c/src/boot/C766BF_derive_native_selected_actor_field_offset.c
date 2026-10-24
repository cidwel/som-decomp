#include "som_c.h"

/* C766BF derive_native_selected_actor_field_offset   [class A, 34 bytes, 15 instructions]
 * Source: src/rom/derive_native_selected_actor_field_offset.s
 * Documented in docs/ui-native-spell-item-labels.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void derive_native_selected_actor_field_offset(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0xA173, (uint16_t)((((RAM16(0x19FE) & 0xFF) << 8) | 0) << 1));
    uint16_t value2 = RAM16(0xA175);
    uint16_t value3 = RAM16(0xA173);
    uint16_t value4 = RAM16(0xA171);
    r->a = (r->a & 0x00FF) | (0 << 8);
    r->x = (uint16_t)((uint16_t)((value2 & 0xFF) + value3) + value4 + ((value2 & 0xFF) + value3 > 0xFFFF));
    r->c = (uint16_t)((value2 & 0xFF) + value3) + value4 + ((value2 & 0xFF) + value3 > 0xFFFF) > 0xFFFF;
    r->v = (((uint16_t)((value2 & 0xFF) + value3) ^ (uint16_t)((uint16_t)((value2 & 0xFF) + value3) + value4 + ((value2 & 0xFF) + value3 > 0xFFFF))) & (value4 ^ (uint16_t)((uint16_t)((value2 & 0xFF) + value3) + value4 + ((value2 & 0xFF) + value3 > 0xFFFF))) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC766BF, SOM_RTS, "gen", derive_native_selected_actor_field_offset, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 34, 15)
