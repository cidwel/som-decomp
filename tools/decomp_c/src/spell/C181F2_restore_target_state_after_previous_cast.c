#include "som_c.h"

/* C181F2 restore_target_state_after_previous_cast   [class B, 83 bytes, 33 instructions]
 * Source: src/rom/restore_target_state_after_previous_cast.s
 * Documented in docs/actor-cast-restore.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void restore_target_state_after_previous_cast(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0xE10C + y);
    uint8_t value2 = RAM8(0xE118 + y);
    uint8_t a1;
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    if (value2 != 1) {
        r->a = (a_hi << 8) | value2;
        r->x = y;
        r->y = value;
        r->c = value2 >= 1;
        r->z = value2 == 1;
        r->n = (uint8_t)(value2 - 1) & 0x80;
        r->sp -= 4;
        JSL(c, 0x820B, 0xC0001E); /* finish_previous_cast_public_jump */
        r->sp += 4;
        uint16_t a_all = r->a;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
    } else {
        uint8_t value3 = RAM8(0xE121 + y);
        r->a = (a_hi << 8) | value3;
        r->c = value2 >= 1;
        r->sp -= 4;
        JSL(c, 0x8205, 0xC00033); /* unused_cast_completion_public_jump */
        r->sp += 4;
        a1 = value3;
        a_hi1 = a_hi;
        carry1 = value2 >= 1;
        overflow1 = overflow;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x;
    r->y = y;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8212, 0xC1CA4F); /* restore_target_effect_palettes_preserving_actor */
    uint16_t y_ret2 = r->y;
    RAM8(0xE01C + y_ret2) = RAM8(0xE128 + y_ret2);
    RAM8(0xE05D + y_ret2) = RAM8(0xE129 + y_ret2);
    RAM8(0xE008 + y_ret2) = 0xFF;
    RAM16_SET(0xE104 + y_ret2, RAM16(0xE12E + y_ret2));
    RAM16_SET(0xE106 + y_ret2, RAM16(0xE124 + y_ret2));
    RAM16_SET(0xE006 + y_ret2, RAM16(0xE134 + y_ret2));
    RAM16_SET(0xE008 + y_ret2, RAM16(0xE122 + y_ret2));
    uint16_t value10 = RAM16(0xE12A + y_ret2);
    RAM16_SET(0xE05E + y_ret2, value10);
    r->a = value10;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC181F2, SOM_RTS, "gen", restore_target_state_after_previous_cast, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 83, 33)
