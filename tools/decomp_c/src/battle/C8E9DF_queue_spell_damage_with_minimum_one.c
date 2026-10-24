#include "som_c.h"

/* C8E9DF queue_spell_damage_with_minimum_one   [class B, 29 bytes, 14 instructions]
 * Source: src/rom/queue_spell_damage_with_minimum_one.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XV.
 */
static void queue_spell_damage_with_minimum_one(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t battle_damage = RAM16(BATTLE_DAMAGE);
    uint16_t value = RAM16(0x0394);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    if (!((uint16_t)(battle_damage - value) & 0x8000)) {
        a1 = (uint8_t)(battle_damage - value);
        a_hi1 = (uint16_t)(battle_damage - value) >> 8;
        zero1 = (uint16_t)(battle_damage - value) == 0;
    } else {
        a1 = 1;
        a_hi1 = 0;
        zero1 = 0;
    }
    uint8_t a2;
    uint8_t a_hi2;
    if (!zero1) {
        a2 = a1;
        a_hi2 = a_hi1;
    } else {
        a2 = 1;
        a_hi2 = 0;
    }
    RAM16_SET(BATTLE_DAMAGE, (a_hi2 << 8) | a2);
    uint16_t value2 = RAM16(ACTOR_PENDING_HP_DAMAGE + x);
    RAM16_SET(ACTOR_PENDING_HP_DAMAGE + x, (uint16_t)(((a_hi2 << 8) | a2) + value2));
    r->v = ((((a_hi2 << 8) | a2) ^ (uint16_t)(((a_hi2 << 8) | a2) + value2)) & (value2 ^ (uint16_t)(((a_hi2 << 8) | a2) + value2)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E9DF, SOM_RTS, "gen", queue_spell_damage_with_minimum_one, 0, L_X | L_V, 1, 1, 0, 29, 14)
