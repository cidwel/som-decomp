#include "som_c.h"
#include "som_hand.h"

/* C141E1 release_spell_entity_sprite_slot   [class A, 23 bytes, 15 instructions]
 * Source: src/rom/release_spell_entity_sprite_slot.s
 * Documented in docs/actor-cast-entity-sprite-transfers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BYCV.
 */
static void release_spell_entity_sprite_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;
    /* PHD, PHP */
    RAM8(sp0) = r->dp >> 8;
    RAM8((uint16_t)(sp0 - 1)) = (uint8_t)r->dp;
    RAM8((uint16_t)(sp0 - 2)) = hand_p_byte(r);
    RAM8((uint16_t)(sp0 - 3)) = r->db; /* PHB */
    r->db = 0x7E;
    r->sp = (uint16_t)(sp0 - 4);
    RAM16_SET(r->x, 0x8000);
    r->a = 0x8000;
    r->mf = 0;
    r->sp = (uint16_t)(sp0 - 4);
    hand_plb(c);
    hand_plp(c);
    hand_pld(c);
    r->z = r->dp == 0;
    r->n = (r->dp & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC141E1, SOM_RTS, "hand", release_spell_entity_sprite_slot, 0, L_B | L_Y | L_C | L_V, 5, -1, -1, 23, 15)
