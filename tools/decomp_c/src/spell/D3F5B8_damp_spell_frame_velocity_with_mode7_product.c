#include "som_c.h"

/* D3F5B8 damp_spell_frame_velocity_with_mode7_product   [class D, 203 bytes, 92 instructions]
 * Source: src/rom/damp_spell_frame_velocity_with_mode7_product.s
 * Documented in docs/map-oam-spell-frames.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01DA.  Callers read: XY.
 */
static void damp_spell_frame_velocity_with_mode7_product(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01DA) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xDA;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM16_SET(0x0009 + (uint16_t)(sp0 - 0x0D), RAM16(0x0000 + sp0 - 4) & 0xFF);
    uint16_t value2 = RAM16(0x0003 + x);
    uint8_t a1;
    uint8_t a_hi1;
    if (!(value2 & 0x8000)) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
    } else {
        a1 = (uint8_t)((value2 ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)((value2 ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0D), (a_hi1 << 8) | a1);
    uint16_t value3 = RAM16(0x0000 + x);
    uint8_t a2;
    uint8_t a_hi2;
    if (!(value3 & 0x8000)) {
        a2 = (uint8_t)value3;
        a_hi2 = value3 >> 8;
    } else {
        a2 = (uint8_t)((value3 ^ 0xFFFF) + 1);
        a_hi2 = (uint16_t)((value3 ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0D), (a_hi2 << 8) | a2);
    uint16_t value4 = RAM16(0x0001 + (uint16_t)(sp0 - 0x0D));
    uint8_t a_hi3;
    if (((a_hi2 << 8) | a2) >= value4) {
        RAM16_SET(0x0005 + (uint16_t)(sp0 - 0x0D), (a_hi2 << 8) | a2);
        uint16_t value5 = RAM16(0x0001 + (uint16_t)(sp0 - 0x0D));
        RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), value5);
        a_hi3 = value5 >> 8;
    } else {
        RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), (a_hi2 << 8) | a2);
        uint16_t value6 = RAM16(0x0001 + (uint16_t)(sp0 - 0x0D));
        RAM16_SET(0x0005 + (uint16_t)(sp0 - 0x0D), value6);
        a_hi3 = value6 >> 8;
    }
    uint16_t value7 = RAM16(0x0007 + (uint16_t)(sp0 - 0x0D));
    uint16_t value8 = RAM16(0x0005 + (uint16_t)(sp0 - 0x0D));
    BUS8_SET(c, 0x00211B, (uint8_t)((uint16_t)((value7 >> 1) + value8) >> 1));
    BUS8_SET(c, 0x00211B, (uint16_t)((value7 >> 1) + value8) >> 1 >> 8);
    uint8_t value9 = RAM8(0x0009 + (uint16_t)(sp0 - 0x0D));
    BUS8_SET(c, 0x00211C, value9);
    BUS8_SET(c, 0x00211C, value9);
    uint16_t value10 = BUS16(c, 0x002134);
    RAM16_SET(0x0009 + (uint16_t)(sp0 - 0x0D), (uint16_t)(((value10 >> 6) ^ 0xFFFF) + 1) & 0x7F);
    uint16_t value11 = RAM16(0x0003 + x);
    BUS8_SET(c, 0x00211B, (uint8_t)(value11 << 1));
    BUS8_SET(c, 0x00211B, (uint16_t)(value11 << 1) >> 8);
    uint8_t value12 = RAM8(0x0009 + (uint16_t)(sp0 - 0x0D));
    BUS8_SET(c, 0x00211C, value12);
    BUS8_SET(c, 0x00211C, value12);
    uint16_t value13 = BUS16(c, 0x002134);
    uint16_t value14 = BUS16(c, 0x002135);
    if (value14 == 0) {
        RAM16_SET(0x0004 + x, 0);
    }
    RAM16_SET(0x0003 + x, value14);
    uint16_t value15 = RAM16(0x0000 + x);
    BUS8_SET(c, 0x00211B, (uint8_t)(value15 << 1));
    BUS8_SET(c, 0x00211B, (uint16_t)(value15 << 1) >> 8);
    uint8_t value16 = RAM8(0x0009 + (uint16_t)(sp0 - 0x0D));
    BUS8_SET(c, 0x00211C, value16);
    BUS8_SET(c, 0x00211C, value16);
    uint16_t value17 = BUS16(c, 0x002134);
    uint16_t value18 = BUS16(c, 0x002135);
    if (value18 == 0) {
        RAM16_SET(0x0001 + x, 0);
    }
    RAM16_SET(0x0000 + x, value18);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F5B8, SOM_RTS, "gen", damp_spell_frame_velocity_with_mode7_product, 0, L_X | L_Y, 13, 0, 0, 203, 92)
