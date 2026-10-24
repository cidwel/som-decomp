#include "som_c.h"

/* C8EEB7 apply_lucid_barrier_spell   [class B, 62 bytes, 25 instructions]
 * Source: src/rom/apply_lucid_barrier_spell.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void apply_lucid_barrier_spell(SomCtx *c)
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
    JSR(c, 0xEEBF, 0xC8E8C0); /* calculate_spell_attack_roll */
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    RAM8(ACTOR_GUARD_FLAGS + x_ret) |= 0x10;
    BUS16_SET(c, 0x004204, RAM16(ACTOR_DEFENSE + x_ret) >> 1);
    BUS8_SET(c, 0x004206, RAM8(0xE176 + y_ret));
    uint16_t value4 = RAM16(ACTOR_MAX_HP + x_ret);
    uint16_t battle_damage = RAM16(BATTLE_DAMAGE);
    if (value4 < battle_damage) {
        RAM16_SET(BATTLE_DAMAGE, value4);
    }
    uint16_t battle_damage2 = RAM16(BATTLE_DAMAGE);
    RAM16_SET(0xE1BD + x_ret, battle_damage2);
    uint8_t value5 = BUS8(c, 0x004214);
    RAM8(ACTOR_FLAT_GUARD_AMOUNT + x_ret) = value5;
    r->a = (battle_damage2 >> 8 << 8) | value5;
    r->c = value4 >= battle_damage;
    r->z = value5 == 0;
    r->n = value5 & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EEB7, SOM_RTS, "gen", apply_lucid_barrier_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 62, 25)
