#include "som_c.h"

/* 7EAC69 wake_waiting_task   [class B, 67 bytes, 36 instructions]
 * Source: src/boot/wake_waiting_task.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: BXY.
 */
static void wake_waiting_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint8_t value = BUS8(c, 0x7F0002 + x);
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y3;
    uint16_t direct_page3;
    if (value != 4) {
        a_hi3 = a >> 8;
        x3 = x;
        y3 = y;
        direct_page3 = dp;
    } else {
        uint8_t a1 = (uint8_t)x;
        uint8_t a_hi1 = x >> 8;
        uint16_t x1 = 0xA2;
        uint16_t y1 = y;
        bool overflow1 = overflow;
        uint16_t direct_page = dp;
        for (;;) {
            uint16_t value2 = BUS16(c, 0x7F0000 + x1);
            bool m_flag;
            bool x_flag;
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            uint16_t direct_page2;
            if (((a_hi1 << 8) | a1) == value2) {
                uint16_t value3 = BUS16(c, 0x7F0000 + ((a_hi1 << 8) | a1));
                BUS16_SET(c, 0x7F0000 + x1, value3);
                BUS8_SET(c, 0x7F0002 + ((a_hi1 << 8) | a1), 2);
                r->a = (value3 >> 8 << 8) | 2;
                r->x = (a_hi1 << 8) | a1;
                r->y = (a_hi1 << 8) | a1;
                r->c = ((a_hi1 << 8) | a1) >= value2;
                r->z = ((a_hi1 << 8) | a1) == 0;
                r->n = ((a_hi1 << 8) | a1) & 0x8000;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7F;
                r->dp = direct_page;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0xACA7, 0x7EA8D6); GUARD_JSR(c, sp_call, 0xACA7); } /* enqueue_task_by_priority */
                r->sp += 4;
                uint16_t dp_ret = r->dp;
                bool m_ret = r->mf;
                bool x_ret = r->xf;
                uint16_t a_all = r->a;
                uint16_t x_ret2 = r->x;
                uint16_t y_ret = r->y;
                m_flag = m_ret;
                x_flag = x_ret;
                a_hi2 = a_all >> 8;
                x2 = x_ret2;
                y2 = y_ret;
                direct_page2 = dp_ret;
            } else {
                uint16_t value4 = BUS16(c, 0x7F0000 + x1);
                if (value4 != 0) {
                    x1 = value4;
                    y1 = value4;
                    continue;
                }
                BUS8_SET(c, 0x7F0002 + ((a_hi1 << 8) | a1), 0x80);
                m_flag = 1;
                x_flag = 0;
                a_hi2 = a_hi1;
                x2 = (a_hi1 << 8) | a1;
                y2 = value4;
                direct_page2 = direct_page;
            }
            a_hi1 = a_hi2;
            x1 = x2;
            y1 = y2;
            direct_page = direct_page2;
            break;
        }
        a_hi3 = a_hi1;
        x3 = x1;
        y3 = y1;
        direct_page3 = direct_page;
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 3);
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    uint8_t value8 = RAM8(0x0000 + sp0);
    r->a = (a_hi3 << 8) | (uint8_t)a;
    r->x = x3;
    r->y = y3;
    r->mf = value6 & 0x20;
    r->xf = value6 & 0x10;
    r->db = value5;
    r->dp = (value8 << 8) | value7;
    r->i = value6 & 0x04;
    r->d = value6 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EAC69, SOM_RTS, "gen", wake_waiting_task, 0, L_B | L_X | L_Y, 5, 0, 0, 67, 36)
