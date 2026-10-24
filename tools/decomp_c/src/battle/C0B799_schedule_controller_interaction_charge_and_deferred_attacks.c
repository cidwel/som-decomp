#include "som_c.h"

/* C0B799 schedule_controller_interaction_charge_and_deferred_attacks   [class C, 184 bytes, 80 instructions]
 * Source: src/rom/schedule_controller_interaction_charge_and_deferred_attacks.s
 * Documented in docs/hero-controller-schedule.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void schedule_controller_interaction_charge_and_deferred_attacks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const bool carry = r->c;
    const bool overflow = r->v;
    JSL(c, 0xB79C, 0xC2B665); /* gate_all_three_controller_inputs_and_start_native_running */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    if (RAM8(0x00F1) == 0) {
        r->mf = 1; /* sep #$30 */
        r->xf = 1;
        x_ret &= 0xFF; /* SEP #$10 clears the index high bytes */
        y_ret &= 0xFF;
        uint8_t value2 = RAM8(0x00D9);
        uint8_t a_hi5;
        uint16_t x5;
        uint16_t y5;
        bool carry5;
        bool overflow5;
        if (value2 == 0) {
            a_hi5 = a_all >> 8;
            x5 = x_ret;
            y5 = y_ret;
            carry5 = carry;
            overflow5 = overflow;
        } else {
            uint8_t a_hi4;
            uint16_t x4;
            uint16_t y4;
            bool carry4;
            bool overflow4;
            if (value2 & 0x80) {
                a_hi4 = a_all >> 8;
                x4 = x_ret;
                y4 = y_ret;
                carry4 = carry;
                overflow4 = overflow;
            } else {
                uint8_t value3 = RAM8(0x00CC);
                RAM8(0x00CC) &= 0xF7;
                uint8_t a_hi3;
                uint16_t x3;
                uint16_t y3;
                bool carry3;
                bool overflow3;
                if ((value3 & 8) == 0) {
                    uint8_t value4 = RAM8(0x00ED);
                    uint8_t a_hi2;
                    uint16_t x2;
                    uint16_t y2;
                    bool carry2;
                    bool overflow2;
                    if (!(value4 & 0x80)) {
                        a_hi2 = a_all >> 8;
                        x2 = x_ret;
                        y2 = y_ret;
                        carry2 = carry;
                        overflow2 = value4 & 0x40;
                    } else {
                        uint8_t value5 = RAM8(0x0043);
                        uint8_t a_hi1;
                        uint16_t x1;
                        uint16_t y1;
                        bool carry1;
                        bool overflow1;
                        if (!(value5 & 0x80)) {
                            r->a = (a_all >> 8 << 8) | value2;
                            r->y = y_ret;
                            r->v = value5 & 0x40;
                            r->mf = 1;
                            r->xf = 1;
                            JSR(c, 0xB7C8, 0xC0B21C); /* consume_controller_selected_deferred_attack_or_begin_attack */
                            uint16_t a_all2 = r->a;
                            uint16_t x_ret2 = r->x;
                            uint16_t y_ret2 = r->y;
                            bool carry_ret = r->c;
                            bool overflow_ret = r->v;
                            a_hi1 = a_all2 >> 8;
                            x1 = x_ret2;
                            y1 = y_ret2;
                            carry1 = carry_ret;
                            overflow1 = overflow_ret;
                        } else {
                            r->a = (a_all >> 8 << 8) | value2;
                            r->v = value5 & 0x40;
                            r->mf = 1;
                            r->xf = 1;
                            JSR(c, 0xB7C3, 0xC0B330); /* advance_selected_hero_charge_timing_and_publish_native_gauge */
                            uint16_t a_all3 = r->a;
                            uint16_t x_ret3 = r->x;
                            uint16_t y_ret3 = r->y;
                            bool carry_ret2 = r->c;
                            bool overflow_ret2 = r->v;
                            a_hi1 = a_all3 >> 8;
                            x1 = x_ret3;
                            y1 = y_ret3;
                            carry1 = carry_ret2;
                            overflow1 = overflow_ret2;
                        }
                        a_hi2 = a_hi1;
                        x2 = x1;
                        y2 = y1;
                        carry2 = carry1;
                        overflow2 = overflow1;
                    }
                    a_hi3 = a_hi2;
                    x3 = x2;
                    y3 = y2;
                    carry3 = carry2;
                    overflow3 = overflow2;
                } else {
                    r->a = (a_all >> 8 << 8) | value2;
                    r->y = y_ret;
                    r->mf = 1;
                    r->xf = 1;
                    JSR(c, 0xB7B4, 0xC0B851); /* scan_controller_actor_contacts_and_dispatch_interaction_or_attack */
                    uint16_t a_all4 = r->a;
                    uint16_t x_ret4 = r->x;
                    uint16_t y_ret4 = r->y;
                    bool carry_ret3 = r->c;
                    bool overflow_ret3 = r->v;
                    a_hi3 = a_all4 >> 8;
                    x3 = x_ret4;
                    y3 = y_ret4;
                    carry3 = carry_ret3;
                    overflow3 = overflow_ret3;
                }
                a_hi4 = a_hi3;
                x4 = x3;
                y4 = y3;
                carry4 = carry3;
                overflow4 = overflow3;
            }
            a_hi5 = a_hi4;
            x5 = x4;
            y5 = y4;
            carry5 = carry4;
            overflow5 = overflow4;
        }
        r->mf = 1; /* sep #$30 */
        r->xf = 1;
        x5 &= 0xFF; /* SEP #$10 clears the index high bytes */
        y5 &= 0xFF;
        uint8_t value6 = RAM8(0x00DA);
        uint8_t a_hi10;
        uint16_t x10;
        uint16_t y10;
        bool carry10;
        bool overflow10;
        if (value6 == 0) {
            a_hi10 = a_hi5;
            x10 = x5;
            y10 = y5;
            carry10 = carry5;
            overflow10 = overflow5;
        } else {
            uint8_t a_hi9;
            uint16_t x9;
            uint16_t y9;
            bool carry9;
            bool overflow9;
            if (value6 & 0x80) {
                a_hi9 = a_hi5;
                x9 = x5;
                y9 = y5;
                carry9 = carry5;
                overflow9 = overflow5;
            } else {
                uint8_t value7 = RAM8(0x00CD);
                RAM8(0x00CD) &= 0xF7;
                uint8_t a_hi8;
                uint16_t x8;
                uint16_t y8;
                bool carry8;
                bool overflow8;
                if ((value7 & 8) == 0) {
                    uint8_t value8 = RAM8(0x00ED);
                    uint8_t a_hi7;
                    uint16_t x7;
                    uint16_t y7;
                    bool carry7;
                    bool overflow7;
                    if (!(value8 & 0x80)) {
                        a_hi7 = a_hi5;
                        x7 = x5;
                        y7 = y5;
                        carry7 = carry5;
                        overflow7 = value8 & 0x40;
                    } else {
                        uint8_t value9 = RAM8(0x0045);
                        uint8_t a_hi6;
                        uint16_t x6;
                        uint16_t y6;
                        bool carry6;
                        bool overflow6;
                        if (!(value9 & 0x80)) {
                            r->a = (a_hi5 << 8) | value6;
                            r->y = y5;
                            r->v = value9 & 0x40;
                            r->mf = 1;
                            r->xf = 1;
                            JSR(c, 0xB7EF, 0xC0B21C); /* consume_controller_selected_deferred_attack_or_begin_attack */
                            uint16_t a_all5 = r->a;
                            uint16_t x_ret5 = r->x;
                            uint16_t y_ret5 = r->y;
                            bool carry_ret4 = r->c;
                            bool overflow_ret4 = r->v;
                            a_hi6 = a_all5 >> 8;
                            x6 = x_ret5;
                            y6 = y_ret5;
                            carry6 = carry_ret4;
                            overflow6 = overflow_ret4;
                        } else {
                            r->a = (a_hi5 << 8) | value6;
                            r->v = value9 & 0x40;
                            r->mf = 1;
                            r->xf = 1;
                            JSR(c, 0xB7EA, 0xC0B330); /* advance_selected_hero_charge_timing_and_publish_native_gauge */
                            uint16_t a_all6 = r->a;
                            uint16_t x_ret6 = r->x;
                            uint16_t y_ret6 = r->y;
                            bool carry_ret5 = r->c;
                            bool overflow_ret5 = r->v;
                            a_hi6 = a_all6 >> 8;
                            x6 = x_ret6;
                            y6 = y_ret6;
                            carry6 = carry_ret5;
                            overflow6 = overflow_ret5;
                        }
                        a_hi7 = a_hi6;
                        x7 = x6;
                        y7 = y6;
                        carry7 = carry6;
                        overflow7 = overflow6;
                    }
                    a_hi8 = a_hi7;
                    x8 = x7;
                    y8 = y7;
                    carry8 = carry7;
                    overflow8 = overflow7;
                } else {
                    r->a = (a_hi5 << 8) | value6;
                    r->y = y5;
                    r->v = overflow5;
                    r->mf = 1;
                    r->xf = 1;
                    JSR(c, 0xB7DB, 0xC0B851); /* scan_controller_actor_contacts_and_dispatch_interaction_or_attack */
                    uint16_t a_all7 = r->a;
                    uint16_t x_ret7 = r->x;
                    uint16_t y_ret7 = r->y;
                    bool carry_ret6 = r->c;
                    bool overflow_ret6 = r->v;
                    a_hi8 = a_all7 >> 8;
                    x8 = x_ret7;
                    y8 = y_ret7;
                    carry8 = carry_ret6;
                    overflow8 = overflow_ret6;
                }
                a_hi9 = a_hi8;
                x9 = x8;
                y9 = y8;
                carry9 = carry8;
                overflow9 = overflow8;
            }
            a_hi10 = a_hi9;
            x10 = x9;
            y10 = y9;
            carry10 = carry9;
            overflow10 = overflow9;
        }
        r->mf = 1; /* sep #$30 */
        r->xf = 1;
        x10 &= 0xFF; /* SEP #$10 clears the index high bytes */
        y10 &= 0xFF;
        uint8_t value10 = RAM8(0x00DB);
        uint8_t a5;
        uint8_t a_hi15;
        uint16_t x15;
        uint16_t y15;
        bool carry15;
        if (value10 == 0) {
            a5 = value10;
            a_hi15 = a_hi10;
            x15 = x10;
            y15 = y10;
            carry15 = carry10;
        } else {
            uint8_t a4;
            uint8_t a_hi14;
            uint16_t x14;
            uint16_t y14;
            bool carry14;
            if (value10 & 0x80) {
                a4 = value10;
                a_hi14 = a_hi10;
                x14 = x10;
                y14 = y10;
                carry14 = carry10;
            } else {
                uint8_t value11 = RAM8(0x00CE);
                RAM8(0x00CE) &= 0xF7;
                uint8_t a3;
                uint8_t a_hi13;
                uint16_t x13;
                uint16_t y13;
                bool carry13;
                if ((value11 & 8) == 0) {
                    uint8_t value12 = RAM8(0x00ED);
                    uint8_t a2;
                    uint8_t a_hi12;
                    uint16_t x12;
                    uint16_t y12;
                    bool carry12;
                    if (!(value12 & 0x80)) {
                        a2 = 8;
                        a_hi12 = a_hi10;
                        x12 = x10;
                        y12 = y10;
                        carry12 = carry10;
                    } else {
                        uint8_t value13 = RAM8(0x0047);
                        uint8_t a1;
                        uint8_t a_hi11;
                        uint16_t x11;
                        uint16_t y11;
                        bool carry11;
                        if (!(value13 & 0x80)) {
                            r->a = (a_hi10 << 8) | value10;
                            r->y = y10;
                            r->v = value13 & 0x40;
                            r->mf = 1;
                            r->xf = 1;
                            JSR(c, 0xB816, 0xC0B21C); /* consume_controller_selected_deferred_attack_or_begin_attack */
                            uint16_t a_all8 = r->a;
                            uint16_t x_ret8 = r->x;
                            uint16_t y_ret8 = r->y;
                            bool carry_ret7 = r->c;
                            a1 = (uint8_t)a_all8;
                            a_hi11 = a_all8 >> 8;
                            x11 = x_ret8;
                            y11 = y_ret8;
                            carry11 = carry_ret7;
                        } else {
                            r->a = (a_hi10 << 8) | value10;
                            r->v = value13 & 0x40;
                            r->mf = 1;
                            r->xf = 1;
                            JSR(c, 0xB811, 0xC0B330); /* advance_selected_hero_charge_timing_and_publish_native_gauge */
                            uint16_t a_all9 = r->a;
                            uint16_t x_ret9 = r->x;
                            uint16_t y_ret9 = r->y;
                            bool carry_ret8 = r->c;
                            a1 = (uint8_t)a_all9;
                            a_hi11 = a_all9 >> 8;
                            x11 = x_ret9;
                            y11 = y_ret9;
                            carry11 = carry_ret8;
                        }
                        a2 = a1;
                        a_hi12 = a_hi11;
                        x12 = x11;
                        y12 = y11;
                        carry12 = carry11;
                    }
                    a3 = a2;
                    a_hi13 = a_hi12;
                    x13 = x12;
                    y13 = y12;
                    carry13 = carry12;
                } else {
                    r->a = (a_hi10 << 8) | value10;
                    r->y = y10;
                    r->v = overflow10;
                    r->mf = 1;
                    r->xf = 1;
                    JSR(c, 0xB802, 0xC0B851); /* scan_controller_actor_contacts_and_dispatch_interaction_or_attack */
                    uint16_t a_all10 = r->a;
                    uint16_t x_ret10 = r->x;
                    uint16_t y_ret10 = r->y;
                    bool carry_ret9 = r->c;
                    a3 = (uint8_t)a_all10;
                    a_hi13 = a_all10 >> 8;
                    x13 = x_ret10;
                    y13 = y_ret10;
                    carry13 = carry_ret9;
                }
                a4 = a3;
                a_hi14 = a_hi13;
                x14 = x13;
                y14 = y13;
                carry14 = carry13;
            }
            a5 = a4;
            a_hi15 = a_hi14;
            x15 = x14;
            y15 = y14;
            carry15 = carry14;
        }
        r->mf = 1; /* sep #$20 */
        uint8_t value14 = RAM8(0x00ED);
        uint8_t a_hi22;
        uint16_t x22;
        uint16_t y22;
        bool carry22;
        bool overflow17;
        if (!(value14 & 0x80)) {
            a_hi22 = a_hi15;
            x22 = x15;
            y22 = y15;
            carry22 = carry15;
            overflow17 = value14 & 0x40;
        } else {
            uint8_t value15 = RAM8(0xE02C);
            uint8_t a_hi17;
            uint16_t x17;
            uint16_t y17;
            bool carry17;
            bool overflow12;
            if (value15 != 0) {
                a_hi17 = a_hi15;
                x17 = x15;
                y17 = y15;
                carry17 = carry15;
                overflow12 = value14 & 0x40;
            } else {
                uint8_t value16 = RAM8(0xE085);
                uint8_t a_hi16;
                uint16_t x16;
                uint16_t y16;
                bool carry16;
                bool overflow11;
                if (value16 == 0) {
                    a_hi16 = a_hi15;
                    x16 = x15;
                    y16 = y15;
                    carry16 = carry15;
                    overflow11 = value14 & 0x40;
                } else {
                    r->a = (a_hi15 << 8) | 1;
                    r->x = x15;
                    r->y = y15;
                    r->c = carry15;
                    r->v = value14 & 0x40;
                    r->mf = 1;
                    r->xf = 1;
                    JSR(c, 0xB82D, 0xC0B32A); /* advance_hero_charge_input_and_restore_byte_accumulator */
                    uint16_t a_all11 = r->a;
                    uint16_t x_ret11 = r->x;
                    uint16_t y_ret11 = r->y;
                    bool carry_ret10 = r->c;
                    bool overflow_ret10 = r->v;
                    a_hi16 = a_all11 >> 8;
                    x16 = x_ret11;
                    y16 = y_ret11;
                    carry16 = carry_ret10;
                    overflow11 = overflow_ret10;
                }
                a_hi17 = a_hi16;
                x17 = x16;
                y17 = y16;
                carry17 = carry16;
                overflow12 = overflow11;
            }
            uint8_t value17 = RAM8(0xE22C);
            uint8_t a_hi19;
            uint16_t x19;
            uint16_t y19;
            bool carry19;
            bool overflow14;
            if (value17 != 0) {
                a_hi19 = a_hi17;
                x19 = x17;
                y19 = y17;
                carry19 = carry17;
                overflow14 = overflow12;
            } else {
                uint8_t value18 = RAM8(0xE285);
                uint8_t a_hi18;
                uint16_t x18;
                uint16_t y18;
                bool carry18;
                bool overflow13;
                if (value18 == 0) {
                    a_hi18 = a_hi17;
                    x18 = x17;
                    y18 = y17;
                    carry18 = carry17;
                    overflow13 = overflow12;
                } else {
                    r->a = (a_hi17 << 8) | 2;
                    r->x = x17;
                    r->y = y17;
                    r->c = carry17;
                    r->v = overflow12;
                    r->mf = 1;
                    r->xf = 1;
                    JSR(c, 0xB83E, 0xC0B32A); /* advance_hero_charge_input_and_restore_byte_accumulator */
                    uint16_t a_all12 = r->a;
                    uint16_t x_ret12 = r->x;
                    uint16_t y_ret12 = r->y;
                    bool carry_ret11 = r->c;
                    bool overflow_ret11 = r->v;
                    a_hi18 = a_all12 >> 8;
                    x18 = x_ret12;
                    y18 = y_ret12;
                    carry18 = carry_ret11;
                    overflow13 = overflow_ret11;
                }
                a_hi19 = a_hi18;
                x19 = x18;
                y19 = y18;
                carry19 = carry18;
                overflow14 = overflow13;
            }
            uint8_t value19 = RAM8(0xE42C);
            uint8_t a_hi21;
            uint16_t x21;
            uint16_t y21;
            bool carry21;
            bool overflow16;
            if (value19 != 0) {
                a_hi21 = a_hi19;
                x21 = x19;
                y21 = y19;
                carry21 = carry19;
                overflow16 = overflow14;
            } else {
                uint8_t value20 = RAM8(0xE485);
                uint8_t a_hi20;
                uint16_t x20;
                uint16_t y20;
                bool carry20;
                bool overflow15;
                if (value20 == 0) {
                    a_hi20 = a_hi19;
                    x20 = x19;
                    y20 = y19;
                    carry20 = carry19;
                    overflow15 = overflow14;
                } else {
                    r->a = (a_hi19 << 8) | 4;
                    r->x = x19;
                    r->y = y19;
                    r->c = carry19;
                    r->v = overflow14;
                    r->mf = 1;
                    r->xf = 1;
                    JSR(c, 0xB84F, 0xC0B32A); /* advance_hero_charge_input_and_restore_byte_accumulator */
                    uint16_t a_all13 = r->a;
                    uint16_t x_ret13 = r->x;
                    uint16_t y_ret13 = r->y;
                    bool carry_ret12 = r->c;
                    bool overflow_ret12 = r->v;
                    a_hi20 = a_all13 >> 8;
                    x20 = x_ret13;
                    y20 = y_ret13;
                    carry20 = carry_ret12;
                    overflow15 = overflow_ret12;
                }
                a_hi21 = a_hi20;
                x21 = x20;
                y21 = y20;
                carry21 = carry20;
                overflow16 = overflow15;
            }
            a_hi22 = a_hi21;
            x22 = x21;
            y22 = y21;
            carry22 = carry21;
            overflow17 = overflow16;
        }
        r->a = (a_hi22 << 8) | a;
        r->x = x22;
        r->y = y22;
        r->c = carry22;
        r->v = overflow17;
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0B799, SOM_RTS, "hand", schedule_controller_interaction_charge_and_deferred_attacks, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 184, 80)
