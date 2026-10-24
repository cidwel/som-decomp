#include "som_c.h"
/* SOM_POLL_HOOK */

/* C01D97 run_native_menu_coordinator_before_exceptional_callback   [class D, 253 bytes, 103 instructions]
 * Source: src/rom/run_native_menu_coordinator_before_exceptional_callback.s
 * Entry: M=any X=any DB=any D=$0000.  Callers read: BXYCZNV.
 */
static void run_native_menu_coordinator_before_exceptional_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    uint64_t loop_guard = 0;
    const uint8_t d_entry = r->d;
    const uint8_t x_entry = r->xf;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = ((((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (x_entry << 4)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = db;
    RAM8(0x0000 + sp0 - 2) = 0;
    RAM8(0x0000 + sp0 - 3) = 0;
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 7) = 0;
    RAM8(0x0000 + sp0 - 8) = 0;
    uint8_t value = RAM8(0x19FE);
    RAM8(0xA21F) = value;
    r->a = (a >> 8 << 8) | value;
    r->y = 0;
    r->z = value == 0;
    r->n = value & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1DAF, 0xC02910); GUARD_JSR(c, sp_call, 0x1DAF); } /* fade_out_native_menu_unless_initializing */
    r->sp += 7;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1DB2, 0xC02955); GUARD_JSR(c, sp_call, 0x1DB2); } /* select_native_menu_actor_matching_current_hero */
    r->sp += 7;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSL(c, 0x1DB6, 0xC00EBF); GUARD_JSL(c, sp_call, 0x1DB6); } /* reset_map_menu_state */
    r->sp += 7;
    uint16_t a_all3 = r->a;
    uint8_t value2 = RAM8(0x0000 + sp0 - 6);
    RAM8(0x0000 + sp0 - 6) = value2;
    r->a = (a_all3 >> 8 << 8) | value2;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1DBB, 0xC0281E); GUARD_JSR(c, sp_call, 0x1DBB); } /* construct_native_menu_graphics_and_install_nmi_vector */
    r->sp += 7;
    uint8_t db_ret2 = r->db;
    bool x_ret3 = r->xf;
    uint16_t a_all4 = r->a;
    bool carry_ret4 = r->c;
    bool overflow_ret2 = r->v;
    uint8_t value3 = RAM8(0x0000 + sp0 - 6);
    if (x_ret3) {
        c->fail = 3;
        return;
    } else {
        uint8_t value24 = BUS8(c, 0xC02A60 + (((a_all4 >> 8 << 8) | value3) & 0xFF));
        uint8_t value25 = RAM8(0x0000 + sp0 - 5);
        uint8_t value26 = RAM8(0x0000 + sp0 - 4);
        uint8_t a2 = value24;
        uint8_t a_hi8 = 0;
        uint16_t x7 = ((a_all4 >> 8 << 8) | value3) & 0xFF;
        uint16_t y7 = (value26 << 8) | value25;
        bool carry7 = carry_ret4;
        bool overflow7 = overflow_ret2;
        uint8_t data_bank6 = db_ret2;
        uint16_t direct_page4 = 0;
        for (;;) {
            LOOP_GUARD(loop_guard);
            RAM8(0xA202) = a2;
            BUS16_SET(c, (data_bank6 << 0x10) + 0xA22B, y7);
            RAM8(0x0000 + sp0 - 4) = a2;
            r->a = (a_hi8 << 8) | a2;
            r->x = x7;
            r->y = y7;
            r->c = carry7;
            r->v = overflow7;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank6;
            r->dp = direct_page4;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1DD4, 0xC02910); GUARD_JSR(c, sp_call, 0x1DD4); } /* fade_out_native_menu_unless_initializing */
            r->sp += 5;
            uint16_t a_all19 = r->a;
            uint8_t value27 = BUS8_RDP(c, (data_bank6 << 0x10) + 0xA212);
            BUS8_SET(c, (data_bank6 << 0x10) + 0xA212, value27 & 0xEF);
            r->a = (a_all19 >> 8 << 8) | 0x10;
            r->z = (value27 & 0x10) == 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1DDC, 0xC028A6); GUARD_JSR(c, sp_call, 0x1DDC); } /* initialize_native_menu_page_state_and_record_pointer */
            r->sp += 5;
            uint8_t value28 = RAM8(0x0000 + sp0 - 4);
            r->a = (uint8_t)(value28 << 1);
            r->x = (uint8_t)(value28 << 1);
            r->c = value28 & 0x80;
            r->z = (uint8_t)(value28 << 1) == 0;
            r->n = (uint8_t)(value28 << 1) & 0x8000;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp;
            switch ((uint8_t)(value28 << 1)) {
            case 0x0000: JSR(c, 0x1DE5, 0xC02AA9); GUARD_JSR(c, sp_call, 0x1DE5); break; /* construct_native_title_page_short_call_wrapper */
            case 0x0002: JSR(c, 0x1DE5, 0xC02AB3); GUARD_JSR(c, sp_call, 0x1DE5); break; /* near_call_native_save_page_constructor */
            case 0x0004: JSR(c, 0x1DE5, 0xC02AAE); GUARD_JSR(c, sp_call, 0x1DE5); break; /* construct_native_load_page_short_call_wrapper */
            case 0x0006: JSR(c, 0x1DE5, 0xC02AA4); GUARD_JSR(c, sp_call, 0x1DE5); break; /* construct_native_name_page_short_call_wrapper */
            case 0x0008: JSR(c, 0x1DE5, 0xC02A9F); GUARD_JSR(c, sp_call, 0x1DE5); break; /* near_call_native_personality_page_constructor */
            case 0x000A: JSR(c, 0x1DE5, 0xC02ABD); GUARD_JSR(c, sp_call, 0x1DE5); break; /* near_call_native_settings_page_constructor */
            case 0x000C: JSR(c, 0x1DE5, 0xC02AC2); GUARD_JSR(c, sp_call, 0x1DE5); break; /* near_call_native_controller_page_constructor */
            case 0x000E: JSR(c, 0x1DE5, 0xC02A9A); GUARD_JSR(c, sp_call, 0x1DE5); break; /* near_call_native_party_status_page_constructor */
            case 0x0010: JSR(c, 0x1DE5, 0xC02A90); GUARD_JSR(c, sp_call, 0x1DE5); break; /* near_call_native_spell_page_constructor */
            case 0x0012: JSR(c, 0x1DE5, 0xC02A95); GUARD_JSR(c, sp_call, 0x1DE5); break; /* near_call_native_item_page_constructor */
            case 0x0014: JSR(c, 0x1DE5, 0xC02AB8); GUARD_JSR(c, sp_call, 0x1DE5); break; /* near_call_native_save_confirmation_page_constructor */
            default: JSR(c, 0x1DE5, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x2A7A + ((uint8_t)(value28 << 1))))); GUARD_JSR(c, sp_call, 0x1DE5);
            }
            }
            r->sp += 4;
            uint16_t dp_ret4 = r->dp;
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t a_all21 = r->a;
            BUS8_SET(c, 0x004200, 0x81);
            r->a = (a_all21 >> 8 << 8) | 0x81;
            r->z = 0;
            r->n = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1DEE, 0xC02930); GUARD_JSR(c, sp_call, 0x1DEE); } /* request_native_menu_open_sound_and_fade_in */
            r->sp += 4;
            uint8_t db_ret10 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret27 = r->xf;
            uint16_t a_all22 = r->a;
            uint16_t x_ret28 = r->x;
            uint16_t y_ret13 = r->y;
            bool carry_ret20 = r->c;
            bool overflow_ret13 = r->v;
            uint8_t a_hi9 = a_all22 >> 8;
            uint16_t x8 = x_ret28;
            uint16_t y8 = y_ret13;
            bool carry8 = carry_ret20;
            bool overflow8 = overflow_ret13;
            uint8_t data_bank7 = db_ret10;
            uint16_t direct_page5 = dp_ret4;
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value29 = BUS8(c, 0x004212);
                if ((value29 & 0x80) != 0) {
                    continue;
                }
                uint8_t a_hi10 = a_hi9;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value30 = BUS8(c, 0x004212);
                    if (!((value30 & 0x80) == 0)) break;
                }
                r->a = (a_hi10 << 8) | (uint8_t)a;
                r->x = x8;
                r->y = y8;
                r->c = carry8;
                r->v = overflow8;
                r->mf = 1;
                r->xf = x_ret27;
                r->db = data_bank7;
                r->dp = direct_page5;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1E01, 0xC01E94); GUARD_JSR(c, sp_call, 0x1E01); } /* publish_pending_native_menu_tiles_oam_and_actor_color */
                r->sp += 4;
                uint8_t db_ret11 = r->db;
                bool overflow_ret14 = r->v;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1E04, 0xC028D9); GUARD_JSR(c, sp_call, 0x1E04); } /* close_title_menu_after_idle_input_timeout */
                r->sp += 4;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1E07, 0xC01ED1); GUARD_JSR(c, sp_call, 0x1E07); } /* tick_native_menu_actor_sprite_palette_blink */
                r->sp += 4;
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret32 = r->xf;
                uint16_t a_all25 = r->a;
                uint16_t x_ret33 = r->x;
                uint16_t y_ret16 = r->y;
                uint8_t value31 = BUS8_RDP(c, (db_ret11 << 0x10) + 0xA201);
                BUS8_SET(c, (db_ret11 << 0x10) + 0xA201, (uint8_t)(value31 + 1));
                bool x_flag5;
                uint8_t a_hi11;
                uint16_t x9;
                uint16_t y9;
                bool carry9;
                bool overflow9;
                uint8_t data_bank8;
                uint16_t direct_page6;
                if ((uint8_t)(value31 + 1) != 4) {
                    x_flag5 = x_ret32;
                    a_hi11 = a_all25 >> 8;
                    x9 = x_ret33;
                    y9 = y_ret16;
                    carry9 = (uint8_t)(value31 + 1) >= 4;
                    overflow9 = overflow_ret14;
                    data_bank8 = db_ret11;
                    direct_page6 = direct_page5;
                } else {
                    BUS8_SET(c, (db_ret11 << 0x10) + 0xA201, 0);
                    r->a = (a_all25 >> 8 << 8) | (uint8_t)(value31 + 1);
                    r->c = (uint8_t)(value31 + 1) >= 4;
                    r->z = (uint8_t)(value31 + 1) == 4;
                    r->n = (uint8_t)((uint8_t)(value31 + 1) - 4) & 0x80;
                    r->sp -= 4;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x1E18, 0xC02BD9); GUARD_JSR(c, sp_call, 0x1E18); } /* await_native_menu_autojoy_and_poll_full_controller_chain */
                    r->sp += 4;
                    r->xf = 0;
                    r->sp -= 4;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x1E1B, 0xC02B06); GUARD_JSR(c, sp_call, 0x1E1B); } /* dispatch_twelve_native_menu_button_bits_and_copy_previous_pads */
                    r->sp += 4;
                    uint16_t dp_ret6 = r->dp;
                    uint8_t db_ret13 = r->db;
                    if (r->mf != 1) { c->fail = 3; return; }
                    bool x_ret35 = r->xf;
                    uint16_t a_all27 = r->a;
                    uint16_t x_ret36 = r->x;
                    uint16_t y_ret18 = r->y;
                    bool carry_ret25 = r->c;
                    bool overflow_ret16 = r->v;
                    x_flag5 = x_ret35;
                    a_hi11 = a_all27 >> 8;
                    x9 = x_ret36;
                    y9 = y_ret18;
                    carry9 = carry_ret25;
                    overflow9 = overflow_ret16;
                    data_bank8 = db_ret13;
                    direct_page6 = dp_ret6;
                }
                uint8_t value32 = BUS8_RDP(c, (data_bank8 << 0x10) + 0xA20A);
                a_hi9 = a_hi11;
                x8 = x9;
                y8 = y9;
                carry8 = carry9;
                overflow8 = overflow9;
                data_bank7 = data_bank8;
                direct_page5 = direct_page6;
                if (!((value32 & 1) == 0)) break;
            }
            uint8_t value33 = BUS8_RDP(c, (data_bank7 << 0x10) + 0xA210);
            if (value33 != 0xFF) {
                BUS8_SET(c, (data_bank7 << 0x10) + 0xA202, value33);
                if (x_ret27 != 0) { c->fail = 3; return; }
                a2 = value33;
                a_hi8 = a_hi9;
                x7 = x8;
                y7 = y8;
                carry7 = value33 >= 0xFF;
                overflow7 = overflow8;
                data_bank6 = data_bank7;
                direct_page4 = direct_page5;
                continue;
            }
            a2 = value33;
            a_hi8 = a_hi9;
            x7 = x8;
            y7 = y8;
            carry7 = value33 >= 0xFF;
            overflow7 = overflow8;
            data_bank6 = data_bank7;
            direct_page4 = direct_page5;
            break;
        }
        r->a = (a_hi8 << 8) | a2;
        r->x = x7;
        r->y = y7;
        r->c = carry7;
        r->v = overflow7;
        r->mf = 1;
        r->db = data_bank6;
        r->dp = direct_page4;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1E32, 0xC02910); GUARD_JSR(c, sp_call, 0x1E32); } /* fade_out_native_menu_unless_initializing */
        r->sp += 4;
        bool x_ret37 = r->xf;
        uint16_t a_all28 = r->a;
        uint8_t value34 = BUS8_RDP(c, (data_bank6 << 0x10) + 0xA202);
        bool x_flag7;
        uint8_t a_hi13;
        uint16_t x11;
        uint16_t y11;
        bool carry11;
        bool overflow11;
        uint8_t data_bank10;
        if (value34 == 0x0A) {
            x_flag7 = x_ret37;
            a_hi13 = a_all28 >> 8;
            x11 = x7;
            y11 = y7;
            carry11 = value34 >= 0x0A;
            overflow11 = overflow7;
            data_bank10 = data_bank6;
        } else {
            bool x_flag6;
            uint8_t a_hi12;
            uint16_t x10;
            uint16_t y10;
            bool carry10;
            bool overflow10;
            uint8_t data_bank9;
            if (value34 == 3) {
                x_flag6 = x_ret37;
                a_hi12 = a_all28 >> 8;
                x10 = x7;
                y10 = y7;
                carry10 = value34 >= 3;
                overflow10 = overflow7;
                data_bank9 = data_bank6;
            } else {
                r->a = (a_all28 >> 8 << 8) | 1;
                r->c = value34 >= 3;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1E42, 0xC029D2); GUARD_JSR(c, sp_call, 0x1E42); } /* expand_local_audio_preset_and_send_four_byte_request */
                r->sp += 4;
                uint8_t db_ret14 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret38 = r->xf;
                uint16_t a_all29 = r->a;
                uint16_t x_ret39 = r->x;
                uint16_t y_ret19 = r->y;
                bool carry_ret27 = r->c;
                bool overflow_ret17 = r->v;
                x_flag6 = x_ret38;
                a_hi12 = a_all29 >> 8;
                x10 = x_ret39;
                y10 = y_ret19;
                carry10 = carry_ret27;
                overflow10 = overflow_ret17;
                data_bank9 = db_ret14;
            }
            x_flag7 = x_flag6;
            a_hi13 = a_hi12;
            x11 = x10;
            y11 = y10;
            carry11 = carry10;
            overflow11 = overflow10;
            data_bank10 = data_bank9;
        }
        uint8_t value35 = BUS8_RDP(c, (data_bank10 << 0x10) + 0xA20A);
        BUS8_SET(c, (data_bank10 << 0x10) + 0xA20A, value35 | 0x80);
        r->a = (a_hi13 << 8) | 0x80;
        r->x = x11;
        r->y = y11;
        r->c = carry11;
        r->z = (value35 & 0x80) == 0;
        r->n = 1;
        r->v = overflow11;
        r->mf = 1;
        r->xf = x_flag7;
        r->db = data_bank10;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1E4A, 0xC02781); GUARD_JSR(c, sp_call, 0x1E4A); } /* clear_native_menu_sprite_and_tile_workspaces */
        r->sp += 4;
        uint16_t x_ret41 = r->x;
        uint16_t y_ret20 = r->y;
        r->mf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1E4D, 0xC025AD); GUARD_JSR(c, sp_call, 0x1E4D); } /* upload_complete_native_menu_tile_workspace */
        r->sp += 4;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret42 = r->xf;
        uint8_t value36 = BUS8_RDP(c, (data_bank10 << 0x10) + 0xA20A);
        BUS8_SET(c, (data_bank10 << 0x10) + 0xA20A, value36 & 0x7F);
        BUS8_SET(c, 0x004200, 1);
        uint16_t value37 = BUS16_RDP(c, (data_bank10 << 0x10) + 0xA21D);
        RAM16_SET(0x0102, value37);
        uint16_t value38 = BUS16_RDP(c, (data_bank10 << 0x10) + 0xA21B);
        RAM16_SET(0x0100, value38);
        RAM8(0x1D05) = 1;
        RAM8(0xA162) = 0;
        RAM8(0x1D04) = 0;
        RAM8(0x1D00) = 0;
        uint8_t value39 = BUS8_RDP(c, (data_bank10 << 0x10) + 0xA21F);
        RAM8(0x19FE) = value39;
        uint8_t value40 = RAM8(0xCFF6);
        bool m_flag2;
        bool x_flag8;
        uint8_t a_hi14;
        uint16_t x12;
        uint16_t y12;
        bool carry12;
        bool zero2;
        bool negative2;
        bool overflow12;
        if (value40 == 0) {
            m_flag2 = 1;
            x_flag8 = x_ret42;
            a_hi14 = value38 >> 8;
            x12 = x_ret41;
            y12 = y_ret20;
            carry12 = carry11;
            zero2 = value40 == 0;
            negative2 = value40 & 0x80;
            overflow12 = overflow11;
        } else {
            r->a = (value38 >> 8 << 8) | value40;
            r->z = value40 == 0;
            r->n = value40 & 0x80;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSL(c, 0x1E8F, 0xC7D000); GUARD_JSL(c, sp_call, 0x1E8F); } /* saved_flag_menu_exception_pha_asl_brk_prefix */
            r->sp += 4;
            bool m_ret8 = r->mf;
            bool x_ret43 = r->xf;
            uint16_t a_all32 = r->a;
            uint16_t x_ret44 = r->x;
            uint16_t y_ret21 = r->y;
            bool carry_ret28 = r->c;
            bool zero_ret32 = r->z;
            bool negative_ret32 = r->n;
            bool overflow_ret18 = r->v;
            m_flag2 = m_ret8;
            x_flag8 = x_ret43;
            a_hi14 = a_all32 >> 8;
            x12 = x_ret44;
            y12 = y_ret21;
            carry12 = carry_ret28;
            zero2 = zero_ret32;
            negative2 = negative_ret32;
            overflow12 = overflow_ret18;
        }
        if (som_exit_arrive(c, 0xC01E90)) {
            r->a = (a_hi14 << 8) | (uint8_t)a;
            r->x = x12;
            r->y = y12;
            r->c = carry12;
            r->z = zero2;
            r->n = negative2;
            r->v = overflow12;
            r->mf = m_flag2;
            r->xf = x_flag8;
            r->sp -= 4;
            c->cpu.k = 0xC0; c->cpu.pc = 0x1E90; c->exited = 1;
            return;
        }
        uint8_t value41 = RAM8(0x0000 + sp0 - 3);
        uint8_t value42 = RAM8(0x0000 + sp0 - 2);
        uint8_t value43 = RAM8(0x0000 + sp0 - 1);
        uint8_t value44 = RAM8(0x0000 + sp0);
        r->a = (a_hi14 << 8) | (uint8_t)a;
        r->x = x12;
        r->y = y12;
        r->c = value44 & 0x01;
        r->z = value44 & 0x02;
        r->n = value44 & 0x80;
        r->v = value44 & 0x40;
        r->mf = value44 & 0x20;
        r->xf = value44 & 0x10;
        r->db = value43;
        r->dp = (value42 << 8) | value41;
        r->i = value44 & 0x04;
        r->d = value44 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
}
SOM_REGISTER(0xC01D97, SOM_RTL, "gen", run_native_menu_coordinator_before_exceptional_callback, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 9, -1, -1, 253, 103)
