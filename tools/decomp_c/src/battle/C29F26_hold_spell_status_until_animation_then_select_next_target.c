#include "som_c.h"

/* C29F26 hold_spell_status_until_animation_then_select_next_target   [class B, 22 bytes, 9 instructions]
 * Source: src/rom/hold_spell_status_until_animation_then_select_next_target.s
 * Documented in docs/boss-native-spell-hold-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void hold_spell_status_until_animation_then_select_next_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    r->x = value;
    JSR(c, 0x9F2A, 0xC29910); /* set_eligible_spell_target_status_and_timer */
    uint16_t y_ret = r->y;
    uint16_t value2 = RAM16(0x009E + value);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value2 != 0) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        x1 = value;
        y1 = y_ret;
        carry1 = carry;
        zero1 = value2 == 0;
        negative1 = value2 & 0x8000;
        overflow1 = overflow;
    } else {
        r->a = value2;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x9F32, 0xC29FBD); /* clear_spell_status_and_mark_reciprocal_contacts */
        RAM16_SET(0x00BA + RAM16(0x0287), 0);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x9F3A, 0xC29A74); /* select_next_live_active_party_spell_target */
        uint16_t a_all3 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret2 = r->c;
        bool zero_ret3 = r->z;
        bool negative_ret3 = r->n;
        bool overflow_ret2 = r->v;
        a1 = (uint8_t)a_all3;
        a_hi1 = a_all3 >> 8;
        x1 = x_ret2;
        y1 = y_ret3;
        carry1 = carry_ret2;
        zero1 = zero_ret3;
        negative1 = negative_ret3;
        overflow1 = overflow_ret2;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29F26, SOM_RTS, "gen", hold_spell_status_until_animation_then_select_next_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 22, 9)
