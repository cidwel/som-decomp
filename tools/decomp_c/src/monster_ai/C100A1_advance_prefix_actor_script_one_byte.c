#include "som_c.h"

/* C100A1 advance_prefix_actor_script_one_byte   [class A, 10 bytes, 5 instructions]
 * Source: src/rom/advance_prefix_actor_script_one_byte.s
 * Documented in docs/actor-program-prefix-copies.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void advance_prefix_actor_script_one_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    RAM16_SET(0x0144 + y, (uint16_t)(RAM16(0x0144 + y) + 1));
    r->a = 0xFFFF;
    r->x = y;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC100A1, SOM_RTS, "gen", advance_prefix_actor_script_one_byte, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 10, 5)
