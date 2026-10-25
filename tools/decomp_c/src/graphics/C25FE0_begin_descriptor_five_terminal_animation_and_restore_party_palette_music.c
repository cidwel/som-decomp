#include "som_c.h"

/* C25FE0 begin_descriptor_five_terminal_animation_and_restore_party_palette_music   [class B, 47 bytes, 18 instructions]
 * Source: src/rom/begin_descriptor_five_terminal_animation_and_restore_party_palette_music.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void begin_descriptor_five_terminal_animation_and_restore_party_palette_music(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint64_t loop_guard = 0;
    uint8_t a_600d = 0;
    uint8_t a_hi_600d = 0;
    uint8_t x_600d = 0;
    uint8_t y_600d = 0;
    bool zero_600d = 0;
    bool negative_600d = 0;
    bool overflow_600d = 0;
    uint16_t direct_page_600d = 0;
    uint8_t data_bank_600d = 0;
    uint8_t a_600d2 = 0;
    uint8_t a_hi_600d2 = 0;
    uint8_t x_600d2 = 0;
    uint8_t y_600d2 = 0;
    bool zero_600d2 = 0;
    bool negative_600d2 = 0;
    bool overflow_600d2 = 0;
    uint16_t direct_page_600d2 = 0;
    uint8_t data_bank_600d2 = 0;
    uint8_t a_600d3 = 0;
    uint8_t a_hi_600d3 = 0;
    uint16_t x_600d3 = 0;
    uint16_t y_600d3 = 0;
    bool zero_600d3 = 0;
    bool negative_600d3 = 0;
    bool overflow_600d3 = 0;
    uint16_t direct_page_600d3 = 0;
    uint8_t data_bank_600d3 = 0;
    uint8_t a_600d4 = 0;
    uint8_t a_hi_600d4 = 0;
    uint16_t x_600d4 = 0;
    uint16_t y_600d4 = 0;
    bool zero_600d4 = 0;
    bool negative_600d4 = 0;
    bool overflow_600d4 = 0;
    uint16_t direct_page_600d4 = 0;
    uint8_t data_bank_600d4 = 0;
    uint16_t value = RAM16(0x0287);
    r->a = 0xAE;
    r->x = value;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5FE7, 0xC21394); GUARD_JSR(c, sp_call, 0x5FE7); } /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    uint16_t value2 = RAM16(OBJECT_PHASE + value);
    RAM16_SET(OBJECT_AGE + value, 0);
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5FF0, 0xC26273); GUARD_JSR(c, sp_call, 0x5FF0); } /* release_party_control_and_restore_boss_palette_music */
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    if (x_ret) {
        uint8_t value3 = RAM8(0x0287);
        uint16_t value4 = RAM16(OBJECT_AGE + value3);
        if (value4 != 0x24) {
            a_600d = (uint8_t)value4;
            a_hi_600d = value4 >> 8;
            x_600d = value3;
            y_600d = (uint8_t)y_ret;
            zero_600d = value4 == 0x24;
            negative_600d = (uint16_t)(value4 - 0x24) & 0x8000;
            overflow_600d = overflow_ret;
            direct_page_600d = 0x0200;
            data_bank_600d = 0x7E;
            goto shared_600D;
        }
        RAM16_SET(OBJECT_AGE + value3, 0);
        RAM16_SET(OBJECT_PHASE + value3, (uint16_t)(RAM16(OBJECT_PHASE + value3) + 1));
        uint16_t value5 = RAM16(0x0072 + value3);
        r->a = value5;
        r->x = value3;
        r->y = (uint8_t)y_ret;
        r->c = value4 >= 0x24;
        r->z = value5 == 0;
        r->n = value5 & 0x8000;
        r->mf = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6006, 0xC20C11); GUARD_JSR(c, sp_call, 0x6006); } /* mark_controller_and_request_numeric_boss_death_event */
        uint16_t dp_ret = r->dp;
        bool x_ret3 = r->xf;
        uint16_t y_ret2 = r->y;
        if (x_ret3) {
            uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->x = value6;
            r->y = (uint8_t)y_ret2;
            r->z = value6 == 0;
            r->n = value6 & 0x80;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x600C, 0xC0006F); GUARD_JSL(c, sp_call, 0x600C); } /* public_actor_death_jump */
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            bool m_ret2 = r->mf;
            bool x_ret5 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret6 = r->x;
            uint16_t y_ret3 = r->y;
            bool zero_ret4 = r->z;
            bool negative_ret4 = r->n;
            bool overflow_ret3 = r->v;
            if (m_ret2) {
                if (x_ret5) {
                    a_600d2 = (uint8_t)a_all4;
                    a_hi_600d2 = a_all4 >> 8;
                    x_600d2 = (uint8_t)x_ret6;
                    y_600d2 = (uint8_t)y_ret3;
                    zero_600d2 = zero_ret4;
                    negative_600d2 = negative_ret4;
                    overflow_600d2 = overflow_ret3;
                    direct_page_600d2 = dp_ret2;
                    data_bank_600d2 = db_ret2;
                    goto shared_600D_1;
                } else {
                    a_600d3 = (uint8_t)a_all4;
                    a_hi_600d3 = a_all4 >> 8;
                    x_600d3 = x_ret6;
                    y_600d3 = y_ret3;
                    zero_600d3 = zero_ret4;
                    negative_600d3 = negative_ret4;
                    overflow_600d3 = overflow_ret3;
                    direct_page_600d3 = dp_ret2;
                    data_bank_600d3 = db_ret2;
                    goto shared_600D_2;
                }
            } else {
                if (x_ret5) {
                    a_600d = (uint8_t)a_all4;
                    a_hi_600d = a_all4 >> 8;
                    x_600d = (uint8_t)x_ret6;
                    y_600d = (uint8_t)y_ret3;
                    zero_600d = zero_ret4;
                    negative_600d = negative_ret4;
                    overflow_600d = overflow_ret3;
                    direct_page_600d = dp_ret2;
                    data_bank_600d = db_ret2;
                    goto shared_600D;
                } else {
                    a_600d4 = (uint8_t)a_all4;
                    a_hi_600d4 = a_all4 >> 8;
                    x_600d4 = x_ret6;
                    y_600d4 = y_ret3;
                    zero_600d4 = zero_ret4;
                    negative_600d4 = negative_ret4;
                    overflow_600d4 = overflow_ret3;
                    direct_page_600d4 = dp_ret2;
                    data_bank_600d4 = db_ret2;
                    goto shared_600D_3;
                }
            }
        } else {
            uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->x = value7;
            r->z = value7 == 0;
            r->n = value7 & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x600C, 0xC0006F); GUARD_JSL(c, sp_call, 0x600C); } /* public_actor_death_jump */
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret3 = r->db;
            bool m_ret3 = r->mf;
            bool x_ret7 = r->xf;
            uint16_t a_all5 = r->a;
            uint16_t x_ret8 = r->x;
            uint16_t y_ret4 = r->y;
            bool zero_ret5 = r->z;
            bool negative_ret5 = r->n;
            bool overflow_ret4 = r->v;
            if (m_ret3) {
                if (x_ret7) {
                    a_600d2 = (uint8_t)a_all5;
                    a_hi_600d2 = a_all5 >> 8;
                    x_600d2 = (uint8_t)x_ret8;
                    y_600d2 = (uint8_t)y_ret4;
                    zero_600d2 = zero_ret5;
                    negative_600d2 = negative_ret5;
                    overflow_600d2 = overflow_ret4;
                    direct_page_600d2 = dp_ret3;
                    data_bank_600d2 = db_ret3;
                    goto shared_600D_1;
                } else {
                    a_600d3 = (uint8_t)a_all5;
                    a_hi_600d3 = a_all5 >> 8;
                    x_600d3 = x_ret8;
                    y_600d3 = y_ret4;
                    zero_600d3 = zero_ret5;
                    negative_600d3 = negative_ret5;
                    overflow_600d3 = overflow_ret4;
                    direct_page_600d3 = dp_ret3;
                    data_bank_600d3 = db_ret3;
                    goto shared_600D_2;
                }
            } else {
                if (x_ret7) {
                    a_600d = (uint8_t)a_all5;
                    a_hi_600d = a_all5 >> 8;
                    x_600d = (uint8_t)x_ret8;
                    y_600d = (uint8_t)y_ret4;
                    zero_600d = zero_ret5;
                    negative_600d = negative_ret5;
                    overflow_600d = overflow_ret4;
                    direct_page_600d = dp_ret3;
                    data_bank_600d = db_ret3;
                    goto shared_600D;
                } else {
                    a_600d4 = (uint8_t)a_all5;
                    a_hi_600d4 = a_all5 >> 8;
                    x_600d4 = x_ret8;
                    y_600d4 = y_ret4;
                    zero_600d4 = zero_ret5;
                    negative_600d4 = negative_ret5;
                    overflow_600d4 = overflow_ret4;
                    direct_page_600d4 = dp_ret3;
                    data_bank_600d4 = db_ret3;
                    goto shared_600D_3;
                }
            }
        }
    } else {
        uint16_t value8 = RAM16(0x0287);
        uint16_t value9 = RAM16(OBJECT_AGE + value8);
        if (value9 != 0x24) {
            a_600d4 = (uint8_t)value9;
            a_hi_600d4 = value9 >> 8;
            x_600d4 = value8;
            y_600d4 = y_ret;
            zero_600d4 = value9 == 0x24;
            negative_600d4 = (uint16_t)(value9 - 0x24) & 0x8000;
            overflow_600d4 = overflow_ret;
            direct_page_600d4 = 0x0200;
            data_bank_600d4 = 0x7E;
            goto shared_600D_3;
        }
        RAM16_SET(OBJECT_AGE + value8, 0);
        RAM16_SET(OBJECT_PHASE + value8, (uint16_t)(RAM16(OBJECT_PHASE + value8) + 1));
        uint16_t value10 = RAM16(0x0072 + value8);
        r->a = value10;
        r->x = value8;
        r->c = value9 >= 0x24;
        r->z = value10 == 0;
        r->n = value10 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6006, 0xC20C11); GUARD_JSR(c, sp_call, 0x6006); } /* mark_controller_and_request_numeric_boss_death_event */
        uint16_t dp_ret4 = r->dp;
        bool x_ret9 = r->xf;
        uint16_t y_ret5 = r->y;
        if (x_ret9) {
            uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 0x87));
            r->x = value11;
            r->y = (uint8_t)y_ret5;
            r->z = value11 == 0;
            r->n = value11 & 0x80;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x600C, 0xC0006F); GUARD_JSL(c, sp_call, 0x600C); } /* public_actor_death_jump */
            uint16_t dp_ret5 = r->dp;
            uint8_t db_ret5 = r->db;
            bool m_ret5 = r->mf;
            bool x_ret11 = r->xf;
            uint16_t a_all7 = r->a;
            uint16_t x_ret12 = r->x;
            uint16_t y_ret6 = r->y;
            bool zero_ret7 = r->z;
            bool negative_ret7 = r->n;
            bool overflow_ret6 = r->v;
            if (m_ret5) {
                if (x_ret11) {
                    a_600d2 = (uint8_t)a_all7;
                    a_hi_600d2 = a_all7 >> 8;
                    x_600d2 = (uint8_t)x_ret12;
                    y_600d2 = (uint8_t)y_ret6;
                    zero_600d2 = zero_ret7;
                    negative_600d2 = negative_ret7;
                    overflow_600d2 = overflow_ret6;
                    direct_page_600d2 = dp_ret5;
                    data_bank_600d2 = db_ret5;
                    goto shared_600D_1;
                } else {
                    a_600d3 = (uint8_t)a_all7;
                    a_hi_600d3 = a_all7 >> 8;
                    x_600d3 = x_ret12;
                    y_600d3 = y_ret6;
                    zero_600d3 = zero_ret7;
                    negative_600d3 = negative_ret7;
                    overflow_600d3 = overflow_ret6;
                    direct_page_600d3 = dp_ret5;
                    data_bank_600d3 = db_ret5;
                    goto shared_600D_2;
                }
            } else {
                if (x_ret11) {
                    a_600d = (uint8_t)a_all7;
                    a_hi_600d = a_all7 >> 8;
                    x_600d = (uint8_t)x_ret12;
                    y_600d = (uint8_t)y_ret6;
                    zero_600d = zero_ret7;
                    negative_600d = negative_ret7;
                    overflow_600d = overflow_ret6;
                    direct_page_600d = dp_ret5;
                    data_bank_600d = db_ret5;
                    goto shared_600D;
                } else {
                    a_600d4 = (uint8_t)a_all7;
                    a_hi_600d4 = a_all7 >> 8;
                    x_600d4 = x_ret12;
                    y_600d4 = y_ret6;
                    zero_600d4 = zero_ret7;
                    negative_600d4 = negative_ret7;
                    overflow_600d4 = overflow_ret6;
                    direct_page_600d4 = dp_ret5;
                    data_bank_600d4 = db_ret5;
                    goto shared_600D_3;
                }
            }
        } else {
            uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 0x87));
            r->x = value12;
            r->z = value12 == 0;
            r->n = value12 & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x600C, 0xC0006F); GUARD_JSL(c, sp_call, 0x600C); } /* public_actor_death_jump */
            uint16_t dp_ret6 = r->dp;
            uint8_t db_ret6 = r->db;
            bool m_ret6 = r->mf;
            bool x_ret13 = r->xf;
            uint16_t a_all8 = r->a;
            uint16_t x_ret14 = r->x;
            uint16_t y_ret7 = r->y;
            bool zero_ret8 = r->z;
            bool negative_ret8 = r->n;
            bool overflow_ret7 = r->v;
            if (m_ret6) {
                if (x_ret13) {
                    a_600d2 = (uint8_t)a_all8;
                    a_hi_600d2 = a_all8 >> 8;
                    x_600d2 = (uint8_t)x_ret14;
                    y_600d2 = (uint8_t)y_ret7;
                    zero_600d2 = zero_ret8;
                    negative_600d2 = negative_ret8;
                    overflow_600d2 = overflow_ret7;
                    direct_page_600d2 = dp_ret6;
                    data_bank_600d2 = db_ret6;
                    goto shared_600D_1;
                } else {
                    a_600d3 = (uint8_t)a_all8;
                    a_hi_600d3 = a_all8 >> 8;
                    x_600d3 = x_ret14;
                    y_600d3 = y_ret7;
                    zero_600d3 = zero_ret8;
                    negative_600d3 = negative_ret8;
                    overflow_600d3 = overflow_ret7;
                    direct_page_600d3 = dp_ret6;
                    data_bank_600d3 = db_ret6;
                    goto shared_600D_2;
                }
            } else {
                if (x_ret13) {
                    a_600d = (uint8_t)a_all8;
                    a_hi_600d = a_all8 >> 8;
                    x_600d = (uint8_t)x_ret14;
                    y_600d = (uint8_t)y_ret7;
                    zero_600d = zero_ret8;
                    negative_600d = negative_ret8;
                    overflow_600d = overflow_ret7;
                    direct_page_600d = dp_ret6;
                    data_bank_600d = db_ret6;
                    goto shared_600D;
                } else {
                    a_600d4 = (uint8_t)a_all8;
                    a_hi_600d4 = a_all8 >> 8;
                    x_600d4 = x_ret14;
                    y_600d4 = y_ret7;
                    zero_600d4 = zero_ret8;
                    negative_600d4 = negative_ret8;
                    overflow_600d4 = overflow_ret7;
                    direct_page_600d4 = dp_ret6;
                    data_bank_600d4 = db_ret6;
                    goto shared_600D_3;
                }
            }
        }
    }
    shared_600D:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_600d << 8) | a_600d;
    r->x = x_600d;
    r->y = y_600d;
    r->c = 0;
    r->z = zero_600d;
    r->n = negative_600d;
    r->v = overflow_600d;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_600d;
    r->dp = direct_page_600d;
    RETURN_RTS(c);
    shared_600D_1:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_600d2 << 8) | a_600d2;
    r->x = x_600d2;
    r->y = y_600d2;
    r->c = 0;
    r->z = zero_600d2;
    r->n = negative_600d2;
    r->v = overflow_600d2;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_600d2;
    r->dp = direct_page_600d2;
    RETURN_RTS(c);
    shared_600D_2:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_600d3 << 8) | a_600d3;
    r->x = x_600d3;
    r->y = y_600d3;
    r->c = 0;
    r->z = zero_600d3;
    r->n = negative_600d3;
    r->v = overflow_600d3;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_600d3;
    r->dp = direct_page_600d3;
    RETURN_RTS(c);
    shared_600D_3:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_600d4 << 8) | a_600d4;
    r->x = x_600d4;
    r->y = y_600d4;
    r->c = 0;
    r->z = zero_600d4;
    r->n = negative_600d4;
    r->v = overflow_600d4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_600d4;
    r->dp = direct_page_600d4;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25FE0, SOM_RTS, "gen", begin_descriptor_five_terminal_animation_and_restore_party_palette_music, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 47, 18)
