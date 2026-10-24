#include "som_c.h"

/* C102B7 actor_script_call   [class B, 65 bytes, 35 instructions]
 * Source: src/rom/actor_script_call.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_call(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), ((uint16_t)(RAM16(0x014F + y) << 1) & 0xFF) + 0x0150);
    uint16_t value2 = RAM16(0x0144 + y);
    BUS16_SET(c, RAM16(0x0001 + (uint16_t)(sp0 - 5)) + 0x7E0000 + y, (uint16_t)(value2 + 3));
    uint16_t value3 = BUS16(c, 0xD04F16 + value2);
    RAM16_SET(0x0144 + y, ((uint8_t)value3 << 8) | (value3 >> 8));
    uint8_t value4 = RAM8(0x014F + y);
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((uint8_t)(value4 + 1) >= 0x10) {
        r->a = ((uint8_t)value3 << 8) | (uint8_t)(value4 + 1);
        r->x = value2;
        r->c = (uint8_t)(value4 + 1) >= 0x10;
        r->z = (uint8_t)(value4 + 1) == 0x10;
        r->n = (uint8_t)((uint8_t)(value4 + 1) - 0x10) & 0x80;
        r->v = ((value2 ^ (uint16_t)(value2 + 3)) & ((uint16_t)(value2 + 3) ^ 3) & 0x8000) != 0;
        r->dp = (uint16_t)(sp0 - 5);
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x02F0, 0xC10100); GUARD_JSR(c, sp_call, 0x02F0); } /* restart_actor_program_on_script_error */
        r->sp += 5;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        m_flag = m_ret;
        x_flag = x_ret;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    } else {
        RAM8(0x014F + y) = (uint8_t)(value4 + 1);
        m_flag = 1;
        x_flag = 0;
        a1 = 0xFF;
        a_hi1 = (uint8_t)value3;
        x1 = value2;
        y1 = y;
        data_bank = 0x7E;
        direct_page = (uint16_t)(sp0 - 5);
    }
    if (m_flag) {
        RAM8(0x0000 + sp0 - 3) = a1;
        uint8_t value6 = RAM8(0x0000 + sp0 - 3);
        uint8_t value7 = RAM8(0x0000 + sp0 - 2);
        uint8_t value8 = RAM8(0x0000 + sp0 - 1);
        uint8_t value9 = RAM8(0x0000 + sp0);
        r->a = (a_hi1 << 8) | value6;
        r->x = x1;
        r->y = y1;
        r->c = value7 & 0x01;
        r->z = ((value9 << 8) | value8) == 0;
        r->n = ((value9 << 8) | value8) & 0x8000;
        r->v = value7 & 0x40;
        r->mf = value7 & 0x20;
        r->xf = value7 & 0x10;
        r->db = data_bank;
        r->dp = (value9 << 8) | value8;
        r->i = value7 & 0x04;
        r->d = value7 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
}
SOM_REGISTER(0xC102B7, SOM_RTS, "gen", actor_script_call, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 65, 35)
