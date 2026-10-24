#include "som_c.h"

/* C00A8D expand_dialogue_window_corners_in_four_steps   [class B, 144 bytes, 50 instructions]
 * Source: src/rom/expand_dialogue_window_corners_in_four_steps.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void expand_dialogue_window_corners_in_four_steps(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA156) = RAM8(0xA165);
    uint8_t value2 = RAM8(0xA166);
    RAM8(0xA157) = value2;
    r->a = (a_hi << 8) | value2;
    r->x = 0x0120;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0A9E, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A9E); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret << 0x10) + 0xA156, (uint8_t)(value3 + 1));
    r->x = 0x8120;
    r->z = 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0AA7, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0AA7); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    uint8_t value4 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA157);
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA157, (uint8_t)(value4 - 1));
    uint8_t value5 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA157);
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA166, value5);
    uint8_t value6 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA164);
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA164, (uint8_t)(value6 - 1));
    bool x_flag3;
    uint8_t a3;
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y3;
    bool carry3;
    bool zero4;
    bool negative4;
    bool overflow3;
    uint8_t data_bank3;
    uint16_t direct_page3;
    if ((uint8_t)(value6 - 1) == 0) {
        uint8_t value7 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA15C);
        BUS8_SET(c, (db_ret2 << 0x10) + 0xA15C, (uint8_t)(value7 + 1));
        x_flag3 = 0;
        a3 = value5;
        a_hi3 = a_all2 >> 8;
        x3 = x_ret2;
        y3 = y_ret2;
        carry3 = carry_ret2;
        zero4 = (uint8_t)(value7 + 1) == 0;
        negative4 = (uint8_t)(value7 + 1) & 0x80;
        overflow3 = overflow_ret2;
        data_bank3 = db_ret2;
        direct_page3 = dp_ret2;
    } else {
        r->a = (a_all2 >> 8 << 8) | value5;
        r->x = 0x8120;
        r->z = 0;
        r->n = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0ABB, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0ABB); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        uint8_t db_ret3 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint8_t value8 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret3 << 0x10) + 0xA156, (uint8_t)(value8 - 1));
        r->x = 0x0120;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0AC4, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0AC4); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all4 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret4 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        uint8_t value9 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret4 << 0x10) + 0xA157, (uint8_t)(value9 - 1));
        uint8_t value10 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret4 << 0x10) + 0xA166, value10);
        uint8_t value11 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA164);
        BUS8_SET(c, (db_ret4 << 0x10) + 0xA164, (uint8_t)(value11 - 1));
        bool x_flag2;
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool carry2;
        bool zero3;
        bool negative3;
        bool overflow2;
        uint8_t data_bank2;
        uint16_t direct_page2;
        if ((uint8_t)(value11 - 1) == 0) {
            uint8_t value12 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA15C);
            BUS8_SET(c, (db_ret4 << 0x10) + 0xA15C, (uint8_t)(value12 + 1));
            x_flag2 = 0;
            a2 = value10;
            a_hi2 = a_all4 >> 8;
            x2 = x_ret4;
            y2 = y_ret4;
            carry2 = carry_ret4;
            zero3 = (uint8_t)(value12 + 1) == 0;
            negative3 = (uint8_t)(value12 + 1) & 0x80;
            overflow2 = overflow_ret4;
            data_bank2 = db_ret4;
            direct_page2 = dp_ret4;
        } else {
            uint8_t value13 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA165);
            BUS8_SET(c, (db_ret4 << 0x10) + 0xA156, value13);
            uint8_t value14 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA168);
            BUS8_SET(c, (db_ret4 << 0x10) + 0xA157, value14);
            r->a = (a_all4 >> 8 << 8) | value14;
            r->x = 0x0120;
            r->z = 0;
            r->n = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0AE4, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0AE4); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            uint8_t db_ret5 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint8_t value15 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA156);
            BUS8_SET(c, (db_ret5 << 0x10) + 0xA156, (uint8_t)(value15 + 1));
            r->x = 0x8120;
            r->z = 0;
            r->n = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0AED, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0AED); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            uint16_t dp_ret6 = r->dp;
            uint8_t db_ret6 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all6 = r->a;
            uint16_t x_ret6 = r->x;
            uint16_t y_ret6 = r->y;
            bool carry_ret6 = r->c;
            bool overflow_ret6 = r->v;
            uint8_t value16 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xA157);
            BUS8_SET(c, (db_ret6 << 0x10) + 0xA157, (uint8_t)(value16 + 1));
            uint8_t value17 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xA157);
            BUS8_SET(c, (db_ret6 << 0x10) + 0xA168, value17);
            uint8_t value18 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xA164);
            BUS8_SET(c, (db_ret6 << 0x10) + 0xA164, (uint8_t)(value18 - 1));
            bool x_flag;
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t x1;
            uint16_t y1;
            bool carry1;
            bool zero2;
            bool negative2;
            bool overflow1;
            uint8_t data_bank;
            uint16_t direct_page;
            if ((uint8_t)(value18 - 1) == 0) {
                uint8_t value19 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret6 << 0x10) + 0xA15C, (uint8_t)(value19 + 1));
                x_flag = 0;
                a1 = value17;
                a_hi1 = a_all6 >> 8;
                x1 = x_ret6;
                y1 = y_ret6;
                carry1 = carry_ret6;
                zero2 = (uint8_t)(value19 + 1) == 0;
                negative2 = (uint8_t)(value19 + 1) & 0x80;
                overflow1 = overflow_ret6;
                data_bank = db_ret6;
                direct_page = dp_ret6;
            } else {
                r->a = (a_all6 >> 8 << 8) | value17;
                r->x = 0x8120;
                r->z = 0;
                r->n = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0B01, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0B01); } /* exchange_dialogue_tilemap_entry_and_request_upload */
                uint8_t db_ret7 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint8_t value20 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xA156);
                BUS8_SET(c, (db_ret7 << 0x10) + 0xA156, (uint8_t)(value20 - 1));
                r->x = 0x0120;
                r->z = 0;
                r->n = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0B0A, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0B0A); } /* exchange_dialogue_tilemap_entry_and_request_upload */
                uint16_t dp_ret8 = r->dp;
                uint8_t db_ret8 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret8 = r->xf;
                uint16_t a_all8 = r->a;
                uint16_t x_ret9 = r->x;
                uint16_t y_ret8 = r->y;
                bool carry_ret8 = r->c;
                bool overflow_ret8 = r->v;
                uint8_t value21 = BUS8_RDP(c, (db_ret8 << 0x10) + 0xA157);
                BUS8_SET(c, (db_ret8 << 0x10) + 0xA157, (uint8_t)(value21 + 1));
                uint8_t value22 = BUS8_RDP(c, (db_ret8 << 0x10) + 0xA157);
                BUS8_SET(c, (db_ret8 << 0x10) + 0xA168, value22);
                uint8_t value23 = BUS8_RDP(c, (db_ret8 << 0x10) + 0xA164);
                BUS8_SET(c, (db_ret8 << 0x10) + 0xA164, (uint8_t)(value23 - 1));
                bool zero1;
                bool negative1;
                if ((uint8_t)(value23 - 1) != 0) {
                    zero1 = (uint8_t)(value23 - 1) == 0;
                    negative1 = (uint8_t)(value23 - 1) & 0x80;
                } else {
                    uint8_t value24 = BUS8_RDP(c, (db_ret8 << 0x10) + 0xA15C);
                    BUS8_SET(c, (db_ret8 << 0x10) + 0xA15C, (uint8_t)(value24 + 1));
                    zero1 = (uint8_t)(value24 + 1) == 0;
                    negative1 = (uint8_t)(value24 + 1) & 0x80;
                }
                x_flag = x_ret8;
                a1 = value22;
                a_hi1 = a_all8 >> 8;
                x1 = x_ret9;
                y1 = y_ret8;
                carry1 = carry_ret8;
                zero2 = zero1;
                negative2 = negative1;
                overflow1 = overflow_ret8;
                data_bank = db_ret8;
                direct_page = dp_ret8;
            }
            x_flag2 = x_flag;
            a2 = a1;
            a_hi2 = a_hi1;
            x2 = x1;
            y2 = y1;
            carry2 = carry1;
            zero3 = zero2;
            negative3 = negative2;
            overflow2 = overflow1;
            data_bank2 = data_bank;
            direct_page2 = direct_page;
        }
        x_flag3 = x_flag2;
        a3 = a2;
        a_hi3 = a_hi2;
        x3 = x2;
        y3 = y2;
        carry3 = carry2;
        zero4 = zero3;
        negative4 = negative3;
        overflow3 = overflow2;
        data_bank3 = data_bank2;
        direct_page3 = direct_page2;
    }
    r->a = (a_hi3 << 8) | a3;
    r->x = x3;
    r->y = y3;
    r->c = carry3;
    r->z = zero4;
    r->n = negative4;
    r->v = overflow3;
    r->xf = x_flag3;
    r->db = data_bank3;
    r->dp = direct_page3;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00A8D, SOM_RTS, "gen", expand_dialogue_window_corners_in_four_steps, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 144, 50)
