#include "som_c.h"

/* C11635 actor_script_set_second_target_self   [class A, 17 bytes, 9 instructions]
 * Source: src/rom/actor_script_set_second_target_self.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_set_second_target_self(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t y = r->y;
    RAM8(0x01AD + y) = (uint16_t)(y - 0xE000) >> 9;
    r->a = ((uint8_t)(y - 0xE000) << 8) | ((uint16_t)(y - 0xE000) >> 9);
    r->c = (uint16_t)(y - 0xE000) >> 8 & 0x01;
    r->z = (uint16_t)(y - 0xE000) >> 9 == 0;
    r->n = (uint16_t)(y - 0xE000) >> 9 & 0x80;
    r->v = ((y ^ 0xE000) & (y ^ (uint16_t)(y - 0xE000)) & 0x8000) != 0;
    TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
}
SOM_REGISTER(0xC11635, SOM_RTS, "gen", actor_script_set_second_target_self, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 17, 9)
