#include "som_c.h"

/* C2394F boss_state_request_sound_operand   [class A, 13 bytes, 7 instructions]
 * Source: src/rom/boss_state_request_sound_operand.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void boss_state_request_sound_operand(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = BUS16(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + y);
    r->a = value;
    r->x = 0x0F;
    r->y = (uint16_t)(y + 2);
    JSR(c, 0x3958, 0xC230E3); /* request_boss_sound_with_parameter_word */
    uint16_t value2 = RAM16(0x0287);
    r->x = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2394F, SOM_RTS, "hand", boss_state_request_sound_operand, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 13, 7)
