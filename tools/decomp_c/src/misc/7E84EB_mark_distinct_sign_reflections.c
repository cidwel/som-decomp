#include "som_c.h"

/* 7E84EB mark_distinct_sign_reflections   [class B, 140 bytes, 81 instructions]
 * Source: src/boot/mark_distinct_sign_reflections.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXY.
 */
static void mark_distinct_sign_reflections(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
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
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 0x0C) + 0x9 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0006 + (uint16_t)(sp0 - 0x0C), x);
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0x18);
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0C), (uint16_t)(value + 4));
    RAM16_SET(0x0008 + (uint16_t)(sp0 - 0x0C), (uint16_t)(value + 4));
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0C), 0);
    uint8_t a1 = 0;
    uint8_t a_hi1 = (uint16_t)(value + 4) >> 8;
    uint16_t x1 = (uint16_t)(value + 4);
    uint16_t y1 = y;
    bool carry1 = value + 4 > 0xFFFF;
    bool overflow1 = ((value ^ (uint16_t)(value + 4)) & ((uint16_t)(value + 4) ^ 4) & 0x8000) != 0;
    uint16_t direct_page = (uint16_t)(sp0 - 0x0C);
    for (;;) {
        BUS8_SET(c, (uint16_t)(direct_page + 1), a1);
        uint16_t value2 = BUS16_RDP(c, (uint16_t)(direct_page + 6));
        uint8_t value3 = BUS8_RDP(c, (db << 0x10) + value2);
        if ((a1 & 1) == 0) {
            BUS8_SET(c, (db << 0x10) + x1, value3);
            uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 1 + value2);
            if ((a1 & 2) == 0) {
                BUS8_SET(c, (db << 0x10) + 1 + x1, value4);
                uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 2 + value2);
                if ((a1 & 4) == 0) {
                    BUS8_SET(c, (db << 0x10) + 2 + x1, value5);
                    uint16_t value6 = BUS16_RDP(c, (uint16_t)(direct_page + 8));
                    r->a = (a1 << 8) | value5;
                    r->x = x1;
                    r->y = value6;
                    r->c = carry1;
                    r->z = value6 == 0;
                    r->n = value6 & 0x8000;
                    r->v = overflow1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = db;
                    r->dp = direct_page;
                    r->sp -= 12;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8546, 0x7E84AE); GUARD_JSR(c, sp_call, 0x8546); } /* test_distinct_component_offset */
                    r->sp += 12;
                    uint16_t dp_ret = r->dp;
                    if (r->mf != 1) { c->fail = 3; return; }
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t a_all = r->a;
                    uint16_t y_ret = r->y;
                    bool overflow_ret = r->v;
                    if ((uint8_t)a_all == 0) {
                        uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                        if ((uint8_t)(value7 + 1) < 8) {
                            a1 = (uint8_t)(value7 + 1);
                            a_hi1 = a_all >> 8;
                            y1 = y_ret;
                            carry1 = (uint8_t)(value7 + 1) >= 8;
                            overflow1 = overflow_ret;
                            direct_page = dp_ret;
                            continue;
                        }
                        a1 = (uint8_t)(value7 + 1);
                        a_hi1 = a_all >> 8;
                        y1 = y_ret;
                        carry1 = (uint8_t)(value7 + 1) >= 8;
                        overflow1 = overflow_ret;
                        direct_page = dp_ret;
                        break;
                    }
                    r->c = (uint8_t)a_all >= 0;
                    r->z = (uint8_t)a_all == 0;
                    r->n = (uint8_t)a_all & 0x80;
                    r->sp -= 12;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x854D, 0x7E8444); GUARD_JSR(c, sp_call, 0x854D); } /* mark_translated_colour_candidates */
                    r->sp += 12;
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t a_all2 = r->a;
                    uint16_t y_ret2 = r->y;
                    uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
                    BUS16_SET(c, (uint16_t)(dp_ret + 2), (uint16_t)(a_all2 + value8));
                    uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
                    BUS16_SET(c, (uint16_t)(dp_ret + 4), (uint16_t)(value9 + 4));
                    uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                    if ((uint8_t)(value10 + 1) < 8) {
                        a1 = (uint8_t)(value10 + 1);
                        a_hi1 = (uint16_t)(value9 + 4) >> 8;
                        x1 = (uint16_t)(value9 + 4);
                        y1 = y_ret2;
                        carry1 = (uint8_t)(value10 + 1) >= 8;
                        overflow1 = ((value9 ^ (uint16_t)(value9 + 4)) & ((uint16_t)(value9 + 4) ^ 4) & 0x8000) != 0;
                        direct_page = dp_ret;
                        continue;
                    }
                    a1 = (uint8_t)(value10 + 1);
                    a_hi1 = (uint16_t)(value9 + 4) >> 8;
                    x1 = (uint16_t)(value9 + 4);
                    y1 = y_ret2;
                    carry1 = (uint8_t)(value10 + 1) >= 8;
                    overflow1 = ((value9 ^ (uint16_t)(value9 + 4)) & ((uint16_t)(value9 + 4) ^ 4) & 0x8000) != 0;
                    direct_page = dp_ret;
                    break;
                }
                BUS8_SET(c, (db << 0x10) + 2 + x1, (uint8_t)((value5 ^ 0xFF) + 1));
                uint16_t value11 = BUS16_RDP(c, (uint16_t)(direct_page + 8));
                r->a = (a1 << 8) | (uint8_t)((value5 ^ 0xFF) + 1);
                r->x = x1;
                r->y = value11;
                r->c = carry1;
                r->z = value11 == 0;
                r->n = value11 & 0x8000;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = db;
                r->dp = direct_page;
                r->sp -= 12;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8546, 0x7E84AE); GUARD_JSR(c, sp_call, 0x8546); } /* test_distinct_component_offset */
                r->sp += 12;
                uint16_t dp_ret2 = r->dp;
                if (r->mf != 1) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all3 = r->a;
                uint16_t y_ret3 = r->y;
                bool overflow_ret3 = r->v;
                if ((uint8_t)a_all3 == 0) {
                    uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                    if ((uint8_t)(value12 + 1) < 8) {
                        a1 = (uint8_t)(value12 + 1);
                        a_hi1 = a_all3 >> 8;
                        y1 = y_ret3;
                        carry1 = (uint8_t)(value12 + 1) >= 8;
                        overflow1 = overflow_ret3;
                        direct_page = dp_ret2;
                        continue;
                    }
                    a1 = (uint8_t)(value12 + 1);
                    a_hi1 = a_all3 >> 8;
                    y1 = y_ret3;
                    carry1 = (uint8_t)(value12 + 1) >= 8;
                    overflow1 = overflow_ret3;
                    direct_page = dp_ret2;
                    break;
                }
                r->c = (uint8_t)a_all3 >= 0;
                r->z = (uint8_t)a_all3 == 0;
                r->n = (uint8_t)a_all3 & 0x80;
                r->sp -= 12;
                { const uint16_t sp_call = r->sp; JSR(c, 0x854D, 0x7E8444); GUARD_JSR(c, sp_call, 0x854D); } /* mark_translated_colour_candidates */
                r->sp += 12;
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all4 = r->a;
                uint16_t y_ret4 = r->y;
                uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 2));
                BUS16_SET(c, (uint16_t)(dp_ret2 + 2), (uint16_t)(a_all4 + value13));
                uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 4));
                BUS16_SET(c, (uint16_t)(dp_ret2 + 4), (uint16_t)(value14 + 4));
                uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                if ((uint8_t)(value15 + 1) < 8) {
                    a1 = (uint8_t)(value15 + 1);
                    a_hi1 = (uint16_t)(value14 + 4) >> 8;
                    x1 = (uint16_t)(value14 + 4);
                    y1 = y_ret4;
                    carry1 = (uint8_t)(value15 + 1) >= 8;
                    overflow1 = ((value14 ^ (uint16_t)(value14 + 4)) & ((uint16_t)(value14 + 4) ^ 4) & 0x8000) != 0;
                    direct_page = dp_ret2;
                    continue;
                }
                a1 = (uint8_t)(value15 + 1);
                a_hi1 = (uint16_t)(value14 + 4) >> 8;
                x1 = (uint16_t)(value14 + 4);
                y1 = y_ret4;
                carry1 = (uint8_t)(value15 + 1) >= 8;
                overflow1 = ((value14 ^ (uint16_t)(value14 + 4)) & ((uint16_t)(value14 + 4) ^ 4) & 0x8000) != 0;
                direct_page = dp_ret2;
                break;
            }
            BUS8_SET(c, (db << 0x10) + 1 + x1, (uint8_t)((value4 ^ 0xFF) + 1));
            uint8_t value16 = BUS8_RDP(c, (db << 0x10) + 2 + value2);
            if ((a1 & 4) == 0) {
                BUS8_SET(c, (db << 0x10) + 2 + x1, value16);
                uint16_t value17 = BUS16_RDP(c, (uint16_t)(direct_page + 8));
                r->a = (a1 << 8) | value16;
                r->x = x1;
                r->y = value17;
                r->c = carry1;
                r->z = value17 == 0;
                r->n = value17 & 0x8000;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = db;
                r->dp = direct_page;
                r->sp -= 12;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8546, 0x7E84AE); GUARD_JSR(c, sp_call, 0x8546); } /* test_distinct_component_offset */
                r->sp += 12;
                uint16_t dp_ret3 = r->dp;
                if (r->mf != 1) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all5 = r->a;
                uint16_t y_ret5 = r->y;
                bool overflow_ret5 = r->v;
                if ((uint8_t)a_all5 == 0) {
                    uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                    if ((uint8_t)(value18 + 1) < 8) {
                        a1 = (uint8_t)(value18 + 1);
                        a_hi1 = a_all5 >> 8;
                        y1 = y_ret5;
                        carry1 = (uint8_t)(value18 + 1) >= 8;
                        overflow1 = overflow_ret5;
                        direct_page = dp_ret3;
                        continue;
                    }
                    a1 = (uint8_t)(value18 + 1);
                    a_hi1 = a_all5 >> 8;
                    y1 = y_ret5;
                    carry1 = (uint8_t)(value18 + 1) >= 8;
                    overflow1 = overflow_ret5;
                    direct_page = dp_ret3;
                    break;
                }
                r->c = (uint8_t)a_all5 >= 0;
                r->z = (uint8_t)a_all5 == 0;
                r->n = (uint8_t)a_all5 & 0x80;
                r->sp -= 12;
                { const uint16_t sp_call = r->sp; JSR(c, 0x854D, 0x7E8444); GUARD_JSR(c, sp_call, 0x854D); } /* mark_translated_colour_candidates */
                r->sp += 12;
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all6 = r->a;
                uint16_t y_ret6 = r->y;
                uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 2));
                BUS16_SET(c, (uint16_t)(dp_ret3 + 2), (uint16_t)(a_all6 + value19));
                uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 4));
                BUS16_SET(c, (uint16_t)(dp_ret3 + 4), (uint16_t)(value20 + 4));
                uint8_t value21 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                if ((uint8_t)(value21 + 1) < 8) {
                    a1 = (uint8_t)(value21 + 1);
                    a_hi1 = (uint16_t)(value20 + 4) >> 8;
                    x1 = (uint16_t)(value20 + 4);
                    y1 = y_ret6;
                    carry1 = (uint8_t)(value21 + 1) >= 8;
                    overflow1 = ((value20 ^ (uint16_t)(value20 + 4)) & ((uint16_t)(value20 + 4) ^ 4) & 0x8000) != 0;
                    direct_page = dp_ret3;
                    continue;
                }
                a1 = (uint8_t)(value21 + 1);
                a_hi1 = (uint16_t)(value20 + 4) >> 8;
                x1 = (uint16_t)(value20 + 4);
                y1 = y_ret6;
                carry1 = (uint8_t)(value21 + 1) >= 8;
                overflow1 = ((value20 ^ (uint16_t)(value20 + 4)) & ((uint16_t)(value20 + 4) ^ 4) & 0x8000) != 0;
                direct_page = dp_ret3;
                break;
            }
            BUS8_SET(c, (db << 0x10) + 2 + x1, (uint8_t)((value16 ^ 0xFF) + 1));
            uint16_t value22 = BUS16_RDP(c, (uint16_t)(direct_page + 8));
            r->a = (a1 << 8) | (uint8_t)((value16 ^ 0xFF) + 1);
            r->x = x1;
            r->y = value22;
            r->c = carry1;
            r->z = value22 == 0;
            r->n = value22 & 0x8000;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = db;
            r->dp = direct_page;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8546, 0x7E84AE); GUARD_JSR(c, sp_call, 0x8546); } /* test_distinct_component_offset */
            r->sp += 12;
            uint16_t dp_ret4 = r->dp;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all7 = r->a;
            uint16_t y_ret7 = r->y;
            bool overflow_ret7 = r->v;
            if ((uint8_t)a_all7 == 0) {
                uint8_t value23 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                if ((uint8_t)(value23 + 1) < 8) {
                    a1 = (uint8_t)(value23 + 1);
                    a_hi1 = a_all7 >> 8;
                    y1 = y_ret7;
                    carry1 = (uint8_t)(value23 + 1) >= 8;
                    overflow1 = overflow_ret7;
                    direct_page = dp_ret4;
                    continue;
                }
                a1 = (uint8_t)(value23 + 1);
                a_hi1 = a_all7 >> 8;
                y1 = y_ret7;
                carry1 = (uint8_t)(value23 + 1) >= 8;
                overflow1 = overflow_ret7;
                direct_page = dp_ret4;
                break;
            }
            r->c = (uint8_t)a_all7 >= 0;
            r->z = (uint8_t)a_all7 == 0;
            r->n = (uint8_t)a_all7 & 0x80;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x854D, 0x7E8444); GUARD_JSR(c, sp_call, 0x854D); } /* mark_translated_colour_candidates */
            r->sp += 12;
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all8 = r->a;
            uint16_t y_ret8 = r->y;
            uint16_t value24 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 2));
            BUS16_SET(c, (uint16_t)(dp_ret4 + 2), (uint16_t)(a_all8 + value24));
            uint16_t value25 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 4));
            BUS16_SET(c, (uint16_t)(dp_ret4 + 4), (uint16_t)(value25 + 4));
            uint8_t value26 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
            if ((uint8_t)(value26 + 1) < 8) {
                a1 = (uint8_t)(value26 + 1);
                a_hi1 = (uint16_t)(value25 + 4) >> 8;
                x1 = (uint16_t)(value25 + 4);
                y1 = y_ret8;
                carry1 = (uint8_t)(value26 + 1) >= 8;
                overflow1 = ((value25 ^ (uint16_t)(value25 + 4)) & ((uint16_t)(value25 + 4) ^ 4) & 0x8000) != 0;
                direct_page = dp_ret4;
                continue;
            }
            a1 = (uint8_t)(value26 + 1);
            a_hi1 = (uint16_t)(value25 + 4) >> 8;
            x1 = (uint16_t)(value25 + 4);
            y1 = y_ret8;
            carry1 = (uint8_t)(value26 + 1) >= 8;
            overflow1 = ((value25 ^ (uint16_t)(value25 + 4)) & ((uint16_t)(value25 + 4) ^ 4) & 0x8000) != 0;
            direct_page = dp_ret4;
            break;
        }
        BUS8_SET(c, (db << 0x10) + x1, (uint8_t)((value3 ^ 0xFF) + 1));
        uint8_t value27 = BUS8_RDP(c, (db << 0x10) + 1 + value2);
        if ((a1 & 2) == 0) {
            BUS8_SET(c, (db << 0x10) + 1 + x1, value27);
            uint8_t value28 = BUS8_RDP(c, (db << 0x10) + 2 + value2);
            if ((a1 & 4) == 0) {
                BUS8_SET(c, (db << 0x10) + 2 + x1, value28);
                uint16_t value29 = BUS16_RDP(c, (uint16_t)(direct_page + 8));
                r->a = (a1 << 8) | value28;
                r->x = x1;
                r->y = value29;
                r->c = carry1;
                r->z = value29 == 0;
                r->n = value29 & 0x8000;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = db;
                r->dp = direct_page;
                r->sp -= 12;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8546, 0x7E84AE); GUARD_JSR(c, sp_call, 0x8546); } /* test_distinct_component_offset */
                r->sp += 12;
                uint16_t dp_ret5 = r->dp;
                if (r->mf != 1) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all9 = r->a;
                uint16_t y_ret9 = r->y;
                bool overflow_ret9 = r->v;
                if ((uint8_t)a_all9 == 0) {
                    uint8_t value30 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 1));
                    if ((uint8_t)(value30 + 1) < 8) {
                        a1 = (uint8_t)(value30 + 1);
                        a_hi1 = a_all9 >> 8;
                        y1 = y_ret9;
                        carry1 = (uint8_t)(value30 + 1) >= 8;
                        overflow1 = overflow_ret9;
                        direct_page = dp_ret5;
                        continue;
                    }
                    a1 = (uint8_t)(value30 + 1);
                    a_hi1 = a_all9 >> 8;
                    y1 = y_ret9;
                    carry1 = (uint8_t)(value30 + 1) >= 8;
                    overflow1 = overflow_ret9;
                    direct_page = dp_ret5;
                    break;
                }
                r->c = (uint8_t)a_all9 >= 0;
                r->z = (uint8_t)a_all9 == 0;
                r->n = (uint8_t)a_all9 & 0x80;
                r->sp -= 12;
                { const uint16_t sp_call = r->sp; JSR(c, 0x854D, 0x7E8444); GUARD_JSR(c, sp_call, 0x854D); } /* mark_translated_colour_candidates */
                r->sp += 12;
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all10 = r->a;
                uint16_t y_ret10 = r->y;
                uint16_t value31 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 2));
                BUS16_SET(c, (uint16_t)(dp_ret5 + 2), (uint16_t)(a_all10 + value31));
                uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 4));
                BUS16_SET(c, (uint16_t)(dp_ret5 + 4), (uint16_t)(value32 + 4));
                uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 1));
                if ((uint8_t)(value33 + 1) < 8) {
                    a1 = (uint8_t)(value33 + 1);
                    a_hi1 = (uint16_t)(value32 + 4) >> 8;
                    x1 = (uint16_t)(value32 + 4);
                    y1 = y_ret10;
                    carry1 = (uint8_t)(value33 + 1) >= 8;
                    overflow1 = ((value32 ^ (uint16_t)(value32 + 4)) & ((uint16_t)(value32 + 4) ^ 4) & 0x8000) != 0;
                    direct_page = dp_ret5;
                    continue;
                }
                a1 = (uint8_t)(value33 + 1);
                a_hi1 = (uint16_t)(value32 + 4) >> 8;
                x1 = (uint16_t)(value32 + 4);
                y1 = y_ret10;
                carry1 = (uint8_t)(value33 + 1) >= 8;
                overflow1 = ((value32 ^ (uint16_t)(value32 + 4)) & ((uint16_t)(value32 + 4) ^ 4) & 0x8000) != 0;
                direct_page = dp_ret5;
                break;
            }
            BUS8_SET(c, (db << 0x10) + 2 + x1, (uint8_t)((value28 ^ 0xFF) + 1));
            uint16_t value34 = BUS16_RDP(c, (uint16_t)(direct_page + 8));
            r->a = (a1 << 8) | (uint8_t)((value28 ^ 0xFF) + 1);
            r->x = x1;
            r->y = value34;
            r->c = carry1;
            r->z = value34 == 0;
            r->n = value34 & 0x8000;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = db;
            r->dp = direct_page;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8546, 0x7E84AE); GUARD_JSR(c, sp_call, 0x8546); } /* test_distinct_component_offset */
            r->sp += 12;
            uint16_t dp_ret6 = r->dp;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all11 = r->a;
            uint16_t y_ret11 = r->y;
            bool overflow_ret11 = r->v;
            if ((uint8_t)a_all11 == 0) {
                uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 1));
                if ((uint8_t)(value35 + 1) < 8) {
                    a1 = (uint8_t)(value35 + 1);
                    a_hi1 = a_all11 >> 8;
                    y1 = y_ret11;
                    carry1 = (uint8_t)(value35 + 1) >= 8;
                    overflow1 = overflow_ret11;
                    direct_page = dp_ret6;
                    continue;
                }
                a1 = (uint8_t)(value35 + 1);
                a_hi1 = a_all11 >> 8;
                y1 = y_ret11;
                carry1 = (uint8_t)(value35 + 1) >= 8;
                overflow1 = overflow_ret11;
                direct_page = dp_ret6;
                break;
            }
            r->c = (uint8_t)a_all11 >= 0;
            r->z = (uint8_t)a_all11 == 0;
            r->n = (uint8_t)a_all11 & 0x80;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x854D, 0x7E8444); GUARD_JSR(c, sp_call, 0x854D); } /* mark_translated_colour_candidates */
            r->sp += 12;
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all12 = r->a;
            uint16_t y_ret12 = r->y;
            uint16_t value36 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 2));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 2), (uint16_t)(a_all12 + value36));
            uint16_t value37 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 4));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 4), (uint16_t)(value37 + 4));
            uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 1));
            if ((uint8_t)(value38 + 1) < 8) {
                a1 = (uint8_t)(value38 + 1);
                a_hi1 = (uint16_t)(value37 + 4) >> 8;
                x1 = (uint16_t)(value37 + 4);
                y1 = y_ret12;
                carry1 = (uint8_t)(value38 + 1) >= 8;
                overflow1 = ((value37 ^ (uint16_t)(value37 + 4)) & ((uint16_t)(value37 + 4) ^ 4) & 0x8000) != 0;
                direct_page = dp_ret6;
                continue;
            }
            a1 = (uint8_t)(value38 + 1);
            a_hi1 = (uint16_t)(value37 + 4) >> 8;
            x1 = (uint16_t)(value37 + 4);
            y1 = y_ret12;
            carry1 = (uint8_t)(value38 + 1) >= 8;
            overflow1 = ((value37 ^ (uint16_t)(value37 + 4)) & ((uint16_t)(value37 + 4) ^ 4) & 0x8000) != 0;
            direct_page = dp_ret6;
            break;
        }
        BUS8_SET(c, (db << 0x10) + 1 + x1, (uint8_t)((value27 ^ 0xFF) + 1));
        uint8_t value39 = BUS8_RDP(c, (db << 0x10) + 2 + value2);
        if ((a1 & 4) == 0) {
            BUS8_SET(c, (db << 0x10) + 2 + x1, value39);
            uint16_t value40 = BUS16_RDP(c, (uint16_t)(direct_page + 8));
            r->a = (a1 << 8) | value39;
            r->x = x1;
            r->y = value40;
            r->c = carry1;
            r->z = value40 == 0;
            r->n = value40 & 0x8000;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = db;
            r->dp = direct_page;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8546, 0x7E84AE); GUARD_JSR(c, sp_call, 0x8546); } /* test_distinct_component_offset */
            r->sp += 12;
            uint16_t dp_ret7 = r->dp;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all13 = r->a;
            uint16_t y_ret13 = r->y;
            bool overflow_ret13 = r->v;
            if ((uint8_t)a_all13 == 0) {
                uint8_t value41 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 1));
                if ((uint8_t)(value41 + 1) < 8) {
                    a1 = (uint8_t)(value41 + 1);
                    a_hi1 = a_all13 >> 8;
                    y1 = y_ret13;
                    carry1 = (uint8_t)(value41 + 1) >= 8;
                    overflow1 = overflow_ret13;
                    direct_page = dp_ret7;
                    continue;
                }
                a1 = (uint8_t)(value41 + 1);
                a_hi1 = a_all13 >> 8;
                y1 = y_ret13;
                carry1 = (uint8_t)(value41 + 1) >= 8;
                overflow1 = overflow_ret13;
                direct_page = dp_ret7;
                break;
            }
            r->c = (uint8_t)a_all13 >= 0;
            r->z = (uint8_t)a_all13 == 0;
            r->n = (uint8_t)a_all13 & 0x80;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x854D, 0x7E8444); GUARD_JSR(c, sp_call, 0x854D); } /* mark_translated_colour_candidates */
            r->sp += 12;
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all14 = r->a;
            uint16_t y_ret14 = r->y;
            uint16_t value42 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 2));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 2), (uint16_t)(a_all14 + value42));
            uint16_t value43 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 4));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 4), (uint16_t)(value43 + 4));
            uint8_t value44 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 1));
            if ((uint8_t)(value44 + 1) < 8) {
                a1 = (uint8_t)(value44 + 1);
                a_hi1 = (uint16_t)(value43 + 4) >> 8;
                x1 = (uint16_t)(value43 + 4);
                y1 = y_ret14;
                carry1 = (uint8_t)(value44 + 1) >= 8;
                overflow1 = ((value43 ^ (uint16_t)(value43 + 4)) & ((uint16_t)(value43 + 4) ^ 4) & 0x8000) != 0;
                direct_page = dp_ret7;
                continue;
            }
            a1 = (uint8_t)(value44 + 1);
            a_hi1 = (uint16_t)(value43 + 4) >> 8;
            x1 = (uint16_t)(value43 + 4);
            y1 = y_ret14;
            carry1 = (uint8_t)(value44 + 1) >= 8;
            overflow1 = ((value43 ^ (uint16_t)(value43 + 4)) & ((uint16_t)(value43 + 4) ^ 4) & 0x8000) != 0;
            direct_page = dp_ret7;
            break;
        }
        BUS8_SET(c, (db << 0x10) + 2 + x1, (uint8_t)((value39 ^ 0xFF) + 1));
        uint16_t value45 = BUS16_RDP(c, (uint16_t)(direct_page + 8));
        r->a = (a1 << 8) | (uint8_t)((value39 ^ 0xFF) + 1);
        r->x = x1;
        r->y = value45;
        r->c = carry1;
        r->z = value45 == 0;
        r->n = value45 & 0x8000;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = db;
        r->dp = direct_page;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8546, 0x7E84AE); GUARD_JSR(c, sp_call, 0x8546); } /* test_distinct_component_offset */
        r->sp += 12;
        uint16_t dp_ret8 = r->dp;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all15 = r->a;
        uint16_t y_ret15 = r->y;
        bool overflow_ret15 = r->v;
        if ((uint8_t)a_all15 == 0) {
            uint8_t value46 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 1));
            if ((uint8_t)(value46 + 1) < 8) {
                a1 = (uint8_t)(value46 + 1);
                a_hi1 = a_all15 >> 8;
                y1 = y_ret15;
                carry1 = (uint8_t)(value46 + 1) >= 8;
                overflow1 = overflow_ret15;
                direct_page = dp_ret8;
                continue;
            }
            a1 = (uint8_t)(value46 + 1);
            a_hi1 = a_all15 >> 8;
            y1 = y_ret15;
            carry1 = (uint8_t)(value46 + 1) >= 8;
            overflow1 = overflow_ret15;
            direct_page = dp_ret8;
            break;
        }
        r->c = (uint8_t)a_all15 >= 0;
        r->z = (uint8_t)a_all15 == 0;
        r->n = (uint8_t)a_all15 & 0x80;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x854D, 0x7E8444); GUARD_JSR(c, sp_call, 0x854D); } /* mark_translated_colour_candidates */
        r->sp += 12;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all16 = r->a;
        uint16_t y_ret16 = r->y;
        uint16_t value47 = BUS16_RDP(c, (uint16_t)(dp_ret8 + 2));
        BUS16_SET(c, (uint16_t)(dp_ret8 + 2), (uint16_t)(a_all16 + value47));
        uint16_t value48 = BUS16_RDP(c, (uint16_t)(dp_ret8 + 4));
        BUS16_SET(c, (uint16_t)(dp_ret8 + 4), (uint16_t)(value48 + 4));
        uint8_t value49 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 1));
        if ((uint8_t)(value49 + 1) < 8) {
            a1 = (uint8_t)(value49 + 1);
            a_hi1 = (uint16_t)(value48 + 4) >> 8;
            x1 = (uint16_t)(value48 + 4);
            y1 = y_ret16;
            carry1 = (uint8_t)(value49 + 1) >= 8;
            overflow1 = ((value48 ^ (uint16_t)(value48 + 4)) & ((uint16_t)(value48 + 4) ^ 4) & 0x8000) != 0;
            direct_page = dp_ret8;
            continue;
        }
        a1 = (uint8_t)(value49 + 1);
        a_hi1 = (uint16_t)(value48 + 4) >> 8;
        x1 = (uint16_t)(value48 + 4);
        y1 = y_ret16;
        carry1 = (uint8_t)(value49 + 1) >= 8;
        overflow1 = ((value48 ^ (uint16_t)(value48 + 4)) & ((uint16_t)(value48 + 4) ^ 4) & 0x8000) != 0;
        direct_page = dp_ret8;
        break;
    }
    uint16_t value50 = BUS16_RDP(c, (uint16_t)(direct_page + 2));
    RAM16_SET(0x0000 + sp0 - 4, value50);
    uint8_t value51 = RAM8(0x0000 + sp0 - 4);
    uint8_t value52 = RAM8(0x0000 + sp0 - 3);
    uint8_t value53 = RAM8(0x0000 + sp0 - 2);
    uint8_t value54 = RAM8(0x0000 + sp0 - 1);
    uint8_t value55 = RAM8(0x0000 + sp0);
    r->a = (value52 << 8) | value51;
    r->x = x1;
    r->y = y1;
    r->mf = value53 & 0x20;
    r->xf = value53 & 0x10;
    r->db = db;
    r->dp = (value55 << 8) | value54;
    r->i = value53 & 0x04;
    r->d = value53 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E84EB, SOM_RTS, "gen", mark_distinct_sign_reflections, 0, L_A | L_B | L_X | L_Y, 12, 1, 0, 140, 81)
