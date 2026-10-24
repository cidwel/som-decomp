#include "som_c.h"

/* C12997 publish_spell_entity_record_or_dma_channel   [class D, 135 bytes, 65 instructions]
 * Source: src/rom/publish_spell_entity_record_or_dma_channel.s
 * Documented in docs/actor-cast-entity-events.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: BXYCZNV.
 */
static void publish_spell_entity_record_or_dma_channel(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0x0000 + sp0 - 6) = 0x7E;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    if (x != 0) {
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
        uint8_t value = RAM8(0x000F + x);
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        if (value == 5) {
            uint8_t value2 = RAM8(0x0009 + x);
            r->x = (((uint16_t)(sp0 - 5) >> 8 << 8) | value2) & 0xFF;
            r->c = value >= 5;
            r->z = ((((uint16_t)(sp0 - 5) >> 8 << 8) | value2) & 0xFF) == 0;
            r->n = (((uint16_t)(sp0 - 5) >> 8 << 8) | value2) & 0xFF & 0x8000;
            r->dp = (uint16_t)(sp0 - 5);
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0x29DD, 0xC14720); GUARD_JSR(c, sp_call, 0x29DD); } /* find_highest_set_entity_flag_bit */
            r->sp += 6;
            uint16_t a_all = r->a;
            uint16_t value3 = RAM16(0x0001 + (uint16_t)(sp0 - 5));
            BUS16_SET(c, 0x004370 + (uint16_t)(a_all << 4), RAM16(0x0000 + value3));
            BUS16_SET(c, 0x004371 + (uint16_t)(a_all << 4), RAM16(0x0001 + value3));
            BUS16_SET(c, 0x004374 + (uint16_t)(a_all << 4), RAM16(0x0004 + value3));
            uint16_t value7 = RAM16(0x0002 + value3);
            BUS16_SET(c, 0x004372 + (uint16_t)(a_all << 4), value7);
            RAM8(0x821E) = RAM8(0x0009 + value3) | RAM8(0x821E);
            if (RAM8(0x0009 + value3) == 0x80) {
                RAM16_SET(0x8228, value3);
            }
            a_hi1 = value7 >> 8;
            x1 = (uint16_t)(a_all << 4);
            y1 = value3;
        } else {
            RAM8(0x000F + x) = value | 0x80;
            uint16_t value11 = RAM16(0x821A);
            uint16_t value12 = RAM16(0x8214);
            uint16_t value13 = RAM16(0x0001 + (uint16_t)(sp0 - 5));
            RAM16_SET(0x0000 + (uint16_t)((uint16_t)(value11 << 1) + value12), value13);
            RAM8(0x821A)++;
            a_hi1 = value13 >> 8;
            x1 = (uint16_t)((uint16_t)(value11 << 1) + value12);
            y1 = y;
        }
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
    } else {
        a_hi2 = (uint16_t)(sp0 - 5) >> 8;
        x2 = x;
        y2 = y;
    }
    uint8_t value14 = RAM8(0x0000 + sp0 - 5);
    uint8_t value16 = RAM8(0x0000 + sp0 - 3);
    uint8_t value17 = RAM8(0x0000 + sp0 - 2);
    uint8_t value18 = RAM8(0x0000 + sp0 - 1);
    uint8_t value19 = RAM8(0x0000 + sp0);
    r->a = (a_hi2 << 8) | value16;
    r->x = x2;
    r->y = y2;
    r->c = value17 & 0x01;
    r->z = ((value19 << 8) | value18) == 0;
    r->n = ((value19 << 8) | value18) & 0x8000;
    r->v = value17 & 0x40;
    r->mf = value17 & 0x20;
    r->xf = value17 & 0x10;
    r->db = value14;
    r->dp = (value19 << 8) | value18;
    r->i = value17 & 0x04;
    r->d = value17 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12997, SOM_RTS, "gen", publish_spell_entity_record_or_dma_channel, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 0, 0, 135, 65)
