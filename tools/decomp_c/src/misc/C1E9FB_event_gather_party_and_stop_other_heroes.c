#include "som_c.h"

/* C1E9FB event_gather_party_and_stop_other_heroes   [class B, 43 bytes, 19 instructions]
 * Source: src/rom/event_gather_party_and_stop_other_heroes.s
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_gather_party_and_stop_other_heroes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t y = r->y;
    const bool overflow = r->v;
    RAM8(0x004E) = 0x80;
    RAM8(0x00D0) = 0x80;
    uint16_t value = RAM16(0x00D4);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t y1;
    bool overflow1;
    if (value == 0) {
        a1 = 0x80;
        a_hi1 = a_hi;
        y1 = y;
        overflow1 = overflow;
    } else {
        r->a = (a_hi << 8) | 0x80;
        r->x = 0;
        r->c = value <= 0;
        r->z = value == 0;
        r->n = (uint16_t)(0 - value) & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEA0C, 0xC1CA6C); GUARD_JSR(c, sp_call, 0xEA0C); } /* clear_actor_movement_charge_and_palette_effects */
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        y1 = y_ret;
        overflow1 = overflow_ret;
    }
    uint16_t value2 = RAM16(0x00D4);
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t y2;
    bool overflow2;
    if (value2 == 0x0200) {
        a2 = a1;
        a_hi2 = a_hi1;
        y2 = y1;
        overflow2 = overflow1;
    } else {
        r->a = (a_hi1 << 8) | a1;
        r->x = 0x0200;
        r->y = y1;
        r->c = value2 <= 0x0200;
        r->z = value2 == 0x0200;
        r->n = (uint16_t)(0x0200 - value2) & 0x8000;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEA16, 0xC1CA6C); GUARD_JSR(c, sp_call, 0xEA16); } /* clear_actor_movement_charge_and_palette_effects */
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        uint16_t y_ret2 = r->y;
        bool overflow_ret2 = r->v;
        a2 = (uint8_t)a_all2;
        a_hi2 = a_all2 >> 8;
        y2 = y_ret2;
        overflow2 = overflow_ret2;
    }
    uint16_t value3 = RAM16(0x00D4);
    bool x_flag;
    uint8_t a3;
    uint8_t a_hi3;
    uint16_t x1;
    uint16_t y3;
    bool carry1;
    bool overflow3;
    if (value3 == 0x0400) {
        x_flag = 0;
        a3 = a2;
        a_hi3 = a_hi2;
        x1 = 0x0400;
        y3 = y2;
        carry1 = value3 <= 0x0400;
        overflow3 = overflow2;
    } else {
        r->a = (a_hi2 << 8) | a2;
        r->x = 0x0400;
        r->y = y2;
        r->c = value3 <= 0x0400;
        r->z = value3 == 0x0400;
        r->n = (uint16_t)(0x0400 - value3) & 0x8000;
        r->v = overflow2;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEA20, 0xC1CA6C); GUARD_JSR(c, sp_call, 0xEA20); } /* clear_actor_movement_charge_and_palette_effects */
        bool x_ret3 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        x_flag = x_ret3;
        a3 = (uint8_t)a_all3;
        a_hi3 = a_all3 >> 8;
        x1 = x_ret4;
        y3 = y_ret3;
        carry1 = carry_ret3;
        overflow3 = overflow_ret3;
    }
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    r->a = (a_hi3 << 8) | a3;
    r->x = x1;
    r->y = y3;
    r->c = carry1;
    r->z = RAM16(0x00D1) == 0;
    r->n = RAM16(0x00D1) & 0x8000;
    r->v = overflow3;
    r->mf = 0;
    r->xf = x_flag;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E9FB, SOM_RTS, "gen", event_gather_party_and_stop_other_heroes, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 43, 19)
