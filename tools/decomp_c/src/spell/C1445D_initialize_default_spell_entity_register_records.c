#include "som_c.h"
#include "som_hand.h"

/* C1445D initialize_default_spell_entity_register_records   [class B, 68 bytes, 40 instructions]
 * Source: src/rom/initialize_default_spell_entity_register_records.s
 * Documented in docs/actor-cast-entity-registers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void initialize_default_spell_entity_register_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = hand_p_byte(r); /* PHP */
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM8(0x0000 + sp0 - 8) = 0x7E;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 7), 0xFCC2);
    RAM8(0x0004 + (uint16_t)(sp0 - 7)) = 0xDC;
    RAM8(0x0001 + (uint16_t)(sp0 - 7)) = 0x26;
    uint8_t a_hi1 = (uint16_t)(sp0 - 7) >> 8;
    uint16_t x1 = 0xFCC2;
    uint16_t y1 = y;
    bool carry1 = (uint16_t)(sp0 - 3) >= 4;
    bool overflow1 = (((uint16_t)(sp0 - 3) ^ 4) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    do {
        uint8_t value;
        BUS8_OK(c, (RAM8(0x0004 + (uint16_t)(sp0 - 7)) << 0x10) + RAM16(0x0002 + (uint16_t)(sp0 - 7)), value);
        r->a = (a_hi1 << 8) | value;
        r->y = y1;
        r->c = carry1;
        r->z = value == 0;
        r->n = value & 0x80;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = (uint16_t)(sp0 - 7);
        r->sp -= 8;
        JSR(c, 0x4480, 0xC144B3); /* allocate_spell_entity_register_record */
        r->sp += 8;
        uint16_t x_ret = r->x;
        uint8_t value2;
        BUS8_OK(c, (RAM8(0x0004 + (uint16_t)(sp0 - 7)) << 0x10) + RAM16(0x0002 + (uint16_t)(sp0 - 7)) + 1, value2);
        RAM8(0x0002 + x_ret) = value2;
        RAM8(0x0003 + x_ret) = 0;
        r->y = 1;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 8;
        JSR(c, 0x448E, 0xC14514); /* append_spell_entity_transient_register_record */
        r->sp += 8;
        uint16_t a_all2 = r->a;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        uint16_t value3 = RAM16(0x0002 + (uint16_t)(sp0 - 7));
        RAM16_SET(0x0002 + (uint16_t)(sp0 - 7), (uint16_t)(value3 + 2));
        RAM8(0x0001 + (uint16_t)(sp0 - 7))--;
        a_hi1 = a_all2 >> 8;
        x1 = (uint16_t)(value3 + 2);
        y1 = y_ret2;
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
    } while (RAM8(0x0001 + (uint16_t)(sp0 - 7)) != 0);
    uint8_t value7 = RAM8(0x0000 + sp0 - 3);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    (void)value8;
    (void)value9;
    r->a = (a_hi1 << 8) | value7;   /* PLB, PLA x4 */
    r->x = x1;
    r->y = y1;
    r->db = RAM8((uint16_t)(sp0 - 7));
    r->sp = (uint16_t)(sp0 - 3);
    hand_plp(c);
    r->dp = (uint16_t)(RAM8((uint16_t)(sp0 - 1)) | (RAM8(sp0) << 8));
    r->sp = sp0;
    r->z = r->dp == 0;
    r->n = (r->dp & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1445D, SOM_RTS, "hand", initialize_default_spell_entity_register_records, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 9, 1, 0, 68, 40)
