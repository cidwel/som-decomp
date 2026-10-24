#include "som_c.h"

/* C29D93 initialize_pull_spell_and_capture_parent_facing   [class B, 51 bytes, 20 instructions]
 * Source: src/rom/initialize_pull_spell_and_capture_parent_facing.s
 * Documented in docs/boss-native-spell-pull-child.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void initialize_pull_spell_and_capture_parent_facing(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    uint16_t current_object_dp0 = RAM16(CURRENT_OBJECT_DP0 + dp);
    uint16_t value = RAM16(0x00B0 + current_object_dp0);
    RAM8(0x00BE + current_object_dp0) = RAM8(0x00B8 + value);
    uint8_t value3 = RAM8(0x00B4 + current_object_dp0);
    uint8_t value4 = BUS8(c, 0xDCE6FF + ((a_hi << 8) | (uint8_t)(value3 << 1)));
    uint16_t current_object_dp02 = RAM16(CURRENT_OBJECT_DP0 + dp);
    r->a = (a_hi << 8) | value4;
    r->x = current_object_dp02;
    r->y = value;
    r->c = value3 & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DAB, 0xC21394); GUARD_JSR(c, sp_call, 0x9DAB); } /* select_boss_animation_and_reset_frame_cursor */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DAE, 0xC29A2B); GUARD_JSR(c, sp_call, 0x9DAE); } /* request_status_spell_start_sound */
    uint16_t x_ret2 = r->x;
    RAM16_SET(OBJECT_PHASE + x_ret2, (uint16_t)(RAM16(OBJECT_PHASE + x_ret2) + 1));
    RAM16_SET(0x0022 + x_ret2, 0x07FF);
    RAM16_SET(0x0098 + x_ret2, RAM16(0x0098 + x_ret2) & 0x7FFF);
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DC3, 0xC298DA); GUARD_JSR(c, sp_call, 0x9DC3); } /* activate_spell_child_and_clear_fractional_height */
    r->c = 0;
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29D93, SOM_RTS, "gen", initialize_pull_spell_and_capture_parent_facing, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 51, 20)
