#include "som_c.h"

/* 7E8577 mark_cyclic_component_permutations   [class B, 144 bytes, 72 instructions]
 * Source: src/boot/mark_cyclic_component_permutations.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXY.
 */
static void mark_cyclic_component_permutations(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0C) + 0x9 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_85f7 = 0;
    uint8_t x_85f7 = 0;
    uint8_t y_85f7 = 0;
    uint16_t direct_page_85f7 = 0;
    uint8_t a_hi_85f72 = 0;
    uint16_t x_85f72 = 0;
    uint16_t y_85f72 = 0;
    uint16_t direct_page_85f72 = 0;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0006 + (uint16_t)(sp0 - 0x0C), x);
    uint16_t value = RAM16(0x0018);
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0C), (uint16_t)(value + 0x24));
    RAM16_SET(0x0008 + (uint16_t)(sp0 - 0x0C), (uint16_t)(value + 0x24));
    RAM8(0x0000 + (uint16_t)(value + 0x24)) = RAM8(0x0000 + x);
    uint16_t value3 = RAM16(0x0001 + x);
    RAM16_SET(0x0001 + (uint16_t)(value + 0x24), value3);
    r->a = value3;
    r->x = (uint16_t)(value + 0x24);
    r->y = x;
    r->c = value + 0x24 > 0xFFFF;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->v = ((value ^ (uint16_t)(value + 0x24)) & ((uint16_t)(value + 0x24) ^ 0x24) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x0C);
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x85A3, 0x7E84EB); GUARD_JSR(c, sp_call, 0x85A3); } /* mark_distinct_sign_reflections */
    r->sp += 12;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0C), a_all);
    uint16_t value4 = RAM16(0x0004 + (uint16_t)(sp0 - 0x0C));
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0C), (uint16_t)(value4 + 4));
    if (x_ret) {
        uint8_t value5 = RAM8(0x0006 + (uint16_t)(sp0 - 0x0C));
        uint16_t value6 = RAM16(0x0000 + value5);
        RAM16_SET(0x0001 + (uint8_t)(value4 + 4), value6);
        uint8_t value7 = RAM8(0x0002 + value5);
        RAM8(0x0000 + (uint8_t)(value4 + 4)) = value7;
        uint8_t value8 = RAM8(0x0008 + (uint16_t)(sp0 - 0x0C));
        r->a = (value6 >> 8 << 8) | value7;
        r->x = (uint8_t)(value4 + 4);
        r->y = value8;
        r->c = value4 + 4 > 0xFFFF;
        r->z = value8 == 0;
        r->n = value8 & 0x80;
        r->v = ((value4 ^ (uint16_t)(value4 + 4)) & ((uint16_t)(value4 + 4) ^ 4) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 1;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x85C3, 0x7E84AE); GUARD_JSR(c, sp_call, 0x85C3); } /* test_distinct_component_offset */
        r->sp += 12;
        uint16_t dp_ret = r->dp;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t y_ret2 = r->y;
        if ((uint8_t)a_all2 == 0) {
            if (x_ret3) {
                a_hi_85f7 = a_all2 >> 8;
                x_85f7 = (uint8_t)(value4 + 4);
                y_85f7 = (uint8_t)y_ret2;
                direct_page_85f7 = dp_ret;
                goto shared_85F7;
            } else {
                a_hi_85f72 = a_all2 >> 8;
                x_85f72 = (uint8_t)(value4 + 4);
                y_85f72 = y_ret2;
                direct_page_85f72 = dp_ret;
                goto shared_85F7_1;
            }
        }
        r->c = (uint8_t)a_all2 >= 0;
        r->z = (uint8_t)a_all2 == 0;
        r->n = (uint8_t)a_all2 & 0x80;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x85CA, 0x7E84EB); GUARD_JSR(c, sp_call, 0x85CA); } /* mark_distinct_sign_reflections */
        r->sp += 12;
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
        BUS16_SET(c, (uint16_t)(dp_ret + 2), (uint16_t)(a_all3 + value9));
        uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
        BUS16_SET(c, (uint16_t)(dp_ret + 4), (uint16_t)(value10 + 4));
        if (x_ret4) {
            uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret + 6));
            uint16_t value12 = RAM16(0x0001 + value11);
            RAM16_SET(0x0000 + (uint8_t)(value10 + 4), value12);
            uint8_t value13 = RAM8(0x0000 + value11);
            RAM8(0x0002 + (uint8_t)(value10 + 4)) = value13;
            r->a = (value12 >> 8 << 8) | value13;
            r->x = (uint8_t)(value10 + 4);
            r->y = value11;
            r->c = value10 + 4 > 0xFFFF;
            r->z = value13 == 0;
            r->n = value13 & 0x80;
            r->v = ((value10 ^ (uint16_t)(value10 + 4)) & ((uint16_t)(value10 + 4) ^ 4) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x85EF, 0x7E84EB); GUARD_JSR(c, sp_call, 0x85EF); } /* mark_distinct_sign_reflections */
            r->sp += 12;
            bool m_ret2 = r->mf;
            bool x_ret6 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret7 = r->x;
            uint16_t y_ret4 = r->y;
            if (m_ret2) {
                uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
                BUS8_SET(c, (uint16_t)(dp_ret + 2), (uint8_t)((uint8_t)a_all4 + value14));
                if (x_ret6) {
                    a_hi_85f7 = a_all4 >> 8;
                    x_85f7 = (uint8_t)x_ret7;
                    y_85f7 = (uint8_t)y_ret4;
                    direct_page_85f7 = dp_ret;
                    goto shared_85F7;
                } else {
                    a_hi_85f72 = a_all4 >> 8;
                    x_85f72 = x_ret7;
                    y_85f72 = y_ret4;
                    direct_page_85f72 = dp_ret;
                    goto shared_85F7_1;
                }
            } else {
                uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
                BUS16_SET(c, (uint16_t)(dp_ret + 2), (uint16_t)(a_all4 + value15));
                if (x_ret6) {
                    a_hi_85f7 = (uint16_t)(a_all4 + value15) >> 8;
                    x_85f7 = (uint8_t)x_ret7;
                    y_85f7 = (uint8_t)y_ret4;
                    direct_page_85f7 = dp_ret;
                    goto shared_85F7;
                } else {
                    a_hi_85f72 = (uint16_t)(a_all4 + value15) >> 8;
                    x_85f72 = x_ret7;
                    y_85f72 = y_ret4;
                    direct_page_85f72 = dp_ret;
                    goto shared_85F7_1;
                }
            }
        } else {
            uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp_ret + 6));
            uint16_t value17 = RAM16(0x0001 + value16);
            RAM16_SET(0x0000 + (uint16_t)(value10 + 4), value17);
            uint8_t value18 = RAM8(0x0000 + value16);
            RAM8(0x0002 + (uint16_t)(value10 + 4)) = value18;
            r->a = (value17 >> 8 << 8) | value18;
            r->x = (uint16_t)(value10 + 4);
            r->y = value16;
            r->c = value10 + 4 > 0xFFFF;
            r->z = value18 == 0;
            r->n = value18 & 0x80;
            r->v = ((value10 ^ (uint16_t)(value10 + 4)) & ((uint16_t)(value10 + 4) ^ 4) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x85EF, 0x7E84EB); GUARD_JSR(c, sp_call, 0x85EF); } /* mark_distinct_sign_reflections */
            r->sp += 12;
            bool m_ret3 = r->mf;
            bool x_ret8 = r->xf;
            uint16_t a_all5 = r->a;
            uint16_t x_ret9 = r->x;
            uint16_t y_ret5 = r->y;
            if (m_ret3) {
                uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
                BUS8_SET(c, (uint16_t)(dp_ret + 2), (uint8_t)((uint8_t)a_all5 + value19));
                if (x_ret8) {
                    a_hi_85f7 = a_all5 >> 8;
                    x_85f7 = (uint8_t)x_ret9;
                    y_85f7 = (uint8_t)y_ret5;
                    direct_page_85f7 = dp_ret;
                    goto shared_85F7;
                } else {
                    a_hi_85f72 = a_all5 >> 8;
                    x_85f72 = x_ret9;
                    y_85f72 = y_ret5;
                    direct_page_85f72 = dp_ret;
                    goto shared_85F7_1;
                }
            } else {
                uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
                BUS16_SET(c, (uint16_t)(dp_ret + 2), (uint16_t)(a_all5 + value20));
                if (x_ret8) {
                    a_hi_85f7 = (uint16_t)(a_all5 + value20) >> 8;
                    x_85f7 = (uint8_t)x_ret9;
                    y_85f7 = (uint8_t)y_ret5;
                    direct_page_85f7 = dp_ret;
                    goto shared_85F7;
                } else {
                    a_hi_85f72 = (uint16_t)(a_all5 + value20) >> 8;
                    x_85f72 = x_ret9;
                    y_85f72 = y_ret5;
                    direct_page_85f72 = dp_ret;
                    goto shared_85F7_1;
                }
            }
        }
    } else {
        uint16_t value21 = RAM16(0x0006 + (uint16_t)(sp0 - 0x0C));
        uint16_t value22 = RAM16(0x0000 + value21);
        RAM16_SET(0x0001 + (uint16_t)(value4 + 4), value22);
        uint8_t value23 = RAM8(0x0002 + value21);
        RAM8(0x0000 + (uint16_t)(value4 + 4)) = value23;
        uint16_t value24 = RAM16(0x0008 + (uint16_t)(sp0 - 0x0C));
        r->a = (value22 >> 8 << 8) | value23;
        r->x = (uint16_t)(value4 + 4);
        r->y = value24;
        r->c = value4 + 4 > 0xFFFF;
        r->z = value24 == 0;
        r->n = value24 & 0x8000;
        r->v = ((value4 ^ (uint16_t)(value4 + 4)) & ((uint16_t)(value4 + 4) ^ 4) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x85C3, 0x7E84AE); GUARD_JSR(c, sp_call, 0x85C3); } /* test_distinct_component_offset */
        r->sp += 12;
        uint16_t dp_ret2 = r->dp;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret10 = r->xf;
        uint16_t a_all6 = r->a;
        uint16_t y_ret6 = r->y;
        if ((uint8_t)a_all6 == 0) {
            if (x_ret10) {
                a_hi_85f7 = a_all6 >> 8;
                x_85f7 = (uint8_t)(value4 + 4);
                y_85f7 = (uint8_t)y_ret6;
                direct_page_85f7 = dp_ret2;
                goto shared_85F7;
            } else {
                a_hi_85f72 = a_all6 >> 8;
                x_85f72 = (uint16_t)(value4 + 4);
                y_85f72 = y_ret6;
                direct_page_85f72 = dp_ret2;
                goto shared_85F7_1;
            }
        }
        r->c = (uint8_t)a_all6 >= 0;
        r->z = (uint8_t)a_all6 == 0;
        r->n = (uint8_t)a_all6 & 0x80;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x85CA, 0x7E84EB); GUARD_JSR(c, sp_call, 0x85CA); } /* mark_distinct_sign_reflections */
        r->sp += 12;
        bool x_ret11 = r->xf;
        uint16_t a_all7 = r->a;
        uint16_t value25 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 2));
        BUS16_SET(c, (uint16_t)(dp_ret2 + 2), (uint16_t)(a_all7 + value25));
        uint16_t value26 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 4));
        BUS16_SET(c, (uint16_t)(dp_ret2 + 4), (uint16_t)(value26 + 4));
        if (x_ret11) {
            uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 6));
            uint16_t value28 = RAM16(0x0001 + value27);
            RAM16_SET(0x0000 + (uint8_t)(value26 + 4), value28);
            uint8_t value29 = RAM8(0x0000 + value27);
            RAM8(0x0002 + (uint8_t)(value26 + 4)) = value29;
            r->a = (value28 >> 8 << 8) | value29;
            r->x = (uint8_t)(value26 + 4);
            r->y = value27;
            r->c = value26 + 4 > 0xFFFF;
            r->z = value29 == 0;
            r->n = value29 & 0x80;
            r->v = ((value26 ^ (uint16_t)(value26 + 4)) & ((uint16_t)(value26 + 4) ^ 4) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x85EF, 0x7E84EB); GUARD_JSR(c, sp_call, 0x85EF); } /* mark_distinct_sign_reflections */
            r->sp += 12;
            bool m_ret5 = r->mf;
            bool x_ret13 = r->xf;
            uint16_t a_all8 = r->a;
            uint16_t x_ret14 = r->x;
            uint16_t y_ret8 = r->y;
            if (m_ret5) {
                uint8_t value30 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 2));
                BUS8_SET(c, (uint16_t)(dp_ret2 + 2), (uint8_t)((uint8_t)a_all8 + value30));
                if (x_ret13) {
                    a_hi_85f7 = a_all8 >> 8;
                    x_85f7 = (uint8_t)x_ret14;
                    y_85f7 = (uint8_t)y_ret8;
                    direct_page_85f7 = dp_ret2;
                    goto shared_85F7;
                } else {
                    a_hi_85f72 = a_all8 >> 8;
                    x_85f72 = x_ret14;
                    y_85f72 = y_ret8;
                    direct_page_85f72 = dp_ret2;
                    goto shared_85F7_1;
                }
            } else {
                uint16_t value31 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 2));
                BUS16_SET(c, (uint16_t)(dp_ret2 + 2), (uint16_t)(a_all8 + value31));
                if (x_ret13) {
                    a_hi_85f7 = (uint16_t)(a_all8 + value31) >> 8;
                    x_85f7 = (uint8_t)x_ret14;
                    y_85f7 = (uint8_t)y_ret8;
                    direct_page_85f7 = dp_ret2;
                    goto shared_85F7;
                } else {
                    a_hi_85f72 = (uint16_t)(a_all8 + value31) >> 8;
                    x_85f72 = x_ret14;
                    y_85f72 = y_ret8;
                    direct_page_85f72 = dp_ret2;
                    goto shared_85F7_1;
                }
            }
        } else {
            uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 6));
            uint16_t value33 = RAM16(0x0001 + value32);
            RAM16_SET(0x0000 + (uint16_t)(value26 + 4), value33);
            uint8_t value34 = RAM8(0x0000 + value32);
            RAM8(0x0002 + (uint16_t)(value26 + 4)) = value34;
            r->a = (value33 >> 8 << 8) | value34;
            r->x = (uint16_t)(value26 + 4);
            r->y = value32;
            r->c = value26 + 4 > 0xFFFF;
            r->z = value34 == 0;
            r->n = value34 & 0x80;
            r->v = ((value26 ^ (uint16_t)(value26 + 4)) & ((uint16_t)(value26 + 4) ^ 4) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x85EF, 0x7E84EB); GUARD_JSR(c, sp_call, 0x85EF); } /* mark_distinct_sign_reflections */
            r->sp += 12;
            bool m_ret6 = r->mf;
            bool x_ret15 = r->xf;
            uint16_t a_all9 = r->a;
            uint16_t x_ret16 = r->x;
            uint16_t y_ret9 = r->y;
            if (m_ret6) {
                uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 2));
                BUS8_SET(c, (uint16_t)(dp_ret2 + 2), (uint8_t)((uint8_t)a_all9 + value35));
                if (x_ret15) {
                    a_hi_85f7 = a_all9 >> 8;
                    x_85f7 = (uint8_t)x_ret16;
                    y_85f7 = (uint8_t)y_ret9;
                    direct_page_85f7 = dp_ret2;
                    goto shared_85F7;
                } else {
                    a_hi_85f72 = a_all9 >> 8;
                    x_85f72 = x_ret16;
                    y_85f72 = y_ret9;
                    direct_page_85f72 = dp_ret2;
                    goto shared_85F7_1;
                }
            } else {
                uint16_t value36 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 2));
                BUS16_SET(c, (uint16_t)(dp_ret2 + 2), (uint16_t)(a_all9 + value36));
                if (x_ret15) {
                    a_hi_85f7 = (uint16_t)(a_all9 + value36) >> 8;
                    x_85f7 = (uint8_t)x_ret16;
                    y_85f7 = (uint8_t)y_ret9;
                    direct_page_85f7 = dp_ret2;
                    goto shared_85F7;
                } else {
                    a_hi_85f72 = (uint16_t)(a_all9 + value36) >> 8;
                    x_85f72 = x_ret16;
                    y_85f72 = y_ret9;
                    direct_page_85f72 = dp_ret2;
                    goto shared_85F7_1;
                }
            }
        }
    }
    shared_85F7:;
    uint16_t value37 = BUS16_RDP(c, (uint16_t)(direct_page_85f7 + 2));
    RAM16_SET(0x0000 + sp0 - 4, value37);
    uint8_t value38 = RAM8(0x0000 + sp0 - 4);
    uint8_t value39 = RAM8(0x0000 + sp0 - 3);
    uint8_t value40 = RAM8(0x0000 + sp0 - 2);
    uint8_t value41 = RAM8(0x0000 + sp0 - 1);
    uint8_t value42 = RAM8(0x0000 + sp0);
    r->a = (value39 << 8) | value38;
    r->x = x_85f7;
    r->y = y_85f7;
    r->mf = value40 & 0x20;
    r->xf = value40 & 0x10;
    r->db = 0x7E;
    r->dp = (value42 << 8) | value41;
    r->i = value40 & 0x04;
    r->d = value40 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_85F7_1:;
    uint16_t value43 = BUS16_RDP(c, (uint16_t)(direct_page_85f72 + 2));
    RAM16_SET(0x0000 + sp0 - 4, value43);
    uint8_t value44 = RAM8(0x0000 + sp0 - 4);
    uint8_t value45 = RAM8(0x0000 + sp0 - 3);
    uint8_t value46 = RAM8(0x0000 + sp0 - 2);
    uint8_t value47 = RAM8(0x0000 + sp0 - 1);
    uint8_t value48 = RAM8(0x0000 + sp0);
    r->a = (value45 << 8) | value44;
    r->x = x_85f72;
    r->y = y_85f72;
    r->mf = value46 & 0x20;
    r->xf = value46 & 0x10;
    r->db = 0x7E;
    r->dp = (value48 << 8) | value47;
    r->i = value46 & 0x04;
    r->d = value46 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E8577, SOM_RTS, "gen", mark_cyclic_component_permutations, 0, L_A | L_B | L_X | L_Y, 12, 1, 0, 144, 72)
