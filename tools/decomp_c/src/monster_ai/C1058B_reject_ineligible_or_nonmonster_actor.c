#include "som_c.h"

/* C1058B reject_ineligible_or_nonmonster_actor   [class A, 13 bytes, 7 instructions]
 * Source: src/rom/reject_ineligible_or_nonmonster_actor.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void reject_ineligible_or_nonmonster_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x058D, 0xC1054A); GUARD_JSR(c, sp_call, 0x058D); } /* test_actor_target_eligibility */
    uint16_t x_ret = r->x;
    bool zero_ret = r->z;
    if (!zero_ret) {
        r->c = 1;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value = RAM8(0x0180 + x_ret);
    SET_A8(r, value);
    r->c = value >= 0x80;
    r->z = value == 0x80;
    r->n = (uint8_t)(value - 0x80) & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1058B, SOM_RTS, "gen", reject_ineligible_or_nonmonster_actor, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 13, 7)
