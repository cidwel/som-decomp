#include "som_c.h"

/* 7EC870 queue_registered_vram_buffer   [class B, 88 bytes, 47 instructions]
 * Source: src/boot/queue_registered_vram_buffer.s
 * Entry: M=any X=16 bit DB=$7F D=any.  Callers read: ABXYCZNV.
 */
static void queue_registered_vram_buffer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 9) = 0x7F;
    RAM8(0x0000 + sp0 - 0x0A) = 0x7F;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), x);
    r->a = ((uint16_t)(sp0 - 9) >> 8 << 8) | 0x7F;
    r->c = (uint16_t)(sp0 - 3) >= 6;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 9);
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC888, 0x7EC73B); GUARD_JSR(c, sp_call, 0xC888); } /* find_registered_vram_buffer */
    r->sp += 10;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t x_ret2 = r->x;
    uint16_t value = BUS16(c, 0x7F0000 + x_ret2);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), (uint16_t)((((value & 0xFF) << 8) | 0) << 2));
    uint16_t value2 = BUS16(c, 0x7F0001 + x_ret2);
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), ((value2 & 0xFF) << 8) | 0);
    r->a = 1;
    r->c = (uint16_t)((((value & 0xFF) << 8) | 0) << 1) & 0x8000;
    r->z = 0;
    r->n = 0;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC8A2, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xC8A2); } /* allocate_transfer_descriptor */
    r->sp += 10;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret4 = r->x;
    if (m_ret) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        BUS8_SET(c, (db_ret << 0x10) + 0x0A + x_ret4, value3);
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 3));
        BUS8_SET(c, (db_ret << 0x10) + 2 + x_ret4, value4);
        uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 5));
        BUS8_SET(c, (db_ret << 0x10) + 5 + x_ret4, value5);
        BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret4, 0x7F);
        r->a = (a_all2 >> 8 << 8) | 0x7F;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->sp -= 10;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC8BB, 0x7E90DA); GUARD_JSR(c, sp_call, 0xC8BB); } /* submit_transfer_or_program_hdma */
        r->sp += 10;
        uint8_t value6 = RAM8(0x0000 + sp0 - 9);
        uint8_t value7 = RAM8(0x0000 + sp0 - 2);
        uint8_t value8 = RAM8(0x0000 + sp0 - 1);
        uint8_t value9 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
        r->c = value7 & 0x01;
        r->z = ((value9 << 8) | value8) == 0;
        r->n = ((value9 << 8) | value8) & 0x8000;
        r->v = value7 & 0x40;
        r->mf = value7 & 0x20;
        r->xf = value7 & 0x10;
        r->db = value6;
        r->dp = (value9 << 8) | value8;
        r->i = value7 & 0x04;
        r->d = value7 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        BUS16_SET(c, (db_ret << 0x10) + 0x0A + x_ret4, value10);
        uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        BUS16_SET(c, (db_ret << 0x10) + 2 + x_ret4, value11);
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
        BUS16_SET(c, (db_ret << 0x10) + 5 + x_ret4, value12);
        BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret4, 0x7F);
        r->a = (value12 >> 8 << 8) | 0x7F;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->sp -= 10;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC8BB, 0x7E90DA); GUARD_JSR(c, sp_call, 0xC8BB); } /* submit_transfer_or_program_hdma */
        r->sp += 10;
        uint8_t value13 = RAM8(0x0000 + sp0 - 9);
        uint8_t value14 = RAM8(0x0000 + sp0 - 2);
        uint8_t value15 = RAM8(0x0000 + sp0 - 1);
        uint8_t value16 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
        r->c = value14 & 0x01;
        r->z = ((value16 << 8) | value15) == 0;
        r->n = ((value16 << 8) | value15) & 0x8000;
        r->v = value14 & 0x40;
        r->mf = value14 & 0x20;
        r->xf = value14 & 0x10;
        r->db = value13;
        r->dp = (value16 << 8) | value15;
        r->i = value14 & 0x04;
        r->d = value14 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7EC870, SOM_RTS, "gen", queue_registered_vram_buffer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 11, -1, 0, 88, 47)
