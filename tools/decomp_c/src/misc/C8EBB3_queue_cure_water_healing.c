#include "som_c.h"

/* C8EBB3 queue_cure_water_healing   [class A, 23 bytes, 11 instructions]
 * Source: src/rom/queue_cure_water_healing.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void queue_cure_water_healing(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    RAM8(0x038F) = 4;
    r->a = (a_hi << 8) | 4;
    r->x = battle_defender_ptr;
    JSR(c, 0xEBBB, 0xC8E8C0); /* calculate_spell_attack_roll */
    uint16_t x_ret = r->x;
    uint16_t value = RAM16(ACTOR_PENDING_HP_HEAL + x_ret);
    uint16_t battle_damage = RAM16(BATTLE_DAMAGE);
    RAM16_SET(ACTOR_PENDING_HP_HEAL + x_ret, (uint16_t)(value + battle_damage));
    r->a = (uint16_t)(value + battle_damage);
    r->c = value + battle_damage > 0xFFFF;
    r->z = (uint16_t)(value + battle_damage) == 0;
    r->n = (uint16_t)(value + battle_damage) & 0x8000;
    r->v = ((value ^ (uint16_t)(value + battle_damage)) & (battle_damage ^ (uint16_t)(value + battle_damage)) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EBB3, SOM_RTS, "gen", queue_cure_water_healing, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 23, 11)
