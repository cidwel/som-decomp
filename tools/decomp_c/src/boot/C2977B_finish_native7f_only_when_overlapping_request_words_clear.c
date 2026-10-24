#include "som_c.h"

/* C2977B finish_native7f_only_when_overlapping_request_words_clear   [class B, 36 bytes, 16 instructions]
 * Source: src/rom/finish_native7f_only_when_overlapping_request_words_clear.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void finish_native7f_only_when_overlapping_request_words_clear(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x00D9);
    uint16_t value2 = RAM16(0x00DA);
    uint16_t value3 = RAM16(0x00DB);
    if (((value | value2 | value3) & 0x80) != 0) {
        r->a = value | value2 | value3;
        r->c = 0;
        r->z = ((value | value2 | value3) & 0x80) == 0;
        r->n = (value | value2 | value3) & 0x8000;
        RETURN_RTS(c);
    }
    uint16_t value4 = RAM16(0x1D04);
    if ((value4 & 0x20) != 0) {
        r->a = value4;
        r->c = 0;
        r->z = (value4 & 0x20) == 0;
        r->n = value4 & 0x8000;
        RETURN_RTS(c);
    }
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value6 = RAM16(0x0072 + value5);
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value6 == 0) {
        m_flag = 0;
        x_flag = 0;
        a1 = (uint8_t)value6;
        a_hi1 = value6 >> 8;
        x1 = value5;
        y1 = y;
        zero1 = value6 == 0;
        negative1 = value6 & 0x8000;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = dp;
    } else {
        r->a = value6;
        r->x = value5;
        r->z = value6 == 0;
        r->n = value6 & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0x979A, 0xC20C11); GUARD_JSR(c, sp_call, 0x979A); } /* mark_controller_and_request_numeric_boss_death_event */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 1;
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
SOM_REGISTER(0xC2977B, SOM_RTS, "gen", finish_native7f_only_when_overlapping_request_words_clear, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 36, 16)
