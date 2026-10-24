#include "som_c.h"

/* C1493A scale_native_spell_sprite_angle_coefficient   [class B, 89 bytes, 57 instructions]
 * Source: src/rom/scale_native_spell_sprite_angle_coefficient.s
 * Documented in docs/actor-cast-entity-trigonometry.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCV.
 */
static void scale_native_spell_sprite_angle_coefficient(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM8(0x0002 + (uint16_t)(sp0 - 5)) = a_hi;
    r->a = (a_hi << 8) | a;
    r->z = (uint8_t)((a_hi << 8) | a) == 0;
    r->n = (uint8_t)((a_hi << 8) | a) & 0x80;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4952, 0xC148D9); GUARD_JSR(c, sp_call, 0x4952); } /* lookup_native_spell_sprite_angle_coefficient */
    r->sp += 6;
    uint16_t a_all = r->a;
    uint8_t a4;
    uint8_t a_hi4;
    if ((uint8_t)a_all == 0) {
        uint8_t a2;
        uint8_t a_hi2;
        if (a_all >> 8 & 0x80) {
            uint8_t value = RAM8(0x0002 + (uint16_t)(sp0 - 5));
            a2 = (uint8_t)a_all;
            a_hi2 = (uint8_t)((value ^ 0xFF) + 1);
        } else {
            uint8_t a1;
            uint8_t a_hi1;
            if (a_all >> 8 == 0) {
                a1 = a_all >> 8;
                a_hi1 = (uint8_t)a_all;
            } else {
                uint8_t value2 = RAM8(0x0002 + (uint16_t)(sp0 - 5));
                a1 = (uint8_t)a_all;
                a_hi1 = value2;
            }
            a2 = a1;
            a_hi2 = a_hi1;
        }
        a4 = a2;
        a_hi4 = a_hi2;
    } else {
        RAM8(0x0001 + (uint16_t)(sp0 - 5)) = a_all >> 8;
        uint8_t value3 = RAM8(0x0002 + (uint16_t)(sp0 - 5));
        BUS16_SET(c, 0x004202, (value3 << 8) | (uint8_t)a_all);
        RAM8(0x0000 + sp0 - 6) = value3;
        RAM8(0x0000 + sp0 - 7) = (uint8_t)((value3 << 8) | (uint8_t)a_all);
        uint16_t value4 = BUS16(c, 0x004216);
        uint8_t value5 = RAM8(0x0001 + (uint16_t)(sp0 - 5));
        RAM8(0x0001 + (uint16_t)(sp0 - 5)) <<= 1;
        uint8_t a3;
        uint8_t a_hi3;
        if (!(value5 & 0x80)) {
            a3 = (uint8_t)value4;
            a_hi3 = value4 >> 8;
        } else {
            a3 = (uint8_t)((value4 ^ 0xFFFF) + 1);
            a_hi3 = (uint16_t)((value4 ^ 0xFFFF) + 1) >> 8;
        }
        a4 = a3;
        a_hi4 = a_hi3;
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 5);
    RAM8(0x0000 + sp0 - 3) = a4;
    uint8_t value8 = RAM8(0x0000 + sp0 - 3);
    uint8_t value9 = RAM8(0x0000 + sp0 - 2);
    uint8_t value10 = RAM8(0x0000 + sp0 - 1);
    uint8_t value11 = RAM8(0x0000 + sp0);
    r->a = (a_hi4 << 8) | value8;
    r->c = value9 & 0x01;
    r->v = value9 & 0x40;
    r->mf = value9 & 0x20;
    r->xf = value9 & 0x10;
    r->db = value6;
    r->dp = (value11 << 8) | value10;
    r->i = value9 & 0x04;
    r->d = value9 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1493A, SOM_RTS, "gen", scale_native_spell_sprite_angle_coefficient, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 8, 1, 0, 89, 57)
