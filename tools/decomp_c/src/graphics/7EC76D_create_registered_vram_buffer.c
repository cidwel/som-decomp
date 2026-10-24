#include "som_c.h"

/* 7EC76D create_registered_vram_buffer   [class B, 185 bytes, 99 instructions]
 * Source: src/boot/create_registered_vram_buffer.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$05E1.  Callers read: XYCV.
 */
static void create_registered_vram_buffer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x05E1) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xE1;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 9) = 0x7F;
    RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7F;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), value);
    r->a = value;
    r->c = (uint16_t)(sp0 - 5) >= 4;
    r->z = (uint8_t)value == 0;
    r->n = (uint8_t)value & 0x80;
    r->v = (((uint16_t)(sp0 - 5) ^ 4) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 9);
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC78A, 0x7EC710); GUARD_JSR(c, sp_call, 0xC78A); } /* select_vram_registration_slot */
    r->sp += 10;
    uint16_t a_all = r->a;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 9), a_all);
    uint8_t value2 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
    uint16_t x3;
    bool carry2;
    if ((value2 & 3) == 0) {
        x3 = 0x0800;
        carry2 = (value2 & 3) >= 0;
    } else {
        uint16_t x2;
        bool carry1;
        if ((value2 & 3) == 1) {
            x2 = 0x1000;
            carry1 = (value2 & 3) >= 1;
        } else {
            uint16_t x1;
            if ((value2 & 3) == 2) {
                x1 = 0x1000;
            } else {
                x1 = 0x2000;
            }
            x2 = x1;
            carry1 = (value2 & 3) >= 2;
        }
        x3 = x2;
        carry2 = carry1;
    }
    RAM8(0x0000 + sp0 - 0x0A) = x3 >> 8;
    RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)x3;
    r->a = (a_all >> 8 << 8) | 0;
    r->x = x3;
    r->c = carry2;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC7AD, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xC7AD); } /* allocate_and_fill_bytes */
    r->sp += 12;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value3 = RAM8(0x0002 + (uint16_t)(sp0 - 9));
        RAM16_SET(0x10002 + value3, (uint8_t)x_ret2);
        RAM16_SET(0x10004 + value3, 0);
        RAM16_SET(0x10006 + value3, 0);
        uint8_t value5 = RAM8(0x0000 + sp0 - 0x0A);
        RAM8(0x10001 + value3) = value5;
        r->a = ((RAM8(0x0001 + (uint16_t)(sp0 - 9)) & 0xFC) << 8) | (value5 >> 3);
        r->x = value3;
        r->y = (uint8_t)y_ret;
        r->c = value5 >> 2 & 0x01;
        r->z = value5 >> 3 == 0;
        r->n = value5 >> 3 & 0x80;
        r->mf = 1;
        r->xf = 1;
        r->sp -= 10;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC7CE, 0x7ED5F3); GUARD_JSR(c, sp_call, 0xC7CE); } /* allocate_vram_pages */
        r->sp += 10;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t a_all3 = r->a;
        if (x_ret3) {
            uint8_t value7 = RAM8(0x0002 + (uint16_t)(sp0 - 9));
            RAM8(0x10000 + value7) = (uint8_t)a_all3;
            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)((uint8_t)a_all3 << 2);
            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (RAM8(0x0001 + (uint16_t)(sp0 - 9)) & 3) | RAM8(0x0006 + (uint16_t)(sp0 - 9));
            uint8_t value10 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
            RAM8(0x0004 + (uint16_t)(sp0 - 9)) = (value10 >> 2) & 3;
            r->a = (a_all3 >> 8 << 8) | ((value10 >> 2) & 3) + 7;
            r->x = value7;
            r->c = ((value10 >> 2) & 3) + 7 > 0xFF;
            r->z = ((value10 >> 2) & 3) + 7 == 0;
            r->n = ((value10 >> 2) & 3) + 7 & 0x80;
            r->v = ((((value10 >> 2) & 3) ^ ((value10 >> 2) & 3) + 7) & (((value10 >> 2) & 3) + 7 ^ 7) & 0x80) != 0;
            r->xf = 1;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC7ED, 0x7EC030); GUARD_JSR(c, sp_call, 0xC7ED); } /* allocate_ppu_register_entry */
            r->sp += 10;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool m_ret2 = r->mf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret6 = r->x;
            if (m_ret2) {
                uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret + 6));
                BUS8_SET(c, (db_ret << 0x10) + 2 + x_ret6, value11);
                r->a = (a_all4 >> 8 << 8) | value11;
                r->z = value11 == 0;
                r->n = value11 & 0x80;
                r->mf = 1;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7F5, 0x7EC097); GUARD_JSR(c, sp_call, 0xC7F5); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret2 = r->dp;
                if (r->mf != 1) { c->fail = 3; return; }
                uint16_t a_all5 = r->a;
                uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 4));
                r->a = (a_all5 >> 8 << 8) | (uint8_t)((uint8_t)(value12 << 1) + 0x0D);
                r->c = (uint8_t)(value12 << 1) + 0x0D > 0xFF;
                r->z = (uint8_t)((uint8_t)(value12 << 1) + 0x0D) == 0;
                r->n = (uint8_t)((uint8_t)(value12 << 1) + 0x0D) & 0x80;
                r->v = (((uint8_t)(value12 << 1) ^ (uint8_t)((uint8_t)(value12 << 1) + 0x0D)) & ((uint8_t)((uint8_t)(value12 << 1) + 0x0D) ^ 0x0D) & 0x80) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7FE, 0x7EC030); GUARD_JSR(c, sp_call, 0xC7FE); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret3 = r->db;
                uint16_t x_ret9 = r->x;
                BUS16_SET(c, (db_ret3 << 0x10) + 2 + x_ret9, 0);
                r->mf = 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC806, 0x7EC097); GUARD_JSR(c, sp_call, 0xC806); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret4 = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 4));
                r->a = (uint16_t)((uint16_t)(value13 << 1) + 0x0E);
                r->c = (uint16_t)(value13 << 1) + 0x0E > 0xFFFF;
                r->z = (uint16_t)((uint16_t)(value13 << 1) + 0x0E) == 0;
                r->n = (uint16_t)((uint16_t)(value13 << 1) + 0x0E) & 0x8000;
                r->v = (((uint16_t)(value13 << 1) ^ (uint16_t)((uint16_t)(value13 << 1) + 0x0E)) & ((uint16_t)((uint16_t)(value13 << 1) + 0x0E) ^ 0x0E) & 0x8000) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC810, 0x7EC030); GUARD_JSR(c, sp_call, 0xC810); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret5 = r->db;
                bool m_ret4 = r->mf;
                uint16_t x_ret12 = r->x;
                if (m_ret4) {
                    BUS8_SET(c, (db_ret5 << 0x10) + 2 + x_ret12, 0);
                    r->mf = 1;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret6 = r->dp;
                    uint8_t db_ret6 = r->db;
                    bool m_ret5 = r->mf;
                    bool x_ret13 = r->xf;
                    if (x_ret13) {
                        uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 2));
                        uint8_t value15 = BUS8_RDP(c, (db_ret6 << 0x10) + 2 + value14);
                        uint8_t value16 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret5) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value17 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value18 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value19 = RAM8(0x0000 + sp0);
                            r->x = value15;
                            r->y = value14;
                            r->c = value17 & 0x01;
                            r->v = value17 & 0x40;
                            r->mf = value17 & 0x20;
                            r->xf = value17 & 0x10;
                            r->db = value16;
                            r->dp = (value19 << 8) | value18;
                            r->i = value17 & 0x04;
                            r->d = value17 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 2));
                        uint16_t value21 = BUS16_RDP(c, (db_ret6 << 0x10) + 2 + value20);
                        uint8_t value22 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret5) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value23 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value24 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value25 = RAM8(0x0000 + sp0);
                            r->x = value21;
                            r->y = value20;
                            r->c = value23 & 0x01;
                            r->v = value23 & 0x40;
                            r->mf = value23 & 0x20;
                            r->xf = value23 & 0x10;
                            r->db = value22;
                            r->dp = (value25 << 8) | value24;
                            r->i = value23 & 0x04;
                            r->d = value23 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                } else {
                    BUS16_SET(c, (db_ret5 << 0x10) + 2 + x_ret12, 0);
                    r->mf = 0;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret7 = r->dp;
                    uint8_t db_ret7 = r->db;
                    bool m_ret6 = r->mf;
                    bool x_ret14 = r->xf;
                    if (x_ret14) {
                        uint8_t value26 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 2));
                        uint8_t value27 = BUS8_RDP(c, (db_ret7 << 0x10) + 2 + value26);
                        uint8_t value28 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret6) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value29 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value30 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value31 = RAM8(0x0000 + sp0);
                            r->x = value27;
                            r->y = value26;
                            r->c = value29 & 0x01;
                            r->v = value29 & 0x40;
                            r->mf = value29 & 0x20;
                            r->xf = value29 & 0x10;
                            r->db = value28;
                            r->dp = (value31 << 8) | value30;
                            r->i = value29 & 0x04;
                            r->d = value29 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 2));
                        uint16_t value33 = BUS16_RDP(c, (db_ret7 << 0x10) + 2 + value32);
                        uint8_t value34 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret6) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value35 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value36 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value37 = RAM8(0x0000 + sp0);
                            r->x = value33;
                            r->y = value32;
                            r->c = value35 & 0x01;
                            r->v = value35 & 0x40;
                            r->mf = value35 & 0x20;
                            r->xf = value35 & 0x10;
                            r->db = value34;
                            r->dp = (value37 << 8) | value36;
                            r->i = value35 & 0x04;
                            r->d = value35 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                }
            } else {
                uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret + 6));
                BUS16_SET(c, (db_ret << 0x10) + 2 + x_ret6, value38);
                r->a = value38;
                r->z = value38 == 0;
                r->n = value38 & 0x8000;
                r->mf = 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7F5, 0x7EC097); GUARD_JSR(c, sp_call, 0xC7F5); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret8 = r->dp;
                if (r->mf != 1) { c->fail = 3; return; }
                uint16_t a_all11 = r->a;
                uint8_t value39 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 4));
                r->a = (a_all11 >> 8 << 8) | (uint8_t)((uint8_t)(value39 << 1) + 0x0D);
                r->c = (uint8_t)(value39 << 1) + 0x0D > 0xFF;
                r->z = (uint8_t)((uint8_t)(value39 << 1) + 0x0D) == 0;
                r->n = (uint8_t)((uint8_t)(value39 << 1) + 0x0D) & 0x80;
                r->v = (((uint8_t)(value39 << 1) ^ (uint8_t)((uint8_t)(value39 << 1) + 0x0D)) & ((uint8_t)((uint8_t)(value39 << 1) + 0x0D) ^ 0x0D) & 0x80) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7FE, 0x7EC030); GUARD_JSR(c, sp_call, 0xC7FE); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret9 = r->db;
                uint16_t x_ret17 = r->x;
                BUS16_SET(c, (db_ret9 << 0x10) + 2 + x_ret17, 0);
                r->mf = 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC806, 0x7EC097); GUARD_JSR(c, sp_call, 0xC806); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret10 = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                uint16_t value40 = BUS16_RDP(c, (uint16_t)(dp_ret10 + 4));
                r->a = (uint16_t)((uint16_t)(value40 << 1) + 0x0E);
                r->c = (uint16_t)(value40 << 1) + 0x0E > 0xFFFF;
                r->z = (uint16_t)((uint16_t)(value40 << 1) + 0x0E) == 0;
                r->n = (uint16_t)((uint16_t)(value40 << 1) + 0x0E) & 0x8000;
                r->v = (((uint16_t)(value40 << 1) ^ (uint16_t)((uint16_t)(value40 << 1) + 0x0E)) & ((uint16_t)((uint16_t)(value40 << 1) + 0x0E) ^ 0x0E) & 0x8000) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC810, 0x7EC030); GUARD_JSR(c, sp_call, 0xC810); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret11 = r->db;
                bool m_ret8 = r->mf;
                uint16_t x_ret20 = r->x;
                if (m_ret8) {
                    BUS8_SET(c, (db_ret11 << 0x10) + 2 + x_ret20, 0);
                    r->mf = 1;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret12 = r->dp;
                    uint8_t db_ret12 = r->db;
                    bool m_ret9 = r->mf;
                    bool x_ret21 = r->xf;
                    if (x_ret21) {
                        uint8_t value41 = BUS8_RDP(c, (uint16_t)(dp_ret12 + 2));
                        uint8_t value42 = BUS8_RDP(c, (db_ret12 << 0x10) + 2 + value41);
                        uint8_t value43 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret9) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value44 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value45 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value46 = RAM8(0x0000 + sp0);
                            r->x = value42;
                            r->y = value41;
                            r->c = value44 & 0x01;
                            r->v = value44 & 0x40;
                            r->mf = value44 & 0x20;
                            r->xf = value44 & 0x10;
                            r->db = value43;
                            r->dp = (value46 << 8) | value45;
                            r->i = value44 & 0x04;
                            r->d = value44 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value47 = BUS16_RDP(c, (uint16_t)(dp_ret12 + 2));
                        uint16_t value48 = BUS16_RDP(c, (db_ret12 << 0x10) + 2 + value47);
                        uint8_t value49 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret9) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value50 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value51 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value52 = RAM8(0x0000 + sp0);
                            r->x = value48;
                            r->y = value47;
                            r->c = value50 & 0x01;
                            r->v = value50 & 0x40;
                            r->mf = value50 & 0x20;
                            r->xf = value50 & 0x10;
                            r->db = value49;
                            r->dp = (value52 << 8) | value51;
                            r->i = value50 & 0x04;
                            r->d = value50 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                } else {
                    BUS16_SET(c, (db_ret11 << 0x10) + 2 + x_ret20, 0);
                    r->mf = 0;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret13 = r->dp;
                    uint8_t db_ret13 = r->db;
                    bool m_ret10 = r->mf;
                    bool x_ret22 = r->xf;
                    if (x_ret22) {
                        uint8_t value53 = BUS8_RDP(c, (uint16_t)(dp_ret13 + 2));
                        uint8_t value54 = BUS8_RDP(c, (db_ret13 << 0x10) + 2 + value53);
                        uint8_t value55 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret10) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value56 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value57 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value58 = RAM8(0x0000 + sp0);
                            r->x = value54;
                            r->y = value53;
                            r->c = value56 & 0x01;
                            r->v = value56 & 0x40;
                            r->mf = value56 & 0x20;
                            r->xf = value56 & 0x10;
                            r->db = value55;
                            r->dp = (value58 << 8) | value57;
                            r->i = value56 & 0x04;
                            r->d = value56 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value59 = BUS16_RDP(c, (uint16_t)(dp_ret13 + 2));
                        uint16_t value60 = BUS16_RDP(c, (db_ret13 << 0x10) + 2 + value59);
                        uint8_t value61 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret10) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value62 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value63 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value64 = RAM8(0x0000 + sp0);
                            r->x = value60;
                            r->y = value59;
                            r->c = value62 & 0x01;
                            r->v = value62 & 0x40;
                            r->mf = value62 & 0x20;
                            r->xf = value62 & 0x10;
                            r->db = value61;
                            r->dp = (value64 << 8) | value63;
                            r->i = value62 & 0x04;
                            r->d = value62 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                }
            }
        } else {
            uint16_t value65 = RAM16(0x0002 + (uint16_t)(sp0 - 9));
            RAM8(0x10000 + value65) = (uint8_t)a_all3;
            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)((uint8_t)a_all3 << 2);
            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (RAM8(0x0001 + (uint16_t)(sp0 - 9)) & 3) | RAM8(0x0006 + (uint16_t)(sp0 - 9));
            uint8_t value68 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
            RAM8(0x0004 + (uint16_t)(sp0 - 9)) = (value68 >> 2) & 3;
            r->a = (a_all3 >> 8 << 8) | ((value68 >> 2) & 3) + 7;
            r->x = value65;
            r->c = ((value68 >> 2) & 3) + 7 > 0xFF;
            r->z = ((value68 >> 2) & 3) + 7 == 0;
            r->n = ((value68 >> 2) & 3) + 7 & 0x80;
            r->v = ((((value68 >> 2) & 3) ^ ((value68 >> 2) & 3) + 7) & (((value68 >> 2) & 3) + 7 ^ 7) & 0x80) != 0;
            r->xf = 0;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC7ED, 0x7EC030); GUARD_JSR(c, sp_call, 0xC7ED); } /* allocate_ppu_register_entry */
            r->sp += 10;
            uint16_t dp_ret14 = r->dp;
            uint8_t db_ret14 = r->db;
            bool m_ret11 = r->mf;
            uint16_t a_all17 = r->a;
            uint16_t x_ret24 = r->x;
            if (m_ret11) {
                uint8_t value69 = BUS8_RDP(c, (uint16_t)(dp_ret14 + 6));
                BUS8_SET(c, (db_ret14 << 0x10) + 2 + x_ret24, value69);
                r->a = (a_all17 >> 8 << 8) | value69;
                r->z = value69 == 0;
                r->n = value69 & 0x80;
                r->mf = 1;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7F5, 0x7EC097); GUARD_JSR(c, sp_call, 0xC7F5); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret15 = r->dp;
                if (r->mf != 1) { c->fail = 3; return; }
                uint16_t a_all18 = r->a;
                uint8_t value70 = BUS8_RDP(c, (uint16_t)(dp_ret15 + 4));
                r->a = (a_all18 >> 8 << 8) | (uint8_t)((uint8_t)(value70 << 1) + 0x0D);
                r->c = (uint8_t)(value70 << 1) + 0x0D > 0xFF;
                r->z = (uint8_t)((uint8_t)(value70 << 1) + 0x0D) == 0;
                r->n = (uint8_t)((uint8_t)(value70 << 1) + 0x0D) & 0x80;
                r->v = (((uint8_t)(value70 << 1) ^ (uint8_t)((uint8_t)(value70 << 1) + 0x0D)) & ((uint8_t)((uint8_t)(value70 << 1) + 0x0D) ^ 0x0D) & 0x80) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7FE, 0x7EC030); GUARD_JSR(c, sp_call, 0xC7FE); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret16 = r->db;
                uint16_t x_ret27 = r->x;
                BUS16_SET(c, (db_ret16 << 0x10) + 2 + x_ret27, 0);
                r->mf = 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC806, 0x7EC097); GUARD_JSR(c, sp_call, 0xC806); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret17 = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                uint16_t value71 = BUS16_RDP(c, (uint16_t)(dp_ret17 + 4));
                r->a = (uint16_t)((uint16_t)(value71 << 1) + 0x0E);
                r->c = (uint16_t)(value71 << 1) + 0x0E > 0xFFFF;
                r->z = (uint16_t)((uint16_t)(value71 << 1) + 0x0E) == 0;
                r->n = (uint16_t)((uint16_t)(value71 << 1) + 0x0E) & 0x8000;
                r->v = (((uint16_t)(value71 << 1) ^ (uint16_t)((uint16_t)(value71 << 1) + 0x0E)) & ((uint16_t)((uint16_t)(value71 << 1) + 0x0E) ^ 0x0E) & 0x8000) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC810, 0x7EC030); GUARD_JSR(c, sp_call, 0xC810); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret18 = r->db;
                bool m_ret13 = r->mf;
                uint16_t x_ret30 = r->x;
                if (m_ret13) {
                    BUS8_SET(c, (db_ret18 << 0x10) + 2 + x_ret30, 0);
                    r->mf = 1;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret19 = r->dp;
                    uint8_t db_ret19 = r->db;
                    bool m_ret14 = r->mf;
                    bool x_ret31 = r->xf;
                    if (x_ret31) {
                        uint8_t value72 = BUS8_RDP(c, (uint16_t)(dp_ret19 + 2));
                        uint8_t value73 = BUS8_RDP(c, (db_ret19 << 0x10) + 2 + value72);
                        uint8_t value74 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret14) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value75 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value76 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value77 = RAM8(0x0000 + sp0);
                            r->x = value73;
                            r->y = value72;
                            r->c = value75 & 0x01;
                            r->v = value75 & 0x40;
                            r->mf = value75 & 0x20;
                            r->xf = value75 & 0x10;
                            r->db = value74;
                            r->dp = (value77 << 8) | value76;
                            r->i = value75 & 0x04;
                            r->d = value75 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value78 = BUS16_RDP(c, (uint16_t)(dp_ret19 + 2));
                        uint16_t value79 = BUS16_RDP(c, (db_ret19 << 0x10) + 2 + value78);
                        uint8_t value80 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret14) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value81 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value82 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value83 = RAM8(0x0000 + sp0);
                            r->x = value79;
                            r->y = value78;
                            r->c = value81 & 0x01;
                            r->v = value81 & 0x40;
                            r->mf = value81 & 0x20;
                            r->xf = value81 & 0x10;
                            r->db = value80;
                            r->dp = (value83 << 8) | value82;
                            r->i = value81 & 0x04;
                            r->d = value81 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                } else {
                    BUS16_SET(c, (db_ret18 << 0x10) + 2 + x_ret30, 0);
                    r->mf = 0;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret20 = r->dp;
                    uint8_t db_ret20 = r->db;
                    bool m_ret15 = r->mf;
                    bool x_ret32 = r->xf;
                    if (x_ret32) {
                        uint8_t value84 = BUS8_RDP(c, (uint16_t)(dp_ret20 + 2));
                        uint8_t value85 = BUS8_RDP(c, (db_ret20 << 0x10) + 2 + value84);
                        uint8_t value86 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret15) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value87 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value88 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value89 = RAM8(0x0000 + sp0);
                            r->x = value85;
                            r->y = value84;
                            r->c = value87 & 0x01;
                            r->v = value87 & 0x40;
                            r->mf = value87 & 0x20;
                            r->xf = value87 & 0x10;
                            r->db = value86;
                            r->dp = (value89 << 8) | value88;
                            r->i = value87 & 0x04;
                            r->d = value87 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value90 = BUS16_RDP(c, (uint16_t)(dp_ret20 + 2));
                        uint16_t value91 = BUS16_RDP(c, (db_ret20 << 0x10) + 2 + value90);
                        uint8_t value92 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret15) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value93 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value94 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value95 = RAM8(0x0000 + sp0);
                            r->x = value91;
                            r->y = value90;
                            r->c = value93 & 0x01;
                            r->v = value93 & 0x40;
                            r->mf = value93 & 0x20;
                            r->xf = value93 & 0x10;
                            r->db = value92;
                            r->dp = (value95 << 8) | value94;
                            r->i = value93 & 0x04;
                            r->d = value93 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                }
            } else {
                uint16_t value96 = BUS16_RDP(c, (uint16_t)(dp_ret14 + 6));
                BUS16_SET(c, (db_ret14 << 0x10) + 2 + x_ret24, value96);
                r->a = value96;
                r->z = value96 == 0;
                r->n = value96 & 0x8000;
                r->mf = 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7F5, 0x7EC097); GUARD_JSR(c, sp_call, 0xC7F5); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret21 = r->dp;
                if (r->mf != 1) { c->fail = 3; return; }
                uint16_t a_all24 = r->a;
                uint8_t value97 = BUS8_RDP(c, (uint16_t)(dp_ret21 + 4));
                r->a = (a_all24 >> 8 << 8) | (uint8_t)((uint8_t)(value97 << 1) + 0x0D);
                r->c = (uint8_t)(value97 << 1) + 0x0D > 0xFF;
                r->z = (uint8_t)((uint8_t)(value97 << 1) + 0x0D) == 0;
                r->n = (uint8_t)((uint8_t)(value97 << 1) + 0x0D) & 0x80;
                r->v = (((uint8_t)(value97 << 1) ^ (uint8_t)((uint8_t)(value97 << 1) + 0x0D)) & ((uint8_t)((uint8_t)(value97 << 1) + 0x0D) ^ 0x0D) & 0x80) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7FE, 0x7EC030); GUARD_JSR(c, sp_call, 0xC7FE); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret22 = r->db;
                uint16_t x_ret35 = r->x;
                BUS16_SET(c, (db_ret22 << 0x10) + 2 + x_ret35, 0);
                r->mf = 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC806, 0x7EC097); GUARD_JSR(c, sp_call, 0xC806); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret23 = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                uint16_t value98 = BUS16_RDP(c, (uint16_t)(dp_ret23 + 4));
                r->a = (uint16_t)((uint16_t)(value98 << 1) + 0x0E);
                r->c = (uint16_t)(value98 << 1) + 0x0E > 0xFFFF;
                r->z = (uint16_t)((uint16_t)(value98 << 1) + 0x0E) == 0;
                r->n = (uint16_t)((uint16_t)(value98 << 1) + 0x0E) & 0x8000;
                r->v = (((uint16_t)(value98 << 1) ^ (uint16_t)((uint16_t)(value98 << 1) + 0x0E)) & ((uint16_t)((uint16_t)(value98 << 1) + 0x0E) ^ 0x0E) & 0x8000) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC810, 0x7EC030); GUARD_JSR(c, sp_call, 0xC810); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret24 = r->db;
                bool m_ret17 = r->mf;
                uint16_t x_ret38 = r->x;
                if (m_ret17) {
                    BUS8_SET(c, (db_ret24 << 0x10) + 2 + x_ret38, 0);
                    r->mf = 1;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret25 = r->dp;
                    uint8_t db_ret25 = r->db;
                    bool m_ret18 = r->mf;
                    bool x_ret39 = r->xf;
                    if (x_ret39) {
                        uint8_t value99 = BUS8_RDP(c, (uint16_t)(dp_ret25 + 2));
                        uint8_t value100 = BUS8_RDP(c, (db_ret25 << 0x10) + 2 + value99);
                        uint8_t value101 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret18) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value102 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value103 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value104 = RAM8(0x0000 + sp0);
                            r->x = value100;
                            r->y = value99;
                            r->c = value102 & 0x01;
                            r->v = value102 & 0x40;
                            r->mf = value102 & 0x20;
                            r->xf = value102 & 0x10;
                            r->db = value101;
                            r->dp = (value104 << 8) | value103;
                            r->i = value102 & 0x04;
                            r->d = value102 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value105 = BUS16_RDP(c, (uint16_t)(dp_ret25 + 2));
                        uint16_t value106 = BUS16_RDP(c, (db_ret25 << 0x10) + 2 + value105);
                        uint8_t value107 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret18) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value108 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value109 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value110 = RAM8(0x0000 + sp0);
                            r->x = value106;
                            r->y = value105;
                            r->c = value108 & 0x01;
                            r->v = value108 & 0x40;
                            r->mf = value108 & 0x20;
                            r->xf = value108 & 0x10;
                            r->db = value107;
                            r->dp = (value110 << 8) | value109;
                            r->i = value108 & 0x04;
                            r->d = value108 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                } else {
                    BUS16_SET(c, (db_ret24 << 0x10) + 2 + x_ret38, 0);
                    r->mf = 0;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret26 = r->dp;
                    uint8_t db_ret26 = r->db;
                    bool m_ret19 = r->mf;
                    bool x_ret40 = r->xf;
                    if (x_ret40) {
                        uint8_t value111 = BUS8_RDP(c, (uint16_t)(dp_ret26 + 2));
                        uint8_t value112 = BUS8_RDP(c, (db_ret26 << 0x10) + 2 + value111);
                        uint8_t value113 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret19) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value114 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value115 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value116 = RAM8(0x0000 + sp0);
                            r->x = value112;
                            r->y = value111;
                            r->c = value114 & 0x01;
                            r->v = value114 & 0x40;
                            r->mf = value114 & 0x20;
                            r->xf = value114 & 0x10;
                            r->db = value113;
                            r->dp = (value116 << 8) | value115;
                            r->i = value114 & 0x04;
                            r->d = value114 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value117 = BUS16_RDP(c, (uint16_t)(dp_ret26 + 2));
                        uint16_t value118 = BUS16_RDP(c, (db_ret26 << 0x10) + 2 + value117);
                        uint8_t value119 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret19) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value120 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value121 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value122 = RAM8(0x0000 + sp0);
                            r->x = value118;
                            r->y = value117;
                            r->c = value120 & 0x01;
                            r->v = value120 & 0x40;
                            r->mf = value120 & 0x20;
                            r->xf = value120 & 0x10;
                            r->db = value119;
                            r->dp = (value122 << 8) | value121;
                            r->i = value120 & 0x04;
                            r->d = value120 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                }
            }
        }
    } else {
        uint16_t value123 = RAM16(0x0002 + (uint16_t)(sp0 - 9));
        BUS16_SET(c, 0x7F0002 + value123, x_ret2);
        BUS16_SET(c, 0x7F0004 + value123, 0);
        BUS16_SET(c, 0x7F0006 + value123, 0);
        uint8_t value125 = RAM8(0x0000 + sp0 - 0x0A);
        BUS8_SET(c, 0x7F0001 + value123, value125);
        r->a = ((RAM8(0x0001 + (uint16_t)(sp0 - 9)) & 0xFC) << 8) | (value125 >> 3);
        r->x = value123;
        r->c = value125 >> 2 & 0x01;
        r->z = value125 >> 3 == 0;
        r->n = value125 >> 3 & 0x80;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 10;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC7CE, 0x7ED5F3); GUARD_JSR(c, sp_call, 0xC7CE); } /* allocate_vram_pages */
        r->sp += 10;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret41 = r->xf;
        uint16_t a_all30 = r->a;
        if (x_ret41) {
            uint8_t value127 = RAM8(0x0002 + (uint16_t)(sp0 - 9));
            RAM8(0x10000 + value127) = (uint8_t)a_all30;
            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)((uint8_t)a_all30 << 2);
            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (RAM8(0x0001 + (uint16_t)(sp0 - 9)) & 3) | RAM8(0x0006 + (uint16_t)(sp0 - 9));
            uint8_t value130 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
            RAM8(0x0004 + (uint16_t)(sp0 - 9)) = (value130 >> 2) & 3;
            r->a = (a_all30 >> 8 << 8) | ((value130 >> 2) & 3) + 7;
            r->x = value127;
            r->y = (uint8_t)y_ret;
            r->c = ((value130 >> 2) & 3) + 7 > 0xFF;
            r->z = ((value130 >> 2) & 3) + 7 == 0;
            r->n = ((value130 >> 2) & 3) + 7 & 0x80;
            r->v = ((((value130 >> 2) & 3) ^ ((value130 >> 2) & 3) + 7) & (((value130 >> 2) & 3) + 7 ^ 7) & 0x80) != 0;
            r->xf = 1;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC7ED, 0x7EC030); GUARD_JSR(c, sp_call, 0xC7ED); } /* allocate_ppu_register_entry */
            r->sp += 10;
            uint16_t dp_ret27 = r->dp;
            uint8_t db_ret27 = r->db;
            bool m_ret20 = r->mf;
            uint16_t a_all31 = r->a;
            uint16_t x_ret44 = r->x;
            if (m_ret20) {
                uint8_t value131 = BUS8_RDP(c, (uint16_t)(dp_ret27 + 6));
                BUS8_SET(c, (db_ret27 << 0x10) + 2 + x_ret44, value131);
                r->a = (a_all31 >> 8 << 8) | value131;
                r->z = value131 == 0;
                r->n = value131 & 0x80;
                r->mf = 1;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7F5, 0x7EC097); GUARD_JSR(c, sp_call, 0xC7F5); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret28 = r->dp;
                if (r->mf != 1) { c->fail = 3; return; }
                uint16_t a_all32 = r->a;
                uint8_t value132 = BUS8_RDP(c, (uint16_t)(dp_ret28 + 4));
                r->a = (a_all32 >> 8 << 8) | (uint8_t)((uint8_t)(value132 << 1) + 0x0D);
                r->c = (uint8_t)(value132 << 1) + 0x0D > 0xFF;
                r->z = (uint8_t)((uint8_t)(value132 << 1) + 0x0D) == 0;
                r->n = (uint8_t)((uint8_t)(value132 << 1) + 0x0D) & 0x80;
                r->v = (((uint8_t)(value132 << 1) ^ (uint8_t)((uint8_t)(value132 << 1) + 0x0D)) & ((uint8_t)((uint8_t)(value132 << 1) + 0x0D) ^ 0x0D) & 0x80) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7FE, 0x7EC030); GUARD_JSR(c, sp_call, 0xC7FE); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret29 = r->db;
                uint16_t x_ret47 = r->x;
                BUS16_SET(c, (db_ret29 << 0x10) + 2 + x_ret47, 0);
                r->mf = 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC806, 0x7EC097); GUARD_JSR(c, sp_call, 0xC806); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret30 = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                uint16_t value133 = BUS16_RDP(c, (uint16_t)(dp_ret30 + 4));
                r->a = (uint16_t)((uint16_t)(value133 << 1) + 0x0E);
                r->c = (uint16_t)(value133 << 1) + 0x0E > 0xFFFF;
                r->z = (uint16_t)((uint16_t)(value133 << 1) + 0x0E) == 0;
                r->n = (uint16_t)((uint16_t)(value133 << 1) + 0x0E) & 0x8000;
                r->v = (((uint16_t)(value133 << 1) ^ (uint16_t)((uint16_t)(value133 << 1) + 0x0E)) & ((uint16_t)((uint16_t)(value133 << 1) + 0x0E) ^ 0x0E) & 0x8000) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC810, 0x7EC030); GUARD_JSR(c, sp_call, 0xC810); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret31 = r->db;
                bool m_ret22 = r->mf;
                uint16_t x_ret50 = r->x;
                if (m_ret22) {
                    BUS8_SET(c, (db_ret31 << 0x10) + 2 + x_ret50, 0);
                    r->mf = 1;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret32 = r->dp;
                    uint8_t db_ret32 = r->db;
                    bool m_ret23 = r->mf;
                    bool x_ret51 = r->xf;
                    if (x_ret51) {
                        uint8_t value134 = BUS8_RDP(c, (uint16_t)(dp_ret32 + 2));
                        uint8_t value135 = BUS8_RDP(c, (db_ret32 << 0x10) + 2 + value134);
                        uint8_t value136 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret23) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value137 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value138 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value139 = RAM8(0x0000 + sp0);
                            r->x = value135;
                            r->y = value134;
                            r->c = value137 & 0x01;
                            r->v = value137 & 0x40;
                            r->mf = value137 & 0x20;
                            r->xf = value137 & 0x10;
                            r->db = value136;
                            r->dp = (value139 << 8) | value138;
                            r->i = value137 & 0x04;
                            r->d = value137 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value140 = BUS16_RDP(c, (uint16_t)(dp_ret32 + 2));
                        uint16_t value141 = BUS16_RDP(c, (db_ret32 << 0x10) + 2 + value140);
                        uint8_t value142 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret23) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value143 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value144 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value145 = RAM8(0x0000 + sp0);
                            r->x = value141;
                            r->y = value140;
                            r->c = value143 & 0x01;
                            r->v = value143 & 0x40;
                            r->mf = value143 & 0x20;
                            r->xf = value143 & 0x10;
                            r->db = value142;
                            r->dp = (value145 << 8) | value144;
                            r->i = value143 & 0x04;
                            r->d = value143 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                } else {
                    BUS16_SET(c, (db_ret31 << 0x10) + 2 + x_ret50, 0);
                    r->mf = 0;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret33 = r->dp;
                    uint8_t db_ret33 = r->db;
                    bool m_ret24 = r->mf;
                    bool x_ret52 = r->xf;
                    if (x_ret52) {
                        uint8_t value146 = BUS8_RDP(c, (uint16_t)(dp_ret33 + 2));
                        uint8_t value147 = BUS8_RDP(c, (db_ret33 << 0x10) + 2 + value146);
                        uint8_t value148 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret24) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value149 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value150 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value151 = RAM8(0x0000 + sp0);
                            r->x = value147;
                            r->y = value146;
                            r->c = value149 & 0x01;
                            r->v = value149 & 0x40;
                            r->mf = value149 & 0x20;
                            r->xf = value149 & 0x10;
                            r->db = value148;
                            r->dp = (value151 << 8) | value150;
                            r->i = value149 & 0x04;
                            r->d = value149 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value152 = BUS16_RDP(c, (uint16_t)(dp_ret33 + 2));
                        uint16_t value153 = BUS16_RDP(c, (db_ret33 << 0x10) + 2 + value152);
                        uint8_t value154 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret24) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value155 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value156 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value157 = RAM8(0x0000 + sp0);
                            r->x = value153;
                            r->y = value152;
                            r->c = value155 & 0x01;
                            r->v = value155 & 0x40;
                            r->mf = value155 & 0x20;
                            r->xf = value155 & 0x10;
                            r->db = value154;
                            r->dp = (value157 << 8) | value156;
                            r->i = value155 & 0x04;
                            r->d = value155 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                }
            } else {
                uint16_t value158 = BUS16_RDP(c, (uint16_t)(dp_ret27 + 6));
                BUS16_SET(c, (db_ret27 << 0x10) + 2 + x_ret44, value158);
                r->a = value158;
                r->z = value158 == 0;
                r->n = value158 & 0x8000;
                r->mf = 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7F5, 0x7EC097); GUARD_JSR(c, sp_call, 0xC7F5); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret34 = r->dp;
                if (r->mf != 1) { c->fail = 3; return; }
                uint16_t a_all38 = r->a;
                uint8_t value159 = BUS8_RDP(c, (uint16_t)(dp_ret34 + 4));
                r->a = (a_all38 >> 8 << 8) | (uint8_t)((uint8_t)(value159 << 1) + 0x0D);
                r->c = (uint8_t)(value159 << 1) + 0x0D > 0xFF;
                r->z = (uint8_t)((uint8_t)(value159 << 1) + 0x0D) == 0;
                r->n = (uint8_t)((uint8_t)(value159 << 1) + 0x0D) & 0x80;
                r->v = (((uint8_t)(value159 << 1) ^ (uint8_t)((uint8_t)(value159 << 1) + 0x0D)) & ((uint8_t)((uint8_t)(value159 << 1) + 0x0D) ^ 0x0D) & 0x80) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7FE, 0x7EC030); GUARD_JSR(c, sp_call, 0xC7FE); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret35 = r->db;
                uint16_t x_ret55 = r->x;
                BUS16_SET(c, (db_ret35 << 0x10) + 2 + x_ret55, 0);
                r->mf = 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC806, 0x7EC097); GUARD_JSR(c, sp_call, 0xC806); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret36 = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                uint16_t value160 = BUS16_RDP(c, (uint16_t)(dp_ret36 + 4));
                r->a = (uint16_t)((uint16_t)(value160 << 1) + 0x0E);
                r->c = (uint16_t)(value160 << 1) + 0x0E > 0xFFFF;
                r->z = (uint16_t)((uint16_t)(value160 << 1) + 0x0E) == 0;
                r->n = (uint16_t)((uint16_t)(value160 << 1) + 0x0E) & 0x8000;
                r->v = (((uint16_t)(value160 << 1) ^ (uint16_t)((uint16_t)(value160 << 1) + 0x0E)) & ((uint16_t)((uint16_t)(value160 << 1) + 0x0E) ^ 0x0E) & 0x8000) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC810, 0x7EC030); GUARD_JSR(c, sp_call, 0xC810); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret37 = r->db;
                bool m_ret26 = r->mf;
                uint16_t x_ret58 = r->x;
                if (m_ret26) {
                    BUS8_SET(c, (db_ret37 << 0x10) + 2 + x_ret58, 0);
                    r->mf = 1;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret38 = r->dp;
                    uint8_t db_ret38 = r->db;
                    bool m_ret27 = r->mf;
                    bool x_ret59 = r->xf;
                    if (x_ret59) {
                        uint8_t value161 = BUS8_RDP(c, (uint16_t)(dp_ret38 + 2));
                        uint8_t value162 = BUS8_RDP(c, (db_ret38 << 0x10) + 2 + value161);
                        uint8_t value163 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret27) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value164 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value165 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value166 = RAM8(0x0000 + sp0);
                            r->x = value162;
                            r->y = value161;
                            r->c = value164 & 0x01;
                            r->v = value164 & 0x40;
                            r->mf = value164 & 0x20;
                            r->xf = value164 & 0x10;
                            r->db = value163;
                            r->dp = (value166 << 8) | value165;
                            r->i = value164 & 0x04;
                            r->d = value164 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value167 = BUS16_RDP(c, (uint16_t)(dp_ret38 + 2));
                        uint16_t value168 = BUS16_RDP(c, (db_ret38 << 0x10) + 2 + value167);
                        uint8_t value169 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret27) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value170 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value171 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value172 = RAM8(0x0000 + sp0);
                            r->x = value168;
                            r->y = value167;
                            r->c = value170 & 0x01;
                            r->v = value170 & 0x40;
                            r->mf = value170 & 0x20;
                            r->xf = value170 & 0x10;
                            r->db = value169;
                            r->dp = (value172 << 8) | value171;
                            r->i = value170 & 0x04;
                            r->d = value170 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                } else {
                    BUS16_SET(c, (db_ret37 << 0x10) + 2 + x_ret58, 0);
                    r->mf = 0;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret39 = r->dp;
                    uint8_t db_ret39 = r->db;
                    bool m_ret28 = r->mf;
                    bool x_ret60 = r->xf;
                    if (x_ret60) {
                        uint8_t value173 = BUS8_RDP(c, (uint16_t)(dp_ret39 + 2));
                        uint8_t value174 = BUS8_RDP(c, (db_ret39 << 0x10) + 2 + value173);
                        uint8_t value175 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret28) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value176 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value177 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value178 = RAM8(0x0000 + sp0);
                            r->x = value174;
                            r->y = value173;
                            r->c = value176 & 0x01;
                            r->v = value176 & 0x40;
                            r->mf = value176 & 0x20;
                            r->xf = value176 & 0x10;
                            r->db = value175;
                            r->dp = (value178 << 8) | value177;
                            r->i = value176 & 0x04;
                            r->d = value176 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value179 = BUS16_RDP(c, (uint16_t)(dp_ret39 + 2));
                        uint16_t value180 = BUS16_RDP(c, (db_ret39 << 0x10) + 2 + value179);
                        uint8_t value181 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret28) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value182 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value183 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value184 = RAM8(0x0000 + sp0);
                            r->x = value180;
                            r->y = value179;
                            r->c = value182 & 0x01;
                            r->v = value182 & 0x40;
                            r->mf = value182 & 0x20;
                            r->xf = value182 & 0x10;
                            r->db = value181;
                            r->dp = (value184 << 8) | value183;
                            r->i = value182 & 0x04;
                            r->d = value182 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                }
            }
        } else {
            uint16_t value185 = RAM16(0x0002 + (uint16_t)(sp0 - 9));
            RAM8(0x10000 + value185) = (uint8_t)a_all30;
            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)((uint8_t)a_all30 << 2);
            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (RAM8(0x0001 + (uint16_t)(sp0 - 9)) & 3) | RAM8(0x0006 + (uint16_t)(sp0 - 9));
            uint8_t value188 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
            RAM8(0x0004 + (uint16_t)(sp0 - 9)) = (value188 >> 2) & 3;
            r->a = (a_all30 >> 8 << 8) | ((value188 >> 2) & 3) + 7;
            r->x = value185;
            r->c = ((value188 >> 2) & 3) + 7 > 0xFF;
            r->z = ((value188 >> 2) & 3) + 7 == 0;
            r->n = ((value188 >> 2) & 3) + 7 & 0x80;
            r->v = ((((value188 >> 2) & 3) ^ ((value188 >> 2) & 3) + 7) & (((value188 >> 2) & 3) + 7 ^ 7) & 0x80) != 0;
            r->xf = 0;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC7ED, 0x7EC030); GUARD_JSR(c, sp_call, 0xC7ED); } /* allocate_ppu_register_entry */
            r->sp += 10;
            uint16_t dp_ret40 = r->dp;
            uint8_t db_ret40 = r->db;
            bool m_ret29 = r->mf;
            uint16_t a_all44 = r->a;
            uint16_t x_ret62 = r->x;
            if (m_ret29) {
                uint8_t value189 = BUS8_RDP(c, (uint16_t)(dp_ret40 + 6));
                BUS8_SET(c, (db_ret40 << 0x10) + 2 + x_ret62, value189);
                r->a = (a_all44 >> 8 << 8) | value189;
                r->z = value189 == 0;
                r->n = value189 & 0x80;
                r->mf = 1;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7F5, 0x7EC097); GUARD_JSR(c, sp_call, 0xC7F5); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret41 = r->dp;
                if (r->mf != 1) { c->fail = 3; return; }
                uint16_t a_all45 = r->a;
                uint8_t value190 = BUS8_RDP(c, (uint16_t)(dp_ret41 + 4));
                r->a = (a_all45 >> 8 << 8) | (uint8_t)((uint8_t)(value190 << 1) + 0x0D);
                r->c = (uint8_t)(value190 << 1) + 0x0D > 0xFF;
                r->z = (uint8_t)((uint8_t)(value190 << 1) + 0x0D) == 0;
                r->n = (uint8_t)((uint8_t)(value190 << 1) + 0x0D) & 0x80;
                r->v = (((uint8_t)(value190 << 1) ^ (uint8_t)((uint8_t)(value190 << 1) + 0x0D)) & ((uint8_t)((uint8_t)(value190 << 1) + 0x0D) ^ 0x0D) & 0x80) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7FE, 0x7EC030); GUARD_JSR(c, sp_call, 0xC7FE); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret42 = r->db;
                uint16_t x_ret65 = r->x;
                BUS16_SET(c, (db_ret42 << 0x10) + 2 + x_ret65, 0);
                r->mf = 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC806, 0x7EC097); GUARD_JSR(c, sp_call, 0xC806); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret43 = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                uint16_t value191 = BUS16_RDP(c, (uint16_t)(dp_ret43 + 4));
                r->a = (uint16_t)((uint16_t)(value191 << 1) + 0x0E);
                r->c = (uint16_t)(value191 << 1) + 0x0E > 0xFFFF;
                r->z = (uint16_t)((uint16_t)(value191 << 1) + 0x0E) == 0;
                r->n = (uint16_t)((uint16_t)(value191 << 1) + 0x0E) & 0x8000;
                r->v = (((uint16_t)(value191 << 1) ^ (uint16_t)((uint16_t)(value191 << 1) + 0x0E)) & ((uint16_t)((uint16_t)(value191 << 1) + 0x0E) ^ 0x0E) & 0x8000) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC810, 0x7EC030); GUARD_JSR(c, sp_call, 0xC810); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret44 = r->db;
                bool m_ret31 = r->mf;
                uint16_t x_ret68 = r->x;
                if (m_ret31) {
                    BUS8_SET(c, (db_ret44 << 0x10) + 2 + x_ret68, 0);
                    r->mf = 1;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret45 = r->dp;
                    uint8_t db_ret45 = r->db;
                    bool m_ret32 = r->mf;
                    bool x_ret69 = r->xf;
                    if (x_ret69) {
                        uint8_t value192 = BUS8_RDP(c, (uint16_t)(dp_ret45 + 2));
                        uint8_t value193 = BUS8_RDP(c, (db_ret45 << 0x10) + 2 + value192);
                        uint8_t value194 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret32) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value195 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value196 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value197 = RAM8(0x0000 + sp0);
                            r->x = value193;
                            r->y = value192;
                            r->c = value195 & 0x01;
                            r->v = value195 & 0x40;
                            r->mf = value195 & 0x20;
                            r->xf = value195 & 0x10;
                            r->db = value194;
                            r->dp = (value197 << 8) | value196;
                            r->i = value195 & 0x04;
                            r->d = value195 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value198 = BUS16_RDP(c, (uint16_t)(dp_ret45 + 2));
                        uint16_t value199 = BUS16_RDP(c, (db_ret45 << 0x10) + 2 + value198);
                        uint8_t value200 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret32) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value201 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value202 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value203 = RAM8(0x0000 + sp0);
                            r->x = value199;
                            r->y = value198;
                            r->c = value201 & 0x01;
                            r->v = value201 & 0x40;
                            r->mf = value201 & 0x20;
                            r->xf = value201 & 0x10;
                            r->db = value200;
                            r->dp = (value203 << 8) | value202;
                            r->i = value201 & 0x04;
                            r->d = value201 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                } else {
                    BUS16_SET(c, (db_ret44 << 0x10) + 2 + x_ret68, 0);
                    r->mf = 0;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret46 = r->dp;
                    uint8_t db_ret46 = r->db;
                    bool m_ret33 = r->mf;
                    bool x_ret70 = r->xf;
                    if (x_ret70) {
                        uint8_t value204 = BUS8_RDP(c, (uint16_t)(dp_ret46 + 2));
                        uint8_t value205 = BUS8_RDP(c, (db_ret46 << 0x10) + 2 + value204);
                        uint8_t value206 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret33) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value207 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value208 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value209 = RAM8(0x0000 + sp0);
                            r->x = value205;
                            r->y = value204;
                            r->c = value207 & 0x01;
                            r->v = value207 & 0x40;
                            r->mf = value207 & 0x20;
                            r->xf = value207 & 0x10;
                            r->db = value206;
                            r->dp = (value209 << 8) | value208;
                            r->i = value207 & 0x04;
                            r->d = value207 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value210 = BUS16_RDP(c, (uint16_t)(dp_ret46 + 2));
                        uint16_t value211 = BUS16_RDP(c, (db_ret46 << 0x10) + 2 + value210);
                        uint8_t value212 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret33) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value213 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value214 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value215 = RAM8(0x0000 + sp0);
                            r->x = value211;
                            r->y = value210;
                            r->c = value213 & 0x01;
                            r->v = value213 & 0x40;
                            r->mf = value213 & 0x20;
                            r->xf = value213 & 0x10;
                            r->db = value212;
                            r->dp = (value215 << 8) | value214;
                            r->i = value213 & 0x04;
                            r->d = value213 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                }
            } else {
                uint16_t value216 = BUS16_RDP(c, (uint16_t)(dp_ret40 + 6));
                BUS16_SET(c, (db_ret40 << 0x10) + 2 + x_ret62, value216);
                r->a = value216;
                r->z = value216 == 0;
                r->n = value216 & 0x8000;
                r->mf = 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7F5, 0x7EC097); GUARD_JSR(c, sp_call, 0xC7F5); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret47 = r->dp;
                if (r->mf != 1) { c->fail = 3; return; }
                uint16_t a_all51 = r->a;
                uint8_t value217 = BUS8_RDP(c, (uint16_t)(dp_ret47 + 4));
                r->a = (a_all51 >> 8 << 8) | (uint8_t)((uint8_t)(value217 << 1) + 0x0D);
                r->c = (uint8_t)(value217 << 1) + 0x0D > 0xFF;
                r->z = (uint8_t)((uint8_t)(value217 << 1) + 0x0D) == 0;
                r->n = (uint8_t)((uint8_t)(value217 << 1) + 0x0D) & 0x80;
                r->v = (((uint8_t)(value217 << 1) ^ (uint8_t)((uint8_t)(value217 << 1) + 0x0D)) & ((uint8_t)((uint8_t)(value217 << 1) + 0x0D) ^ 0x0D) & 0x80) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC7FE, 0x7EC030); GUARD_JSR(c, sp_call, 0xC7FE); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret48 = r->db;
                uint16_t x_ret73 = r->x;
                BUS16_SET(c, (db_ret48 << 0x10) + 2 + x_ret73, 0);
                r->mf = 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC806, 0x7EC097); GUARD_JSR(c, sp_call, 0xC806); } /* append_oneshot_ppu_entry */
                r->sp += 10;
                uint16_t dp_ret49 = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                uint16_t value218 = BUS16_RDP(c, (uint16_t)(dp_ret49 + 4));
                r->a = (uint16_t)((uint16_t)(value218 << 1) + 0x0E);
                r->c = (uint16_t)(value218 << 1) + 0x0E > 0xFFFF;
                r->z = (uint16_t)((uint16_t)(value218 << 1) + 0x0E) == 0;
                r->n = (uint16_t)((uint16_t)(value218 << 1) + 0x0E) & 0x8000;
                r->v = (((uint16_t)(value218 << 1) ^ (uint16_t)((uint16_t)(value218 << 1) + 0x0E)) & ((uint16_t)((uint16_t)(value218 << 1) + 0x0E) ^ 0x0E) & 0x8000) != 0;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC810, 0x7EC030); GUARD_JSR(c, sp_call, 0xC810); } /* allocate_ppu_register_entry */
                r->sp += 10;
                uint8_t db_ret50 = r->db;
                bool m_ret35 = r->mf;
                uint16_t x_ret76 = r->x;
                if (m_ret35) {
                    BUS8_SET(c, (db_ret50 << 0x10) + 2 + x_ret76, 0);
                    r->mf = 1;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret51 = r->dp;
                    uint8_t db_ret51 = r->db;
                    bool m_ret36 = r->mf;
                    bool x_ret77 = r->xf;
                    if (x_ret77) {
                        uint8_t value219 = BUS8_RDP(c, (uint16_t)(dp_ret51 + 2));
                        uint8_t value220 = BUS8_RDP(c, (db_ret51 << 0x10) + 2 + value219);
                        uint8_t value221 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret36) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value222 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value223 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value224 = RAM8(0x0000 + sp0);
                            r->x = value220;
                            r->y = value219;
                            r->c = value222 & 0x01;
                            r->v = value222 & 0x40;
                            r->mf = value222 & 0x20;
                            r->xf = value222 & 0x10;
                            r->db = value221;
                            r->dp = (value224 << 8) | value223;
                            r->i = value222 & 0x04;
                            r->d = value222 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value225 = BUS16_RDP(c, (uint16_t)(dp_ret51 + 2));
                        uint16_t value226 = BUS16_RDP(c, (db_ret51 << 0x10) + 2 + value225);
                        uint8_t value227 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret36) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value228 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value229 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value230 = RAM8(0x0000 + sp0);
                            r->x = value226;
                            r->y = value225;
                            r->c = value228 & 0x01;
                            r->v = value228 & 0x40;
                            r->mf = value228 & 0x20;
                            r->xf = value228 & 0x10;
                            r->db = value227;
                            r->dp = (value230 << 8) | value229;
                            r->i = value228 & 0x04;
                            r->d = value228 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                } else {
                    BUS16_SET(c, (db_ret50 << 0x10) + 2 + x_ret76, 0);
                    r->mf = 0;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC816, 0x7EC097); GUARD_JSR(c, sp_call, 0xC816); } /* append_oneshot_ppu_entry */
                    r->sp += 10;
                    uint16_t dp_ret52 = r->dp;
                    uint8_t db_ret52 = r->db;
                    bool m_ret37 = r->mf;
                    bool x_ret78 = r->xf;
                    if (x_ret78) {
                        uint8_t value231 = BUS8_RDP(c, (uint16_t)(dp_ret52 + 2));
                        uint8_t value232 = BUS8_RDP(c, (db_ret52 << 0x10) + 2 + value231);
                        uint8_t value233 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret37) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value234 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value235 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value236 = RAM8(0x0000 + sp0);
                            r->x = value232;
                            r->y = value231;
                            r->c = value234 & 0x01;
                            r->v = value234 & 0x40;
                            r->mf = value234 & 0x20;
                            r->xf = value234 & 0x10;
                            r->db = value233;
                            r->dp = (value236 << 8) | value235;
                            r->i = value234 & 0x04;
                            r->d = value234 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    } else {
                        uint16_t value237 = BUS16_RDP(c, (uint16_t)(dp_ret52 + 2));
                        uint16_t value238 = BUS16_RDP(c, (db_ret52 << 0x10) + 2 + value237);
                        uint8_t value239 = RAM8(0x0000 + sp0 - 9);
                        if (m_ret37) {
                            c->fail = 3; /* operand size does not fit the register width on this path */
                            return;
                        } else {
                            uint8_t value240 = RAM8(0x0000 + sp0 - 2);
                            uint8_t value241 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value242 = RAM8(0x0000 + sp0);
                            r->x = value238;
                            r->y = value237;
                            r->c = value240 & 0x01;
                            r->v = value240 & 0x40;
                            r->mf = value240 & 0x20;
                            r->xf = value240 & 0x10;
                            r->db = value239;
                            r->dp = (value242 << 8) | value241;
                            r->i = value240 & 0x04;
                            r->d = value240 & 0x08;
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                    }
                }
            }
        }
    }
}
SOM_REGISTER(0x7EC76D, SOM_RTS, "gen", create_registered_vram_buffer, 0, L_X | L_Y | L_C | L_V, 12, 0, 0, 185, 99)
