#include "som_c.h"
#include "som_hand.h"

/* 7EA911 suspend_current_task   [class C, 182 bytes, 86 instructions]
 * Source: src/boot/suspend_current_task.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void suspend_current_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a_hi_a948 = 0;
    uint16_t y_a948 = 0;
    bool carry_a948 = 0;
    bool overflow_a948 = 0;
    uint16_t direct_page_a948 = 0;
    uint8_t a_hi_a9482 = 0;
    uint8_t y_a9482 = 0;
    bool carry_a9482 = 0;
    bool overflow_a9482 = 0;
    uint16_t direct_page_a9482 = 0;
    uint8_t a_hi_a9483 = 0;
    uint16_t y_a9483 = 0;
    bool carry_a9483 = 0;
    bool overflow_a9483 = 0;
    uint16_t direct_page_a9483 = 0;
    uint8_t a_hi_a9484 = 0;
    uint8_t y_a9484 = 0;
    bool carry_a9484 = 0;
    bool overflow_a9484 = 0;
    uint16_t direct_page_a9484 = 0;
    uint8_t a_hi_a961 = 0;
    uint16_t x_a961 = 0;
    uint16_t y_a961 = 0;
    bool overflow_a961 = 0;
    uint16_t direct_page_a961 = 0;
    uint8_t data_bank_a961 = 0;
    uint8_t a_hi_a9612 = 0;
    uint8_t x_a9612 = 0;
    uint8_t y_a9612 = 0;
    bool overflow_a9612 = 0;
    uint16_t direct_page_a9612 = 0;
    uint8_t data_bank_a9612 = 0;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = db;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = ((overflow << 6) | (d_entry << 3)) | (i_entry << 2) | carry;
    uint16_t value = RAM16(0x1009E);
    BUS16_SET(c, 0x7F0006 + value, (uint16_t)(sp0 - 5));
    uint16_t value2 = BUS16(c, 0x7F000A + value);
    if (value2 == 0) {
        BUS8_SET(c, 0x7F0002 + value, 4);
        uint16_t value3 = RAM16(0x100A2);
        BUS16_SET(c, 0x7F0000 + value, value3);
        RAM16_SET(0x100A2, value);
        a_hi_a948 = value3 >> 8;
        y_a948 = value2;
        carry_a948 = carry;
        overflow_a948 = overflow;
        direct_page_a948 = dp;
        goto shared_A948;
    }
    BUS8_SET(c, 0x7F0002 + value, 2);
    r->a = ((uint16_t)(sp0 - 5) >> 8 << 8) | 2;
    r->x = value;
    r->y = value2;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->db = 0x7F;
    r->i = 1;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA935, 0x7EA8D6); GUARD_JSR(c, sp_call, 0xA935); } /* enqueue_task_by_priority */
    r->sp += 5;
    uint16_t dp_ret = r->dp;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    if (m_ret) {
        if (x_ret) {
            a_hi_a9482 = a_all >> 8;
            y_a9482 = (uint8_t)y_ret;
            carry_a9482 = carry_ret;
            overflow_a9482 = overflow_ret;
            direct_page_a9482 = dp_ret;
            goto shared_A948_1;
        } else {
            a_hi_a9483 = a_all >> 8;
            y_a9483 = y_ret;
            carry_a9483 = carry_ret;
            overflow_a9483 = overflow_ret;
            direct_page_a9483 = dp_ret;
            goto shared_A948_2;
        }
    } else {
        if (x_ret) {
            a_hi_a9484 = a_all >> 8;
            y_a9484 = (uint8_t)y_ret;
            carry_a9484 = carry_ret;
            overflow_a9484 = overflow_ret;
            direct_page_a9484 = dp_ret;
            goto shared_A948_3;
        } else {
            a_hi_a948 = a_all >> 8;
            y_a948 = y_ret;
            carry_a948 = carry_ret;
            overflow_a948 = overflow_ret;
            direct_page_a948 = dp_ret;
            goto shared_A948;
        }
    }
    shared_A948:;
    uint16_t value4 = RAM16(0x100A0);
    if (value4 != 0) {
        a_hi_a961 = a_hi_a948;
        x_a961 = value4;
        y_a961 = y_a948;
        overflow_a961 = overflow_a948;
        direct_page_a961 = direct_page_a948;
        data_bank_a961 = 0x7F;
        goto shared_A961;
    }
    r->a = (a_hi_a948 << 8) | 0x7E;
    r->x = 0x600A;
    r->y = y_a948;
    r->c = carry_a948;
    r->z = 0;
    r->n = 0;
    r->v = overflow_a948;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7F;
    r->dp = direct_page_a948;
    r->i = 1;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA958, 0x7EAAFF); GUARD_JSR(c, sp_call, 0xA958); } /* create_task_resources */
    r->sp += 5;
    uint8_t db_ret = r->db;
    bool m_ret2 = r->mf;
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret2 = r->y;
    bool overflow_ret2 = r->v;
    if (m_ret2) {
        uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 4 + x_ret4);
        BUS8_SET(c, (db_ret << 0x10) + 0xBE, value5);
        if (x_ret3) {
            a_hi_a9612 = a_all2 >> 8;
            x_a9612 = (uint8_t)x_ret4;
            y_a9612 = (uint8_t)y_ret2;
            overflow_a9612 = overflow_ret2;
            direct_page_a9612 = direct_page_a948;
            data_bank_a9612 = db_ret;
            goto shared_A961_1;
        } else {
            a_hi_a961 = a_all2 >> 8;
            x_a961 = x_ret4;
            y_a961 = y_ret2;
            overflow_a961 = overflow_ret2;
            direct_page_a961 = direct_page_a948;
            data_bank_a961 = db_ret;
            goto shared_A961;
        }
    } else {
        uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 4 + x_ret4);
        BUS16_SET(c, (db_ret << 0x10) + 0xBE, value6);
        if (x_ret3) {
            a_hi_a9612 = value6 >> 8;
            x_a9612 = (uint8_t)x_ret4;
            y_a9612 = (uint8_t)y_ret2;
            overflow_a9612 = overflow_ret2;
            direct_page_a9612 = direct_page_a948;
            data_bank_a9612 = db_ret;
            goto shared_A961_1;
        } else {
            a_hi_a961 = value6 >> 8;
            x_a961 = x_ret4;
            y_a961 = y_ret2;
            overflow_a961 = overflow_ret2;
            direct_page_a961 = direct_page_a948;
            data_bank_a961 = db_ret;
            goto shared_A961;
        }
    }
    shared_A948_1:;
    uint8_t value7 = RAM8(0x100A0);
    if (value7 != 0) {
        a_hi_a9612 = a_hi_a9482;
        x_a9612 = value7;
        y_a9612 = y_a9482;
        overflow_a9612 = overflow_a9482;
        direct_page_a9612 = direct_page_a9482;
        data_bank_a9612 = 0x7F;
        goto shared_A961_1;
    }
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_A948_2:;
    uint16_t value8 = RAM16(0x100A0);
    if (value8 != 0) {
        a_hi_a961 = a_hi_a9483;
        x_a961 = value8;
        y_a961 = y_a9483;
        overflow_a961 = overflow_a9483;
        direct_page_a961 = direct_page_a9483;
        data_bank_a961 = 0x7F;
        goto shared_A961;
    }
    r->a = (a_hi_a9483 << 8) | 0x7E;
    r->x = 0x600A;
    r->y = y_a9483;
    r->c = carry_a9483;
    r->z = 0;
    r->n = 0;
    r->v = overflow_a9483;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7F;
    r->dp = direct_page_a9483;
    r->i = 1;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA958, 0x7EAAFF); GUARD_JSR(c, sp_call, 0xA958); } /* create_task_resources */
    r->sp += 5;
    uint8_t db_ret2 = r->db;
    bool m_ret3 = r->mf;
    bool x_ret5 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t x_ret6 = r->x;
    uint16_t y_ret3 = r->y;
    bool overflow_ret3 = r->v;
    if (m_ret3) {
        uint8_t value9 = BUS8_RDP(c, (db_ret2 << 0x10) + 4 + x_ret6);
        BUS8_SET(c, (db_ret2 << 0x10) + 0xBE, value9);
        if (x_ret5) {
            a_hi_a9612 = a_all3 >> 8;
            x_a9612 = (uint8_t)x_ret6;
            y_a9612 = (uint8_t)y_ret3;
            overflow_a9612 = overflow_ret3;
            direct_page_a9612 = direct_page_a9483;
            data_bank_a9612 = db_ret2;
            goto shared_A961_1;
        } else {
            a_hi_a961 = a_all3 >> 8;
            x_a961 = x_ret6;
            y_a961 = y_ret3;
            overflow_a961 = overflow_ret3;
            direct_page_a961 = direct_page_a9483;
            data_bank_a961 = db_ret2;
            goto shared_A961;
        }
    } else {
        uint16_t value10 = BUS16_RDP(c, (db_ret2 << 0x10) + 4 + x_ret6);
        BUS16_SET(c, (db_ret2 << 0x10) + 0xBE, value10);
        if (x_ret5) {
            a_hi_a9612 = value10 >> 8;
            x_a9612 = (uint8_t)x_ret6;
            y_a9612 = (uint8_t)y_ret3;
            overflow_a9612 = overflow_ret3;
            direct_page_a9612 = direct_page_a9483;
            data_bank_a9612 = db_ret2;
            goto shared_A961_1;
        } else {
            a_hi_a961 = value10 >> 8;
            x_a961 = x_ret6;
            y_a961 = y_ret3;
            overflow_a961 = overflow_ret3;
            direct_page_a961 = direct_page_a9483;
            data_bank_a961 = db_ret2;
            goto shared_A961;
        }
    }
    shared_A948_3:;
    uint8_t value11 = RAM8(0x100A0);
    if (value11 != 0) {
        a_hi_a9612 = a_hi_a9484;
        x_a9612 = value11;
        y_a9612 = y_a9484;
        overflow_a9612 = overflow_a9484;
        direct_page_a9612 = direct_page_a9484;
        data_bank_a9612 = 0x7F;
        goto shared_A961_1;
    }
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_A961:;
    uint16_t value12 = BUS16_RDP(c, (data_bank_a961 << 0x10) + x_a961);
    BUS16_SET(c, (data_bank_a961 << 0x10) + 0xA0, value12);
    BUS16_SET(c, (data_bank_a961 << 0x10) + x_a961, 0);
    BUS16_SET(c, (data_bank_a961 << 0x10) + 0x9E, x_a961);
    uint16_t value13 = BUS16_RDP(c, (data_bank_a961 << 0x10) + 6 + x_a961);
    r->sp = value13;
    som_task_note(c);
    sp0 = r->sp + 5;
    if ((uint32_t)value13 + 6 > 0x2000) { c->fail = 3; return; } /* the resumed task's stack is outside the WRAM mirror of bank 0: not modelled */
    uint8_t value14 = BUS8_RDP(c, (data_bank_a961 << 0x10) + 2 + x_a961);
    if (value14 == 8) {
        BUS8_SET(c, (data_bank_a961 << 0x10) + 2 + x_a961, 1);
        uint8_t value15 = BUS8_RDP(c, (data_bank_a961 << 0x10) + 0x8E);
        BUS8_SET(c, (data_bank_a961 << 0x10) + 0x8E, (uint8_t)(value15 + 1));
        uint8_t value16 = BUS8_RDP(c, (data_bank_a961 << 0x10) + 0x8E);
        BUS8_SET(c, (data_bank_a961 << 0x10) + 0x8E, (uint8_t)(value16 - 1));
        r->a = (value13 >> 8 << 8) | 1;
        r->x = x_a961;
        r->y = y_a961;
        r->c = value14 >= 8;
        r->z = (uint8_t)(value16 - 1) == 0;
        r->n = (uint8_t)(value16 - 1) & 0x80;
        r->v = overflow_a961;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_a961;
        r->dp = direct_page_a961;
        r->i = 0;
        RETURN_RTL(c);
    }
    if (value14 == 0x10) {
        const uint16_t sp_old = sp0;
        if (((uint16_t)(sp_old - 5) & 0xFF00) > 0x1F00) { c->fail = 3; return; } /* the direct page D = (S-5) & $FF00 would address ROM/registers, not WRAM */
        r->sp = (uint16_t)(((uint16_t)(sp_old - 5) & 0xFF00) + 0xF6);
        som_task_note(c);
        sp0 = r->sp + 5;
        uint16_t value17 = RAM16(0x00FD + ((uint16_t)(sp_old - 5) & 0xFF00));
        RAM16_SET(0x00F7 + ((uint16_t)(sp_old - 5) & 0xFF00), value17);
        RAM8(0x00F9 + ((uint16_t)(sp_old - 5) & 0xFF00)) = RAM8(0x00FF + ((uint16_t)(sp_old - 5) & 0xFF00));
        BUS8_SET(c, (data_bank_a961 << 0x10) + 2 + x_a961, 1);
        uint8_t value19 = BUS8_RDP(c, (data_bank_a961 << 0x10) + 0x8E);
        BUS8_SET(c, (data_bank_a961 << 0x10) + 0x8E, (uint8_t)(value19 + 1));
        uint8_t value20 = BUS8_RDP(c, (data_bank_a961 << 0x10) + 0x8E);
        BUS8_SET(c, (data_bank_a961 << 0x10) + 0x8E, (uint8_t)(value20 - 1));
        r->a = (value17 >> 8 << 8) | 1;
        r->x = x_a961;
        r->y = y_a961;
        r->c = ((uint16_t)(sp_old - 5) & 0xFF00) + 0xF6 > 0xFFFF;
        r->z = (uint8_t)(value20 - 1) == 0;
        r->n = (uint8_t)(value20 - 1) & 0x80;
        r->v = ((((uint16_t)(sp_old - 5) & 0xFF00) ^ (uint16_t)(((uint16_t)(sp_old - 5) & 0xFF00) + 0xF6)) & ((uint16_t)(((uint16_t)(sp_old - 5) & 0xFF00) + 0xF6) ^ 0xF6) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_a961;
        r->dp = (uint16_t)(sp_old - 5) & 0xFF00;
        r->i = 0;
        RETURN_RTL(c);
    }
    BUS8_SET(c, (data_bank_a961 << 0x10) + 2 + x_a961, 1);
    uint16_t value21 = BUS16_RDP(c, (data_bank_a961 << 0x10) + 0x0A + x_a961);
    r->a = (value13 >> 8 << 8) | 1;
    r->x = value21;
    r->y = value21;
    r->c = value14 >= 0x10;
    r->z = value21 == 0;
    r->n = value21 & 0x8000;
    r->v = overflow_a961;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_a961;
    r->dp = direct_page_a961;
    r->i = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA98B, 0x7EB20B); GUARD_JSR(c, sp_call, 0xA98B); } /* take_record_link */
    uint8_t db_ret3 = r->db;
    bool m_ret4 = r->mf;
    bool x_ret7 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t x_ret8 = r->x;
    if (x_ret7) {
        uint8_t value22 = BUS8_RDP(c, (db_ret3 << 0x10) + 0x9E);
        if (m_ret4) {
            BUS8_SET(c, (db_ret3 << 0x10) + 0x0A + value22, (uint8_t)a_all4);
            uint8_t value24 = RAM8(0x0000 + sp0 - 3);
            uint8_t value25 = RAM8(0x0000 + sp0 - 2);
            uint8_t value26 = RAM8(0x0000 + sp0 - 1);
            uint8_t value27 = RAM8(0x0000 + sp0);
            r->x = (uint8_t)x_ret8;
            r->y = value22;
            r->c = value25 & 0x01;
            r->z = ((value27 << 8) | value26) == 0;
            r->n = ((value27 << 8) | value26) & 0x8000;
            r->v = value25 & 0x40;
            r->mf = value25 & 0x20;
            r->xf = value25 & 0x10;
            r->db = value24;
            r->dp = (value27 << 8) | value26;
            r->i = value25 & 0x04;
            r->d = value25 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp += 5;
            RETURN_RTS(c);
        } else {
            BUS16_SET(c, (db_ret3 << 0x10) + 0x0A + value22, a_all4);
            uint8_t value29 = RAM8(0x0000 + sp0 - 3);
            uint8_t value30 = RAM8(0x0000 + sp0 - 2);
            uint8_t value31 = RAM8(0x0000 + sp0 - 1);
            uint8_t value32 = RAM8(0x0000 + sp0);
            r->x = (uint8_t)x_ret8;
            r->y = value22;
            r->c = value30 & 0x01;
            r->z = ((value32 << 8) | value31) == 0;
            r->n = ((value32 << 8) | value31) & 0x8000;
            r->v = value30 & 0x40;
            r->mf = value30 & 0x20;
            r->xf = value30 & 0x10;
            r->db = value29;
            r->dp = (value32 << 8) | value31;
            r->i = value30 & 0x04;
            r->d = value30 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp += 5;
            RETURN_RTS(c);
        }
    } else {
        uint16_t value33 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x9E);
        /* the first of the two PLPs of the epilogue pulls the P of the second PHP; with its X flag set it clears the index high bytes before the last PLP restores the final flags */
        const uint16_t xy_t = (RAM8(0x0000 + sp0 - 4) & 0x10) ? 0x00FF : 0xFFFF;
        r->x &= xy_t;
        if (m_ret4) {
            BUS8_SET(c, (db_ret3 << 0x10) + 0x0A + value33, (uint8_t)a_all4);
            uint8_t value35 = RAM8(0x0000 + sp0 - 3);
            uint8_t value36 = RAM8(0x0000 + sp0 - 2);
            uint8_t value37 = RAM8(0x0000 + sp0 - 1);
            uint8_t value38 = RAM8(0x0000 + sp0);
            r->y = value33 & xy_t;
            r->c = value36 & 0x01;
            r->z = ((value38 << 8) | value37) == 0;
            r->n = ((value38 << 8) | value37) & 0x8000;
            r->v = value36 & 0x40;
            r->mf = value36 & 0x20;
            r->xf = value36 & 0x10;
            r->db = value35;
            r->dp = (value38 << 8) | value37;
            r->i = value36 & 0x04;
            r->d = value36 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp += 5;
            RETURN_RTS(c);
        } else {
            BUS16_SET(c, (db_ret3 << 0x10) + 0x0A + value33, a_all4);
            uint8_t value40 = RAM8(0x0000 + sp0 - 3);
            uint8_t value41 = RAM8(0x0000 + sp0 - 2);
            uint8_t value42 = RAM8(0x0000 + sp0 - 1);
            uint8_t value43 = RAM8(0x0000 + sp0);
            r->y = value33 & xy_t;
            r->c = value41 & 0x01;
            r->z = ((value43 << 8) | value42) == 0;
            r->n = ((value43 << 8) | value42) & 0x8000;
            r->v = value41 & 0x40;
            r->mf = value41 & 0x20;
            r->xf = value41 & 0x10;
            r->db = value40;
            r->dp = (value43 << 8) | value42;
            r->i = value41 & 0x04;
            r->d = value41 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp += 5;
            RETURN_RTS(c);
        }
    }
    shared_A961_1:;
    uint16_t value44 = BUS16_RDP(c, (data_bank_a9612 << 0x10) + x_a9612);
    BUS16_SET(c, (data_bank_a9612 << 0x10) + 0xA0, value44);
    BUS16_SET(c, (data_bank_a9612 << 0x10) + x_a9612, 0);
    BUS8_SET(c, (data_bank_a9612 << 0x10) + 0x9E, x_a9612);
    uint16_t value45 = BUS16_RDP(c, (data_bank_a9612 << 0x10) + 6 + x_a9612);
    r->sp = value45;
    som_task_note(c);
    sp0 = r->sp + 5;
    if ((uint32_t)value45 + 6 > 0x2000) { c->fail = 3; return; } /* the resumed task's stack is outside the WRAM mirror of bank 0: not modelled */
    uint8_t value46 = BUS8_RDP(c, (data_bank_a9612 << 0x10) + 2 + x_a9612);
    if (value46 == 8) {
        BUS8_SET(c, (data_bank_a9612 << 0x10) + 2 + x_a9612, 1);
        uint8_t value47 = BUS8_RDP(c, (data_bank_a9612 << 0x10) + 0x8E);
        BUS8_SET(c, (data_bank_a9612 << 0x10) + 0x8E, (uint8_t)(value47 + 1));
        uint8_t value48 = BUS8_RDP(c, (data_bank_a9612 << 0x10) + 0x8E);
        BUS8_SET(c, (data_bank_a9612 << 0x10) + 0x8E, (uint8_t)(value48 - 1));
        r->a = (value45 >> 8 << 8) | 1;
        r->x = x_a9612;
        r->y = y_a9612;
        r->c = value46 >= 8;
        r->z = (uint8_t)(value48 - 1) == 0;
        r->n = (uint8_t)(value48 - 1) & 0x80;
        r->v = overflow_a9612;
        r->mf = 1;
        r->xf = 1;
        r->db = data_bank_a9612;
        r->dp = direct_page_a9612;
        r->i = 0;
        RETURN_RTL(c);
    }
    if (value46 == 0x10) {
        const uint16_t sp_old2 = sp0;
        if (((uint16_t)(sp_old2 - 5) & 0xFF00) > 0x1F00) { c->fail = 3; return; } /* the direct page D = (S-5) & $FF00 would address ROM/registers, not WRAM */
        r->sp = (uint16_t)(((uint16_t)(sp_old2 - 5) & 0xFF00) + 0xF6);
        som_task_note(c);
        sp0 = r->sp + 5;
        uint16_t value49 = RAM16(0x00FD + ((uint16_t)(sp_old2 - 5) & 0xFF00));
        RAM16_SET(0x00F7 + ((uint16_t)(sp_old2 - 5) & 0xFF00), value49);
        RAM8(0x00F9 + ((uint16_t)(sp_old2 - 5) & 0xFF00)) = RAM8(0x00FF + ((uint16_t)(sp_old2 - 5) & 0xFF00));
        BUS8_SET(c, (data_bank_a9612 << 0x10) + 2 + x_a9612, 1);
        uint8_t value51 = BUS8_RDP(c, (data_bank_a9612 << 0x10) + 0x8E);
        BUS8_SET(c, (data_bank_a9612 << 0x10) + 0x8E, (uint8_t)(value51 + 1));
        uint8_t value52 = BUS8_RDP(c, (data_bank_a9612 << 0x10) + 0x8E);
        BUS8_SET(c, (data_bank_a9612 << 0x10) + 0x8E, (uint8_t)(value52 - 1));
        r->a = (value49 >> 8 << 8) | 1;
        r->x = x_a9612;
        r->y = y_a9612;
        r->c = ((uint16_t)(sp_old2 - 5) & 0xFF00) + 0xF6 > 0xFFFF;
        r->z = (uint8_t)(value52 - 1) == 0;
        r->n = (uint8_t)(value52 - 1) & 0x80;
        r->v = ((((uint16_t)(sp_old2 - 5) & 0xFF00) ^ (uint16_t)(((uint16_t)(sp_old2 - 5) & 0xFF00) + 0xF6)) & ((uint16_t)(((uint16_t)(sp_old2 - 5) & 0xFF00) + 0xF6) ^ 0xF6) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 1;
        r->db = data_bank_a9612;
        r->dp = (uint16_t)(sp_old2 - 5) & 0xFF00;
        r->i = 0;
        RETURN_RTL(c);
    }
    BUS8_SET(c, (data_bank_a9612 << 0x10) + 2 + x_a9612, 1);
    uint8_t value53 = BUS8_RDP(c, (data_bank_a9612 << 0x10) + 0x0A + x_a9612);
    r->a = (value45 >> 8 << 8) | 1;
    r->x = value53;
    r->y = value53;
    r->c = value46 >= 0x10;
    r->z = value53 == 0;
    r->n = value53 & 0x80;
    r->v = overflow_a9612;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_a9612;
    r->dp = direct_page_a9612;
    r->i = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA98B, 0x7EB20B); GUARD_JSR(c, sp_call, 0xA98B); } /* take_record_link */
    uint8_t db_ret4 = r->db;
    bool m_ret5 = r->mf;
    bool x_ret9 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t x_ret10 = r->x;
    if (x_ret9) {
        uint8_t value54 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x9E);
        if (m_ret5) {
            BUS8_SET(c, (db_ret4 << 0x10) + 0x0A + value54, (uint8_t)a_all5);
            uint8_t value56 = RAM8(0x0000 + sp0 - 3);
            uint8_t value57 = RAM8(0x0000 + sp0 - 2);
            uint8_t value58 = RAM8(0x0000 + sp0 - 1);
            uint8_t value59 = RAM8(0x0000 + sp0);
            r->x = (uint8_t)x_ret10;
            r->y = value54;
            r->c = value57 & 0x01;
            r->z = ((value59 << 8) | value58) == 0;
            r->n = ((value59 << 8) | value58) & 0x8000;
            r->v = value57 & 0x40;
            r->mf = value57 & 0x20;
            r->xf = value57 & 0x10;
            r->db = value56;
            r->dp = (value59 << 8) | value58;
            r->i = value57 & 0x04;
            r->d = value57 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp += 5;
            RETURN_RTS(c);
        } else {
            BUS16_SET(c, (db_ret4 << 0x10) + 0x0A + value54, a_all5);
            uint8_t value61 = RAM8(0x0000 + sp0 - 3);
            uint8_t value62 = RAM8(0x0000 + sp0 - 2);
            uint8_t value63 = RAM8(0x0000 + sp0 - 1);
            uint8_t value64 = RAM8(0x0000 + sp0);
            r->x = (uint8_t)x_ret10;
            r->y = value54;
            r->c = value62 & 0x01;
            r->z = ((value64 << 8) | value63) == 0;
            r->n = ((value64 << 8) | value63) & 0x8000;
            r->v = value62 & 0x40;
            r->mf = value62 & 0x20;
            r->xf = value62 & 0x10;
            r->db = value61;
            r->dp = (value64 << 8) | value63;
            r->i = value62 & 0x04;
            r->d = value62 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp += 5;
            RETURN_RTS(c);
        }
    } else {
        uint16_t value65 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x9E);
        /* the first of the two PLPs of the epilogue pulls the P of the second PHP; with its X flag set it clears the index high bytes before the last PLP restores the final flags */
        const uint16_t xy_t = (RAM8(0x0000 + sp0 - 4) & 0x10) ? 0x00FF : 0xFFFF;
        r->x &= xy_t;
        if (m_ret5) {
            BUS8_SET(c, (db_ret4 << 0x10) + 0x0A + value65, (uint8_t)a_all5);
            uint8_t value67 = RAM8(0x0000 + sp0 - 3);
            uint8_t value68 = RAM8(0x0000 + sp0 - 2);
            uint8_t value69 = RAM8(0x0000 + sp0 - 1);
            uint8_t value70 = RAM8(0x0000 + sp0);
            r->y = value65 & xy_t;
            r->c = value68 & 0x01;
            r->z = ((value70 << 8) | value69) == 0;
            r->n = ((value70 << 8) | value69) & 0x8000;
            r->v = value68 & 0x40;
            r->mf = value68 & 0x20;
            r->xf = value68 & 0x10;
            r->db = value67;
            r->dp = (value70 << 8) | value69;
            r->i = value68 & 0x04;
            r->d = value68 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp += 5;
            RETURN_RTS(c);
        } else {
            BUS16_SET(c, (db_ret4 << 0x10) + 0x0A + value65, a_all5);
            uint8_t value72 = RAM8(0x0000 + sp0 - 3);
            uint8_t value73 = RAM8(0x0000 + sp0 - 2);
            uint8_t value74 = RAM8(0x0000 + sp0 - 1);
            uint8_t value75 = RAM8(0x0000 + sp0);
            r->y = value65 & xy_t;
            r->c = value73 & 0x01;
            r->z = ((value75 << 8) | value74) == 0;
            r->n = ((value75 << 8) | value74) & 0x8000;
            r->v = value73 & 0x40;
            r->mf = value73 & 0x20;
            r->xf = value73 & 0x10;
            r->db = value72;
            r->dp = (value75 << 8) | value74;
            r->i = value73 & 0x04;
            r->d = value73 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp += 5;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0x7EA911, SOM_RTS, "hand", suspend_current_task, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 0, 0, 182, 86)
