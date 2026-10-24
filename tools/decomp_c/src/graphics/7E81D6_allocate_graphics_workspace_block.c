#include "som_c.h"

/* 7E81D6 allocate_graphics_workspace_block   [class B, 161 bytes, 90 instructions]
 * Source: src/boot/allocate_graphics_workspace_block.s
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void allocate_graphics_workspace_block(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 0x0C) + 0x9 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 0x0C) = db;
    RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0E) = 0x7F;
    r->a = value;
    r->c = (uint16_t)(sp0 - 5) >= 7;
    r->z = (uint8_t)value == 0;
    r->n = (uint8_t)value & 0x80;
    r->v = (((uint16_t)(sp0 - 5) ^ 7) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 0x0C)) & 0x8000) != 0;
    r->mf = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 0x0C);
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0x81F1, 0x7E805F); GUARD_JSR(c, sp_call, 0x81F1); } /* select_graphics_registration */
    r->sp += 13;
    uint16_t a_all = r->a;
    RAM16_SET(0x0008 + (uint16_t)(sp0 - 0x0C), a_all);
    uint16_t value2 = BUS16(c, 0x7F0004 + a_all);
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0C), value2);
    uint16_t value3 = BUS16(c, 0x7F0006 + a_all);
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0C), value3);
    uint16_t value4 = BUS16(c, 0x7F0002 + a_all);
    uint16_t value5 = BUS16(c, 0x7F0001 + a_all);
    uint8_t a1 = 0;
    uint8_t a_hi1 = value5 & 0xFF;
    uint16_t y1 = value4 & 0xFF;
    for (;;) {
        uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) >> 1);
        uint8_t a_hi1_next = ((a_hi1 << 8) | a1) >> 1 >> 8;
        uint16_t y1_next = (uint16_t)(y1 - 1);
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        y1 = y1_next;
        if (!(y1 != 0)) break;
    }
    uint16_t value6 = RAM16(0x0002 + (uint16_t)(sp0 - 0x0C));
    RAM16_SET(0x0006 + (uint16_t)(sp0 - 0x0C), (uint16_t)(((a_hi1 << 8) | a1) + value6));
    uint16_t value7 = RAM16(0x0004 + (uint16_t)(sp0 - 0x0C));
    uint8_t a_hi2 = (uint16_t)(((a_hi1 << 8) | a1) + value6) >> 8;
    uint16_t x1 = value7;
    bool carry1 = ((a_hi1 << 8) | a1) + value6 > 0xFFFF;
    for (;;) {
        uint8_t value8 = RAM8(0x10000 + x1);
        if (value8 != 0) {
            uint16_t value9 = RAM16(0x0006 + (uint16_t)(sp0 - 0x0C));
            uint16_t x2;
            if ((uint16_t)(x1 + 1) < value9) {
                x2 = (uint16_t)(x1 + 1);
            } else {
                x2 = RAM16(0x0002 + (uint16_t)(sp0 - 0x0C));
            }
            uint16_t value11 = RAM16(0x0004 + (uint16_t)(sp0 - 0x0C));
            if (x2 != value11) {
                x1 = x2;
                carry1 = x2 >= value11;
                continue;
            }
            uint8_t value12 = RAM8(0x0000 + sp0 - 0x0C);
            uint8_t value13 = RAM8(0x0000 + sp0 - 2);
            uint8_t value14 = RAM8(0x0000 + sp0 - 1);
            uint8_t value15 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((uint16_t)(sp0 - 0x0C) + 9);
            r->x = 0xFFFF;
            r->y = y1;
            r->c = value13 & 0x01;
            r->v = value13 & 0x40;
            r->mf = value13 & 0x20;
            r->xf = value13 & 0x10;
            r->db = value12;
            r->dp = (value15 << 8) | value14;
            r->i = value13 & 0x04;
            r->d = value13 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0C), x1);
        r->a = (a_hi2 << 8) | value8;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = value8 == 0;
        r->n = value8 & 0x80;
        r->v = ((((a_hi1 << 8) | a1) ^ (uint16_t)(((a_hi1 << 8) | a1) + value6)) & (value6 ^ (uint16_t)(((a_hi1 << 8) | a1) + value6)) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8233, 0x7EACE9); GUARD_JSR(c, sp_call, 0x8233); } /* current_task_id */
        r->sp += 13;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all2 = r->a;
        if (x_ret) {
            uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp_ret + 4));
            if (m_ret) {
                BUS8_SET(c, (db_ret << 0x10) + value16, (uint8_t)a_all2);
                uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp_ret + 8));
                BUS16_SET(c, (db_ret << 0x10) + 4 + value17, value16);
                uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
                BUS16_SET(c, (uint16_t)(dp_ret + 4), (uint16_t)((uint16_t)(value16 - value18) << 5));
                uint16_t value19 = BUS16_RDP(c, (db_ret << 0x10) + 2 + value17);
                if (value19 == 3) {
                    uint16_t value20 = BUS16_RDP(c, (db_ret << 0x10) + value17);
                    uint16_t value21 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                    uint8_t value22 = RAM8(0x0000 + sp0 - 0x0C);
                    uint8_t value23 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value24 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value25 = RAM8(0x0000 + sp0);
                    r->a = (uint16_t)((uint16_t)(sp0 - 0x0C) + 9);
                    r->x = (uint8_t)((((uint8_t)((value20 & 0xFF) << 1 << 1) << 8) | ((value20 & 0xFF) << 1 << 1 >> 8)) + value21);
                    r->y = value16;
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
                uint16_t value26 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret + 4), value26 >> 1);
                if (value19 != 2) {
                    uint16_t value27 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                    BUS16_RMW_SET(c, (uint16_t)(dp_ret + 4), value27 >> 1);
                }
                uint16_t value28 = BUS16_RDP(c, (db_ret << 0x10) + value17);
                uint16_t value29 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                uint8_t value30 = RAM8(0x0000 + sp0 - 0x0C);
                uint8_t value31 = RAM8(0x0000 + sp0 - 2);
                uint8_t value32 = RAM8(0x0000 + sp0 - 1);
                uint8_t value33 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 0x0C) + 9);
                r->x = (uint8_t)((((uint8_t)((value28 & 0xFF) << 1 << 1) << 8) | ((value28 & 0xFF) << 1 << 1 >> 8)) + value29);
                r->y = value16;
                r->c = value31 & 0x01;
                r->v = value31 & 0x40;
                r->mf = value31 & 0x20;
                r->xf = value31 & 0x10;
                r->db = value30;
                r->dp = (value33 << 8) | value32;
                r->i = value31 & 0x04;
                r->d = value31 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                BUS16_SET(c, (db_ret << 0x10) + value16, a_all2);
                uint8_t value34 = BUS8_RDP(c, (uint16_t)(dp_ret + 8));
                BUS16_SET(c, (db_ret << 0x10) + 4 + value34, value16);
                uint16_t value35 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
                BUS16_SET(c, (uint16_t)(dp_ret + 4), (uint16_t)((uint16_t)(value16 - value35) << 5));
                uint16_t value36 = BUS16_RDP(c, (db_ret << 0x10) + 2 + value34);
                if (value36 == 3) {
                    uint16_t value37 = BUS16_RDP(c, (db_ret << 0x10) + value34);
                    uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                    uint8_t value39 = RAM8(0x0000 + sp0 - 0x0C);
                    uint8_t value40 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value41 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value42 = RAM8(0x0000 + sp0);
                    r->a = (uint16_t)((uint16_t)(sp0 - 0x0C) + 9);
                    r->x = (uint8_t)((((uint8_t)((value37 & 0xFF) << 1 << 1) << 8) | ((value37 & 0xFF) << 1 << 1 >> 8)) + value38);
                    r->y = value16;
                    r->c = value40 & 0x01;
                    r->v = value40 & 0x40;
                    r->mf = value40 & 0x20;
                    r->xf = value40 & 0x10;
                    r->db = value39;
                    r->dp = (value42 << 8) | value41;
                    r->i = value40 & 0x04;
                    r->d = value40 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                uint16_t value43 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret + 4), value43 >> 1);
                if (value36 != 2) {
                    uint16_t value44 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                    BUS16_RMW_SET(c, (uint16_t)(dp_ret + 4), value44 >> 1);
                }
                uint16_t value45 = BUS16_RDP(c, (db_ret << 0x10) + value34);
                uint16_t value46 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                uint8_t value47 = RAM8(0x0000 + sp0 - 0x0C);
                uint8_t value48 = RAM8(0x0000 + sp0 - 2);
                uint8_t value49 = RAM8(0x0000 + sp0 - 1);
                uint8_t value50 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 0x0C) + 9);
                r->x = (uint8_t)((((uint8_t)((value45 & 0xFF) << 1 << 1) << 8) | ((value45 & 0xFF) << 1 << 1 >> 8)) + value46);
                r->y = value16;
                r->c = value48 & 0x01;
                r->v = value48 & 0x40;
                r->mf = value48 & 0x20;
                r->xf = value48 & 0x10;
                r->db = value47;
                r->dp = (value50 << 8) | value49;
                r->i = value48 & 0x04;
                r->d = value48 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            uint16_t value51 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
            if (m_ret) {
                BUS8_SET(c, (db_ret << 0x10) + value51, (uint8_t)a_all2);
                uint16_t value52 = BUS16_RDP(c, (uint16_t)(dp_ret + 8));
                BUS16_SET(c, (db_ret << 0x10) + 4 + value52, value51);
                uint16_t value53 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
                BUS16_SET(c, (uint16_t)(dp_ret + 4), (uint16_t)((uint16_t)(value51 - value53) << 5));
                uint16_t value54 = BUS16_RDP(c, (db_ret << 0x10) + 2 + value52);
                if (value54 == 3) {
                    uint16_t value55 = BUS16_RDP(c, (db_ret << 0x10) + value52);
                    uint16_t value56 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                    uint8_t value57 = RAM8(0x0000 + sp0 - 0x0C);
                    uint8_t value58 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value59 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value60 = RAM8(0x0000 + sp0);
                    r->a = (uint16_t)((uint16_t)(sp0 - 0x0C) + 9);
                    r->x = (uint16_t)((((uint8_t)((value55 & 0xFF) << 1 << 1) << 8) | ((value55 & 0xFF) << 1 << 1 >> 8)) + value56);
                    r->y = value51;
                    r->c = value58 & 0x01;
                    r->v = value58 & 0x40;
                    r->mf = value58 & 0x20;
                    r->xf = value58 & 0x10;
                    r->db = value57;
                    r->dp = (value60 << 8) | value59;
                    r->i = value58 & 0x04;
                    r->d = value58 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                uint16_t value61 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret + 4), value61 >> 1);
                if (value54 != 2) {
                    uint16_t value62 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                    BUS16_RMW_SET(c, (uint16_t)(dp_ret + 4), value62 >> 1);
                }
                uint16_t value63 = BUS16_RDP(c, (db_ret << 0x10) + value52);
                uint16_t value64 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                uint8_t value65 = RAM8(0x0000 + sp0 - 0x0C);
                uint8_t value66 = RAM8(0x0000 + sp0 - 2);
                uint8_t value67 = RAM8(0x0000 + sp0 - 1);
                uint8_t value68 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 0x0C) + 9);
                r->x = (uint16_t)((((uint8_t)((value63 & 0xFF) << 1 << 1) << 8) | ((value63 & 0xFF) << 1 << 1 >> 8)) + value64);
                r->y = value51;
                r->c = value66 & 0x01;
                r->v = value66 & 0x40;
                r->mf = value66 & 0x20;
                r->xf = value66 & 0x10;
                r->db = value65;
                r->dp = (value68 << 8) | value67;
                r->i = value66 & 0x04;
                r->d = value66 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                BUS16_SET(c, (db_ret << 0x10) + value51, a_all2);
                uint16_t value69 = BUS16_RDP(c, (uint16_t)(dp_ret + 8));
                BUS16_SET(c, (db_ret << 0x10) + 4 + value69, value51);
                uint16_t value70 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
                BUS16_SET(c, (uint16_t)(dp_ret + 4), (uint16_t)((uint16_t)(value51 - value70) << 5));
                uint16_t value71 = BUS16_RDP(c, (db_ret << 0x10) + 2 + value69);
                if (value71 == 3) {
                    uint16_t value72 = BUS16_RDP(c, (db_ret << 0x10) + value69);
                    uint16_t value73 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                    uint8_t value74 = RAM8(0x0000 + sp0 - 0x0C);
                    uint8_t value75 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value76 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value77 = RAM8(0x0000 + sp0);
                    r->a = (uint16_t)((uint16_t)(sp0 - 0x0C) + 9);
                    r->x = (uint16_t)((((uint8_t)((value72 & 0xFF) << 1 << 1) << 8) | ((value72 & 0xFF) << 1 << 1 >> 8)) + value73);
                    r->y = value51;
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
                uint16_t value78 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret + 4), value78 >> 1);
                if (value71 != 2) {
                    uint16_t value79 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                    BUS16_RMW_SET(c, (uint16_t)(dp_ret + 4), value79 >> 1);
                }
                uint16_t value80 = BUS16_RDP(c, (db_ret << 0x10) + value69);
                uint16_t value81 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                uint8_t value82 = RAM8(0x0000 + sp0 - 0x0C);
                uint8_t value83 = RAM8(0x0000 + sp0 - 2);
                uint8_t value84 = RAM8(0x0000 + sp0 - 1);
                uint8_t value85 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 0x0C) + 9);
                r->x = (uint16_t)((((uint8_t)((value80 & 0xFF) << 1 << 1) << 8) | ((value80 & 0xFF) << 1 << 1 >> 8)) + value81);
                r->y = value51;
                r->c = value83 & 0x01;
                r->v = value83 & 0x40;
                r->mf = value83 & 0x20;
                r->xf = value83 & 0x10;
                r->db = value82;
                r->dp = (value85 << 8) | value84;
                r->i = value83 & 0x04;
                r->d = value83 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
}
SOM_REGISTER(0x7E81D6, SOM_RTS, "gen", allocate_graphics_workspace_block, 0, L_B | L_X | L_Y | L_C | L_V, 15, -1, 0, 161, 90)
