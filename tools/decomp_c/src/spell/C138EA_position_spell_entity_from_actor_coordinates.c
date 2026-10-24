#include "som_c.h"
#include "som_hand.h"

/* C138EA position_spell_entity_from_actor_coordinates   [class B, 65 bytes, 39 instructions]
 * Source: src/rom/position_spell_entity_from_actor_coordinates.s
 * Documented in docs/actor-cast-entity-sprite-instances.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void position_spell_entity_from_actor_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = hand_p_byte(r); /* PHP */
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = r->db; /* PHB */
    RAM8(0x0000 + sp0 - 6) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), RAM16(0xE045 + (((uint8_t)((((a_hi << 8) | a) & 0xFF) << 1) << 8) | ((((a_hi << 8) | a) & 0xFF) << 1 >> 8))) & 0xFF);
    RAM16_SET(0x0002 + x, RAM16(0xE020 + (((uint8_t)((((a_hi << 8) | a) & 0xFF) << 1) << 8) | ((((a_hi << 8) | a) & 0xFF) << 1 >> 8))));
    uint16_t value3 = RAM16(0xE022 + (((uint8_t)((((a_hi << 8) | a) & 0xFF) << 1) << 8) | ((((a_hi << 8) | a) & 0xFF) << 1 >> 8)));
    uint16_t value4 = RAM16(0x0001 + (uint16_t)(sp0 - 5));
    RAM16_SET(0x0000 + x, (uint16_t)((uint16_t)(value3 - value4) - 8));
    r->a = (r->a & 0x00FF) | (((uint16_t)((uint16_t)(value3 - value4) - 8) >> 8) << 8);
    r->x = ((uint8_t)((((a_hi << 8) | a) & 0xFF) << 1) << 8) | ((((a_hi << 8) | a) & 0xFF) << 1 >> 8);
    r->y = x;
    /* PLB, SEP #$20, PLA, PLA, PLP, PLD: the pulls read what STA $01 may have overwritten */
    r->db = RAM8((uint16_t)(sp0 - 5));
    r->a = (uint16_t)((r->a & 0xFF00) | RAM8((uint16_t)(sp0 - 3)));
    r->sp = (uint16_t)(sp0 - 3);
    hand_plp(c);
    r->dp = (uint16_t)(RAM8((uint16_t)(sp0 - 1)) | (RAM8(sp0) << 8));
    r->sp = sp0;
    r->z = r->dp == 0;
    r->n = (r->dp & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC138EA, SOM_RTS, "hand", position_spell_entity_from_actor_coordinates, 0, L_B | L_X | L_Y | L_C | L_V, 8, 1, 0, 65, 39)
