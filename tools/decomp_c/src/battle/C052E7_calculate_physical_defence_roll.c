#include "som_c.h"

/* C052E7 calculate_physical_defence_roll   [class B, 69 bytes, 35 instructions]
 * Source: src/rom/calculate_physical_defence_roll.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void calculate_physical_defence_roll(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 0x64;
    r->z = 0;
    r->n = 0;
    JSL(c, 0x52EC, 0xC03884); /* random_below_long_wrapper */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    uint8_t battle_evade_work = RAM8(BATTLE_EVADE_WORK);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool overflow1;
    if ((uint8_t)a_all >= battle_evade_work) {
        RAM16_SET(BATTLE_TEMP_A8, RAM16(0x0394));
        RAM8(BATTLE_TEMP_A6) = battle_evade_work;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x531A, 0xC0543B); /* multiply_byte_word_divide_by_100 */
        bool overflow_ret2 = r->v;
        uint16_t battle_temp_a4 = RAM16(BATTLE_TEMP_A4);
        a1 = (uint8_t)battle_temp_a4;
        a_hi1 = battle_temp_a4 >> 8;
        x1 = x_ret;
        y1 = y_ret;
        overflow1 = overflow_ret2;
    } else {
        uint16_t value2 = RAM16(0x0394);
        r->a = value2 >> 4;
        r->c = value2 >> 3 & 0x01;
        r->z = value2 >> 4 == 0;
        r->n = value2 >> 4 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        JSL(c, 0x52FE, 0xC03884); /* random_below_long_wrapper */
        uint16_t a_all3 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        uint16_t value3 = RAM16(0x0394);
        a1 = (uint8_t)((a_all3 & 0xFF) + value3);
        a_hi1 = (uint16_t)((a_all3 & 0xFF) + value3) >> 8;
        x1 = x_ret2;
        y1 = y_ret2;
        overflow1 = (((a_all3 & 0xFF) ^ (uint16_t)((a_all3 & 0xFF) + value3)) & (value3 ^ (uint16_t)((a_all3 & 0xFF) + value3)) & 0x8000) != 0;
    }
    uint8_t a2;
    uint8_t a_hi2;
    if (((a_hi1 << 8) | a1) < 0x03E7) {
        a2 = a1;
        a_hi2 = a_hi1;
    } else {
        a2 = 0xE7;
        a_hi2 = 3;
    }
    RAM16_SET(0x0394, (a_hi2 << 8) | a2);
    r->a = (a_hi2 << 8) | a2;
    r->x = x1;
    r->y = y1;
    r->c = ((a_hi1 << 8) | a1) >= 0x03E7;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC052E7, SOM_RTS, "gen", calculate_physical_defence_roll, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 69, 35)
