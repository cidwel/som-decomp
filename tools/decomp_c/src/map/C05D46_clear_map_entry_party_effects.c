#include "som_c.h"

/* C05D46 clear_map_entry_party_effects   [class B, 117 bytes, 55 instructions]
 * Source: src/rom/clear_map_entry_party_effects.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void clear_map_entry_party_effects(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = 0;
    RAM8(0x0000 + sp0 - 3) = ((((negative << 7) | (overflow << 6) | 0x20 | 0x10) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    uint16_t x1 = 0xFE00;
    uint16_t y1 = 0x0100;
    for (;;) {
        RAM16_SET(0x0000 + x1, 0);
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    RAM16_SET(0x03B4, 0x0400);
    uint8_t a_hi1 = 4;
    uint16_t x2 = x1;
    uint16_t y2 = y1;
    bool carry1 = carry;
    bool overflow1 = overflow;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint16_t value = RAM16(0x03B4);
            RAM16_SET(ACTOR_PENDING_HP_DAMAGE + value, 0);
            RAM16_SET(ACTOR_PENDING_HP_HEAL + value, 0);
            RAM16_SET(ACTOR_PENDING_MP_DAMAGE + value, 0);
            uint16_t value2 = RAM16(ACTOR_STATUS + value);
            RAM16_SET(ACTOR_STATUS + value, value2 & 0xF7EC);
            RAM8(HERO_HIT_MASK + value) = 0;
            uint8_t value3 = RAM8(0xE02C + value);
            uint8_t a_hi3;
            uint16_t x4;
            uint16_t y4;
            bool carry3;
            bool overflow3;
            if (value3 == 0) {
                r->a = ((value2 & 0xF7EC) >> 8 << 8) | 1;
                r->x = value;
                r->y = y2;
                r->c = carry1;
                r->z = 0;
                r->n = 0;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0x0300;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSL(c, 0x5DA0, 0xC10024); GUARD_JSL(c, sp_call, 0x5DA0); } /* call_actor_status_program_long */
                r->sp += 4;
                if (r->mf != 1) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all = r->a;
                uint16_t x_ret = r->x;
                uint16_t y_ret = r->y;
                bool carry_ret = r->c;
                bool overflow_ret = r->v;
                a_hi3 = a_all >> 8;
                x4 = x_ret;
                y4 = y_ret;
                carry3 = carry_ret;
                overflow3 = overflow_ret;
            } else {
                uint16_t value4 = RAM16(ACTOR_STATUS + value);
                uint8_t a_hi2;
                uint16_t x3;
                uint16_t y3;
                bool carry2;
                bool overflow2;
                if ((value4 & 0x4160) != 0) {
                    r->a = (value4 >> 8 << 8) | 1;
                    r->x = value;
                    r->y = y2;
                    r->c = carry1;
                    r->z = 0;
                    r->n = 0;
                    r->v = overflow1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0x0300;
                    r->sp -= 4;
                    { const uint16_t sp_call = r->sp; JSL(c, 0x5DA0, 0xC10024); GUARD_JSL(c, sp_call, 0x5DA0); } /* call_actor_status_program_long */
                    r->sp += 4;
                    if (r->mf != 1) { c->fail = 3; return; }
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t a_all2 = r->a;
                    uint16_t x_ret2 = r->x;
                    uint16_t y_ret2 = r->y;
                    bool carry_ret2 = r->c;
                    bool overflow_ret2 = r->v;
                    a_hi2 = a_all2 >> 8;
                    x3 = x_ret2;
                    y3 = y_ret2;
                    carry2 = carry_ret2;
                    overflow2 = overflow_ret2;
                } else {
                    a_hi2 = value4 >> 8;
                    x3 = value;
                    y3 = y2;
                    carry2 = carry1;
                    overflow2 = overflow1;
                }
                a_hi3 = a_hi2;
                x4 = x3;
                y4 = y3;
                carry3 = carry2;
                overflow3 = overflow2;
            }
            RAM8(0x03B5)--;
            RAM8(0x03B5)--;
            if (!(RAM8(0x03B5) & 0x80)) {
                a_hi1 = a_hi3;
                x2 = x4;
                y2 = y4;
                carry1 = carry3;
                overflow1 = overflow3;
                first_pass = false;
                continue;
            }
            a_hi1 = a_hi3;
            x2 = x4;
            y2 = y4;
            carry1 = carry3;
            overflow1 = overflow3;
            break;
        } else {
            uint16_t value5 = RAM16(0x03B4);
            RAM16_SET(ACTOR_PENDING_HP_DAMAGE + value5, 0);
            RAM16_SET(ACTOR_PENDING_HP_HEAL + value5, 0);
            RAM16_SET(ACTOR_PENDING_MP_DAMAGE + value5, 0);
            uint16_t value6 = RAM16(ACTOR_STATUS + value5);
            RAM16_SET(ACTOR_STATUS + value5, value6 & 0xF7EC);
            RAM8(HERO_HIT_MASK + value5) = 0;
            uint8_t value7 = RAM8(0xE02C + value5);
            uint8_t a_hi5;
            uint16_t x6;
            uint16_t y6;
            bool carry5;
            bool overflow5;
            if (value7 == 0) {
                r->a = ((value6 & 0xF7EC) >> 8 << 8) | 1;
                r->x = value5;
                r->y = y2;
                r->c = carry1;
                r->z = 0;
                r->n = 0;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0x0300;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSL(c, 0x5DA0, 0xC10024); GUARD_JSL(c, sp_call, 0x5DA0); } /* call_actor_status_program_long */
                r->sp += 4;
                if (r->mf != 1) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all3 = r->a;
                uint16_t x_ret3 = r->x;
                uint16_t y_ret3 = r->y;
                bool carry_ret3 = r->c;
                bool overflow_ret3 = r->v;
                a_hi5 = a_all3 >> 8;
                x6 = x_ret3;
                y6 = y_ret3;
                carry5 = carry_ret3;
                overflow5 = overflow_ret3;
            } else {
                uint16_t value8 = RAM16(ACTOR_STATUS + value5);
                uint8_t a_hi4;
                uint16_t x5;
                uint16_t y5;
                bool carry4;
                bool overflow4;
                if ((value8 & 0x4160) != 0) {
                    r->a = (value8 >> 8 << 8) | 1;
                    r->x = value5;
                    r->y = y2;
                    r->c = carry1;
                    r->z = 0;
                    r->n = 0;
                    r->v = overflow1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0x0300;
                    r->sp -= 4;
                    { const uint16_t sp_call = r->sp; JSL(c, 0x5DA0, 0xC10024); GUARD_JSL(c, sp_call, 0x5DA0); } /* call_actor_status_program_long */
                    r->sp += 4;
                    if (r->mf != 1) { c->fail = 3; return; }
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t a_all4 = r->a;
                    uint16_t x_ret4 = r->x;
                    uint16_t y_ret4 = r->y;
                    bool carry_ret4 = r->c;
                    bool overflow_ret4 = r->v;
                    a_hi4 = a_all4 >> 8;
                    x5 = x_ret4;
                    y5 = y_ret4;
                    carry4 = carry_ret4;
                    overflow4 = overflow_ret4;
                } else {
                    a_hi4 = value8 >> 8;
                    x5 = value5;
                    y5 = y2;
                    carry4 = carry1;
                    overflow4 = overflow1;
                }
                a_hi5 = a_hi4;
                x6 = x5;
                y6 = y5;
                carry5 = carry4;
                overflow5 = overflow4;
            }
            RAM8(0x03B5)--;
            RAM8(0x03B5)--;
            if (!(RAM8(0x03B5) & 0x80)) {
                a_hi1 = a_hi5;
                x2 = x6;
                y2 = y6;
                carry1 = carry5;
                overflow1 = overflow5;
                continue;
            }
            a_hi1 = a_hi5;
            x2 = x6;
            y2 = y6;
            carry1 = carry5;
            overflow1 = overflow5;
            break;
        }
    }
    RAM8(0x03A0) = 0;
    RAM8(0x039F) = 0;
    RAM8(0x03A2) = 0;
    RAM8(0x03A1) = 0;
    RAM8(0x03A3) = 0;
    r->a = (a_hi1 << 8) | 0;
    r->x = x2;
    r->y = y2;
    r->c = carry1;
    r->z = 1;
    r->n = 0;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0300;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5DB6, 0xC00098); GUARD_JSL(c, sp_call, 0x5DB6); } /* clear_map_menu_workspace_jump */
    r->sp += 4;
    uint8_t value9 = RAM8(0x0000 + sp0 - 3);
    uint8_t value10 = RAM8(0x0000 + sp0 - 2);
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->c = value9 & 0x01;
    r->v = value9 & 0x40;
    r->mf = value9 & 0x20;
    r->xf = value9 & 0x10;
    r->db = value10;
    r->dp = (value12 << 8) | value11;
    r->i = value9 & 0x04;
    r->d = value9 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05D46, SOM_RTL, "gen", clear_map_entry_party_effects, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 5, 1, 1, 117, 55)
