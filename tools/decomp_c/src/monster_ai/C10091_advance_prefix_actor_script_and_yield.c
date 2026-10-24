#include "som_c.h"

/* C10091 advance_prefix_actor_script_and_yield   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/advance_prefix_actor_script_and_yield.s
 * Documented in docs/actor-program-prefix-copies.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void advance_prefix_actor_script_and_yield(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0144 + y);
    RAM16_SET(0x0144 + y, (uint16_t)((((a_hi << 8) | a) & 0xFF) + value));
    r->a = 0;
    r->c = (((a_hi << 8) | a) & 0xFF) + value > 0xFFFF;
    r->z = 1;
    r->n = 0;
    r->v = (((((a_hi << 8) | a) & 0xFF) ^ (uint16_t)((((a_hi << 8) | a) & 0xFF) + value)) & (value ^ (uint16_t)((((a_hi << 8) | a) & 0xFF) + value)) & 0x8000) != 0;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10091, SOM_RTS, "gen", advance_prefix_actor_script_and_yield, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 16, 7)
