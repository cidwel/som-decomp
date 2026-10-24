#include "som_c.h"

/* C23934 boss_state_external_actor_command_operand   [class A, 12 bytes, 8 instructions]
 * Source: src/rom/boss_state_external_actor_command_operand.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void boss_state_external_actor_command_operand(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value;
    BUS16_PTR(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + y, RAM8(0x0232), value);
    r->a = value;
    r->y = (uint16_t)(y + 2);
    r->sp -= 2;
    JSR(c, 0x393B, 0xC23963); /* boss_external_actor_command_if_selected */
    r->sp += 2;
    uint16_t value2 = RAM16(0x0287);
    r->x = value2;
    r->y = (uint16_t)(y + 2);
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23934, SOM_RTS, "hand", boss_state_external_actor_command_operand, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 12, 8)
