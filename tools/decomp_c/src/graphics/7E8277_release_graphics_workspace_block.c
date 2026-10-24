#include "som_c.h"

/* 7E8277 release_graphics_workspace_block   [class B, 93 bytes, 55 instructions]
 * Source: src/boot/release_graphics_workspace_block.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void release_graphics_workspace_block(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 9) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0A) = 0x7F;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), x);
    r->a = ((uint16_t)(sp0 - 9) >> 8 << 8) | 0x7F;
    r->c = (uint16_t)(sp0 - 3) >= 6;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
    r->mf = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 9);
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x828F, 0x7ED6B3); GUARD_JSR(c, sp_call, 0x828F); } /* read_vram_address_tag_word */
    r->sp += 10;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8292, 0x7E805F); GUARD_JSR(c, sp_call, 0x8292); } /* select_graphics_registration */
    r->sp += 10;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    BUS16_SET(c, (uint16_t)(dp_ret + 1), a_all2);
    if (x_ret3) {
        uint16_t value = BUS16_RDP(c, (db_ret << 0x10) + 2 + (uint8_t)a_all2);
        BUS16_SET(c, (uint16_t)(dp_ret + 5), value & 3);
        uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + (uint8_t)a_all2);
        uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 5), (uint16_t)(value4 - 1));
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint16_t)(value4 - 1) == 0) {
            a2 = (uint8_t)((uint16_t)(((uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 2) - value3) ^ 0xFFFF) + 1) >> 3);
            a_hi2 = (uint16_t)(((uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 2) - value3) ^ 0xFFFF) + 1) >> 3 >> 8;
        } else {
            uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret + 5), (uint16_t)(value5 - 1));
            uint8_t a1;
            uint8_t a_hi1;
            if ((uint16_t)(value5 - 1) == 0) {
                a1 = (uint8_t)((uint16_t)(((uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 2) - value3) ^ 0xFFFF) + 1) >> 4);
                a_hi1 = (uint16_t)(((uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 2) - value3) ^ 0xFFFF) + 1) >> 4 >> 8;
            } else {
                a1 = (uint8_t)((uint16_t)(((uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 2) - value3) ^ 0xFFFF) + 1) >> 5);
                a_hi1 = (uint16_t)(((uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 2) - value3) ^ 0xFFFF) + 1) >> 5 >> 8;
            }
            a2 = a1;
            a_hi2 = a_hi1;
        }
        uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 6 + (uint8_t)a_all2);
        BUS16_SET(c, (db_ret << 0x10) + 4 + (uint8_t)a_all2, (uint16_t)(((a_hi2 << 8) | a2) + value6));
        BUS8_SET(c, (db_ret << 0x10) + (uint8_t)(((a_hi2 << 8) | a2) + value6), 0);
        uint8_t value7 = RAM8(0x0000 + sp0 - 9);
        uint8_t value8 = RAM8(0x0000 + sp0 - 2);
        uint8_t value9 = RAM8(0x0000 + sp0 - 1);
        uint8_t value10 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
        r->x = (uint8_t)(((a_hi2 << 8) | a2) + value6);
        r->y = (uint8_t)y;
        r->c = value8 & 0x01;
        r->z = ((value10 << 8) | value9) == 0;
        r->n = ((value10 << 8) | value9) & 0x8000;
        r->v = value8 & 0x40;
        r->mf = value8 & 0x20;
        r->xf = value8 & 0x10;
        r->db = value7;
        r->dp = (value10 << 8) | value9;
        r->i = value8 & 0x04;
        r->d = value8 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value11 = BUS16_RDP(c, (db_ret << 0x10) + 2 + a_all2);
        BUS16_SET(c, (uint16_t)(dp_ret + 5), value11 & 3);
        uint16_t value12 = BUS16_RDP(c, (db_ret << 0x10) + a_all2);
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 5), (uint16_t)(value14 - 1));
        uint8_t a4;
        uint8_t a_hi4;
        if ((uint16_t)(value14 - 1) == 0) {
            a4 = (uint8_t)((uint16_t)(((uint16_t)((uint16_t)((((value12 & 0xFF) << 8) | 0) << 2) - value13) ^ 0xFFFF) + 1) >> 3);
            a_hi4 = (uint16_t)(((uint16_t)((uint16_t)((((value12 & 0xFF) << 8) | 0) << 2) - value13) ^ 0xFFFF) + 1) >> 3 >> 8;
        } else {
            uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret + 5), (uint16_t)(value15 - 1));
            uint8_t a3;
            uint8_t a_hi3;
            if ((uint16_t)(value15 - 1) == 0) {
                a3 = (uint8_t)((uint16_t)(((uint16_t)((uint16_t)((((value12 & 0xFF) << 8) | 0) << 2) - value13) ^ 0xFFFF) + 1) >> 4);
                a_hi3 = (uint16_t)(((uint16_t)((uint16_t)((((value12 & 0xFF) << 8) | 0) << 2) - value13) ^ 0xFFFF) + 1) >> 4 >> 8;
            } else {
                a3 = (uint8_t)((uint16_t)(((uint16_t)((uint16_t)((((value12 & 0xFF) << 8) | 0) << 2) - value13) ^ 0xFFFF) + 1) >> 5);
                a_hi3 = (uint16_t)(((uint16_t)((uint16_t)((((value12 & 0xFF) << 8) | 0) << 2) - value13) ^ 0xFFFF) + 1) >> 5 >> 8;
            }
            a4 = a3;
            a_hi4 = a_hi3;
        }
        uint16_t value16 = BUS16_RDP(c, (db_ret << 0x10) + 6 + a_all2);
        BUS16_SET(c, (db_ret << 0x10) + 4 + a_all2, (uint16_t)(((a_hi4 << 8) | a4) + value16));
        BUS8_SET(c, (db_ret << 0x10) + (uint16_t)(((a_hi4 << 8) | a4) + value16), 0);
        uint8_t value17 = RAM8(0x0000 + sp0 - 9);
        uint8_t value18 = RAM8(0x0000 + sp0 - 2);
        uint8_t value19 = RAM8(0x0000 + sp0 - 1);
        uint8_t value20 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
        r->x = (uint16_t)(((a_hi4 << 8) | a4) + value16);
        r->c = value18 & 0x01;
        r->z = ((value20 << 8) | value19) == 0;
        r->n = ((value20 << 8) | value19) & 0x8000;
        r->v = value18 & 0x40;
        r->mf = value18 & 0x20;
        r->xf = value18 & 0x10;
        r->db = value17;
        r->dp = (value20 << 8) | value19;
        r->i = value18 & 0x04;
        r->d = value18 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7E8277, SOM_RTS, "gen", release_graphics_workspace_block, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 11, 1, 0, 93, 55)
