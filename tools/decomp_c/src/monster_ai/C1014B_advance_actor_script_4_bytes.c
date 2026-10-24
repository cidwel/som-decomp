#include "som_c.h"

/* C1014B advance_actor_script_4_bytes   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/advance_actor_script_4_bytes.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E1.  Callers read: nothing.
 */
static void advance_actor_script_4_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E1) { c->fail = 3; return; }
    const uint16_t y = r->y;
    RAM16_SET(0x0144 + y, (uint16_t)(RAM16(0x0144 + y) + 4));
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1014B, SOM_RTS, "gen", advance_actor_script_4_bytes, 0, 0, 1, 1, 0, 16, 7)
