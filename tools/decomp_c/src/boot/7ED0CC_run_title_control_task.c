#include "som_c.h"

/* 7ED0CC run_title_control_task   [class B, 128 bytes, 55 instructions]
 * Source: src/boot/run_title_control_task.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: ABXYCZNV.
 */
static void run_title_control_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = RAM8(0x10317);
    if (value != 0) {
        uint8_t a1 = value;
        uint8_t a_hi1 = a_hi;
        uint16_t x1 = x;
        uint16_t y1 = y;
        bool carry1 = carry;
        bool zero1 = value == 0;
        bool negative1 = value & 0x80;
        bool overflow1 = overflow;
        uint8_t data_bank = 0x7F;
        uint16_t direct_page = dp;
        for (;;) {
            r->a = (a_hi1 << 8) | 0;
            r->y = y1;
            r->c = carry1;
            r->z = 1;
            r->n = 0;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD125, 0x7EC030); GUARD_JSR(c, sp_call, 0xD125); } /* allocate_ppu_register_entry */
            r->sp += 3;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t a_all = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret = r->y;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 2 + x_ret2);
            bool zero2;
            bool negative2;
            if (value2 == 0) {
                zero2 = value2 == 0;
                negative2 = value2 & 0x80;
            } else {
                uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 2 + x_ret2);
                BUS8_SET(c, (db_ret << 0x10) + 2 + x_ret2, (uint8_t)(value3 - 1));
                if ((uint8_t)(value3 - 1) != 0) {
                    r->z = (uint8_t)(value3 - 1) == 0;
                    r->n = (uint8_t)(value3 - 1) & 0x80;
                    r->sp -= 3;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD132, 0x7EC097); GUARD_JSR(c, sp_call, 0xD132); } /* append_oneshot_ppu_entry */
                    r->sp += 3;
                    r->x = 4;
                    r->z = 0;
                    r->n = 0;
                    r->sp -= 3;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xD138, 0x7EABE7); GUARD_JSR(c, sp_call, 0xD138); } /* receive_with_supplied_delay */
                    r->sp += 3;
                    uint16_t dp_ret3 = r->dp;
                    uint8_t db_ret3 = r->db;
                    if (r->mf != 1) { c->fail = 3; return; }
                    bool x_ret3 = r->xf;
                    uint16_t a_all3 = r->a;
                    uint16_t x_ret4 = r->x;
                    uint16_t y_ret3 = r->y;
                    bool carry_ret3 = r->c;
                    bool zero_ret3 = r->z;
                    bool negative_ret3 = r->n;
                    bool overflow_ret3 = r->v;
                    if (x_ret3 != 0) { c->fail = 3; return; }
                    a1 = (uint8_t)a_all3;
                    a_hi1 = a_all3 >> 8;
                    x1 = x_ret4;
                    y1 = y_ret3;
                    carry1 = carry_ret3;
                    zero1 = zero_ret3;
                    negative1 = negative_ret3;
                    overflow1 = overflow_ret3;
                    data_bank = db_ret3;
                    direct_page = dp_ret3;
                    continue;
                }
                zero2 = (uint8_t)(value3 - 1) == 0;
                negative2 = (uint8_t)(value3 - 1) & 0x80;
            }
            a1 = value2;
            a_hi1 = a_all >> 8;
            x1 = x_ret2;
            y1 = y_ret;
            carry1 = carry_ret;
            zero1 = zero2;
            negative1 = negative2;
            overflow1 = overflow_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
            break;
        }
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 1;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD13D, 0x7EC097); GUARD_JSR(c, sp_call, 0xD13D); } /* append_oneshot_ppu_entry */
        r->sp += 3;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD140, 0x7EACD0); GUARD_JSR(c, sp_call, 0xD140); } /* current_task_parent_id */
        r->sp += 3;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all5 = r->a;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)a_all5;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD144, 0x7EB1A9); GUARD_JSR(c, sp_call, 0xD144); } /* allocate_eight_byte_record */
        r->sp += 4;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all6 = r->a;
        uint8_t value4 = RAM8(0x0000 + sp0 - 3);
        r->a = (a_all6 >> 8 << 8) | value4;
        r->z = value4 == 0;
        r->n = value4 & 0x80;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD148, 0x7EB258); GUARD_JSR(c, sp_call, 0xD148); } /* append_pending_record */
        r->sp += 3;
        uint8_t value5 = RAM8(0x0000 + sp0 - 2);
        uint8_t value6 = RAM8(0x0000 + sp0 - 1);
        uint8_t value7 = RAM8(0x0000 + sp0);
        r->c = value5 & 0x01;
        r->z = ((value7 << 8) | value6) == 0;
        r->n = ((value7 << 8) | value6) & 0x8000;
        r->v = value5 & 0x40;
        r->mf = value5 & 0x20;
        r->xf = value5 & 0x10;
        r->dp = (value7 << 8) | value6;
        r->i = value5 & 0x04;
        r->d = value5 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
    uint8_t a_hi2 = a_hi;
    uint16_t x2 = x;
    uint16_t y2 = y;
    bool carry2 = carry;
    bool overflow2 = overflow;
    uint8_t data_bank2 = 0x7F;
    uint16_t direct_page2 = dp;
    for (;;) {
        r->a = (a_hi2 << 8) | 0;
        r->y = y2;
        r->c = carry2;
        r->z = 1;
        r->n = 0;
        r->v = overflow2;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank2;
        r->dp = direct_page2;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD0DB, 0x7EC030); GUARD_JSR(c, sp_call, 0xD0DB); } /* allocate_ppu_register_entry */
        r->sp += 3;
        uint16_t dp_ret7 = r->dp;
        uint8_t db_ret7 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all8 = r->a;
        uint16_t x_ret12 = r->x;
        uint16_t y_ret6 = r->y;
        bool carry_ret8 = r->c;
        bool overflow_ret8 = r->v;
        uint8_t value8 = BUS8_RDP(c, (db_ret7 << 0x10) + 2 + x_ret12);
        if (value8 == 0) {
            a_hi2 = a_all8 >> 8;
            x2 = x_ret12;
            y2 = y_ret6;
            carry2 = carry_ret8;
            overflow2 = overflow_ret8;
            data_bank2 = db_ret7;
            direct_page2 = dp_ret7;
            break;
        }
        uint8_t value9 = BUS8_RDP(c, (db_ret7 << 0x10) + 2 + x_ret12);
        BUS8_SET(c, (db_ret7 << 0x10) + 2 + x_ret12, (uint8_t)(value9 - 1));
        if ((uint8_t)(value9 - 1) == 0) {
            a_hi2 = a_all8 >> 8;
            x2 = x_ret12;
            y2 = y_ret6;
            carry2 = carry_ret8;
            overflow2 = overflow_ret8;
            data_bank2 = db_ret7;
            direct_page2 = dp_ret7;
            break;
        }
        r->z = (uint8_t)(value9 - 1) == 0;
        r->n = (uint8_t)(value9 - 1) & 0x80;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD0E8, 0x7EC097); GUARD_JSR(c, sp_call, 0xD0E8); } /* append_oneshot_ppu_entry */
        r->sp += 3;
        r->x = 1;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD0EE, 0x7EABE7); GUARD_JSR(c, sp_call, 0xD0EE); } /* receive_with_supplied_delay */
        r->sp += 3;
        uint16_t dp_ret9 = r->dp;
        uint8_t db_ret9 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret13 = r->xf;
        uint16_t a_all10 = r->a;
        uint16_t x_ret14 = r->x;
        uint16_t y_ret8 = r->y;
        bool carry_ret10 = r->c;
        bool overflow_ret10 = r->v;
        if (x_ret13 != 0) { c->fail = 3; return; }
        a_hi2 = a_all10 >> 8;
        x2 = x_ret14;
        y2 = y_ret8;
        carry2 = carry_ret10;
        overflow2 = overflow_ret10;
        data_bank2 = db_ret9;
        direct_page2 = dp_ret9;
        continue;
    }
    r->x = 0;
    r->c = carry2;
    r->z = 1;
    r->n = 0;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank2;
    r->dp = direct_page2;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD0F6, 0x7ECD82); GUARD_JSR(c, sp_call, 0xD0F6); } /* copy_and_submit_title_tilemap */
    r->sp += 3;
    uint16_t dp_ret10 = r->dp;
    bool x_ret15 = r->xf;
    uint16_t a_all11 = r->a;
    uint16_t x_ret16 = r->x;
    uint16_t y_ret9 = r->y;
    bool carry_ret11 = r->c;
    bool overflow_ret11 = r->v;
    uint8_t a_hi3 = a_all11 >> 8;
    uint16_t x3 = x_ret16;
    uint16_t y3 = y_ret9;
    bool carry3 = carry_ret11;
    bool overflow3 = overflow_ret11;
    uint8_t data_bank3 = data_bank2;
    uint16_t direct_page3 = dp_ret10;
    for (;;) {
        r->a = (a_hi3 << 8) | 0;
        r->y = y3;
        r->c = carry3;
        r->z = 1;
        r->n = 0;
        r->v = overflow3;
        r->mf = 1;
        r->xf = x_ret15;
        r->db = data_bank3;
        r->dp = direct_page3;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD0FB, 0x7EC030); GUARD_JSR(c, sp_call, 0xD0FB); } /* allocate_ppu_register_entry */
        r->sp += 3;
        uint16_t dp_ret11 = r->dp;
        uint8_t db_ret10 = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all12 = r->a;
        uint16_t x_ret17 = r->x;
        uint16_t y_ret10 = r->y;
        bool overflow_ret12 = r->v;
        uint8_t value10 = BUS8_RDP(c, (db_ret10 << 0x10) + 2 + x_ret17);
        if (value10 == 0x0F) {
            a_hi3 = a_all12 >> 8;
            x3 = x_ret17;
            y3 = y_ret10;
            carry3 = value10 >= 0x0F;
            overflow3 = overflow_ret12;
            data_bank3 = db_ret10;
            direct_page3 = dp_ret11;
            break;
        }
        uint8_t value11 = BUS8_RDP(c, (db_ret10 << 0x10) + 2 + x_ret17);
        BUS8_SET(c, (db_ret10 << 0x10) + 2 + x_ret17, (uint8_t)(value11 + 1));
        RAM8(0x0000 + sp0 - 3) = (uint8_t)(value11 + 1);
        r->c = value10 >= 0x0F;
        r->z = (uint8_t)(value11 + 1) == 0;
        r->n = (uint8_t)(value11 + 1) & 0x80;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD10D, 0x7EC097); GUARD_JSR(c, sp_call, 0xD10D); } /* append_oneshot_ppu_entry */
        r->sp += 4;
        uint16_t dp_ret12 = r->dp;
        uint8_t db_ret11 = r->db;
        uint16_t a_all13 = r->a;
        uint16_t y_ret11 = r->y;
        bool overflow_ret13 = r->v;
        uint8_t value12 = RAM8(0x0000 + sp0 - 3);
        if (value12 == 0x0F) {
            a_hi3 = a_all13 >> 8;
            x3 = x_ret17;
            y3 = y_ret11;
            carry3 = value12 >= 0x0F;
            overflow3 = overflow_ret13;
            data_bank3 = db_ret11;
            direct_page3 = dp_ret12;
            break;
        }
        r->x = 1;
        r->c = value12 >= 0x0F;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD118, 0x7EABE7); GUARD_JSR(c, sp_call, 0xD118); } /* receive_with_supplied_delay */
        r->sp += 3;
        uint16_t dp_ret13 = r->dp;
        uint8_t db_ret12 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all14 = r->a;
        uint16_t x_ret19 = r->x;
        uint16_t y_ret12 = r->y;
        bool carry_ret14 = r->c;
        bool overflow_ret14 = r->v;
        a_hi3 = a_all14 >> 8;
        x3 = x_ret19;
        y3 = y_ret12;
        carry3 = carry_ret14;
        overflow3 = overflow_ret14;
        data_bank3 = db_ret12;
        direct_page3 = dp_ret13;
        continue;
    }
    r->x = 0x1E;
    r->c = carry3;
    r->z = 0;
    r->n = 0;
    r->v = overflow3;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank3;
    r->dp = direct_page3;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD120, 0x7EABE7); GUARD_JSR(c, sp_call, 0xD120); } /* receive_with_supplied_delay */
    r->sp += 3;
    uint16_t dp_ret14 = r->dp;
    uint8_t db_ret13 = r->db;
    bool x_ret20 = r->xf;
    uint16_t a_all15 = r->a;
    uint16_t x_ret21 = r->x;
    uint16_t y_ret13 = r->y;
    bool carry_ret15 = r->c;
    bool zero_ret15 = r->z;
    bool negative_ret15 = r->n;
    bool overflow_ret15 = r->v;
    uint8_t a2 = (uint8_t)a_all15;
    uint8_t a_hi4 = a_all15 >> 8;
    uint16_t x4 = x_ret21;
    uint16_t y4 = y_ret13;
    bool carry4 = carry_ret15;
    bool zero3 = zero_ret15;
    bool negative3 = negative_ret15;
    bool overflow4 = overflow_ret15;
    uint8_t data_bank4 = db_ret13;
    uint16_t direct_page4 = dp_ret14;
    for (;;) {
        r->a = (a_hi4 << 8) | 0;
        r->y = y4;
        r->c = carry4;
        r->z = 1;
        r->n = 0;
        r->v = overflow4;
        r->mf = 1;
        r->xf = x_ret20;
        r->db = data_bank4;
        r->dp = direct_page4;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD125, 0x7EC030); GUARD_JSR(c, sp_call, 0xD125); } /* allocate_ppu_register_entry */
        r->sp += 3;
        uint16_t dp_ret15 = r->dp;
        uint8_t db_ret14 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all16 = r->a;
        uint16_t x_ret23 = r->x;
        uint16_t y_ret14 = r->y;
        bool carry_ret16 = r->c;
        bool overflow_ret16 = r->v;
        uint8_t value13 = BUS8_RDP(c, (db_ret14 << 0x10) + 2 + x_ret23);
        bool zero4;
        bool negative4;
        if (value13 == 0) {
            zero4 = value13 == 0;
            negative4 = value13 & 0x80;
        } else {
            uint8_t value14 = BUS8_RDP(c, (db_ret14 << 0x10) + 2 + x_ret23);
            BUS8_SET(c, (db_ret14 << 0x10) + 2 + x_ret23, (uint8_t)(value14 - 1));
            if ((uint8_t)(value14 - 1) != 0) {
                r->z = (uint8_t)(value14 - 1) == 0;
                r->n = (uint8_t)(value14 - 1) & 0x80;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD132, 0x7EC097); GUARD_JSR(c, sp_call, 0xD132); } /* append_oneshot_ppu_entry */
                r->sp += 3;
                r->x = 4;
                r->z = 0;
                r->n = 0;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD138, 0x7EABE7); GUARD_JSR(c, sp_call, 0xD138); } /* receive_with_supplied_delay */
                r->sp += 3;
                uint16_t dp_ret17 = r->dp;
                uint8_t db_ret16 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                uint16_t a_all18 = r->a;
                uint16_t x_ret25 = r->x;
                uint16_t y_ret16 = r->y;
                bool carry_ret18 = r->c;
                bool zero_ret18 = r->z;
                bool negative_ret18 = r->n;
                bool overflow_ret18 = r->v;
                a2 = (uint8_t)a_all18;
                a_hi4 = a_all18 >> 8;
                x4 = x_ret25;
                y4 = y_ret16;
                carry4 = carry_ret18;
                zero3 = zero_ret18;
                negative3 = negative_ret18;
                overflow4 = overflow_ret18;
                data_bank4 = db_ret16;
                direct_page4 = dp_ret17;
                continue;
            }
            zero4 = (uint8_t)(value14 - 1) == 0;
            negative4 = (uint8_t)(value14 - 1) & 0x80;
        }
        a2 = value13;
        a_hi4 = a_all16 >> 8;
        x4 = x_ret23;
        y4 = y_ret14;
        carry4 = carry_ret16;
        zero3 = zero4;
        negative3 = negative4;
        overflow4 = overflow_ret16;
        data_bank4 = db_ret14;
        direct_page4 = dp_ret15;
        break;
    }
    r->x = x4;
    r->y = y4;
    r->c = carry4;
    r->z = zero3;
    r->n = negative3;
    r->v = overflow4;
    r->mf = 1;
    r->db = data_bank4;
    r->dp = direct_page4;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD13D, 0x7EC097); GUARD_JSR(c, sp_call, 0xD13D); } /* append_oneshot_ppu_entry */
    r->sp += 3;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD140, 0x7EACD0); GUARD_JSR(c, sp_call, 0xD140); } /* current_task_parent_id */
    r->sp += 3;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all20 = r->a;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)a_all20;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD144, 0x7EB1A9); GUARD_JSR(c, sp_call, 0xD144); } /* allocate_eight_byte_record */
    r->sp += 4;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all21 = r->a;
    uint8_t value15 = RAM8(0x0000 + sp0 - 3);
    r->a = (a_all21 >> 8 << 8) | value15;
    r->z = value15 == 0;
    r->n = value15 & 0x80;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD148, 0x7EB258); GUARD_JSR(c, sp_call, 0xD148); } /* append_pending_record */
    r->sp += 3;
    uint8_t value16 = RAM8(0x0000 + sp0 - 2);
    uint8_t value17 = RAM8(0x0000 + sp0 - 1);
    uint8_t value18 = RAM8(0x0000 + sp0);
    r->c = value16 & 0x01;
    r->z = ((value18 << 8) | value17) == 0;
    r->n = ((value18 << 8) | value17) & 0x8000;
    r->v = value16 & 0x40;
    r->mf = value16 & 0x20;
    r->xf = value16 & 0x10;
    r->dp = (value18 << 8) | value17;
    r->i = value16 & 0x04;
    r->d = value16 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0x7ED0CC, SOM_RTL, "gen", run_title_control_task, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, 1, 0, 128, 55)
