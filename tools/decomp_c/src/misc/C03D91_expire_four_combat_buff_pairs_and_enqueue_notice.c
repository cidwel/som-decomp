#include "som_c.h"

/* C03D91 expire_four_combat_buff_pairs_and_enqueue_notice   [class B, 75 bytes, 33 instructions]
 * Source: src/rom/expire_four_combat_buff_pairs_and_enqueue_notice.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void expire_four_combat_buff_pairs_and_enqueue_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(ACTOR_BUFF_FLAGS + x);
    uint8_t a2;
    if ((value & 3) == 0) {
        a2 = value;
    } else {
        RAM8(0xE1BC + x)--;
        uint8_t a1;
        if (RAM8(0xE1BC + x) != 0) {
            a1 = value;
        } else {
            RAM8(ACTOR_BUFF_FLAGS + x) = value & 0xFC;
            a1 = value & 0xFC;
        }
        a2 = a1;
    }
    uint8_t a4;
    if ((a2 & 0x0C) == 0) {
        a4 = a2;
    } else {
        RAM8(0xE1BB + x)--;
        uint8_t a3;
        if (RAM8(0xE1BB + x) != 0) {
            a3 = a2;
        } else {
            RAM8(ACTOR_BUFF_FLAGS + x) = a2 & 0xF3;
            a3 = a2 & 0xF3;
        }
        a4 = a3;
    }
    uint8_t a6;
    if ((a4 & 0x30) == 0) {
        a6 = a4;
    } else {
        RAM8(0xE1BA + x)--;
        uint8_t a5;
        if (RAM8(0xE1BA + x) != 0) {
            a5 = a4;
        } else {
            RAM8(ACTOR_BUFF_FLAGS + x) = a4 & 0xCF;
            a5 = a4 & 0xCF;
        }
        a6 = a5;
    }
    if ((a6 & 0xC0) != 0) {
        RAM8(0xE1B7 + x)--;
        if (RAM8(0xE1B7 + x) == 0) {
            RAM8(ACTOR_BUFF_FLAGS + x) = a6 & 0x3F;
        }
    }
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool overflow2;
    if (value == 0) {
        a_hi2 = a_hi;
        x2 = x;
        y2 = y;
        carry2 = carry;
        overflow2 = overflow;
    } else {
        uint8_t value2 = RAM8(ACTOR_BUFF_FLAGS + x);
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        if (value2 != 0) {
            a_hi1 = a_hi;
            x1 = x;
            y1 = y;
            carry1 = carry;
            overflow1 = overflow;
        } else {
            r->a = (a_hi << 8) | value2;
            JSL(c, 0x3DD8, 0xC058B9); /* enqueue_actor_buff_expiration_notice */
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
            a_hi1 = a_all >> 8;
            x1 = battle_defender_ptr;
            y1 = y_ret;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
        }
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        overflow2 = overflow1;
    }
    r->a = (a_hi2 << 8) | a;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03D91, SOM_RTS, "gen", expire_four_combat_buff_pairs_and_enqueue_notice, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 75, 33)
