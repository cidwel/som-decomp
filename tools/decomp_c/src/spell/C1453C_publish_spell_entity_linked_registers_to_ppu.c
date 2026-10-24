#include "som_c.h"

/* C1453C publish_spell_entity_linked_registers_to_ppu   [class B, 164 bytes, 87 instructions]
 * Source: src/rom/publish_spell_entity_linked_registers_to_ppu.s
 * Documented in docs/actor-cast-entity-registers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01B4.  Callers read: BXYCV.
 */
static void publish_spell_entity_linked_registers_to_ppu(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01B4) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xB4;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM8(0x0000 + sp0 - 8) = 0x7E;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), 0x2100);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), 0);
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    uint16_t y1 = 0x842A;
    for (;;) {
        uint16_t value = RAM16(0x0001 + y1);
        if ((value & 0xFF) != 0) {
            uint16_t value2 = RAM16(0x8426);
            RAM8(0x0000 + sp0 - 8) = (uint16_t)((value & 0xFF) + value2) >> 8;
            RAM8(0x0000 + sp0 - 9) = (uint8_t)((value & 0xFF) + value2);
            uint16_t value3 = RAM16(0x0000 + (uint16_t)((value & 0xFF) + value2));
            uint16_t value4 = RAM16(0x0002 + (uint16_t)((value & 0xFF) + value2));
            uint8_t a1;
            if ((value3 & 0xFF) != 0) {
                a1 = (uint8_t)value4;
            } else {
                RAM8(0x0000 + RAM16(0x8432)) = (uint8_t)value4;
                a1 = (uint8_t)value4 | 0x80;
            }
            BUS8_SET(c, (RAM8(0x0003 + (uint16_t)(sp0 - 7)) << 0x10) + RAM16(0x0001 + (uint16_t)(sp0 - 7)) + (value3 & 0xFF), a1);
            uint8_t value6 = BUS8(c, 0xDCFC8E + (value3 & 0xFF));
            uint8_t a_hi2;
            if (value6 == 0) {
                a_hi2 = value4 >> 8;
            } else {
                uint16_t y2;
                if (value6 != 1) {
                    y2 = value3 & 0xFF;
                } else {
                    y2 = (value3 & 0xFF) + 1;
                }
                BUS8_SET(c, (RAM8(0x0003 + (uint16_t)(sp0 - 7)) << 0x10) + RAM16(0x0001 + (uint16_t)(sp0 - 7)) + y2, value4 >> 8);
                a_hi2 = value6;
            }
            uint8_t value7 = RAM8(0x0000 + sp0 - 9);
            uint8_t value8 = RAM8(0x0000 + sp0 - 8);
            a_hi1 = a_hi2;
            x1 = value3 & 0xFF;
            y1 = (value8 << 8) | value7;
            continue;
        }
        a_hi1 = 0;
        break;
    }
    uint8_t a_hi3 = a_hi1;
    uint16_t x2 = x1;
    uint16_t y3 = 0x842E;
    for (;;) {
        uint16_t value9 = RAM16(0x0001 + y3);
        if ((value9 & 0xFF) != 0) {
            uint16_t value10 = RAM16(0x8426);
            RAM8(0x0000 + sp0 - 8) = (uint16_t)((value9 & 0xFF) + value10) >> 8;
            RAM8(0x0000 + sp0 - 9) = (uint8_t)((value9 & 0xFF) + value10);
            uint16_t value11 = RAM16(0x0000 + (uint16_t)((value9 & 0xFF) + value10));
            uint16_t value12 = RAM16(0x0002 + (uint16_t)((value9 & 0xFF) + value10));
            uint8_t a2;
            if ((value11 & 0xFF) != 0) {
                a2 = (uint8_t)value12;
            } else {
                RAM8(0x0000 + RAM16(0x8432)) = (uint8_t)value12;
                a2 = (uint8_t)value12 | 0x80;
            }
            BUS8_SET(c, (RAM8(0x0003 + (uint16_t)(sp0 - 7)) << 0x10) + RAM16(0x0001 + (uint16_t)(sp0 - 7)) + (value11 & 0xFF), a2);
            uint8_t value14 = BUS8(c, 0xDCFC8E + (value11 & 0xFF));
            uint8_t a_hi4;
            if (value14 == 0) {
                a_hi4 = value12 >> 8;
            } else {
                uint16_t y4;
                if (value14 != 1) {
                    y4 = value11 & 0xFF;
                } else {
                    y4 = (value11 & 0xFF) + 1;
                }
                BUS8_SET(c, (RAM8(0x0003 + (uint16_t)(sp0 - 7)) << 0x10) + RAM16(0x0001 + (uint16_t)(sp0 - 7)) + y4, value12 >> 8);
                a_hi4 = value14;
            }
            uint8_t value15 = RAM8(0x0000 + sp0 - 9);
            uint8_t value16 = RAM8(0x0000 + sp0 - 8);
            a_hi3 = a_hi4;
            x2 = value11 & 0xFF;
            y3 = (value16 << 8) | value15;
            continue;
        }
        a_hi3 = 0;
        break;
    }
    uint8_t value17 = RAM8(0x0000 + sp0 - 7);
    uint8_t value21 = RAM8(0x0000 + sp0 - 3);
    uint8_t value22 = RAM8(0x0000 + sp0 - 2);
    uint8_t value23 = RAM8(0x0000 + sp0 - 1);
    uint8_t value24 = RAM8(0x0000 + sp0);
    r->a = (a_hi3 << 8) | value21;
    r->x = x2;
    r->y = y3;
    r->c = value22 & 0x01;
    r->v = value22 & 0x40;
    r->mf = value22 & 0x20;
    r->xf = value22 & 0x10;
    r->db = value17;
    r->dp = (value24 << 8) | value23;
    r->i = value22 & 0x04;
    r->d = value22 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1453C, SOM_RTS, "gen", publish_spell_entity_linked_registers_to_ppu, 0, L_B | L_X | L_Y | L_C | L_V, 10, 1, 0, 164, 87)
