#include "som_c.h"

/* 7EB1DD release_eight_byte_record   [class B, 46 bytes, 26 instructions]
 * Source: src/boot/release_eight_byte_record.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABXYCZNV.
 */
static void release_eight_byte_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    bool interrupt_disable2;
    bool decimal_mode2;
    bool m_flag2;
    bool x_flag2;
    uint8_t a2;
    uint8_t a_hi2;
    if (x == 0) {
        interrupt_disable2 = i_entry;
        decimal_mode2 = d_entry;
        m_flag2 = 0;
        x_flag2 = 0;
        a2 = 0x7F;
        a_hi2 = a >> 8;
    } else {
        bool interrupt_disable;
        bool decimal_mode;
        bool m_flag;
        bool x_flag;
        uint8_t a1;
        uint8_t a_hi1;
        if (x == 0xFFFF) {
            interrupt_disable = i_entry;
            decimal_mode = d_entry;
            m_flag = 0;
            x_flag = 0;
            a1 = 0x7F;
            a_hi1 = a >> 8;
        } else {
            RAM8(0x0000 + sp0 - 4) = (((((uint16_t)(x - 0xFFFF) >> 0x0F << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | ((x == 0xFFFF) << 1) | x >= 0xFFFF;
            uint16_t value = RAM16(0x102C6);
            BUS16_SET(c, 0x7F0000 + x, value);
            BUS8_SET(c, 0x7F0002 + x, 0);
            RAM16_SET(0x102C6, x);
            uint8_t value2 = RAM8(0x0000 + sp0 - 4);
            interrupt_disable = value2 & 0x04;
            decimal_mode = value2 & 0x08;
            m_flag = value2 & 0x20;
            x_flag = value2 & 0x10;
            a1 = (uint8_t)value;
            a_hi1 = value >> 8;
        }
        interrupt_disable2 = interrupt_disable;
        decimal_mode2 = decimal_mode;
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        a2 = a1;
        a_hi2 = a_hi1;
    }
    uint8_t value3 = RAM8(0x0000 + sp0 - 3);
    uint8_t value4 = RAM8(0x0000 + sp0 - 2);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->a = (a_hi2 << 8) | a2;
    r->c = value4 & 0x01;
    r->z = ((value6 << 8) | value5) == 0;
    r->n = ((value6 << 8) | value5) & 0x8000;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value3;
    r->dp = (value6 << 8) | value5;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB1DD, SOM_RTS, "gen", release_eight_byte_record, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 0, 0, 46, 26)
