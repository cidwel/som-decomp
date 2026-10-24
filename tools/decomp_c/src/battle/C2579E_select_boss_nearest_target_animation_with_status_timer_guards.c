#include "som_c.h"

/* C2579E select_boss_nearest_target_animation_with_status_timer_guards   [class B, 111 bytes, 46 instructions]
 * Source: src/rom/select_boss_nearest_target_animation_with_status_timer_guards.s
 * Documented in docs/boss-native-target-animation.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void select_boss_nearest_target_animation_with_status_timer_guards(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    { const uint16_t sp_call = r->sp; JSR(c, 0x57A0, 0xC23224); GUARD_JSR(c, sp_call, 0x57A0); } /* select_nearest_active_living_party_actor */
    uint16_t a_all = r->a;
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x00A9 + value, a_all);
    if ((RAM16(0x0190 + value) & 0x8003) != 0) {
        uint16_t value3 = RAM16(0x009A + value);
        uint8_t a_hi1;
        if (value3 == 0x18) {
            a_hi1 = 0;
        } else {
            r->a = 0x18;
            r->x = value;
            r->c = value3 <= 0x18;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x57CF, 0xC21394); GUARD_JSR(c, sp_call, 0x57CF); } /* select_boss_animation_and_reset_frame_cursor */
            uint16_t a_all2 = r->a;
            a_hi1 = a_all2 >> 8;
        }
        r->a = (a_hi1 << 8) | (uint8_t)a;
        r->x = value;
        r->c = value3 <= 0x18;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if ((RAM16(0x0060 + value) & 0xE0) != 0) {
        uint16_t value5 = RAM16(0x009A + value);
        uint8_t a_hi2;
        if (value5 == 0x18) {
            a_hi2 = 0;
        } else {
            r->a = 0x18;
            r->x = value;
            r->c = value5 <= 0x18;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x57CF, 0xC21394); GUARD_JSR(c, sp_call, 0x57CF); } /* select_boss_animation_and_reset_frame_cursor */
            uint16_t a_all3 = r->a;
            a_hi2 = a_all3 >> 8;
        }
        r->a = (a_hi2 << 8) | (uint8_t)a;
        r->x = value;
        r->c = value5 <= 0x18;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if (RAM16(0x00B8 + value) != 0) {
        RAM16_SET(0x00B8 + value, (uint16_t)(RAM16(0x00B8 + value) - 1));
        uint16_t value7 = RAM16(0x009A + value);
        uint8_t a_hi3;
        if (value7 == 0x18) {
            a_hi3 = 0;
        } else {
            r->a = 0x18;
            r->x = value;
            r->c = value7 <= 0x18;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x57CF, 0xC21394); GUARD_JSR(c, sp_call, 0x57CF); } /* select_boss_animation_and_reset_frame_cursor */
            uint16_t a_all4 = r->a;
            a_hi3 = a_all4 >> 8;
        }
        r->a = (a_hi3 << 8) | (uint8_t)a;
        r->x = value;
        r->c = value7 <= 0x18;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value8 = RAM16(0x002D + value);
    if (value8 >> 2 < value8) {
        r->a = RAM16(0x00A9 + value);
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x57DB, 0xC20941); GUARD_JSR(c, sp_call, 0x57DB); } /* derive_eight_way_direction_to_low_byte_target */
        uint16_t a_all5 = r->a;
        RAM16_SET(0x00AB + RAM16(0x0287), a_all5);
        uint16_t value11 = BUS16(c, 0xC2580D + (uint16_t)(a_all5 << 1));
        uint16_t value12 = RAM16(0x0287);
        RAM16_SET(0x0200, value11);
        uint16_t value13 = RAM16(0x009A + value12);
        uint8_t a_hi4;
        if ((value11 & 0x0F) + 0x18 == value13) {
            a_hi4 = 0;
        } else {
            r->a = (value11 & 0x0F) + 0x18;
            r->x = value12;
            r->c = (value11 & 0x0F) + 0x18 >= value13;
            r->v = (((value11 & 0x0F) ^ (value11 & 0x0F) + 0x18) & ((value11 & 0x0F) + 0x18 ^ 0x18) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x57F9, 0xC21394); GUARD_JSR(c, sp_call, 0x57F9); } /* select_boss_animation_and_reset_frame_cursor */
            RAM16_SET(0x0202, RAM16(0x0098 + value12) & 0xFF3F);
            uint16_t value15 = RAM16(0x0201);
            uint16_t value16 = RAM16(0x0202);
            RAM16_SET(0x0098 + value12, (value15 & 0xC0) | value16);
            a_hi4 = ((value15 & 0xC0) | value16) >> 8;
        }
        r->a = (a_hi4 << 8) | (uint8_t)a;
        r->x = value12;
        r->c = (value11 & 0x0F) + 0x18 >= value13;
        r->v = (((value11 & 0x0F) ^ (value11 & 0x0F) + 0x18) & ((value11 & 0x0F) + 0x18 ^ 0x18) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value17 = RAM16(0x009A + value);
    uint8_t a_hi5;
    if (value17 == 0x18) {
        a_hi5 = 0;
    } else {
        r->a = 0x18;
        r->x = value;
        r->c = value17 <= 0x18;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x57CF, 0xC21394); GUARD_JSR(c, sp_call, 0x57CF); } /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all7 = r->a;
        a_hi5 = a_all7 >> 8;
    }
    r->a = (a_hi5 << 8) | (uint8_t)a;
    r->x = value;
    r->c = value17 <= 0x18;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2579E, SOM_RTS, "gen", select_boss_nearest_target_animation_with_status_timer_guards, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 111, 46)
