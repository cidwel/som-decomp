#include "som_c.h"

/* C8ECB5 apply_lunar_boost_spell   [class A, 28 bytes, 12 instructions]
 * Source: src/rom/apply_lunar_boost_spell.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void apply_lunar_boost_spell(SomCtx *c)
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
    JSR(c, 0xECBD, 0xC8E8C0); /* calculate_spell_attack_roll */
    uint16_t x_ret = r->x;
    RAM8(ACTOR_BUFF_FLAGS + x_ret) = (RAM8(ACTOR_BUFF_FLAGS + x_ret) & 0x33) | 0x48;
    uint8_t value2 = RAM8(0x039C);
    RAM8(0xE1B7 + x_ret) = value2;
    RAM8(0xE1BB + x_ret) = value2;
    SET_A8(r, value2);
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8ECB5, SOM_RTS, "gen", apply_lunar_boost_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 28, 12)
