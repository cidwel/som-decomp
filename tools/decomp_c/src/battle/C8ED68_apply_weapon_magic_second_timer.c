#include "som_c.h"

/* C8ED68 apply_weapon_magic_second_timer   [class A, 26 bytes, 12 instructions]
 * Source: src/rom/apply_weapon_magic_second_timer.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void apply_weapon_magic_second_timer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    uint8_t value = RAM8(0xE1E4);
    if (value == 1) {
        RAM8(0xE19D) = 0;
        RAM8(0x038F) = 4;
        r->a = (a_hi << 8) | 4;
        r->x = battle_defender_ptr;
        r->c = value >= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xED7B, 0xC8E8C0); GUARD_JSR(c, sp_call, 0xED7B); } /* calculate_spell_attack_roll */
        uint8_t value2 = RAM8(0x039C);
        RAM8(0xCC79) = value2;
        SET_A8(r, value2);
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    SET_A8(r, value);
    r->x = battle_defender_ptr;
    r->c = value >= 1;
    r->z = value == 1;
    r->n = (uint8_t)(value - 1) & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8ED68, SOM_RTS, "gen", apply_weapon_magic_second_timer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 26, 12)
