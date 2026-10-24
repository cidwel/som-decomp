#include "som_c.h"

/* C29FA0 finish_binding_spell_contact_and_clear_selected_command_global_control   [class B, 29 bytes, 13 instructions]
 * Source: src/rom/finish_binding_spell_contact_and_clear_selected_command_global_control.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void finish_binding_spell_contact_and_clear_selected_command_global_control(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint8_t value2 = RAM8(0x009E + value);
    if (value2 != 0) {
        r->a = (a_hi << 8) | value2;
        r->x = value;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9FB4, 0xC298F6); GUARD_JSR(c, sp_call, 0x9FB4); } /* mark_eligible_spell_target_control19 */
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9FB7, 0xC29910); GUARD_JSR(c, sp_call, 0x9FB7); } /* set_eligible_spell_target_status_and_timer */
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9FBA, 0xC2993D); GUARD_JSR(c, sp_call, 0x9FBA); } /* follow_spell_target_integer_position */
        r->c = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = (a_hi << 8) | value2;
    r->x = value;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9FA9, 0xC29FBD); GUARD_JSR(c, sp_call, 0x9FA9); } /* clear_spell_status_and_mark_reciprocal_contacts */
    r->a = 0x8A00;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9FAF, 0xC23963); GUARD_JSR(c, sp_call, 0x9FAF); } /* boss_external_actor_command_if_selected */
    r->c = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29FA0, SOM_RTS, "gen", finish_binding_spell_contact_and_clear_selected_command_global_control, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 29, 13)
