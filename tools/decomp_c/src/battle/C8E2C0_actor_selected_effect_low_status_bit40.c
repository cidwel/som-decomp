#include "som_c.h"

/* C8E2C0 actor_selected_effect_low_status_bit40   [class A, 11 bytes, 5 instructions]
 * Source: src/rom/actor_selected_effect_low_status_bit40.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void actor_selected_effect_low_status_bit40(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    uint8_t value;
    hand_ldx_dp(c, 0x85);
    a_lda(r, 0x40);
    const uint32_t addr = (((uint32_t)r->db << 16) + 0xE190 + r->x) & 0xFFFFFF;
    BUS8_PTR(c, addr, 0xE1, value);   /* an unmapped read returns the operand high byte left on the bus */
    a_ora(r, value);
    BUS8_SET(c, addr, r->a);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E2C0, SOM_RTS, "hand", actor_selected_effect_low_status_bit40, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 11, 5)
