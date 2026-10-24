#include "som_c.h"

/* C264BE position_orbit_from_signed_products_parent_and_offset_with_carry   [class B, 67 bytes, 30 instructions]
 * Source: src/rom/position_orbit_from_signed_products_parent_and_offset_with_carry.s
 * Documented in docs/boss-descriptor-three-orbit.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void position_orbit_from_signed_products_parent_and_offset_with_carry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00BA + x);
    RAM16_SET(0x0299, RAM16(0x002B + value));
    RAM16_SET(0x029B, RAM16(0x0032 + value));
    uint16_t value4 = RAM16(0x0287);
    RAM16_SET(0x0246, RAM16(0x00B4 + value4));
    uint16_t value6 = RAM16(0x0295);
    RAM16_SET(0x024E, value6);
    r->a = value6;
    r->x = value4;
    JSR(c, 0x64D9, 0xC22B94); /* multiply_signed_words_to_double_word */
    uint16_t value7 = RAM16(0x0257);
    uint16_t value8 = RAM16(0x0287);
    uint16_t value9 = RAM16(0x00B6 + value8);
    uint16_t value10 = RAM16(0x0299);
    RAM16_SET(0x002B + value8, (uint16_t)((uint16_t)(value7 + value9) + value10 + (value7 + value9 > 0xFFFF)));
    RAM16_SET(0x0246, RAM16(0x00B4 + value8));
    uint16_t value12 = RAM16(0x0297);
    RAM16_SET(0x024E, value12);
    r->a = value12;
    r->x = value8;
    r->c = (uint16_t)(value7 + value9) + value10 + (value7 + value9 > 0xFFFF) > 0xFFFF;
    r->v = (((uint16_t)(value7 + value9) ^ (uint16_t)((uint16_t)(value7 + value9) + value10 + (value7 + value9 > 0xFFFF))) & (value10 ^ (uint16_t)((uint16_t)(value7 + value9) + value10 + (value7 + value9 > 0xFFFF))) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x64F2, 0xC22B94); /* multiply_signed_words_to_double_word */
    uint16_t value13 = RAM16(0x0257);
    uint16_t value14 = RAM16(0x0287);
    uint16_t value15 = RAM16(0x00B8 + value14);
    RAM16_SET(0x0032 + value14, (uint16_t)((uint16_t)(value13 + value15) + RAM16(0x029B) + (value13 + value15 > 0xFFFF)));
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC264BE, SOM_RTS, "gen", position_orbit_from_signed_products_parent_and_offset_with_carry, 0, 0, 1, 0, 0, 67, 30)
