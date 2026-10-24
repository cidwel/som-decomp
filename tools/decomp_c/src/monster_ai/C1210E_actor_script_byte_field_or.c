#include "som_c.h"

/* C1210E actor_script_byte_field_or   [class A, 21 bytes, 8 instructions]
 * Source: src/rom/actor_script_byte_field_or.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_script_byte_field_or(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2110, 0xC11FEB); GUARD_JSR(c, sp_call, 0x2110); } /* resolve_actor_script_field_reference */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    RAM8(0x0000 + sp0) = x_ret >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret;
    uint8_t value = RAM8(0x0180 + x_ret);
    uint8_t value3 = BUS8(c, 0xD04F18 + RAM16(0x0144 + y));
    RAM8(0x0180 + x_ret) = value | value3;
    r->a = (a_all >> 8 << 8) | (value | value3);
    r->z = x_ret == 0;
    r->n = x_ret & 0x8000;
    r->mf = 1;
    r->xf = 0;
    TAIL_CALL(c, 0xC1014B, SOM_RTS); /* advance_actor_script_4_bytes */
}
SOM_REGISTER(0xC1210E, SOM_RTS, "gen", actor_script_byte_field_or, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 21, 8)
