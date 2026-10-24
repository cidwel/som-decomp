#include "som_c.h"

/* C1D942 advance_actor_program_before_current_action_dispatch   [class C, 485 bytes, 195 instructions]
 * Source: src/rom/advance_actor_program_before_current_action_dispatch.s
 * Documented in docs/actor-program-step-caller.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYCV.
 */
static void advance_actor_program_before_current_action_dispatch(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM8(0xE064 + x) = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xD94B, 0xC10028); GUARD_JSL(c, sp_call, 0xD94B); } /* execute_actor_program_step_long */
    r->sp += 2;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (x_ret) {
        c->fail = 3;
        return;
    } else {
        uint8_t value3 = RAM8(0x0000 + sp0 - 1);
        uint8_t value4 = RAM8(0x0000 + sp0);
        uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0xE140 + ((value4 << 8) | value3));
        if (value5 != 0) {
            if (value5 & 0x80) {
                if ((value5 & 0x40) != 0) {
                    if (value5 >= 0xC2) {
                        r->x = (value4 << 8) | value3;
                        r->c = value5 >= 0xC2;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTL(c);
                    }
                    if (value5 != 0xC0) {
                        BUS8_SET(c, (db_ret << 0x10) + 0xE067 + ((value4 << 8) | value3), 0x80);
                        BUS8_SET(c, (db_ret << 0x10) + 0xE013 + ((value4 << 8) | value3), 0);
                        uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0xE010 + ((value4 << 8) | value3));
                        RAM8(0x000C + dp_ret) = value6;
                        uint8_t value7 = BUS8_RDP(c, (db_ret << 0x10) + 0xE011 + ((value4 << 8) | value3));
                        RAM8(0x000D + dp_ret) = value7;
                        uint8_t value8 = BUS8_RDP(c, (db_ret << 0x10) + 0xE142 + ((value4 << 8) | value3));
                        BUS8_SET(c, (db_ret << 0x10) + 0xE011 + ((value4 << 8) | value3), value8);
                        uint8_t value9 = BUS8_RDP(c, (db_ret << 0x10) + 0xE143 + ((value4 << 8) | value3));
                        uint8_t a1;
                        if (value9 != 0) {
                            a1 = value9;
                        } else {
                            BUS8_SET(c, (db_ret << 0x10) + 0xE064 + ((value4 << 8) | value3), 0x80);
                            a1 = 0;
                        }
                        BUS8_SET(c, (db_ret << 0x10) + 0xE062 + ((value4 << 8) | value3), a1);
                        r->a = (a_all >> 8 << 8) | a1;
                        r->x = (value4 << 8) | value3;
                        r->mf = 1;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xDB06, 0xC1DB27); GUARD_JSR(c, sp_call, 0xDB06); } /* decode_actor_direction_command_and_diagonal_facing */
                        uint16_t a_all2 = r->a;
                        BUS8_SET(c, (db_ret << 0x10) + 0xE010 + ((value4 << 8) | value3), (uint8_t)a_all2);
                        uint8_t value10 = BUS8_RDP(c, (db_ret << 0x10) + 0xE030 + ((value4 << 8) | value3));
                        bool carry1;
                        if (value10 == 0xFF) {
                            BUS16_SET(c, (db_ret << 0x10) + 0xE030 + ((value4 << 8) | value3), (a_all2 >> 8 << 8) | value10);
                            BUS16_SET(c, (db_ret << 0x10) + 0xE006 + ((value4 << 8) | value3), 0);
                            BUS16_SET(c, (db_ret << 0x10) + 0xE008 + ((value4 << 8) | value3), 0);
                            carry1 = value10 >= 0xFF;
                        } else {
                            uint16_t value11 = BUS16_RDP(c, (db_ret << 0x10) + 0xE010 + ((value4 << 8) | value3));
                            uint16_t value12 = RAM16(0x000C + dp_ret);
                            if (value11 != value12) {
                                BUS16_SET(c, (db_ret << 0x10) + 0xE030 + ((value4 << 8) | value3), 0xFF);
                                BUS16_SET(c, (db_ret << 0x10) + 0xE006 + ((value4 << 8) | value3), 0);
                                BUS16_SET(c, (db_ret << 0x10) + 0xE008 + ((value4 << 8) | value3), 0);
                            }
                            carry1 = value11 >= value12;
                        }
                        r->c = carry1;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTL(c);
                    }
                    uint8_t value13 = BUS8_RDP(c, (db_ret << 0x10) + 0xE141 + ((value4 << 8) | value3));
                    BUS8_SET(c, (db_ret << 0x10) + 0x1E00, value13);
                    uint8_t value14 = BUS8_RDP(c, (db_ret << 0x10) + 0xE142 + ((value4 << 8) | value3));
                    BUS8_SET(c, (db_ret << 0x10) + 0x1E01, value14);
                    uint8_t value15 = BUS8_RDP(c, (db_ret << 0x10) + 0xE143 + ((value4 << 8) | value3));
                    BUS8_SET(c, (db_ret << 0x10) + 0x1E02, value15);
                    RAM8(0x0000 + sp0) = value4;
                    RAM8(0x0000 + sp0 - 1) = (uint8_t)((value4 << 8) | value3);
                    r->a = (a_all >> 8 << 8) | value15;
                    r->x = (value4 << 8) | value3;
                    r->c = value5 >= 0xC0;
                    r->z = value15 == 0;
                    r->n = value15 & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    r->sp -= 2;
                    { const uint16_t sp_call = r->sp; JSL(c, 0xDAD8, 0xC30004); GUARD_JSL(c, sp_call, 0xDAD8); } /* audio_command_sender_public_jump */
                    r->sp += 2;
                    r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                if (value5 != 0x81) {
                    r->x = (value4 << 8) | value3;
                    r->c = value5 >= 0x81;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTL(c);
                }
                BUS8_SET(c, (db_ret << 0x10) + 0xE043 + ((value4 << 8) | value3), 0);
                uint8_t value18 = BUS8_RDP(c, (db_ret << 0x10) + 0xE142 + ((value4 << 8) | value3));
                BUS8_SET(c, (db_ret << 0x10) + 0xE03D + ((value4 << 8) | value3), value18);
                BUS8_SET(c, (db_ret << 0x10) + 0xE180 + ((value4 << 8) | value3), value18);
                BUS8_SET(c, (db_ret << 0x10) + 0xE032 + ((value4 << 8) | value3), 1);
                r->x = (value4 << 8) | value3;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xDA99, 0xC1DFD3); GUARD_JSR(c, sp_call, 0xDA99); } /* load_actor_map_graphics */
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0xDA9D, 0xC0DF51); GUARD_JSL(c, sp_call, 0xDA9D); } /* refresh_large_map_object_palette_and_graphics_entry */
                uint16_t x_ret7 = r->x;
                BUS8_SET(c, (db_ret << 0x10) + 0xE030 + x_ret7, 0xFF);
                BUS8_SET(c, (db_ret << 0x10) + 0xE104 + x_ret7, 0);
                BUS8_SET(c, (db_ret << 0x10) + 0xE100 + x_ret7, 0);
                BUS8_SET(c, (db_ret << 0x10) + 0xE083 + x_ret7, 0);
                BUS8_SET(c, (db_ret << 0x10) + 0xE084 + x_ret7, 0);
                BUS8_SET(c, (db_ret << 0x10) + 0xE01C + x_ret7, 0);
                BUS8_SET(c, (db_ret << 0x10) + 0xE00A + x_ret7, 0);
                BUS8_SET(c, (db_ret << 0x10) + 0xE064 + x_ret7, 0);
                BUS8_SET(c, (db_ret << 0x10) + 0xE062 + x_ret7, 0);
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTL(c);
            }
            if ((value5 & 0x40) == 0) {
                if (value5 < 7) {
                    if (value5 == 1) {
                        uint8_t value19 = BUS8_RDP(c, (db_ret << 0x10) + 0xE067 + ((value4 << 8) | value3));
                        if (value19 != 0) {
                            BUS8_SET(c, (db_ret << 0x10) + 0xE006 + ((value4 << 8) | value3), 0);
                            BUS8_SET(c, (db_ret << 0x10) + 0xE007 + ((value4 << 8) | value3), 0);
                            BUS8_SET(c, (db_ret << 0x10) + 0xE008 + ((value4 << 8) | value3), 0);
                            BUS8_SET(c, (db_ret << 0x10) + 0xE013 + ((value4 << 8) | value3), 0);
                            BUS8_SET(c, (db_ret << 0x10) + 0xE011 + ((value4 << 8) | value3), 0);
                            BUS8_SET(c, (db_ret << 0x10) + 0xE067 + ((value4 << 8) | value3), 0);
                            BUS8_SET(c, (db_ret << 0x10) + 0xE030 + ((value4 << 8) | value3), 0xFF);
                        }
                        r->x = (value4 << 8) | value3;
                        r->c = value5 >= 1;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTL(c);
                    }
                    if (value5 == 2) {
                        BUS8_SET(c, (db_ret << 0x10) + 0xE064 + ((value4 << 8) | value3), 0x80);
                        BUS8_SET(c, (db_ret << 0x10) + 0xE085 + ((value4 << 8) | value3), 0);
                        r->a = (a_all >> 8 << 8) | 0x80;
                        r->x = (value4 << 8) | value3;
                        r->c = value5 >= 2;
                        r->mf = 1;
                        r->xf = 0;
                        TAIL_CALL(c, 0xC0B287, SOM_RTL); /* begin_actor_attack_with_direct_target_long */
                    }
                    if (value5 == 4) {
                        BUS8_SET(c, (db_ret << 0x10) + 0xE000 + ((value4 << 8) | value3), 0);
                        BUS8_SET(c, (db_ret << 0x10) + 0xE043 + ((value4 << 8) | value3), 0);
                        r->x = (value4 << 8) | value3;
                        r->c = value5 >= 4;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTL(c);
                    }
                    if (value5 == 5) {
                        r->a = (a_all >> 8 << 8) | value5;
                        r->x = (value4 << 8) | value3;
                        r->mf = 1;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSL(c, 0xD9C7, 0xC2A360); GUARD_JSL(c, sp_call, 0xD9C7); } /* select_reusable_spare_actor_for_action_clone */
                        bool carry_ret5 = r->c;
                        if (!carry_ret5) {
                            r->xf = 0;
                            RETURN_RTL(c);
                        }
                        RAM8(0x0000 + sp0) = value4;
                        RAM8(0x0000 + sp0 - 1) = (uint8_t)((value4 << 8) | value3);
                        r->xf = 0;
                        r->sp -= 2;
                        { const uint16_t sp_call = r->sp; JSL(c, 0xD9CE, 0xC2A39F); GUARD_JSL(c, sp_call, 0xD9CE); } /* clone_selected_actor_fields_into_spare_record */
                        r->sp += 2;
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 2;
                        { const uint16_t sp_call = r->sp; JSL(c, 0xD9D2, 0xC0E1A2); GUARD_JSL(c, sp_call, 0xD9D2); } /* assign_large_object_palette_rows_entry */
                        r->sp += 2;
                        r->mf = 0;
                        r->xf = 0;
                        r->sp -= 2;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xD9D5, 0xC1E022); GUARD_JSR(c, sp_call, 0xD9D5); } /* load_actor_map_palette */
                        r->sp += 2;
                        uint16_t a_all9 = r->a;
                        uint16_t x_ret9 = r->x;
                        BUS8_SET(c, (db_ret << 0x10) + 0xE032 + x_ret9, 1);
                        r->a = (a_all9 >> 8 << 8) | 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 2;
                        { const uint16_t sp_call = r->sp; JSL(c, 0xD9E0, 0xC0E034); GUARD_JSL(c, sp_call, 0xD9E0); } /* refresh_actor_identity_graphics_and_program_long */
                        r->sp += 2;
                        bool x_ret10 = r->xf;
                        if (x_ret10) {
                            c->fail = 3;
                            return;
                        } else {
                            r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                            r->xf = 0;
                            RETURN_RTL(c);
                        }
                    }
                    if (((value4 << 8) | value3) >= 0x0600) {
                        r->x = (value4 << 8) | value3;
                        r->c = ((value4 << 8) | value3) >= 0x0600;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTL(c);
                    }
                    uint8_t value23 = RAM8(0x00ED + dp_ret);
                    if (!(value23 & 0x80)) {
                        r->x = (value4 << 8) | value3;
                        r->c = ((value4 << 8) | value3) >= 0x0600;
                        r->v = value23 & 0x40;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTL(c);
                    }
                    uint8_t value24 = BUS8_RDP(c, (db_ret << 0x10) + 0xE01A + ((value4 << 8) | value3));
                    uint8_t value25 = BUS8_RDP(c, (db_ret << 0x10) + 0xE01B + ((value4 << 8) | value3));
                    if ((value24 | value25) != 0) {
                        r->x = (value4 << 8) | value3;
                        r->c = ((value4 << 8) | value3) >= 0x0600;
                        r->v = value23 & 0x40;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTL(c);
                    }
                    BUS8_SET(c, (db_ret << 0x10) + 0xE064 + ((value4 << 8) | value3), 0x80);
                    BUS8_SET(c, (db_ret << 0x10) + 0xE085 + ((value4 << 8) | value3), 0x80);
                    r->a = (a_all >> 8 << 8) | 0x80;
                    r->x = (value4 << 8) | value3;
                    r->c = ((value4 << 8) | value3) >= 0x0600;
                    r->v = value23 & 0x40;
                    r->mf = 1;
                    r->xf = 0;
                    TAIL_CALL(c, 0xC0B295, SOM_RTL); /* begin_actor_attack_variant_long */
                }
                if (value5 != 7) {
                    r->x = (value4 << 8) | value3;
                    r->c = value5 >= 7;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTL(c);
                }
                r->a = (a_all >> 8 << 8) | value5;
                r->x = (value4 << 8) | value3;
                r->c = value5 >= 7;
                r->mf = 1;
                r->xf = 0;
                TAIL_CALL(c, 0xC2B01E, SOM_RTL); /* clear_actor_charge_and_idle_party_gauge */
            }
            if (value5 >= 0x45) {
                r->x = (value4 << 8) | value3;
                r->c = value5 >= 0x45;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            if (value5 == 0x40) {
                uint8_t value26 = BUS8_RDP(c, (db_ret << 0x10) + 0xE141 + ((value4 << 8) | value3));
                BUS8_SET(c, (db_ret << 0x10) + 0xE011 + ((value4 << 8) | value3), value26);
                BUS8_SET(c, (db_ret << 0x10) + 0xE01C + ((value4 << 8) | value3), 0x40);
                BUS8_SET(c, (db_ret << 0x10) + 0xE064 + ((value4 << 8) | value3), 0x80);
                BUS8_SET(c, (db_ret << 0x10) + 0xE030 + ((value4 << 8) | value3), 0xFF);
                BUS8_SET(c, (db_ret << 0x10) + 0xE006 + ((value4 << 8) | value3), 0);
                BUS8_SET(c, (db_ret << 0x10) + 0xE007 + ((value4 << 8) | value3), 0);
                BUS8_SET(c, (db_ret << 0x10) + 0xE008 + ((value4 << 8) | value3), 0);
                r->x = (value4 << 8) | value3;
                r->c = value5 >= 0x40;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            if (value5 == 0x41) {
                r->x = (value4 << 8) | value3;
                r->c = value5 >= 0x41;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            if (value5 == 0x42) {
                r->x = (value4 << 8) | value3;
                r->c = value5 >= 0x42;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            if (value5 == 0x43) {
                r->a = (a_all >> 8 << 8) | value5;
                r->x = (value4 << 8) | value3;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0xDA57, 0xC2A360); GUARD_JSL(c, sp_call, 0xDA57); } /* select_reusable_spare_actor_for_action_clone */
                bool carry_ret10 = r->c;
                if (!carry_ret10) {
                    r->xf = 0;
                    RETURN_RTL(c);
                }
                RAM8(0x0000 + sp0) = value4;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)((value4 << 8) | value3);
                r->xf = 0;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSL(c, 0xDA5E, 0xC2A39F); GUARD_JSL(c, sp_call, 0xDA5E); } /* clone_selected_actor_fields_into_spare_record */
                r->sp += 2;
                uint16_t a_all12 = r->a;
                uint16_t x_ret12 = r->x;
                uint8_t value27 = BUS8_RDP(c, (db_ret << 0x10) + 0xE141 + x_ret12);
                BUS8_SET(c, (db_ret << 0x10) + 0xE03D + x_ret12, value27);
                BUS8_SET(c, (db_ret << 0x10) + 0xE180 + x_ret12, value27);
                BUS8_SET(c, (db_ret << 0x10) + 0xE032 + x_ret12, 1);
                BUS8_SET(c, (db_ret << 0x10) + 0xE000 + x_ret12, 1);
                BUS8_SET(c, (db_ret << 0x10) + 0xE043 + x_ret12, 0);
                r->a = (a_all12 >> 8 << 8) | 0;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSL(c, 0xDA7A, 0xC0E1A2); GUARD_JSL(c, sp_call, 0xDA7A); } /* assign_large_object_palette_rows_entry */
                r->sp += 2;
                r->mf = 0;
                r->xf = 0;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSR(c, 0xDA7D, 0xC1DFD3); GUARD_JSR(c, sp_call, 0xDA7D); } /* load_actor_map_graphics */
                r->sp += 2;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSL(c, 0xDA81, 0xC0DF51); GUARD_JSL(c, sp_call, 0xDA81); } /* refresh_large_map_object_palette_and_graphics_entry */
                r->sp += 2;
                bool x_ret14 = r->xf;
                if (x_ret14) {
                    c->fail = 3;
                    return;
                } else {
                    r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                    r->xf = 0;
                    RETURN_RTL(c);
                }
            }
            uint8_t value31 = BUS8_RDP(c, (db_ret << 0x10) + 0xE141 + ((value4 << 8) | value3));
            BUS8_SET(c, (db_ret << 0x10) + 0xE011 + ((value4 << 8) | value3), value31);
            BUS8_SET(c, (db_ret << 0x10) + 0xE01C + ((value4 << 8) | value3), 0x40);
            BUS8_SET(c, (db_ret << 0x10) + 0xE064 + ((value4 << 8) | value3), 0x80);
            BUS8_SET(c, (db_ret << 0x10) + 0xE030 + ((value4 << 8) | value3), 0xFF);
            BUS8_SET(c, (db_ret << 0x10) + 0xE006 + ((value4 << 8) | value3), 0);
            BUS8_SET(c, (db_ret << 0x10) + 0xE007 + ((value4 << 8) | value3), 0);
            BUS8_SET(c, (db_ret << 0x10) + 0xE008 + ((value4 << 8) | value3), 0);
            r->a = (a_all >> 8 << 8) | 0xFF;
            r->x = (value4 << 8) | value3;
            r->c = value5 >= 0x43;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xDA20, 0xC188C7); GUARD_JSR(c, sp_call, 0xDA20); } /* prepare_guarded_actor_cast_request_and_party_graphics */
            r->xf = 0;
            RETURN_RTL(c);
        }
        r->x = (value4 << 8) | value3;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
}
SOM_REGISTER(0xC1D942, SOM_RTL, "gen", advance_actor_program_before_current_action_dispatch, 0, L_X | L_Y | L_C | L_V, 2, 1, 0, 485, 195)
