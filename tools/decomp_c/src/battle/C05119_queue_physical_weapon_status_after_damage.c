#include "som_c.h"

/* C05119 queue_physical_weapon_status_after_damage   [class B, 50 bytes, 21 instructions]
 * Source: src/rom/queue_physical_weapon_status_after_damage.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void queue_physical_weapon_status_after_damage(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint8_t value = RAM8(ACTOR_STATUS + x);
    if ((value & 0x10) != 0) {
        RAM8(ACTOR_STATUS + x) = value & 0xEF;
    }
    uint16_t value2 = RAM16(ACTOR_INFLICTED_STATUS + y);
    uint16_t value3 = RAM16(ACTOR_STATUS_IMMUNITY + x);
    uint8_t a_hi3;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    if ((value2 & value3) != 0) {
        a_hi3 = value2 >> 8;
        x1 = x;
        y1 = y;
        carry1 = carry;
        overflow1 = value3 & 0x4000;
    } else {
        r->a = (value2 >> 8 << 8) | 0x64;
        r->z = 0;
        r->n = 0;
        r->v = value3 & 0x4000;
        JSL(c, 0x5136, 0xC03884); /* random_below_long_wrapper */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        uint8_t value4 = RAM8(ACTOR_WEAPON_STATUS_CHANCE + y_ret);
        uint8_t a_hi2;
        if ((uint8_t)a_all >= value4) {
            a_hi2 = a_all >> 8;
        } else {
            uint16_t value5 = RAM16(ACTOR_PENDING_HP_DAMAGE + x_ret);
            uint8_t a_hi1;
            if (value5 == 0) {
                a_hi1 = value5 >> 8;
            } else {
                uint16_t value6 = RAM16(ACTOR_INFLICTED_STATUS + y_ret);
                RAM16_SET(0x039A, value6);
                a_hi1 = value6 >> 8;
            }
            a_hi2 = a_hi1;
        }
        a_hi3 = a_hi2;
        x1 = x_ret;
        y1 = y_ret;
        carry1 = (uint8_t)a_all >= value4;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi3 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC05119, SOM_RTS, "gen", queue_physical_weapon_status_after_damage, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 50, 21)
