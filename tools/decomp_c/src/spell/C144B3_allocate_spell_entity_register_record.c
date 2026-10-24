#include "som_c.h"
#include "som_hand_d.h"

/* C144B3 allocate_spell_entity_register_record   [class B, 68 bytes, 38 instructions]
 * Source: src/rom/allocate_spell_entity_register_record.s
 * Documented in docs/actor-cast-entity-registers.md
 * Entry: any width, DB and D (the routine normalises M/X and DB and restores them).  Callers read: BXYCV.
 */
static void allocate_spell_entity_register_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x30);
    i_sep(r, 0x20);
    i_phb(c);
    i_pha(c);
    a_lda(r, 0x7E);
    i_pha(c);
    i_plb(c); /* DB = $7E */
    i_pla(c); /* the caller's A.low */
    i_rep(r, 0x20);
    a_ldx(r, RAM16(0x8428)); /* free list head */
    if (!r->z) {
        a_and(r, 0x00FF);
        i_pha(c);
        a_lda(r, RAM16(r->x));
        RAM16_SET(0x8428, r->a); /* free list head = next free record */
        i_pla(c);
        RAM16_SET(r->x, r->a); /* record kind */
        i_txy(r);
        i_tax(r);
        a_lda(r, BUS16(c, 0xDCFC8E + r->x));
        a_and(r, 0x00FF);
        if (!r->z) {
            a_cmp(r, 0x0001);
            if (!r->z) i_tax(r);
        }
        i_txa(r);
        r->c = 0;
        a_adc(r, RAM16(0x8432));
        i_tax(r);
        a_lda(r, RAM16(r->x));
        RAM16_SET(0x0002 + r->y, r->a);
        i_tyx(r);
    }
    i_plb(c);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC144B3, SOM_RTS, "hand", allocate_spell_entity_register_record, 0, L_B | L_X | L_Y | L_C | L_V, 6, 1, 0, 68, 38)
