#include "som_c.h"
#include "som_hand_d.h"

/* C13690 decrement_spell_entity_all_color_channels   [class B, 35 bytes, 19 instructions]
 * Source: src/rom/decrement_spell_entity_all_color_channels.s
 * Documented in docs/actor-cast-entity-resource-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any (the callees need DB=$7E).  Callers read: ABXYCZNV.
 */
static void decrement_spell_entity_all_color_channels(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    i_sep(r, 0x20);
    JSR(c, 0x3698, 0xC144A1); /* get_spell_entity_register_shadow */
    a_lda(r, RAM8(0x0032 + r->x));
    a_ora(r, 0xE0);
    a_cmp(r, 0xE0);
    if (!r->z) {
        i_deca(r);
        i_pha(c);
        a_lda(r, 0x32);
        JSR(c, 0x36A8, 0xC144B3); /* allocate_spell_entity_register_record */
        i_pla(c);
        RAM8(0x0002 + r->x) = r->a;
        JSR(c, 0x36AF, 0xC14514); /* append_spell_entity_transient_register_record */
    }
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13690, SOM_RTS, "hand", decrement_spell_entity_all_color_channels, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, 1, 0, 35, 19)
