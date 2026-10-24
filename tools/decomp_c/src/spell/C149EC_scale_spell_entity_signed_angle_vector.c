#include "som_c.h"

/* C149EC scale_spell_entity_signed_angle_vector   [class B, 188 bytes, 106 instructions]
 * Source: src/rom/scale_spell_entity_signed_angle_vector.s
 * Documented in docs/actor-cast-entity-signed-vectors.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XY.
 */
static void scale_spell_entity_signed_angle_vector(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0C) + 0x9 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 0x0C) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0E) = 0x7E;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0C), value);
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0C), 0);
    uint8_t a1;
    uint8_t a_hi1;
    if (!(x & 0x8000)) {
        a1 = (uint8_t)x;
        a_hi1 = x >> 8;
    } else {
        RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0C), (uint16_t)(RAM16(0x0002 + (uint16_t)(sp0 - 0x0C)) - 1));
        a1 = (uint8_t)((x ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)((x ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0C), (a_hi1 << 8) | a1);
    uint8_t value2 = RAM8(0x0001 + (uint16_t)(sp0 - 0x0C));
    r->a = (a_hi1 << 8) | value2;
    r->c = (uint16_t)(sp0 - 5) >= 7;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->v = (((uint16_t)(sp0 - 5) ^ 7) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 0x0C)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 0x0C);
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4A1A, 0xC148D9); GUARD_JSR(c, sp_call, 0x4A1A); } /* lookup_native_spell_sprite_angle_coefficient */
    r->sp += 13;
    uint16_t a_all = r->a;
    uint8_t a6;
    uint8_t a_hi6;
    uint16_t x4;
    if ((uint8_t)a_all == 0) {
        uint8_t a3;
        uint8_t a_hi2;
        uint16_t x2;
        if (a_all >> 8 & 0x80) {
            uint16_t value3 = RAM16(0x0004 + (uint16_t)(sp0 - 0x0C));
            a3 = 0;
            a_hi2 = (uint16_t)((value3 ^ 0xFFFF) + 1) >> 8;
            x2 = (uint16_t)((value3 ^ 0xFFFF) + 1);
        } else {
            uint8_t a2;
            uint16_t x1;
            if (a_all >> 8 == 0) {
                a2 = a_all >> 8;
                x1 = 0;
            } else {
                uint16_t value4 = RAM16(0x0004 + (uint16_t)(sp0 - 0x0C));
                a2 = 0;
                x1 = value4;
            }
            a3 = a2;
            a_hi2 = (uint8_t)a_all;
            x2 = x1;
        }
        a6 = a3;
        a_hi6 = a_hi2;
        x4 = x2;
    } else {
        RAM8(0x0002 + (uint16_t)(sp0 - 0x0C)) = (a_all >> 8) ^ RAM8(0x0002 + (uint16_t)(sp0 - 0x0C));
        RAM8(0x0009 + (uint16_t)(sp0 - 0x0C)) = (uint8_t)a_all;
        uint8_t value6 = RAM8(0x0004 + (uint16_t)(sp0 - 0x0C));
        BUS16_SET(c, 0x004202, (value6 << 8) | (uint8_t)a_all);
        RAM8(0x0000 + sp0 - 0x0D) = value6;
        RAM8(0x0000 + sp0 - 0x0E) = (uint8_t)((value6 << 8) | (uint8_t)a_all);
        uint16_t value7 = BUS16(c, 0x004216);
        uint8_t value8 = RAM8(0x0002 + (uint16_t)(sp0 - 0x0C));
        RAM8(0x0002 + (uint16_t)(sp0 - 0x0C)) <<= 1;
        uint8_t a4;
        uint8_t a_hi3;
        if (!(value8 & 0x80)) {
            a4 = (uint8_t)value7;
            a_hi3 = value7 >> 8;
        } else {
            a4 = (uint8_t)((value7 ^ 0xFFFF) + 1);
            a_hi3 = (uint16_t)((value7 ^ 0xFFFF) + 1) >> 8;
        }
        RAM16_SET(0x0006 + (uint16_t)(sp0 - 0x0C), (a_hi3 << 8) | a4);
        RAM8(0x0008 + (uint16_t)(sp0 - 0x0C)) = 0;
        if ((a_hi3 & 0x80) != 0) {
            RAM8(0x0008 + (uint16_t)(sp0 - 0x0C))--;
        }
        uint16_t value9 = RAM16(0x0007 + (uint16_t)(sp0 - 0x0C));
        uint8_t value10 = RAM8(0x0005 + (uint16_t)(sp0 - 0x0C));
        uint8_t a_hi5;
        uint16_t x3;
        if (value10 == 0) {
            a_hi5 = a4;
            x3 = value9;
        } else {
            uint8_t value11 = RAM8(0x0009 + (uint16_t)(sp0 - 0x0C));
            BUS16_SET(c, 0x004202, (value11 << 8) | value10);
            RAM8(0x0000 + sp0 - 0x0D) = value11;
            RAM8(0x0000 + sp0 - 0x0E) = (uint8_t)((value11 << 8) | value10);
            uint16_t value12 = BUS16(c, 0x004216);
            uint8_t value13 = RAM8(0x0002 + (uint16_t)(sp0 - 0x0C));
            RAM8(0x0002 + (uint16_t)(sp0 - 0x0C)) <<= 1;
            uint8_t a5;
            uint8_t a_hi4;
            if (!(value13 & 0x80)) {
                a5 = (uint8_t)value12;
                a_hi4 = value12 >> 8;
            } else {
                a5 = (uint8_t)((value12 ^ 0xFFFF) + 1);
                a_hi4 = (uint16_t)((value12 ^ 0xFFFF) + 1) >> 8;
            }
            uint16_t value14 = RAM16(0x0007 + (uint16_t)(sp0 - 0x0C));
            a_hi5 = (uint16_t)(((a_hi4 << 8) | a5) + value14) >> 8;
            x3 = (uint16_t)(((a_hi4 << 8) | a5) + value14);
        }
        a6 = RAM8(0x0006 + (uint16_t)(sp0 - 0x0C));
        a_hi6 = a_hi5;
        x4 = x3;
    }
    uint8_t value16 = RAM8(0x0000 + sp0 - 0x0C);
    RAM16_SET(0x0000 + sp0 - 4, (a_hi6 << 8) | a6);
    uint8_t value19 = RAM8(0x0000 + sp0 - 2);
    uint8_t value20 = RAM8(0x0000 + sp0 - 1);
    uint8_t value21 = RAM8(0x0000 + sp0);
    r->x = x4;
    r->mf = value19 & 0x20;
    r->xf = value19 & 0x10;
    r->db = value16;
    r->dp = (value21 << 8) | value20;
    r->i = value19 & 0x04;
    r->d = value19 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC149EC, SOM_RTS, "gen", scale_spell_entity_signed_angle_vector, 0, L_X | L_Y, 15, 1, 0, 188, 106)
