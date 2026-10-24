#include "som_c.h"

/* C2395C boss_state_jump_to_operand_pointer   [class A, 7 bytes, 4 instructions]
 * Source: src/rom/boss_state_jump_to_operand_pointer.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void boss_state_jump_to_operand_pointer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value;
    BUS16_PTR(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + y, RAM8(0x0232), value);
    RAM16_SET(0x0230, value);
    uint16_t value2 = RAM16(0x02C5);
    r->a = value;
    r->y = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2395C, SOM_RTS, "hand", boss_state_jump_to_operand_pointer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 7, 4)
