#include "som_c.h"

/* C1EA84 refresh_map_object_slot_when_inactive_or_flag_rejected   [class B, 21 bytes, 8 instructions]
 * Source: src/rom/refresh_map_object_slot_when_inactive_or_flag_rejected.s
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: Y.
 */
static void refresh_map_object_slot_when_inactive_or_flag_rejected(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xE000 + x);
    bool m_flag2;
    bool x_flag2;
    uint16_t y2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if (value == 0) {
        r->a = (a >> 8 << 8) | value;
        r->z = value == 0;
        r->n = value & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEA97, 0x00E00C); GUARD_JSL(c, sp_call, 0xEA97); } /* retire_and_rescan_cached_map_object_slot */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t y_ret = r->y;
        m_flag2 = m_ret;
        x_flag2 = x_ret;
        y2 = y_ret;
        data_bank2 = db_ret;
        direct_page2 = dp_ret;
    } else {
        uint16_t value2 = RAM16(0xE034 + x);
        r->a = (a >> 8 << 8) | value;
        r->y = value2;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEA91, 0x02C757); GUARD_JSL(c, sp_call, 0xEA91); } /* test_map_object_event_flag_range */
        bool carry_ret2 = r->c;
        bool m_flag;
        bool x_flag;
        uint16_t y1;
        uint8_t data_bank;
        uint16_t direct_page;
        if (carry_ret2) {
            m_flag = 1;
            x_flag = 0;
            y1 = value2;
            data_bank = 0x7E;
            direct_page = 0;
        } else {
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xEA97, 0x00E00C); GUARD_JSL(c, sp_call, 0xEA97); } /* retire_and_rescan_cached_map_object_slot */
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            bool m_ret2 = r->mf;
            bool x_ret4 = r->xf;
            uint16_t y_ret2 = r->y;
            m_flag = m_ret2;
            x_flag = x_ret4;
            y1 = y_ret2;
            data_bank = db_ret2;
            direct_page = dp_ret2;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        y2 = y1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    r->y = y2;
    r->mf = m_flag2;
    r->xf = x_flag2;
    r->db = data_bank2;
    r->dp = direct_page2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EA84, SOM_RTS, "gen", refresh_map_object_slot_when_inactive_or_flag_rejected, 0, L_Y, 1, -1, 0, 21, 8)
