#include "som_c.h"

/* C10239 skip_actor_script_after_5_bytes   [class A, 12 bytes, 8 instructions]
 * Source: src/rom/skip_actor_script_after_5_bytes.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void skip_actor_script_after_5_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0144 + y);
    r->x = (uint16_t)(value + 5);
    r->z = (uint16_t)(value + 5) == 0;
    r->n = (uint16_t)(value + 5) & 0x8000;
    JSR(c, 0x0243, 0xC101F7); /* skip_actor_script_relative_operand */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10239, SOM_RTS, "gen", skip_actor_script_after_5_bytes, 0, 0, 1, 0, 0, 12, 8)
