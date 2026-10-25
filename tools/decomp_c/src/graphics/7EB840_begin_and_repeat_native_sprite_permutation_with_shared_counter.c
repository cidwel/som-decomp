#include "som_c.h"

/* 7EB840 begin_and_repeat_native_sprite_permutation_with_shared_counter   [class C, 143 bytes, 81 instructions]
 * Source: src/boot/begin_and_repeat_native_sprite_permutation_with_shared_counter.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Returns after the release only when the release leaves M=16 (the heap release restores the caller P).
 */
/* B8C6..B8CF for M=16 after the heap release: TSC / CLC / ADC #$0008 / TCS / PLP / PLD / RTS.  With M=8 the same bytes decode as ADC #$08 / BRK $1B. */
static void sprite_permutation_m16_epilogue(SomCtx *c, uint16_t sp0)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    r->a = (uint16_t)(sp0 - 0x0B + 8);
    const uint8_t p = RAM8(0x0000 + sp0 - 2);
    const uint8_t lo = RAM8(0x0000 + sp0 - 1);
    const uint8_t hi = RAM8(0x0000 + sp0);
    r->c = p & 0x01;
    r->v = p & 0x40;
    r->mf = p & 0x20;
    r->xf = p & 0x10;
    r->i = p & 0x04;
    r->d = p & 0x08;
    r->dp = (hi << 8) | lo;
    r->z = ((hi << 8) | lo) == 0;
    r->n = ((hi << 8) | lo) & 0x8000;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    r->sp = sp0;
    i_rts(c);
}

