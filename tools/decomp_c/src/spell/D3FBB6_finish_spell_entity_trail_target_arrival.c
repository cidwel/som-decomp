#include "som_c.h"

/* D3FBB6 finish_spell_entity_trail_target_arrival   [class B, 142 bytes, 73 instructions]
 * Source: src/rom/finish_spell_entity_trail_target_arrival.s
 * Documented in docs/actor-cast-entity-trail-direction.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XY.
 */
static void finish_spell_entity_trail_target_arrival(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0B) + 0x8 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0B), x);
    uint16_t value = RAM16(0x014C + x);
    uint8_t a1;
    uint8_t a_hi1;
    if ((value & 1) == 0) {
        uint16_t value2 = RAM16(0x0146 + x);
        uint16_t value3 = RAM16(0x0142 + x);
        a1 = (uint8_t)(value2 - value3);
        a_hi1 = (uint16_t)(value2 - value3) >> 8;
    } else {
        uint16_t value4 = RAM16(0x0144 + x);
        uint16_t value5 = RAM16(0x0140 + x);
        a1 = (uint8_t)(value4 - value5);
        a_hi1 = (uint16_t)(value4 - value5) >> 8;
    }
    uint16_t y1;
    if ((((((uint8_t)(((a_hi1 << 8) | a1) >> 6) << 8) | (((a_hi1 << 8) | a1) >> 6 >> 8)) ^ value) & 2) != 0) {
        y1 = 0xFE3A;
    } else {
        y1 = 0xFE1A;
    }
    RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0B), y1);
    RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0B), (uint16_t)(((RAM16(0x014C + x) & 3) << 1 << 1 << 1) + RAM16(0x0007 + (uint16_t)(sp0 - 0x0B))));
    uint16_t value8 = RAM16(0x0150 + x);
    uint8_t a2;
    uint8_t a_hi2;
    if ((uint16_t)(value8 + 1) < 0x14) {
        a2 = (uint8_t)(value8 + 1);
        a_hi2 = (uint16_t)(value8 + 1) >> 8;
    } else {
        a2 = 0;
        a_hi2 = 0;
    }
    RAM16_SET(0x0150 + x, (a_hi2 << 8) | a2);
    uint16_t value9 = RAM16(0x0001 + (uint16_t)(sp0 - 0x0B));
    RAM16_SET(0x000A + (uint16_t)((uint16_t)(((a_hi2 << 8) | a2) << 4) + value9), RAM16(0x014C + x));
    RAM16_SET(0x0006 + (uint16_t)((uint16_t)(((a_hi2 << 8) | a2) << 4) + value9), (uint16_t)(RAM16(0x0007 + (uint16_t)(sp0 - 0x0B)) - 0xF800));
    RAM16_SET(0x000C + (uint16_t)((uint16_t)(((a_hi2 << 8) | a2) << 4) + value9), 4);
    RAM16_SET(0x014A + x, 0);
    RAM16_SET(0x0148 + x, 0);
    RAM16_SET(0x0152 + x, 0x78);
    RAM16_SET(0x0154 + x, (uint16_t)(RAM16(0x0154 + x) + 1));
    uint8_t value12 = RAM8(0x0000 + sp0 - 2);
    uint8_t value13 = RAM8(0x0000 + sp0 - 1);
    uint8_t value14 = RAM8(0x0000 + sp0);
    r->y = (uint16_t)((uint16_t)(((a_hi2 << 8) | a2) << 4) + value9);
    r->mf = value12 & 0x20;
    r->xf = value12 & 0x10;
    r->dp = (value14 << 8) | value13;
    r->i = value12 & 0x04;
    r->d = value12 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3FBB6, SOM_RTS, "gen", finish_spell_entity_trail_target_arrival, 0, L_X | L_Y, 11, 1, 0, 142, 73)
