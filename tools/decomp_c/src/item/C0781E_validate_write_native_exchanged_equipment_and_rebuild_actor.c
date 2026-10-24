#include "som_c.h"
#include "som_hand_b.h"

/* C0781E validate_write_native_exchanged_equipment_and_rebuild_actor   [class B, 72 bytes, hand written]
 * Source: src/rom/validate_write_native_exchanged_equipment_and_rebuild_actor.s
 *
 * A = equipment id, X = equipment field offset.  Steps:
 *   1. ask the eligibility test for the selected hero (A, Y = X / 2 byte swapped); when it answers "not eligible"
 *      and the ring category ($1809) is not 3, the id is replaced by $0015 (the stored copy of A on the stack);
 *   2. write the id (masked to 7 bits) with the weapon palette alias; for category 3 refresh the equipped sprite id;
 *   3. rebuild the actor stats from the field's hero bits (X & $0600).
 * The stack is real: the callees may read it and the push/pull widths follow the registers the callees leave.
 * Entry: any widths, any bank for the category byte (it is read through the data bank).
 */
static void validate_write_native_exchanged_equipment_and_rebuild_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    r->mf = 0; r->xf = 0;                        /* REP #$30 */
    push16(c, r->x);                             /* PHX */
    push16(c, r->a);                             /* PHA */
    push16(c, r->a);                             /* PHA */
    r->a = r->x; zn(r, r->a, 0);                 /* TXA */
    i_lsra(r);                                   /* LSR */
    r->a = (uint16_t)((r->a << 8) | (r->a >> 8)); zn(r, r->a, 1);   /* XBA */
    r->y = r->a; zn(r, r->y, 0);                 /* TAY */
    r->a = pull16(c); zn(r, r->a, 0);            /* PLA */
    { const uint16_t sp_call = r->sp; JSL(c, 0x782B, 0xC079C7); GUARD_JSL(c, sp_call, 0x782B); }   /* test_native_menu_item_eligibility_for_selected_hero */
    if (r->z) {                                  /* BNE not taken: not eligible */
        r->mf = 1;                               /* SEP #$20 */
        a_lda(r, BUS8(c, ((uint32_t)r->db << 16) | 0x1809));   /* LDA $1809 */
        a_cmp(r, 0x03);
        if (!r->z) {                             /* BEQ not taken: category is not 3 */
            r->mf = 0; r->xf = 0;                /* REP #$30 */
            r->a = 0x0015; zn(r, r->a, 0);       /* LDA #$0015 */
            RAM16_SET((uint16_t)(r->sp + 1), r->a);   /* STA $01,S replaces the stored id */
        }
    }
    r->mf = 0; r->xf = 0;                        /* REP #$30 */
    r->a = pull16(c); zn(r, r->a, 0);            /* PLA */
    r->x = pull16(c); zn(r, r->x, 0);            /* PLX */
    r->mf = 1;                                   /* SEP #$20 */
    a_and(r, 0x7F);
    { const uint16_t sp_call = r->sp; JSR(c, 0x7848, 0xC07A7D); GUARD_JSR(c, sp_call, 0x7848); }   /* write_native_actor_equipment_field_with_weapon_palette_alias */
    i_phx(c);                                    /* PHX: one or two bytes, as the callee left X */
    if (!r->mf) { c->fail = 3; return; }         /* LDA/CMP #$03 below are 8-bit immediates */
    a_lda(r, BUS8(c, ((uint32_t)r->db << 16) | 0x1809));       /* LDA $1809 */
    a_cmp(r, 0x03);
    if (r->z) {                                  /* BNE not taken: category 3 */
        r->mf = 0;                               /* REP #$20 */
        r->a = r->x; zn(r, r->a, 0);             /* TXA */
        a_ora(r, 0xE180);                        /* ORA #$E180 */
        r->x = r->a; zn(r, r->x, r->xf);         /* TAX */
        { const uint16_t sp_call = r->sp; JSR(c, 0x785A, 0xC07699); GUARD_JSR(c, sp_call, 0x785A); }   /* refresh_native_equipped_sprite_id_and_clear_pose_offsets */
    }
    r->mf = 0; r->xf = 0;                        /* REP #$30 */
    r->a = pull16(c); zn(r, r->a, 0);            /* PLA */
    a_and(r, 0x0600);
    r->x = r->a; zn(r, r->x, 0);                 /* TAX */
    { const uint16_t sp_call = r->sp; JSR(c, 0x7864, 0xC07A28); GUARD_JSR(c, sp_call, 0x7864); }   /* rebuild_native_equipped_actor_stats_and_cap_persistent_mana */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0781E, SOM_RTS, "hand", validate_write_native_exchanged_equipment_and_rebuild_actor, 0, L_ALL, 6, -1, -1, 72, 39)
