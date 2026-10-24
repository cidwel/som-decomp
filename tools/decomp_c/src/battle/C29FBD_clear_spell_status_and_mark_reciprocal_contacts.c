#include "som_c.h"

/* C29FBD clear_spell_status_and_mark_reciprocal_contacts   [class B, 59 bytes, 27 instructions]
 * Source: src/rom/clear_spell_status_and_mark_reciprocal_contacts.s
 * Documented in docs/boss-native-spell-status-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYCV.
 */
static void clear_spell_status_and_mark_reciprocal_contacts(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    JSR(c, 0x9FBF, 0xC2992D); /* clear_spell_target_low_status_bit */
    uint16_t value = RAM16(0x00B2 + x);
    uint16_t value2 = RAM16(0x00B0 + x);
    uint8_t value3 = BUS8(c, 0xC205F0 + (((uint8_t)((uint16_t)(value2 - 0xE600) >> 1) << 8) | ((uint16_t)(value2 - 0xE600) >> 1 >> 8)));
    RAM8(0x0059 + value) = value3 | RAM8(0x0059 + value);
    uint16_t value5 = RAM16(0x0287);
    uint16_t value6 = RAM16(0x00B2 + value5);
    uint8_t value7 = BUS8(c, 0xC205F0 + (((uint8_t)((uint16_t)(value6 - 0xE000) >> 1) << 8) | ((uint16_t)(value6 - 0xE000) >> 1 >> 8)));
    uint8_t value8 = RAM8(0x005A + value5);
    RAM8(0x005A + value5) = value7 | value8;
    r->a = ((uint8_t)((uint16_t)(value6 - 0xE000) >> 1) << 8) | (value7 | value8);
    r->y = value5;
    r->c = (uint16_t)(value6 - 0xE000) & 0x01;
    r->v = ((value6 ^ 0xE000) & (value6 ^ (uint16_t)(value6 - 0xE000)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29FBD, SOM_RTS, "gen", clear_spell_status_and_mark_reciprocal_contacts, 0, L_B | L_Y | L_C | L_V, 1, 0, 0, 59, 27)
