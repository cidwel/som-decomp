#include "som_c.h"

/* C8E990 calculate_spell_magic_defence_roll   [class B, 79 bytes, 37 instructions]
 * Source: src/rom/calculate_spell_magic_defence_roll.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: X.
 */
static void calculate_spell_magic_defence_roll(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 0x65;
    r->z = 0;
    r->n = 0;
    JSL(c, 0xE995, 0xC03884); /* random_below_long_wrapper */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    if ((uint8_t)a_all >= RAM8(ACTOR_MAGIC_EVADE + x_ret)) {
        uint16_t value2 = RAM16(ACTOR_MAGIC_DEFENSE + x_ret);
        RAM16_SET(BATTLE_TEMP_A8, (uint16_t)((value2 >> 2) + value2));
        RAM8(BATTLE_TEMP_A6) = RAM8(ACTOR_MAGIC_EVADE + x_ret);
        r->mf = 1;
        r->xf = 0;
        JSL(c, 0xE9D5, 0xC05437); /* multiply_byte_word_divide_by_100_long_wrapper */
        RAM16_SET(0x0394, RAM16(BATTLE_TEMP_A4));
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value4 = RAM16(ACTOR_MAGIC_DEFENSE + x_ret);
    r->a = value4 >> 4;
    r->c = value4 >> 3 & 0x01;
    r->z = value4 >> 4 == 0;
    r->n = value4 >> 4 & 0x8000;
    r->mf = 1;
    r->xf = 0;
    JSL(c, 0xE9A9, 0xC03884); /* random_below_long_wrapper */
    uint16_t a_all3 = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t value5 = RAM16(ACTOR_MAGIC_DEFENSE + x_ret2);
    uint8_t a1;
    uint8_t a_hi1;
    if ((uint16_t)((a_all3 & 0xFF) + value5) < 0x03E7) {
        a1 = (uint8_t)((a_all3 & 0xFF) + value5);
        a_hi1 = (uint16_t)((a_all3 & 0xFF) + value5) >> 8;
    } else {
        a1 = 0xE7;
        a_hi1 = 3;
    }
    RAM16_SET(0x0394, (a_hi1 << 8) | a1);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E990, SOM_RTS, "gen", calculate_spell_magic_defence_roll, 0, L_X, 1, 1, 0, 79, 37)
