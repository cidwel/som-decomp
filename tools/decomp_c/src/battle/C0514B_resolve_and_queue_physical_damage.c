#include "som_c.h"

/* C0514B resolve_and_queue_physical_damage   [class B, 156 bytes, 68 instructions]
 * Source: src/rom/resolve_and_queue_physical_damage.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void resolve_and_queue_physical_damage(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM8(0x0390) = RAM8(ACTOR_FLAT_GUARD_AMOUNT + x);
    RAM8(0xE1EC + x) = RAM8(BATTLE_ATTACKER_SLOT);
    RAM16_SET(0x0394, RAM16(BATTLE_DEFENCE_WORK));
    JSR(c, 0x515F, 0xC051E7); /* calculate_physical_attack_roll */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x5162, 0xC052E7); /* calculate_physical_defence_roll */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x5165, 0xC0532C); /* apply_critical_hit_or_weapon_gauge */
    uint16_t x_ret3 = r->x;
    uint16_t y_ret3 = r->y;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x5168, 0xC0541B); /* apply_lucid_barrier_absorption */
    uint16_t battle_damage = RAM16(BATTLE_DAMAGE);
    uint16_t value2 = RAM16(0x0394);
    if ((uint16_t)(battle_damage - value2) == 0) {
        r->a = (uint16_t)(battle_damage - value2);
        r->c = battle_damage >= value2;
        r->v = ((battle_damage ^ value2) & (battle_damage ^ (uint16_t)(battle_damage - value2)) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 0;
        JSL(c, 0x5179, 0xC04E6B); /* select_actor_miss_reaction_long */
        uint16_t x_ret4 = r->x;
        if (!(RAM8(ACTOR_KIND_FLAGS + x_ret4) & 0x80)) {
            uint16_t value4 = RAM16(ACTOR_PENDING_HP_DAMAGE + x_ret4);
            if (value4 == 0) {
                if (RAM8(0xE175 + x_ret4) == 0) {
                    RAM8(0xE17B + x_ret4) = 0;
                    RAM8(0xE17C + x_ret4) = 0;
                    RAM8(0xE175 + x_ret4) = 0xD0;
                }
            }
            r->a = (r->a & 0x00FF) | ((value4 >> 8) << 8);
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if (!((uint16_t)(battle_damage - value2) & 0x8000)) {
        RAM16_SET(BATTLE_DAMAGE, (uint16_t)(battle_damage - value2));
        uint16_t value6 = RAM16(ACTOR_WEAPON_FLAGS + y_ret3);
        uint8_t a_hi2;
        bool carry2;
        bool overflow2;
        if ((value6 & 0x40) == 0) {
            uint16_t battle_damage2 = RAM16(BATTLE_DAMAGE);
            uint16_t value7 = RAM16(ACTOR_PENDING_HP_DAMAGE + x_ret3);
            RAM16_SET(ACTOR_PENDING_HP_DAMAGE + x_ret3, (uint16_t)(battle_damage2 + value7));
            a_hi2 = (uint16_t)(battle_damage2 + value7) >> 8;
            carry2 = battle_damage2 + value7 > 0xFFFF;
            overflow2 = ((battle_damage2 ^ (uint16_t)(battle_damage2 + value7)) & (value7 ^ (uint16_t)(battle_damage2 + value7)) & 0x8000) != 0;
        } else {
            uint16_t value8 = RAM16(ACTOR_MONSTER_TYPE + x_ret3);
            uint8_t a_hi1;
            bool carry1;
            bool overflow1;
            if ((value8 & 0x20) != 0) {
                RAM16_SET(ACTOR_PENDING_HP_DAMAGE + y_ret3, (uint16_t)(RAM16(BATTLE_DAMAGE) + RAM16(ACTOR_PENDING_HP_DAMAGE + y_ret3)));
                uint16_t battle_damage4 = RAM16(BATTLE_DAMAGE);
                uint16_t value10 = RAM16(ACTOR_PENDING_HP_HEAL + x_ret3);
                RAM16_SET(ACTOR_PENDING_HP_HEAL + x_ret3, (uint16_t)(battle_damage4 + value10));
                RAM8(0xE1EC + y_ret3) = RAM8(BATTLE_ATTACKER_SLOT);
                a_hi1 = (uint16_t)(battle_damage4 + value10) >> 8;
                carry1 = battle_damage4 + value10 > 0xFFFF;
                overflow1 = ((battle_damage4 ^ (uint16_t)(battle_damage4 + value10)) & (value10 ^ (uint16_t)(battle_damage4 + value10)) & 0x8000) != 0;
            } else {
                RAM16_SET(ACTOR_PENDING_HP_DAMAGE + x_ret3, (uint16_t)(RAM16(BATTLE_DAMAGE) + RAM16(ACTOR_PENDING_HP_DAMAGE + x_ret3)));
                uint16_t battle_damage6 = RAM16(BATTLE_DAMAGE);
                uint16_t value12 = RAM16(ACTOR_PENDING_HP_HEAL + y_ret3);
                RAM16_SET(ACTOR_PENDING_HP_HEAL + y_ret3, (uint16_t)(battle_damage6 + value12));
                a_hi1 = (uint16_t)(battle_damage6 + value12) >> 8;
                carry1 = battle_damage6 + value12 > 0xFFFF;
                overflow1 = ((battle_damage6 ^ (uint16_t)(battle_damage6 + value12)) & (value12 ^ (uint16_t)(battle_damage6 + value12)) & 0x8000) != 0;
            }
            a_hi2 = a_hi1;
            carry2 = carry1;
            overflow2 = overflow1;
        }
        r->a = (r->a & 0x00FF) | (a_hi2 << 8);
        r->c = carry2;
        r->v = overflow2;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = (uint16_t)(battle_damage - value2);
    r->c = battle_damage >= value2;
    r->v = ((battle_damage ^ value2) & (battle_damage ^ (uint16_t)(battle_damage - value2)) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    JSL(c, 0x5179, 0xC04E6B); /* select_actor_miss_reaction_long */
    uint16_t x_ret5 = r->x;
    if (!(RAM8(ACTOR_KIND_FLAGS + x_ret5) & 0x80)) {
        uint16_t value14 = RAM16(ACTOR_PENDING_HP_DAMAGE + x_ret5);
        if (value14 == 0) {
            if (RAM8(0xE175 + x_ret5) == 0) {
                RAM8(0xE17B + x_ret5) = 0;
                RAM8(0xE17C + x_ret5) = 0;
                RAM8(0xE175 + x_ret5) = 0xD0;
            }
        }
        r->a = (r->a & 0x00FF) | ((value14 >> 8) << 8);
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0514B, SOM_RTS, "gen", resolve_and_queue_physical_damage, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 156, 68)
