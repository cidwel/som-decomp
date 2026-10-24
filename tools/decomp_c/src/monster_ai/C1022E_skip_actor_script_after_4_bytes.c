#include "som_c.h"

/* C1022E skip_actor_script_after_4_bytes   [class A, 11 bytes, 7 instructions]
 * Source: src/rom/skip_actor_script_after_4_bytes.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E1.  Callers read: nothing.
 */
static void skip_actor_script_after_4_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E1) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0144 + y);
    r->x = (uint16_t)(value + 4);
    r->z = (uint16_t)(value + 4) == 0;
    r->n = (uint16_t)(value + 4) & 0x8000;
    JSR(c, 0x0237, 0xC101F7); /* skip_actor_script_relative_operand */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1022E, SOM_RTS, "gen", skip_actor_script_after_4_bytes, 0, 0, 1, 1, 0, 11, 7)
