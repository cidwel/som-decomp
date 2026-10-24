#include "som_c.h"

/* C04E31 clear_actor_identity_attribute_record   [class B, 58 bytes, 25 instructions]
 * Source: src/rom/clear_actor_identity_attribute_record.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BV.
 */
static void clear_actor_identity_attribute_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint16_t x1 = x;
    uint16_t y1 = 9;
    for (;;) {
        RAM16_SET(0xE170 + x1, 0);
        RAM16_SET(ACTOR_HP + x1, 0);
        RAM16_SET(ACTOR_WEAPON_MASK + x1, 0);
        RAM16_SET(0xE1A6 + x1, 0);
        RAM16_SET(0xE1B8 + x1, 0);
        RAM16_SET(0xE1CA + x1, 0);
        RAM16_SET(0xE1DC + x1, 0);
        RAM16_SET(0xE1EE + x1, 0);
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    RAM8(0xE1EC + x) = 0x0F;
    RAM8(0xE1F0 + x) = 0xFF;
    RAM8(0xE1E5 + x) = 0xFF;
    RAM8(0xE1FC + x) = 0xFF;
    r->a = 0xFF;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04E31, SOM_RTS, "gen", clear_actor_identity_attribute_record, 0, L_B | L_V, 2, 1, 0, 58, 25)
