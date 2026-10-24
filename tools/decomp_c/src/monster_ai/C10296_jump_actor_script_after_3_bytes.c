#include "som_c.h"

/* C10296 jump_actor_script_after_3_bytes   [class A, 10 bytes, 6 instructions]
 * Source: src/rom/jump_actor_script_after_3_bytes.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void jump_actor_script_after_3_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0144 + y);
    r->x = (uint16_t)(value + 3);
    r->z = (uint16_t)(value + 3) == 0;
    r->n = (uint16_t)(value + 3) & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x029E, 0xC10245); GUARD_JSR(c, sp_call, 0x029E); } /* jump_actor_script_relative_operand */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10296, SOM_RTS, "gen", jump_actor_script_after_3_bytes, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 10, 6)
