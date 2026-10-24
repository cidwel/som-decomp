#include "som_c.h"

/* C0C1E7 upload_map_menu_and_prepare_palette_hdma   [class D, 81 bytes, 33 instructions]
 * Source: src/rom/upload_map_menu_and_prepare_palette_hdma.s
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: CV.
 */
static void upload_map_menu_and_prepare_palette_hdma(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    uint8_t value = RAM8(0x1D04);
    bool m_flag;
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    if ((value & 4) == 0) {
        m_flag = 1;
        a_hi1 = a_hi;
        carry1 = carry;
        overflow1 = value & 0x40;
        data_bank = 0;
    } else {
        r->a = (a_hi << 8) | 4;
        r->z = (value & 4) == 0;
        r->n = value & 0x80;
        r->v = value & 0x40;
        { const uint16_t sp_call = r->sp; JSL(c, 0xC1F3, 0xC00006); GUARD_JSL(c, sp_call, 0xC1F3); } /* upload_menu_frame_entry */
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        uint16_t a_all = r->a;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        a_hi1 = a_all >> 8;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
    }
    uint8_t value2 = BUS8_RDP(c, (data_bank << 0x10) + 0x1D04);
    if ((value2 & 0x20) != 0) {
        if ((RAM8(0x002C) & 3) != 0) {
            r->c = carry1;
            r->v = overflow1;
            r->mf = 1;
            r->db = data_bank;
            RETURN_RTS(c);
        }
        uint16_t value4 = BUS16_RDP(c, (data_bank << 0x10) + 0x010E);
        if (value4 == 0) {
            r->c = carry1;
            r->v = overflow1;
            r->mf = 0;
            r->db = data_bank;
            RETURN_RTS(c);
        }
        BUS16_SET(c, (data_bank << 0x10) + 0x4312, 0x05D0);
        BUS16_SET(c, (data_bank << 0x10) + 0x4302, 0x05DB);
        BUS16_SET(c, (data_bank << 0x10) + 0x4308, 0x05DB);
        BUS16_SET(c, (data_bank << 0x10) + 0x4310, 0x2242);
        BUS16_SET(c, (data_bank << 0x10) + 0x4300, 0x2100);
        BUS8_SET(c, (data_bank << 0x10) + 0x4304, 0);
        BUS8_SET(c, (data_bank << 0x10) + 0x4314, 0);
        BUS8_SET(c, (data_bank << 0x10) + 0x4317, 0x7E);
        RAM8(0x002C) |= 3;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 1;
        r->db = data_bank;
        RETURN_RTS(c);
    }
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->db = data_bank;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C1E7, SOM_RTS, "gen", upload_map_menu_and_prepare_palette_hdma, 0, L_C | L_V, 1, 1, -1, 81, 33)
