#include "som_c.h"

/* 7EC621 intersect_native_unsigned_rectangles_into_bank_7f_buffer   [class B, 144 bytes, 70 instructions]
 * Source: src/boot/intersect_native_unsigned_rectangles_into_bank_7f_buffer.s
 * Documented in docs/boot-native-rectangle-intersection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void intersect_native_unsigned_rectangles_into_bank_7f_buffer(SomCtx *c)
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
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0D) + 0xA > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 0x0D) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0E) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0F) = 0x7F;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0D), value);
    uint16_t value2 = BUS16(c, 0x7F0004 + x);
    uint16_t value3 = BUS16(c, 0x7F0004 + y);
    uint8_t a1;
    uint8_t a_hi1;
    if (value2 < value3) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
    } else {
        uint16_t value4 = BUS16(c, 0x7F0004 + y);
        a1 = (uint8_t)value4;
        a_hi1 = value4 >> 8;
    }
    RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), (a_hi1 << 8) | a1);
    uint16_t value5 = BUS16(c, 0x7F0006 + x);
    uint16_t value6 = BUS16(c, 0x7F0006 + y);
    uint8_t a2;
    uint8_t a_hi2;
    if (value5 < value6) {
        a2 = (uint8_t)value5;
        a_hi2 = value5 >> 8;
    } else {
        uint16_t value7 = BUS16(c, 0x7F0006 + y);
        a2 = (uint8_t)value7;
        a_hi2 = value7 >> 8;
    }
    RAM16_SET(0x0009 + (uint16_t)(sp0 - 0x0D), (a_hi2 << 8) | a2);
    uint16_t value8 = BUS16(c, 0x7F0000 + x);
    uint16_t value9 = BUS16(c, 0x7F0000 + y);
    uint8_t a3;
    uint8_t a_hi3;
    if (value8 >= value9) {
        a3 = (uint8_t)value8;
        a_hi3 = value8 >> 8;
    } else {
        uint16_t value10 = BUS16(c, 0x7F0000 + y);
        a3 = (uint8_t)value10;
        a_hi3 = value10 >> 8;
    }
    uint16_t value11 = RAM16(0x0007 + (uint16_t)(sp0 - 0x0D));
    uint8_t a6;
    uint16_t x2;
    if (((a_hi3 << 8) | a3) >= value11) {
        uint16_t value12 = RAM16(0x0001 + (uint16_t)(sp0 - 0x0D));
        BUS16_SET(c, 0x7F0000 + value12, 0);
        BUS16_SET(c, 0x7F0002 + value12, 0);
        BUS16_SET(c, 0x7F0004 + value12, 0);
        BUS16_SET(c, 0x7F0006 + value12, 0);
        a6 = 0;
        x2 = value12;
    } else {
        RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0D), (a_hi3 << 8) | a3);
        uint16_t value13 = BUS16(c, 0x7F0002 + x);
        uint16_t value14 = BUS16(c, 0x7F0002 + y);
        uint8_t a4;
        uint8_t a_hi4;
        if (value13 >= value14) {
            a4 = (uint8_t)value13;
            a_hi4 = value13 >> 8;
        } else {
            uint16_t value15 = BUS16(c, 0x7F0002 + y);
            a4 = (uint8_t)value15;
            a_hi4 = value15 >> 8;
        }
        uint16_t value16 = RAM16(0x0009 + (uint16_t)(sp0 - 0x0D));
        uint8_t a5;
        uint16_t x1;
        if (((a_hi4 << 8) | a4) >= value16) {
            uint16_t value17 = RAM16(0x0001 + (uint16_t)(sp0 - 0x0D));
            BUS16_SET(c, 0x7F0000 + value17, 0);
            BUS16_SET(c, 0x7F0002 + value17, 0);
            BUS16_SET(c, 0x7F0004 + value17, 0);
            BUS16_SET(c, 0x7F0006 + value17, 0);
            a5 = 0;
            x1 = value17;
        } else {
            RAM16_SET(0x0005 + (uint16_t)(sp0 - 0x0D), (a_hi4 << 8) | a4);
            uint16_t value18 = RAM16(0x0001 + (uint16_t)(sp0 - 0x0D));
            BUS16_SET(c, 0x7F0000 + value18, RAM16(0x0003 + (uint16_t)(sp0 - 0x0D)));
            BUS16_SET(c, 0x7F0002 + value18, RAM16(0x0005 + (uint16_t)(sp0 - 0x0D)));
            BUS16_SET(c, 0x7F0004 + value18, RAM16(0x0007 + (uint16_t)(sp0 - 0x0D)));
            BUS16_SET(c, 0x7F0006 + value18, RAM16(0x0009 + (uint16_t)(sp0 - 0x0D)));
            a5 = 1;
            x1 = value18;
        }
        a6 = a5;
        x2 = x1;
    }
    uint8_t value23 = RAM8(0x0000 + sp0 - 0x0D);
    RAM16_SET(0x0000 + sp0 - 4, a6);
    uint8_t value24 = RAM8(0x0000 + sp0 - 4);
    uint8_t value25 = RAM8(0x0000 + sp0 - 3);
    uint8_t value26 = RAM8(0x0000 + sp0 - 2);
    uint8_t value27 = RAM8(0x0000 + sp0 - 1);
    uint8_t value28 = RAM8(0x0000 + sp0);
    r->a = (value25 << 8) | value24;
    r->x = x2;
    r->c = value26 & 0x01;
    r->z = ((value28 << 8) | value27) == 0;
    r->n = ((value28 << 8) | value27) & 0x8000;
    r->v = value26 & 0x40;
    r->mf = value26 & 0x20;
    r->xf = value26 & 0x10;
    r->db = value23;
    r->dp = (value28 << 8) | value27;
    r->i = value26 & 0x04;
    r->d = value26 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC621, SOM_RTS, "gen", intersect_native_unsigned_rectangles_into_bank_7f_buffer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 16, 1, 0, 144, 70)
