#include "som_c.h"

/* C10285 jump_actor_script_after_1_bytes   [class A, 8 bytes, 4 instructions]
 * Source: src/rom/jump_actor_script_after_1_bytes.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E3.  Callers read: A.
 */
static void jump_actor_script_after_1_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E3) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0144 + y);
    r->x = (uint16_t)(value + 1);
    r->z = (uint16_t)(value + 1) == 0;
    r->n = (uint16_t)(value + 1) & 0x8000;
    JSR(c, 0x028B, 0xC10245); /* jump_actor_script_relative_operand */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10285, SOM_RTS, "gen", jump_actor_script_after_1_bytes, 0, L_A, 1, 1, 0, 8, 4)
