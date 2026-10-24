#include "som_c.h"

/* C8E9FC cure_actor_statuses_and_shorten_timers   [class B, 109 bytes, 50 instructions]
 * Source: src/rom/cure_actor_statuses_and_shorten_timers.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCZNV.
 */
static void cure_actor_statuses_and_shorten_timers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM8(ACTOR_STATUS_HIGH + x) &= 0xFD;
    uint8_t value2 = RAM8(0x039D);
    if (value2 != 8) {
        if (value2 < 4) {
            uint16_t value3 = RAM16(0x0396);
            RAM8(BATTLE_TEMP_A4) = (uint8_t)(value3 >> 2);
            RAM8(0x03B2) = 5;
            uint8_t a_hi1 = value3 >> 2 >> 8;
            uint16_t x1 = x;
            bool carry1 = value3 >> 1 & 0x01;
            bool overflow1 = overflow;
            do {
                uint8_t value4 = RAM8(ACTOR_LOW_STATUS_TIMER + x1);
                uint8_t battle_temp_a4 = RAM8(BATTLE_TEMP_A4);
                uint8_t a1;
                bool zero1;
                if (value4 >= battle_temp_a4) {
                    a1 = (uint8_t)(value4 - battle_temp_a4);
                    zero1 = (uint8_t)(value4 - battle_temp_a4) == 0;
                } else {
                    a1 = 0;
                    zero1 = 1;
                }
                uint8_t a2;
                if (!zero1) {
                    a2 = a1;
                } else {
                    a2 = 1;
                }
                RAM8(ACTOR_LOW_STATUS_TIMER + x1) = a2;
                RAM8(0x03B2)--;
                x1 = (uint16_t)(x1 + 1);
                carry1 = value4 >= battle_temp_a4;
                overflow1 = ((value4 ^ battle_temp_a4) & (value4 ^ (uint8_t)(value4 - battle_temp_a4)) & 0x80) != 0;
            } while (RAM8(0x03B2) != 0);
            uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
            uint16_t battle_attacker_ptr = RAM16(BATTLE_ATTACKER_PTR);
            uint8_t value5 = RAM8(ACTOR_GUARD_FLAGS + battle_defender_ptr);
            RAM8(ACTOR_GUARD_FLAGS + battle_defender_ptr) = value5 | 4;
            r->a = (a_hi1 << 8) | (value5 | 4);
            r->x = battle_defender_ptr;
            r->y = battle_attacker_ptr;
            r->c = carry1;
            r->z = (value5 | 4) == 0;
            r->n = (value5 | 4) & 0x80;
            r->v = overflow1;
            RETURN_RTS(c);
        }
        uint8_t value6 = RAM8(0xE176 + y);
        if (value6 != 1) {
            uint16_t value7 = RAM16(0x0396);
            RAM8(BATTLE_TEMP_A4) = (uint8_t)(value7 >> 2);
            RAM8(0x03B2) = 5;
            uint8_t a_hi2 = value7 >> 2 >> 8;
            uint16_t x2 = x;
            bool carry2 = value7 >> 1 & 0x01;
            bool overflow2 = overflow;
            do {
                uint8_t value8 = RAM8(ACTOR_LOW_STATUS_TIMER + x2);
                uint8_t battle_temp_a42 = RAM8(BATTLE_TEMP_A4);
                uint8_t a3;
                bool zero2;
                if (value8 >= battle_temp_a42) {
                    a3 = (uint8_t)(value8 - battle_temp_a42);
                    zero2 = (uint8_t)(value8 - battle_temp_a42) == 0;
                } else {
                    a3 = 0;
                    zero2 = 1;
                }
                uint8_t a4;
                if (!zero2) {
                    a4 = a3;
                } else {
                    a4 = 1;
                }
                RAM8(ACTOR_LOW_STATUS_TIMER + x2) = a4;
                RAM8(0x03B2)--;
                x2 = (uint16_t)(x2 + 1);
                carry2 = value8 >= battle_temp_a42;
                overflow2 = ((value8 ^ battle_temp_a42) & (value8 ^ (uint8_t)(value8 - battle_temp_a42)) & 0x80) != 0;
            } while (RAM8(0x03B2) != 0);
            uint16_t battle_defender_ptr2 = RAM16(BATTLE_DEFENDER_PTR);
            uint16_t battle_attacker_ptr2 = RAM16(BATTLE_ATTACKER_PTR);
            uint8_t value9 = RAM8(ACTOR_GUARD_FLAGS + battle_defender_ptr2);
            RAM8(ACTOR_GUARD_FLAGS + battle_defender_ptr2) = value9 | 4;
            r->a = (a_hi2 << 8) | (value9 | 4);
            r->x = battle_defender_ptr2;
            r->y = battle_attacker_ptr2;
            r->c = carry2;
            r->z = (value9 | 4) == 0;
            r->n = (value9 | 4) & 0x80;
            r->v = overflow2;
            RETURN_RTS(c);
        }
        RAM8(ACTOR_LOW_STATUS_TIMER + x) = 1;
        RAM8(ACTOR_TIMER_1B3 + x) = 1;
        RAM8(ACTOR_DEATH_TIMER + x) = 1;
        RAM8(ACTOR_TIMER_1B5 + x) = 1;
        RAM8(ACTOR_STATUS_DAMAGE_TIMER + x) = 1;
        uint16_t value10 = RAM16(ACTOR_STATUS + x);
        RAM16_SET(ACTOR_STATUS + x, value10 & 0x8400);
        r->a = (r->a & 0x00FF) | (((value10 & 0x8400) >> 8) << 8);
        r->c = value6 >= 1;
        r->z = (value10 & 0x8400) == 0;
        r->n = value10 & 0x8400 & 0x8000;
        RETURN_RTS(c);
    }
    RAM8(ACTOR_LOW_STATUS_TIMER + x) = 1;
    RAM8(ACTOR_TIMER_1B3 + x) = 1;
    RAM8(ACTOR_DEATH_TIMER + x) = 1;
    RAM8(ACTOR_TIMER_1B5 + x) = 1;
    RAM8(ACTOR_STATUS_DAMAGE_TIMER + x) = 1;
    uint16_t value11 = RAM16(ACTOR_STATUS + x);
    RAM16_SET(ACTOR_STATUS + x, value11 & 0x8400);
    r->a = (r->a & 0x00FF) | (((value11 & 0x8400) >> 8) << 8);
    r->c = value2 >= 8;
    r->z = (value11 & 0x8400) == 0;
    r->n = value11 & 0x8400 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E9FC, SOM_RTS, "gen", cure_actor_statuses_and_shorten_timers, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 109, 50)
