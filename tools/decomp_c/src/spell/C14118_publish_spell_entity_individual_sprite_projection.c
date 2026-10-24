#include "som_c.h"

/* C14118 publish_spell_entity_individual_sprite_projection   [class A, 18 bytes, 13 instructions]
 * Source: src/rom/publish_spell_entity_individual_sprite_projection.s
 * Documented in docs/actor-cast-entity-projection.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: Y.
 */
static void publish_spell_entity_individual_sprite_projection(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;

    /* PHD, PHP, REP #$20, SEP #$20, PHB, LDA #$7E, PHA, PLB */
    RAM8(sp0) = r->dp >> 8;
    RAM8((uint16_t)(sp0 - 1)) = (uint8_t)r->dp;
    RAM8((uint16_t)(sp0 - 2)) = hand_p_byte(r);
    RAM8((uint16_t)(sp0 - 3)) = r->db;
    RAM8((uint16_t)(sp0 - 4)) = 0x7E; /* PHA; PLB pulls it straight back */
    r->db = 0x7E;
    r->mf = 1;
    SET_A8(r, 0x7E);
    r->z = 0;
    r->n = 0;
    r->sp = (uint16_t)(sp0 - 4);
    JSR(c, 0x4125, 0xC13E9C); /* project_spell_entity_sprite_record_to_oam */
    hand_plb(c);
    hand_plp(c);
    hand_pld(c);
    r->z = r->dp == 0;
    r->n = (r->dp & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14118, SOM_RTS, "hand", publish_spell_entity_individual_sprite_projection, 0, L_Y, 5, -1, 0, 18, 13)
