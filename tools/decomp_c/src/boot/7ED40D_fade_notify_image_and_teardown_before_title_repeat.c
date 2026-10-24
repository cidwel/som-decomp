#include "som_c.h"

/* 7ED40D fade_notify_image_and_teardown_before_title_repeat   [class B, 56 bytes, 27 instructions]
 * Source: src/boot/fade_notify_image_and_teardown_before_title_repeat.s
 * Documented in docs/boot-native-title-repeat-finish.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYV.
 */
static void fade_notify_image_and_teardown_before_title_repeat(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp + 1;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0 - 1) = dp >> 8;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 3) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    r->a = (uint16_t)(sp0 - 5);
    r->z = (uint16_t)(sp0 - 5) == 0;
    r->n = (uint16_t)(sp0 - 5) & 0x8000;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD418, 0x7ED1DA); GUARD_JSR(c, sp_call, 0xD418); } /* fade_parent_display_until_control_exit */
    r->sp += 4;
    uint16_t a_all = r->a;
    if ((uint8_t)a_all == 0) {
        RAM8(0x0000 + sp0 - 4) = (uint8_t)a_all;
        uint8_t value = RAM8(0x0000 + sp0 - 4);
        uint8_t value2 = RAM8(0x0000 + sp0 - 3);
        uint8_t value3 = RAM8(0x0000 + sp0 - 2);
        uint8_t value4 = RAM8(0x0000 + sp0 - 1);
        r->a = (a_all >> 8 << 8) | value;
        r->v = value2 & 0x40;
        r->mf = value2 & 0x20;
        r->xf = value2 & 0x10;
        r->dp = (value4 << 8) | value3;
        r->i = value2 & 0x04;
        r->d = value2 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    r->x = 4;
    r->c = (uint8_t)a_all >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD422, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD422); } /* dispatch_parent_messages */
    r->sp += 4;
    uint16_t a_all2 = r->a;
    if ((uint8_t)a_all2 == 0) {
        RAM8(0x0000 + sp0 - 4) = (uint8_t)a_all2;
        uint8_t value5 = RAM8(0x0000 + sp0 - 4);
        uint8_t value6 = RAM8(0x0000 + sp0 - 3);
        uint8_t value7 = RAM8(0x0000 + sp0 - 2);
        uint8_t value8 = RAM8(0x0000 + sp0 - 1);
        r->a = (a_all2 >> 8 << 8) | value5;
        r->v = value6 & 0x40;
        r->mf = value6 & 0x20;
        r->xf = value6 & 0x10;
        r->dp = (value8 << 8) | value7;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    r->c = (uint8_t)a_all2 >= 0;
    r->z = (uint8_t)a_all2 == 0;
    r->n = (uint8_t)a_all2 & 0x80;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD429, 0x7EB1A9); GUARD_JSR(c, sp_call, 0xD429); } /* allocate_eight_byte_record */
    r->sp += 4;
    uint8_t db_ret3 = r->db;
    bool m_ret = r->mf;
    uint16_t a_all3 = r->a;
    if (m_ret) {
        uint8_t value9 = BUS8_RDP(c, (db_ret3 << 0x10) + 0x0311);
        r->a = (a_all3 >> 8 << 8) | value9;
        r->z = value9 == 0;
        r->n = value9 & 0x80;
        r->mf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD42F, 0x7EB258); GUARD_JSR(c, sp_call, 0xD42F); } /* append_pending_record */
        r->sp += 4;
        uint8_t db_ret4 = r->db;
        bool m_ret2 = r->mf;
        if (m_ret2) {
            BUS8_SET(c, (db_ret4 << 0x10) + 0x0312, 0);
            BUS8_SET(c, (db_ret4 << 0x10) + 0x0311, 0);
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD438, 0x7ED3AA); GUARD_JSR(c, sp_call, 0xD438); } /* teardown_title_window_and_tracked_tasks */
            r->sp += 4;
            r->x = 0xB4;
            r->z = 0;
            r->n = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD43E, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD43E); } /* dispatch_parent_messages */
            r->sp += 4;
            bool m_ret4 = r->mf;
            uint16_t a_all6 = r->a;
            if (m_ret4) {
                RAM8(0x0000 + sp0 - 4) = (uint8_t)a_all6;
                uint8_t value10 = RAM8(0x0000 + sp0 - 4);
                uint8_t value11 = RAM8(0x0000 + sp0 - 3);
                uint8_t value12 = RAM8(0x0000 + sp0 - 2);
                uint8_t value13 = RAM8(0x0000 + sp0 - 1);
                r->a = (a_all6 >> 8 << 8) | value10;
                r->v = value11 & 0x40;
                r->mf = value11 & 0x20;
                r->xf = value11 & 0x10;
                r->dp = (value13 << 8) | value12;
                r->i = value11 & 0x04;
                r->d = value11 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                RAM16_SET(0x0000 + sp0 - 4, a_all6);
                uint8_t value14 = RAM8(0x0000 + sp0 - 4);
                uint8_t value15 = RAM8(0x0000 + sp0 - 3);
                uint8_t value16 = RAM8(0x0000 + sp0 - 2);
                uint8_t value17 = RAM8(0x0000 + sp0 - 1);
                uint8_t value18 = RAM8(0x0000 + sp0);
                r->a = (value15 << 8) | value14;
                r->v = value16 & 0x40;
                r->mf = value16 & 0x20;
                r->xf = value16 & 0x10;
                r->dp = (value18 << 8) | value17;
                r->i = value16 & 0x04;
                r->d = value16 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                r->sp += 1;
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (db_ret4 << 0x10) + 0x0312, 0);
            BUS16_SET(c, (db_ret4 << 0x10) + 0x0311, 0);
            r->mf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD438, 0x7ED3AA); GUARD_JSR(c, sp_call, 0xD438); } /* teardown_title_window_and_tracked_tasks */
            r->sp += 4;
            r->x = 0xB4;
            r->z = 0;
            r->n = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD43E, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD43E); } /* dispatch_parent_messages */
            r->sp += 4;
            bool m_ret6 = r->mf;
            uint16_t a_all8 = r->a;
            if (m_ret6) {
                RAM8(0x0000 + sp0 - 4) = (uint8_t)a_all8;
                uint8_t value19 = RAM8(0x0000 + sp0 - 4);
                uint8_t value20 = RAM8(0x0000 + sp0 - 3);
                uint8_t value21 = RAM8(0x0000 + sp0 - 2);
                uint8_t value22 = RAM8(0x0000 + sp0 - 1);
                r->a = (a_all8 >> 8 << 8) | value19;
                r->v = value20 & 0x40;
                r->mf = value20 & 0x20;
                r->xf = value20 & 0x10;
                r->dp = (value22 << 8) | value21;
                r->i = value20 & 0x04;
                r->d = value20 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                RAM16_SET(0x0000 + sp0 - 4, a_all8);
                uint8_t value23 = RAM8(0x0000 + sp0 - 4);
                uint8_t value24 = RAM8(0x0000 + sp0 - 3);
                uint8_t value25 = RAM8(0x0000 + sp0 - 2);
                uint8_t value26 = RAM8(0x0000 + sp0 - 1);
                uint8_t value27 = RAM8(0x0000 + sp0);
                r->a = (value24 << 8) | value23;
                r->v = value25 & 0x40;
                r->mf = value25 & 0x20;
                r->xf = value25 & 0x10;
                r->dp = (value27 << 8) | value26;
                r->i = value25 & 0x04;
                r->d = value25 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                r->sp += 1;
                RETURN_RTS(c);
            }
        }
    } else {
        uint16_t value28 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0311);
        r->a = value28;
        r->z = value28 == 0;
        r->n = value28 & 0x8000;
        r->mf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD42F, 0x7EB258); GUARD_JSR(c, sp_call, 0xD42F); } /* append_pending_record */
        r->sp += 4;
        uint8_t db_ret9 = r->db;
        bool m_ret7 = r->mf;
        if (m_ret7) {
            BUS8_SET(c, (db_ret9 << 0x10) + 0x0312, 0);
            BUS8_SET(c, (db_ret9 << 0x10) + 0x0311, 0);
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD438, 0x7ED3AA); GUARD_JSR(c, sp_call, 0xD438); } /* teardown_title_window_and_tracked_tasks */
            r->sp += 4;
            r->x = 0xB4;
            r->z = 0;
            r->n = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD43E, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD43E); } /* dispatch_parent_messages */
            r->sp += 4;
            bool m_ret9 = r->mf;
            uint16_t a_all11 = r->a;
            if (m_ret9) {
                RAM8(0x0000 + sp0 - 4) = (uint8_t)a_all11;
                uint8_t value29 = RAM8(0x0000 + sp0 - 4);
                uint8_t value30 = RAM8(0x0000 + sp0 - 3);
                uint8_t value31 = RAM8(0x0000 + sp0 - 2);
                uint8_t value32 = RAM8(0x0000 + sp0 - 1);
                r->a = (a_all11 >> 8 << 8) | value29;
                r->v = value30 & 0x40;
                r->mf = value30 & 0x20;
                r->xf = value30 & 0x10;
                r->dp = (value32 << 8) | value31;
                r->i = value30 & 0x04;
                r->d = value30 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                RAM16_SET(0x0000 + sp0 - 4, a_all11);
                uint8_t value33 = RAM8(0x0000 + sp0 - 4);
                uint8_t value34 = RAM8(0x0000 + sp0 - 3);
                uint8_t value35 = RAM8(0x0000 + sp0 - 2);
                uint8_t value36 = RAM8(0x0000 + sp0 - 1);
                uint8_t value37 = RAM8(0x0000 + sp0);
                r->a = (value34 << 8) | value33;
                r->v = value35 & 0x40;
                r->mf = value35 & 0x20;
                r->xf = value35 & 0x10;
                r->dp = (value37 << 8) | value36;
                r->i = value35 & 0x04;
                r->d = value35 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                r->sp += 1;
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (db_ret9 << 0x10) + 0x0312, 0);
            BUS16_SET(c, (db_ret9 << 0x10) + 0x0311, 0);
            r->mf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD438, 0x7ED3AA); GUARD_JSR(c, sp_call, 0xD438); } /* teardown_title_window_and_tracked_tasks */
            r->sp += 4;
            r->x = 0xB4;
            r->z = 0;
            r->n = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD43E, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD43E); } /* dispatch_parent_messages */
            r->sp += 4;
            bool m_ret11 = r->mf;
            uint16_t a_all13 = r->a;
            if (m_ret11) {
                RAM8(0x0000 + sp0 - 4) = (uint8_t)a_all13;
                uint8_t value38 = RAM8(0x0000 + sp0 - 4);
                uint8_t value39 = RAM8(0x0000 + sp0 - 3);
                uint8_t value40 = RAM8(0x0000 + sp0 - 2);
                uint8_t value41 = RAM8(0x0000 + sp0 - 1);
                r->a = (a_all13 >> 8 << 8) | value38;
                r->v = value39 & 0x40;
                r->mf = value39 & 0x20;
                r->xf = value39 & 0x10;
                r->dp = (value41 << 8) | value40;
                r->i = value39 & 0x04;
                r->d = value39 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                RAM16_SET(0x0000 + sp0 - 4, a_all13);
                uint8_t value42 = RAM8(0x0000 + sp0 - 4);
                uint8_t value43 = RAM8(0x0000 + sp0 - 3);
                uint8_t value44 = RAM8(0x0000 + sp0 - 2);
                uint8_t value45 = RAM8(0x0000 + sp0 - 1);
                uint8_t value46 = RAM8(0x0000 + sp0);
                r->a = (value43 << 8) | value42;
                r->v = value44 & 0x40;
                r->mf = value44 & 0x20;
                r->xf = value44 & 0x10;
                r->dp = (value46 << 8) | value45;
                r->i = value44 & 0x04;
                r->d = value44 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                r->sp += 1;
                RETURN_RTS(c);
            }
        }
    }
}
SOM_REGISTER(0x7ED40D, SOM_RTS, "gen", fade_notify_image_and_teardown_before_title_repeat, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_V, 5, 1, 0, 56, 27)
