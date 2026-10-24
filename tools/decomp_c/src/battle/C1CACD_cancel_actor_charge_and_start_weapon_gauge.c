#include "som_c.h"

/* C1CACD cancel_actor_charge_and_start_weapon_gauge   [class A, 26 bytes, 12 instructions]
 * Source: src/rom/cancel_actor_charge_and_start_weapon_gauge.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void cancel_actor_charge_and_start_weapon_gauge(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM8(0xE01A + x) = 0;
    RAM8(0xE01B + x) = 0;
    RAM8(ACTOR_CHARGE_STAGE + x) = 0;
    uint8_t value = RAM8(ACTOR_AGILITY + x);
    RAM8(ACTOR_WEAPON_GAUGE + x) = ((uint8_t)(0x64 - value) >> 1) + 0x32;
    RAM8(0xE063 + x) = 0;
    SET_A8(r, ((uint8_t)(0x64 - value) >> 1) + 0x32);
    r->c = ((uint8_t)(0x64 - value) >> 1) + 0x32 > 0xFF;
    r->v = ((((uint8_t)(0x64 - value) >> 1) ^ ((uint8_t)(0x64 - value) >> 1) + 0x32) & (((uint8_t)(0x64 - value) >> 1) + 0x32 ^ 0x32) & 0x80) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1CACD, SOM_RTS, "gen", cancel_actor_charge_and_start_weapon_gauge, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 26, 12)
