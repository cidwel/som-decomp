#include "som_c.h"
#include "som_hand_d.h"

/* C14240 queue_spell_entity_sprite_slot_read   [class B, 87 bytes, 48 instructions]
 * Source: src/rom/queue_spell_entity_sprite_slot_read.s
 * Documented in docs/actor-cast-entity-sprite-transfers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: CV.
 */
static void queue_spell_entity_sprite_slot_read(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x20);
    i_phx(c);
    i_tsc(r);
    i_tcd(r); /* D = S: the slot pointer pushed above is direct page $01 */
    i_sep(r, 0x20);
    i_phb(c);
    a_lda(r, 0x7E);
    i_pha(c);
    i_plb(c);
    i_rep(r, 0x20);
    dp_wr16(c, 0x01, r->x);
    a_lda(r, 0x0002);
    JSR(c, 0x4257, 0xC12896); /* allocate_spell_entity_actor_slot */
    REQUIRE_M16(c);
    a_lda(r, 0x0020);
    RAM16_SET(0x0005 + r->x, r->a);
    a_lda(r, dp_rd16(c, 0x01));
    RAM16_SET(0x0002 + r->x, r->a);
    a_lda(r, dp_rd16(c, 0x01));
    r->c = 1;
    a_sbc(r, RAM16(0x8424));
    i_lsra(r);
    i_sep(r, 0x20);
    i_pha(c);
    RAM8(0x000A + r->x) = r->a;
    a_lda(r, 0x7E);
    RAM8(0x0004 + r->x) = r->a;
    a_lda(r, 0x80);
    RAM8(0x0000 + r->x) = r->a;
    a_lda(r, 0x3B);
    RAM8(0x0001 + r->x) = r->a;
    JSR(c, 0x4281, 0xC12997); /* publish_spell_entity_record_or_dma_channel */
    a_ldx(r, dp_rd16(c, 0x01));
    RAM8(0x0000 + r->x) = 0;
    RAM8(0x0001 + r->x) = 0;
    i_pla(c);
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    i_plb(c);
    som_wr(c, (uint16_t)(r->sp + 2), r->a); /* STA $02,S */
    i_pla(c);
    i_pla(c);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14240, SOM_RTS, "hand", queue_spell_entity_sprite_slot_read, 0, L_C | L_V, 7, 1, 0, 87, 48)
