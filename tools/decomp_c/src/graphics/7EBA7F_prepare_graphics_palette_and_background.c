#include "som_c.h"

/* 7EBA7F prepare_graphics_palette_and_background   [class B, 232 bytes, 105 instructions]
 * Source: src/boot/prepare_graphics_palette_and_background.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BYCV.
 */
static void prepare_graphics_palette_and_background(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0B) + 0x8 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->a = 0x49;
    r->x = 0x0200;
    r->c = (uint16_t)(sp0 - 3) >= 8;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 8) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0B)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x0B);
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBA92, 0x7E809B); GUARD_JSR(c, sp_call, 0xBA92); } /* create_graphics_buffer */
    r->sp += 11;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        RAM8(0x0007 + (uint16_t)(sp0 - 0x0B)) = (uint8_t)x_ret2;
        r->a = 1;
        r->x = (uint8_t)x_ret2;
        r->y = (uint8_t)y_ret;
        r->z = 0;
        r->n = 0;
        r->xf = 1;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBA9A, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xBA9A); } /* allocate_transfer_descriptor */
        r->sp += 11;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t x_ret4 = r->x;
        uint16_t value = BUS16_RDP(c, (uint16_t)(dp_ret + 7));
        BUS16_SET(c, (db_ret << 0x10) + 0x0A + x_ret4, value);
        BUS16_SET(c, (db_ret << 0x10) + 2 + x_ret4, 0x2000);
        BUS16_SET(c, (db_ret << 0x10) + 5 + x_ret4, 0x1000);
        BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret4, 0x7E);
        r->a = 0x107E;
        r->z = 0;
        r->n = 0;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBAB7, 0x7E90DA); GUARD_JSR(c, sp_call, 0xBAB7); } /* submit_transfer_or_program_hdma */
        r->sp += 11;
        if (r->mf != 0) { c->fail = 3; return; }
        r->a = 1;
        r->z = 0;
        r->n = 0;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBABD, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xBABD); } /* allocate_transfer_descriptor */
        r->sp += 11;
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t x_ret8 = r->x;
        uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 7));
        BUS16_SET(c, (db_ret3 << 0x10) + 0x0A + x_ret8, (uint16_t)(value2 + 0x0800));
        BUS16_SET(c, (db_ret3 << 0x10) + 2 + x_ret8, 0x3000);
        BUS16_SET(c, (db_ret3 << 0x10) + 5 + x_ret8, 0x1000);
        BUS8_SET(c, (db_ret3 << 0x10) + 4 + x_ret8, 0x7E);
        r->a = 0x107E;
        r->c = value2 + 0x0800 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = ((value2 ^ (uint16_t)(value2 + 0x0800)) & ((uint16_t)(value2 + 0x0800) ^ 0x0800) & 0x8000) != 0;
        r->mf = 1;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBADC, 0x7E90DA); GUARD_JSR(c, sp_call, 0xBADC); } /* submit_transfer_or_program_hdma */
        r->sp += 11;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all5 = r->a;
        r->a = (a_all5 >> 8 << 8) | 0;
        r->z = 1;
        r->n = 0;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBAE1, 0x7EBBAB); GUARD_JSR(c, sp_call, 0xBAE1); } /* allocate_palette_slot */
        r->sp += 11;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret11 = r->x;
        RAM8(0x0000 + sp0 - 0x0B) = x_ret11 >> 8;
        RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)x_ret11;
        r->a = 0x7E12;
        r->y = 0x5150;
        r->z = 0;
        r->n = 0;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBAED, 0x7EBC9A); GUARD_JSR(c, sp_call, 0xBAED); } /* copy_palette_colours */
        r->sp += 13;
        bool x_ret12 = r->xf;
        if (x_ret12) {
            c->fail = 3;
            return;
        } else {
            uint8_t value10 = RAM8(0x0000 + sp0 - 0x0C);
            uint8_t value11 = RAM8(0x0000 + sp0 - 0x0B);
            r->x = (value11 << 8) | value10;
            r->z = ((value11 << 8) | value10) == 0;
            r->n = ((value11 << 8) | value10) & 0x8000;
            r->xf = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBAF1, 0x7EBBFE); GUARD_JSR(c, sp_call, 0xBAF1); } /* queue_palette_upload */
            r->sp += 11;
            uint16_t dp_ret11 = r->dp;
            uint8_t db_ret11 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t a_all15 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret11 + 5), (((uint8_t)((uint8_t)a_all15 << 2) | 0x20) << 8) | 0);
            r->a = 0x19;
            r->c = (uint8_t)((uint8_t)a_all15 << 1) & 0x80;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBB02, 0x7EC76D); GUARD_JSR(c, sp_call, 0xBB02); } /* create_registered_vram_buffer */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t x_ret27 = r->x;
            bool carry_ret16 = r->c;
            bool overflow_ret16 = r->v;
            BUS16_SET(c, (uint16_t)(dp_ret11 + 3), x_ret27);
            BUS16_SET(c, (uint16_t)(dp_ret11 + 1), 0x0E);
            uint8_t a_hi3 = 0;
            uint16_t x4 = x_ret27;
            bool carry2 = carry_ret16;
            bool overflow2 = overflow_ret16;
            for (;;) {
                uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret11 + 5));
                uint8_t a2 = (uint8_t)value12;
                uint8_t a_hi4 = value12 >> 8;
                uint16_t x5 = x4;
                uint16_t y3 = 0x10;
                for (;;) {
                    BUS16_SET(c, (db_ret11 << 0x10) + x5, (a_hi4 << 8) | a2);
                    BUS16_SET(c, (db_ret11 << 0x10) + 0x20 + x5, ((a_hi4 << 8) | a2) ^ 0x0100);
                    uint8_t a2_next = (uint8_t)((((a_hi4 << 8) | a2) ^ 0x0100 ^ 0x0100) + 1);
                    uint8_t a_hi4_next = (uint16_t)((((a_hi4 << 8) | a2) ^ 0x0100 ^ 0x0100) + 1) >> 8;
                    uint16_t x5_next = (uint16_t)(x5 + 2);
                    uint16_t y3_next = (uint16_t)(y3 - 1);
                    a2 = a2_next;
                    a_hi4 = a_hi4_next;
                    x5 = x5_next;
                    y3 = y3_next;
                    if (!(y3 != 0)) break;
                }
                BUS16_SET(c, (uint16_t)(dp_ret11 + 5), (a_hi4 << 8) | a2);
                uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret11 + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret11 + 1), (uint16_t)(value13 - 1));
                a_hi3 = (uint16_t)(x5 + 0x20) >> 8;
                x4 = (uint16_t)(x5 + 0x20);
                carry2 = x5 + 0x20 > 0xFFFF;
                overflow2 = ((x5 ^ (uint16_t)(x5 + 0x20)) & ((uint16_t)(x5 + 0x20) ^ 0x20) & 0x8000) != 0;
                if (!((uint16_t)(value13 - 1) != 0)) break;
            }
            uint16_t x6 = x4;
            uint16_t y4 = 0x0640;
            for (;;) {
                BUS16_SET(c, (db_ret11 << 0x10) + x6, 0x210F);
                x6 = (uint16_t)(x6 + 2);
                y4 = (uint16_t)(y4 - 1);
                if (!(y4 != 0)) break;
            }
            uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret11 + 3));
            r->a = 0x210F;
            r->x = value14;
            r->y = y4;
            r->c = carry2;
            r->z = value14 == 0;
            r->n = value14 & 0x8000;
            r->v = overflow2;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBB3F, 0x7EC870); GUARD_JSR(c, sp_call, 0xBB3F); } /* queue_registered_vram_buffer */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            r->a = 0x12;
            r->z = 0;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBB45, 0x7EC030); GUARD_JSR(c, sp_call, 0xBB45); } /* allocate_ppu_register_entry */
            r->sp += 11;
            uint8_t db_ret12 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            uint16_t x_ret31 = r->x;
            BUS16_SET(c, (db_ret12 << 0x10) + 2 + x_ret31, 0xFFC8);
            r->a = 0xFFC8;
            r->z = 0;
            r->n = 1;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBB4E, 0x7EC097); GUARD_JSR(c, sp_call, 0xBB4E); } /* append_oneshot_ppu_entry */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            r->a = 0x11;
            r->z = 0;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBB54, 0x7EC030); GUARD_JSR(c, sp_call, 0xBB54); } /* allocate_ppu_register_entry */
            r->sp += 11;
            uint8_t db_ret14 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            uint16_t x_ret34 = r->x;
            BUS16_SET(c, (db_ret14 << 0x10) + 2 + x_ret34, 0);
            r->a = 0;
            r->z = 1;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBB5D, 0x7EC097); GUARD_JSR(c, sp_call, 0xBB5D); } /* append_oneshot_ppu_entry */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            uint8_t value15 = RAM8(0x0000 + sp0 - 2);
            uint8_t value16 = RAM8(0x0000 + sp0 - 1);
            uint8_t value17 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((uint16_t)(sp0 - 0x0B) + 8);
            r->c = value15 & 0x01;
            r->v = value15 & 0x40;
            r->mf = value15 & 0x20;
            r->xf = value15 & 0x10;
            r->dp = (value17 << 8) | value16;
            r->i = value15 & 0x04;
            r->d = value15 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0B), x_ret2);
        r->a = 1;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBA9A, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xBA9A); } /* allocate_transfer_descriptor */
        r->sp += 11;
        uint16_t dp_ret16 = r->dp;
        uint8_t db_ret16 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t x_ret37 = r->x;
        uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret16 + 7));
        BUS16_SET(c, (db_ret16 << 0x10) + 0x0A + x_ret37, value18);
        BUS16_SET(c, (db_ret16 << 0x10) + 2 + x_ret37, 0x2000);
        BUS16_SET(c, (db_ret16 << 0x10) + 5 + x_ret37, 0x1000);
        BUS8_SET(c, (db_ret16 << 0x10) + 4 + x_ret37, 0x7E);
        r->a = 0x107E;
        r->z = 0;
        r->n = 0;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBAB7, 0x7E90DA); GUARD_JSR(c, sp_call, 0xBAB7); } /* submit_transfer_or_program_hdma */
        r->sp += 11;
        if (r->mf != 0) { c->fail = 3; return; }
        r->a = 1;
        r->z = 0;
        r->n = 0;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBABD, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xBABD); } /* allocate_transfer_descriptor */
        r->sp += 11;
        uint16_t dp_ret18 = r->dp;
        uint8_t db_ret18 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t x_ret41 = r->x;
        uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp_ret18 + 7));
        BUS16_SET(c, (db_ret18 << 0x10) + 0x0A + x_ret41, (uint16_t)(value19 + 0x0800));
        BUS16_SET(c, (db_ret18 << 0x10) + 2 + x_ret41, 0x3000);
        BUS16_SET(c, (db_ret18 << 0x10) + 5 + x_ret41, 0x1000);
        BUS8_SET(c, (db_ret18 << 0x10) + 4 + x_ret41, 0x7E);
        r->a = 0x107E;
        r->c = value19 + 0x0800 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = ((value19 ^ (uint16_t)(value19 + 0x0800)) & ((uint16_t)(value19 + 0x0800) ^ 0x0800) & 0x8000) != 0;
        r->mf = 1;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBADC, 0x7E90DA); GUARD_JSR(c, sp_call, 0xBADC); } /* submit_transfer_or_program_hdma */
        r->sp += 11;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all25 = r->a;
        r->a = (a_all25 >> 8 << 8) | 0;
        r->z = 1;
        r->n = 0;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBAE1, 0x7EBBAB); GUARD_JSR(c, sp_call, 0xBAE1); } /* allocate_palette_slot */
        r->sp += 11;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret44 = r->x;
        RAM8(0x0000 + sp0 - 0x0B) = x_ret44 >> 8;
        RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)x_ret44;
        r->a = 0x7E12;
        r->y = 0x5150;
        r->z = 0;
        r->n = 0;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBAED, 0x7EBC9A); GUARD_JSR(c, sp_call, 0xBAED); } /* copy_palette_colours */
        r->sp += 13;
        bool x_ret45 = r->xf;
        if (x_ret45) {
            c->fail = 3;
            return;
        } else {
            uint8_t value27 = RAM8(0x0000 + sp0 - 0x0C);
            uint8_t value28 = RAM8(0x0000 + sp0 - 0x0B);
            r->x = (value28 << 8) | value27;
            r->z = ((value28 << 8) | value27) == 0;
            r->n = ((value28 << 8) | value27) & 0x8000;
            r->xf = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBAF1, 0x7EBBFE); GUARD_JSR(c, sp_call, 0xBAF1); } /* queue_palette_upload */
            r->sp += 11;
            uint16_t dp_ret26 = r->dp;
            uint8_t db_ret26 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t a_all35 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret26 + 5), (((uint8_t)((uint8_t)a_all35 << 2) | 0x20) << 8) | 0);
            r->a = 0x19;
            r->c = (uint8_t)((uint8_t)a_all35 << 1) & 0x80;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBB02, 0x7EC76D); GUARD_JSR(c, sp_call, 0xBB02); } /* create_registered_vram_buffer */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t x_ret60 = r->x;
            bool carry_ret36 = r->c;
            bool overflow_ret36 = r->v;
            BUS16_SET(c, (uint16_t)(dp_ret26 + 3), x_ret60);
            BUS16_SET(c, (uint16_t)(dp_ret26 + 1), 0x0E);
            uint8_t a_hi7 = 0;
            uint16_t x10 = x_ret60;
            bool carry4 = carry_ret36;
            bool overflow4 = overflow_ret36;
            for (;;) {
                uint16_t value29 = BUS16_RDP(c, (uint16_t)(dp_ret26 + 5));
                uint8_t a4 = (uint8_t)value29;
                uint8_t a_hi8 = value29 >> 8;
                uint16_t x11 = x10;
                uint16_t y7 = 0x10;
                for (;;) {
                    BUS16_SET(c, (db_ret26 << 0x10) + x11, (a_hi8 << 8) | a4);
                    BUS16_SET(c, (db_ret26 << 0x10) + 0x20 + x11, ((a_hi8 << 8) | a4) ^ 0x0100);
                    uint8_t a4_next = (uint8_t)((((a_hi8 << 8) | a4) ^ 0x0100 ^ 0x0100) + 1);
                    uint8_t a_hi8_next = (uint16_t)((((a_hi8 << 8) | a4) ^ 0x0100 ^ 0x0100) + 1) >> 8;
                    uint16_t x11_next = (uint16_t)(x11 + 2);
                    uint16_t y7_next = (uint16_t)(y7 - 1);
                    a4 = a4_next;
                    a_hi8 = a_hi8_next;
                    x11 = x11_next;
                    y7 = y7_next;
                    if (!(y7 != 0)) break;
                }
                BUS16_SET(c, (uint16_t)(dp_ret26 + 5), (a_hi8 << 8) | a4);
                uint16_t value30 = BUS16_RDP(c, (uint16_t)(dp_ret26 + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret26 + 1), (uint16_t)(value30 - 1));
                a_hi7 = (uint16_t)(x11 + 0x20) >> 8;
                x10 = (uint16_t)(x11 + 0x20);
                carry4 = x11 + 0x20 > 0xFFFF;
                overflow4 = ((x11 ^ (uint16_t)(x11 + 0x20)) & ((uint16_t)(x11 + 0x20) ^ 0x20) & 0x8000) != 0;
                if (!((uint16_t)(value30 - 1) != 0)) break;
            }
            uint16_t x12 = x10;
            uint16_t y8 = 0x0640;
            for (;;) {
                BUS16_SET(c, (db_ret26 << 0x10) + x12, 0x210F);
                x12 = (uint16_t)(x12 + 2);
                y8 = (uint16_t)(y8 - 1);
                if (!(y8 != 0)) break;
            }
            uint16_t value31 = BUS16_RDP(c, (uint16_t)(dp_ret26 + 3));
            r->a = 0x210F;
            r->x = value31;
            r->y = y8;
            r->c = carry4;
            r->z = value31 == 0;
            r->n = value31 & 0x8000;
            r->v = overflow4;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBB3F, 0x7EC870); GUARD_JSR(c, sp_call, 0xBB3F); } /* queue_registered_vram_buffer */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            r->a = 0x12;
            r->z = 0;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBB45, 0x7EC030); GUARD_JSR(c, sp_call, 0xBB45); } /* allocate_ppu_register_entry */
            r->sp += 11;
            uint8_t db_ret27 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            uint16_t x_ret64 = r->x;
            BUS16_SET(c, (db_ret27 << 0x10) + 2 + x_ret64, 0xFFC8);
            r->a = 0xFFC8;
            r->z = 0;
            r->n = 1;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBB4E, 0x7EC097); GUARD_JSR(c, sp_call, 0xBB4E); } /* append_oneshot_ppu_entry */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            r->a = 0x11;
            r->z = 0;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBB54, 0x7EC030); GUARD_JSR(c, sp_call, 0xBB54); } /* allocate_ppu_register_entry */
            r->sp += 11;
            uint8_t db_ret29 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            uint16_t x_ret67 = r->x;
            BUS16_SET(c, (db_ret29 << 0x10) + 2 + x_ret67, 0);
            r->a = 0;
            r->z = 1;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBB5D, 0x7EC097); GUARD_JSR(c, sp_call, 0xBB5D); } /* append_oneshot_ppu_entry */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            uint8_t value32 = RAM8(0x0000 + sp0 - 2);
            uint8_t value33 = RAM8(0x0000 + sp0 - 1);
            uint8_t value34 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((uint16_t)(sp0 - 0x0B) + 8);
            r->c = value32 & 0x01;
            r->v = value32 & 0x40;
            r->mf = value32 & 0x20;
            r->xf = value32 & 0x10;
            r->dp = (value34 << 8) | value33;
            r->i = value32 & 0x04;
            r->d = value32 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0x7EBA7F, SOM_RTS, "gen", prepare_graphics_palette_and_background, 0, L_B | L_Y | L_C | L_V, 13, 1, 0, 232, 105)
