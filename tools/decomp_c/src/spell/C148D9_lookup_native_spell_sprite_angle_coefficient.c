#include "som_c.h"

/* C148D9 lookup_native_spell_sprite_angle_coefficient   [class B, 74 bytes, 44 instructions]
 * Source: src/rom/lookup_native_spell_sprite_angle_coefficient.s
 * Documented in docs/actor-cast-entity-trigonometry.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXY.
 */
static void lookup_native_spell_sprite_angle_coefficient(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
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
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), 0);
    uint8_t a1;
    uint8_t a_hi1;
    if ((((a_hi << 8) | a) & 0x80) == 0) {
        a1 = ((a_hi << 8) | a) & 0xFF;
        a_hi1 = 0;
    } else {
        if ((uint16_t)((((a_hi << 8) | a) & 0xFF) - 0x80) != 0) {
            RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 5)) - 1));
        }
        a1 = (uint8_t)((((a_hi << 8) | a) & 0xFF) - 0x80);
        a_hi1 = (uint16_t)((((a_hi << 8) | a) & 0xFF) - 0x80) >> 8;
    }
    uint8_t a2;
    uint8_t a_hi2;
    if ((((a_hi1 << 8) | a1) & 0x40) == 0) {
        a2 = a1;
        a_hi2 = a_hi1;
    } else {
        a2 = (uint8_t)(((uint16_t)(((a_hi1 << 8) | a1) - 0x80) ^ 0xFFFF) + 1);
        a_hi2 = (uint16_t)(((uint16_t)(((a_hi1 << 8) | a1) - 0x80) ^ 0xFFFF) + 1) >> 8;
    }
    uint16_t value = BUS16(c, 0xDCFEA8 + (uint16_t)(((a_hi2 << 8) | a2) << 1));
    uint16_t value2 = RAM16(0x0001 + (uint16_t)(sp0 - 5));
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 5)) << 1));
    uint8_t a3;
    uint8_t a_hi3;
    if (!(value2 & 0x8000)) {
        a3 = (uint8_t)value;
        a_hi3 = value >> 8;
    } else {
        a3 = (uint8_t)(value | 0xFF00);
        a_hi3 = (value | 0xFF00) >> 8;
    }
    RAM8(0x0000 + sp0 - 3) = a3;
    r->a = (a_hi3 << 8) | RAM8(0x0000 + sp0 - 3);
    r->x = (uint16_t)(((a_hi2 << 8) | a2) << 1);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC148D9, SOM_RTS, "gen", lookup_native_spell_sprite_angle_coefficient, 0, L_A | L_B | L_X | L_Y, 8, 1, 0, 74, 44)
