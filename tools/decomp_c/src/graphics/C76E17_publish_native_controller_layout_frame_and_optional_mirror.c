#include "som_c.h"

/* C76E17 publish_native_controller_layout_frame_and_optional_mirror   [class A, 31 bytes, 14 instructions]
 * Source: src/rom/publish_native_controller_layout_frame_and_optional_mirror.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void publish_native_controller_layout_frame_and_optional_mirror(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA198) = 0;
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0xC7;
    r->a = (a_hi << 8) | 0xC7;
    r->y = 0x75D2;
    r->z = 0;
    r->n = 0;
    r->db = 0xC7;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6E25, 0xC02AF6); GUARD_JSL(c, sp_call, 0x6E25); } /* native_controller_layout_rectangle_long_wrapper */
    r->sp += 1;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    uint8_t value = RAM8(0x0000 + sp0);
    uint16_t value2 = BUS16_RDP(c, (value << 0x10) + 0xA220);
    uint8_t value3 = BUS8_RDP(c, (value << 0x10) + 0xA22F + value2);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t y1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((value3 & 3) == 0) {
        m_flag = 1;
        x_flag = 0;
        a_hi1 = a_all >> 8;
        y1 = y_ret;
        data_bank = value;
        direct_page = 0;
    } else {
        r->a = a_all >> 8 << 8 | (value3 & 3);
        r->x = value2;
        r->z = (value3 & 3) == 0;
        r->n = value3 & 3 & 0x80;
        r->mf = 1;
        r->xf = 0;
        r->db = value;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6E34, 0xC76F74); GUARD_JSL(c, sp_call, 0x6E34); } /* swap_and_mirror_native_controller_frame_tiles */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t y_ret2 = r->y;
        m_flag = m_ret;
        x_flag = x_ret2;
        a_hi1 = a_all2 >> 8;
        y1 = y_ret2;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->a = (a_hi1 << 8) | a;
    r->y = y1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76E17, SOM_RTL, "gen", publish_native_controller_layout_frame_and_optional_mirror, 0, L_B | L_Y | L_C | L_V, 2, 1, 0, 31, 14)
