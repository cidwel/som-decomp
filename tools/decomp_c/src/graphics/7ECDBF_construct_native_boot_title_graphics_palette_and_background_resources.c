#include "som_c.h"

/* 7ECDBF construct_native_boot_title_graphics_palette_and_background_resources   [class B, 163 bytes, 72 instructions]
 * Source: src/boot/construct_native_boot_title_graphics_palette_and_background_resources.s
 * Documented in docs/boot-native-task-graphics-setup.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCZNV.
 */
static void construct_native_boot_title_graphics_palette_and_background_resources(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp + 3;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0 - 3) = dp >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 5) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 6) = 0x7E;
    RAM8(0x0000 + sp0 - 7) = x >> 8;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)x;
    r->a = ((uint16_t)(sp0 - 9) >> 8 << 8) | 0x46;
    r->x = 0x80;
    r->z = 0;
    r->n = 0;
    r->dp = (uint16_t)(sp0 - 9);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCDD0, 0x7E809B); GUARD_JSR(c, sp_call, 0xCDD0); } /* create_graphics_buffer */
    r->sp += 6;
    uint16_t a_all = r->a;
    r->a = (a_all >> 8 << 8) | 0x46;
    r->z = 0;
    r->n = 0;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCDD5, 0x7E81D6); GUARD_JSR(c, sp_call, 0xCDD5); } /* allocate_graphics_workspace_block */
    r->sp += 6;
    bool x_ret3 = r->xf;
    uint16_t x_ret4 = r->x;
    if (x_ret3) {
        RAM8(0x0308) = (uint8_t)x_ret4;
        r->a = 1;
        r->x = (uint8_t)x_ret4;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 1;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCDE0, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xCDE0); } /* allocate_transfer_descriptor */
        r->sp += 6;
        uint8_t db_ret = r->db;
        uint16_t x_ret6 = r->x;
        BUS16_SET(c, (db_ret << 0x10) + 2 + x_ret6, 0x4000);
        uint16_t value = BUS16_RDP(c, (db_ret << 0x10) + 0x0308);
        BUS16_SET(c, (db_ret << 0x10) + 0x0A + x_ret6, value);
        BUS16_SET(c, (db_ret << 0x10) + 5 + x_ret6, 0x1000);
        BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret6, 0x7E);
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCDFC, 0x7E90DA); GUARD_JSR(c, sp_call, 0xCDFC); } /* submit_transfer_or_program_hdma */
        r->sp += 6;
        uint16_t a_all4 = r->a;
        r->a = (a_all4 >> 8 << 8) | 0;
        r->z = 1;
        r->n = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCE01, 0x7EBBAB); GUARD_JSR(c, sp_call, 0xCE01); } /* allocate_palette_slot */
        r->sp += 6;
        uint8_t db_ret3 = r->db;
        uint16_t x_ret9 = r->x;
        BUS16_SET(c, (db_ret3 << 0x10) + 0x030A, x_ret9);
        r->a = 0x7E1D;
        r->y = 0x5120;
        r->z = 0;
        r->n = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCE0F, 0x7EBC9A); GUARD_JSR(c, sp_call, 0xCE0F); } /* copy_palette_colours */
        r->sp += 6;
        bool x_ret10 = r->xf;
        uint16_t y_ret6 = r->y;
        if (x_ret10) {
            uint8_t value2 = BUS8_RDP(c, (db_ret3 << 0x10) + 0x030A);
            r->x = value2;
            r->y = (uint8_t)y_ret6;
            r->z = value2 == 0;
            r->n = value2 & 0x80;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCE15, 0x7EBBFE); GUARD_JSR(c, sp_call, 0xCE15); } /* queue_palette_upload */
            r->sp += 6;
            uint8_t db_ret4 = r->db;
            uint16_t a_all7 = r->a;
            BUS8_SET(c, (db_ret4 << 0x10) + 0x0310, (uint8_t)((uint8_t)a_all7 << 2) | 0x20);
            r->a = (a_all7 >> 8 << 8) | 0x14;
            r->c = (uint8_t)((uint8_t)a_all7 << 1) & 0x80;
            r->z = 0;
            r->n = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCE21, 0x7EC76D); GUARD_JSR(c, sp_call, 0xCE21); } /* create_registered_vram_buffer */
            r->sp += 6;
            bool x_ret14 = r->xf;
            uint16_t x_ret15 = r->x;
            if (x_ret14) {
                BUS8_SET(c, (db_ret4 << 0x10) + 0x0306, (uint8_t)x_ret15);
                uint16_t value3 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x0306);
                r->x = (uint8_t)(value3 + 0x0740);
                r->c = value3 + 0x0740 > 0xFFFF;
                r->z = (uint8_t)(value3 + 0x0740) == 0;
                r->n = (uint8_t)(value3 + 0x0740) & 0x80;
                r->v = ((value3 ^ (uint16_t)(value3 + 0x0740)) & ((uint16_t)(value3 + 0x0740) ^ 0x0740) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE31, 0x7E9716); GUARD_JSR(c, sp_call, 0xCE31); } /* copy_native_title_font_and_register_eight_upper_palette_slots */
                r->sp += 6;
                uint16_t a_all9 = r->a;
                r->a = (a_all9 >> 8 << 8) | 0x2C;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE38, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE38); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret5 = r->db;
                uint16_t x_ret19 = r->x;
                uint8_t value4 = BUS8_RDP(c, (db_ret5 << 0x10) + 2 + x_ret19);
                BUS8_SET(c, (db_ret5 << 0x10) + 2 + x_ret19, value4 | 2);
                r->z = (value4 | 2) == 0;
                r->n = (value4 | 2) & 0x80;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE43, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE43); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint16_t a_all11 = r->a;
                r->a = (a_all11 >> 8 << 8) | 5;
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE48, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE48); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret7 = r->db;
                uint16_t x_ret22 = r->x;
                BUS8_SET(c, (db_ret7 << 0x10) + 2 + x_ret22, 3);
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE50, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE50); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint8_t db_ret8 = r->db;
                uint16_t a_all13 = r->a;
                r->a = (a_all13 >> 8 << 8) | 0;
                r->x = 9;
                r->z = 1;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE58, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xCE58); } /* allocate_and_fill_bytes */
                r->sp += 6;
                bool m_ret5 = r->mf;
                bool x_ret23 = r->xf;
                uint16_t x_ret24 = r->x;
                uint16_t y_ret14 = r->y;
                if (x_ret23) {
                    BUS8_SET(c, (db_ret8 << 0x10) + 0x030C, (uint8_t)x_ret24);
                    if (m_ret5) {
                        uint8_t value8 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value9 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value10 = RAM8(0x0000 + sp0 - 3);
                        r->x = (uint8_t)x_ret24;
                        r->y = (uint8_t)y_ret14;
                        r->c = value8 & 0x01;
                        r->z = ((value10 << 8) | value9) == 0;
                        r->n = ((value10 << 8) | value9) & 0x8000;
                        r->v = value8 & 0x40;
                        r->mf = value8 & 0x20;
                        r->xf = value8 & 0x10;
                        r->dp = (value10 << 8) | value9;
                        r->i = value8 & 0x04;
                        r->d = value8 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value15 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value16 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value17 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value18 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value19 = RAM8(0x0000 + sp0);
                        r->a = (value16 << 8) | value15;
                        r->x = (uint8_t)x_ret24;
                        r->y = (uint8_t)y_ret14;
                        r->c = value17 & 0x01;
                        r->z = ((value19 << 8) | value18) == 0;
                        r->n = ((value19 << 8) | value18) & 0x8000;
                        r->v = value17 & 0x40;
                        r->mf = value17 & 0x20;
                        r->xf = value17 & 0x10;
                        r->dp = (value19 << 8) | value18;
                        r->i = value17 & 0x04;
                        r->d = value17 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                } else {
                    BUS16_SET(c, (db_ret8 << 0x10) + 0x030C, x_ret24);
                    if (m_ret5) {
                        uint8_t value23 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value24 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value25 = RAM8(0x0000 + sp0 - 3);
                        r->c = value23 & 0x01;
                        r->z = ((value25 << 8) | value24) == 0;
                        r->n = ((value25 << 8) | value24) & 0x8000;
                        r->v = value23 & 0x40;
                        r->mf = value23 & 0x20;
                        r->xf = value23 & 0x10;
                        r->dp = (value25 << 8) | value24;
                        r->i = value23 & 0x04;
                        r->d = value23 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value30 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value31 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value32 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value33 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value34 = RAM8(0x0000 + sp0);
                        r->a = (value31 << 8) | value30;
                        r->c = value32 & 0x01;
                        r->z = ((value34 << 8) | value33) == 0;
                        r->n = ((value34 << 8) | value33) & 0x8000;
                        r->v = value32 & 0x40;
                        r->mf = value32 & 0x20;
                        r->xf = value32 & 0x10;
                        r->dp = (value34 << 8) | value33;
                        r->i = value32 & 0x04;
                        r->d = value32 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                }
            } else {
                BUS16_SET(c, (db_ret4 << 0x10) + 0x0306, x_ret15);
                uint16_t value35 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x0306);
                r->x = (uint16_t)(value35 + 0x0740);
                r->c = value35 + 0x0740 > 0xFFFF;
                r->z = (uint16_t)(value35 + 0x0740) == 0;
                r->n = (uint16_t)(value35 + 0x0740) & 0x8000;
                r->v = ((value35 ^ (uint16_t)(value35 + 0x0740)) & ((uint16_t)(value35 + 0x0740) ^ 0x0740) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE31, 0x7E9716); GUARD_JSR(c, sp_call, 0xCE31); } /* copy_native_title_font_and_register_eight_upper_palette_slots */
                r->sp += 6;
                uint16_t a_all15 = r->a;
                r->a = (a_all15 >> 8 << 8) | 0x2C;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE38, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE38); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret9 = r->db;
                uint16_t x_ret28 = r->x;
                uint8_t value36 = BUS8_RDP(c, (db_ret9 << 0x10) + 2 + x_ret28);
                BUS8_SET(c, (db_ret9 << 0x10) + 2 + x_ret28, value36 | 2);
                r->z = (value36 | 2) == 0;
                r->n = (value36 | 2) & 0x80;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE43, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE43); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint16_t a_all17 = r->a;
                r->a = (a_all17 >> 8 << 8) | 5;
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE48, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE48); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret11 = r->db;
                uint16_t x_ret31 = r->x;
                BUS8_SET(c, (db_ret11 << 0x10) + 2 + x_ret31, 3);
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE50, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE50); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint8_t db_ret12 = r->db;
                uint16_t a_all19 = r->a;
                r->a = (a_all19 >> 8 << 8) | 0;
                r->x = 9;
                r->z = 1;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE58, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xCE58); } /* allocate_and_fill_bytes */
                r->sp += 6;
                bool m_ret7 = r->mf;
                bool x_ret32 = r->xf;
                uint16_t x_ret33 = r->x;
                uint16_t y_ret20 = r->y;
                if (x_ret32) {
                    BUS8_SET(c, (db_ret12 << 0x10) + 0x030C, (uint8_t)x_ret33);
                    if (m_ret7) {
                        uint8_t value40 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value41 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value42 = RAM8(0x0000 + sp0 - 3);
                        r->x = (uint8_t)x_ret33;
                        r->y = (uint8_t)y_ret20;
                        r->c = value40 & 0x01;
                        r->z = ((value42 << 8) | value41) == 0;
                        r->n = ((value42 << 8) | value41) & 0x8000;
                        r->v = value40 & 0x40;
                        r->mf = value40 & 0x20;
                        r->xf = value40 & 0x10;
                        r->dp = (value42 << 8) | value41;
                        r->i = value40 & 0x04;
                        r->d = value40 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value47 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value48 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value49 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value50 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value51 = RAM8(0x0000 + sp0);
                        r->a = (value48 << 8) | value47;
                        r->x = (uint8_t)x_ret33;
                        r->y = (uint8_t)y_ret20;
                        r->c = value49 & 0x01;
                        r->z = ((value51 << 8) | value50) == 0;
                        r->n = ((value51 << 8) | value50) & 0x8000;
                        r->v = value49 & 0x40;
                        r->mf = value49 & 0x20;
                        r->xf = value49 & 0x10;
                        r->dp = (value51 << 8) | value50;
                        r->i = value49 & 0x04;
                        r->d = value49 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                } else {
                    BUS16_SET(c, (db_ret12 << 0x10) + 0x030C, x_ret33);
                    if (m_ret7) {
                        uint8_t value55 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value56 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value57 = RAM8(0x0000 + sp0 - 3);
                        r->c = value55 & 0x01;
                        r->z = ((value57 << 8) | value56) == 0;
                        r->n = ((value57 << 8) | value56) & 0x8000;
                        r->v = value55 & 0x40;
                        r->mf = value55 & 0x20;
                        r->xf = value55 & 0x10;
                        r->dp = (value57 << 8) | value56;
                        r->i = value55 & 0x04;
                        r->d = value55 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value62 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value63 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value64 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value65 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value66 = RAM8(0x0000 + sp0);
                        r->a = (value63 << 8) | value62;
                        r->c = value64 & 0x01;
                        r->z = ((value66 << 8) | value65) == 0;
                        r->n = ((value66 << 8) | value65) & 0x8000;
                        r->v = value64 & 0x40;
                        r->mf = value64 & 0x20;
                        r->xf = value64 & 0x10;
                        r->dp = (value66 << 8) | value65;
                        r->i = value64 & 0x04;
                        r->d = value64 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                }
            }
        } else {
            uint16_t value67 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x030A);
            r->x = value67;
            r->z = value67 == 0;
            r->n = value67 & 0x8000;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCE15, 0x7EBBFE); GUARD_JSR(c, sp_call, 0xCE15); } /* queue_palette_upload */
            r->sp += 6;
            uint8_t db_ret13 = r->db;
            uint16_t a_all21 = r->a;
            BUS8_SET(c, (db_ret13 << 0x10) + 0x0310, (uint8_t)((uint8_t)a_all21 << 2) | 0x20);
            r->a = (a_all21 >> 8 << 8) | 0x14;
            r->c = (uint8_t)((uint8_t)a_all21 << 1) & 0x80;
            r->z = 0;
            r->n = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCE21, 0x7EC76D); GUARD_JSR(c, sp_call, 0xCE21); } /* create_registered_vram_buffer */
            r->sp += 6;
            bool x_ret36 = r->xf;
            uint16_t x_ret37 = r->x;
            if (x_ret36) {
                BUS8_SET(c, (db_ret13 << 0x10) + 0x0306, (uint8_t)x_ret37);
                uint16_t value68 = BUS16_RDP(c, (db_ret13 << 0x10) + 0x0306);
                r->x = (uint8_t)(value68 + 0x0740);
                r->c = value68 + 0x0740 > 0xFFFF;
                r->z = (uint8_t)(value68 + 0x0740) == 0;
                r->n = (uint8_t)(value68 + 0x0740) & 0x80;
                r->v = ((value68 ^ (uint16_t)(value68 + 0x0740)) & ((uint16_t)(value68 + 0x0740) ^ 0x0740) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE31, 0x7E9716); GUARD_JSR(c, sp_call, 0xCE31); } /* copy_native_title_font_and_register_eight_upper_palette_slots */
                r->sp += 6;
                uint16_t a_all23 = r->a;
                r->a = (a_all23 >> 8 << 8) | 0x2C;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE38, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE38); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret14 = r->db;
                uint16_t x_ret41 = r->x;
                uint8_t value69 = BUS8_RDP(c, (db_ret14 << 0x10) + 2 + x_ret41);
                BUS8_SET(c, (db_ret14 << 0x10) + 2 + x_ret41, value69 | 2);
                r->z = (value69 | 2) == 0;
                r->n = (value69 | 2) & 0x80;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE43, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE43); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint16_t a_all25 = r->a;
                r->a = (a_all25 >> 8 << 8) | 5;
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE48, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE48); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret16 = r->db;
                uint16_t x_ret44 = r->x;
                BUS8_SET(c, (db_ret16 << 0x10) + 2 + x_ret44, 3);
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE50, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE50); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint8_t db_ret17 = r->db;
                uint16_t a_all27 = r->a;
                r->a = (a_all27 >> 8 << 8) | 0;
                r->x = 9;
                r->z = 1;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE58, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xCE58); } /* allocate_and_fill_bytes */
                r->sp += 6;
                bool m_ret10 = r->mf;
                bool x_ret45 = r->xf;
                uint16_t x_ret46 = r->x;
                uint16_t y_ret28 = r->y;
                if (x_ret45) {
                    BUS8_SET(c, (db_ret17 << 0x10) + 0x030C, (uint8_t)x_ret46);
                    if (m_ret10) {
                        uint8_t value73 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value74 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value75 = RAM8(0x0000 + sp0 - 3);
                        r->x = (uint8_t)x_ret46;
                        r->y = (uint8_t)y_ret28;
                        r->c = value73 & 0x01;
                        r->z = ((value75 << 8) | value74) == 0;
                        r->n = ((value75 << 8) | value74) & 0x8000;
                        r->v = value73 & 0x40;
                        r->mf = value73 & 0x20;
                        r->xf = value73 & 0x10;
                        r->dp = (value75 << 8) | value74;
                        r->i = value73 & 0x04;
                        r->d = value73 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value80 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value81 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value82 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value83 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value84 = RAM8(0x0000 + sp0);
                        r->a = (value81 << 8) | value80;
                        r->x = (uint8_t)x_ret46;
                        r->y = (uint8_t)y_ret28;
                        r->c = value82 & 0x01;
                        r->z = ((value84 << 8) | value83) == 0;
                        r->n = ((value84 << 8) | value83) & 0x8000;
                        r->v = value82 & 0x40;
                        r->mf = value82 & 0x20;
                        r->xf = value82 & 0x10;
                        r->dp = (value84 << 8) | value83;
                        r->i = value82 & 0x04;
                        r->d = value82 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                } else {
                    BUS16_SET(c, (db_ret17 << 0x10) + 0x030C, x_ret46);
                    if (m_ret10) {
                        uint8_t value88 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value89 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value90 = RAM8(0x0000 + sp0 - 3);
                        r->c = value88 & 0x01;
                        r->z = ((value90 << 8) | value89) == 0;
                        r->n = ((value90 << 8) | value89) & 0x8000;
                        r->v = value88 & 0x40;
                        r->mf = value88 & 0x20;
                        r->xf = value88 & 0x10;
                        r->dp = (value90 << 8) | value89;
                        r->i = value88 & 0x04;
                        r->d = value88 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value95 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value96 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value97 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value98 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value99 = RAM8(0x0000 + sp0);
                        r->a = (value96 << 8) | value95;
                        r->c = value97 & 0x01;
                        r->z = ((value99 << 8) | value98) == 0;
                        r->n = ((value99 << 8) | value98) & 0x8000;
                        r->v = value97 & 0x40;
                        r->mf = value97 & 0x20;
                        r->xf = value97 & 0x10;
                        r->dp = (value99 << 8) | value98;
                        r->i = value97 & 0x04;
                        r->d = value97 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                }
            } else {
                BUS16_SET(c, (db_ret13 << 0x10) + 0x0306, x_ret37);
                uint16_t value100 = BUS16_RDP(c, (db_ret13 << 0x10) + 0x0306);
                r->x = (uint16_t)(value100 + 0x0740);
                r->c = value100 + 0x0740 > 0xFFFF;
                r->z = (uint16_t)(value100 + 0x0740) == 0;
                r->n = (uint16_t)(value100 + 0x0740) & 0x8000;
                r->v = ((value100 ^ (uint16_t)(value100 + 0x0740)) & ((uint16_t)(value100 + 0x0740) ^ 0x0740) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE31, 0x7E9716); GUARD_JSR(c, sp_call, 0xCE31); } /* copy_native_title_font_and_register_eight_upper_palette_slots */
                r->sp += 6;
                uint16_t a_all29 = r->a;
                r->a = (a_all29 >> 8 << 8) | 0x2C;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE38, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE38); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret18 = r->db;
                uint16_t x_ret50 = r->x;
                uint8_t value101 = BUS8_RDP(c, (db_ret18 << 0x10) + 2 + x_ret50);
                BUS8_SET(c, (db_ret18 << 0x10) + 2 + x_ret50, value101 | 2);
                r->z = (value101 | 2) == 0;
                r->n = (value101 | 2) & 0x80;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE43, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE43); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint16_t a_all31 = r->a;
                r->a = (a_all31 >> 8 << 8) | 5;
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE48, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE48); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret20 = r->db;
                uint16_t x_ret53 = r->x;
                BUS8_SET(c, (db_ret20 << 0x10) + 2 + x_ret53, 3);
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE50, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE50); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint8_t db_ret21 = r->db;
                uint16_t a_all33 = r->a;
                r->a = (a_all33 >> 8 << 8) | 0;
                r->x = 9;
                r->z = 1;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE58, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xCE58); } /* allocate_and_fill_bytes */
                r->sp += 6;
                bool m_ret12 = r->mf;
                bool x_ret54 = r->xf;
                uint16_t x_ret55 = r->x;
                uint16_t y_ret34 = r->y;
                if (x_ret54) {
                    BUS8_SET(c, (db_ret21 << 0x10) + 0x030C, (uint8_t)x_ret55);
                    if (m_ret12) {
                        uint8_t value105 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value106 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value107 = RAM8(0x0000 + sp0 - 3);
                        r->x = (uint8_t)x_ret55;
                        r->y = (uint8_t)y_ret34;
                        r->c = value105 & 0x01;
                        r->z = ((value107 << 8) | value106) == 0;
                        r->n = ((value107 << 8) | value106) & 0x8000;
                        r->v = value105 & 0x40;
                        r->mf = value105 & 0x20;
                        r->xf = value105 & 0x10;
                        r->dp = (value107 << 8) | value106;
                        r->i = value105 & 0x04;
                        r->d = value105 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value112 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value113 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value114 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value115 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value116 = RAM8(0x0000 + sp0);
                        r->a = (value113 << 8) | value112;
                        r->x = (uint8_t)x_ret55;
                        r->y = (uint8_t)y_ret34;
                        r->c = value114 & 0x01;
                        r->z = ((value116 << 8) | value115) == 0;
                        r->n = ((value116 << 8) | value115) & 0x8000;
                        r->v = value114 & 0x40;
                        r->mf = value114 & 0x20;
                        r->xf = value114 & 0x10;
                        r->dp = (value116 << 8) | value115;
                        r->i = value114 & 0x04;
                        r->d = value114 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                } else {
                    BUS16_SET(c, (db_ret21 << 0x10) + 0x030C, x_ret55);
                    if (m_ret12) {
                        uint8_t value120 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value121 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value122 = RAM8(0x0000 + sp0 - 3);
                        r->c = value120 & 0x01;
                        r->z = ((value122 << 8) | value121) == 0;
                        r->n = ((value122 << 8) | value121) & 0x8000;
                        r->v = value120 & 0x40;
                        r->mf = value120 & 0x20;
                        r->xf = value120 & 0x10;
                        r->dp = (value122 << 8) | value121;
                        r->i = value120 & 0x04;
                        r->d = value120 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value127 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value128 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value129 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value130 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value131 = RAM8(0x0000 + sp0);
                        r->a = (value128 << 8) | value127;
                        r->c = value129 & 0x01;
                        r->z = ((value131 << 8) | value130) == 0;
                        r->n = ((value131 << 8) | value130) & 0x8000;
                        r->v = value129 & 0x40;
                        r->mf = value129 & 0x20;
                        r->xf = value129 & 0x10;
                        r->dp = (value131 << 8) | value130;
                        r->i = value129 & 0x04;
                        r->d = value129 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                }
            }
        }
    } else {
        RAM16_SET(0x0308, x_ret4);
        r->a = 1;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCDE0, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xCDE0); } /* allocate_transfer_descriptor */
        r->sp += 6;
        uint8_t db_ret22 = r->db;
        uint16_t x_ret57 = r->x;
        BUS16_SET(c, (db_ret22 << 0x10) + 2 + x_ret57, 0x4000);
        uint16_t value132 = BUS16_RDP(c, (db_ret22 << 0x10) + 0x0308);
        BUS16_SET(c, (db_ret22 << 0x10) + 0x0A + x_ret57, value132);
        BUS16_SET(c, (db_ret22 << 0x10) + 5 + x_ret57, 0x1000);
        BUS8_SET(c, (db_ret22 << 0x10) + 4 + x_ret57, 0x7E);
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCDFC, 0x7E90DA); GUARD_JSR(c, sp_call, 0xCDFC); } /* submit_transfer_or_program_hdma */
        r->sp += 6;
        uint16_t a_all36 = r->a;
        r->a = (a_all36 >> 8 << 8) | 0;
        r->z = 1;
        r->n = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCE01, 0x7EBBAB); GUARD_JSR(c, sp_call, 0xCE01); } /* allocate_palette_slot */
        r->sp += 6;
        uint8_t db_ret24 = r->db;
        uint16_t x_ret60 = r->x;
        BUS16_SET(c, (db_ret24 << 0x10) + 0x030A, x_ret60);
        r->a = 0x7E1D;
        r->y = 0x5120;
        r->z = 0;
        r->n = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCE0F, 0x7EBC9A); GUARD_JSR(c, sp_call, 0xCE0F); } /* copy_palette_colours */
        r->sp += 6;
        bool x_ret61 = r->xf;
        uint16_t y_ret38 = r->y;
        if (x_ret61) {
            uint8_t value133 = BUS8_RDP(c, (db_ret24 << 0x10) + 0x030A);
            r->x = value133;
            r->y = (uint8_t)y_ret38;
            r->z = value133 == 0;
            r->n = value133 & 0x80;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCE15, 0x7EBBFE); GUARD_JSR(c, sp_call, 0xCE15); } /* queue_palette_upload */
            r->sp += 6;
            uint8_t db_ret25 = r->db;
            uint16_t a_all39 = r->a;
            BUS8_SET(c, (db_ret25 << 0x10) + 0x0310, (uint8_t)((uint8_t)a_all39 << 2) | 0x20);
            r->a = (a_all39 >> 8 << 8) | 0x14;
            r->c = (uint8_t)((uint8_t)a_all39 << 1) & 0x80;
            r->z = 0;
            r->n = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCE21, 0x7EC76D); GUARD_JSR(c, sp_call, 0xCE21); } /* create_registered_vram_buffer */
            r->sp += 6;
            bool x_ret65 = r->xf;
            uint16_t x_ret66 = r->x;
            if (x_ret65) {
                BUS8_SET(c, (db_ret25 << 0x10) + 0x0306, (uint8_t)x_ret66);
                uint16_t value134 = BUS16_RDP(c, (db_ret25 << 0x10) + 0x0306);
                r->x = (uint8_t)(value134 + 0x0740);
                r->c = value134 + 0x0740 > 0xFFFF;
                r->z = (uint8_t)(value134 + 0x0740) == 0;
                r->n = (uint8_t)(value134 + 0x0740) & 0x80;
                r->v = ((value134 ^ (uint16_t)(value134 + 0x0740)) & ((uint16_t)(value134 + 0x0740) ^ 0x0740) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE31, 0x7E9716); GUARD_JSR(c, sp_call, 0xCE31); } /* copy_native_title_font_and_register_eight_upper_palette_slots */
                r->sp += 6;
                uint16_t a_all41 = r->a;
                r->a = (a_all41 >> 8 << 8) | 0x2C;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE38, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE38); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret26 = r->db;
                uint16_t x_ret70 = r->x;
                uint8_t value135 = BUS8_RDP(c, (db_ret26 << 0x10) + 2 + x_ret70);
                BUS8_SET(c, (db_ret26 << 0x10) + 2 + x_ret70, value135 | 2);
                r->z = (value135 | 2) == 0;
                r->n = (value135 | 2) & 0x80;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE43, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE43); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint16_t a_all43 = r->a;
                r->a = (a_all43 >> 8 << 8) | 5;
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE48, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE48); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret28 = r->db;
                uint16_t x_ret73 = r->x;
                BUS8_SET(c, (db_ret28 << 0x10) + 2 + x_ret73, 3);
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE50, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE50); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint8_t db_ret29 = r->db;
                uint16_t a_all45 = r->a;
                r->a = (a_all45 >> 8 << 8) | 0;
                r->x = 9;
                r->z = 1;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE58, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xCE58); } /* allocate_and_fill_bytes */
                r->sp += 6;
                bool m_ret16 = r->mf;
                bool x_ret74 = r->xf;
                uint16_t x_ret75 = r->x;
                uint16_t y_ret46 = r->y;
                if (x_ret74) {
                    BUS8_SET(c, (db_ret29 << 0x10) + 0x030C, (uint8_t)x_ret75);
                    if (m_ret16) {
                        uint8_t value139 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value140 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value141 = RAM8(0x0000 + sp0 - 3);
                        r->x = (uint8_t)x_ret75;
                        r->y = (uint8_t)y_ret46;
                        r->c = value139 & 0x01;
                        r->z = ((value141 << 8) | value140) == 0;
                        r->n = ((value141 << 8) | value140) & 0x8000;
                        r->v = value139 & 0x40;
                        r->mf = value139 & 0x20;
                        r->xf = value139 & 0x10;
                        r->dp = (value141 << 8) | value140;
                        r->i = value139 & 0x04;
                        r->d = value139 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value146 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value147 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value148 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value149 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value150 = RAM8(0x0000 + sp0);
                        r->a = (value147 << 8) | value146;
                        r->x = (uint8_t)x_ret75;
                        r->y = (uint8_t)y_ret46;
                        r->c = value148 & 0x01;
                        r->z = ((value150 << 8) | value149) == 0;
                        r->n = ((value150 << 8) | value149) & 0x8000;
                        r->v = value148 & 0x40;
                        r->mf = value148 & 0x20;
                        r->xf = value148 & 0x10;
                        r->dp = (value150 << 8) | value149;
                        r->i = value148 & 0x04;
                        r->d = value148 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                } else {
                    BUS16_SET(c, (db_ret29 << 0x10) + 0x030C, x_ret75);
                    if (m_ret16) {
                        uint8_t value154 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value155 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value156 = RAM8(0x0000 + sp0 - 3);
                        r->c = value154 & 0x01;
                        r->z = ((value156 << 8) | value155) == 0;
                        r->n = ((value156 << 8) | value155) & 0x8000;
                        r->v = value154 & 0x40;
                        r->mf = value154 & 0x20;
                        r->xf = value154 & 0x10;
                        r->dp = (value156 << 8) | value155;
                        r->i = value154 & 0x04;
                        r->d = value154 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value161 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value162 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value163 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value164 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value165 = RAM8(0x0000 + sp0);
                        r->a = (value162 << 8) | value161;
                        r->c = value163 & 0x01;
                        r->z = ((value165 << 8) | value164) == 0;
                        r->n = ((value165 << 8) | value164) & 0x8000;
                        r->v = value163 & 0x40;
                        r->mf = value163 & 0x20;
                        r->xf = value163 & 0x10;
                        r->dp = (value165 << 8) | value164;
                        r->i = value163 & 0x04;
                        r->d = value163 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                }
            } else {
                BUS16_SET(c, (db_ret25 << 0x10) + 0x0306, x_ret66);
                uint16_t value166 = BUS16_RDP(c, (db_ret25 << 0x10) + 0x0306);
                r->x = (uint16_t)(value166 + 0x0740);
                r->c = value166 + 0x0740 > 0xFFFF;
                r->z = (uint16_t)(value166 + 0x0740) == 0;
                r->n = (uint16_t)(value166 + 0x0740) & 0x8000;
                r->v = ((value166 ^ (uint16_t)(value166 + 0x0740)) & ((uint16_t)(value166 + 0x0740) ^ 0x0740) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE31, 0x7E9716); GUARD_JSR(c, sp_call, 0xCE31); } /* copy_native_title_font_and_register_eight_upper_palette_slots */
                r->sp += 6;
                uint16_t a_all47 = r->a;
                r->a = (a_all47 >> 8 << 8) | 0x2C;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE38, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE38); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret30 = r->db;
                uint16_t x_ret79 = r->x;
                uint8_t value167 = BUS8_RDP(c, (db_ret30 << 0x10) + 2 + x_ret79);
                BUS8_SET(c, (db_ret30 << 0x10) + 2 + x_ret79, value167 | 2);
                r->z = (value167 | 2) == 0;
                r->n = (value167 | 2) & 0x80;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE43, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE43); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint16_t a_all49 = r->a;
                r->a = (a_all49 >> 8 << 8) | 5;
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE48, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE48); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret32 = r->db;
                uint16_t x_ret82 = r->x;
                BUS8_SET(c, (db_ret32 << 0x10) + 2 + x_ret82, 3);
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE50, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE50); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint8_t db_ret33 = r->db;
                uint16_t a_all51 = r->a;
                r->a = (a_all51 >> 8 << 8) | 0;
                r->x = 9;
                r->z = 1;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE58, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xCE58); } /* allocate_and_fill_bytes */
                r->sp += 6;
                bool m_ret18 = r->mf;
                bool x_ret83 = r->xf;
                uint16_t x_ret84 = r->x;
                uint16_t y_ret52 = r->y;
                if (x_ret83) {
                    BUS8_SET(c, (db_ret33 << 0x10) + 0x030C, (uint8_t)x_ret84);
                    if (m_ret18) {
                        uint8_t value171 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value172 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value173 = RAM8(0x0000 + sp0 - 3);
                        r->x = (uint8_t)x_ret84;
                        r->y = (uint8_t)y_ret52;
                        r->c = value171 & 0x01;
                        r->z = ((value173 << 8) | value172) == 0;
                        r->n = ((value173 << 8) | value172) & 0x8000;
                        r->v = value171 & 0x40;
                        r->mf = value171 & 0x20;
                        r->xf = value171 & 0x10;
                        r->dp = (value173 << 8) | value172;
                        r->i = value171 & 0x04;
                        r->d = value171 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value178 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value179 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value180 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value181 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value182 = RAM8(0x0000 + sp0);
                        r->a = (value179 << 8) | value178;
                        r->x = (uint8_t)x_ret84;
                        r->y = (uint8_t)y_ret52;
                        r->c = value180 & 0x01;
                        r->z = ((value182 << 8) | value181) == 0;
                        r->n = ((value182 << 8) | value181) & 0x8000;
                        r->v = value180 & 0x40;
                        r->mf = value180 & 0x20;
                        r->xf = value180 & 0x10;
                        r->dp = (value182 << 8) | value181;
                        r->i = value180 & 0x04;
                        r->d = value180 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                } else {
                    BUS16_SET(c, (db_ret33 << 0x10) + 0x030C, x_ret84);
                    if (m_ret18) {
                        uint8_t value186 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value187 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value188 = RAM8(0x0000 + sp0 - 3);
                        r->c = value186 & 0x01;
                        r->z = ((value188 << 8) | value187) == 0;
                        r->n = ((value188 << 8) | value187) & 0x8000;
                        r->v = value186 & 0x40;
                        r->mf = value186 & 0x20;
                        r->xf = value186 & 0x10;
                        r->dp = (value188 << 8) | value187;
                        r->i = value186 & 0x04;
                        r->d = value186 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value193 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value194 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value195 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value196 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value197 = RAM8(0x0000 + sp0);
                        r->a = (value194 << 8) | value193;
                        r->c = value195 & 0x01;
                        r->z = ((value197 << 8) | value196) == 0;
                        r->n = ((value197 << 8) | value196) & 0x8000;
                        r->v = value195 & 0x40;
                        r->mf = value195 & 0x20;
                        r->xf = value195 & 0x10;
                        r->dp = (value197 << 8) | value196;
                        r->i = value195 & 0x04;
                        r->d = value195 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                }
            }
        } else {
            uint16_t value198 = BUS16_RDP(c, (db_ret24 << 0x10) + 0x030A);
            r->x = value198;
            r->z = value198 == 0;
            r->n = value198 & 0x8000;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCE15, 0x7EBBFE); GUARD_JSR(c, sp_call, 0xCE15); } /* queue_palette_upload */
            r->sp += 6;
            uint8_t db_ret34 = r->db;
            uint16_t a_all53 = r->a;
            BUS8_SET(c, (db_ret34 << 0x10) + 0x0310, (uint8_t)((uint8_t)a_all53 << 2) | 0x20);
            r->a = (a_all53 >> 8 << 8) | 0x14;
            r->c = (uint8_t)((uint8_t)a_all53 << 1) & 0x80;
            r->z = 0;
            r->n = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCE21, 0x7EC76D); GUARD_JSR(c, sp_call, 0xCE21); } /* create_registered_vram_buffer */
            r->sp += 6;
            bool x_ret87 = r->xf;
            uint16_t x_ret88 = r->x;
            if (x_ret87) {
                BUS8_SET(c, (db_ret34 << 0x10) + 0x0306, (uint8_t)x_ret88);
                uint16_t value199 = BUS16_RDP(c, (db_ret34 << 0x10) + 0x0306);
                r->x = (uint8_t)(value199 + 0x0740);
                r->c = value199 + 0x0740 > 0xFFFF;
                r->z = (uint8_t)(value199 + 0x0740) == 0;
                r->n = (uint8_t)(value199 + 0x0740) & 0x80;
                r->v = ((value199 ^ (uint16_t)(value199 + 0x0740)) & ((uint16_t)(value199 + 0x0740) ^ 0x0740) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE31, 0x7E9716); GUARD_JSR(c, sp_call, 0xCE31); } /* copy_native_title_font_and_register_eight_upper_palette_slots */
                r->sp += 6;
                uint16_t a_all55 = r->a;
                r->a = (a_all55 >> 8 << 8) | 0x2C;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE38, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE38); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret35 = r->db;
                uint16_t x_ret92 = r->x;
                uint8_t value200 = BUS8_RDP(c, (db_ret35 << 0x10) + 2 + x_ret92);
                BUS8_SET(c, (db_ret35 << 0x10) + 2 + x_ret92, value200 | 2);
                r->z = (value200 | 2) == 0;
                r->n = (value200 | 2) & 0x80;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE43, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE43); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint16_t a_all57 = r->a;
                r->a = (a_all57 >> 8 << 8) | 5;
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE48, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE48); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret37 = r->db;
                uint16_t x_ret95 = r->x;
                BUS8_SET(c, (db_ret37 << 0x10) + 2 + x_ret95, 3);
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE50, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE50); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint8_t db_ret38 = r->db;
                uint16_t a_all59 = r->a;
                r->a = (a_all59 >> 8 << 8) | 0;
                r->x = 9;
                r->z = 1;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE58, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xCE58); } /* allocate_and_fill_bytes */
                r->sp += 6;
                bool m_ret21 = r->mf;
                bool x_ret96 = r->xf;
                uint16_t x_ret97 = r->x;
                uint16_t y_ret60 = r->y;
                if (x_ret96) {
                    BUS8_SET(c, (db_ret38 << 0x10) + 0x030C, (uint8_t)x_ret97);
                    if (m_ret21) {
                        uint8_t value204 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value205 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value206 = RAM8(0x0000 + sp0 - 3);
                        r->x = (uint8_t)x_ret97;
                        r->y = (uint8_t)y_ret60;
                        r->c = value204 & 0x01;
                        r->z = ((value206 << 8) | value205) == 0;
                        r->n = ((value206 << 8) | value205) & 0x8000;
                        r->v = value204 & 0x40;
                        r->mf = value204 & 0x20;
                        r->xf = value204 & 0x10;
                        r->dp = (value206 << 8) | value205;
                        r->i = value204 & 0x04;
                        r->d = value204 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value211 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value212 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value213 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value214 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value215 = RAM8(0x0000 + sp0);
                        r->a = (value212 << 8) | value211;
                        r->x = (uint8_t)x_ret97;
                        r->y = (uint8_t)y_ret60;
                        r->c = value213 & 0x01;
                        r->z = ((value215 << 8) | value214) == 0;
                        r->n = ((value215 << 8) | value214) & 0x8000;
                        r->v = value213 & 0x40;
                        r->mf = value213 & 0x20;
                        r->xf = value213 & 0x10;
                        r->dp = (value215 << 8) | value214;
                        r->i = value213 & 0x04;
                        r->d = value213 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                } else {
                    BUS16_SET(c, (db_ret38 << 0x10) + 0x030C, x_ret97);
                    if (m_ret21) {
                        uint8_t value219 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value220 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value221 = RAM8(0x0000 + sp0 - 3);
                        r->c = value219 & 0x01;
                        r->z = ((value221 << 8) | value220) == 0;
                        r->n = ((value221 << 8) | value220) & 0x8000;
                        r->v = value219 & 0x40;
                        r->mf = value219 & 0x20;
                        r->xf = value219 & 0x10;
                        r->dp = (value221 << 8) | value220;
                        r->i = value219 & 0x04;
                        r->d = value219 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value226 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value227 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value228 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value229 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value230 = RAM8(0x0000 + sp0);
                        r->a = (value227 << 8) | value226;
                        r->c = value228 & 0x01;
                        r->z = ((value230 << 8) | value229) == 0;
                        r->n = ((value230 << 8) | value229) & 0x8000;
                        r->v = value228 & 0x40;
                        r->mf = value228 & 0x20;
                        r->xf = value228 & 0x10;
                        r->dp = (value230 << 8) | value229;
                        r->i = value228 & 0x04;
                        r->d = value228 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                }
            } else {
                BUS16_SET(c, (db_ret34 << 0x10) + 0x0306, x_ret88);
                uint16_t value231 = BUS16_RDP(c, (db_ret34 << 0x10) + 0x0306);
                r->x = (uint16_t)(value231 + 0x0740);
                r->c = value231 + 0x0740 > 0xFFFF;
                r->z = (uint16_t)(value231 + 0x0740) == 0;
                r->n = (uint16_t)(value231 + 0x0740) & 0x8000;
                r->v = ((value231 ^ (uint16_t)(value231 + 0x0740)) & ((uint16_t)(value231 + 0x0740) ^ 0x0740) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE31, 0x7E9716); GUARD_JSR(c, sp_call, 0xCE31); } /* copy_native_title_font_and_register_eight_upper_palette_slots */
                r->sp += 6;
                uint16_t a_all61 = r->a;
                r->a = (a_all61 >> 8 << 8) | 0x2C;
                r->z = 0;
                r->n = 0;
                r->mf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE38, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE38); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret39 = r->db;
                uint16_t x_ret101 = r->x;
                uint8_t value232 = BUS8_RDP(c, (db_ret39 << 0x10) + 2 + x_ret101);
                BUS8_SET(c, (db_ret39 << 0x10) + 2 + x_ret101, value232 | 2);
                r->z = (value232 | 2) == 0;
                r->n = (value232 | 2) & 0x80;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE43, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE43); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint16_t a_all63 = r->a;
                r->a = (a_all63 >> 8 << 8) | 5;
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE48, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE48); } /* allocate_ppu_register_entry */
                r->sp += 6;
                uint8_t db_ret41 = r->db;
                uint16_t x_ret104 = r->x;
                BUS8_SET(c, (db_ret41 << 0x10) + 2 + x_ret104, 3);
                r->z = 0;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE50, 0x7EC097); GUARD_JSR(c, sp_call, 0xCE50); } /* append_oneshot_ppu_entry */
                r->sp += 6;
                uint8_t db_ret42 = r->db;
                uint16_t a_all65 = r->a;
                r->a = (a_all65 >> 8 << 8) | 0;
                r->x = 9;
                r->z = 1;
                r->n = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xCE58, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xCE58); } /* allocate_and_fill_bytes */
                r->sp += 6;
                bool m_ret23 = r->mf;
                bool x_ret105 = r->xf;
                uint16_t x_ret106 = r->x;
                uint16_t y_ret66 = r->y;
                if (x_ret105) {
                    BUS8_SET(c, (db_ret42 << 0x10) + 0x030C, (uint8_t)x_ret106);
                    if (m_ret23) {
                        uint8_t value236 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value237 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value238 = RAM8(0x0000 + sp0 - 3);
                        r->x = (uint8_t)x_ret106;
                        r->y = (uint8_t)y_ret66;
                        r->c = value236 & 0x01;
                        r->z = ((value238 << 8) | value237) == 0;
                        r->n = ((value238 << 8) | value237) & 0x8000;
                        r->v = value236 & 0x40;
                        r->mf = value236 & 0x20;
                        r->xf = value236 & 0x10;
                        r->dp = (value238 << 8) | value237;
                        r->i = value236 & 0x04;
                        r->d = value236 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value243 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value244 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value245 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value246 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value247 = RAM8(0x0000 + sp0);
                        r->a = (value244 << 8) | value243;
                        r->x = (uint8_t)x_ret106;
                        r->y = (uint8_t)y_ret66;
                        r->c = value245 & 0x01;
                        r->z = ((value247 << 8) | value246) == 0;
                        r->n = ((value247 << 8) | value246) & 0x8000;
                        r->v = value245 & 0x40;
                        r->mf = value245 & 0x20;
                        r->xf = value245 & 0x10;
                        r->dp = (value247 << 8) | value246;
                        r->i = value245 & 0x04;
                        r->d = value245 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                } else {
                    BUS16_SET(c, (db_ret42 << 0x10) + 0x030C, x_ret106);
                    if (m_ret23) {
                        uint8_t value251 = RAM8(0x0000 + sp0 - 5);
                        uint8_t value252 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value253 = RAM8(0x0000 + sp0 - 3);
                        r->c = value251 & 0x01;
                        r->z = ((value253 << 8) | value252) == 0;
                        r->n = ((value253 << 8) | value252) & 0x8000;
                        r->v = value251 & 0x40;
                        r->mf = value251 & 0x20;
                        r->xf = value251 & 0x10;
                        r->dp = (value253 << 8) | value252;
                        r->i = value251 & 0x04;
                        r->d = value251 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        uint8_t value258 = RAM8(0x0000 + sp0 - 4);
                        uint8_t value259 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value260 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value261 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value262 = RAM8(0x0000 + sp0);
                        r->a = (value259 << 8) | value258;
                        r->c = value260 & 0x01;
                        r->z = ((value262 << 8) | value261) == 0;
                        r->n = ((value262 << 8) | value261) & 0x8000;
                        r->v = value260 & 0x40;
                        r->mf = value260 & 0x20;
                        r->xf = value260 & 0x10;
                        r->dp = (value262 << 8) | value261;
                        r->i = value260 & 0x04;
                        r->d = value260 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        r->sp += 3;
                        RETURN_RTS(c);
                    }
                }
            }
        }
    }
}
SOM_REGISTER(0x7ECDBF, SOM_RTS, "gen", construct_native_boot_title_graphics_palette_and_background_resources, SOM_UNWINDS, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 9, 1, 0, 163, 72)
