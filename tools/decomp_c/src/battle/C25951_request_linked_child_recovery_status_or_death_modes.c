#include "som_c.h"

/* C25951 request_linked_child_recovery_status_or_death_modes   [class B, 140 bytes, 55 instructions]
 * Source: src/rom/request_linked_child_recovery_status_or_death_modes.s
 * Documented in docs/boss-native-linked-parent-update.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void request_linked_child_recovery_status_or_death_modes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00BE + value);
    uint8_t a_hi12;
    if (value2 == 0) {
        r->a = value2;
        r->x = value;
        JSR(c, 0x59A8, 0xC20501); /* consume_boss_byte34_bit0_or_return_negative_status */
        uint16_t a_all = r->a;
        bool carry_ret = r->c;
        uint8_t a_hi1;
        if (!carry_ret) {
            a_hi1 = a_all >> 8;
        } else {
            uint16_t value3 = RAM16(0x0287);
            RAM16_SET(0x0081 + RAM16(0x00B0 + value3), 2);
            RAM16_SET(0x0081 + RAM16(0x00B2 + value3), 2);
            a_hi1 = 0;
        }
        a_hi12 = a_hi1;
    } else {
        uint16_t value6 = RAM16(0x0182 + value);
        uint8_t a_hi11;
        if (value2 < value6) {
            r->a = value2;
            r->x = value;
            JSR(c, 0x59A8, 0xC20501); /* consume_boss_byte34_bit0_or_return_negative_status */
            uint16_t a_all2 = r->a;
            bool carry_ret2 = r->c;
            uint8_t a_hi2;
            if (!carry_ret2) {
                a_hi2 = a_all2 >> 8;
            } else {
                uint16_t value7 = RAM16(0x0287);
                RAM16_SET(0x0081 + RAM16(0x00B0 + value7), 2);
                RAM16_SET(0x0081 + RAM16(0x00B2 + value7), 2);
                a_hi2 = 0;
            }
            a_hi11 = a_hi2;
        } else {
            r->x = value;
            JSR(c, 0x595F, 0xC25920); /* derive_boss_threshold_from_hardware_division_and_clamp */
            RAM16_SET(0x00BC + value, RAM16(0x00BA + value));
            uint16_t value11 = RAM16(0x0287);
            uint16_t value12 = RAM16(0x00A9 + value11);
            uint16_t value13 = RAM16(0x0002 + (((uint8_t)(value12 << 1) << 8) | ((uint16_t)(value12 << 1) >> 8)));
            uint16_t value14 = RAM16(0x002B + value11);
            uint8_t a_hi10;
            if (value13 < value14) {
                uint16_t value15 = RAM16(0x00B2 + value11);
                uint16_t value16 = RAM16(0x0083 + value15);
                uint8_t a_hi5;
                if (value16 & 0x8000) {
                    uint16_t value17 = RAM16(0x00B0 + value11);
                    uint16_t value18 = RAM16(0x0083 + value17);
                    uint8_t a_hi4;
                    if (value18 & 0x8000) {
                        r->a = value18;
                        r->x = value11;
                        r->y = value17;
                        r->mf = 0;
                        r->xf = 0;
                        JSR(c, 0x59A8, 0xC20501); /* consume_boss_byte34_bit0_or_return_negative_status */
                        uint16_t a_all4 = r->a;
                        bool carry_ret4 = r->c;
                        uint8_t a_hi3;
                        if (!carry_ret4) {
                            a_hi3 = a_all4 >> 8;
                        } else {
                            uint16_t value19 = RAM16(0x0287);
                            RAM16_SET(0x0081 + RAM16(0x00B0 + value19), 2);
                            RAM16_SET(0x0081 + RAM16(0x00B2 + value19), 2);
                            a_hi3 = 0;
                        }
                        a_hi4 = a_hi3;
                    } else {
                        RAM16_SET(0x0081 + value17, 6);
                        a_hi4 = 0;
                    }
                    a_hi5 = a_hi4;
                } else {
                    RAM16_SET(0x0081 + value15, 6);
                    a_hi5 = 0;
                }
                a_hi10 = a_hi5;
            } else {
                uint16_t value22 = RAM16(0x00B0 + value11);
                uint16_t value23 = RAM16(0x0083 + value22);
                uint8_t a_hi9;
                if (value23 & 0x8000) {
                    uint16_t value24 = RAM16(0x00B2 + value11);
                    uint16_t value25 = RAM16(0x0083 + value24);
                    uint8_t a_hi8;
                    if (value25 & 0x8000) {
                        uint8_t a_hi7;
                        if (value23 & 0x8000) {
                            r->a = value23;
                            r->x = value11;
                            r->y = value22;
                            r->mf = 0;
                            r->xf = 0;
                            JSR(c, 0x59A8, 0xC20501); /* consume_boss_byte34_bit0_or_return_negative_status */
                            uint16_t a_all5 = r->a;
                            bool carry_ret5 = r->c;
                            uint8_t a_hi6;
                            if (!carry_ret5) {
                                a_hi6 = a_all5 >> 8;
                            } else {
                                uint16_t value26 = RAM16(0x0287);
                                RAM16_SET(0x0081 + RAM16(0x00B0 + value26), 2);
                                RAM16_SET(0x0081 + RAM16(0x00B2 + value26), 2);
                                a_hi6 = 0;
                            }
                            a_hi7 = a_hi6;
                        } else {
                            RAM16_SET(0x0081 + value22, 6);
                            a_hi7 = 0;
                        }
                        a_hi8 = a_hi7;
                    } else {
                        RAM16_SET(0x0081 + value24, 6);
                        a_hi8 = 0;
                    }
                    a_hi9 = a_hi8;
                } else {
                    RAM16_SET(0x0081 + value22, 6);
                    a_hi9 = 0;
                }
                a_hi10 = a_hi9;
            }
            a_hi11 = a_hi10;
        }
        a_hi12 = a_hi11;
    }
    uint16_t value29 = RAM16(0x0287);
    if (RAM16(0x0190 + value29) & 0x8000) {
        RAM16_SET(0x0081 + RAM16(0x00B0 + value29), 4);
        RAM16_SET(0x0081 + RAM16(0x00B2 + value29), 4);
        RAM16_SET(0x008E + value29, 0x59DD);
        RAM16_SET(OBJECT_PHASE + value29, 0);
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25951, SOM_RTS, "gen", request_linked_child_recovery_status_or_death_modes, 0, 0, 1, 0, 0, 140, 55)
