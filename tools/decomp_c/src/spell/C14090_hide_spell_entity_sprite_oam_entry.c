#include "som_c.h"
#include "som_hand_d.h"

/* C14090 hide_spell_entity_sprite_oam_entry   [class B, 46 bytes, 26 instructions]
 * Source: src/rom/hide_spell_entity_sprite_oam_entry.s
 * Documented in docs/actor-cast-entity-projection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: Y.
 */
static void hide_spell_entity_sprite_oam_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    i_sep(r, 0x20);
    i_phb(c);
    a_lda(r, 0x7E);
    i_pha(c);
    i_plb(c);
    i_rep(r, 0x20);
    a_lda(r, 0xFFF0);
    RAM16_SET(0x0002 + r->x, r->a);
    RAM16_SET(0x0004 + r->x, 0);
    a_lda(r, RAM16(0x000A + r->x));
    a_and(r, 0x00FF);
    i_asla(r);
    i_asla(r);
    r->c = 0;
    a_adc(r, RAM16(0x841E));
    i_tax(r);
    i_sep(r, 0x20);
    a_lda(r, 0xF0);
    RAM8(0x0001 + r->x) = r->a;
    i_plb(c);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14090, SOM_RTS, "hand", hide_spell_entity_sprite_oam_entry, 0, L_Y, 5, 1, 0, 46, 26)
