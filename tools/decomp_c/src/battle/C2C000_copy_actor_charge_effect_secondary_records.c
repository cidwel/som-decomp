#include "som_c.h"

/* C2C000 copy_actor_charge_effect_secondary_records   [class A, 33 bytes, 17 instructions]
 * Source: src/rom/copy_actor_charge_effect_secondary_records.s
 * Documented in docs/actor-animation-special-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYV.
 */
static void copy_actor_charge_effect_secondary_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0xD001 + y);
    RAM16_SET(0xD011 + y, value);
    RAM16_SET(0xD021 + y, value);
    uint8_t a_hi1 = value >> 8;
    uint16_t x1 = 7;
    uint16_t y1 = y;
    for (;;) {
        uint16_t value2 = RAM16(0xD002 + y1);
        RAM16_SET(0xD012 + y1, value2);
        RAM16_SET(0xD022 + y1, value2);
        a_hi1 = value2 >> 8;
        x1 = (uint16_t)(x1 - 1);
        y1 = (uint16_t)(y1 + 2);
        if (!(x1 != 0)) break;
    }
    r->x = x;
    r->y = y;
    r->v = overflow;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C000, SOM_RTS, "gen", copy_actor_charge_effect_secondary_records, 0, L_X | L_Y | L_V, 4, 1, 0, 33, 17)
