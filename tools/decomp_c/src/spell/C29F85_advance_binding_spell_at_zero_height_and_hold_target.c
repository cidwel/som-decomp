#include "som_c.h"

/* C29F85 advance_binding_spell_at_zero_height_and_hold_target   [class B, 27 bytes, 11 instructions]
 * Source: src/rom/advance_binding_spell_at_zero_height_and_hold_target.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void advance_binding_spell_at_zero_height_and_hold_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = RAM16(0x0066 + value);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value2 != 0) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        zero1 = value2 == 0;
        negative1 = value2 & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
        r->a = 0x0127;
        r->x = value;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9F94, 0xC21394); GUARD_JSR(c, sp_call, 0x9F94); } /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all = r->a;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        zero1 = zero_ret;
        negative1 = negative_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = value;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9F97, 0xC298F6); GUARD_JSR(c, sp_call, 0x9F97); } /* mark_eligible_spell_target_control19 */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9F9A, 0xC29910); GUARD_JSR(c, sp_call, 0x9F9A); } /* set_eligible_spell_target_status_and_timer */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9F9D, 0xC2993D); GUARD_JSR(c, sp_call, 0x9F9D); } /* follow_spell_target_integer_position */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29F85, SOM_RTS, "gen", advance_binding_spell_at_zero_height_and_hold_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 27, 11)
