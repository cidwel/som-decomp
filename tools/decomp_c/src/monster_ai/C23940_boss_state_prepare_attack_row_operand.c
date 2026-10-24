#include "som_c.h"

/* C23940 boss_state_prepare_attack_row_operand   [class A, 15 bytes, 9 instructions]
 * Source: src/rom/boss_state_prepare_attack_row_operand.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void boss_state_prepare_attack_row_operand(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = BUS16(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + y);
    uint16_t value2 = RAM16(0x0287);
    r->a = value;
    r->x = value2;
    r->y = (uint16_t)(y + 2);
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->sp -= 2;
    JSL(c, 0x394A, 0xC0006C); /* boss_attack_row_public_jump */
    r->sp += 2;
    uint16_t value3 = RAM16(0x0287);
    r->x = value3;
    r->y = (uint16_t)(y + 2);
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23940, SOM_RTS, "hand", boss_state_prepare_attack_row_operand, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 15, 9)
