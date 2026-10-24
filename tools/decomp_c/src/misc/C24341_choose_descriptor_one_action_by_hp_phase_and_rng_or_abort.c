#include "som_c.h"

/* C24341 choose_descriptor_one_action_by_hp_phase_and_rng_or_abort   [class B, 208 bytes, 100 instructions]
 * Source: src/rom/choose_descriptor_one_action_by_hp_phase_and_rng_or_abort.s
 * Documented in docs/boss-descriptor-one.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_one_action_by_hp_phase_and_rng_or_abort(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a_hi_4356 = 0;
    uint16_t x_4356 = 0;
    uint16_t y_4356 = 0;
    uint16_t value = RAM16(0x007E + x);
    if (value != 0) {
        a_hi_4356 = value >> 8;
        x_4356 = x;
        y_4356 = y;
        goto shared_4356;
    }
    r->a = value;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4348, 0xC24330); GUARD_JSR(c, sp_call, 0x4348); } /* request_descriptor_one_phase_eight_at_half_hp */
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    if (!carry_ret) {
        a_hi_4356 = a_all >> 8;
        x_4356 = x;
        y_4356 = y;
        goto shared_4356;
    }
    uint16_t value2 = RAM16(0x0042 + x);
    uint16_t value3 = BUS16(c, 0xDCE17E + (uint16_t)(value2 << 1));
    r->a = value3;
    r->x = (uint16_t)(value2 << 1);
    r->c = 0;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
    shared_4356:;
    RAM16_SET(0x0358, (uint16_t)((uint16_t)(RAM16(0x0042 + x_4356) << 4) + RAM16(0x007E + x_4356)));
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4366, 0xC23224); GUARD_JSR(c, sp_call, 0x4366); } /* select_nearest_active_living_party_actor */
    uint16_t a_all2 = r->a;
    RAM16_SET(0x00A9 + RAM16(0x0287), a_all2);
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x436E, 0xC2091D); GUARD_JSR(c, sp_call, 0x436E); } /* derive_four_way_direction_to_low_byte_target */
    uint16_t a_all3 = r->a;
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x00AB + x_ret2, a_all3);
    r->a = RAM16(0x00A9 + x_ret2);
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4377, 0xC208BC); GUARD_JSR(c, sp_call, 0x4377); } /* derive_clamped_target_distance_minus_one */
    uint16_t a_all4 = r->a;
    uint16_t x_ret3 = r->x;
    if (a_all4 >= 1) {
        if (a_all4 >= 2) {
            r->a = RAM16(0x00A9 + x_ret3);
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x43D3, 0xC23A63); GUARD_JSR(c, sp_call, 0x43D3); } /* compare_target_axis_proximity_with_literal_early_return */
            bool carry_ret5 = r->c;
            if (carry_ret5) {
                r->a = 0x10;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x43EE, 0xC2300B); GUARD_JSR(c, sp_call, 0x43EE); } /* draw_boss_frame_random_number */
                bool zero_ret6 = r->z;
                if (!zero_ret6) {
                    r->c = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 2;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x43F6, 0xC2300B); GUARD_JSR(c, sp_call, 0x43F6); } /* draw_boss_frame_random_number */
                bool zero_ret7 = r->z;
                if (!zero_ret7) {
                    uint16_t value9 = RAM16(0x0287);
                    if (RAM16(0x0042 + value9) != 0) {
                        r->a = 0xD6C8;
                        r->x = value9;
                        r->c = 0;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    r->a = 0xD6A5;
                    r->x = value9;
                    r->c = 0;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 0xD6A3;
                r->c = 0;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value12 = RAM16(0x00AB + RAM16(0x0287));
            uint16_t value13 = RAM16(0x0358);
            uint16_t value14 = BUS16(c, 0xDCE1CA + (uint16_t)((uint16_t)(value12 << 1) + value13));
            if (value14 == 0) {
                r->a = 0x10;
                r->x = (uint16_t)((uint16_t)(value12 << 1) + value13);
                r->c = (uint16_t)(value12 << 1) + value13 > 0xFFFF;
                r->v = (((uint16_t)(value12 << 1) ^ (uint16_t)((uint16_t)(value12 << 1) + value13)) & (value13 ^ (uint16_t)((uint16_t)(value12 << 1) + value13)) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x43EE, 0xC2300B); GUARD_JSR(c, sp_call, 0x43EE); } /* draw_boss_frame_random_number */
                bool zero_ret8 = r->z;
                if (!zero_ret8) {
                    r->c = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 2;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x43F6, 0xC2300B); GUARD_JSR(c, sp_call, 0x43F6); } /* draw_boss_frame_random_number */
                bool zero_ret9 = r->z;
                if (!zero_ret9) {
                    uint16_t value15 = RAM16(0x0287);
                    if (RAM16(0x0042 + value15) != 0) {
                        r->a = 0xD6C8;
                        r->x = value15;
                        r->c = 0;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    r->a = 0xD6A5;
                    r->x = value15;
                    r->c = 0;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 0xD6A3;
                r->c = 0;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = value14;
            r->x = (uint16_t)((uint16_t)(value12 << 1) + value13);
            r->c = 0;
            r->z = value14 == 0;
            r->n = value14 & 0x8000;
            r->v = (((uint16_t)(value12 << 1) ^ (uint16_t)((uint16_t)(value12 << 1) + value13)) & (value13 ^ (uint16_t)((uint16_t)(value12 << 1) + value13)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 1;
        r->c = a_all4 >= 2;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x43A9, 0xC2300B); GUARD_JSR(c, sp_call, 0x43A9); } /* draw_boss_frame_random_number */
        bool zero_ret10 = r->z;
        if (zero_ret10) {
            uint16_t value18 = RAM16(0x00AB + RAM16(0x0287));
            uint16_t value19 = RAM16(0x0358);
            uint16_t value20 = BUS16(c, 0xDCE1AA + (uint16_t)((uint16_t)(value18 << 1) + value19));
            r->a = value20;
            r->x = (uint16_t)((uint16_t)(value18 << 1) + value19);
            r->c = 0;
            r->z = value20 == 0;
            r->n = value20 & 0x8000;
            r->v = (((uint16_t)(value18 << 1) ^ (uint16_t)((uint16_t)(value18 << 1) + value19)) & (value19 ^ (uint16_t)((uint16_t)(value18 << 1) + value19)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value22 = RAM16(0x00AB + RAM16(0x0287));
        uint16_t value23 = RAM16(0x0358);
        uint16_t value24 = BUS16(c, 0xDCE18A + (uint16_t)((uint16_t)(value22 << 1) + value23));
        r->a = value24;
        r->x = (uint16_t)((uint16_t)(value22 << 1) + value23);
        r->c = 0;
        r->z = value24 == 0;
        r->n = value24 & 0x8000;
        r->v = (((uint16_t)(value22 << 1) ^ (uint16_t)((uint16_t)(value22 << 1) + value23)) & (value23 ^ (uint16_t)((uint16_t)(value22 << 1) + value23)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 1;
    r->c = a_all4 >= 1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4382, 0xC2300B); GUARD_JSR(c, sp_call, 0x4382); } /* draw_boss_frame_random_number */
    uint16_t a_all11 = r->a;
    uint16_t x_ret10 = r->x;
    bool zero_ret11 = r->z;
    if (!zero_ret11) {
        if (a_all11 >= 2) {
            r->a = RAM16(0x00A9 + x_ret10);
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x43D3, 0xC23A63); GUARD_JSR(c, sp_call, 0x43D3); } /* compare_target_axis_proximity_with_literal_early_return */
            bool carry_ret12 = r->c;
            if (carry_ret12) {
                r->a = 0x10;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x43EE, 0xC2300B); GUARD_JSR(c, sp_call, 0x43EE); } /* draw_boss_frame_random_number */
                bool zero_ret13 = r->z;
                if (!zero_ret13) {
                    r->c = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 2;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x43F6, 0xC2300B); GUARD_JSR(c, sp_call, 0x43F6); } /* draw_boss_frame_random_number */
                bool zero_ret14 = r->z;
                if (!zero_ret14) {
                    uint16_t value26 = RAM16(0x0287);
                    if (RAM16(0x0042 + value26) != 0) {
                        r->a = 0xD6C8;
                        r->x = value26;
                        r->c = 0;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    r->a = 0xD6A5;
                    r->x = value26;
                    r->c = 0;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 0xD6A3;
                r->c = 0;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value29 = RAM16(0x00AB + RAM16(0x0287));
            uint16_t value30 = RAM16(0x0358);
            uint16_t value31 = BUS16(c, 0xDCE1CA + (uint16_t)((uint16_t)(value29 << 1) + value30));
            if (value31 == 0) {
                r->a = 0x10;
                r->x = (uint16_t)((uint16_t)(value29 << 1) + value30);
                r->c = (uint16_t)(value29 << 1) + value30 > 0xFFFF;
                r->v = (((uint16_t)(value29 << 1) ^ (uint16_t)((uint16_t)(value29 << 1) + value30)) & (value30 ^ (uint16_t)((uint16_t)(value29 << 1) + value30)) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x43EE, 0xC2300B); GUARD_JSR(c, sp_call, 0x43EE); } /* draw_boss_frame_random_number */
                bool zero_ret15 = r->z;
                if (!zero_ret15) {
                    r->c = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 2;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x43F6, 0xC2300B); GUARD_JSR(c, sp_call, 0x43F6); } /* draw_boss_frame_random_number */
                bool zero_ret16 = r->z;
                if (!zero_ret16) {
                    uint16_t value32 = RAM16(0x0287);
                    if (RAM16(0x0042 + value32) != 0) {
                        r->a = 0xD6C8;
                        r->x = value32;
                        r->c = 0;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    r->a = 0xD6A5;
                    r->x = value32;
                    r->c = 0;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 0xD6A3;
                r->c = 0;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = value31;
            r->x = (uint16_t)((uint16_t)(value29 << 1) + value30);
            r->c = 0;
            r->z = value31 == 0;
            r->n = value31 & 0x8000;
            r->v = (((uint16_t)(value29 << 1) ^ (uint16_t)((uint16_t)(value29 << 1) + value30)) & (value30 ^ (uint16_t)((uint16_t)(value29 << 1) + value30)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 1;
        r->c = a_all11 >= 2;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x43A9, 0xC2300B); GUARD_JSR(c, sp_call, 0x43A9); } /* draw_boss_frame_random_number */
        bool zero_ret17 = r->z;
        if (zero_ret17) {
            uint16_t value35 = RAM16(0x00AB + RAM16(0x0287));
            uint16_t value36 = RAM16(0x0358);
            uint16_t value37 = BUS16(c, 0xDCE1AA + (uint16_t)((uint16_t)(value35 << 1) + value36));
            r->a = value37;
            r->x = (uint16_t)((uint16_t)(value35 << 1) + value36);
            r->c = 0;
            r->z = value37 == 0;
            r->n = value37 & 0x8000;
            r->v = (((uint16_t)(value35 << 1) ^ (uint16_t)((uint16_t)(value35 << 1) + value36)) & (value36 ^ (uint16_t)((uint16_t)(value35 << 1) + value36)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value39 = RAM16(0x00AB + RAM16(0x0287));
        uint16_t value40 = RAM16(0x0358);
        uint16_t value41 = BUS16(c, 0xDCE18A + (uint16_t)((uint16_t)(value39 << 1) + value40));
        r->a = value41;
        r->x = (uint16_t)((uint16_t)(value39 << 1) + value40);
        r->c = 0;
        r->z = value41 == 0;
        r->n = value41 & 0x8000;
        r->v = (((uint16_t)(value39 << 1) ^ (uint16_t)((uint16_t)(value39 << 1) + value40)) & (value40 ^ (uint16_t)((uint16_t)(value39 << 1) + value40)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x438A, 0xC2300B); GUARD_JSR(c, sp_call, 0x438A); } /* draw_boss_frame_random_number */
    uint16_t a_all18 = r->a;
    RAM16_SET(0x021A, (uint16_t)(a_all18 << 1));
    uint16_t value43 = RAM16(0x0042 + RAM16(0x0287));
    uint16_t value44 = RAM16(0x021A);
    uint16_t value45 = BUS16(c, 0xDCE182 + (uint16_t)((uint16_t)(value43 << 2) + value44));
    r->a = value45;
    r->x = (uint16_t)((uint16_t)(value43 << 2) + value44);
    r->c = 0;
    r->z = value45 == 0;
    r->n = value45 & 0x8000;
    r->v = (((uint16_t)(value43 << 2) ^ (uint16_t)((uint16_t)(value43 << 2) + value44)) & (value44 ^ (uint16_t)((uint16_t)(value43 << 2) + value44)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24341, SOM_RTS, "gen", choose_descriptor_one_action_by_hp_phase_and_rng_or_abort, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 208, 100)
