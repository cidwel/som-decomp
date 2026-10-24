#include "som_c.h"
#include "som_hand_d.h"

/* C1345A release_spell_entity_visual_resource   [class B, 135 bytes, 66 instructions]
 * Source: src/rom/release_spell_entity_visual_resource.s
 * Documented in docs/actor-cast-entity-resource-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void release_spell_entity_visual_resource(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    /* a seven byte frame below the saved D and P holds the locals; D points into it, so direct page = stack */
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    i_tsc(r);
    r->c = 1;
    a_sbc(r, 0x0007);
    i_tcd(r);
    i_tcs(r);
    i_sep(r, 0x20);
    i_phb(c);
    a_lda(r, 0x7E);
    i_pha(c);
    i_plb(c);
    dp_wr16(c, 0x04, r->x); /* entity */
    dp_wr16(c, 0x06, r->y);
    i_txy(r);
    a_lda(r, 4);
    dp_wr8(c, 0x01, r->a); /* slots left */
    for (;;) {
        dp_wr16(c, 0x02, r->y); /* current slot pointer */
        a_ldx(r, RAM16(r->y));
        if (r->z) break;
        JSR(c, 0x347E, 0xC143D3); /* restore_spell_entity_sprite_slot_shadow */
        REQUIRE_M8X16(c);
        a_ldy(r, dp_rd16(c, 0x02));
        a_ldx(r, RAM16(r->y));
        JSR(c, 0x3486, 0xC141F8); /* queue_spell_entity_sprite_slot_write */
        REQUIRE_M8X16(c);
        a_ldy(r, dp_rd16(c, 0x02));
        i_iny(r);
        i_iny(r);
        const uint8_t left = dp_rd8(c, 0x01) - 1;
        dp_wr8(c, 0x01, left);
        hand_nz8(r, left);
        if (left == 0) break;
    }
    a_ldx(r, dp_rd16(c, 0x04));
    a_lda(r, RAM8(0x0024 + r->x));
    if (!r->z) {
        a_ldx(r, dp_rd16(c, 0x06));
        a_lda(r, RAM8(0x002C + r->x));
        if (r->z) {
            a_lda(r, 0x30);
            JSR(c, 0x34A1, 0xC144B3); /* allocate_spell_entity_register_record */
            REQUIRE_M8X16(c);
            a_lda(r, 0x02);
            RAM8(0x0002 + r->x) = r->a;
            JSR(c, 0x34A9, 0xC14514); /* append_spell_entity_transient_register_record */
            REQUIRE_M8X16(c);
            a_lda(r, 0x31);
            JSR(c, 0x34AE, 0xC144B3);
            REQUIRE_M8X16(c);
            a_lda(r, RAM8(0x0023));
            RAM8(0x0002 + r->x) = r->a;
            JSR(c, 0x34B8, 0xC14514);
            REQUIRE_M8X16(c);
            a_lda(r, 0x32);
            JSR(c, 0x34BD, 0xC144B3);
            REQUIRE_M8X16(c);
            a_lda(r, 0xE0);
            RAM8(0x0002 + r->x) = r->a;
            JSR(c, 0x34C5, 0xC14514);
            REQUIRE_M8X16(c);
        }
    }
    JSR(c, 0x34C8, 0xC12FE4); /* wait_for_spell_entity_irq_completion */
    REQUIRE_M8X16(c);
    a_lda(r, 0xFF);
    a_ldx(r, dp_rd16(c, 0x04));
    JSR(c, 0x34CF, 0xC130E2); /* release_selected_spell_entity_sprite_pointers */
    REQUIRE_M8X16(c);
    a_ldx(r, dp_rd16(c, 0x04));
    JSR(c, 0x34D4, 0xC13D7D); /* release_spell_entity_heap_with_saved_bank */
    i_plb(c);
    i_rep(r, 0x20);
    i_tsc(r);
    r->c = 0;
    a_adc(r, 0x0007);
    i_tcs(r);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1345A, SOM_RTS, "hand", release_spell_entity_visual_resource, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 12, 1, 0, 135, 66)
