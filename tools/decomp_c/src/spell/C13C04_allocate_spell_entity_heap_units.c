#include "som_c.h"

/* C13C04 allocate_spell_entity_heap_units   [class B, 180 bytes, 101 instructions]
 * Source: src/rom/allocate_spell_entity_heap_units.s
 * Documented in docs/actor-cast-entity-memory.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: BXY.
 */
static void allocate_spell_entity_heap_units(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0A) + 0x7 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 0x0A) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0C) = 0x7E;
    RAM8(0x0002 + (uint16_t)(sp0 - 0x0A)) = (uint8_t)value;
    RAM8(0x0003 + (uint16_t)(sp0 - 0x0A)) = 0;
    RAM8(0x0007 + (uint16_t)(sp0 - 0x0A)) = 1;
    uint16_t value2 = RAM16(0x8238);
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0A), value2);
    RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) = (uint8_t)(0xF0 - RAM8(0x8238));
    RAM8(0x0006 + (uint16_t)(sp0 - 0x0A)) = RAM8(0x0002 + (uint16_t)(sp0 - 0x0A));
    uint8_t a_hi1 = value >> 8;
    uint16_t x1 = value2;
    uint16_t y1 = y;
    for (;;) {
        uint8_t value5 = RAM8(0x823A + x1);
        uint16_t x4;
        uint16_t y6;
        if (value5 != 0) {
            RAM8(0x0006 + (uint16_t)(sp0 - 0x0A)) = RAM8(0x0002 + (uint16_t)(sp0 - 0x0A));
            RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0A), x1);
            RAM8(0x0001 + (uint16_t)(sp0 - 0x0A))--;
            if (RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) != 0) {
                x1 = (uint16_t)(x1 + 1);
                continue;
            }
            x4 = 0;
            y6 = y1;
        } else {
            RAM8(0x0006 + (uint16_t)(sp0 - 0x0A))--;
            uint16_t x3;
            uint16_t y5;
            if (RAM8(0x0006 + (uint16_t)(sp0 - 0x0A)) == 0) {
                uint8_t value7 = RAM8(0x0001 + (uint16_t)(sp0 - 0x0A));
                uint8_t value8 = RAM8(0x8236);
                if ((uint8_t)(0xF0 - value7) != value8) {
                    if ((uint8_t)(0xF0 - value7) >= value8) {
                        RAM8(0x8236) = (uint8_t)(0xF0 - value7);
                    }
                }
                uint16_t value9 = RAM16(0x0004 + (uint16_t)(sp0 - 0x0A));
                uint16_t value10 = RAM16(0x8238);
                uint8_t a1;
                uint8_t a_hi3;
                uint16_t y4;
                if (value9 != value10) {
                    a1 = (uint8_t)value9;
                    a_hi3 = value9 >> 8;
                    y4 = y1;
                } else {
                    uint16_t value11 = RAM16(0x0002 + (uint16_t)(sp0 - 0x0A));
                    uint8_t a_hi2 = (uint16_t)(value9 + value11) >> 8;
                    uint16_t y2 = (uint16_t)(value9 + value11);
                    for (;;) {
                        uint8_t value12 = RAM8(0x823A + y2);
                        uint16_t y3;
                        if (value12 == 0) {
                            y3 = y2;
                        } else {
                            RAM8(0x0001 + (uint16_t)(sp0 - 0x0A))--;
                            if (RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) != 0) {
                                y2 = (uint16_t)(y2 + 1);
                                continue;
                            }
                            y3 = 0;
                        }
                        y2 = y3;
                        break;
                    }
                    RAM16_SET(0x8238, y2);
                    uint16_t value13 = RAM16(0x0004 + (uint16_t)(sp0 - 0x0A));
                    a1 = (uint8_t)(value13 - 1);
                    a_hi3 = (uint16_t)(value13 - 1) >> 8;
                    y4 = y2;
                }
                RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0A), (uint16_t)(((a_hi3 << 8) | a1) + 1));
                RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) = RAM8(0x0002 + (uint16_t)(sp0 - 0x0A));
                uint8_t a_hi4 = (uint16_t)(((a_hi3 << 8) | a1) + 1) >> 8;
                uint16_t x2 = (uint16_t)(((a_hi3 << 8) | a1) + 1);
                do {
                    RAM8(0x823A + x2) = RAM8(0x0001 + (uint16_t)(sp0 - 0x0A));
                    RAM8(0x832A + x2) = RAM8(0x0007 + (uint16_t)(sp0 - 0x0A));
                    RAM8(0x0001 + (uint16_t)(sp0 - 0x0A))--;
                    x2 = (uint16_t)(x2 + 1);
                } while (RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) != 0);
                x3 = (uint16_t)((uint16_t)(RAM16(0x0004 + (uint16_t)(sp0 - 0x0A)) << 6) + 0x8200);
                y5 = y4;
            } else {
                RAM8(0x0001 + (uint16_t)(sp0 - 0x0A))--;
                if (RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) != 0) {
                    x1 = (uint16_t)(x1 + 1);
                    continue;
                }
                x3 = 0;
                y5 = y1;
            }
            x4 = x3;
            y6 = y5;
        }
        x1 = x4;
        y1 = y6;
        break;
    }
    uint8_t value18 = RAM8(0x0000 + sp0 - 0x0A);
    uint8_t value19 = RAM8(0x0000 + sp0 - 2);
    uint8_t value20 = RAM8(0x0000 + sp0 - 1);
    uint8_t value21 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)((uint16_t)(sp0 - 0x0A) + 7);
    r->x = x1;
    r->y = y1;
    r->mf = value19 & 0x20;
    r->xf = value19 & 0x10;
    r->db = value18;
    r->dp = (value21 << 8) | value20;
    r->i = value19 & 0x04;
    r->d = value19 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13C04, SOM_RTS, "gen", allocate_spell_entity_heap_units, 0, L_B | L_X | L_Y, 13, 0, 0, 180, 101)
