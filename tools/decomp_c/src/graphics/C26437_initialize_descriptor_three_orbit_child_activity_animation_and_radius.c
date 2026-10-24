#include "som_c.h"

/* C26437 initialize_descriptor_three_orbit_child_activity_animation_and_radius   [class C, 102 bytes, 44 instructions]
 * Source: src/rom/initialize_descriptor_three_orbit_child_activity_animation_and_radius.s
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_three_orbit_child_activity_animation_and_radius(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0x94 + value);
    BUS16_RMW_SET(c, (db << 0x10) + 0x94 + value, (uint16_t)(value2 + 1));
    r->a = 0xC0;
    r->x = value;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6441, 0xC21394); GUARD_JSR(c, sp_call, 0x6441); } /* select_boss_animation_and_reset_frame_cursor */
    BUS16_SET(c, (db << 0x10) + value, 1);
    BUS16_SET(c, (db << 0x10) + 0xB4 + value, 1);
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    r->a = 1;
    r->x = value3;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x644F, 0xC2649D); GUARD_JSR(c, sp_call, 0x644F); } /* advance_orbit_sine_and_cosine_phases */
    bool x_ret = r->xf;
    if (x_ret) {
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp + 0x87));
        uint16_t value5 = BUS16_RDP(c, (db << 0x10) + 0xB4 + value4);
        if ((uint16_t)(value5 + 4) >= 0x50) {
            uint16_t value6 = BUS16_RDP(c, (db << 0x10) + 0x94 + value4);
            BUS16_RMW_SET(c, (db << 0x10) + 0x94 + value4, (uint16_t)(value6 + 1));
            BUS16_SET(c, (db << 0x10) + 0x96 + value4, 0);
            uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp + 0x87));
            uint16_t value8 = BUS16_RDP(c, (db << 0x10) + 0x96 + value7);
            if (value8 >= 0x50) {
                uint16_t value9 = BUS16_RDP(c, (db << 0x10) + 0x94 + value7);
                BUS16_RMW_SET(c, (db << 0x10) + 0x94 + value7, (uint16_t)(value9 + 1));
                uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp + 0x87));
                r->a = value8;
                r->x = value10;
                r->y = (uint8_t)y;
                r->c = value8 >= 0x50;
                r->z = value10 == 0;
                r->n = value10 & 0x80;
                r->v = ((value5 ^ (uint16_t)(value5 + 4)) & ((uint16_t)(value5 + 4) ^ 4) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x6487, 0xC2649D); GUARD_JSR(c, sp_call, 0x6487); } /* advance_orbit_sine_and_cosine_phases */
                bool x_ret3 = r->xf;
                if (x_ret3) {
                    uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp + 0x87));
                    uint16_t value12 = BUS16_RDP(c, (db << 0x10) + 0xB4 + value11);
                    if ((uint16_t)(value12 - 4) & 0x8000) {
                        r->a = (uint16_t)(value12 - 4);
                        r->x = value11;
                        r->c = 1;
                        r->z = (uint16_t)(value12 - 4) == 0;
                        r->n = (uint16_t)(value12 - 4) & 0x8000;
                        r->v = ((value12 ^ 4) & (value12 ^ (uint16_t)(value12 - 4)) & 0x8000) != 0;
                        r->mf = 0;
                        r->xf = 1;
                        RETURN_RTS(c);
                    }
                    BUS16_SET(c, (db << 0x10) + 0xB4 + value11, (uint16_t)(value12 - 4));
                    r->a = (uint16_t)(value12 - 4);
                    r->x = value11;
                    r->c = value12 >= 4;
                    r->z = (uint16_t)(value12 - 4) == 0;
                    r->n = (uint16_t)(value12 - 4) & 0x8000;
                    r->v = ((value12 ^ 4) & (value12 ^ (uint16_t)(value12 - 4)) & 0x8000) != 0;
                    r->mf = 0;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x6498, 0xC264BE); GUARD_JSR(c, sp_call, 0x6498); } /* position_orbit_from_signed_products_parent_and_offset_with_carry */
                    r->c = 0;
                    r->mf = 0;
                    r->xf = 1;
                    RETURN_RTS(c);
                } else {
                    uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
                    uint16_t value14 = BUS16_RDP(c, (db << 0x10) + 0xB4 + value13);
                    if ((uint16_t)(value14 - 4) & 0x8000) {
                        r->a = (uint16_t)(value14 - 4);
                        r->x = value13;
                        r->c = 1;
                        r->z = (uint16_t)(value14 - 4) == 0;
                        r->n = (uint16_t)(value14 - 4) & 0x8000;
                        r->v = ((value14 ^ 4) & (value14 ^ (uint16_t)(value14 - 4)) & 0x8000) != 0;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    BUS16_SET(c, (db << 0x10) + 0xB4 + value13, (uint16_t)(value14 - 4));
                    r->a = (uint16_t)(value14 - 4);
                    r->x = value13;
                    r->c = value14 >= 4;
                    r->z = (uint16_t)(value14 - 4) == 0;
                    r->n = (uint16_t)(value14 - 4) & 0x8000;
                    r->v = ((value14 ^ 4) & (value14 ^ (uint16_t)(value14 - 4)) & 0x8000) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x6498, 0xC264BE); GUARD_JSR(c, sp_call, 0x6498); } /* position_orbit_from_signed_products_parent_and_offset_with_carry */
                    r->c = 0;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
            r->a = value8;
            r->x = value7;
            r->y = (uint8_t)y;
            r->c = value8 >= 0x50;
            r->z = value8 == 0x50;
            r->n = (uint16_t)(value8 - 0x50) & 0x8000;
            r->v = ((value5 ^ (uint16_t)(value5 + 4)) & ((uint16_t)(value5 + 4) ^ 4) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x6478, 0xC2649D); GUARD_JSR(c, sp_call, 0x6478); } /* advance_orbit_sine_and_cosine_phases */
            bool x_ret7 = r->xf;
            if (x_ret7) {
                uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 0x87));
                r->x = value15;
                r->z = value15 == 0;
                r->n = value15 & 0x80;
                r->mf = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x647D, 0xC264BE); GUARD_JSR(c, sp_call, 0x647D); } /* position_orbit_from_signed_products_parent_and_offset_with_carry */
                r->c = 0;
                r->mf = 0;
                r->xf = 1;
                RETURN_RTS(c);
            } else {
                uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
                r->x = value16;
                r->z = value16 == 0;
                r->n = value16 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x647D, 0xC264BE); GUARD_JSR(c, sp_call, 0x647D); } /* position_orbit_from_signed_products_parent_and_offset_with_carry */
                r->c = 0;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
        }
        BUS16_SET(c, (db << 0x10) + 0xB4 + value4, (uint16_t)(value5 + 4));
        r->a = (uint16_t)(value5 + 4);
        r->x = value4;
        r->y = (uint8_t)y;
        r->c = (uint16_t)(value5 + 4) >= 0x50;
        r->z = (uint16_t)(value5 + 4) == 0x50;
        r->n = (uint16_t)((uint16_t)(value5 + 4) - 0x50) & 0x8000;
        r->v = ((value5 ^ (uint16_t)(value5 + 4)) & ((uint16_t)(value5 + 4) ^ 4) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6463, 0xC264BE); GUARD_JSR(c, sp_call, 0x6463); } /* position_orbit_from_signed_products_parent_and_offset_with_carry */
        r->c = 0;
        r->mf = 0;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
        uint16_t value18 = BUS16_RDP(c, (db << 0x10) + 0xB4 + value17);
        if ((uint16_t)(value18 + 4) >= 0x50) {
            uint16_t value19 = BUS16_RDP(c, (db << 0x10) + 0x94 + value17);
            BUS16_RMW_SET(c, (db << 0x10) + 0x94 + value17, (uint16_t)(value19 + 1));
            BUS16_SET(c, (db << 0x10) + 0x96 + value17, 0);
            uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
            uint16_t value21 = BUS16_RDP(c, (db << 0x10) + 0x96 + value20);
            if (value21 >= 0x50) {
                uint16_t value22 = BUS16_RDP(c, (db << 0x10) + 0x94 + value20);
                BUS16_RMW_SET(c, (db << 0x10) + 0x94 + value20, (uint16_t)(value22 + 1));
                uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
                r->a = value21;
                r->x = value23;
                r->c = value21 >= 0x50;
                r->z = value23 == 0;
                r->n = value23 & 0x8000;
                r->v = ((value18 ^ (uint16_t)(value18 + 4)) & ((uint16_t)(value18 + 4) ^ 4) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x6487, 0xC2649D); GUARD_JSR(c, sp_call, 0x6487); } /* advance_orbit_sine_and_cosine_phases */
                bool x_ret12 = r->xf;
                if (x_ret12) {
                    uint8_t value24 = BUS8_RDP(c, (uint16_t)(dp + 0x87));
                    uint16_t value25 = BUS16_RDP(c, (db << 0x10) + 0xB4 + value24);
                    if ((uint16_t)(value25 - 4) & 0x8000) {
                        r->a = (uint16_t)(value25 - 4);
                        r->x = value24;
                        r->y = (uint8_t)y;
                        r->c = 1;
                        r->z = (uint16_t)(value25 - 4) == 0;
                        r->n = (uint16_t)(value25 - 4) & 0x8000;
                        r->v = ((value25 ^ 4) & (value25 ^ (uint16_t)(value25 - 4)) & 0x8000) != 0;
                        r->mf = 0;
                        r->xf = 1;
                        RETURN_RTS(c);
                    }
                    BUS16_SET(c, (db << 0x10) + 0xB4 + value24, (uint16_t)(value25 - 4));
                    r->a = (uint16_t)(value25 - 4);
                    r->x = value24;
                    r->y = (uint8_t)y;
                    r->c = value25 >= 4;
                    r->z = (uint16_t)(value25 - 4) == 0;
                    r->n = (uint16_t)(value25 - 4) & 0x8000;
                    r->v = ((value25 ^ 4) & (value25 ^ (uint16_t)(value25 - 4)) & 0x8000) != 0;
                    r->mf = 0;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x6498, 0xC264BE); GUARD_JSR(c, sp_call, 0x6498); } /* position_orbit_from_signed_products_parent_and_offset_with_carry */
                    r->c = 0;
                    r->mf = 0;
                    r->xf = 1;
                    RETURN_RTS(c);
                } else {
                    uint16_t value26 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
                    uint16_t value27 = BUS16_RDP(c, (db << 0x10) + 0xB4 + value26);
                    if ((uint16_t)(value27 - 4) & 0x8000) {
                        r->a = (uint16_t)(value27 - 4);
                        r->x = value26;
                        r->c = 1;
                        r->z = (uint16_t)(value27 - 4) == 0;
                        r->n = (uint16_t)(value27 - 4) & 0x8000;
                        r->v = ((value27 ^ 4) & (value27 ^ (uint16_t)(value27 - 4)) & 0x8000) != 0;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    BUS16_SET(c, (db << 0x10) + 0xB4 + value26, (uint16_t)(value27 - 4));
                    r->a = (uint16_t)(value27 - 4);
                    r->x = value26;
                    r->c = value27 >= 4;
                    r->z = (uint16_t)(value27 - 4) == 0;
                    r->n = (uint16_t)(value27 - 4) & 0x8000;
                    r->v = ((value27 ^ 4) & (value27 ^ (uint16_t)(value27 - 4)) & 0x8000) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x6498, 0xC264BE); GUARD_JSR(c, sp_call, 0x6498); } /* position_orbit_from_signed_products_parent_and_offset_with_carry */
                    r->c = 0;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
            r->a = value21;
            r->x = value20;
            r->c = value21 >= 0x50;
            r->z = value21 == 0x50;
            r->n = (uint16_t)(value21 - 0x50) & 0x8000;
            r->v = ((value18 ^ (uint16_t)(value18 + 4)) & ((uint16_t)(value18 + 4) ^ 4) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x6478, 0xC2649D); GUARD_JSR(c, sp_call, 0x6478); } /* advance_orbit_sine_and_cosine_phases */
            bool x_ret16 = r->xf;
            if (x_ret16) {
                uint8_t value28 = BUS8_RDP(c, (uint16_t)(dp + 0x87));
                r->x = value28;
                r->y = (uint8_t)y;
                r->z = value28 == 0;
                r->n = value28 & 0x80;
                r->mf = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x647D, 0xC264BE); GUARD_JSR(c, sp_call, 0x647D); } /* position_orbit_from_signed_products_parent_and_offset_with_carry */
                r->c = 0;
                r->mf = 0;
                r->xf = 1;
                RETURN_RTS(c);
            } else {
                uint16_t value29 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
                r->x = value29;
                r->z = value29 == 0;
                r->n = value29 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x647D, 0xC264BE); GUARD_JSR(c, sp_call, 0x647D); } /* position_orbit_from_signed_products_parent_and_offset_with_carry */
                r->c = 0;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
        }
        BUS16_SET(c, (db << 0x10) + 0xB4 + value17, (uint16_t)(value18 + 4));
        r->a = (uint16_t)(value18 + 4);
        r->x = value17;
        r->c = (uint16_t)(value18 + 4) >= 0x50;
        r->z = (uint16_t)(value18 + 4) == 0x50;
        r->n = (uint16_t)((uint16_t)(value18 + 4) - 0x50) & 0x8000;
        r->v = ((value18 ^ (uint16_t)(value18 + 4)) & ((uint16_t)(value18 + 4) ^ 4) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6463, 0xC264BE); GUARD_JSR(c, sp_call, 0x6463); } /* position_orbit_from_signed_products_parent_and_offset_with_carry */
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC26437, SOM_RTS, "gen", initialize_descriptor_three_orbit_child_activity_animation_and_radius, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 102, 44)
