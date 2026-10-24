#include "som_c.h"

/* C04F1E select_actor_mp_damage_impact_motion   [class B, 49 bytes, 23 instructions]
 * Source: src/rom/select_actor_mp_damage_impact_motion.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void select_actor_mp_damage_impact_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const bool carry = r->c;
    uint16_t value = RAM16(ACTOR_STATUS + x);
    uint8_t a_hi1;
    bool carry1;
    if ((value & 0xC578) != 0) {
        a_hi1 = value >> 8;
        carry1 = carry;
    } else {
        RAM8(BATTLE_TEMP_A4) = 8;
        if ((RAM8(ACTOR_KIND_FLAGS + x) & 0x81) != 0) {
            RAM8(BATTLE_TEMP_A4) = 0x0D;
        }
        uint8_t value3 = RAM8(ACTOR_MAX_MP + x);
        uint8_t battle_damage = RAM8(BATTLE_DAMAGE);
        if (value3 >> 2 < battle_damage) {
            RAM8(BATTLE_TEMP_A4)++;
        }
        r->a = (value >> 8 << 8) | RAM8(BATTLE_TEMP_A4);
        r->c = value3 >> 2 >= battle_damage;
        JSR(c, 0x4F48, 0xC04F6E); /* store_actor_impact_motion_when_counter_idle */
        uint16_t a_all = r->a;
        RAM8(ACTOR_DEATH_TIMER + x) = 3;
        a_hi1 = a_all >> 8;
        carry1 = value3 >> 2 >= battle_damage;
    }
    r->a = (a_hi1 << 8) | a;
    r->c = carry1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04F1E, SOM_RTS, "gen", select_actor_mp_damage_impact_motion, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 49, 23)
