#include "som_c.h"

/* C10121 advance_actor_script_1_bytes   [class A, 10 bytes, 5 instructions]
 * Source: src/rom/advance_actor_script_1_bytes.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void advance_actor_script_1_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t y = r->y;
    RAM16_SET(0x0144 + y, (uint16_t)(RAM16(0x0144 + y) + 1));
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10121, SOM_RTS, "gen", advance_actor_script_1_bytes, 0, 0, 1, -1, 0, 10, 5)
