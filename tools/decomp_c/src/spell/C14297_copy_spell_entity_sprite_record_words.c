#include "som_c.h"
#include "som_hand.h"

/* C14297 copy_spell_entity_sprite_record_words   [class B, 79 bytes, 52 instructions]
 * Source: src/rom/copy_spell_entity_sprite_record_words.s
 * Documented in docs/actor-cast-entity-sprite-transfers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: CV.
 */
static void copy_spell_entity_sprite_record_words(SomCtx *c)
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
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = hand_p_byte(r); /* PHP */
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 0x0A) = r->db; /* PHB */
    RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0C) = 0x7E;
    RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) = (uint8_t)value;
    RAM8(0x0005 + (uint16_t)(sp0 - 0x0A)) = value >> 8;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0A), y);
    RAM16_SET(0x0006 + (uint16_t)(sp0 - 0x0A), x);
    uint16_t value2 = RAM16(0x0006 + (uint16_t)(sp0 - 0x0A));
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0A), (RAM16(0x0001 + (uint16_t)(sp0 - 0x0A)) & 0x0F) + 1);
    uint8_t a_hi1 = 0;
    uint16_t x1 = (uint16_t)(((value & 0xF0) >> 3) + value2);
    uint16_t y1 = 0;
    do {
        uint16_t value4;
        BUS16_OK(c, (RAM8(0x0005 + (uint16_t)(sp0 - 0x0A)) << 0x10) + RAM16(0x0003 + (uint16_t)(sp0 - 0x0A)) + y1, value4);
        RAM16_SET(0x0000 + x1, value4);
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0A), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 0x0A)) - 1));
        a_hi1 = value4 >> 8;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 2);
    } while (RAM16(0x0001 + (uint16_t)(sp0 - 0x0A)) != 0);
    /* PLB, TSC, CLC, ADC #, TCS, PLP, PLD: the pulls read what the routine may have overwritten */
    r->db = RAM8((uint16_t)(sp0 - 10));
    r->sp = (uint16_t)(sp0 - 3);
    hand_plp(c);
    r->dp = (uint16_t)(RAM8((uint16_t)(sp0 - 1)) | (RAM8(sp0) << 8));
    r->sp = sp0;
    r->z = r->dp == 0;
    r->n = (r->dp & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14297, SOM_RTS, "hand", copy_spell_entity_sprite_record_words, 0, L_C | L_V, 13, 1, 0, 79, 52)
