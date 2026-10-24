#include "som_c.h"
#include "som_hand.h"

/* C1433E rotate_spell_entity_words_backward   [class B, 90 bytes, 54 instructions]
 * Source: src/rom/rotate_spell_entity_words_backward.s
 * Documented in docs/actor-cast-entity-resource-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: CV.
 */
static void rotate_spell_entity_words_backward(SomCtx *c)
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
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 9) = r->db; /* PHB */
    RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7E;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), x);
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), value);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), value & 0xFF);
    uint16_t value2 = RAM16(0x0005 + (uint16_t)(sp0 - 9));
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), (((uint8_t)value2 << 8) | (value2 >> 8)) & 0xFF);
    uint16_t value3 = RAM16(0x0003 + (uint16_t)(sp0 - 9));
    if ((uint16_t)(((((uint8_t)value2 << 8) | (value2 >> 8)) & 0xFF) - value3) != 0) {
        if (((((uint8_t)value2 << 8) | (value2 >> 8)) & 0xFF) >= value3) {
            RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), (uint16_t)(((((uint8_t)value2 << 8) | (value2 >> 8)) & 0xFF) - value3));
            RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0005 + (uint16_t)(sp0 - 9)) << 1));
            uint16_t value5 = RAM16(0x0005 + (uint16_t)(sp0 - 9));
            uint16_t value6 = RAM16(0x0000 + (uint16_t)(x + value5));
            RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), value6);
            uint8_t a_hi1 = value6 >> 8;
            uint16_t x1 = (uint16_t)(x + value5);
            do {
                uint16_t value7 = RAM16(0x0000 + (uint16_t)(x1 - 2));
                RAM16_SET(0x0002 + (uint16_t)(x1 - 2), value7);
                RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0003 + (uint16_t)(sp0 - 9)) - 1));
                a_hi1 = value7 >> 8;
                x1 = (uint16_t)(x1 - 2);
            } while (RAM16(0x0003 + (uint16_t)(sp0 - 9)) != 0);
            RAM16_SET(0x0000 + x1, RAM16(0x0005 + (uint16_t)(sp0 - 9)));
        }
    }
    /* PLB, TSC, CLC, ADC #, TCS, PLP, PLD: the pulls read what the routine may have overwritten */
    r->db = RAM8((uint16_t)(sp0 - 9));
    r->sp = (uint16_t)(sp0 - 3);
    hand_plp(c);
    r->dp = (uint16_t)(RAM8((uint16_t)(sp0 - 1)) | (RAM8(sp0) << 8));
    r->sp = sp0;
    r->z = r->dp == 0;
    r->n = (r->dp & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1433E, SOM_RTS, "hand", rotate_spell_entity_words_backward, 0, L_C | L_V, 12, 1, 0, 90, 54)
