#include "som_c.h"

/* C23843 boss_state_set_field_4a_operand   [class A, 10 bytes, 6 instructions]
 * Source: src/rom/boss_state_set_field_4a_operand.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void boss_state_set_field_4a_operand(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    uint16_t value2;
    BUS16_PTR(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + y, RAM8(0x0232), value2);
    RAM16_SET(0x004A + value, value2);
    r->a = value2;
    r->x = value;
    r->y = (uint16_t)(y + 2);
    r->z = (uint16_t)(y + 2) == 0;
    r->n = (uint16_t)(y + 2) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23843, SOM_RTS, "hand", boss_state_set_field_4a_operand, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 10, 6)
