#include "som_c.h"

/* C007E0 restore_dialogue_style_or_publish_collapsed_window_band   [class B, 100 bytes, 44 instructions]
 * Source: src/rom/restore_dialogue_style_or_publish_collapsed_window_band.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void restore_dialogue_style_or_publish_collapsed_window_band(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xCFF8);
    uint8_t a1;
    uint8_t a_hi3;
    uint16_t x2;
    uint16_t y3;
    bool carry3;
    bool zero1;
    bool negative1;
    bool overflow3;
    uint8_t data_bank3;
    uint16_t direct_page3;
    if (value == 0) {
        uint8_t value2 = RAM8(0xA166);
        RAM8(0xA157) = value2;
        RAM8(0x0000 + sp0) = value2;
        RAM8(0xA156) = RAM8(0xA165);
        uint8_t value4 = RAM8(0xA16C);
        RAM8(0xA164) = value4;
        RAM8(0x0000 + sp0 - 1) = value4;
        uint8_t a_hi1 = a_hi;
        uint16_t y1 = y;
        bool carry1 = carry;
        bool overflow1 = overflow;
        uint8_t data_bank = 0x7E;
        uint16_t direct_page = dp;
        for (;;) {
            RAM8(0x0000 + sp0 - 2) = 1;
            RAM8(0x0000 + sp0 - 3) = 0x20;
            r->a = (a_hi1 << 8) | a;
            r->x = 0x0120;
            r->y = y1;
            r->c = carry1;
            r->z = 0;
            r->n = 0;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0813, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0813); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            r->sp += 4;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            uint8_t value7 = BUS8_RDP(c, (db_ret << 0x10) + 0xA157);
            BUS8_SET(c, (db_ret << 0x10) + 0xA157, (uint8_t)(value7 + 1));
            uint8_t value8 = BUS8_RDP(c, (db_ret << 0x10) + 0xA164);
            BUS8_SET(c, (db_ret << 0x10) + 0xA164, (uint8_t)(value8 - 1));
            a_hi1 = a_all >> 8;
            y1 = y_ret;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
            if (!((uint8_t)(value8 - 1) != 0)) break;
        }
        BUS8_SET(c, (data_bank << 0x10) + 0xA164, RAM8(0x0000 + sp0 - 1));
        BUS8_SET(c, (data_bank << 0x10) + 0xA157, RAM8(0x0000 + sp0));
        uint8_t value11 = BUS8_RDP(c, (data_bank << 0x10) + 0xA156);
        BUS8_SET(c, (data_bank << 0x10) + 0xA156, (uint8_t)(value11 + 1));
        uint8_t a_hi2 = a_hi1;
        uint16_t x1 = 0;
        uint16_t y2 = y1;
        bool carry2 = carry1;
        bool overflow2 = overflow1;
        uint8_t data_bank2 = data_bank;
        uint16_t direct_page2 = direct_page;
        for (;;) {
            RAM8(0x0000 + sp0) = 0x81;
            RAM8(0x0000 + sp0 - 1) = 0x20;
            r->a = (a_hi2 << 8) | a;
            r->x = 0x8120;
            r->y = y2;
            r->c = carry2;
            r->z = 0;
            r->n = 1;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank2;
            r->dp = direct_page2;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x082E, 0xC01BC0); GUARD_JSR(c, sp_call, 0x082E); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            r->sp += 2;
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all2 = r->a;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            uint8_t value12 = RAM8(0x0000 + sp0 - 1);
            uint8_t value13 = RAM8(0x0000 + sp0);
            uint8_t value14 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA157);
            BUS8_SET(c, (db_ret2 << 0x10) + 0xA157, (uint8_t)(value14 + 1));
            uint8_t value15 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA164);
            BUS8_SET(c, (db_ret2 << 0x10) + 0xA164, (uint8_t)(value15 - 1));
            a_hi2 = a_all2 >> 8;
            x1 = (value13 << 8) | value12;
            y2 = y_ret2;
            carry2 = carry_ret2;
            overflow2 = overflow_ret2;
            data_bank2 = db_ret2;
            direct_page2 = dp_ret2;
            if (!((uint8_t)(value15 - 1) != 0)) break;
        }
        uint8_t value16 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xA15E);
        BUS8_SET(c, (data_bank2 << 0x10) + 0xA15E, (uint8_t)(value16 + 1));
        uint8_t value17 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xA16C);
        BUS8_SET(c, (data_bank2 << 0x10) + 0xA164, (uint8_t)(value17 - 2));
        a1 = (uint8_t)(value17 - 2);
        a_hi3 = a_hi2;
        x2 = x1;
        y3 = y2;
        carry3 = carry2;
        zero1 = (uint8_t)(value17 - 2) == 0;
        negative1 = (uint8_t)(value17 - 2) & 0x80;
        overflow3 = overflow2;
        data_bank3 = data_bank2;
        direct_page3 = direct_page2;
    } else {
        RAM8(0xA15E) = 4;
        uint8_t value18 = RAM8(0xA24E);
        uint8_t value19 = RAM8(0xA21B);
        RAM8(0xA24F + value18) = value19;
        a1 = value19;
        a_hi3 = 0;
        x2 = value18;
        y3 = y;
        carry3 = carry;
        zero1 = value19 == 0;
        negative1 = value19 & 0x80;
        overflow3 = overflow;
        data_bank3 = 0x7E;
        direct_page3 = dp;
    }
    r->a = (a_hi3 << 8) | a1;
    r->x = x2;
    r->y = y3;
    r->c = carry3;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow3;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank3;
    r->dp = direct_page3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC007E0, SOM_RTS, "gen", restore_dialogue_style_or_publish_collapsed_window_band, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, 1, 0, 100, 44)
