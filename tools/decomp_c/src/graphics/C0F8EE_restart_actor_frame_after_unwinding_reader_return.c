#include "som_c.h"

/* C0F8EE restart_actor_frame_after_unwinding_reader_return   [class C, 259 bytes, 118 instructions]
 * Source: src/rom/restart_actor_frame_after_unwinding_reader_return.s
 * Documented in docs/actor-animation-step.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYCV.
 */
static void restart_actor_frame_after_unwinding_reader_return(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0xE030 + x) = 0xFF;
    uint8_t value = RAM8(0xE02C + x);
    uint8_t value2 = RAM8(0xE060 + x);
    bool m_flag2;
    bool x_flag2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool overflow2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if ((value | value2) != 0) {
        m_flag2 = 1;
        x_flag2 = 0;
        x2 = x;
        y2 = y;
        carry2 = carry;
        overflow2 = overflow;
        data_bank2 = 0x7E;
        direct_page2 = 0;
    } else {
        uint8_t value3 = RAM8(0xE064 + x);
        bool m_flag;
        bool x_flag;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        uint8_t data_bank;
        uint16_t direct_page;
        if (!(value3 & 0x80)) {
            m_flag = 1;
            x_flag = 0;
            x1 = x;
            y1 = y;
            carry1 = carry;
            overflow1 = overflow;
            data_bank = 0x7E;
            direct_page = 0;
        } else {
            r->a = (a_hi << 8) | value3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xF904, 0xC0F8B3); GUARD_JSR(c, sp_call, 0xF904); } /* trigger_actor_program_under_native_animation_guards */
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool m_ret = r->mf;
            bool x_ret = r->xf;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret = r->y;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            m_flag = m_ret;
            x_flag = x_ret;
            x1 = x_ret2;
            y1 = y_ret;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        overflow2 = overflow1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->v = overflow2;
    r->mf = 0;
    r->xf = x_flag2;
    r->db = data_bank2;
    r->dp = direct_page2;
    r->sp += 2;
    TAIL_CALL(c, 0xC0F52D, SOM_RTS); /* external */
}
SOM_REGISTER(0xC0F8EE, SOM_RTS, "gen", restart_actor_frame_after_unwinding_reader_return, SOM_UNWINDS, L_X | L_Y | L_C | L_V, 2, 1, 0, 259, 118)
