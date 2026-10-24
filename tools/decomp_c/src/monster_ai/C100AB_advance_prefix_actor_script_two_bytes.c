#include "som_c.h"

/* C100AB advance_prefix_actor_script_two_bytes   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/advance_prefix_actor_script_two_bytes.s
 * Documented in docs/actor-program-prefix-copies.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void advance_prefix_actor_script_two_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0144 + y);
    RAM16_SET(0x0144 + y, (uint16_t)(value + 2));
    r->a = 0xFFFF;
    r->c = value + 2 > 0xFFFF;
    r->z = 0;
    r->n = 1;
    r->v = ((value ^ (uint16_t)(value + 2)) & ((uint16_t)(value + 2) ^ 2) & 0x8000) != 0;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC100AB, SOM_RTS, "gen", advance_prefix_actor_script_two_bytes, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 16, 7)
