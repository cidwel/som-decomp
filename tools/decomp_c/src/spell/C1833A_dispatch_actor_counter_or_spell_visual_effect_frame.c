#include "som_c.h"
#include "som_hand_d.h"

/* C1833A dispatch_actor_counter_or_spell_visual_effect_frame   [class B, 235 bytes, 105 instructions]
 * Source: src/rom/dispatch_actor_counter_or_spell_visual_effect_frame.s
 * Documented in docs/actor-charge-frame-workers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void dispatch_actor_counter_or_spell_visual_effect_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    i_sep(r, 0x20);
    a_lda(r, RAM8(0xE060 + r->x));
    a_and(r, 0xE0);
    a_cmp(r, 0x40);
    if (!r->z) {
        a_cmp(r, 0xE0);
        if (r->z) {
            JSR(c, 0x834B, 0xC18D80); /* update_native_effect_cells_before_shared_weapon_restore */
            RETURN_RTL(c);
        }
        a_cmp(r, 0xC0);
        if (r->z) JSR(c, 0x8353, 0xC191E1); /* update_native_visual_effect_cadence_signed_motion_and_point_trail */
        RETURN_RTL(c);
    }
    /* floating number bounce, hold and retirement */
    a_lda(r, RAM8(0xE11F + r->x));
    if (r->z) {
        bool bounce = false;
        a_lda(r, RAM8(0xE11E + r->x));
        r->c = 0;
        a_adc(r, RAM8(0xE11C + r->x));
        RAM8(0xE11E + r->x) = r->a;
        bounce = !r->z;
        if (!bounce) {
            RAM8(0xE11C + r->x) = m_asl(r, RAM8(0xE11C + r->x));
            a_lda(r, RAM8(0xE11D + r->x));
            i_lsra(r);
            RAM8(0xE11D + r->x) = r->a;
            a_cmp(r, 0x02);
            bounce = r->c;
            if (!bounce) a_lda(r, 0xFF);
        }
        if (bounce) {
            a_lda(r, RAM8(0xE11E + r->x));
            if (r->n) a_eor(r, 0xFF);
            i_rep(r, 0x20);
            a_and(r, 0x007F);
            i_asla(r);
            i_asla(r);
            i_phx(c);
            i_tax(r);
            a_lda(r, BUS16(c, 0xFD22 + r->x)); /* sine table */
            if (c->fail) return;
            i_plx(c);
            a_cmp(r, 0x0100);
            i_sep(r, 0x20);
            if (r->c) a_lda(r, 0xFF);
            BUS8_SET(c, 0x4202, r->a); /* WRMPYA */
            a_lda(r, RAM8(0xE11D + r->x));
            BUS8_SET(c, 0x4203, r->a); /* WRMPYB */
            i_rep(r, 0x20);
            a_lda(r, BUS16(c, 0x4216)); /* RDMPYL */
            i_xba(r);
            i_pha(c);
            a_and(r, 0x00FF);
            a_eor(r, 0xFFFF);
            i_inca(r);
            RAM16_SET(0xE11A + r->x, r->a);
            a_lda(r, RAM16(0xE074 + r->x));
            a_and(r, 0x007F);
            r->c = 0;
            a_adc(r, RAM16(0xE11A + r->x));
            RAM16_SET(0xE11A + r->x, r->a);
            i_pla(c);
            i_sep(r, 0x20);
            i_lsra(r);
            RAM8(0xE0D1 + r->x) = r->a;
            i_lsra(r);
            RAM8(0xE0D9 + r->x) = r->a;
            JSR(c, 0x83D9, 0xC18564); /* choose_and_copy_floating_number_animated_palette */
            RETURN_RTL(c);
        }
    }
    r->c = 1;
    a_sbc(r, 0x07);
    RAM8(0xE11F + r->x) = r->a;
    if (r->c) {
        a_cmp(r, 0x38);
        if (!r->c) {
            a_lda(r, RAM8(0xE0D0 + r->x));
            a_cmp(r, RAM8(0xE0D4 + r->x));
            if (!r->z) RAM8(0xE0D0 + r->x) = m_inc(r, RAM8(0xE0D0 + r->x));
            a_lda(r, RAM8(0xE0D8 + r->x));
            a_cmp(r, RAM8(0xE0D4 + r->x));
            if (!r->z) RAM8(0xE0D8 + r->x) = m_dec(r, RAM8(0xE0D8 + r->x));
        }
        JSR(c, 0x83F7, 0xC18564); /* choose_and_copy_floating_number_animated_palette */
        RETURN_RTL(c);
    }
    i_sep(r, 0x20);
    RAM8(0xE00C + r->x) = 0;
    RAM8(0xE059 + r->x) = 0;
    RAM8(0xE060 + r->x) = 0;
    RAM8(0xE084 + r->x) = 0;
    a_bit(r, dp_rd8(c, 0x5C));
    if (r->n) {
        a_cpx(r, 0x0600);
        if (r->c) {
            a_lda(r, 0x01);
            RAM8(0xE001 + r->x) = r->a;
            RETURN_RTL(c);
        }
    }
    a_lda(r, 0x01);
    RAM8(0xE00C + r->x) = r->a;
    dp_wr16(c, 0x14, r->x);
    JSL(c, 0x8420, 0xC185E4); /* load_object_weapon_palette_from_field_069 */
    JSR(c, 0x8423, 0xC1852B); /* clear_sixteen_floating_number_tile_words */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1833A, SOM_RTL, "hand", dispatch_actor_counter_or_spell_visual_effect_frame, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 235, 105)
