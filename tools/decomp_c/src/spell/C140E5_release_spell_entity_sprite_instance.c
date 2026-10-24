#include "som_c.h"
#include "som_hand_d.h"

/* C140E5 release_spell_entity_sprite_instance   [class B, 51 bytes, 32 instructions]
 * Source: src/rom/release_spell_entity_sprite_instance.s
 * Documented in docs/actor-cast-entity-sprite-activation.md
 * Entry: any M, X, DB and D (the routine sets DB itself and restores everything).  Callers read: BYCV.
 */
static void release_spell_entity_sprite_instance(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    i_phb(c);
    i_tsc(r);
    i_tcd(r); /* D = S: the byte at direct page $01 is the counter pushed below */
    i_sep(r, 0x20);
    i_phb(c);
    a_lda(r, 0x7E);
    i_pha(c);
    i_plb(c);
    a_lda(r, RAM8(0x8420));
    if (!r->z) {
        JSR(c, 0x40FA, 0xC140BE); /* release_spell_entity_individual_sprite_instance */
    } else {
        RAM8(0x0008 + r->x) = 0;
        i_txy(r);
        a_lda(r, 0x04);
        dp_wr8(c, 0x01, r->a);
        do {
            i_phy(c);
            a_ldx(r, RAM16(r->y));
            JSR(c, 0x410B, 0xC140BE); /* release_spell_entity_individual_sprite_instance */
            i_ply(c);
            i_iny(r);
            i_iny(r);
            const uint8_t left = dp_rd8(c, 0x01) - 1;
            dp_wr8(c, 0x01, left);
            hand_nz8(r, left);
        } while (!r->z);
    }
    i_plb(c);
    i_pla(c);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC140E5, SOM_RTS, "hand", release_spell_entity_sprite_instance, 0, L_B | L_Y | L_C | L_V, 7, -1, -1, 51, 32)
