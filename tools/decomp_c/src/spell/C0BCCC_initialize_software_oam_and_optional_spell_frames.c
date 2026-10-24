#include "som_c.h"

/* C0BCCC initialize_software_oam_and_optional_spell_frames   [class B, 39 bytes, 17 instructions]
 * Source: src/rom/initialize_software_oam_and_optional_spell_frames.s
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_software_oam_and_optional_spell_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x0059, 1);
    RAM16_SET(0x005A, 0);
    RAM16_SET(0x007C, 0);
    RAM16_SET(RING_OPEN, 0);
    uint16_t x1 = 0x0200;
    bool carry1 = carry;
    for (;;) {
        BUS16_SET(c, 0x000800 + x1, 0);
        uint16_t x1_next = (uint16_t)(x1 + 2);
        bool carry1_next = (uint16_t)(x1 + 2) >= 0x0220;
        x1 = x1_next;
        carry1 = carry1_next;
        if (!(x1 < 0x0220)) break;
    }
    uint8_t value = RAM8(0xCFF7);
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x2;
    uint16_t y1;
    bool carry2;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value == 0) {
        m_flag = 1;
        x_flag = 0;
        a1 = value;
        a_hi1 = 0;
        x2 = x1;
        y1 = y;
        carry2 = carry1;
        zero1 = value == 0;
        negative1 = value & 0x80;
        overflow1 = overflow;
        data_bank = 0;
        direct_page = 0;
    } else {
        r->a = value;
        r->x = x1;
        r->y = y;
        r->c = carry1;
        r->z = value == 0;
        r->n = value & 0x80;
        r->v = overflow;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xBCF1, 0xC10034); GUARD_JSL(c, sp_call, 0xBCF1); } /* render_optional_spell_frames_long */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x2 = x_ret2;
        y1 = y_ret;
        carry2 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x2;
    r->y = y1;
    r->c = carry2;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0BCCC, SOM_RTS, "gen", initialize_software_oam_and_optional_spell_frames, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, -1, 39, 17)
