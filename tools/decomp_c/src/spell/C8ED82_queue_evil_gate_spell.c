#include "som_c.h"

/* C8ED82 queue_evil_gate_spell   [class B, 73 bytes, 36 instructions]
 * Source: src/rom/queue_evil_gate_spell.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void queue_evil_gate_spell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->x = RAM16(BATTLE_DEFENDER_PTR);
    JSR(c, 0xED86, 0xC8EA69); /* divide_spell_level_by_target_count */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xED89, 0xC8E8C0); /* calculate_spell_attack_roll */
    uint16_t x_ret = r->x;
    BUS16_SET(c, 0x004204, (uint16_t)(RAM16(ACTOR_HP + x_ret) + RAM16(ACTOR_MAX_HP + x_ret)) >> 1);
    BUS8_SET(c, 0x004206, (uint8_t)(0x0A - RAM8(0x039D)));
    uint16_t value4 = BUS16(c, 0x004214);
    RAM16_SET(BATTLE_DAMAGE, value4);
    uint16_t value5 = RAM16(ACTOR_KIND_FLAGS + x_ret);
    uint16_t battle_damage = RAM16(BATTLE_DAMAGE);
    uint8_t a1;
    uint8_t a_hi1;
    if ((value5 & 0x40) == 0) {
        a1 = (uint8_t)battle_damage;
        a_hi1 = battle_damage >> 8;
    } else {
        a1 = 1;
        a_hi1 = 0;
    }
    uint16_t value6 = RAM16(ACTOR_PENDING_HP_DAMAGE + x_ret);
    RAM16_SET(ACTOR_PENDING_HP_DAMAGE + x_ret, (uint16_t)(((a_hi1 << 8) | a1) + value6));
    r->a = (uint16_t)(((a_hi1 << 8) | a1) + value6);
    r->c = ((a_hi1 << 8) | a1) + value6 > 0xFFFF;
    r->z = (uint16_t)(((a_hi1 << 8) | a1) + value6) == 0;
    r->n = (uint16_t)(((a_hi1 << 8) | a1) + value6) & 0x8000;
    r->v = ((((a_hi1 << 8) | a1) ^ (uint16_t)(((a_hi1 << 8) | a1) + value6)) & (value6 ^ (uint16_t)(((a_hi1 << 8) | a1) + value6)) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8ED82, SOM_RTS, "gen", queue_evil_gate_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 73, 36)
