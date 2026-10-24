#include "som_c.h"

/* C238B9 boss_state_prepare_spell_operand   [class A, 18 bytes, 10 instructions]
 * Source: src/rom/boss_state_prepare_spell_operand.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void boss_state_prepare_spell_operand(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    uint16_t value2;
    BUS16_PTR(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + y, RAM8(0x0232), value2);
    r->a = value2;
    r->x = value;
    r->y = (uint16_t)(y + 2);
    r->sp -= 2;
    JSR(c, 0x38C2, 0xC2396D); /* prepare_boss_spell_targets */
    r->sp += 2;
    uint16_t x_ret = r->x;
    RAM16_SET(0x0080 + x_ret, 1);
    r->a = 1;
    r->y = (uint16_t)(y + 2);
    r->z = (uint16_t)(y + 2) == 0;
    r->n = (uint16_t)(y + 2) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC238B9, SOM_RTS, "hand", boss_state_prepare_spell_operand, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 18, 10)
