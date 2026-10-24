#include "som_c.h"

/* C23CAB mark_boss_and_target_reciprocal_contact_bits   [class B, 61 bytes, 32 instructions]
 * Source: src/rom/mark_boss_and_target_reciprocal_contact_bits.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void mark_boss_and_target_reciprocal_contact_bits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00A9 + x);
    uint8_t value2 = BUS8(c, 0xC205F0 + (((uint8_t)((uint16_t)(x - 0xE600) >> 1) << 8) | ((uint16_t)(x - 0xE600) >> 1 >> 8)));
    RAM8(0x0059 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) = value2 | RAM8(0x0059 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    uint16_t value4 = RAM16(0x0287);
    uint8_t value5 = BUS8(c, 0xC205F0 + (((uint8_t)((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0) >> 1) << 8) | ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0) >> 1 >> 8)));
    uint8_t value6 = RAM8(0x005A + value4);
    RAM8(0x005A + value4) = value5 | value6;
    uint16_t value7 = RAM16(0x0287);
    r->a = ((uint8_t)((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0) >> 1) << 8) | (value5 | value6);
    r->x = value7;
    r->y = value4;
    r->c = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0) & 0x01;
    r->z = value7 == 0;
    r->n = value7 & 0x8000;
    r->v = (((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23CAB, SOM_RTS, "gen", mark_boss_and_target_reciprocal_contact_bits, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 61, 32)
