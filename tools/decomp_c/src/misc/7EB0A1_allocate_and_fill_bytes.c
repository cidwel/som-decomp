#include "som_c.h"

/* 7EB0A1 allocate_and_fill_bytes   [class B, 53 bytes, 34 instructions]
 * Source: src/boot/allocate_and_fill_bytes.s
 * Entry: M=any X=16 bit DB=$7F D=any.  Callers read: BXYCZNV.
 */
static void allocate_and_fill_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 8) + 0x5 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 8) = 0x7F;
    RAM8(0x0000 + sp0 - 9) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0A) = 0x7F;
    RAM8(0x0001 + (uint16_t)(sp0 - 8)) = (uint8_t)value;
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 8), x);
    r->a = value;
    r->c = (uint16_t)(sp0 - 5) >= 3;
    r->z = (uint8_t)value == 0;
    r->n = (uint8_t)value & 0x80;
    r->v = (((uint16_t)(sp0 - 5) ^ 3) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 8)) & 0x8000) != 0;
    r->mf = 1;
    r->dp = (uint16_t)(sp0 - 8);
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB0BE, 0x7EB081); GUARD_JSR(c, sp_call, 0xB0BE); } /* allocate_boot_heap_bytes_without_fill */
    r->sp += 9;
    uint16_t dp_ret = r->dp;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    if (x_ret) {
        BUS8_SET(c, (uint16_t)(dp_ret + 2), (uint8_t)x_ret2);
        if (m_ret) {
            uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 4));
            r->a = (a_all >> 8 << 8) | value2;
            r->x = (uint8_t)x_ret2;
            r->y = value3;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB0C7, 0x7EC37D); GUARD_JSR(c, sp_call, 0xB0C7); } /* fill_native_boot_memory_using_words_or_forward_copy */
            r->sp += 9;
            uint16_t dp_ret2 = r->dp;
            bool x_ret3 = r->xf;
            uint16_t y_ret2 = r->y;
            if (x_ret3) {
                uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 2));
                uint8_t value5 = RAM8(0x0000 + sp0 - 8);
                uint8_t value6 = RAM8(0x0000 + sp0 - 2);
                uint8_t value7 = RAM8(0x0000 + sp0 - 1);
                uint8_t value8 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
                r->x = value4;
                r->y = (uint8_t)y_ret2;
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
            } else {
                uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 2));
                uint8_t value10 = RAM8(0x0000 + sp0 - 8);
                uint8_t value11 = RAM8(0x0000 + sp0 - 2);
                uint8_t value12 = RAM8(0x0000 + sp0 - 1);
                uint8_t value13 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
                r->x = value9;
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
        } else {
            uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
            uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp_ret + 4));
            r->a = value14;
            r->x = (uint8_t)x_ret2;
            r->y = value15;
            r->z = value15 == 0;
            r->n = value15 & 0x80;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB0C7, 0x7EC37D); GUARD_JSR(c, sp_call, 0xB0C7); } /* fill_native_boot_memory_using_words_or_forward_copy */
            r->sp += 9;
            uint16_t dp_ret3 = r->dp;
            bool x_ret5 = r->xf;
            uint16_t y_ret3 = r->y;
            if (x_ret5) {
                uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 2));
                uint8_t value17 = RAM8(0x0000 + sp0 - 8);
                uint8_t value18 = RAM8(0x0000 + sp0 - 2);
                uint8_t value19 = RAM8(0x0000 + sp0 - 1);
                uint8_t value20 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
                r->x = value16;
                r->y = (uint8_t)y_ret3;
                r->c = value18 & 0x01;
                r->z = ((value20 << 8) | value19) == 0;
                r->n = ((value20 << 8) | value19) & 0x8000;
                r->v = value18 & 0x40;
                r->mf = value18 & 0x20;
                r->xf = value18 & 0x10;
                r->db = value17;
                r->dp = (value20 << 8) | value19;
                r->i = value18 & 0x04;
                r->d = value18 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value21 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 2));
                uint8_t value22 = RAM8(0x0000 + sp0 - 8);
                uint8_t value23 = RAM8(0x0000 + sp0 - 2);
                uint8_t value24 = RAM8(0x0000 + sp0 - 1);
                uint8_t value25 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
                r->x = value21;
                r->c = value23 & 0x01;
                r->z = ((value25 << 8) | value24) == 0;
                r->n = ((value25 << 8) | value24) & 0x8000;
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
        }
    } else {
        BUS16_SET(c, (uint16_t)(dp_ret + 2), x_ret2);
        if (m_ret) {
            uint8_t value26 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            uint16_t value27 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
            r->a = (a_all >> 8 << 8) | value26;
            r->y = value27;
            r->z = value27 == 0;
            r->n = value27 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB0C7, 0x7EC37D); GUARD_JSR(c, sp_call, 0xB0C7); } /* fill_native_boot_memory_using_words_or_forward_copy */
            r->sp += 9;
            uint16_t dp_ret4 = r->dp;
            bool x_ret7 = r->xf;
            uint16_t y_ret4 = r->y;
            if (x_ret7) {
                uint8_t value28 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 2));
                uint8_t value29 = RAM8(0x0000 + sp0 - 8);
                uint8_t value30 = RAM8(0x0000 + sp0 - 2);
                uint8_t value31 = RAM8(0x0000 + sp0 - 1);
                uint8_t value32 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
                r->x = value28;
                r->y = (uint8_t)y_ret4;
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
                RETURN_RTS(c);
            } else {
                uint16_t value33 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 2));
                uint8_t value34 = RAM8(0x0000 + sp0 - 8);
                uint8_t value35 = RAM8(0x0000 + sp0 - 2);
                uint8_t value36 = RAM8(0x0000 + sp0 - 1);
                uint8_t value37 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
                r->x = value33;
                r->c = value35 & 0x01;
                r->z = ((value37 << 8) | value36) == 0;
                r->n = ((value37 << 8) | value36) & 0x8000;
                r->v = value35 & 0x40;
                r->mf = value35 & 0x20;
                r->xf = value35 & 0x10;
                r->db = value34;
                r->dp = (value37 << 8) | value36;
                r->i = value35 & 0x04;
                r->d = value35 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
            uint16_t value39 = BUS16_RDP(c, (uint16_t)(dp_ret + 4));
            r->a = value38;
            r->y = value39;
            r->z = value39 == 0;
            r->n = value39 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB0C7, 0x7EC37D); GUARD_JSR(c, sp_call, 0xB0C7); } /* fill_native_boot_memory_using_words_or_forward_copy */
            r->sp += 9;
            uint16_t dp_ret5 = r->dp;
            bool x_ret9 = r->xf;
            uint16_t y_ret5 = r->y;
            if (x_ret9) {
                uint8_t value40 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 2));
                uint8_t value41 = RAM8(0x0000 + sp0 - 8);
                uint8_t value42 = RAM8(0x0000 + sp0 - 2);
                uint8_t value43 = RAM8(0x0000 + sp0 - 1);
                uint8_t value44 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
                r->x = value40;
                r->y = (uint8_t)y_ret5;
                r->c = value42 & 0x01;
                r->z = ((value44 << 8) | value43) == 0;
                r->n = ((value44 << 8) | value43) & 0x8000;
                r->v = value42 & 0x40;
                r->mf = value42 & 0x20;
                r->xf = value42 & 0x10;
                r->db = value41;
                r->dp = (value44 << 8) | value43;
                r->i = value42 & 0x04;
                r->d = value42 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value45 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 2));
                uint8_t value46 = RAM8(0x0000 + sp0 - 8);
                uint8_t value47 = RAM8(0x0000 + sp0 - 2);
                uint8_t value48 = RAM8(0x0000 + sp0 - 1);
                uint8_t value49 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
                r->x = value45;
                r->c = value47 & 0x01;
                r->z = ((value49 << 8) | value48) == 0;
                r->n = ((value49 << 8) | value48) & 0x8000;
                r->v = value47 & 0x40;
                r->mf = value47 & 0x20;
                r->xf = value47 & 0x10;
                r->db = value46;
                r->dp = (value49 << 8) | value48;
                r->i = value47 & 0x04;
                r->d = value47 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
}
SOM_REGISTER(0x7EB0A1, SOM_RTS, "gen", allocate_and_fill_bytes, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 11, -1, 0, 53, 34)
