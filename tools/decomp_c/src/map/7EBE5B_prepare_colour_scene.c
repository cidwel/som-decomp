#include "som_c.h"

/* 7EBE5B prepare_colour_scene   [class B, 130 bytes, 70 instructions]
 * Source: src/boot/prepare_colour_scene.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$05F1.  Callers read: BYCZNV.
 */
static void prepare_colour_scene(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x05F1) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0D) + 0xA > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xF1;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x0D) = 0x7F;
    RAM8(0x0000 + sp0 - 0x0E) = 0x7F;
    r->a = 0x43;
    r->x = 0x0180;
    r->c = (uint16_t)(sp0 - 3) >= 0x0A;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 0x0A) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0D)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x0D);
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBE77, 0x7E809B); GUARD_JSR(c, sp_call, 0xBE77); } /* create_graphics_buffer */
    r->sp += 14;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        RAM8(0x0005 + (uint16_t)(sp0 - 0x0D)) = (uint8_t)x_ret2;
        r->a = 0x10;
        r->x = (uint8_t)x_ret2;
        r->y = (uint8_t)y_ret;
        r->z = 0;
        r->n = 0;
        r->xf = 1;
        r->sp -= 14;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBE7F, 0x7EC76D); GUARD_JSR(c, sp_call, 0xBE7F); } /* create_registered_vram_buffer */
        r->sp += 14;
        bool x_ret3 = r->xf;
        uint16_t x_ret4 = r->x;
        if (x_ret3) {
            RAM8(0x102D4) = (uint8_t)x_ret4;
            RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0D), 0x0C);
            RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), 0);
            uint8_t a_hi1 = 0;
            uint8_t x1 = (uint8_t)((uint8_t)x_ret4 + 0x0600);
            do {
                RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0D), 0x10);
                RAM8(0x0009 + (uint16_t)(sp0 - 0x0D)) = (uint8_t)(x1 - 0x80);
                uint16_t value = RAM16(0x0007 + (uint16_t)(sp0 - 0x0D));
                uint8_t a1 = (uint8_t)value;
                uint8_t a_hi2 = value >> 8;
                uint8_t x2 = (uint8_t)(x1 - 0x80);
                do {
                    RAM16_SET(0x10000 + x2, (a_hi2 << 8) | a1);
                    RAM16_SET(0x10040 + x2, (uint16_t)(((a_hi2 << 8) | a1) + 1));
                    RAM16_SET(0x10042 + x2, (uint16_t)(((a_hi2 << 8) | a1) + 2));
                    RAM16_SET(0x10002 + x2, (uint16_t)(((a_hi2 << 8) | a1) + 3));
                    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0D), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 0x0D)) - 1));
                    uint8_t a1_next = (uint8_t)(((a_hi2 << 8) | a1) + 4);
                    uint8_t a_hi2_next = (uint16_t)(((a_hi2 << 8) | a1) + 4) >> 8;
                    uint8_t x2_next = (uint8_t)(x2 + 4);
                    a1 = a1_next;
                    a_hi2 = a_hi2_next;
                    x2 = x2_next;
                } while (RAM16(0x0001 + (uint16_t)(sp0 - 0x0D)) != 0);
                RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), (a_hi2 << 8) | a1);
                uint8_t value2 = RAM8(0x0009 + (uint16_t)(sp0 - 0x0D));
                RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0D), (uint16_t)(RAM16(0x0003 + (uint16_t)(sp0 - 0x0D)) - 1));
                a_hi1 = a_hi2;
                x1 = value2;
            } while (RAM16(0x0003 + (uint16_t)(sp0 - 0x0D)) != 0);
            uint16_t value3 = RAM16(0x102D4);
            r->x = (uint8_t)(value3 + 0x0600);
            r->c = value3 + 0x0600 > 0xFFFF;
            r->z = (uint8_t)(value3 + 0x0600) == 0;
            r->n = (uint8_t)(value3 + 0x0600) & 0x80;
            r->v = ((value3 ^ (uint16_t)(value3 + 0x0600)) & ((uint16_t)(value3 + 0x0600) ^ 0x0600) & 0x8000) != 0;
            r->xf = 1;
            r->sp -= 14;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBECC, 0x7E9763); GUARD_JSR(c, sp_call, 0xBECC); } /* copy_colour_scene_map_template */
            r->sp += 14;
            bool x_ret5 = r->xf;
            uint16_t y_ret3 = r->y;
            if (x_ret5) {
                uint8_t value4 = RAM8(0x102D4);
                r->x = value4;
                r->y = (uint8_t)y_ret3;
                r->z = value4 == 0;
                r->n = value4 & 0x80;
                r->xf = 1;
                r->sp -= 14;
                { const uint16_t sp_call = r->sp; JSR(c, 0xBED2, 0x7EC870); GUARD_JSR(c, sp_call, 0xBED2); } /* queue_registered_vram_buffer */
                r->sp += 14;
                bool m_ret2 = r->mf;
                uint8_t value5 = RAM8(0x0000 + sp0 - 0x0D);
                if (m_ret2) {
                    c->fail = 3; /* operand size does not fit the register width on this path */
                    return;
                } else {
                    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value8 = RAM8(0x0000 + sp0);
                    r->a = (uint16_t)((uint16_t)(sp0 - 0x0D) + 0x0A);
                    r->c = value6 & 0x01;
                    r->z = ((value8 << 8) | value7) == 0;
                    r->n = ((value8 << 8) | value7) & 0x8000;
                    r->v = value6 & 0x40;
                    r->mf = value6 & 0x20;
                    r->xf = value6 & 0x10;
                    r->db = value5;
                    r->dp = (value8 << 8) | value7;
                    r->i = value6 & 0x04;
                    r->d = value6 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            } else {
                uint16_t value9 = RAM16(0x102D4);
                r->x = value9;
                r->z = value9 == 0;
                r->n = value9 & 0x8000;
                r->xf = 0;
                r->sp -= 14;
                { const uint16_t sp_call = r->sp; JSR(c, 0xBED2, 0x7EC870); GUARD_JSR(c, sp_call, 0xBED2); } /* queue_registered_vram_buffer */
                r->sp += 14;
                bool m_ret3 = r->mf;
                uint8_t value10 = RAM8(0x0000 + sp0 - 0x0D);
                if (m_ret3) {
                    c->fail = 3; /* operand size does not fit the register width on this path */
                    return;
                } else {
                    uint8_t value11 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value12 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value13 = RAM8(0x0000 + sp0);
                    r->a = (uint16_t)((uint16_t)(sp0 - 0x0D) + 0x0A);
                    r->c = value11 & 0x01;
                    r->z = ((value13 << 8) | value12) == 0;
                    r->n = ((value13 << 8) | value12) & 0x8000;
                    r->v = value11 & 0x40;
                    r->mf = value11 & 0x20;
                    r->xf = value11 & 0x10;
                    r->db = value10;
                    r->dp = (value13 << 8) | value12;
                    r->i = value11 & 0x04;
                    r->d = value11 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
        } else {
            RAM16_SET(0x102D4, x_ret4);
            RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0D), 0x0C);
            RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), 0);
            uint8_t a_hi3 = 0;
            uint16_t x3 = (uint16_t)(x_ret4 + 0x0600);
            do {
                RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0D), 0x10);
                RAM16_SET(0x0009 + (uint16_t)(sp0 - 0x0D), (uint16_t)(x3 - 0x80));
                uint16_t value14 = RAM16(0x0007 + (uint16_t)(sp0 - 0x0D));
                uint8_t a2 = (uint8_t)value14;
                uint8_t a_hi4 = value14 >> 8;
                uint16_t x4 = (uint16_t)(x3 - 0x80);
                do {
                    BUS16_SET(c, 0x7F0000 + x4, (a_hi4 << 8) | a2);
                    BUS16_SET(c, 0x7F0040 + x4, (uint16_t)(((a_hi4 << 8) | a2) + 1));
                    BUS16_SET(c, 0x7F0042 + x4, (uint16_t)(((a_hi4 << 8) | a2) + 2));
                    BUS16_SET(c, 0x7F0002 + x4, (uint16_t)(((a_hi4 << 8) | a2) + 3));
                    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0D), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 0x0D)) - 1));
                    uint8_t a2_next = (uint8_t)(((a_hi4 << 8) | a2) + 4);
                    uint8_t a_hi4_next = (uint16_t)(((a_hi4 << 8) | a2) + 4) >> 8;
                    uint16_t x4_next = (uint16_t)(x4 + 4);
                    a2 = a2_next;
                    a_hi4 = a_hi4_next;
                    x4 = x4_next;
                } while (RAM16(0x0001 + (uint16_t)(sp0 - 0x0D)) != 0);
                RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), (a_hi4 << 8) | a2);
                uint16_t value15 = RAM16(0x0009 + (uint16_t)(sp0 - 0x0D));
                RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0D), (uint16_t)(RAM16(0x0003 + (uint16_t)(sp0 - 0x0D)) - 1));
                a_hi3 = a_hi4;
                x3 = value15;
            } while (RAM16(0x0003 + (uint16_t)(sp0 - 0x0D)) != 0);
            uint16_t value16 = RAM16(0x102D4);
            r->x = (uint16_t)(value16 + 0x0600);
            r->c = value16 + 0x0600 > 0xFFFF;
            r->z = (uint16_t)(value16 + 0x0600) == 0;
            r->n = (uint16_t)(value16 + 0x0600) & 0x8000;
            r->v = ((value16 ^ (uint16_t)(value16 + 0x0600)) & ((uint16_t)(value16 + 0x0600) ^ 0x0600) & 0x8000) != 0;
            r->xf = 0;
            r->sp -= 14;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBECC, 0x7E9763); GUARD_JSR(c, sp_call, 0xBECC); } /* copy_colour_scene_map_template */
            r->sp += 14;
            bool x_ret11 = r->xf;
            uint16_t y_ret6 = r->y;
            if (x_ret11) {
                uint8_t value17 = RAM8(0x102D4);
                r->x = value17;
                r->y = (uint8_t)y_ret6;
                r->z = value17 == 0;
                r->n = value17 & 0x80;
                r->xf = 1;
                r->sp -= 14;
                { const uint16_t sp_call = r->sp; JSR(c, 0xBED2, 0x7EC870); GUARD_JSR(c, sp_call, 0xBED2); } /* queue_registered_vram_buffer */
                r->sp += 14;
                bool m_ret5 = r->mf;
                uint8_t value18 = RAM8(0x0000 + sp0 - 0x0D);
                if (m_ret5) {
                    c->fail = 3; /* operand size does not fit the register width on this path */
                    return;
                } else {
                    uint8_t value19 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value20 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value21 = RAM8(0x0000 + sp0);
                    r->a = (uint16_t)((uint16_t)(sp0 - 0x0D) + 0x0A);
                    r->c = value19 & 0x01;
                    r->z = ((value21 << 8) | value20) == 0;
                    r->n = ((value21 << 8) | value20) & 0x8000;
                    r->v = value19 & 0x40;
                    r->mf = value19 & 0x20;
                    r->xf = value19 & 0x10;
                    r->db = value18;
                    r->dp = (value21 << 8) | value20;
                    r->i = value19 & 0x04;
                    r->d = value19 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            } else {
                uint16_t value22 = RAM16(0x102D4);
                r->x = value22;
                r->z = value22 == 0;
                r->n = value22 & 0x8000;
                r->xf = 0;
                r->sp -= 14;
                { const uint16_t sp_call = r->sp; JSR(c, 0xBED2, 0x7EC870); GUARD_JSR(c, sp_call, 0xBED2); } /* queue_registered_vram_buffer */
                r->sp += 14;
                bool m_ret6 = r->mf;
                uint8_t value23 = RAM8(0x0000 + sp0 - 0x0D);
                if (m_ret6) {
                    c->fail = 3; /* operand size does not fit the register width on this path */
                    return;
                } else {
                    uint8_t value24 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value25 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value26 = RAM8(0x0000 + sp0);
                    r->a = (uint16_t)((uint16_t)(sp0 - 0x0D) + 0x0A);
                    r->c = value24 & 0x01;
                    r->z = ((value26 << 8) | value25) == 0;
                    r->n = ((value26 << 8) | value25) & 0x8000;
                    r->v = value24 & 0x40;
                    r->mf = value24 & 0x20;
                    r->xf = value24 & 0x10;
                    r->db = value23;
                    r->dp = (value26 << 8) | value25;
                    r->i = value24 & 0x04;
                    r->d = value24 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
        }
    } else {
        RAM16_SET(0x0005 + (uint16_t)(sp0 - 0x0D), x_ret2);
        r->a = 0x10;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        r->sp -= 14;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBE7F, 0x7EC76D); GUARD_JSR(c, sp_call, 0xBE7F); } /* create_registered_vram_buffer */
        r->sp += 14;
        bool x_ret17 = r->xf;
        uint16_t x_ret18 = r->x;
        if (x_ret17) {
            RAM8(0x102D4) = (uint8_t)x_ret18;
            RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0D), 0x0C);
            RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), 0);
            uint8_t a_hi5 = 0;
            uint8_t x5 = (uint8_t)((uint8_t)x_ret18 + 0x0600);
            do {
                RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0D), 0x10);
                RAM8(0x0009 + (uint16_t)(sp0 - 0x0D)) = (uint8_t)(x5 - 0x80);
                uint16_t value27 = RAM16(0x0007 + (uint16_t)(sp0 - 0x0D));
                uint8_t a3 = (uint8_t)value27;
                uint8_t a_hi6 = value27 >> 8;
                uint8_t x6 = (uint8_t)(x5 - 0x80);
                do {
                    RAM16_SET(0x10000 + x6, (a_hi6 << 8) | a3);
                    RAM16_SET(0x10040 + x6, (uint16_t)(((a_hi6 << 8) | a3) + 1));
                    RAM16_SET(0x10042 + x6, (uint16_t)(((a_hi6 << 8) | a3) + 2));
                    RAM16_SET(0x10002 + x6, (uint16_t)(((a_hi6 << 8) | a3) + 3));
                    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0D), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 0x0D)) - 1));
                    uint8_t a3_next = (uint8_t)(((a_hi6 << 8) | a3) + 4);
                    uint8_t a_hi6_next = (uint16_t)(((a_hi6 << 8) | a3) + 4) >> 8;
                    uint8_t x6_next = (uint8_t)(x6 + 4);
                    a3 = a3_next;
                    a_hi6 = a_hi6_next;
                    x6 = x6_next;
                } while (RAM16(0x0001 + (uint16_t)(sp0 - 0x0D)) != 0);
                RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), (a_hi6 << 8) | a3);
                uint8_t value28 = RAM8(0x0009 + (uint16_t)(sp0 - 0x0D));
                RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0D), (uint16_t)(RAM16(0x0003 + (uint16_t)(sp0 - 0x0D)) - 1));
                a_hi5 = a_hi6;
                x5 = value28;
            } while (RAM16(0x0003 + (uint16_t)(sp0 - 0x0D)) != 0);
            uint16_t value29 = RAM16(0x102D4);
            r->x = (uint8_t)(value29 + 0x0600);
            r->c = value29 + 0x0600 > 0xFFFF;
            r->z = (uint8_t)(value29 + 0x0600) == 0;
            r->n = (uint8_t)(value29 + 0x0600) & 0x80;
            r->v = ((value29 ^ (uint16_t)(value29 + 0x0600)) & ((uint16_t)(value29 + 0x0600) ^ 0x0600) & 0x8000) != 0;
            r->xf = 1;
            r->sp -= 14;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBECC, 0x7E9763); GUARD_JSR(c, sp_call, 0xBECC); } /* copy_colour_scene_map_template */
            r->sp += 14;
            bool x_ret19 = r->xf;
            uint16_t y_ret10 = r->y;
            if (x_ret19) {
                uint8_t value30 = RAM8(0x102D4);
                r->x = value30;
                r->y = (uint8_t)y_ret10;
                r->z = value30 == 0;
                r->n = value30 & 0x80;
                r->xf = 1;
                r->sp -= 14;
                { const uint16_t sp_call = r->sp; JSR(c, 0xBED2, 0x7EC870); GUARD_JSR(c, sp_call, 0xBED2); } /* queue_registered_vram_buffer */
                r->sp += 14;
                bool m_ret8 = r->mf;
                uint8_t value31 = RAM8(0x0000 + sp0 - 0x0D);
                if (m_ret8) {
                    c->fail = 3; /* operand size does not fit the register width on this path */
                    return;
                } else {
                    uint8_t value32 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value33 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value34 = RAM8(0x0000 + sp0);
                    r->a = (uint16_t)((uint16_t)(sp0 - 0x0D) + 0x0A);
                    r->c = value32 & 0x01;
                    r->z = ((value34 << 8) | value33) == 0;
                    r->n = ((value34 << 8) | value33) & 0x8000;
                    r->v = value32 & 0x40;
                    r->mf = value32 & 0x20;
                    r->xf = value32 & 0x10;
                    r->db = value31;
                    r->dp = (value34 << 8) | value33;
                    r->i = value32 & 0x04;
                    r->d = value32 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            } else {
                uint16_t value35 = RAM16(0x102D4);
                r->x = value35;
                r->z = value35 == 0;
                r->n = value35 & 0x8000;
                r->xf = 0;
                r->sp -= 14;
                { const uint16_t sp_call = r->sp; JSR(c, 0xBED2, 0x7EC870); GUARD_JSR(c, sp_call, 0xBED2); } /* queue_registered_vram_buffer */
                r->sp += 14;
                bool m_ret9 = r->mf;
                uint8_t value36 = RAM8(0x0000 + sp0 - 0x0D);
                if (m_ret9) {
                    c->fail = 3; /* operand size does not fit the register width on this path */
                    return;
                } else {
                    uint8_t value37 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value38 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value39 = RAM8(0x0000 + sp0);
                    r->a = (uint16_t)((uint16_t)(sp0 - 0x0D) + 0x0A);
                    r->c = value37 & 0x01;
                    r->z = ((value39 << 8) | value38) == 0;
                    r->n = ((value39 << 8) | value38) & 0x8000;
                    r->v = value37 & 0x40;
                    r->mf = value37 & 0x20;
                    r->xf = value37 & 0x10;
                    r->db = value36;
                    r->dp = (value39 << 8) | value38;
                    r->i = value37 & 0x04;
                    r->d = value37 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
        } else {
            RAM16_SET(0x102D4, x_ret18);
            RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0D), 0x0C);
            RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), 0);
            uint8_t a_hi7 = 0;
            uint16_t x7 = (uint16_t)(x_ret18 + 0x0600);
            do {
                RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0D), 0x10);
                RAM16_SET(0x0009 + (uint16_t)(sp0 - 0x0D), (uint16_t)(x7 - 0x80));
                uint16_t value40 = RAM16(0x0007 + (uint16_t)(sp0 - 0x0D));
                uint8_t a4 = (uint8_t)value40;
                uint8_t a_hi8 = value40 >> 8;
                uint16_t x8 = (uint16_t)(x7 - 0x80);
                do {
                    BUS16_SET(c, 0x7F0000 + x8, (a_hi8 << 8) | a4);
                    BUS16_SET(c, 0x7F0040 + x8, (uint16_t)(((a_hi8 << 8) | a4) + 1));
                    BUS16_SET(c, 0x7F0042 + x8, (uint16_t)(((a_hi8 << 8) | a4) + 2));
                    BUS16_SET(c, 0x7F0002 + x8, (uint16_t)(((a_hi8 << 8) | a4) + 3));
                    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0D), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 0x0D)) - 1));
                    uint8_t a4_next = (uint8_t)(((a_hi8 << 8) | a4) + 4);
                    uint8_t a_hi8_next = (uint16_t)(((a_hi8 << 8) | a4) + 4) >> 8;
                    uint16_t x8_next = (uint16_t)(x8 + 4);
                    a4 = a4_next;
                    a_hi8 = a_hi8_next;
                    x8 = x8_next;
                } while (RAM16(0x0001 + (uint16_t)(sp0 - 0x0D)) != 0);
                RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), (a_hi8 << 8) | a4);
                uint16_t value41 = RAM16(0x0009 + (uint16_t)(sp0 - 0x0D));
                RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0D), (uint16_t)(RAM16(0x0003 + (uint16_t)(sp0 - 0x0D)) - 1));
                a_hi7 = a_hi8;
                x7 = value41;
            } while (RAM16(0x0003 + (uint16_t)(sp0 - 0x0D)) != 0);
            uint16_t value42 = RAM16(0x102D4);
            r->x = (uint16_t)(value42 + 0x0600);
            r->c = value42 + 0x0600 > 0xFFFF;
            r->z = (uint16_t)(value42 + 0x0600) == 0;
            r->n = (uint16_t)(value42 + 0x0600) & 0x8000;
            r->v = ((value42 ^ (uint16_t)(value42 + 0x0600)) & ((uint16_t)(value42 + 0x0600) ^ 0x0600) & 0x8000) != 0;
            r->xf = 0;
            r->sp -= 14;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBECC, 0x7E9763); GUARD_JSR(c, sp_call, 0xBECC); } /* copy_colour_scene_map_template */
            r->sp += 14;
            bool x_ret25 = r->xf;
            uint16_t y_ret13 = r->y;
            if (x_ret25) {
                uint8_t value43 = RAM8(0x102D4);
                r->x = value43;
                r->y = (uint8_t)y_ret13;
                r->z = value43 == 0;
                r->n = value43 & 0x80;
                r->xf = 1;
                r->sp -= 14;
                { const uint16_t sp_call = r->sp; JSR(c, 0xBED2, 0x7EC870); GUARD_JSR(c, sp_call, 0xBED2); } /* queue_registered_vram_buffer */
                r->sp += 14;
                bool m_ret11 = r->mf;
                uint8_t value44 = RAM8(0x0000 + sp0 - 0x0D);
                if (m_ret11) {
                    c->fail = 3; /* operand size does not fit the register width on this path */
                    return;
                } else {
                    uint8_t value45 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value46 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value47 = RAM8(0x0000 + sp0);
                    r->a = (uint16_t)((uint16_t)(sp0 - 0x0D) + 0x0A);
                    r->c = value45 & 0x01;
                    r->z = ((value47 << 8) | value46) == 0;
                    r->n = ((value47 << 8) | value46) & 0x8000;
                    r->v = value45 & 0x40;
                    r->mf = value45 & 0x20;
                    r->xf = value45 & 0x10;
                    r->db = value44;
                    r->dp = (value47 << 8) | value46;
                    r->i = value45 & 0x04;
                    r->d = value45 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            } else {
                uint16_t value48 = RAM16(0x102D4);
                r->x = value48;
                r->z = value48 == 0;
                r->n = value48 & 0x8000;
                r->xf = 0;
                r->sp -= 14;
                { const uint16_t sp_call = r->sp; JSR(c, 0xBED2, 0x7EC870); GUARD_JSR(c, sp_call, 0xBED2); } /* queue_registered_vram_buffer */
                r->sp += 14;
                bool m_ret12 = r->mf;
                uint8_t value49 = RAM8(0x0000 + sp0 - 0x0D);
                if (m_ret12) {
                    c->fail = 3; /* operand size does not fit the register width on this path */
                    return;
                } else {
                    uint8_t value50 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value51 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value52 = RAM8(0x0000 + sp0);
                    r->a = (uint16_t)((uint16_t)(sp0 - 0x0D) + 0x0A);
                    r->c = value50 & 0x01;
                    r->z = ((value52 << 8) | value51) == 0;
                    r->n = ((value52 << 8) | value51) & 0x8000;
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
        }
    }
}
SOM_REGISTER(0x7EBE5B, SOM_RTS, "gen", prepare_colour_scene, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 15, 1, 0, 130, 70)
