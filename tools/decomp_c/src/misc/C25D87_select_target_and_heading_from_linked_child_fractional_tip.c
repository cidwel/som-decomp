#include "som_c.h"

/* C25D87 select_target_and_heading_from_linked_child_fractional_tip   [class C, 88 bytes, 41 instructions]
 * Source: src/rom/select_target_and_heading_from_linked_child_fractional_tip.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYV.
 */
static void select_target_and_heading_from_linked_child_fractional_tip(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x002B + value);
    uint16_t value3 = RAM16(0x0032 + value);
    uint16_t value4 = RAM16(0x00B8 + value);
    uint8_t a1;
    uint8_t a_hi1;
    if (!(value4 & 0x8000)) {
        a1 = (((uint8_t)value4 << 8) | (value4 >> 8)) & 0xFF;
        a_hi1 = 0;
    } else {
        a1 = (uint8_t)(((((uint8_t)value4 << 8) | (value4 >> 8)) & 0xFF) | 0xFF00);
        a_hi1 = (((((uint8_t)value4 << 8) | (value4 >> 8)) & 0xFF) | 0xFF00) >> 8;
    }
    RAM16_SET(0x002B + value, (uint16_t)(((a_hi1 << 8) | a1) + value2));
    uint16_t value5 = RAM16(0x00BA + value);
    uint8_t a2;
    uint8_t a_hi2;
    if (!(value5 & 0x8000)) {
        a2 = (((uint8_t)value5 << 8) | (value5 >> 8)) & 0xFF;
        a_hi2 = 0;
    } else {
        a2 = (uint8_t)(((((uint8_t)value5 << 8) | (value5 >> 8)) & 0xFF) | 0xFF00);
        a_hi2 = (((((uint8_t)value5 << 8) | (value5 >> 8)) & 0xFF) | 0xFF00) >> 8;
    }
    RAM16_SET(0x0032 + value, (uint16_t)(((a_hi2 << 8) | a2) + RAM16(0x0032 + value)));
    r->sp -= 4;
    JSR(c, 0x5DBD, 0xC23224); /* select_nearest_active_living_party_actor */
    r->sp += 4;
    uint16_t a_all = r->a;
    RAM16_SET(0x00A9 + RAM16(0x0287), a_all);
    r->mf = 0;
    r->xf = 0;
    r->sp -= 4;
    JSR(c, 0x5DC5, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
    r->sp += 4;
    uint16_t a_all2 = r->a;
    RAM16_SET(0x00AB + RAM16(0x0287), a_all2);
    uint16_t value9 = BUS16(c, 0xC25DDF + (uint16_t)(a_all2 << 1));
    uint16_t value10 = RAM16(0x0287);
    RAM16_SET(0x00B4 + value10, value9);
    RAM16_SET(0x0032 + value10, value3);
    RAM16_SET(0x002B + value10, value2);
    r->a = value2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25D87, SOM_RTS, "gen", select_target_and_heading_from_linked_child_fractional_tip, 0, L_B | L_Y | L_V, 5, 0, 0, 88, 41)
