#include "som_c.h"

/* C2630F choose_descriptor_three_action_or_status_abort   [class B, 155 bytes, 72 instructions]
 * Source: src/rom/choose_descriptor_three_action_or_status_abort.s
 * Documented in docs/boss-descriptor-three.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_three_action_or_status_abort(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM16_SET(0x007E + RAM16(0x0287), RAM16(0x02C7));
    { const uint16_t sp_call = r->sp; JSR(c, 0x6318, 0xC23224); GUARD_JSR(c, sp_call, 0x6318); } /* select_nearest_active_living_party_actor */
    uint16_t a_all = r->a;
    RAM16_SET(0x00A9 + RAM16(0x0287), a_all);
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6320, 0xC2091D); GUARD_JSR(c, sp_call, 0x6320); } /* derive_four_way_direction_to_low_byte_target */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x00AB + x_ret2, a_all2);
    if (a_all2 != 1) {
        r->a = 2;
        r->c = a_all2 >= 1;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6346, 0xC2300B); GUARD_JSR(c, sp_call, 0x6346); } /* draw_boss_frame_random_number */
        bool zero_ret3 = r->z;
        if (!zero_ret3) {
            uint16_t value4 = RAM16(0x0287);
            uint16_t value5 = RAM16(0x0042 + value4);
            if (value5 != 0) {
                if (value5 == 2) {
                    r->a = 2;
                    r->x = value4;
                    r->c = value5 >= 2;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x6383, 0xC2300B); GUARD_JSR(c, sp_call, 0x6383); } /* draw_boss_frame_random_number */
                    uint16_t a_all4 = r->a;
                    uint16_t value6 = BUS16(c, 0xDCE2B1 + (uint16_t)(a_all4 << 1));
                    if (value6 != 0xDFD4) {
                        r->a = value6;
                        r->x = (uint16_t)(a_all4 << 1);
                        r->c = 0;
                        r->z = value6 == 0xDFD4;
                        r->n = (uint16_t)(value6 - 0xDFD4) & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    uint16_t value7 = RAM16(0x0287);
                    uint16_t value8 = RAM16(0x00A9 + value7);
                    uint16_t value9 = RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)value8 << 8) | (value8 >> 8)) << 1) + 0xE000));
                    if (value9 != 0) {
                        RAM16_SET(0x007E + value7, 0);
                        r->a = value9;
                        r->x = value7;
                        r->y = (uint16_t)((uint16_t)((((uint8_t)value8 << 8) | (value8 >> 8)) << 1) + 0xE000);
                        r->c = 1;
                        r->z = value9 == 0;
                        r->n = value9 & 0x8000;
                        r->v = (((uint16_t)((((uint8_t)value8 << 8) | (value8 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value8 << 8) | (value8 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value8 << 8) | (value8 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    r->a = 0xDFD4;
                    r->x = value7;
                    r->y = (uint16_t)((uint16_t)((((uint8_t)value8 << 8) | (value8 >> 8)) << 1) + 0xE000);
                    r->c = 0;
                    r->z = 0;
                    r->n = 1;
                    r->v = (((uint16_t)((((uint8_t)value8 << 8) | (value8 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value8 << 8) | (value8 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value8 << 8) | (value8 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 1;
                r->x = value4;
                r->c = value5 >= 2;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x6375, 0xC2300B); GUARD_JSR(c, sp_call, 0x6375); } /* draw_boss_frame_random_number */
                uint16_t a_all5 = r->a;
                uint16_t value10 = BUS16(c, 0xDCE2AD + (uint16_t)(a_all5 << 1));
                r->a = value10;
                r->x = (uint16_t)(a_all5 << 1);
                r->c = 0;
                r->z = value10 == 0;
                r->n = value10 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 1;
            r->x = value4;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x6362, 0xC2300B); GUARD_JSR(c, sp_call, 0x6362); } /* draw_boss_frame_random_number */
            uint16_t a_all6 = r->a;
            uint16_t value11 = BUS16(c, 0xDCE2A9 + (uint16_t)(a_all6 << 1));
            r->a = value11;
            r->x = (uint16_t)(a_all6 << 1);
            r->c = 0;
            r->z = value11 == 0;
            r->n = value11 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value13 = RAM16(0x0042 + RAM16(0x0287));
        uint16_t value14 = BUS16(c, 0xDCE2B7 + (uint16_t)(value13 << 1));
        r->a = value14;
        r->x = (uint16_t)(value13 << 1);
        r->c = 0;
        r->z = value14 == 0;
        r->n = value14 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = RAM16(0x00A9 + x_ret2);
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x632E, 0xC208BC); GUARD_JSR(c, sp_call, 0x632E); } /* derive_clamped_target_distance_minus_one */
    uint16_t a_all7 = r->a;
    if (a_all7 >= 3) {
        r->a = 2;
        r->c = a_all7 >= 3;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6346, 0xC2300B); GUARD_JSR(c, sp_call, 0x6346); } /* draw_boss_frame_random_number */
        bool zero_ret8 = r->z;
        if (!zero_ret8) {
            uint16_t value16 = RAM16(0x0287);
            uint16_t value17 = RAM16(0x0042 + value16);
            if (value17 != 0) {
                if (value17 == 2) {
                    r->a = 2;
                    r->x = value16;
                    r->c = value17 >= 2;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x6383, 0xC2300B); GUARD_JSR(c, sp_call, 0x6383); } /* draw_boss_frame_random_number */
                    uint16_t a_all9 = r->a;
                    uint16_t value18 = BUS16(c, 0xDCE2B1 + (uint16_t)(a_all9 << 1));
                    if (value18 != 0xDFD4) {
                        r->a = value18;
                        r->x = (uint16_t)(a_all9 << 1);
                        r->c = 0;
                        r->z = value18 == 0xDFD4;
                        r->n = (uint16_t)(value18 - 0xDFD4) & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    uint16_t value19 = RAM16(0x0287);
                    uint16_t value20 = RAM16(0x00A9 + value19);
                    uint16_t value21 = RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)value20 << 8) | (value20 >> 8)) << 1) + 0xE000));
                    if (value21 != 0) {
                        RAM16_SET(0x007E + value19, 0);
                        r->a = value21;
                        r->x = value19;
                        r->y = (uint16_t)((uint16_t)((((uint8_t)value20 << 8) | (value20 >> 8)) << 1) + 0xE000);
                        r->c = 1;
                        r->z = value21 == 0;
                        r->n = value21 & 0x8000;
                        r->v = (((uint16_t)((((uint8_t)value20 << 8) | (value20 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value20 << 8) | (value20 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value20 << 8) | (value20 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    r->a = 0xDFD4;
                    r->x = value19;
                    r->y = (uint16_t)((uint16_t)((((uint8_t)value20 << 8) | (value20 >> 8)) << 1) + 0xE000);
                    r->c = 0;
                    r->z = 0;
                    r->n = 1;
                    r->v = (((uint16_t)((((uint8_t)value20 << 8) | (value20 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value20 << 8) | (value20 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value20 << 8) | (value20 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 1;
                r->x = value16;
                r->c = value17 >= 2;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x6375, 0xC2300B); GUARD_JSR(c, sp_call, 0x6375); } /* draw_boss_frame_random_number */
                uint16_t a_all10 = r->a;
                uint16_t value22 = BUS16(c, 0xDCE2AD + (uint16_t)(a_all10 << 1));
                r->a = value22;
                r->x = (uint16_t)(a_all10 << 1);
                r->c = 0;
                r->z = value22 == 0;
                r->n = value22 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 1;
            r->x = value16;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x6362, 0xC2300B); GUARD_JSR(c, sp_call, 0x6362); } /* draw_boss_frame_random_number */
            uint16_t a_all11 = r->a;
            uint16_t value23 = BUS16(c, 0xDCE2A9 + (uint16_t)(a_all11 << 1));
            r->a = value23;
            r->x = (uint16_t)(a_all11 << 1);
            r->c = 0;
            r->z = value23 == 0;
            r->n = value23 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value25 = RAM16(0x0042 + RAM16(0x0287));
        uint16_t value26 = BUS16(c, 0xDCE2B7 + (uint16_t)(value25 << 1));
        r->a = value26;
        r->x = (uint16_t)(value25 << 1);
        r->c = 0;
        r->z = value26 == 0;
        r->n = value26 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value28 = RAM16(0x0042 + RAM16(0x0287));
    uint16_t value29 = BUS16(c, 0xDCE2BD + (uint16_t)(value28 << 1));
    r->a = value29;
    r->x = (uint16_t)(value28 << 1);
    r->c = 0;
    r->z = value29 == 0;
    r->n = value29 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2630F, SOM_RTS, "gen", choose_descriptor_three_action_or_status_abort, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 155, 72)
