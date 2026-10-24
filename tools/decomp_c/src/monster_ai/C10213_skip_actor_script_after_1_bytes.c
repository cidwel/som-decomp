#include "som_c.h"

/* C10213 skip_actor_script_after_1_bytes   [class A, 8 bytes, 4 instructions]
 * Source: src/rom/skip_actor_script_after_1_bytes.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: A.
 */
static void skip_actor_script_after_1_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0144 + y);
    r->x = (uint16_t)(value + 1);
    r->z = (uint16_t)(value + 1) == 0;
    r->n = (uint16_t)(value + 1) & 0x8000;
    JSR(c, 0x0219, 0xC101F7); /* skip_actor_script_relative_operand */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10213, SOM_RTS, "gen", skip_actor_script_after_1_bytes, 0, L_A, 1, -1, 0, 8, 4)
