#include "som_c.h"

/* C759E0 append_native_saved_slot_format_pair   [class A, 12 bytes, 7 instructions]
 * Source: src/rom/append_native_saved_slot_format_pair.s
 * Documented in docs/ui-native-loaded-game-slot-descriptions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_native_saved_slot_format_pair(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    RAM8(0x9C01 + x) = (uint8_t)(a << 1);
    RAM8(0x9C00 + x) = 0x5C;
    r->x = (uint16_t)(x + 2);
    r->c = a & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC759E0, SOM_RTS, "gen", append_native_saved_slot_format_pair, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 12, 7)
