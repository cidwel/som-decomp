#include "som_c.h"

/* 7ECA65 construct_second_warm_scene_background_resources   [class B, 147 bytes, 71 instructions]
 * Source: src/boot/construct_second_warm_scene_background_resources.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void construct_second_warm_scene_background_resources(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 0x0D) + 0x8 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->a = 0x42;
    r->x = 0x11;
    r->c = (uint16_t)(sp0 - 3) >= 0x0A;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 0x0A) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0D)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x0D);
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCA78, 0x7E809B); GUARD_JSR(c, sp_call, 0xCA78); } /* create_graphics_buffer */
    r->sp += 13;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        RAM8(0x0007 + (uint16_t)(sp0 - 0x0D)) = (uint8_t)x_ret2;
        r->a = 1;
        r->x = (uint8_t)x_ret2;
        r->y = (uint8_t)y_ret;
        r->z = 0;
        r->n = 0;
        r->xf = 1;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCA80, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xCA80); } /* allocate_transfer_descriptor */
        r->sp += 13;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t x_ret4 = r->x;
        uint16_t value = BUS16_RDP(c, (uint16_t)(dp_ret + 7));
        BUS16_SET(c, (db_ret << 0x10) + 0x0A + x_ret4, value);
        BUS16_SET(c, (db_ret << 0x10) + 2 + x_ret4, 0x57C0);
        BUS16_SET(c, (db_ret << 0x10) + 5 + x_ret4, 0x0220);
        BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret4, 0x7E);
        r->a = 0x027E;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCA9B, 0x7E90DA); GUARD_JSR(c, sp_call, 0xCA9B); } /* submit_transfer_or_program_hdma */
        r->sp += 13;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all3 = r->a;
        r->a = (a_all3 >> 8 << 8) | 0;
        r->z = 1;
        r->n = 0;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCAA0, 0x7EBBAB); GUARD_JSR(c, sp_call, 0xCAA0); } /* allocate_palette_slot */
        r->sp += 13;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret7 = r->x;
        RAM8(0x0000 + sp0 - 0x0D) = x_ret7 >> 8;
        RAM8(0x0000 + sp0 - 0x0E) = (uint8_t)x_ret7;
        r->a = 0x7E1E;
        r->y = 0x51A0;
        r->z = 0;
        r->n = 0;
        r->sp -= 15;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCAAC, 0x7EBC9A); GUARD_JSR(c, sp_call, 0xCAAC); } /* copy_palette_colours */
        r->sp += 15;
        bool x_ret8 = r->xf;
        if (x_ret8) {
            c->fail = 3;
            return;
        } else {
            uint8_t value12 = RAM8(0x0000 + sp0 - 0x0E);
            uint8_t value13 = RAM8(0x0000 + sp0 - 0x0D);
            r->x = (value13 << 8) | value12;
            r->z = ((value13 << 8) | value12) == 0;
            r->n = ((value13 << 8) | value12) & 0x8000;
            r->xf = 0;
            r->sp -= 13;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCAB0, 0x7EBBFE); GUARD_JSR(c, sp_call, 0xCAB0); } /* queue_palette_upload */
            r->sp += 13;
            uint16_t dp_ret5 = r->dp;
            uint8_t db_ret5 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t a_all9 = r->a;
            BUS8_SET(c, (uint16_t)(dp_ret5 + 6), (uint8_t)((uint8_t)a_all9 << 2) | 0x20);
            r->a = 0x10;
            r->c = (uint8_t)((uint8_t)a_all9 << 1) & 0x80;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->sp -= 13;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCABE, 0x7EC76D); GUARD_JSR(c, sp_call, 0xCABE); } /* create_registered_vram_buffer */
            r->sp += 13;
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all10 = r->a;
            uint16_t x_ret17 = r->x;
            bool carry_ret10 = r->c;
            bool overflow_ret10 = r->v;
            BUS16_SET(c, (uint16_t)(dp_ret5 + 3), x_ret17);
            BUS8_SET(c, (uint16_t)(dp_ret5 + 1), 0x1D);
            uint8_t a_hi3 = a_all10 >> 8;
            uint16_t x3 = 0;
            uint16_t y3 = x_ret17;
            for (;;) {
                BUS8_SET(c, (uint16_t)(dp_ret5 + 9), 0x20);
                uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 5));
                uint8_t a_hi4 = a_hi3;
                uint16_t x4 = x3;
                uint16_t y4 = y3;
                for (;;) {
                    BUS8_SET(c, (db_ret5 << 0x10) + y4, RAM8(0x60C8 + x4));
                    uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 6));
                    BUS8_SET(c, (db_ret5 << 0x10) + (uint16_t)(y4 + 1), value16);
                    uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 9));
                    BUS8_SET(c, (uint16_t)(dp_ret5 + 9), (uint8_t)(value17 - 1));
                    x4 = (uint16_t)(x4 + 1);
                    y4 = (uint16_t)(y4 + 2);
                    if (!((uint8_t)(value17 - 1) != 0)) break;
                }
                uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret5 + 1), (uint8_t)(value18 - 1));
                a_hi3 = a_hi4;
                x3 = x4;
                y3 = y4;
                if (!((uint8_t)(value18 - 1) != 0)) break;
            }
            uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 3));
            r->x = value19;
            r->y = y3;
            r->c = carry_ret10;
            r->z = value19 == 0;
            r->n = value19 & 0x8000;
            r->v = overflow_ret10;
            r->mf = 1;
            r->sp -= 13;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCAEC, 0x7EC870); GUARD_JSR(c, sp_call, 0xCAEC); } /* queue_registered_vram_buffer */
            r->sp += 13;
            uint8_t value20 = RAM8(0x0000 + sp0 - 2);
            uint8_t value21 = RAM8(0x0000 + sp0 - 1);
            uint8_t value22 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((uint16_t)(sp0 - 0x0D) + 0x0A);
            r->c = value20 & 0x01;
            r->v = value20 & 0x40;
            r->mf = value20 & 0x20;
            r->xf = value20 & 0x10;
            r->dp = (value22 << 8) | value21;
            r->i = value20 & 0x04;
            r->d = value20 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), x_ret2);
        r->a = 1;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCA80, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xCA80); } /* allocate_transfer_descriptor */
        r->sp += 13;
        uint16_t dp_ret6 = r->dp;
        uint8_t db_ret6 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t x_ret21 = r->x;
        uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 7));
        BUS16_SET(c, (db_ret6 << 0x10) + 0x0A + x_ret21, value23);
        BUS16_SET(c, (db_ret6 << 0x10) + 2 + x_ret21, 0x57C0);
        BUS16_SET(c, (db_ret6 << 0x10) + 5 + x_ret21, 0x0220);
        BUS8_SET(c, (db_ret6 << 0x10) + 4 + x_ret21, 0x7E);
        r->a = 0x027E;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCA9B, 0x7E90DA); GUARD_JSR(c, sp_call, 0xCA9B); } /* submit_transfer_or_program_hdma */
        r->sp += 13;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all13 = r->a;
        r->a = (a_all13 >> 8 << 8) | 0;
        r->z = 1;
        r->n = 0;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCAA0, 0x7EBBAB); GUARD_JSR(c, sp_call, 0xCAA0); } /* allocate_palette_slot */
        r->sp += 13;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret24 = r->x;
        RAM8(0x0000 + sp0 - 0x0D) = x_ret24 >> 8;
        RAM8(0x0000 + sp0 - 0x0E) = (uint8_t)x_ret24;
        r->a = 0x7E1E;
        r->y = 0x51A0;
        r->z = 0;
        r->n = 0;
        r->sp -= 15;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCAAC, 0x7EBC9A); GUARD_JSR(c, sp_call, 0xCAAC); } /* copy_palette_colours */
        r->sp += 15;
        bool x_ret25 = r->xf;
        if (x_ret25) {
            c->fail = 3;
            return;
        } else {
            uint8_t value34 = RAM8(0x0000 + sp0 - 0x0E);
            uint8_t value35 = RAM8(0x0000 + sp0 - 0x0D);
            r->x = (value35 << 8) | value34;
            r->z = ((value35 << 8) | value34) == 0;
            r->n = ((value35 << 8) | value34) & 0x8000;
            r->xf = 0;
            r->sp -= 13;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCAB0, 0x7EBBFE); GUARD_JSR(c, sp_call, 0xCAB0); } /* queue_palette_upload */
            r->sp += 13;
            uint16_t dp_ret10 = r->dp;
            uint8_t db_ret10 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t a_all19 = r->a;
            BUS8_SET(c, (uint16_t)(dp_ret10 + 6), (uint8_t)((uint8_t)a_all19 << 2) | 0x20);
            r->a = 0x10;
            r->c = (uint8_t)((uint8_t)a_all19 << 1) & 0x80;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->sp -= 13;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCABE, 0x7EC76D); GUARD_JSR(c, sp_call, 0xCABE); } /* create_registered_vram_buffer */
            r->sp += 13;
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all20 = r->a;
            uint16_t x_ret34 = r->x;
            bool carry_ret20 = r->c;
            bool overflow_ret20 = r->v;
            BUS16_SET(c, (uint16_t)(dp_ret10 + 3), x_ret34);
            BUS8_SET(c, (uint16_t)(dp_ret10 + 1), 0x1D);
            uint8_t a_hi7 = a_all20 >> 8;
            uint16_t x7 = 0;
            uint16_t y7 = x_ret34;
            for (;;) {
                BUS8_SET(c, (uint16_t)(dp_ret10 + 9), 0x20);
                uint8_t value36 = BUS8_RDP(c, (uint16_t)(dp_ret10 + 5));
                uint8_t a_hi8 = a_hi7;
                uint16_t x8 = x7;
                uint16_t y8 = y7;
                for (;;) {
                    BUS8_SET(c, (db_ret10 << 0x10) + y8, RAM8(0x60C8 + x8));
                    uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp_ret10 + 6));
                    BUS8_SET(c, (db_ret10 << 0x10) + (uint16_t)(y8 + 1), value38);
                    uint8_t value39 = BUS8_RDP(c, (uint16_t)(dp_ret10 + 9));
                    BUS8_SET(c, (uint16_t)(dp_ret10 + 9), (uint8_t)(value39 - 1));
                    x8 = (uint16_t)(x8 + 1);
                    y8 = (uint16_t)(y8 + 2);
                    if (!((uint8_t)(value39 - 1) != 0)) break;
                }
                uint8_t value40 = BUS8_RDP(c, (uint16_t)(dp_ret10 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret10 + 1), (uint8_t)(value40 - 1));
                a_hi7 = a_hi8;
                x7 = x8;
                y7 = y8;
                if (!((uint8_t)(value40 - 1) != 0)) break;
            }
            uint16_t value41 = BUS16_RDP(c, (uint16_t)(dp_ret10 + 3));
            r->x = value41;
            r->y = y7;
            r->c = carry_ret20;
            r->z = value41 == 0;
            r->n = value41 & 0x8000;
            r->v = overflow_ret20;
            r->mf = 1;
            r->sp -= 13;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCAEC, 0x7EC870); GUARD_JSR(c, sp_call, 0xCAEC); } /* queue_registered_vram_buffer */
            r->sp += 13;
            uint8_t value42 = RAM8(0x0000 + sp0 - 2);
            uint8_t value43 = RAM8(0x0000 + sp0 - 1);
            uint8_t value44 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((uint16_t)(sp0 - 0x0D) + 0x0A);
            r->c = value42 & 0x01;
            r->v = value42 & 0x40;
            r->mf = value42 & 0x20;
            r->xf = value42 & 0x10;
            r->dp = (value44 << 8) | value43;
            r->i = value42 & 0x04;
            r->d = value42 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0x7ECA65, SOM_RTS, "gen", construct_second_warm_scene_background_resources, 0, L_B | L_X | L_Y | L_C | L_V, 15, 1, 0, 147, 71)
