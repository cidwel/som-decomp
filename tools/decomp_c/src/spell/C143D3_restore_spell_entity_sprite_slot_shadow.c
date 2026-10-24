#include "som_c.h"
#include "som_hand.h"

/* C143D3 restore_spell_entity_sprite_slot_shadow   [class A, 30 bytes, 20 instructions]
 * Source: src/rom/restore_spell_entity_sprite_slot_shadow.s
 * Documented in docs/actor-cast-entity-sprite-transfers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BCV.
 */
static void restore_spell_entity_sprite_slot_shadow(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;

    /* PHD, PHP, REP #$20, SEP #$20, PHB, LDA #$7E, PHA, PLB, REP #$20 */
    RAM8(sp0) = r->dp >> 8;
    RAM8((uint16_t)(sp0 - 1)) = (uint8_t)r->dp;
    RAM8((uint16_t)(sp0 - 2)) = hand_p_byte(r);
    RAM8((uint16_t)(sp0 - 3)) = r->db;
    r->db = 0x7E;
    r->a = 0x20;
    r->x = (uint16_t)(x + 0x0200);
    r->y = x;
    r->c = x + 0x0200 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((x ^ (uint16_t)(x + 0x0200)) & ((uint16_t)(x + 0x0200) ^ 0x0200) & 0x8000) != 0;
    r->mf = 0;
    r->sp = (uint16_t)(sp0 - 4);
    JSR(c, 0x43EC, 0xC14761); /* copy_native_entity_memory_bytes */
    hand_plb(c);
    hand_plp(c);
    hand_pld(c);
    r->z = r->dp == 0;
    r->n = (r->dp & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC143D3, SOM_RTS, "hand", restore_spell_entity_sprite_slot_shadow, 0, L_B | L_C | L_V, 5, 1, 0, 30, 20)
