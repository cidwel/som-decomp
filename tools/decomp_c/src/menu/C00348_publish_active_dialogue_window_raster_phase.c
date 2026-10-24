#include "som_c.h"

/* C00348 publish_active_dialogue_window_raster_phase   [class B, 199 bytes, 82 instructions]
 * Source: src/rom/publish_active_dialogue_window_raster_phase.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void publish_active_dialogue_window_raster_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint8_t a_hi_036d = 0;
    uint16_t y_036d = 0;
    uint8_t a_hi_036a = 0;
    uint16_t x_036a = 0;
    uint16_t y_036a = 0;
    uint8_t a_hi_0389 = 0;
    uint16_t y_0389 = 0;
    uint16_t direct_page_0389 = 0;
    uint8_t data_bank_0389 = 0;
    uint8_t a_hi_0386 = 0;
    uint16_t y_0386 = 0;
    uint8_t a_hi_03b6 = 0;
    uint8_t y_03b6 = 0;
    bool overflow_03b6 = 0;
    uint16_t direct_page_03b6 = 0;
    uint8_t data_bank_03b6 = 0;
    uint8_t a_hi_03b62 = 0;
    uint16_t y_03b62 = 0;
    bool overflow_03b62 = 0;
    uint16_t direct_page_03b62 = 0;
    uint8_t data_bank_03b62 = 0;
    uint8_t a_hi_03892 = 0;
    uint8_t y_03892 = 0;
    uint16_t direct_page_03892 = 0;
    uint8_t data_bank_03892 = 0;
    if (RAM8(0xA162) != 1) {
        a_hi_036d = a_hi;
        y_036d = 0;
        goto shared_036D;
    }
    if (RAM8(0xA16F) == 0) {
        if (RAM8(0xA15C) >= 5) {
            a_hi_036d = a_hi;
            y_036d = 0;
            goto shared_036D;
        }
        a_hi_036a = a_hi;
        x_036a = 0;
        y_036a = 0;
        goto shared_036A;
    }
    if (RAM8(0xA15C) >= 3) {
        a_hi_036d = a_hi;
        y_036d = 0;
        goto shared_036D;
    }
    a_hi_036a = a_hi;
    x_036a = 0;
    y_036a = 0;
    shared_036A:;
    r->a = (a_hi_036a << 8) | a;
    r->x = x_036a;
    r->y = y_036a;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x036C, 0xC00435); GUARD_JSR(c, sp_call, 0x036C); } /* clear_dialogue_window_tile_run_and_advance_destination */
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    a_hi_036d = a_all >> 8;
    y_036d = y_ret;
    goto shared_036D;
    shared_036D:;
    uint16_t value5 = RAM16(0xA1A0);
    RAM8(0x0000 + sp0) = value5 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value5;
    if (RAM8(0xA16F) == 0) {
        if (RAM8(0xA15C) >= 5) {
            a_hi_0389 = a_hi_036d;
            y_0389 = y_036d;
            direct_page_0389 = 0;
            data_bank_0389 = 0x7E;
            goto shared_0389;
        }
        a_hi_0386 = a_hi_036d;
        y_0386 = y_036d;
        goto shared_0386;
    }
    if (RAM8(0xA15C) >= 3) {
        a_hi_0389 = a_hi_036d;
        y_0389 = y_036d;
        direct_page_0389 = 0;
        data_bank_0389 = 0x7E;
        goto shared_0389;
    }
    a_hi_0386 = a_hi_036d;
    y_0386 = y_036d;
    goto shared_0386;
    shared_0389:;
    uint8_t value9 = BUS8_RDP(c, (data_bank_0389 << 0x10) + 0xA16C);
    BUS8_SET(c, (data_bank_0389 << 0x10) + 0xA164, (value9 >> 1) + (value9 & 1));
    uint16_t value10 = BUS16_RDP(c, (data_bank_0389 << 0x10) + 0xA182);
    BUS16_SET(c, (data_bank_0389 << 0x10) + 0xA1A0, value10);
    BUS8_SET(c, (data_bank_0389 << 0x10) + 0xA16D, 0);
    BUS8_SET(c, (data_bank_0389 << 0x10) + 0xA171, 0);
    r->a = (a_hi_0389 << 8) | (value9 >> 1) + (value9 & 1);
    r->x = value10;
    r->y = y_0389;
    r->c = (value9 >> 1) + (value9 & 1) > 0xFF;
    r->z = value10 == 0;
    r->n = value10 & 0x8000;
    r->v = (((value9 >> 1) ^ (value9 >> 1) + (value9 & 1)) & (value9 >> 1) + (value9 & 1) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_0389;
    r->dp = direct_page_0389;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x03A0, 0xC0044C); GUARD_JSR(c, sp_call, 0x03A0); } /* draw_dialogue_window_fill_tile_pairs */
    r->sp += 2;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret2 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    bool overflow_ret = r->v;
    uint8_t value11 = BUS8_RDP(c, (db_ret << 0x10) + 0xA16F);
    if (value11 == 0) {
        uint8_t value12 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15C);
        if (value12 < 5) {
            if (x_ret2) {
                c->fail = 3;
                return;
            } else {
                uint8_t value18 = RAM8(0x0000 + sp0 - 1);
                uint8_t value19 = RAM8(0x0000 + sp0);
                BUS16_SET(c, (db_ret << 0x10) + 0xA1A0, (value19 << 8) | value18);
                r->a = (a_all2 >> 8 << 8) | value12;
                r->x = (value19 << 8) | value18;
                r->c = value12 >= 5;
                r->z = ((value19 << 8) | value18) == 0;
                r->n = ((value19 << 8) | value18) & 0x8000;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x03C3, 0xC00D7F); GUARD_JSR(c, sp_call, 0x03C3); } /* request_dialogue_window_transfer_of_256_bytes */
                uint16_t value20 = BUS16_RDP(c, (db_ret << 0x10) + 0xA15C);
                uint16_t value21 = BUS16(c, 0xC01102 + (uint16_t)((uint16_t)((value20 & 0xFF) - 1) << 1));
                RAM16_SET(0x1D06, value21);
                uint8_t value22 = BUS8_RDP(c, (db_ret << 0x10) + 0xA16F);
                if (value22 == 0) {
                    r->a = (value21 >> 8 << 8) | 7;
                    r->x = (uint16_t)((uint16_t)((value20 & 0xFF) - 1) << 1);
                    r->c = (uint16_t)((value20 & 0xFF) - 1) & 0x8000;
                    r->z = 0;
                    r->n = 0;
                    r->mf = 1;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
                    uint8_t value23 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15C);
                    BUS8_SET(c, (db_ret << 0x10) + 0xA15C, (uint8_t)(value23 + 1));
                    r->z = (uint8_t)(value23 + 1) == 0;
                    r->n = (uint8_t)(value23 + 1) & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint8_t value24 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15C);
                if (value24 != 2) {
                    uint16_t value25 = BUS16_RDP(c, (db_ret << 0x10) + 0xA15C);
                    uint16_t value26 = BUS16(c, 0xC01112 + (uint16_t)((uint16_t)((value25 & 0xFF) - 1) << 1));
                    RAM16_SET(0x1D06, value26);
                    RAM16_SET(0x1D18, 0x0180);
                    r->a = 0x0107;
                    r->x = (uint16_t)((uint16_t)((value25 & 0xFF) - 1) << 1);
                    r->c = (uint16_t)((value25 & 0xFF) - 1) & 0x8000;
                    r->z = 0;
                    r->n = 0;
                    r->mf = 1;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
                    uint8_t value27 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15C);
                    BUS8_SET(c, (db_ret << 0x10) + 0xA15C, (uint8_t)(value27 + 1));
                    r->z = (uint8_t)(value27 + 1) == 0;
                    r->n = (uint8_t)(value27 + 1) & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint8_t value28 = BUS8_RDP(c, (db_ret << 0x10) + 0xA186);
                BUS8_SET(c, (db_ret << 0x10) + 0xA186, value28 | 1);
                uint16_t value29 = BUS16_RDP(c, (db_ret << 0x10) + 0xA15C);
                uint16_t value30 = BUS16(c, 0xC01112 + (uint16_t)((uint16_t)((value29 & 0xFF) - 1) << 1));
                RAM16_SET(0x1D06, value30);
                RAM16_SET(0x1D18, 0x0180);
                r->a = 0x0107;
                r->x = (uint16_t)((uint16_t)((value29 & 0xFF) - 1) << 1);
                r->c = (uint16_t)((value29 & 0xFF) - 1) & 0x8000;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
                uint8_t value31 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret << 0x10) + 0xA15C, (uint8_t)(value31 + 1));
                r->z = (uint8_t)(value31 + 1) == 0;
                r->n = (uint8_t)(value31 + 1) & 0x80;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
        }
        if (x_ret2) {
            a_hi_03b6 = a_all2 >> 8;
            y_03b6 = (uint8_t)y_ret2;
            overflow_03b6 = overflow_ret;
            direct_page_03b6 = dp_ret;
            data_bank_03b6 = db_ret;
            goto shared_03B6;
        } else {
            a_hi_03b62 = a_all2 >> 8;
            y_03b62 = y_ret2;
            overflow_03b62 = overflow_ret;
            direct_page_03b62 = dp_ret;
            data_bank_03b62 = db_ret;
            goto shared_03B6_1;
        }
    }
    uint8_t value32 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15C);
    if (value32 < 3) {
        if (x_ret2) {
            c->fail = 3;
            return;
        } else {
            uint8_t value38 = RAM8(0x0000 + sp0 - 1);
            uint8_t value39 = RAM8(0x0000 + sp0);
            BUS16_SET(c, (db_ret << 0x10) + 0xA1A0, (value39 << 8) | value38);
            r->a = (a_all2 >> 8 << 8) | value32;
            r->x = (value39 << 8) | value38;
            r->c = value32 >= 3;
            r->z = ((value39 << 8) | value38) == 0;
            r->n = ((value39 << 8) | value38) & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x03C3, 0xC00D7F); GUARD_JSR(c, sp_call, 0x03C3); } /* request_dialogue_window_transfer_of_256_bytes */
            uint16_t value40 = BUS16_RDP(c, (db_ret << 0x10) + 0xA15C);
            uint16_t value41 = BUS16(c, 0xC01102 + (uint16_t)((uint16_t)((value40 & 0xFF) - 1) << 1));
            RAM16_SET(0x1D06, value41);
            uint8_t value42 = BUS8_RDP(c, (db_ret << 0x10) + 0xA16F);
            if (value42 == 0) {
                r->a = (value41 >> 8 << 8) | 7;
                r->x = (uint16_t)((uint16_t)((value40 & 0xFF) - 1) << 1);
                r->c = (uint16_t)((value40 & 0xFF) - 1) & 0x8000;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
                uint8_t value43 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret << 0x10) + 0xA15C, (uint8_t)(value43 + 1));
                r->z = (uint8_t)(value43 + 1) == 0;
                r->n = (uint8_t)(value43 + 1) & 0x80;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t value44 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15C);
            if (value44 != 2) {
                uint16_t value45 = BUS16_RDP(c, (db_ret << 0x10) + 0xA15C);
                uint16_t value46 = BUS16(c, 0xC01112 + (uint16_t)((uint16_t)((value45 & 0xFF) - 1) << 1));
                RAM16_SET(0x1D06, value46);
                RAM16_SET(0x1D18, 0x0180);
                r->a = 0x0107;
                r->x = (uint16_t)((uint16_t)((value45 & 0xFF) - 1) << 1);
                r->c = (uint16_t)((value45 & 0xFF) - 1) & 0x8000;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
                uint8_t value47 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret << 0x10) + 0xA15C, (uint8_t)(value47 + 1));
                r->z = (uint8_t)(value47 + 1) == 0;
                r->n = (uint8_t)(value47 + 1) & 0x80;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t value48 = BUS8_RDP(c, (db_ret << 0x10) + 0xA186);
            BUS8_SET(c, (db_ret << 0x10) + 0xA186, value48 | 1);
            uint16_t value49 = BUS16_RDP(c, (db_ret << 0x10) + 0xA15C);
            uint16_t value50 = BUS16(c, 0xC01112 + (uint16_t)((uint16_t)((value49 & 0xFF) - 1) << 1));
            RAM16_SET(0x1D06, value50);
            RAM16_SET(0x1D18, 0x0180);
            r->a = 0x0107;
            r->x = (uint16_t)((uint16_t)((value49 & 0xFF) - 1) << 1);
            r->c = (uint16_t)((value49 & 0xFF) - 1) & 0x8000;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
            uint8_t value51 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15C);
            BUS8_SET(c, (db_ret << 0x10) + 0xA15C, (uint8_t)(value51 + 1));
            r->z = (uint8_t)(value51 + 1) == 0;
            r->n = (uint8_t)(value51 + 1) & 0x80;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
    if (x_ret2) {
        a_hi_03b6 = a_all2 >> 8;
        y_03b6 = (uint8_t)y_ret2;
        overflow_03b6 = overflow_ret;
        direct_page_03b6 = dp_ret;
        data_bank_03b6 = db_ret;
        goto shared_03B6;
    } else {
        a_hi_03b62 = a_all2 >> 8;
        y_03b62 = y_ret2;
        overflow_03b62 = overflow_ret;
        direct_page_03b62 = dp_ret;
        data_bank_03b62 = db_ret;
        goto shared_03B6_1;
    }
    shared_0386:;
    r->y = y_0386;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0388, 0xC00413); GUARD_JSR(c, sp_call, 0x0388); } /* draw_dialogue_window_end_tile_for_current_style */
    r->sp += 2;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret4 = r->xf;
    uint16_t a_all15 = r->a;
    uint16_t y_ret3 = r->y;
    if (x_ret4) {
        a_hi_03892 = a_all15 >> 8;
        y_03892 = (uint8_t)y_ret3;
        direct_page_03892 = dp_ret2;
        data_bank_03892 = db_ret2;
        goto shared_0389_1;
    } else {
        a_hi_0389 = a_all15 >> 8;
        y_0389 = y_ret3;
        direct_page_0389 = dp_ret2;
        data_bank_0389 = db_ret2;
        goto shared_0389;
    }
    shared_03B6:;
    r->y = y_03b6;
    r->v = overflow_03b6;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_03b6;
    r->dp = direct_page_03b6;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x03B8, 0xC00413); GUARD_JSR(c, sp_call, 0x03B8); } /* draw_dialogue_window_end_tile_for_current_style */
    r->sp += 2;
    uint8_t db_ret3 = r->db;
    bool x_ret6 = r->xf;
    uint16_t y_ret4 = r->y;
    if (x_ret6) {
        c->fail = 3;
        return;
    } else {
        r->x = y_ret4;
        r->z = y_ret4 == 0;
        r->n = y_ret4 & 0x8000;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x03BC, 0xC00435); GUARD_JSR(c, sp_call, 0x03BC); } /* clear_dialogue_window_tile_run_and_advance_destination */
        r->sp += 2;
        uint8_t value57 = RAM8(0x0000 + sp0 - 1);
        uint8_t value58 = RAM8(0x0000 + sp0);
        BUS16_SET(c, (db_ret3 << 0x10) + 0xA1A0, (value58 << 8) | value57);
        r->x = (value58 << 8) | value57;
        r->z = ((value58 << 8) | value57) == 0;
        r->n = ((value58 << 8) | value57) & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x03C3, 0xC00D7F); GUARD_JSR(c, sp_call, 0x03C3); } /* request_dialogue_window_transfer_of_256_bytes */
        uint16_t value59 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA15C);
        uint16_t value60 = BUS16(c, 0xC01102 + (uint16_t)((uint16_t)((value59 & 0xFF) - 1) << 1));
        RAM16_SET(0x1D06, value60);
        uint8_t value61 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA16F);
        if (value61 == 0) {
            r->a = (value60 >> 8 << 8) | 7;
            r->x = (uint16_t)((uint16_t)((value59 & 0xFF) - 1) << 1);
            r->c = (uint16_t)((value59 & 0xFF) - 1) & 0x8000;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
            uint8_t value62 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA15C);
            BUS8_SET(c, (db_ret3 << 0x10) + 0xA15C, (uint8_t)(value62 + 1));
            r->z = (uint8_t)(value62 + 1) == 0;
            r->n = (uint8_t)(value62 + 1) & 0x80;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint8_t value63 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA15C);
        if (value63 != 2) {
            uint16_t value64 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA15C);
            uint16_t value65 = BUS16(c, 0xC01112 + (uint16_t)((uint16_t)((value64 & 0xFF) - 1) << 1));
            RAM16_SET(0x1D06, value65);
            RAM16_SET(0x1D18, 0x0180);
            r->a = 0x0107;
            r->x = (uint16_t)((uint16_t)((value64 & 0xFF) - 1) << 1);
            r->c = (uint16_t)((value64 & 0xFF) - 1) & 0x8000;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
            uint8_t value66 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA15C);
            BUS8_SET(c, (db_ret3 << 0x10) + 0xA15C, (uint8_t)(value66 + 1));
            r->z = (uint8_t)(value66 + 1) == 0;
            r->n = (uint8_t)(value66 + 1) & 0x80;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint8_t value67 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA186);
        BUS8_SET(c, (db_ret3 << 0x10) + 0xA186, value67 | 1);
        uint16_t value68 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA15C);
        uint16_t value69 = BUS16(c, 0xC01112 + (uint16_t)((uint16_t)((value68 & 0xFF) - 1) << 1));
        RAM16_SET(0x1D06, value69);
        RAM16_SET(0x1D18, 0x0180);
        r->a = 0x0107;
        r->x = (uint16_t)((uint16_t)((value68 & 0xFF) - 1) << 1);
        r->c = (uint16_t)((value68 & 0xFF) - 1) & 0x8000;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
        uint8_t value70 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA15C);
        BUS8_SET(c, (db_ret3 << 0x10) + 0xA15C, (uint8_t)(value70 + 1));
        r->z = (uint8_t)(value70 + 1) == 0;
        r->n = (uint8_t)(value70 + 1) & 0x80;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    shared_03B6_1:;
    r->y = y_03b62;
    r->v = overflow_03b62;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_03b62;
    r->dp = direct_page_03b62;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x03B8, 0xC00413); GUARD_JSR(c, sp_call, 0x03B8); } /* draw_dialogue_window_end_tile_for_current_style */
    r->sp += 2;
    uint8_t db_ret4 = r->db;
    bool x_ret10 = r->xf;
    uint16_t y_ret7 = r->y;
    if (x_ret10) {
        c->fail = 3;
        return;
    } else {
        r->x = y_ret7;
        r->z = y_ret7 == 0;
        r->n = y_ret7 & 0x8000;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x03BC, 0xC00435); GUARD_JSR(c, sp_call, 0x03BC); } /* clear_dialogue_window_tile_run_and_advance_destination */
        r->sp += 2;
        uint8_t value76 = RAM8(0x0000 + sp0 - 1);
        uint8_t value77 = RAM8(0x0000 + sp0);
        BUS16_SET(c, (db_ret4 << 0x10) + 0xA1A0, (value77 << 8) | value76);
        r->x = (value77 << 8) | value76;
        r->z = ((value77 << 8) | value76) == 0;
        r->n = ((value77 << 8) | value76) & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x03C3, 0xC00D7F); GUARD_JSR(c, sp_call, 0x03C3); } /* request_dialogue_window_transfer_of_256_bytes */
        uint16_t value78 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xA15C);
        uint16_t value79 = BUS16(c, 0xC01102 + (uint16_t)((uint16_t)((value78 & 0xFF) - 1) << 1));
        RAM16_SET(0x1D06, value79);
        uint8_t value80 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA16F);
        if (value80 == 0) {
            r->a = (value79 >> 8 << 8) | 7;
            r->x = (uint16_t)((uint16_t)((value78 & 0xFF) - 1) << 1);
            r->c = (uint16_t)((value78 & 0xFF) - 1) & 0x8000;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
            uint8_t value81 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA15C);
            BUS8_SET(c, (db_ret4 << 0x10) + 0xA15C, (uint8_t)(value81 + 1));
            r->z = (uint8_t)(value81 + 1) == 0;
            r->n = (uint8_t)(value81 + 1) & 0x80;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint8_t value82 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA15C);
        if (value82 != 2) {
            uint16_t value83 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xA15C);
            uint16_t value84 = BUS16(c, 0xC01112 + (uint16_t)((uint16_t)((value83 & 0xFF) - 1) << 1));
            RAM16_SET(0x1D06, value84);
            RAM16_SET(0x1D18, 0x0180);
            r->a = 0x0107;
            r->x = (uint16_t)((uint16_t)((value83 & 0xFF) - 1) << 1);
            r->c = (uint16_t)((value83 & 0xFF) - 1) & 0x8000;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
            uint8_t value85 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA15C);
            BUS8_SET(c, (db_ret4 << 0x10) + 0xA15C, (uint8_t)(value85 + 1));
            r->z = (uint8_t)(value85 + 1) == 0;
            r->n = (uint8_t)(value85 + 1) & 0x80;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint8_t value86 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA186);
        BUS8_SET(c, (db_ret4 << 0x10) + 0xA186, value86 | 1);
        uint16_t value87 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xA15C);
        uint16_t value88 = BUS16(c, 0xC01112 + (uint16_t)((uint16_t)((value87 & 0xFF) - 1) << 1));
        RAM16_SET(0x1D06, value88);
        RAM16_SET(0x1D18, 0x0180);
        r->a = 0x0107;
        r->x = (uint16_t)((uint16_t)((value87 & 0xFF) - 1) << 1);
        r->c = (uint16_t)((value87 & 0xFF) - 1) & 0x8000;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
        uint8_t value89 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA15C);
        BUS8_SET(c, (db_ret4 << 0x10) + 0xA15C, (uint8_t)(value89 + 1));
        r->z = (uint8_t)(value89 + 1) == 0;
        r->n = (uint8_t)(value89 + 1) & 0x80;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    shared_0389_1:;
    uint8_t value90 = BUS8_RDP(c, (data_bank_03892 << 0x10) + 0xA16C);
    BUS8_SET(c, (data_bank_03892 << 0x10) + 0xA164, (value90 >> 1) + (value90 & 1));
    uint8_t value91 = BUS8_RDP(c, (data_bank_03892 << 0x10) + 0xA182);
    BUS8_SET(c, (data_bank_03892 << 0x10) + 0xA1A0, value91);
    BUS8_SET(c, (data_bank_03892 << 0x10) + 0xA16D, 0);
    BUS8_SET(c, (data_bank_03892 << 0x10) + 0xA171, 0);
    r->a = (a_hi_03892 << 8) | (value90 >> 1) + (value90 & 1);
    r->x = value91;
    r->y = y_03892;
    r->c = (value90 >> 1) + (value90 & 1) > 0xFF;
    r->z = value91 == 0;
    r->n = value91 & 0x80;
    r->v = (((value90 >> 1) ^ (value90 >> 1) + (value90 & 1)) & (value90 >> 1) + (value90 & 1) & 0x80) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_03892;
    r->dp = direct_page_03892;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x03A0, 0xC0044C); GUARD_JSR(c, sp_call, 0x03A0); } /* draw_dialogue_window_fill_tile_pairs */
    r->sp += 2;
    uint16_t dp_ret5 = r->dp;
    uint8_t db_ret5 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret14 = r->xf;
    uint16_t a_all34 = r->a;
    uint16_t y_ret10 = r->y;
    bool overflow_ret5 = r->v;
    uint8_t value92 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA16F);
    if (value92 == 0) {
        uint8_t value93 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA15C);
        if (value93 < 5) {
            if (x_ret14) {
                c->fail = 3;
                return;
            } else {
                uint8_t value99 = RAM8(0x0000 + sp0 - 1);
                uint8_t value100 = RAM8(0x0000 + sp0);
                BUS16_SET(c, (db_ret5 << 0x10) + 0xA1A0, (value100 << 8) | value99);
                r->a = (a_all34 >> 8 << 8) | value93;
                r->x = (value100 << 8) | value99;
                r->c = value93 >= 5;
                r->z = ((value100 << 8) | value99) == 0;
                r->n = ((value100 << 8) | value99) & 0x8000;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x03C3, 0xC00D7F); GUARD_JSR(c, sp_call, 0x03C3); } /* request_dialogue_window_transfer_of_256_bytes */
                uint16_t value101 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA15C);
                uint16_t value102 = BUS16(c, 0xC01102 + (uint16_t)((uint16_t)((value101 & 0xFF) - 1) << 1));
                RAM16_SET(0x1D06, value102);
                uint8_t value103 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA16F);
                if (value103 == 0) {
                    r->a = (value102 >> 8 << 8) | 7;
                    r->x = (uint16_t)((uint16_t)((value101 & 0xFF) - 1) << 1);
                    r->c = (uint16_t)((value101 & 0xFF) - 1) & 0x8000;
                    r->z = 0;
                    r->n = 0;
                    r->mf = 1;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
                    uint8_t value104 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA15C);
                    BUS8_SET(c, (db_ret5 << 0x10) + 0xA15C, (uint8_t)(value104 + 1));
                    r->z = (uint8_t)(value104 + 1) == 0;
                    r->n = (uint8_t)(value104 + 1) & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint8_t value105 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA15C);
                if (value105 != 2) {
                    uint16_t value106 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA15C);
                    uint16_t value107 = BUS16(c, 0xC01112 + (uint16_t)((uint16_t)((value106 & 0xFF) - 1) << 1));
                    RAM16_SET(0x1D06, value107);
                    RAM16_SET(0x1D18, 0x0180);
                    r->a = 0x0107;
                    r->x = (uint16_t)((uint16_t)((value106 & 0xFF) - 1) << 1);
                    r->c = (uint16_t)((value106 & 0xFF) - 1) & 0x8000;
                    r->z = 0;
                    r->n = 0;
                    r->mf = 1;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
                    uint8_t value108 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA15C);
                    BUS8_SET(c, (db_ret5 << 0x10) + 0xA15C, (uint8_t)(value108 + 1));
                    r->z = (uint8_t)(value108 + 1) == 0;
                    r->n = (uint8_t)(value108 + 1) & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint8_t value109 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA186);
                BUS8_SET(c, (db_ret5 << 0x10) + 0xA186, value109 | 1);
                uint16_t value110 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA15C);
                uint16_t value111 = BUS16(c, 0xC01112 + (uint16_t)((uint16_t)((value110 & 0xFF) - 1) << 1));
                RAM16_SET(0x1D06, value111);
                RAM16_SET(0x1D18, 0x0180);
                r->a = 0x0107;
                r->x = (uint16_t)((uint16_t)((value110 & 0xFF) - 1) << 1);
                r->c = (uint16_t)((value110 & 0xFF) - 1) & 0x8000;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
                uint8_t value112 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret5 << 0x10) + 0xA15C, (uint8_t)(value112 + 1));
                r->z = (uint8_t)(value112 + 1) == 0;
                r->n = (uint8_t)(value112 + 1) & 0x80;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
        }
        if (x_ret14) {
            a_hi_03b6 = a_all34 >> 8;
            y_03b6 = (uint8_t)y_ret10;
            overflow_03b6 = overflow_ret5;
            direct_page_03b6 = dp_ret5;
            data_bank_03b6 = db_ret5;
            goto shared_03B6;
        } else {
            a_hi_03b62 = a_all34 >> 8;
            y_03b62 = y_ret10;
            overflow_03b62 = overflow_ret5;
            direct_page_03b62 = dp_ret5;
            data_bank_03b62 = db_ret5;
            goto shared_03B6_1;
        }
    }
    uint8_t value113 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA15C);
    if (value113 < 3) {
        if (x_ret14) {
            c->fail = 3;
            return;
        } else {
            uint8_t value119 = RAM8(0x0000 + sp0 - 1);
            uint8_t value120 = RAM8(0x0000 + sp0);
            BUS16_SET(c, (db_ret5 << 0x10) + 0xA1A0, (value120 << 8) | value119);
            r->a = (a_all34 >> 8 << 8) | value113;
            r->x = (value120 << 8) | value119;
            r->c = value113 >= 3;
            r->z = ((value120 << 8) | value119) == 0;
            r->n = ((value120 << 8) | value119) & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x03C3, 0xC00D7F); GUARD_JSR(c, sp_call, 0x03C3); } /* request_dialogue_window_transfer_of_256_bytes */
            uint16_t value121 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA15C);
            uint16_t value122 = BUS16(c, 0xC01102 + (uint16_t)((uint16_t)((value121 & 0xFF) - 1) << 1));
            RAM16_SET(0x1D06, value122);
            uint8_t value123 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA16F);
            if (value123 == 0) {
                r->a = (value122 >> 8 << 8) | 7;
                r->x = (uint16_t)((uint16_t)((value121 & 0xFF) - 1) << 1);
                r->c = (uint16_t)((value121 & 0xFF) - 1) & 0x8000;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
                uint8_t value124 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret5 << 0x10) + 0xA15C, (uint8_t)(value124 + 1));
                r->z = (uint8_t)(value124 + 1) == 0;
                r->n = (uint8_t)(value124 + 1) & 0x80;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t value125 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA15C);
            if (value125 != 2) {
                uint16_t value126 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA15C);
                uint16_t value127 = BUS16(c, 0xC01112 + (uint16_t)((uint16_t)((value126 & 0xFF) - 1) << 1));
                RAM16_SET(0x1D06, value127);
                RAM16_SET(0x1D18, 0x0180);
                r->a = 0x0107;
                r->x = (uint16_t)((uint16_t)((value126 & 0xFF) - 1) << 1);
                r->c = (uint16_t)((value126 & 0xFF) - 1) & 0x8000;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
                uint8_t value128 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret5 << 0x10) + 0xA15C, (uint8_t)(value128 + 1));
                r->z = (uint8_t)(value128 + 1) == 0;
                r->n = (uint8_t)(value128 + 1) & 0x80;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t value129 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA186);
            BUS8_SET(c, (db_ret5 << 0x10) + 0xA186, value129 | 1);
            uint16_t value130 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA15C);
            uint16_t value131 = BUS16(c, 0xC01112 + (uint16_t)((uint16_t)((value130 & 0xFF) - 1) << 1));
            RAM16_SET(0x1D06, value131);
            RAM16_SET(0x1D18, 0x0180);
            r->a = 0x0107;
            r->x = (uint16_t)((uint16_t)((value130 & 0xFF) - 1) << 1);
            r->c = (uint16_t)((value130 & 0xFF) - 1) & 0x8000;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x040A, 0xC00FFA); GUARD_JSR(c, sp_call, 0x040A); } /* request_dialogue_transfer_and_conditional_window_flags */
            uint8_t value132 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA15C);
            BUS8_SET(c, (db_ret5 << 0x10) + 0xA15C, (uint8_t)(value132 + 1));
            r->z = (uint8_t)(value132 + 1) == 0;
            r->n = (uint8_t)(value132 + 1) & 0x80;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
    if (x_ret14) {
        a_hi_03b6 = a_all34 >> 8;
        y_03b6 = (uint8_t)y_ret10;
        overflow_03b6 = overflow_ret5;
        direct_page_03b6 = dp_ret5;
        data_bank_03b6 = db_ret5;
        goto shared_03B6;
    } else {
        a_hi_03b62 = a_all34 >> 8;
        y_03b62 = y_ret10;
        overflow_03b62 = overflow_ret5;
        direct_page_03b62 = dp_ret5;
        data_bank_03b62 = db_ret5;
        goto shared_03B6_1;
    }
}
SOM_REGISTER(0xC00348, SOM_RTS, "gen", publish_active_dialogue_window_raster_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 199, 82)
