#include "som_c.h"

/* C2B01E clear_actor_charge_and_idle_party_gauge   [class B, 53 bytes, 25 instructions]
 * Source: src/rom/clear_actor_charge_and_idle_party_gauge.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void clear_actor_charge_and_idle_party_gauge(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    RAM8(0xE085 + x) = 0;
    RAM8(0xE01A + x) = 0;
    RAM8(0xE01B + x) = 0;
    RAM8(ACTOR_CHARGE_STAGE + x) = 0;
    uint8_t a_hi2;
    bool carry2;
    if (x >= 0x0600) {
        a_hi2 = a_hi;
        carry2 = x >= 0x0600;
    } else {
        uint8_t value = RAM8(ACTOR_WEAPON_GAUGE + x);
        uint8_t a_hi1;
        bool carry1;
        if (value != 0) {
            a_hi1 = a_hi;
            carry1 = x >= 0x0600;
        } else {
            RAM16_SET(0x0A56 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3), 0x2817);
            RAM16_SET(0x0A50 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3), 0);
            RAM16_SET(0x0A52 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3), 0);
            RAM16_SET(0x0A53 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3), 0);
            a_hi1 = 0;
            carry1 = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 2) & 0x8000;
        }
        a_hi2 = a_hi1;
        carry2 = carry1;
    }
    r->a = (r->a & 0x00FF) | (a_hi2 << 8);
    r->c = carry2;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2B01E, SOM_RTL, "gen", clear_actor_charge_and_idle_party_gauge, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 53, 25)