static void begin_and_repeat_native_sprite_permutation_with_shared_counter(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->d) { c->fail = 3; return; } /* binary ADC/SBC: entered with the decimal flag clear */
    const uint16_t sp0 = r->sp;
    uint64_t loop_guard = 0;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->a = (uint16_t)(sp0 - 0x0B);
    r->x = 0x0220;
    r->c = (uint16_t)(sp0 - 3) >= 8;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 8) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0B)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 0x0B);
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB852, 0x7EB081); GUARD_JSR(c, sp_call, 0xB852); } /* allocate_boot_heap_bytes_without_fill */
    r->sp += 11;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t x_ret = r->x;
    if (x_ret == 0) {
        if (som_exit_arrive(c, 0x7EB8C6)) {
            r->c = x_ret >= 0;
            r->z = x_ret == 0;
            r->n = x_ret & 0x8000;
            r->sp -= 11;
            c->cpu.k = 0x7E; c->cpu.pc = 0xB8C6; c->exited = 1;
            return;
        }
        if (m_ret) {
            if (som_exit_arrive(c, 0x7EB8CA)) {
                r->a = ((uint16_t)(sp0 - 0x0B) >> 8 << 8) | (uint8_t)((uint8_t)(sp0 - 0x0B) + 8);
                r->c = (uint8_t)(sp0 - 0x0B) + 8 > 0xFF;
                r->z = (uint8_t)((uint8_t)(sp0 - 0x0B) + 8) == 0;
                r->n = (uint8_t)((uint8_t)(sp0 - 0x0B) + 8) & 0x80;
                r->v = (((uint8_t)(sp0 - 0x0B) ^ (uint8_t)((uint8_t)(sp0 - 0x0B) + 8)) & ((uint8_t)((uint8_t)(sp0 - 0x0B) + 8) ^ 8) & 0x80) != 0;
                r->mf = 1;
                r->sp -= 11;
                c->cpu.k = 0x7E; c->cpu.pc = 0xB8CA; c->exited = 1;
                return;
            }
            c->fail = 1; /* BRK: software interrupt, outside the contract (the oracle stops here as well) */
            return;
        } else {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        }
    }
    BUS16_SET(c, (uint16_t)(dp_ret + 5), x_ret);
    uint16_t value = BUS16_RDP(c, (db_ret << 0x10) + 0x02CC);
    r->a = 0x0220;
    r->x = value;
    r->y = x_ret;
    r->c = x_ret >= 0;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB865, 0x7EC3BF); GUARD_JSR(c, sp_call, 0xB865); } /* copy_native_same_bank_memory_through_stack_generated_mvn */
    r->sp += 11;
    uint16_t dp_ret2 = r->dp;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret2 = r->xf;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    if (x_ret2) {
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0x02CA);
        BUS16_SET(c, (uint16_t)(dp_ret2 + 1), 0x20);
        uint16_t a_b86e = 0x0020;
        uint8_t x1 = value2;
        uint8_t y1 = (uint8_t)y_ret2;
        bool carry1 = carry_ret2;
        bool overflow1 = overflow_ret2;
        for (;;) {
            LOOP_GUARD(loop_guard);
            if (som_exit_arrive(c, 0x7EB86E)) {
                r->a = a_b86e;
                r->x = x1;
                r->y = y1;
                r->c = carry1;
                r->v = overflow1;
                r->xf = 1;
                r->sp -= 11;
                c->cpu.k = 0x7E; c->cpu.pc = 0xB86E; c->exited = 1;
                return;
            }
            RAM8(0x0000 + sp0 - 0x0B) = x1;
            uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + x1);
            uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0x0A + value3);
            RAM8(0x0000 + sp0 - 0x0C) = 0;
            RAM8(0x0000 + sp0 - 0x0D) = value4 & 0x7F;
            uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
            uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 9 + x1);
            RAM8(0x0000 + sp0 - 0x0E) = value6 >> 8;
            RAM8(0x0000 + sp0 - 0x0F) = (uint8_t)value6;
            uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0x02CC);
            BUS16_SET(c, (uint16_t)(dp_ret2 + 3), 8);
            uint16_t a_b893 = 8;
            uint8_t x2 = (uint8_t)((uint16_t)(value6 << 4) + value7);
            uint8_t y2 = (uint8_t)(((value4 & 0x7F) << 1 << 1 << 1 << 1) + value5);
            for (;;) {
                LOOP_GUARD(loop_guard);
                if (som_exit_arrive(c, 0x7EB893)) {
                    r->a = a_b893;
                    r->x = x2;
                    r->y = y2;
                    r->c = (uint16_t)(value6 << 4) + value7 > 0xFFFF;
                    r->v = (((uint16_t)(value6 << 4) ^ (uint16_t)((uint16_t)(value6 << 4) + value7)) & (value7 ^ (uint16_t)((uint16_t)(value6 << 4) + value7)) & 0x8000) != 0;
                    r->xf = 1;
                    r->sp -= 16;
                    c->cpu.k = 0x7E; c->cpu.pc = 0xB893; c->exited = 1;
                    return;
                }
                uint16_t value8 = BUS16_RDP(c, (db_ret << 0x10) + y2);
                BUS16_SET(c, (db_ret << 0x10) + x2, value8);
                uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value9 - 1));
                a_b893 = value8;
                x2 = (uint8_t)(x2 + 2);
                y2 = (uint8_t)(y2 + 2);
                if (!((uint16_t)(value9 - 1) != 0)) break;
            }
            uint8_t value10 = RAM8(0x0000 + sp0 - 0x0F);
            uint8_t value11 = RAM8(0x0000 + sp0 - 0x0E);
            uint16_t value12 = BUS16_RDP(c, (db_ret << 0x10) + 0x02CC);
            uint8_t value13 = RAM8(0x0000 + sp0 - 0x0D);
            uint8_t value14 = RAM8(0x0000 + sp0 - 0x0C);
            uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
            uint8_t value16 = BUS8_RDP(c, (db_ret << 0x10) + 0x0200 + (uint8_t)(((value11 << 8) | value10) + value12));
            BUS8_SET(c, (db_ret << 0x10) + 0x0200 + (uint8_t)(((value14 << 8) | value13) + value15), value16);
            uint8_t value17 = RAM8(0x0000 + sp0 - 0x0B);
            uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value18 - 1));
            a_b86e = (uint16_t)(value17 + 0x10);
            x1 = (uint8_t)(value17 + 0x10);
            y1 = (uint8_t)(((value11 << 8) | value10) + value12);
            carry1 = value17 + 0x10 > 0xFFFF;
            overflow1 = ((value17 ^ value17 + 0x10) & (value17 + 0x10 ^ 0x10) & 0x8000) != 0;
            if (!((uint16_t)(value18 - 1) != 0)) break;
        }
        uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 5));
        r->a = a_b86e;
        r->x = value19;
        r->y = y1;
        r->c = carry1;
        r->z = value19 == 0;
        r->n = value19 & 0x80;
        r->v = overflow1;
        r->xf = 1;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB8C5, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xB8C5); } /* release_native_heap_suffix_through_bank_7f_api */
        r->sp += 11;
        if (r->mf == 0) {
            if (som_exit_arrive(c, 0x7EB8C6)) {
                r->sp -= 11;
                c->cpu.k = 0x7E; c->cpu.pc = 0xB8C6; c->exited = 1;
                return;
            }
            sprite_permutation_m16_epilogue(c, sp0);
            return;
        }
        if (som_exit_arrive(c, 0x7EB8C6)) {
            r->sp -= 11;
            c->cpu.k = 0x7E; c->cpu.pc = 0xB8C6; c->exited = 1;
            return;
        }
        if (som_exit_arrive(c, 0x7EB8CA)) {
            r->a = ((uint16_t)(sp0 - 0x0B) >> 8 << 8) | (uint8_t)((uint8_t)(sp0 - 0x0B) + 8);
            r->c = (uint8_t)(sp0 - 0x0B) + 8 > 0xFF;
            r->z = (uint8_t)((uint8_t)(sp0 - 0x0B) + 8) == 0;
            r->n = (uint8_t)((uint8_t)(sp0 - 0x0B) + 8) & 0x80;
            r->v = (((uint8_t)(sp0 - 0x0B) ^ (uint8_t)((uint8_t)(sp0 - 0x0B) + 8)) & ((uint8_t)((uint8_t)(sp0 - 0x0B) + 8) ^ 8) & 0x80) != 0;
            r->sp -= 11;
            c->cpu.k = 0x7E; c->cpu.pc = 0xB8CA; c->exited = 1;
            return;
        }
        c->fail = 1; /* BRK: software interrupt, outside the contract (the oracle stops here as well) */
        return;
    } else {
        uint16_t value20 = BUS16_RDP(c, (db_ret << 0x10) + 0x02CA);
        BUS16_SET(c, (uint16_t)(dp_ret2 + 1), 0x20);
        uint16_t a_b86e = 0x0020;
        uint16_t x3 = value20;
        uint16_t y3 = y_ret2;
        bool carry2 = carry_ret2;
        bool overflow2 = overflow_ret2;
        for (;;) {
            LOOP_GUARD(loop_guard);
            if (som_exit_arrive(c, 0x7EB86E)) {
                r->a = a_b86e;
                r->x = x3;
                r->y = y3;
                r->c = carry2;
                r->v = overflow2;
                r->xf = 0;
                r->sp -= 11;
                c->cpu.k = 0x7E; c->cpu.pc = 0xB86E; c->exited = 1;
                return;
            }
            RAM8(0x0000 + sp0 - 0x0B) = x3 >> 8;
            RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)x3;
            uint16_t value21 = BUS16_RDP(c, (db_ret << 0x10) + x3);
            uint16_t value22 = BUS16_RDP(c, (db_ret << 0x10) + 0x0A + value21);
            RAM8(0x0000 + sp0 - 0x0D) = 0;
            RAM8(0x0000 + sp0 - 0x0E) = value22 & 0x7F;
            uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
            uint16_t value24 = BUS16_RDP(c, (db_ret << 0x10) + 9 + x3);
            RAM8(0x0000 + sp0 - 0x0F) = value24 >> 8;
            RAM8(0x0000 + sp0 - 0x10) = (uint8_t)value24;
            uint16_t value25 = BUS16_RDP(c, (db_ret << 0x10) + 0x02CC);
            BUS16_SET(c, (uint16_t)(dp_ret2 + 3), 8);
            uint16_t a_b893 = 8;
            uint16_t x4 = (uint16_t)((uint16_t)(value24 << 4) + value25);
            uint16_t y4 = (uint16_t)(((value22 & 0x7F) << 1 << 1 << 1 << 1) + value23);
            for (;;) {
                LOOP_GUARD(loop_guard);
                if (som_exit_arrive(c, 0x7EB893)) {
                    r->a = a_b893;
                    r->x = x4;
                    r->y = y4;
                    r->c = (uint16_t)(value24 << 4) + value25 > 0xFFFF;
                    r->v = (((uint16_t)(value24 << 4) ^ (uint16_t)((uint16_t)(value24 << 4) + value25)) & (value25 ^ (uint16_t)((uint16_t)(value24 << 4) + value25)) & 0x8000) != 0;
                    r->xf = 0;
                    r->sp -= 17;
                    c->cpu.k = 0x7E; c->cpu.pc = 0xB893; c->exited = 1;
                    return;
                }
                uint16_t value26 = BUS16_RDP(c, (db_ret << 0x10) + y4);
                BUS16_SET(c, (db_ret << 0x10) + x4, value26);
                uint16_t value27 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value27 - 1));
                a_b893 = value26;
                x4 = (uint16_t)(x4 + 2);
                y4 = (uint16_t)(y4 + 2);
                if (!((uint16_t)(value27 - 1) != 0)) break;
            }
            uint8_t value28 = RAM8(0x0000 + sp0 - 0x10);
            uint8_t value29 = RAM8(0x0000 + sp0 - 0x0F);
            uint16_t value30 = BUS16_RDP(c, (db_ret << 0x10) + 0x02CC);
            uint8_t value31 = RAM8(0x0000 + sp0 - 0x0E);
            uint8_t value32 = RAM8(0x0000 + sp0 - 0x0D);
            uint16_t value33 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
            uint8_t value34 = BUS8_RDP(c, (db_ret << 0x10) + 0x0200 + (uint16_t)(((value29 << 8) | value28) + value30));
            BUS8_SET(c, (db_ret << 0x10) + 0x0200 + (uint16_t)(((value32 << 8) | value31) + value33), value34);
            uint8_t value35 = RAM8(0x0000 + sp0 - 0x0C);
            uint8_t value36 = RAM8(0x0000 + sp0 - 0x0B);
            uint16_t value37 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value37 - 1));
            a_b86e = (uint16_t)(((value36 << 8) | value35) + 0x10);
            x3 = (uint16_t)(((value36 << 8) | value35) + 0x10);
            y3 = (uint16_t)(((value29 << 8) | value28) + value30);
            carry2 = ((value36 << 8) | value35) + 0x10 > 0xFFFF;
            overflow2 = ((((value36 << 8) | value35) ^ (uint16_t)(((value36 << 8) | value35) + 0x10)) & ((uint16_t)(((value36 << 8) | value35) + 0x10) ^ 0x10) & 0x8000) != 0;
            if (!((uint16_t)(value37 - 1) != 0)) break;
        }
        uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
        r->a = a_b86e;
        r->x = value38;
        r->y = y3;
        r->c = carry2;
        r->z = value38 == 0;
        r->n = value38 & 0x8000;
        r->v = overflow2;
        r->xf = 0;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB8C5, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xB8C5); } /* release_native_heap_suffix_through_bank_7f_api */
        r->sp += 11;
        if (r->mf == 0) {
            if (som_exit_arrive(c, 0x7EB8C6)) {
                r->sp -= 11;
                c->cpu.k = 0x7E; c->cpu.pc = 0xB8C6; c->exited = 1;
                return;
            }
            sprite_permutation_m16_epilogue(c, sp0);
            return;
        }
        if (som_exit_arrive(c, 0x7EB8C6)) {
            r->sp -= 11;
            c->cpu.k = 0x7E; c->cpu.pc = 0xB8C6; c->exited = 1;
            return;
        }
        if (som_exit_arrive(c, 0x7EB8CA)) {
            r->a = ((uint16_t)(sp0 - 0x0B) >> 8 << 8) | (uint8_t)((uint8_t)(sp0 - 0x0B) + 8);
            r->c = (uint8_t)(sp0 - 0x0B) + 8 > 0xFF;
            r->z = (uint8_t)((uint8_t)(sp0 - 0x0B) + 8) == 0;
            r->n = (uint8_t)((uint8_t)(sp0 - 0x0B) + 8) & 0x80;
            r->v = (((uint8_t)(sp0 - 0x0B) ^ (uint8_t)((uint8_t)(sp0 - 0x0B) + 8)) & ((uint8_t)((uint8_t)(sp0 - 0x0B) + 8) ^ 8) & 0x80) != 0;
            r->sp -= 11;
            c->cpu.k = 0x7E; c->cpu.pc = 0xB8CA; c->exited = 1;
            return;
        }
        c->fail = 1; /* BRK: software interrupt, outside the contract (the oracle stops here as well) */
        return;
    }
}
SOM_REGISTER(0x7EB840, SOM_RTS, "hand", begin_and_repeat_native_sprite_permutation_with_shared_counter, 0, L_ALL, 17, 1, 0, 143, 81)
