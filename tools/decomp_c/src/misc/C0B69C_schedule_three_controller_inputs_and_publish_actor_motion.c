#include "som_c.h"

/* C0B69C schedule_three_controller_inputs_and_publish_actor_motion   [class B, 116 bytes, 59 instructions]
 * Source: src/rom/schedule_three_controller_inputs_and_publish_actor_motion.s
 * Documented in docs/hero-controller-schedule.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void schedule_three_controller_inputs_and_publish_actor_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x00F1);
    if (value & 0x40) {
        RAM16_SET(0x0042, 0);
        RAM16_SET(0x0044, 0);
        RAM16_SET(0x0046, 0);
        RAM8(0x00CC) = 0;
        RAM8(0x00CD) = 0;
        RAM8(0x00CE) = 0;
        r->v = value & 0x40;
        RETURN_RTS(c);
    }
    if (value & 0x80) {
        r->v = value & 0x40;
        RETURN_RTS(c);
    }
    uint8_t value2 = RAM8(0x00FF);
    uint8_t value3 = RAM8(0x0052);
    if ((value2 | value3) != 0) {
        RAM16_SET(0x0042, 0);
        RAM16_SET(0x0044, 0);
        RAM16_SET(0x0046, 0);
        RAM8(0x00CC) = 0;
        RAM8(0x00CD) = 0;
        RAM8(0x00CE) = 0;
        SET_A8(r, value2 | value3);
        r->v = value & 0x40;
        RETURN_RTS(c);
    }
    uint8_t value4 = RAM8(0x00E2);
    if ((value4 & 1) != 0) {
        RAM16_SET(0x0042, 0);
        RAM16_SET(0x0044, 0);
        RAM16_SET(0x0046, 0);
        RAM8(0x00CC) = 0;
        RAM8(0x00CD) = 0;
        RAM8(0x00CE) = 0;
        SET_A8(r, value4 & 1);
        r->v = value & 0x40;
        RETURN_RTS(c);
    }
    uint8_t value5 = RAM8(0x00E8);
    if ((value5 & 4) == 0) {
        r->a = a_hi << 8 | (value5 & 4);
        r->v = value & 0x40;
        JSR(c, 0xB6C9, 0xC0B799); /* schedule_controller_interaction_charge_and_deferred_attacks */
        uint16_t a_all = r->a;
        uint8_t x_ret = r->x;
        uint8_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        RAM8(0x0012) = RAM8(0x0042);
        RAM8(0x0010) = RAM8(0x0043);
        uint8_t value8 = RAM8(0x00D9);
        bool x_flag2;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool carry2;
        bool overflow2;
        if (value8 == 0) {
            x_flag2 = 1;
            a_hi2 = a_all >> 8;
            x2 = x_ret;
            y2 = y_ret;
            carry2 = carry_ret;
            overflow2 = overflow_ret;
        } else {
            bool x_flag;
            uint8_t a_hi1;
            uint16_t x1;
            uint16_t y1;
            bool carry1;
            bool overflow1;
            if (value8 & 0x80) {
                x_flag = 1;
                a_hi1 = a_all >> 8;
                x1 = x_ret;
                y1 = y_ret;
                carry1 = carry_ret;
                overflow1 = overflow_ret;
            } else {
                RAM8(0x0011) = value8;
                r->a = (a_all >> 8 << 8) | value8;
                r->mf = 1;
                r->xf = 1;
                r->db = 0x7E;
                r->sp -= 1;
                JSR(c, 0xB6E3, 0xC0B710); /* produce_hero_signed_velocity_pose_and_energy_from_controller */
                r->sp += 1;
                uint16_t a_all2 = r->a;
                uint16_t x_ret2 = r->x;
                uint16_t y_ret2 = r->y;
                bool carry_ret2 = r->c;
                bool overflow_ret2 = r->v;
                x_flag = 0;
                a_hi1 = a_all2 >> 8;
                x1 = x_ret2;
                y1 = y_ret2;
                carry1 = carry_ret2;
                overflow1 = overflow_ret2;
            }
            x_flag2 = x_flag;
            a_hi2 = a_hi1;
            x2 = x1;
            y2 = y1;
            carry2 = carry1;
            overflow2 = overflow1;
        }
        r->mf = 1; /* sep #$30 */
        r->xf = 1;
        RAM8(0x0012) = RAM8(0x0044);
        RAM8(0x0010) = RAM8(0x0045);
        uint8_t value11 = RAM8(0x00DA);
        bool x_flag4;
        uint8_t a_hi4;
        uint16_t x4;
        uint16_t y4;
        bool carry4;
        bool overflow4;
        if (value11 == 0) {
            x_flag4 = 1;
            a_hi4 = a_hi2;
            x4 = (uint8_t)x2;
            y4 = (uint8_t)y2;
            carry4 = carry2;
            overflow4 = overflow2;
        } else {
            bool x_flag3;
            uint8_t a_hi3;
            uint16_t x3;
            uint16_t y3;
            bool carry3;
            bool overflow3;
            if (value11 & 0x80) {
                x_flag3 = 1;
                a_hi3 = a_hi2;
                x3 = (uint8_t)x2;
                y3 = (uint8_t)y2;
                carry3 = carry2;
                overflow3 = overflow2;
            } else {
                RAM8(0x0011) = value11;
                r->a = (a_hi2 << 8) | value11;
                r->mf = 1;
                r->xf = 1;
                r->db = 0x7E;
                r->sp -= 1;
                JSR(c, 0xB6F8, 0xC0B710); /* produce_hero_signed_velocity_pose_and_energy_from_controller */
                r->sp += 1;
                uint16_t a_all3 = r->a;
                uint16_t x_ret3 = r->x;
                uint16_t y_ret3 = r->y;
                bool carry_ret3 = r->c;
                bool overflow_ret3 = r->v;
                x_flag3 = 0;
                a_hi3 = a_all3 >> 8;
                x3 = x_ret3;
                y3 = y_ret3;
                carry3 = carry_ret3;
                overflow3 = overflow_ret3;
            }
            x_flag4 = x_flag3;
            a_hi4 = a_hi3;
            x4 = x3;
            y4 = y3;
            carry4 = carry3;
            overflow4 = overflow3;
        }
        r->mf = 1; /* sep #$30 */
        r->xf = 1;
        RAM8(0x0012) = RAM8(0x0046);
        RAM8(0x0010) = RAM8(0x0047);
        uint8_t value14 = RAM8(0x00DB);
        bool x_flag6;
        uint8_t a2;
        uint8_t a_hi6;
        uint16_t x6;
        uint16_t y6;
        bool carry6;
        bool overflow6;
        if (value14 == 0) {
            x_flag6 = 1;
            a2 = value14;
            a_hi6 = a_hi4;
            x6 = (uint8_t)x4;
            y6 = (uint8_t)y4;
            carry6 = carry4;
            overflow6 = overflow4;
        } else {
            bool x_flag5;
            uint8_t a1;
            uint8_t a_hi5;
            uint16_t x5;
            uint16_t y5;
            bool carry5;
            bool overflow5;
            if (value14 & 0x80) {
                x_flag5 = 1;
                a1 = value14;
                a_hi5 = a_hi4;
                x5 = (uint8_t)x4;
                y5 = (uint8_t)y4;
                carry5 = carry4;
                overflow5 = overflow4;
            } else {
                RAM8(0x0011) = value14;
                r->a = (a_hi4 << 8) | value14;
                r->mf = 1;
                r->xf = 1;
                r->db = 0x7E;
                r->sp -= 1;
                JSR(c, 0xB70D, 0xC0B710); /* produce_hero_signed_velocity_pose_and_energy_from_controller */
                r->sp += 1;
                uint16_t a_all4 = r->a;
                uint16_t x_ret4 = r->x;
                uint16_t y_ret4 = r->y;
                bool carry_ret4 = r->c;
                bool overflow_ret4 = r->v;
                x_flag5 = 0;
                a1 = (uint8_t)a_all4;
                a_hi5 = a_all4 >> 8;
                x5 = x_ret4;
                y5 = y_ret4;
                carry5 = carry_ret4;
                overflow5 = overflow_ret4;
            }
            x_flag6 = x_flag5;
            a2 = a1;
            a_hi6 = a_hi5;
            x6 = x5;
            y6 = y5;
            carry6 = carry5;
            overflow6 = overflow5;
        }
        r->a = (a_hi6 << 8) | a2;
        r->x = x6;
        r->y = y6;
        r->c = carry6;
        r->v = overflow6;
        r->xf = x_flag6;
        r->db = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0042, 0);
    RAM16_SET(0x0044, 0);
    RAM16_SET(0x0046, 0);
    RAM8(0x00CC) = 0;
    RAM8(0x00CD) = 0;
    RAM8(0x00CE) = 0;
    SET_A8(r, value5 & 4);
    r->v = value & 0x40;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0B69C, SOM_RTS, "hand", schedule_three_controller_inputs_and_publish_actor_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 116, 59)
