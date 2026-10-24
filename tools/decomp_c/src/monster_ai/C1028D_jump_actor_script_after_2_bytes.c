#include "som_c.h"

/* C1028D jump_actor_script_after_2_bytes   [class A, 9 bytes, 5 instructions]
 * Source: src/rom/jump_actor_script_after_2_bytes.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void jump_actor_script_after_2_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0144 + y);
    r->x = (uint16_t)(value + 2);
    r->z = (uint16_t)(value + 2) == 0;
    r->n = (uint16_t)(value + 2) & 0x8000;
    JSR(c, 0x0294, 0xC10245); /* jump_actor_script_relative_operand */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1028D, SOM_RTS, "gen", jump_actor_script_after_2_bytes, 0, 0, 1, 1, 0, 9, 5)
