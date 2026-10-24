#include "som_c.h"

/* C23372 derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction   [class A, 19 bytes, 9 instructions]
 * Source: src/rom/derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction.s
 * Documented in docs/boss-native-linked-parent.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0295, RAM16(0x0189 + x) & 0xFF);
    uint16_t value2 = RAM16(0x0295);
    RAM16_SET(0x002D + x, (uint16_t)(0x64 - value2) >> 1);
    r->a = (uint16_t)(0x64 - value2) >> 1;
    r->c = (uint16_t)(0x64 - value2) & 0x01;
    r->v = ((value2 ^ 0x64) & ((uint16_t)(0x64 - value2) ^ 0x64) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23372, SOM_RTS, "gen", derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 19, 9)
