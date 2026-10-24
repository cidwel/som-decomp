#include "som_c.h"

static void store_selected_actor_weapon_experience_byte(SomCtx *c);

/* C043B7 advance_actor_weapon_experience_and_level   [class B, 162 bytes, 74 instructions]
 * Source: src/rom/advance_actor_weapon_experience_and_level.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BYCV.
 */
static void advance_actor_weapon_experience_and_level(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp_in = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0xE000 + y);
    if (value == 1) {
        if (!(RAM8(ACTOR_STATUS_HIGH + y) & 0x80)) {
            uint8_t value4 = BUS8(c, 0xC043AC + (RAM16(ACTOR_WEAPON_LEVEL + y) & 0xFF));
            RAM8(BATTLE_DIV_WORK) = value4;
            uint8_t value5 = RAM8(0xE1E4 + y);
            RAM8(0x03B0) = (uint8_t)(RAM8(0xCFB0 + value5) + 1);
            RAM16_SET(BATTLE_MUL_WORK, y);
            RAM16_SET(0x03D4, y);
            uint8_t value7 = RAM8(ACTOR_WEAPON_LEVEL + y);
            uint8_t value8 = RAM8(0x03B0);
            if (value7 != value8) {
                RAM8(0x03D4) = RAM8(0xE1E4 + y);
                uint8_t value11 = RAM8(0xE1D0 + RAM16(0x03D4));
                uint8_t battle_temp_a6 = RAM8(BATTLE_TEMP_A6);
                RAM8(0x03D0) = (uint8_t)(value11 + battle_temp_a6);
                uint16_t battle_mul_work = RAM16(BATTLE_MUL_WORK);
                uint8_t value12 = RAM8(0x03D0);
                uint8_t battle_div_work = RAM8(BATTLE_DIV_WORK);
                if (value12 < battle_div_work) {
                    r->a = value12;
                    r->x = value5;
                    r->y = battle_mul_work;
                    r->c = value12 >= battle_div_work;
                    r->z = value12 == battle_div_work;
                    r->n = (uint8_t)(value12 - battle_div_work) & 0x80;
                    r->v = ((value11 ^ (uint8_t)(value11 + battle_temp_a6)) & (battle_temp_a6 ^ (uint8_t)(value11 + battle_temp_a6)) & 0x80) != 0;
                    store_selected_actor_weapon_experience_byte(c); return;
                }
                uint8_t value13 = RAM8(ACTOR_WEAPON_LEVEL + battle_mul_work);
                if (value13 != 8) {
                    RAM8(0x03D0) = 0;
                    uint8_t value14 = RAM8(0xE1E4 + battle_mul_work);
                    RAM8(BATTLE_DIV_WORK) = value14;
                    RAM8(0x03D4) = value14 >> 1;
                    uint16_t value15 = RAM16(0x03D4);
                    uint8_t battle_div_work2 = RAM8(BATTLE_DIV_WORK);
                    bool carry1;
                    bool overflow1;
                    if ((battle_div_work2 & 1) != 0) {
                        RAM8(0xE1C0 + value15) = (uint8_t)(RAM8(0xE1C0 + value15) + 1);
                        carry1 = value14 & 0x01;
                        overflow1 = ((value11 ^ (uint8_t)(value11 + battle_temp_a6)) & (battle_temp_a6 ^ (uint8_t)(value11 + battle_temp_a6)) & 0x80) != 0;
                    } else {
                        uint8_t value17 = RAM8(0xE1C0 + value15);
                        RAM8(0xE1C0 + value15) = (uint8_t)(value17 + 0x10);
                        carry1 = value17 + 0x10 > 0xFF;
                        overflow1 = ((value17 ^ (uint8_t)(value17 + 0x10)) & ((uint8_t)(value17 + 0x10) ^ 0x10) & 0x80) != 0;
                    }
                    r->a = a;
                    r->x = value5;
                    r->y = value15;
                    r->c = carry1;
                    r->v = overflow1;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x443A, store_selected_actor_weapon_experience_byte, sp_in, 2); GUARD_JSR(c, sp_call, 0x443A); }
                    uint16_t dp_ret = r->dp;
                    uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xCC));
                    r->x = value18;
                    r->z = value18 == 0;
                    r->n = value18 & 0x8000;
                    r->mf = 1;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSL(c, 0x4440, 0xC04530); GUARD_JSL(c, sp_call, 0x4440); } /* rebuild_actor_attributes_native */
                    { const uint16_t sp_call = r->sp; JSR(c, 0x4443, 0xC05B40); GUARD_JSR(c, sp_call, 0x4443); } /* enqueue_actor_weapon_level_up_notice */
                    if (r->mf != 1) { c->fail = 3; return; }
                    uint16_t a_all3 = r->a;
                    r->a = (a_all3 >> 8 << 8) | 0xCE;
                    r->z = 0;
                    r->n = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x4448, 0xC0398D); GUARD_JSR(c, sp_call, 0x4448); } /* send_combat_sound_with_fixed_parameter_fifteen */
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                RAM8(0x03D0) = battle_div_work;
                r->a = battle_div_work;
                r->x = value5;
                r->y = battle_mul_work;
                r->c = value13 >= 8;
                r->z = battle_div_work == 0;
                r->n = battle_div_work & 0x80;
                r->v = ((value11 ^ (uint8_t)(value11 + battle_temp_a6)) & (battle_temp_a6 ^ (uint8_t)(value11 + battle_temp_a6)) & 0x80) != 0;
                store_selected_actor_weapon_experience_byte(c); return;
            }
            RAM8(0x03D0) = 0;
            r->a = value7;
            r->x = value5;
            r->c = value7 >= value8;
            r->z = value7 == value8;
            r->n = (uint8_t)(value7 - value8) & 0x80;
            store_selected_actor_weapon_experience_byte(c); return;
        }
        r->c = value >= 1;
        RETURN_RTS(c);
    }
    r->c = value >= 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC043B7, SOM_RTS, "gen", advance_actor_weapon_experience_and_level, 0, L_B | L_Y | L_C | L_V, 5, 1, 0, 162, 74)

/* C0444A store_selected_actor_weapon_experience_byte   [class A, 15 bytes, 7 instructions]
 * Source: src/rom/advance_actor_weapon_experience_and_level.s
 * Subroutine of advance_actor_weapon_experience_and_level, translated in place.
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void store_selected_actor_weapon_experience_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    RAM8(0x03D4) = RAM8(0xE1E4 + RAM16(BATTLE_MUL_WORK));
    uint16_t value2 = RAM16(0x03D4);
    uint8_t value3 = RAM8(0x03D0);
    RAM8(0xE1D0 + value2) = value3;
    SET_A8(r, value3);
    r->y = value2;
    r->z = value3 == 0;
    r->n = value3 & 0x80;
    RETURN_RTS(c);
}
