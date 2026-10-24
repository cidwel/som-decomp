#include "som_c.h"

/* C11E16 actor_script_call_native_cast_preserving_context   [class A, 22 bytes, 16 instructions]
 * Source: src/rom/actor_script_call_native_cast_preserving_context.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BY.
 */
static void actor_script_call_native_cast_preserving_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    r->a = (a_hi << 8) | 0x7E;
    r->x = y;
    r->z = y == 0;
    r->n = y & 0x8000;
    r->sp -= 6;
    JSL(c, 0x1E26, 0xC0001B); /* cast_spell_public_jump */
    r->sp += 6;
    r->y = y;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC11E16, SOM_RTS, "gen", actor_script_call_native_cast_preserving_context, 0, L_B | L_Y, 6, 1, 0, 22, 16)
