#include "som_c.h"

static void test_actor_vertical_footprint_and_redirect_step(SomCtx *c);
static void test_actor_vertical_footprint_and_redirect_step_v2(SomCtx *c);
static void test_actor_vertical_footprint_and_redirect_step_v3(SomCtx *c);
static void test_actor_vertical_footprint_and_redirect_step_v4(SomCtx *c);
static void test_actor_vertical_footprint_and_redirect_step_v5(SomCtx *c);
static void test_actor_vertical_footprint_and_redirect_step_v6(SomCtx *c);
static void test_actor_vertical_footprint_and_redirect_step_v7(SomCtx *c);
static void test_actor_vertical_footprint_and_redirect_step_v8(SomCtx *c);

/* C1B9EA test_actor_horizontal_footprint_and_redirect_step   [class C, 578 bytes, 316 instructions]
 * Source: src/rom/test_actor_horizontal_footprint_and_redirect_step.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCZNV.
 */
static void test_actor_horizontal_footprint_and_redirect_step(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_ba10 = 0;
    uint8_t a_hi_ba10 = 0;
    uint8_t a_ba21 = 0;
    uint8_t a_hi_ba21 = 0;
    uint8_t a_ba42 = 0;
    uint8_t a_hi_ba42 = 0;
    uint8_t a_hi_ba77 = 0;
    uint16_t y_ba77 = 0;
    bool carry_ba77 = 0;
    uint8_t a_hi_ba88 = 0;
    uint8_t y_ba88 = 0;
    bool zero_ba88 = 0;
    bool negative_ba88 = 0;
    bool overflow_ba88 = 0;
    bool irq_disable_ba88 = 0;
    bool decimal_ba88 = 0;
    uint8_t a_hi_ba882 = 0;
    uint16_t y_ba882 = 0;
    bool zero_ba882 = 0;
    bool negative_ba882 = 0;
    bool overflow_ba882 = 0;
    bool irq_disable_ba882 = 0;
    bool decimal_ba882 = 0;
    uint8_t a_hi_ba883 = 0;
    uint8_t y_ba883 = 0;
    bool zero_ba883 = 0;
    bool negative_ba883 = 0;
    bool overflow_ba883 = 0;
    bool irq_disable_ba883 = 0;
    bool decimal_ba883 = 0;
    uint8_t a_hi_ba884 = 0;
    uint16_t y_ba884 = 0;
    bool zero_ba884 = 0;
    bool negative_ba884 = 0;
    bool overflow_ba884 = 0;
    bool irq_disable_ba884 = 0;
    bool decimal_ba884 = 0;
    uint8_t a_hi_ba86 = 0;
    uint8_t y_ba86 = 0;
    bool zero_ba86 = 0;
    bool negative_ba86 = 0;
    bool overflow_ba86 = 0;
    bool irq_disable_ba86 = 0;
    bool decimal_ba86 = 0;
    uint8_t a_hi_ba862 = 0;
    uint16_t y_ba862 = 0;
    bool zero_ba862 = 0;
    bool negative_ba862 = 0;
    bool overflow_ba862 = 0;
    bool irq_disable_ba862 = 0;
    bool decimal_ba862 = 0;
    uint8_t a_hi_bbfb = 0;
    uint8_t y_bbfb = 0;
    bool zero_bbfb = 0;
    bool negative_bbfb = 0;
    bool overflow_bbfb = 0;
    bool irq_disable_bbfb = 0;
    bool decimal_bbfb = 0;
    uint8_t a_hi_bbfb2 = 0;
    uint16_t y_bbfb2 = 0;
    bool zero_bbfb2 = 0;
    bool negative_bbfb2 = 0;
    bool overflow_bbfb2 = 0;
    bool irq_disable_bbfb2 = 0;
    bool decimal_bbfb2 = 0;
    uint8_t a_ba98 = 0;
    uint8_t a_hi_ba98 = 0;
    bool overflow_ba98 = 0;
    bool irq_disable_ba98 = 0;
    bool decimal_ba98 = 0;
    uint8_t a_ba982 = 0;
    uint8_t a_hi_ba982 = 0;
    bool overflow_ba982 = 0;
    bool irq_disable_ba982 = 0;
    bool decimal_ba982 = 0;
    uint8_t a_hi_ba863 = 0;
    uint8_t y_ba863 = 0;
    bool zero_ba863 = 0;
    bool negative_ba863 = 0;
    bool overflow_ba863 = 0;
    bool irq_disable_ba863 = 0;
    bool decimal_ba863 = 0;
    uint8_t a_hi_ba864 = 0;
    uint16_t y_ba864 = 0;
    bool zero_ba864 = 0;
    bool negative_ba864 = 0;
    bool overflow_ba864 = 0;
    bool irq_disable_ba864 = 0;
    bool decimal_ba864 = 0;
    uint8_t a_hi_bc08 = 0;
    uint8_t y_bc08 = 0;
    bool overflow_bc08 = 0;
    uint16_t direct_page_bc08 = 0;
    uint8_t data_bank_bc08 = 0;
    bool irq_disable_bc08 = 0;
    bool decimal_bc08 = 0;
    uint8_t a_hi_bc082 = 0;
    uint16_t y_bc082 = 0;
    bool overflow_bc082 = 0;
    uint16_t direct_page_bc082 = 0;
    uint8_t data_bank_bc082 = 0;
    bool irq_disable_bc082 = 0;
    bool decimal_bc082 = 0;
    uint8_t a_hi_bc083 = 0;
    uint8_t y_bc083 = 0;
    bool overflow_bc083 = 0;
    uint16_t direct_page_bc083 = 0;
    uint8_t data_bank_bc083 = 0;
    bool irq_disable_bc083 = 0;
    bool decimal_bc083 = 0;
    uint8_t a_hi_bc084 = 0;
    uint16_t y_bc084 = 0;
    bool overflow_bc084 = 0;
    uint16_t direct_page_bc084 = 0;
    uint8_t data_bank_bc084 = 0;
    bool irq_disable_bc084 = 0;
    bool decimal_bc084 = 0;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = RAM8(0x001A);
    uint8_t value2 = RAM8(0x001E);
    if ((uint8_t)((value >> 1) + value2) >= 0x80) {
        uint16_t value3 = RAM16(0x0012);
        if (!((uint16_t)(((((a_hi << 8) | (uint8_t)((value >> 1) + value2)) & 0x7F) ^ 0xFFFF) + value3 + 1) & 0x8000)) {
            a_ba10 = (uint8_t)(((((a_hi << 8) | (uint8_t)((value >> 1) + value2)) & 0x7F) ^ 0xFFFF) + value3 + 1);
            a_hi_ba10 = (uint16_t)(((((a_hi << 8) | (uint8_t)((value >> 1) + value2)) & 0x7F) ^ 0xFFFF) + value3 + 1) >> 8;
            goto shared_BA10;
        }
        uint16_t value4 = RAM16(0x00C0);
        a_ba10 = (uint8_t)((uint16_t)(((((a_hi << 8) | (uint8_t)((value >> 1) + value2)) & 0x7F) ^ 0xFFFF) + value3 + 1) + value4);
        a_hi_ba10 = (uint16_t)((uint16_t)(((((a_hi << 8) | (uint8_t)((value >> 1) + value2)) & 0x7F) ^ 0xFFFF) + value3 + 1) + value4) >> 8;
        goto shared_BA10;
    }
    uint16_t value5 = RAM16(0x0012);
    uint16_t value6 = RAM16(0x00C0);
    if ((uint16_t)((((a_hi << 8) | (uint8_t)((value >> 1) + value2)) & 0x7F) + value5) < value6) {
        a_ba10 = (uint8_t)((((a_hi << 8) | (uint8_t)((value >> 1) + value2)) & 0x7F) + value5);
        a_hi_ba10 = (uint16_t)((((a_hi << 8) | (uint8_t)((value >> 1) + value2)) & 0x7F) + value5) >> 8;
        goto shared_BA10;
    }
    a_ba10 = (uint8_t)((uint16_t)((((a_hi << 8) | (uint8_t)((value >> 1) + value2)) & 0x7F) + value5) - value6 - ((uint16_t)((((a_hi << 8) | (uint8_t)((value >> 1) + value2)) & 0x7F) + value5) >= value6 ^ 1));
    a_hi_ba10 = (uint16_t)((uint16_t)((((a_hi << 8) | (uint8_t)((value >> 1) + value2)) & 0x7F) + value5) - value6 - ((uint16_t)((((a_hi << 8) | (uint8_t)((value >> 1) + value2)) & 0x7F) + value5) >= value6 ^ 1)) >> 8;
    shared_BA10:;
    RAM16_SET(0x0004, (a_hi_ba10 << 8) | a_ba10);
    RAM16_SET(0x0008, ((a_hi_ba10 << 8) | a_ba10) >> 4);
    uint8_t value7 = RAM8(0x001F);
    if (!(value7 & 0x80)) {
        a_ba21 = value7;
        a_hi_ba21 = ((a_hi_ba10 << 8) | a_ba10) >> 4 >> 8;
        goto shared_BA21;
    }
    a_ba21 = (uint8_t)((value7 ^ 0x7F) + 1);
    a_hi_ba21 = ((a_hi_ba10 << 8) | a_ba10) >> 4 >> 8;
    goto shared_BA21;
    shared_BA21:;
    if ((uint8_t)(a_ba21 + 4) >= 0x80) {
        uint16_t value8 = RAM16(0x0014);
        if (!((uint16_t)(((((a_hi_ba21 << 8) | (uint8_t)(a_ba21 + 4)) & 0x7F) ^ 0xFFFF) + value8 + 1) & 0x8000)) {
            a_ba42 = (uint8_t)(((((a_hi_ba21 << 8) | (uint8_t)(a_ba21 + 4)) & 0x7F) ^ 0xFFFF) + value8 + 1);
            a_hi_ba42 = (uint16_t)(((((a_hi_ba21 << 8) | (uint8_t)(a_ba21 + 4)) & 0x7F) ^ 0xFFFF) + value8 + 1) >> 8;
            goto shared_BA42;
        }
        uint16_t value9 = RAM16(0x00C2);
        a_ba42 = (uint8_t)((uint16_t)(((((a_hi_ba21 << 8) | (uint8_t)(a_ba21 + 4)) & 0x7F) ^ 0xFFFF) + value8 + 1) + value9);
        a_hi_ba42 = (uint16_t)((uint16_t)(((((a_hi_ba21 << 8) | (uint8_t)(a_ba21 + 4)) & 0x7F) ^ 0xFFFF) + value8 + 1) + value9) >> 8;
        goto shared_BA42;
    }
    uint16_t value10 = RAM16(0x0014);
    uint16_t value11 = RAM16(0x00C2);
    if ((uint16_t)((((a_hi_ba21 << 8) | (uint8_t)(a_ba21 + 4)) & 0x7F) + value10 + ((uint8_t)(a_ba21 + 4) >= 0x80)) < value11) {
        a_ba42 = (uint8_t)((((a_hi_ba21 << 8) | (uint8_t)(a_ba21 + 4)) & 0x7F) + value10 + ((uint8_t)(a_ba21 + 4) >= 0x80));
        a_hi_ba42 = (uint16_t)((((a_hi_ba21 << 8) | (uint8_t)(a_ba21 + 4)) & 0x7F) + value10 + ((uint8_t)(a_ba21 + 4) >= 0x80)) >> 8;
        goto shared_BA42;
    }
    a_ba42 = (uint8_t)((uint16_t)((((a_hi_ba21 << 8) | (uint8_t)(a_ba21 + 4)) & 0x7F) + value10 + ((uint8_t)(a_ba21 + 4) >= 0x80)) - value11 - ((uint16_t)((((a_hi_ba21 << 8) | (uint8_t)(a_ba21 + 4)) & 0x7F) + value10 + ((uint8_t)(a_ba21 + 4) >= 0x80)) >= value11 ^ 1));
    a_hi_ba42 = (uint16_t)((uint16_t)((((a_hi_ba21 << 8) | (uint8_t)(a_ba21 + 4)) & 0x7F) + value10 + ((uint8_t)(a_ba21 + 4) >= 0x80)) - value11 - ((uint16_t)((((a_hi_ba21 << 8) | (uint8_t)(a_ba21 + 4)) & 0x7F) + value10 + ((uint8_t)(a_ba21 + 4) >= 0x80)) >= value11 ^ 1)) >> 8;
    goto shared_BA42;
    shared_BA42:;
    RAM8(0x0000 + sp0 - 1) = a_hi_ba42;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)((a_hi_ba42 << 8) | a_ba42);
    RAM16_SET(0x0004, ((a_ba42 << 8) | RAM8(0x0004)) & 0x0F0F);
    uint16_t value13 = RAM16(0x0008);
    RAM16_SET(0x0008, ((((a_hi_ba42 << 8) | a_ba42) & 0x0FF0) << 1 << 1 << 1) | value13);
    uint16_t value14 = BUS16_RDL(c, (RAM8(0x000C) << 0x10) + RAM16(0x000A) + (((((a_hi_ba42 << 8) | a_ba42) & 0x0FF0) << 1 << 1 << 1) | value13), RAM8(0x000C));
    uint8_t value15 = BUS8_RDL(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value14 & 0xFF) << 1 << 1), RAM8(0x000F));
    RAM8(0x0007) = value15;
    uint8_t value16 = BUS8_RDL(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + (((value14 & 0xFF) << 1 << 1) + 2), RAM8(0x000F));
    RAM8(0x0006) = value16;
    if ((value16 & 0xF0) == 0x10) {
        a_hi_ba77 = (value14 & 0xFF) << 1 << 1 >> 8;
        y_ba77 = ((value14 & 0xFF) << 1 << 1) + 2;
        carry_ba77 = (value16 & 0xF0) >= 0x10;
        goto shared_BA77;
    }
    RAM8(0x0006) = 0;
    a_hi_ba77 = (value14 & 0xFF) << 1 << 1 >> 8;
    y_ba77 = ((value14 & 0xFF) << 1 << 1) + 2;
    carry_ba77 = (value16 & 0xF0) >= 0x10;
    goto shared_BA77;
    shared_BA77:;
    r->a = (a_hi_ba77 << 8) | a;
    r->y = y_ba77;
    r->c = carry_ba77;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBA79, 0xC1BE15); GUARD_JSR(c, sp_call, 0xBA79); } /* test_vertical_terrain_shape_and_preceding_cells */
    r->sp += 1;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    if (carry_ret) {
        uint8_t value17 = RAM8(0x0000 + sp0);
        if (value17 & 0x01) {
            if (value17 & 0x20) {
                if (value17 & 0x10) {
                    a_hi_ba88 = a_all >> 8;
                    y_ba88 = (uint8_t)y_ret;
                    zero_ba88 = value17 & 0x02;
                    negative_ba88 = value17 & 0x80;
                    overflow_ba88 = value17 & 0x40;
                    irq_disable_ba88 = value17 & 0x04;
                    decimal_ba88 = value17 & 0x08;
                    goto shared_BA88;
                } else {
                    a_hi_ba882 = a_all >> 8;
                    y_ba882 = y_ret;
                    zero_ba882 = value17 & 0x02;
                    negative_ba882 = value17 & 0x80;
                    overflow_ba882 = value17 & 0x40;
                    irq_disable_ba882 = value17 & 0x04;
                    decimal_ba882 = value17 & 0x08;
                    goto shared_BA88_1;
                }
            } else {
                if (value17 & 0x10) {
                    a_hi_ba883 = a_all >> 8;
                    y_ba883 = (uint8_t)y_ret;
                    zero_ba883 = value17 & 0x02;
                    negative_ba883 = value17 & 0x80;
                    overflow_ba883 = value17 & 0x40;
                    irq_disable_ba883 = value17 & 0x04;
                    decimal_ba883 = value17 & 0x08;
                    goto shared_BA88_2;
                } else {
                    a_hi_ba884 = a_all >> 8;
                    y_ba884 = y_ret;
                    zero_ba884 = value17 & 0x02;
                    negative_ba884 = value17 & 0x80;
                    overflow_ba884 = value17 & 0x40;
                    irq_disable_ba884 = value17 & 0x04;
                    decimal_ba884 = value17 & 0x08;
                    goto shared_BA88_3;
                }
            }
        }
        if (value17 & 0x20) {
            uint8_t value18 = RAM8(0x0002);
            if (value18 != 0) {
                if (value18 < 8) {
                    uint8_t value19 = RAM8(0x001E);
                    if (value19 & 0x80) {
                        if (value18 != 4) {
                            if (value18 != 6) {
                                if (value17 & 0x10) {
                                    a_hi_ba86 = a_all >> 8;
                                    y_ba86 = (uint8_t)y_ret;
                                    zero_ba86 = value18 == 6;
                                    negative_ba86 = (uint8_t)(value18 - 6) & 0x80;
                                    overflow_ba86 = value19 & 0x40;
                                    irq_disable_ba86 = value17 & 0x04;
                                    decimal_ba86 = value17 & 0x08;
                                    goto shared_BA86;
                                } else {
                                    a_hi_ba862 = a_all >> 8;
                                    y_ba862 = y_ret;
                                    zero_ba862 = value18 == 6;
                                    negative_ba862 = (uint8_t)(value18 - 6) & 0x80;
                                    overflow_ba862 = value19 & 0x40;
                                    irq_disable_ba862 = value17 & 0x04;
                                    decimal_ba862 = value17 & 0x08;
                                    goto shared_BA86_1;
                                }
                            }
                            RAM8(0x001F) = value19 ^ 0x80;
                            RAM8(0x001D)++;
                            if (value17 & 0x10) {
                                a_hi_bbfb = a_all >> 8;
                                y_bbfb = (uint8_t)y_ret;
                                zero_bbfb = RAM8(0x001D) == 0;
                                negative_bbfb = RAM8(0x001D) & 0x80;
                                overflow_bbfb = value19 & 0x40;
                                irq_disable_bbfb = value17 & 0x04;
                                decimal_bbfb = value17 & 0x08;
                                goto shared_BBFB;
                            } else {
                                a_hi_bbfb2 = a_all >> 8;
                                y_bbfb2 = y_ret;
                                zero_bbfb2 = RAM8(0x001D) == 0;
                                negative_bbfb2 = RAM8(0x001D) & 0x80;
                                overflow_bbfb2 = value19 & 0x40;
                                irq_disable_bbfb2 = value17 & 0x04;
                                decimal_bbfb2 = value17 & 0x08;
                                goto shared_BBFB_1;
                            }
                        }
                        RAM8(0x001F) = value19;
                        RAM8(0x001D)++;
                        if (value17 & 0x10) {
                            a_hi_bbfb = a_all >> 8;
                            y_bbfb = (uint8_t)y_ret;
                            zero_bbfb = RAM8(0x001D) == 0;
                            negative_bbfb = RAM8(0x001D) & 0x80;
                            overflow_bbfb = value19 & 0x40;
                            irq_disable_bbfb = value17 & 0x04;
                            decimal_bbfb = value17 & 0x08;
                            goto shared_BBFB;
                        } else {
                            a_hi_bbfb2 = a_all >> 8;
                            y_bbfb2 = y_ret;
                            zero_bbfb2 = RAM8(0x001D) == 0;
                            negative_bbfb2 = RAM8(0x001D) & 0x80;
                            overflow_bbfb2 = value19 & 0x40;
                            irq_disable_bbfb2 = value17 & 0x04;
                            decimal_bbfb2 = value17 & 0x08;
                            goto shared_BBFB_1;
                        }
                    }
                    if (value18 != 5) {
                        if (value18 != 7) {
                            if (value17 & 0x10) {
                                a_hi_ba86 = a_all >> 8;
                                y_ba86 = (uint8_t)y_ret;
                                zero_ba86 = value18 == 7;
                                negative_ba86 = (uint8_t)(value18 - 7) & 0x80;
                                overflow_ba86 = value19 & 0x40;
                                irq_disable_ba86 = value17 & 0x04;
                                decimal_ba86 = value17 & 0x08;
                                goto shared_BA86;
                            } else {
                                a_hi_ba862 = a_all >> 8;
                                y_ba862 = y_ret;
                                zero_ba862 = value18 == 7;
                                negative_ba862 = (uint8_t)(value18 - 7) & 0x80;
                                overflow_ba862 = value19 & 0x40;
                                irq_disable_ba862 = value17 & 0x04;
                                decimal_ba862 = value17 & 0x08;
                                goto shared_BA86_1;
                            }
                        }
                        RAM8(0x001F) = value19 ^ 0x80;
                        RAM8(0x001D)++;
                        if (value17 & 0x10) {
                            a_hi_bbfb = a_all >> 8;
                            y_bbfb = (uint8_t)y_ret;
                            zero_bbfb = RAM8(0x001D) == 0;
                            negative_bbfb = RAM8(0x001D) & 0x80;
                            overflow_bbfb = value19 & 0x40;
                            irq_disable_bbfb = value17 & 0x04;
                            decimal_bbfb = value17 & 0x08;
                            goto shared_BBFB;
                        } else {
                            a_hi_bbfb2 = a_all >> 8;
                            y_bbfb2 = y_ret;
                            zero_bbfb2 = RAM8(0x001D) == 0;
                            negative_bbfb2 = RAM8(0x001D) & 0x80;
                            overflow_bbfb2 = value19 & 0x40;
                            irq_disable_bbfb2 = value17 & 0x04;
                            decimal_bbfb2 = value17 & 0x08;
                            goto shared_BBFB_1;
                        }
                    }
                    RAM8(0x001F) = value19;
                    RAM8(0x001D)++;
                    if (value17 & 0x10) {
                        a_hi_bbfb = a_all >> 8;
                        y_bbfb = (uint8_t)y_ret;
                        zero_bbfb = RAM8(0x001D) == 0;
                        negative_bbfb = RAM8(0x001D) & 0x80;
                        overflow_bbfb = value19 & 0x40;
                        irq_disable_bbfb = value17 & 0x04;
                        decimal_bbfb = value17 & 0x08;
                        goto shared_BBFB;
                    } else {
                        a_hi_bbfb2 = a_all >> 8;
                        y_bbfb2 = y_ret;
                        zero_bbfb2 = RAM8(0x001D) == 0;
                        negative_bbfb2 = RAM8(0x001D) & 0x80;
                        overflow_bbfb2 = value19 & 0x40;
                        irq_disable_bbfb2 = value17 & 0x04;
                        decimal_bbfb2 = value17 & 0x08;
                        goto shared_BBFB_1;
                    }
                }
                if (value18 == 8) {
                    uint8_t value20 = RAM8(0x001E);
                    if (value17 & 0x10) {
                        a_ba98 = value20;
                        a_hi_ba98 = a_all >> 8;
                        overflow_ba98 = value17 & 0x40;
                        irq_disable_ba98 = value17 & 0x04;
                        decimal_ba98 = value17 & 0x08;
                        goto shared_BA98;
                    } else {
                        a_ba982 = value20;
                        a_hi_ba982 = a_all >> 8;
                        overflow_ba982 = value17 & 0x40;
                        irq_disable_ba982 = value17 & 0x04;
                        decimal_ba982 = value17 & 0x08;
                        goto shared_BA98_1;
                    }
                }
                if (value18 != 9) {
                    if (value17 & 0x10) {
                        a_hi_ba86 = a_all >> 8;
                        y_ba86 = (uint8_t)y_ret;
                        zero_ba86 = value18 == 9;
                        negative_ba86 = (uint8_t)(value18 - 9) & 0x80;
                        overflow_ba86 = value17 & 0x40;
                        irq_disable_ba86 = value17 & 0x04;
                        decimal_ba86 = value17 & 0x08;
                        goto shared_BA86;
                    } else {
                        a_hi_ba862 = a_all >> 8;
                        y_ba862 = y_ret;
                        zero_ba862 = value18 == 9;
                        negative_ba862 = (uint8_t)(value18 - 9) & 0x80;
                        overflow_ba862 = value17 & 0x40;
                        irq_disable_ba862 = value17 & 0x04;
                        decimal_ba862 = value17 & 0x08;
                        goto shared_BA86_1;
                    }
                }
                uint8_t value21 = RAM8(0x001E);
                if (value17 & 0x10) {
                    a_ba98 = value21 ^ 0x80;
                    a_hi_ba98 = a_all >> 8;
                    overflow_ba98 = value17 & 0x40;
                    irq_disable_ba98 = value17 & 0x04;
                    decimal_ba98 = value17 & 0x08;
                    goto shared_BA98;
                } else {
                    a_ba982 = value21 ^ 0x80;
                    a_hi_ba982 = a_all >> 8;
                    overflow_ba982 = value17 & 0x40;
                    irq_disable_ba982 = value17 & 0x04;
                    decimal_ba982 = value17 & 0x08;
                    goto shared_BA98_1;
                }
            }
            if (value17 & 0x10) {
                a_hi_ba86 = a_all >> 8;
                y_ba86 = (uint8_t)y_ret;
                zero_ba86 = value18 == 0;
                negative_ba86 = value18 & 0x80;
                overflow_ba86 = value17 & 0x40;
                irq_disable_ba86 = value17 & 0x04;
                decimal_ba86 = value17 & 0x08;
                goto shared_BA86;
            } else {
                a_hi_ba862 = a_all >> 8;
                y_ba862 = y_ret;
                zero_ba862 = value18 == 0;
                negative_ba862 = value18 & 0x80;
                overflow_ba862 = value17 & 0x40;
                irq_disable_ba862 = value17 & 0x04;
                decimal_ba862 = value17 & 0x08;
                goto shared_BA86_1;
            }
        } else {
            uint16_t value22 = RAM16(0x0002);
            if (value22 != 0) {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
            if (value17 & 0x10) {
                a_hi_ba863 = value22 >> 8;
                y_ba863 = (uint8_t)y_ret;
                zero_ba863 = value22 == 0;
                negative_ba863 = value22 & 0x8000;
                overflow_ba863 = value17 & 0x40;
                irq_disable_ba863 = value17 & 0x04;
                decimal_ba863 = value17 & 0x08;
                goto shared_BA86_2;
            } else {
                a_hi_ba864 = value22 >> 8;
                y_ba864 = y_ret;
                zero_ba864 = value22 == 0;
                negative_ba864 = value22 & 0x8000;
                overflow_ba864 = value17 & 0x40;
                irq_disable_ba864 = value17 & 0x04;
                decimal_ba864 = value17 & 0x08;
                goto shared_BA86_3;
            }
        }
    }
    uint8_t value23 = RAM8(0x0000 + sp0);
    r->c = 0;
    r->z = value23 & 0x02;
    r->n = value23 & 0x80;
    r->v = value23 & 0x40;
    r->mf = value23 & 0x20;
    r->xf = value23 & 0x10;
    r->i = value23 & 0x04;
    r->d = value23 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BA88:;
    r->a = (a_hi_ba88 << 8) | a;
    r->y = y_ba88;
    r->c = 1;
    r->z = zero_ba88;
    r->n = negative_ba88;
    r->v = overflow_ba88;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_ba88;
    r->d = decimal_ba88;
    RETURN_RTS(c);
    shared_BA88_1:;
    r->a = (a_hi_ba882 << 8) | a;
    r->y = y_ba882;
    r->c = 1;
    r->z = zero_ba882;
    r->n = negative_ba882;
    r->v = overflow_ba882;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_ba882;
    r->d = decimal_ba882;
    RETURN_RTS(c);
    shared_BA88_2:;
    r->a = (a_hi_ba883 << 8) | a;
    r->y = y_ba883;
    r->c = 1;
    r->z = zero_ba883;
    r->n = negative_ba883;
    r->v = overflow_ba883;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_ba883;
    r->d = decimal_ba883;
    RETURN_RTS(c);
    shared_BA88_3:;
    r->a = (a_hi_ba884 << 8) | a;
    r->y = y_ba884;
    r->c = 1;
    r->z = zero_ba884;
    r->n = negative_ba884;
    r->v = overflow_ba884;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_ba884;
    r->d = decimal_ba884;
    RETURN_RTS(c);
    shared_BA86:;
    RAM8(0x001E) = 0;
    a_hi_ba88 = a_hi_ba86;
    y_ba88 = y_ba86;
    zero_ba88 = zero_ba86;
    negative_ba88 = negative_ba86;
    overflow_ba88 = overflow_ba86;
    irq_disable_ba88 = irq_disable_ba86;
    decimal_ba88 = decimal_ba86;
    goto shared_BA88;
    shared_BA86_1:;
    RAM8(0x001E) = 0;
    a_hi_ba882 = a_hi_ba862;
    y_ba882 = y_ba862;
    zero_ba882 = zero_ba862;
    negative_ba882 = negative_ba862;
    overflow_ba882 = overflow_ba862;
    irq_disable_ba882 = irq_disable_ba862;
    decimal_ba882 = decimal_ba862;
    goto shared_BA88_1;
    shared_BBFB:;
    r->a = (a_hi_bbfb << 8) | a;
    r->y = y_bbfb;
    r->c = 1;
    r->z = zero_bbfb;
    r->n = negative_bbfb;
    r->v = overflow_bbfb;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bbfb;
    r->d = decimal_bbfb;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBBFE, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBBFE); } /* test_actor_horizontal_footprint_and_redirect_step */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    if (carry_ret2) {
        if (m_ret) {
            if (x_ret) {
                a_hi_bc08 = a_all2 >> 8;
                y_bc08 = (uint8_t)y_ret2;
                overflow_bc08 = overflow_ret2;
                direct_page_bc08 = 0;
                data_bank_bc08 = 0x7E;
                irq_disable_bc08 = irq_disable_bbfb;
                decimal_bc08 = decimal_bbfb;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all2 >> 8;
                y_bc082 = y_ret2;
                overflow_bc082 = overflow_ret2;
                direct_page_bc082 = 0;
                data_bank_bc082 = 0x7E;
                irq_disable_bc082 = irq_disable_bbfb;
                decimal_bc082 = decimal_bbfb;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret) {
                a_hi_bc083 = a_all2 >> 8;
                y_bc083 = (uint8_t)y_ret2;
                overflow_bc083 = overflow_ret2;
                direct_page_bc083 = 0;
                data_bank_bc083 = 0x7E;
                irq_disable_bc083 = irq_disable_bbfb;
                decimal_bc083 = decimal_bbfb;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all2 >> 8;
                y_bc084 = y_ret2;
                overflow_bc084 = overflow_ret2;
                direct_page_bc084 = 0;
                data_bank_bc084 = 0x7E;
                irq_disable_bc084 = irq_disable_bbfb;
                decimal_bc084 = decimal_bbfb;
                goto shared_BC08_3;
            }
        }
    }
    r->c = 1;
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); }
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret2 = r->mf;
    bool x_ret2 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    if (carry_ret3) {
        if (m_ret2) {
            if (x_ret2) {
                a_hi_bc08 = a_all3 >> 8;
                y_bc08 = (uint8_t)y_ret3;
                overflow_bc08 = overflow_ret3;
                direct_page_bc08 = dp_ret;
                data_bank_bc08 = db_ret;
                irq_disable_bc08 = irq_disable_bbfb;
                decimal_bc08 = decimal_bbfb;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all3 >> 8;
                y_bc082 = y_ret3;
                overflow_bc082 = overflow_ret3;
                direct_page_bc082 = dp_ret;
                data_bank_bc082 = db_ret;
                irq_disable_bc082 = irq_disable_bbfb;
                decimal_bc082 = decimal_bbfb;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret2) {
                a_hi_bc083 = a_all3 >> 8;
                y_bc083 = (uint8_t)y_ret3;
                overflow_bc083 = overflow_ret3;
                direct_page_bc083 = dp_ret;
                data_bank_bc083 = db_ret;
                irq_disable_bc083 = irq_disable_bbfb;
                decimal_bc083 = decimal_bbfb;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all3 >> 8;
                y_bc084 = y_ret3;
                overflow_bc084 = overflow_ret3;
                direct_page_bc084 = dp_ret;
                data_bank_bc084 = db_ret;
                irq_disable_bc084 = irq_disable_bbfb;
                decimal_bc084 = decimal_bbfb;
                goto shared_BC08_3;
            }
        }
    }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BBFB_1:;
    r->a = (a_hi_bbfb2 << 8) | a;
    r->y = y_bbfb2;
    r->c = 1;
    r->z = zero_bbfb2;
    r->n = negative_bbfb2;
    r->v = overflow_bbfb2;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bbfb2;
    r->d = decimal_bbfb2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBBFE, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBBFE); } /* test_actor_horizontal_footprint_and_redirect_step */
    bool m_ret3 = r->mf;
    bool x_ret3 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t y_ret4 = r->y;
    bool carry_ret4 = r->c;
    bool overflow_ret4 = r->v;
    if (carry_ret4) {
        if (m_ret3) {
            if (x_ret3) {
                a_hi_bc08 = a_all4 >> 8;
                y_bc08 = (uint8_t)y_ret4;
                overflow_bc08 = overflow_ret4;
                direct_page_bc08 = 0;
                data_bank_bc08 = 0x7E;
                irq_disable_bc08 = irq_disable_bbfb2;
                decimal_bc08 = decimal_bbfb2;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all4 >> 8;
                y_bc082 = y_ret4;
                overflow_bc082 = overflow_ret4;
                direct_page_bc082 = 0;
                data_bank_bc082 = 0x7E;
                irq_disable_bc082 = irq_disable_bbfb2;
                decimal_bc082 = decimal_bbfb2;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret3) {
                a_hi_bc083 = a_all4 >> 8;
                y_bc083 = (uint8_t)y_ret4;
                overflow_bc083 = overflow_ret4;
                direct_page_bc083 = 0;
                data_bank_bc083 = 0x7E;
                irq_disable_bc083 = irq_disable_bbfb2;
                decimal_bc083 = decimal_bbfb2;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all4 >> 8;
                y_bc084 = y_ret4;
                overflow_bc084 = overflow_ret4;
                direct_page_bc084 = 0;
                data_bank_bc084 = 0x7E;
                irq_disable_bc084 = irq_disable_bbfb2;
                decimal_bc084 = decimal_bbfb2;
                goto shared_BC08_3;
            }
        }
    }
    r->c = 1;
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); }
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret4 = r->mf;
    bool x_ret4 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t y_ret5 = r->y;
    bool carry_ret5 = r->c;
    bool overflow_ret5 = r->v;
    if (carry_ret5) {
        if (m_ret4) {
            if (x_ret4) {
                a_hi_bc08 = a_all5 >> 8;
                y_bc08 = (uint8_t)y_ret5;
                overflow_bc08 = overflow_ret5;
                direct_page_bc08 = dp_ret2;
                data_bank_bc08 = db_ret2;
                irq_disable_bc08 = irq_disable_bbfb2;
                decimal_bc08 = decimal_bbfb2;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all5 >> 8;
                y_bc082 = y_ret5;
                overflow_bc082 = overflow_ret5;
                direct_page_bc082 = dp_ret2;
                data_bank_bc082 = db_ret2;
                irq_disable_bc082 = irq_disable_bbfb2;
                decimal_bc082 = decimal_bbfb2;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret4) {
                a_hi_bc083 = a_all5 >> 8;
                y_bc083 = (uint8_t)y_ret5;
                overflow_bc083 = overflow_ret5;
                direct_page_bc083 = dp_ret2;
                data_bank_bc083 = db_ret2;
                irq_disable_bc083 = irq_disable_bbfb2;
                decimal_bc083 = decimal_bbfb2;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all5 >> 8;
                y_bc084 = y_ret5;
                overflow_bc084 = overflow_ret5;
                direct_page_bc084 = dp_ret2;
                data_bank_bc084 = db_ret2;
                irq_disable_bc084 = irq_disable_bbfb2;
                decimal_bc084 = decimal_bbfb2;
                goto shared_BC08_3;
            }
        }
    }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BA98:;
    RAM8(0x001F) = a_ba98;
    RAM8(0x001E) = 0;
    RAM8(0x001D)++;
    uint8_t value24 = RAM8(0x001D);
    r->a = (a_hi_ba98 << 8) | a_ba98;
    r->c = 1;
    r->z = value24 == 0;
    r->n = value24 & 0x80;
    r->v = overflow_ba98;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_ba98;
    r->d = decimal_ba98;
    test_actor_vertical_footprint_and_redirect_step_v4(c); return;
    shared_BA98_1:;
    RAM8(0x001F) = a_ba982;
    RAM8(0x001E) = 0;
    RAM8(0x001D)++;
    uint8_t value25 = RAM8(0x001D);
    r->a = (a_hi_ba982 << 8) | a_ba982;
    r->c = 1;
    r->z = value25 == 0;
    r->n = value25 & 0x80;
    r->v = overflow_ba982;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_ba982;
    r->d = decimal_ba982;
    test_actor_vertical_footprint_and_redirect_step_v3(c); return;
    shared_BA86_2:;
    RAM16_SET(0x001E, 0);
    a_hi_ba883 = a_hi_ba863;
    y_ba883 = y_ba863;
    zero_ba883 = zero_ba863;
    negative_ba883 = negative_ba863;
    overflow_ba883 = overflow_ba863;
    irq_disable_ba883 = irq_disable_ba863;
    decimal_ba883 = decimal_ba863;
    goto shared_BA88_2;
    shared_BA86_3:;
    RAM16_SET(0x001E, 0);
    a_hi_ba884 = a_hi_ba864;
    y_ba884 = y_ba864;
    zero_ba884 = zero_ba864;
    negative_ba884 = negative_ba864;
    overflow_ba884 = overflow_ba864;
    irq_disable_ba884 = irq_disable_ba864;
    decimal_ba884 = decimal_ba864;
    goto shared_BA88_3;
    shared_BC08:;
    uint8_t value26 = BUS8_RDP(c, (uint16_t)(direct_page_bc08 + 0x1F));
    RAM8(0x0000 + sp0) = value26;
    BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1F), 0);
    r->a = (a_hi_bc08 << 8) | value26;
    r->y = y_bc08;
    r->c = 1;
    r->z = value26 == 0;
    r->n = value26 & 0x80;
    r->v = overflow_bc08;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_bc08;
    r->dp = direct_page_bc08;
    r->i = irq_disable_bc08;
    r->d = decimal_bc08;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 1;
    bool m_ret5 = r->mf;
    uint16_t a_all6 = r->a;
    bool carry_ret6 = r->c;
    if (carry_ret6) {
        if (m_ret5) {
            BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1F), RAM8(0x0000 + sp0));
            uint8_t value28 = BUS8_RDP(c, (uint16_t)(direct_page_bc08 + 0x1E));
            RAM8(0x0000 + sp0) = value28;
            BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1E), 0);
            r->a = (a_all6 >> 8 << 8) | value28;
            r->c = 1;
            r->z = value28 == 0;
            r->n = value28 & 0x80;
            r->mf = 1;
            r->sp -= 1;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 1;
            uint16_t dp_ret3 = r->dp;
            bool m_ret6 = r->mf;
            bool carry_ret7 = r->c;
            if (carry_ret7) {
                if (m_ret6) {
                    uint8_t value29 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1E), 0);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1F), 0);
                    r->c = 1;
                    r->z = value29 == 0;
                    r->n = value29 & 0x80;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
            if (m_ret6) {
                uint8_t value30 = RAM8(0x0000 + sp0);
                r->z = value30 == 0;
                r->n = value30 & 0x80;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            c->fail = 3;
            return;
        }
    }
    if (m_ret5) {
        uint8_t value31 = RAM8(0x0000 + sp0);
        r->z = value31 == 0;
        r->n = value31 & 0x80;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
    shared_BC08_1:;
    uint8_t value32 = BUS8_RDP(c, (uint16_t)(direct_page_bc082 + 0x1F));
    RAM8(0x0000 + sp0) = value32;
    BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1F), 0);
    r->a = (a_hi_bc082 << 8) | value32;
    r->y = y_bc082;
    r->c = 1;
    r->z = value32 == 0;
    r->n = value32 & 0x80;
    r->v = overflow_bc082;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_bc082;
    r->dp = direct_page_bc082;
    r->i = irq_disable_bc082;
    r->d = decimal_bc082;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 1;
    bool m_ret7 = r->mf;
    uint16_t a_all8 = r->a;
    bool carry_ret8 = r->c;
    if (carry_ret8) {
        if (m_ret7) {
            BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1F), RAM8(0x0000 + sp0));
            uint8_t value34 = BUS8_RDP(c, (uint16_t)(direct_page_bc082 + 0x1E));
            RAM8(0x0000 + sp0) = value34;
            BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1E), 0);
            r->a = (a_all8 >> 8 << 8) | value34;
            r->c = 1;
            r->z = value34 == 0;
            r->n = value34 & 0x80;
            r->mf = 1;
            r->sp -= 1;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 1;
            uint16_t dp_ret4 = r->dp;
            bool m_ret8 = r->mf;
            bool carry_ret9 = r->c;
            if (carry_ret9) {
                if (m_ret8) {
                    uint8_t value35 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 0x1E), 0);
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 0x1F), 0);
                    r->c = 1;
                    r->z = value35 == 0;
                    r->n = value35 & 0x80;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
            if (m_ret8) {
                uint8_t value36 = RAM8(0x0000 + sp0);
                r->z = value36 == 0;
                r->n = value36 & 0x80;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            c->fail = 3;
            return;
        }
    }
    if (m_ret7) {
        uint8_t value37 = RAM8(0x0000 + sp0);
        r->z = value37 == 0;
        r->n = value37 & 0x80;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
    shared_BC08_2:;
    uint16_t value38 = BUS16_RDP(c, (uint16_t)(direct_page_bc083 + 0x1F));
    RAM8(0x0000 + sp0) = value38 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value38;
    BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), 0);
    r->a = value38;
    r->y = y_bc083;
    r->c = 1;
    r->z = value38 == 0;
    r->n = value38 & 0x8000;
    r->v = overflow_bc083;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_bc083;
    r->dp = direct_page_bc083;
    r->i = irq_disable_bc083;
    r->d = decimal_bc083;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 2;
    bool m_ret9 = r->mf;
    uint16_t a_all10 = r->a;
    bool carry_ret10 = r->c;
    if (carry_ret10) {
        if (m_ret9) {
            BUS8_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), RAM8(0x0000 + sp0 - 1));
            uint8_t value40 = BUS8_RDP(c, (uint16_t)(direct_page_bc083 + 0x1E));
            RAM8(0x0000 + sp0 - 1) = value40;
            BUS8_SET(c, (uint16_t)(direct_page_bc083 + 0x1E), 0);
            r->a = (a_all10 >> 8 << 8) | value40;
            r->c = 1;
            r->z = value40 == 0;
            r->n = value40 & 0x80;
            r->mf = 1;
            r->sp -= 2;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret5 = r->dp;
            bool m_ret10 = r->mf;
            bool carry_ret11 = r->c;
            if (carry_ret11) {
                if (m_ret10) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value42 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value43 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret5 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret5 + 0x1F), 0);
                    r->a = (value43 << 8) | value42;
                    r->c = 1;
                    r->z = ((value43 << 8) | value42) == 0;
                    r->n = ((value43 << 8) | value42) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret10) {
                c->fail = 3;
                return;
            } else {
                uint8_t value45 = RAM8(0x0000 + sp0 - 1);
                uint8_t value46 = RAM8(0x0000 + sp0);
                r->a = (value46 << 8) | value45;
                r->z = ((value46 << 8) | value45) == 0;
                r->n = ((value46 << 8) | value45) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1));
            uint16_t value49 = BUS16_RDP(c, (uint16_t)(direct_page_bc083 + 0x1E));
            RAM8(0x0000 + sp0) = value49 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)value49;
            BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1E), 0);
            r->a = value49;
            r->c = 1;
            r->z = value49 == 0;
            r->n = value49 & 0x8000;
            r->mf = 0;
            r->sp -= 2;
            if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret6 = r->dp;
            bool m_ret11 = r->mf;
            bool carry_ret12 = r->c;
            if (carry_ret12) {
                if (m_ret11) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value51 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value52 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret6 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret6 + 0x1F), 0);
                    r->a = (value52 << 8) | value51;
                    r->c = 1;
                    r->z = ((value52 << 8) | value51) == 0;
                    r->n = ((value52 << 8) | value51) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret11) {
                c->fail = 3;
                return;
            } else {
                uint8_t value54 = RAM8(0x0000 + sp0 - 1);
                uint8_t value55 = RAM8(0x0000 + sp0);
                r->a = (value55 << 8) | value54;
                r->z = ((value55 << 8) | value54) == 0;
                r->n = ((value55 << 8) | value54) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
    if (m_ret9) {
        c->fail = 3;
        return;
    } else {
        uint8_t value57 = RAM8(0x0000 + sp0 - 1);
        uint8_t value58 = RAM8(0x0000 + sp0);
        r->a = (value58 << 8) | value57;
        r->z = ((value58 << 8) | value57) == 0;
        r->n = ((value58 << 8) | value57) & 0x8000;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    shared_BC08_3:;
    uint16_t value59 = BUS16_RDP(c, (uint16_t)(direct_page_bc084 + 0x1F));
    RAM8(0x0000 + sp0) = value59 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value59;
    BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), 0);
    r->a = value59;
    r->y = y_bc084;
    r->c = 1;
    r->z = value59 == 0;
    r->n = value59 & 0x8000;
    r->v = overflow_bc084;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_bc084;
    r->dp = direct_page_bc084;
    r->i = irq_disable_bc084;
    r->d = decimal_bc084;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 2;
    bool m_ret12 = r->mf;
    uint16_t a_all13 = r->a;
    bool carry_ret13 = r->c;
    if (carry_ret13) {
        if (m_ret12) {
            BUS8_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), RAM8(0x0000 + sp0 - 1));
            uint8_t value61 = BUS8_RDP(c, (uint16_t)(direct_page_bc084 + 0x1E));
            RAM8(0x0000 + sp0 - 1) = value61;
            BUS8_SET(c, (uint16_t)(direct_page_bc084 + 0x1E), 0);
            r->a = (a_all13 >> 8 << 8) | value61;
            r->c = 1;
            r->z = value61 == 0;
            r->n = value61 & 0x80;
            r->mf = 1;
            r->sp -= 2;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret7 = r->dp;
            bool m_ret13 = r->mf;
            bool carry_ret14 = r->c;
            if (carry_ret14) {
                if (m_ret13) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value63 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value64 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret7 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret7 + 0x1F), 0);
                    r->a = (value64 << 8) | value63;
                    r->c = 1;
                    r->z = ((value64 << 8) | value63) == 0;
                    r->n = ((value64 << 8) | value63) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret13) {
                c->fail = 3;
                return;
            } else {
                uint8_t value66 = RAM8(0x0000 + sp0 - 1);
                uint8_t value67 = RAM8(0x0000 + sp0);
                r->a = (value67 << 8) | value66;
                r->z = ((value67 << 8) | value66) == 0;
                r->n = ((value67 << 8) | value66) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1));
            uint16_t value70 = BUS16_RDP(c, (uint16_t)(direct_page_bc084 + 0x1E));
            RAM8(0x0000 + sp0) = value70 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)value70;
            BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1E), 0);
            r->a = value70;
            r->c = 1;
            r->z = value70 == 0;
            r->n = value70 & 0x8000;
            r->mf = 0;
            r->sp -= 2;
            if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret8 = r->dp;
            bool m_ret14 = r->mf;
            bool carry_ret15 = r->c;
            if (carry_ret15) {
                if (m_ret14) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value72 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value73 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret8 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret8 + 0x1F), 0);
                    r->a = (value73 << 8) | value72;
                    r->c = 1;
                    r->z = ((value73 << 8) | value72) == 0;
                    r->n = ((value73 << 8) | value72) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret14) {
                c->fail = 3;
                return;
            } else {
                uint8_t value75 = RAM8(0x0000 + sp0 - 1);
                uint8_t value76 = RAM8(0x0000 + sp0);
                r->a = (value76 << 8) | value75;
                r->z = ((value76 << 8) | value75) == 0;
                r->n = ((value76 << 8) | value75) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
    if (m_ret12) {
        c->fail = 3;
        return;
    } else {
        uint8_t value78 = RAM8(0x0000 + sp0 - 1);
        uint8_t value79 = RAM8(0x0000 + sp0);
        r->a = (value79 << 8) | value78;
        r->z = ((value79 << 8) | value78) == 0;
        r->n = ((value79 << 8) | value78) & 0x8000;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC1B9EA, SOM_RTS, "gen", test_actor_horizontal_footprint_and_redirect_step, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 43, 1, 0, 578, 316)

/* C1BAE2 test_actor_vertical_footprint_and_redirect_step   [class A, 306 bytes, 169 instructions]
 * Source: src/rom/test_actor_horizontal_footprint_and_redirect_step.s
 * Subroutine of test_actor_horizontal_footprint_and_redirect_step, translated in place.
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void test_actor_vertical_footprint_and_redirect_step(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}

/* C1BAE2 test_actor_vertical_footprint_and_redirect_step_v2   [class A, 306 bytes, 169 instructions]
 * Source: src/rom/test_actor_horizontal_footprint_and_redirect_step.s
 * Subroutine of test_actor_horizontal_footprint_and_redirect_step, translated in place.
 * Entry: M=16 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void test_actor_vertical_footprint_and_redirect_step_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x10) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}

/* C1BAE2 test_actor_vertical_footprint_and_redirect_step_v3   [class A, 306 bytes, 169 instructions]
 * Source: src/rom/test_actor_horizontal_footprint_and_redirect_step.s
 * Subroutine of test_actor_horizontal_footprint_and_redirect_step, translated in place.
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void test_actor_vertical_footprint_and_redirect_step_v3(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_bb89 = 0;
    uint8_t a_hi_bb89 = 0;
    uint8_t x_bb89 = 0;
    uint8_t y_bb89 = 0;
    bool zero_bb89 = 0;
    bool negative_bb89 = 0;
    bool overflow_bb89 = 0;
    bool irq_disable_bb89 = 0;
    bool decimal_bb89 = 0;
    uint8_t a_bb892 = 0;
    uint8_t a_hi_bb892 = 0;
    uint16_t x_bb892 = 0;
    uint16_t y_bb892 = 0;
    bool zero_bb892 = 0;
    bool negative_bb892 = 0;
    bool overflow_bb892 = 0;
    bool irq_disable_bb892 = 0;
    bool decimal_bb892 = 0;
    uint8_t a_bb893 = 0;
    uint8_t a_hi_bb893 = 0;
    uint8_t x_bb893 = 0;
    uint8_t y_bb893 = 0;
    bool zero_bb893 = 0;
    bool negative_bb893 = 0;
    bool overflow_bb893 = 0;
    bool irq_disable_bb893 = 0;
    bool decimal_bb893 = 0;
    uint8_t a_bb894 = 0;
    uint8_t a_hi_bb894 = 0;
    uint16_t x_bb894 = 0;
    uint16_t y_bb894 = 0;
    bool zero_bb894 = 0;
    bool negative_bb894 = 0;
    bool overflow_bb894 = 0;
    bool irq_disable_bb894 = 0;
    bool decimal_bb894 = 0;
    uint8_t a_bb87 = 0;
    uint8_t a_hi_bb87 = 0;
    uint8_t x_bb87 = 0;
    uint8_t y_bb87 = 0;
    bool zero_bb87 = 0;
    bool negative_bb87 = 0;
    bool overflow_bb87 = 0;
    bool irq_disable_bb87 = 0;
    bool decimal_bb87 = 0;
    uint8_t a_bb872 = 0;
    uint8_t a_hi_bb872 = 0;
    uint16_t x_bb872 = 0;
    uint16_t y_bb872 = 0;
    bool zero_bb872 = 0;
    bool negative_bb872 = 0;
    bool overflow_bb872 = 0;
    bool irq_disable_bb872 = 0;
    bool decimal_bb872 = 0;
    uint8_t a_bbfb = 0;
    uint8_t a_hi_bbfb = 0;
    uint8_t x_bbfb = 0;
    uint8_t y_bbfb = 0;
    bool zero_bbfb = 0;
    bool negative_bbfb = 0;
    bool overflow_bbfb = 0;
    bool irq_disable_bbfb = 0;
    bool decimal_bbfb = 0;
    uint8_t a_bbfb2 = 0;
    uint8_t a_hi_bbfb2 = 0;
    uint16_t x_bbfb2 = 0;
    uint16_t y_bbfb2 = 0;
    bool zero_bbfb2 = 0;
    bool negative_bbfb2 = 0;
    bool overflow_bbfb2 = 0;
    bool irq_disable_bbfb2 = 0;
    bool decimal_bbfb2 = 0;
    uint8_t a_bb99 = 0;
    uint8_t a_hi_bb99 = 0;
    bool irq_disable_bb99 = 0;
    bool decimal_bb99 = 0;
    uint8_t a_bb992 = 0;
    uint8_t a_hi_bb992 = 0;
    bool irq_disable_bb992 = 0;
    bool decimal_bb992 = 0;
    uint8_t a_bb873 = 0;
    uint8_t a_hi_bb873 = 0;
    uint8_t x_bb873 = 0;
    uint8_t y_bb873 = 0;
    bool zero_bb873 = 0;
    bool negative_bb873 = 0;
    bool overflow_bb873 = 0;
    bool irq_disable_bb873 = 0;
    bool decimal_bb873 = 0;
    uint8_t a_bb874 = 0;
    uint8_t a_hi_bb874 = 0;
    uint16_t x_bb874 = 0;
    uint16_t y_bb874 = 0;
    bool zero_bb874 = 0;
    bool negative_bb874 = 0;
    bool overflow_bb874 = 0;
    bool irq_disable_bb874 = 0;
    bool decimal_bb874 = 0;
    uint8_t a_hi_bc08 = 0;
    uint8_t x_bc08 = 0;
    uint8_t y_bc08 = 0;
    bool overflow_bc08 = 0;
    uint16_t direct_page_bc08 = 0;
    uint8_t data_bank_bc08 = 0;
    bool irq_disable_bc08 = 0;
    bool decimal_bc08 = 0;
    uint8_t a_hi_bc082 = 0;
    uint16_t x_bc082 = 0;
    uint16_t y_bc082 = 0;
    bool overflow_bc082 = 0;
    uint16_t direct_page_bc082 = 0;
    uint8_t data_bank_bc082 = 0;
    bool irq_disable_bc082 = 0;
    bool decimal_bc082 = 0;
    uint8_t a_hi_bc083 = 0;
    uint8_t x_bc083 = 0;
    uint8_t y_bc083 = 0;
    bool overflow_bc083 = 0;
    uint16_t direct_page_bc083 = 0;
    uint8_t data_bank_bc083 = 0;
    bool irq_disable_bc083 = 0;
    bool decimal_bc083 = 0;
    uint8_t a_hi_bc084 = 0;
    uint16_t x_bc084 = 0;
    uint16_t y_bc084 = 0;
    bool overflow_bc084 = 0;
    uint16_t direct_page_bc084 = 0;
    uint8_t data_bank_bc084 = 0;
    bool irq_disable_bc084 = 0;
    bool decimal_bc084 = 0;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = RAM8(0x001F);
    uint8_t a3;
    uint8_t a_hi3;
    if ((uint8_t)(value + 4) >= 0x80) {
        uint16_t value2 = RAM16(0x0014);
        uint8_t a1;
        uint8_t a_hi1;
        if (!((uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) & 0x8000)) {
            a1 = (uint8_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1);
            a_hi1 = (uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) >> 8;
        } else {
            uint16_t value3 = RAM16(0x00C2);
            a1 = (uint8_t)((uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) + value3);
            a_hi1 = (uint16_t)((uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) + value3) >> 8;
        }
        a3 = a1;
        a_hi3 = a_hi1;
    } else {
        uint16_t value4 = RAM16(0x0014);
        uint16_t value5 = RAM16(0x00C2);
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) < value5) {
            a2 = (uint8_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4);
            a_hi2 = (uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) >> 8;
        } else {
            a2 = (uint8_t)((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) - value5 - ((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) >= value5 ^ 1));
            a_hi2 = (uint16_t)((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) - value5 - ((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) >= value5 ^ 1)) >> 8;
        }
        a3 = a2;
        a_hi3 = a_hi2;
    }
    RAM16_SET(0x0004, (a_hi3 << 8) | a3);
    RAM16_SET(0x0008, (((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1);
    uint8_t value6 = RAM8(0x001E);
    uint8_t a4;
    if (!(value6 & 0x80)) {
        a4 = value6;
    } else {
        a4 = (uint8_t)((value6 ^ 0x7F) + 1);
    }
    RAM8(0x0000) = a4;
    uint8_t value7 = RAM8(0x001A);
    uint8_t value8 = RAM8(0x0000);
    uint8_t a7;
    uint8_t a_hi6;
    if (!((uint8_t)((value7 >> 1) + value8) & 0x80)) {
        uint16_t value9 = RAM16(0x0012);
        uint16_t value10 = RAM16(0x00C0);
        uint8_t a5;
        uint8_t a_hi4;
        if ((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9) < value10) {
            a5 = (uint8_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9);
            a_hi4 = (uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9) >> 8;
        } else {
            a5 = (uint8_t)((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9) - value10 - ((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9) >= value10 ^ 1));
            a_hi4 = (uint16_t)((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9) - value10 - ((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9) >= value10 ^ 1)) >> 8;
        }
        a7 = a5;
        a_hi6 = a_hi4;
    } else {
        uint16_t value11 = RAM16(0x0012);
        uint8_t a6;
        uint8_t a_hi5;
        if (!((uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8) | 0xFF00) + value11) & 0x8000)) {
            a6 = (uint8_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8) | 0xFF00) + value11);
            a_hi5 = (uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8) | 0xFF00) + value11) >> 8;
        } else {
            uint16_t value12 = RAM16(0x00C0);
            a6 = (uint8_t)((uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8) | 0xFF00) + value11) + value12);
            a_hi5 = (uint16_t)((uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8) | 0xFF00) + value11) + value12) >> 8;
        }
        a7 = a6;
        a_hi6 = a_hi5;
    }
    RAM8(0x0000 + sp0 - 1) = a_hi6;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)((a_hi6 << 8) | a7);
    RAM16_SET(0x0004, ((RAM8(0x0004) << 8) | a7) & 0x0F0F);
    uint16_t value14 = RAM16(0x0008);
    RAM16_SET(0x0008, ((((a_hi6 << 8) | a7) >> 4) & 0x7F) | value14);
    uint16_t value15 = BUS16_RDL(c, (RAM8(0x000C) << 0x10) + RAM16(0x000A) + (((((a_hi6 << 8) | a7) >> 4) & 0x7F) | value14), RAM8(0x000C));
    uint8_t value16 = BUS8_RDL(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value15 & 0xFF) << 1 << 1), RAM8(0x000F));
    RAM8(0x0007) = value16;
    uint8_t value17 = BUS8_RDL(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + (((value15 & 0xFF) << 1 << 1) + 2), RAM8(0x000F));
    RAM8(0x0006) = value17;
    if ((value17 & 0xF0) != 0x10) {
        RAM8(0x0006) = 0;
    }
    r->a = (value15 & 0xFF) << 1 << 1 >> 8 << 8 | (value17 & 0xF0);
    r->y = ((value15 & 0xFF) << 1 << 1) + 2;
    r->c = (value17 & 0xF0) >= 0x10;
    r->z = (value17 & 0xF0) == 0x10;
    r->n = (uint8_t)((value17 & 0xF0) - 0x10) & 0x80;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBB7A, 0xC1BC37); GUARD_JSR(c, sp_call, 0xBB7A); } /* test_horizontal_terrain_shape_and_preceding_cells */
    r->sp += 1;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    if (carry_ret) {
        uint8_t value18 = RAM8(0x0000 + sp0);
        if (value18 & 0x01) {
            if (value18 & 0x20) {
                if (value18 & 0x10) {
                    a_bb89 = (uint8_t)a_all;
                    a_hi_bb89 = a_all >> 8;
                    x_bb89 = (uint8_t)x;
                    y_bb89 = (uint8_t)y_ret;
                    zero_bb89 = value18 & 0x02;
                    negative_bb89 = value18 & 0x80;
                    overflow_bb89 = value18 & 0x40;
                    irq_disable_bb89 = value18 & 0x04;
                    decimal_bb89 = value18 & 0x08;
                    goto shared_BB89;
                } else {
                    a_bb892 = (uint8_t)a_all;
                    a_hi_bb892 = a_all >> 8;
                    x_bb892 = x;
                    y_bb892 = y_ret;
                    zero_bb892 = value18 & 0x02;
                    negative_bb892 = value18 & 0x80;
                    overflow_bb892 = value18 & 0x40;
                    irq_disable_bb892 = value18 & 0x04;
                    decimal_bb892 = value18 & 0x08;
                    goto shared_BB89_1;
                }
            } else {
                if (value18 & 0x10) {
                    a_bb893 = (uint8_t)a_all;
                    a_hi_bb893 = a_all >> 8;
                    x_bb893 = (uint8_t)x;
                    y_bb893 = (uint8_t)y_ret;
                    zero_bb893 = value18 & 0x02;
                    negative_bb893 = value18 & 0x80;
                    overflow_bb893 = value18 & 0x40;
                    irq_disable_bb893 = value18 & 0x04;
                    decimal_bb893 = value18 & 0x08;
                    goto shared_BB89_2;
                } else {
                    a_bb894 = (uint8_t)a_all;
                    a_hi_bb894 = a_all >> 8;
                    x_bb894 = x;
                    y_bb894 = y_ret;
                    zero_bb894 = value18 & 0x02;
                    negative_bb894 = value18 & 0x80;
                    overflow_bb894 = value18 & 0x40;
                    irq_disable_bb894 = value18 & 0x04;
                    decimal_bb894 = value18 & 0x08;
                    goto shared_BB89_3;
                }
            }
        }
        if (value18 & 0x20) {
            uint8_t value19 = RAM8(0x0002);
            if (value19 != 0) {
                if (value19 < 8) {
                    uint8_t value20 = RAM8(0x001F);
                    if (value20 & 0x80) {
                        if (value19 != 5) {
                            if (value19 != 6) {
                                if (value18 & 0x10) {
                                    a_bb87 = value19;
                                    a_hi_bb87 = a_all >> 8;
                                    x_bb87 = (uint8_t)x;
                                    y_bb87 = (uint8_t)y_ret;
                                    zero_bb87 = value19 == 6;
                                    negative_bb87 = (uint8_t)(value19 - 6) & 0x80;
                                    overflow_bb87 = value20 & 0x40;
                                    irq_disable_bb87 = value18 & 0x04;
                                    decimal_bb87 = value18 & 0x08;
                                    goto shared_BB87;
                                } else {
                                    a_bb872 = value19;
                                    a_hi_bb872 = a_all >> 8;
                                    x_bb872 = x;
                                    y_bb872 = y_ret;
                                    zero_bb872 = value19 == 6;
                                    negative_bb872 = (uint8_t)(value19 - 6) & 0x80;
                                    overflow_bb872 = value20 & 0x40;
                                    irq_disable_bb872 = value18 & 0x04;
                                    decimal_bb872 = value18 & 0x08;
                                    goto shared_BB87_1;
                                }
                            }
                            RAM8(0x001E) = value20 ^ 0x80;
                            RAM8(0x001C)++;
                            if (value18 & 0x10) {
                                a_bbfb = value20 ^ 0x80;
                                a_hi_bbfb = a_all >> 8;
                                x_bbfb = (uint8_t)x;
                                y_bbfb = (uint8_t)y_ret;
                                zero_bbfb = RAM8(0x001C) == 0;
                                negative_bbfb = RAM8(0x001C) & 0x80;
                                overflow_bbfb = value20 & 0x40;
                                irq_disable_bbfb = value18 & 0x04;
                                decimal_bbfb = value18 & 0x08;
                                goto shared_BBFB;
                            } else {
                                a_bbfb2 = value20 ^ 0x80;
                                a_hi_bbfb2 = a_all >> 8;
                                x_bbfb2 = x;
                                y_bbfb2 = y_ret;
                                zero_bbfb2 = RAM8(0x001C) == 0;
                                negative_bbfb2 = RAM8(0x001C) & 0x80;
                                overflow_bbfb2 = value20 & 0x40;
                                irq_disable_bbfb2 = value18 & 0x04;
                                decimal_bbfb2 = value18 & 0x08;
                                goto shared_BBFB_1;
                            }
                        }
                        RAM8(0x001E) = value20;
                        RAM8(0x001C)++;
                        if (value18 & 0x10) {
                            a_bbfb = value20;
                            a_hi_bbfb = a_all >> 8;
                            x_bbfb = (uint8_t)x;
                            y_bbfb = (uint8_t)y_ret;
                            zero_bbfb = RAM8(0x001C) == 0;
                            negative_bbfb = RAM8(0x001C) & 0x80;
                            overflow_bbfb = value20 & 0x40;
                            irq_disable_bbfb = value18 & 0x04;
                            decimal_bbfb = value18 & 0x08;
                            goto shared_BBFB;
                        } else {
                            a_bbfb2 = value20;
                            a_hi_bbfb2 = a_all >> 8;
                            x_bbfb2 = x;
                            y_bbfb2 = y_ret;
                            zero_bbfb2 = RAM8(0x001C) == 0;
                            negative_bbfb2 = RAM8(0x001C) & 0x80;
                            overflow_bbfb2 = value20 & 0x40;
                            irq_disable_bbfb2 = value18 & 0x04;
                            decimal_bbfb2 = value18 & 0x08;
                            goto shared_BBFB_1;
                        }
                    }
                    if (value19 != 4) {
                        if (value19 != 7) {
                            if (value18 & 0x10) {
                                a_bb87 = value19;
                                a_hi_bb87 = a_all >> 8;
                                x_bb87 = (uint8_t)x;
                                y_bb87 = (uint8_t)y_ret;
                                zero_bb87 = value19 == 7;
                                negative_bb87 = (uint8_t)(value19 - 7) & 0x80;
                                overflow_bb87 = value20 & 0x40;
                                irq_disable_bb87 = value18 & 0x04;
                                decimal_bb87 = value18 & 0x08;
                                goto shared_BB87;
                            } else {
                                a_bb872 = value19;
                                a_hi_bb872 = a_all >> 8;
                                x_bb872 = x;
                                y_bb872 = y_ret;
                                zero_bb872 = value19 == 7;
                                negative_bb872 = (uint8_t)(value19 - 7) & 0x80;
                                overflow_bb872 = value20 & 0x40;
                                irq_disable_bb872 = value18 & 0x04;
                                decimal_bb872 = value18 & 0x08;
                                goto shared_BB87_1;
                            }
                        }
                        RAM8(0x001E) = value20 ^ 0x80;
                        RAM8(0x001C)++;
                        if (value18 & 0x10) {
                            a_bbfb = value20 ^ 0x80;
                            a_hi_bbfb = a_all >> 8;
                            x_bbfb = (uint8_t)x;
                            y_bbfb = (uint8_t)y_ret;
                            zero_bbfb = RAM8(0x001C) == 0;
                            negative_bbfb = RAM8(0x001C) & 0x80;
                            overflow_bbfb = value20 & 0x40;
                            irq_disable_bbfb = value18 & 0x04;
                            decimal_bbfb = value18 & 0x08;
                            goto shared_BBFB;
                        } else {
                            a_bbfb2 = value20 ^ 0x80;
                            a_hi_bbfb2 = a_all >> 8;
                            x_bbfb2 = x;
                            y_bbfb2 = y_ret;
                            zero_bbfb2 = RAM8(0x001C) == 0;
                            negative_bbfb2 = RAM8(0x001C) & 0x80;
                            overflow_bbfb2 = value20 & 0x40;
                            irq_disable_bbfb2 = value18 & 0x04;
                            decimal_bbfb2 = value18 & 0x08;
                            goto shared_BBFB_1;
                        }
                    }
                    RAM8(0x001E) = value20;
                    RAM8(0x001C)++;
                    if (value18 & 0x10) {
                        a_bbfb = value20;
                        a_hi_bbfb = a_all >> 8;
                        x_bbfb = (uint8_t)x;
                        y_bbfb = (uint8_t)y_ret;
                        zero_bbfb = RAM8(0x001C) == 0;
                        negative_bbfb = RAM8(0x001C) & 0x80;
                        overflow_bbfb = value20 & 0x40;
                        irq_disable_bbfb = value18 & 0x04;
                        decimal_bbfb = value18 & 0x08;
                        goto shared_BBFB;
                    } else {
                        a_bbfb2 = value20;
                        a_hi_bbfb2 = a_all >> 8;
                        x_bbfb2 = x;
                        y_bbfb2 = y_ret;
                        zero_bbfb2 = RAM8(0x001C) == 0;
                        negative_bbfb2 = RAM8(0x001C) & 0x80;
                        overflow_bbfb2 = value20 & 0x40;
                        irq_disable_bbfb2 = value18 & 0x04;
                        decimal_bbfb2 = value18 & 0x08;
                        goto shared_BBFB_1;
                    }
                }
                if (value19 == 8) {
                    uint8_t value21 = RAM8(0x001F);
                    if (value18 & 0x10) {
                        a_bb99 = value21;
                        a_hi_bb99 = a_all >> 8;
                        irq_disable_bb99 = value18 & 0x04;
                        decimal_bb99 = value18 & 0x08;
                        goto shared_BB99;
                    } else {
                        a_bb992 = value21;
                        a_hi_bb992 = a_all >> 8;
                        irq_disable_bb992 = value18 & 0x04;
                        decimal_bb992 = value18 & 0x08;
                        goto shared_BB99_1;
                    }
                }
                if (value19 != 9) {
                    if (value18 & 0x10) {
                        a_bb87 = value19;
                        a_hi_bb87 = a_all >> 8;
                        x_bb87 = (uint8_t)x;
                        y_bb87 = (uint8_t)y_ret;
                        zero_bb87 = value19 == 9;
                        negative_bb87 = (uint8_t)(value19 - 9) & 0x80;
                        overflow_bb87 = value18 & 0x40;
                        irq_disable_bb87 = value18 & 0x04;
                        decimal_bb87 = value18 & 0x08;
                        goto shared_BB87;
                    } else {
                        a_bb872 = value19;
                        a_hi_bb872 = a_all >> 8;
                        x_bb872 = x;
                        y_bb872 = y_ret;
                        zero_bb872 = value19 == 9;
                        negative_bb872 = (uint8_t)(value19 - 9) & 0x80;
                        overflow_bb872 = value18 & 0x40;
                        irq_disable_bb872 = value18 & 0x04;
                        decimal_bb872 = value18 & 0x08;
                        goto shared_BB87_1;
                    }
                }
                uint8_t value22 = RAM8(0x001F);
                if (value18 & 0x10) {
                    a_bb99 = value22 ^ 0x80;
                    a_hi_bb99 = a_all >> 8;
                    irq_disable_bb99 = value18 & 0x04;
                    decimal_bb99 = value18 & 0x08;
                    goto shared_BB99;
                } else {
                    a_bb992 = value22 ^ 0x80;
                    a_hi_bb992 = a_all >> 8;
                    irq_disable_bb992 = value18 & 0x04;
                    decimal_bb992 = value18 & 0x08;
                    goto shared_BB99_1;
                }
            }
            if (value18 & 0x10) {
                a_bb87 = value19;
                a_hi_bb87 = a_all >> 8;
                x_bb87 = (uint8_t)x;
                y_bb87 = (uint8_t)y_ret;
                zero_bb87 = value19 == 0;
                negative_bb87 = value19 & 0x80;
                overflow_bb87 = value18 & 0x40;
                irq_disable_bb87 = value18 & 0x04;
                decimal_bb87 = value18 & 0x08;
                goto shared_BB87;
            } else {
                a_bb872 = value19;
                a_hi_bb872 = a_all >> 8;
                x_bb872 = x;
                y_bb872 = y_ret;
                zero_bb872 = value19 == 0;
                negative_bb872 = value19 & 0x80;
                overflow_bb872 = value18 & 0x40;
                irq_disable_bb872 = value18 & 0x04;
                decimal_bb872 = value18 & 0x08;
                goto shared_BB87_1;
            }
        } else {
            uint16_t value23 = RAM16(0x0002);
            if (value23 != 0) {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
            if (value18 & 0x10) {
                a_bb873 = (uint8_t)value23;
                a_hi_bb873 = value23 >> 8;
                x_bb873 = (uint8_t)x;
                y_bb873 = (uint8_t)y_ret;
                zero_bb873 = value23 == 0;
                negative_bb873 = value23 & 0x8000;
                overflow_bb873 = value18 & 0x40;
                irq_disable_bb873 = value18 & 0x04;
                decimal_bb873 = value18 & 0x08;
                goto shared_BB87_2;
            } else {
                a_bb874 = (uint8_t)value23;
                a_hi_bb874 = value23 >> 8;
                x_bb874 = x;
                y_bb874 = y_ret;
                zero_bb874 = value23 == 0;
                negative_bb874 = value23 & 0x8000;
                overflow_bb874 = value18 & 0x40;
                irq_disable_bb874 = value18 & 0x04;
                decimal_bb874 = value18 & 0x08;
                goto shared_BB87_3;
            }
        }
    }
    uint8_t value24 = RAM8(0x0000 + sp0);
    r->c = 0;
    r->z = value24 & 0x02;
    r->n = value24 & 0x80;
    r->v = value24 & 0x40;
    r->mf = value24 & 0x20;
    r->xf = value24 & 0x10;
    r->i = value24 & 0x04;
    r->d = value24 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BB89:;
    r->a = (a_hi_bb89 << 8) | a_bb89;
    r->x = x_bb89;
    r->y = y_bb89;
    r->c = 1;
    r->z = zero_bb89;
    r->n = negative_bb89;
    r->v = overflow_bb89;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bb89;
    r->d = decimal_bb89;
    RETURN_RTS(c);
    shared_BB89_1:;
    r->a = (a_hi_bb892 << 8) | a_bb892;
    r->x = x_bb892;
    r->y = y_bb892;
    r->c = 1;
    r->z = zero_bb892;
    r->n = negative_bb892;
    r->v = overflow_bb892;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bb892;
    r->d = decimal_bb892;
    RETURN_RTS(c);
    shared_BB89_2:;
    r->a = (a_hi_bb893 << 8) | a_bb893;
    r->x = x_bb893;
    r->y = y_bb893;
    r->c = 1;
    r->z = zero_bb893;
    r->n = negative_bb893;
    r->v = overflow_bb893;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bb893;
    r->d = decimal_bb893;
    RETURN_RTS(c);
    shared_BB89_3:;
    r->a = (a_hi_bb894 << 8) | a_bb894;
    r->x = x_bb894;
    r->y = y_bb894;
    r->c = 1;
    r->z = zero_bb894;
    r->n = negative_bb894;
    r->v = overflow_bb894;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bb894;
    r->d = decimal_bb894;
    RETURN_RTS(c);
    shared_BB87:;
    RAM8(0x001F) = 0;
    a_bb89 = a_bb87;
    a_hi_bb89 = a_hi_bb87;
    x_bb89 = x_bb87;
    y_bb89 = y_bb87;
    zero_bb89 = zero_bb87;
    negative_bb89 = negative_bb87;
    overflow_bb89 = overflow_bb87;
    irq_disable_bb89 = irq_disable_bb87;
    decimal_bb89 = decimal_bb87;
    goto shared_BB89;
    shared_BB87_1:;
    RAM8(0x001F) = 0;
    a_bb892 = a_bb872;
    a_hi_bb892 = a_hi_bb872;
    x_bb892 = x_bb872;
    y_bb892 = y_bb872;
    zero_bb892 = zero_bb872;
    negative_bb892 = negative_bb872;
    overflow_bb892 = overflow_bb872;
    irq_disable_bb892 = irq_disable_bb872;
    decimal_bb892 = decimal_bb872;
    goto shared_BB89_1;
    shared_BBFB:;
    r->a = (a_hi_bbfb << 8) | a_bbfb;
    r->x = x_bbfb;
    r->y = y_bbfb;
    r->c = 1;
    r->z = zero_bbfb;
    r->n = negative_bbfb;
    r->v = overflow_bbfb;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bbfb;
    r->d = decimal_bbfb;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBBFE, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBBFE); } /* test_actor_horizontal_footprint_and_redirect_step */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    if (carry_ret2) {
        if (m_ret) {
            if (x_ret) {
                a_hi_bc08 = a_all2 >> 8;
                x_bc08 = x_bbfb;
                y_bc08 = (uint8_t)y_ret2;
                overflow_bc08 = overflow_ret2;
                direct_page_bc08 = 0;
                data_bank_bc08 = 0x7E;
                irq_disable_bc08 = irq_disable_bbfb;
                decimal_bc08 = decimal_bbfb;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all2 >> 8;
                x_bc082 = x_bbfb;
                y_bc082 = y_ret2;
                overflow_bc082 = overflow_ret2;
                direct_page_bc082 = 0;
                data_bank_bc082 = 0x7E;
                irq_disable_bc082 = irq_disable_bbfb;
                decimal_bc082 = decimal_bbfb;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret) {
                a_hi_bc083 = a_all2 >> 8;
                x_bc083 = x_bbfb;
                y_bc083 = (uint8_t)y_ret2;
                overflow_bc083 = overflow_ret2;
                direct_page_bc083 = 0;
                data_bank_bc083 = 0x7E;
                irq_disable_bc083 = irq_disable_bbfb;
                decimal_bc083 = decimal_bbfb;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all2 >> 8;
                x_bc084 = x_bbfb;
                y_bc084 = y_ret2;
                overflow_bc084 = overflow_ret2;
                direct_page_bc084 = 0;
                data_bank_bc084 = 0x7E;
                irq_disable_bc084 = irq_disable_bbfb;
                decimal_bc084 = decimal_bbfb;
                goto shared_BC08_3;
            }
        }
    }
    r->c = 1;
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); }
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret2 = r->mf;
    bool x_ret2 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    if (carry_ret3) {
        if (m_ret2) {
            if (x_ret2) {
                a_hi_bc08 = a_all3 >> 8;
                x_bc08 = x_bbfb;
                y_bc08 = (uint8_t)y_ret3;
                overflow_bc08 = overflow_ret3;
                direct_page_bc08 = dp_ret;
                data_bank_bc08 = db_ret;
                irq_disable_bc08 = irq_disable_bbfb;
                decimal_bc08 = decimal_bbfb;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all3 >> 8;
                x_bc082 = x_bbfb;
                y_bc082 = y_ret3;
                overflow_bc082 = overflow_ret3;
                direct_page_bc082 = dp_ret;
                data_bank_bc082 = db_ret;
                irq_disable_bc082 = irq_disable_bbfb;
                decimal_bc082 = decimal_bbfb;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret2) {
                a_hi_bc083 = a_all3 >> 8;
                x_bc083 = x_bbfb;
                y_bc083 = (uint8_t)y_ret3;
                overflow_bc083 = overflow_ret3;
                direct_page_bc083 = dp_ret;
                data_bank_bc083 = db_ret;
                irq_disable_bc083 = irq_disable_bbfb;
                decimal_bc083 = decimal_bbfb;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all3 >> 8;
                x_bc084 = x_bbfb;
                y_bc084 = y_ret3;
                overflow_bc084 = overflow_ret3;
                direct_page_bc084 = dp_ret;
                data_bank_bc084 = db_ret;
                irq_disable_bc084 = irq_disable_bbfb;
                decimal_bc084 = decimal_bbfb;
                goto shared_BC08_3;
            }
        }
    }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BBFB_1:;
    r->a = (a_hi_bbfb2 << 8) | a_bbfb2;
    r->x = x_bbfb2;
    r->y = y_bbfb2;
    r->c = 1;
    r->z = zero_bbfb2;
    r->n = negative_bbfb2;
    r->v = overflow_bbfb2;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bbfb2;
    r->d = decimal_bbfb2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBBFE, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBBFE); } /* test_actor_horizontal_footprint_and_redirect_step */
    bool m_ret3 = r->mf;
    bool x_ret3 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t y_ret4 = r->y;
    bool carry_ret4 = r->c;
    bool overflow_ret4 = r->v;
    if (carry_ret4) {
        if (m_ret3) {
            if (x_ret3) {
                a_hi_bc08 = a_all4 >> 8;
                x_bc08 = (uint8_t)x_bbfb2;
                y_bc08 = (uint8_t)y_ret4;
                overflow_bc08 = overflow_ret4;
                direct_page_bc08 = 0;
                data_bank_bc08 = 0x7E;
                irq_disable_bc08 = irq_disable_bbfb2;
                decimal_bc08 = decimal_bbfb2;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all4 >> 8;
                x_bc082 = x_bbfb2;
                y_bc082 = y_ret4;
                overflow_bc082 = overflow_ret4;
                direct_page_bc082 = 0;
                data_bank_bc082 = 0x7E;
                irq_disable_bc082 = irq_disable_bbfb2;
                decimal_bc082 = decimal_bbfb2;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret3) {
                a_hi_bc083 = a_all4 >> 8;
                x_bc083 = (uint8_t)x_bbfb2;
                y_bc083 = (uint8_t)y_ret4;
                overflow_bc083 = overflow_ret4;
                direct_page_bc083 = 0;
                data_bank_bc083 = 0x7E;
                irq_disable_bc083 = irq_disable_bbfb2;
                decimal_bc083 = decimal_bbfb2;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all4 >> 8;
                x_bc084 = x_bbfb2;
                y_bc084 = y_ret4;
                overflow_bc084 = overflow_ret4;
                direct_page_bc084 = 0;
                data_bank_bc084 = 0x7E;
                irq_disable_bc084 = irq_disable_bbfb2;
                decimal_bc084 = decimal_bbfb2;
                goto shared_BC08_3;
            }
        }
    }
    r->c = 1;
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); }
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret4 = r->mf;
    bool x_ret4 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t y_ret5 = r->y;
    bool carry_ret5 = r->c;
    bool overflow_ret5 = r->v;
    if (carry_ret5) {
        if (m_ret4) {
            if (x_ret4) {
                a_hi_bc08 = a_all5 >> 8;
                x_bc08 = (uint8_t)x_bbfb2;
                y_bc08 = (uint8_t)y_ret5;
                overflow_bc08 = overflow_ret5;
                direct_page_bc08 = dp_ret2;
                data_bank_bc08 = db_ret2;
                irq_disable_bc08 = irq_disable_bbfb2;
                decimal_bc08 = decimal_bbfb2;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all5 >> 8;
                x_bc082 = x_bbfb2;
                y_bc082 = y_ret5;
                overflow_bc082 = overflow_ret5;
                direct_page_bc082 = dp_ret2;
                data_bank_bc082 = db_ret2;
                irq_disable_bc082 = irq_disable_bbfb2;
                decimal_bc082 = decimal_bbfb2;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret4) {
                a_hi_bc083 = a_all5 >> 8;
                x_bc083 = (uint8_t)x_bbfb2;
                y_bc083 = (uint8_t)y_ret5;
                overflow_bc083 = overflow_ret5;
                direct_page_bc083 = dp_ret2;
                data_bank_bc083 = db_ret2;
                irq_disable_bc083 = irq_disable_bbfb2;
                decimal_bc083 = decimal_bbfb2;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all5 >> 8;
                x_bc084 = x_bbfb2;
                y_bc084 = y_ret5;
                overflow_bc084 = overflow_ret5;
                direct_page_bc084 = dp_ret2;
                data_bank_bc084 = db_ret2;
                irq_disable_bc084 = irq_disable_bbfb2;
                decimal_bc084 = decimal_bbfb2;
                goto shared_BC08_3;
            }
        }
    }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BB99:;
    RAM8(0x001E) = a_bb99;
    RAM8(0x001F) = 0;
    RAM8(0x001C)++;
    r->a = (a_hi_bb99 << 8) | a_bb99;
    r->c = 1;
    r->z = RAM8(0x001C) == 0;
    r->n = RAM8(0x001C) & 0x80;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bb99;
    r->d = decimal_bb99;
    TAIL_CALL(c, 0xC1B9EA, SOM_RTS); /* test_actor_horizontal_footprint_and_redirect_step */
    shared_BB99_1:;
    RAM8(0x001E) = a_bb992;
    RAM8(0x001F) = 0;
    RAM8(0x001C)++;
    r->a = (a_hi_bb992 << 8) | a_bb992;
    r->c = 1;
    r->z = RAM8(0x001C) == 0;
    r->n = RAM8(0x001C) & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bb992;
    r->d = decimal_bb992;
    TAIL_CALL(c, 0xC1B9EA, SOM_RTS); /* test_actor_horizontal_footprint_and_redirect_step */
    shared_BB87_2:;
    RAM16_SET(0x001F, 0);
    a_bb893 = a_bb873;
    a_hi_bb893 = a_hi_bb873;
    x_bb893 = x_bb873;
    y_bb893 = y_bb873;
    zero_bb893 = zero_bb873;
    negative_bb893 = negative_bb873;
    overflow_bb893 = overflow_bb873;
    irq_disable_bb893 = irq_disable_bb873;
    decimal_bb893 = decimal_bb873;
    goto shared_BB89_2;
    shared_BB87_3:;
    RAM16_SET(0x001F, 0);
    a_bb894 = a_bb874;
    a_hi_bb894 = a_hi_bb874;
    x_bb894 = x_bb874;
    y_bb894 = y_bb874;
    zero_bb894 = zero_bb874;
    negative_bb894 = negative_bb874;
    overflow_bb894 = overflow_bb874;
    irq_disable_bb894 = irq_disable_bb874;
    decimal_bb894 = decimal_bb874;
    goto shared_BB89_3;
    shared_BC08:;
    uint8_t value25 = BUS8_RDP(c, (uint16_t)(direct_page_bc08 + 0x1F));
    RAM8(0x0000 + sp0) = value25;
    BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1F), 0);
    r->a = (a_hi_bc08 << 8) | value25;
    r->x = x_bc08;
    r->y = y_bc08;
    r->c = 1;
    r->z = value25 == 0;
    r->n = value25 & 0x80;
    r->v = overflow_bc08;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_bc08;
    r->dp = direct_page_bc08;
    r->i = irq_disable_bc08;
    r->d = decimal_bc08;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 1;
    bool m_ret5 = r->mf;
    uint16_t a_all6 = r->a;
    bool carry_ret6 = r->c;
    if (carry_ret6) {
        if (m_ret5) {
            BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1F), RAM8(0x0000 + sp0));
            uint8_t value27 = BUS8_RDP(c, (uint16_t)(direct_page_bc08 + 0x1E));
            RAM8(0x0000 + sp0) = value27;
            BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1E), 0);
            r->a = (a_all6 >> 8 << 8) | value27;
            r->c = 1;
            r->z = value27 == 0;
            r->n = value27 & 0x80;
            r->mf = 1;
            r->sp -= 1;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 1;
            uint16_t dp_ret3 = r->dp;
            bool m_ret6 = r->mf;
            bool carry_ret7 = r->c;
            if (carry_ret7) {
                if (m_ret6) {
                    uint8_t value28 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1E), 0);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1F), 0);
                    SET_A8(r, value28);
                    r->c = 1;
                    r->z = value28 == 0;
                    r->n = value28 & 0x80;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
            if (m_ret6) {
                uint8_t value29 = RAM8(0x0000 + sp0);
                SET_A8(r, value29);
                r->z = value29 == 0;
                r->n = value29 & 0x80;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            c->fail = 3;
            return;
        }
    }
    if (m_ret5) {
        uint8_t value30 = RAM8(0x0000 + sp0);
        SET_A8(r, value30);
        r->z = value30 == 0;
        r->n = value30 & 0x80;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
    shared_BC08_1:;
    uint8_t value31 = BUS8_RDP(c, (uint16_t)(direct_page_bc082 + 0x1F));
    RAM8(0x0000 + sp0) = value31;
    BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1F), 0);
    r->a = (a_hi_bc082 << 8) | value31;
    r->x = x_bc082;
    r->y = y_bc082;
    r->c = 1;
    r->z = value31 == 0;
    r->n = value31 & 0x80;
    r->v = overflow_bc082;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_bc082;
    r->dp = direct_page_bc082;
    r->i = irq_disable_bc082;
    r->d = decimal_bc082;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 1;
    bool m_ret7 = r->mf;
    uint16_t a_all8 = r->a;
    bool carry_ret8 = r->c;
    if (carry_ret8) {
        if (m_ret7) {
            BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1F), RAM8(0x0000 + sp0));
            uint8_t value33 = BUS8_RDP(c, (uint16_t)(direct_page_bc082 + 0x1E));
            RAM8(0x0000 + sp0) = value33;
            BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1E), 0);
            r->a = (a_all8 >> 8 << 8) | value33;
            r->c = 1;
            r->z = value33 == 0;
            r->n = value33 & 0x80;
            r->mf = 1;
            r->sp -= 1;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 1;
            uint16_t dp_ret4 = r->dp;
            bool m_ret8 = r->mf;
            bool carry_ret9 = r->c;
            if (carry_ret9) {
                if (m_ret8) {
                    uint8_t value34 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 0x1E), 0);
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 0x1F), 0);
                    SET_A8(r, value34);
                    r->c = 1;
                    r->z = value34 == 0;
                    r->n = value34 & 0x80;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
            if (m_ret8) {
                uint8_t value35 = RAM8(0x0000 + sp0);
                SET_A8(r, value35);
                r->z = value35 == 0;
                r->n = value35 & 0x80;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            c->fail = 3;
            return;
        }
    }
    if (m_ret7) {
        uint8_t value36 = RAM8(0x0000 + sp0);
        SET_A8(r, value36);
        r->z = value36 == 0;
        r->n = value36 & 0x80;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
    shared_BC08_2:;
    uint16_t value37 = BUS16_RDP(c, (uint16_t)(direct_page_bc083 + 0x1F));
    RAM8(0x0000 + sp0) = value37 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value37;
    BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), 0);
    r->a = value37;
    r->x = x_bc083;
    r->y = y_bc083;
    r->c = 1;
    r->z = value37 == 0;
    r->n = value37 & 0x8000;
    r->v = overflow_bc083;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_bc083;
    r->dp = direct_page_bc083;
    r->i = irq_disable_bc083;
    r->d = decimal_bc083;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 2;
    bool m_ret9 = r->mf;
    uint16_t a_all10 = r->a;
    bool carry_ret10 = r->c;
    if (carry_ret10) {
        if (m_ret9) {
            BUS8_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), RAM8(0x0000 + sp0 - 1));
            uint8_t value39 = BUS8_RDP(c, (uint16_t)(direct_page_bc083 + 0x1E));
            RAM8(0x0000 + sp0 - 1) = value39;
            BUS8_SET(c, (uint16_t)(direct_page_bc083 + 0x1E), 0);
            r->a = (a_all10 >> 8 << 8) | value39;
            r->c = 1;
            r->z = value39 == 0;
            r->n = value39 & 0x80;
            r->mf = 1;
            r->sp -= 2;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret5 = r->dp;
            bool m_ret10 = r->mf;
            bool carry_ret11 = r->c;
            if (carry_ret11) {
                if (m_ret10) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value41 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value42 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret5 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret5 + 0x1F), 0);
                    r->a = (value42 << 8) | value41;
                    r->c = 1;
                    r->z = ((value42 << 8) | value41) == 0;
                    r->n = ((value42 << 8) | value41) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret10) {
                c->fail = 3;
                return;
            } else {
                uint8_t value44 = RAM8(0x0000 + sp0 - 1);
                uint8_t value45 = RAM8(0x0000 + sp0);
                r->a = (value45 << 8) | value44;
                r->z = ((value45 << 8) | value44) == 0;
                r->n = ((value45 << 8) | value44) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1));
            uint16_t value48 = BUS16_RDP(c, (uint16_t)(direct_page_bc083 + 0x1E));
            RAM8(0x0000 + sp0) = value48 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)value48;
            BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1E), 0);
            r->a = value48;
            r->c = 1;
            r->z = value48 == 0;
            r->n = value48 & 0x8000;
            r->mf = 0;
            r->sp -= 2;
            if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret6 = r->dp;
            bool m_ret11 = r->mf;
            bool carry_ret12 = r->c;
            if (carry_ret12) {
                if (m_ret11) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value50 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value51 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret6 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret6 + 0x1F), 0);
                    r->a = (value51 << 8) | value50;
                    r->c = 1;
                    r->z = ((value51 << 8) | value50) == 0;
                    r->n = ((value51 << 8) | value50) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret11) {
                c->fail = 3;
                return;
            } else {
                uint8_t value53 = RAM8(0x0000 + sp0 - 1);
                uint8_t value54 = RAM8(0x0000 + sp0);
                r->a = (value54 << 8) | value53;
                r->z = ((value54 << 8) | value53) == 0;
                r->n = ((value54 << 8) | value53) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
    if (m_ret9) {
        c->fail = 3;
        return;
    } else {
        uint8_t value56 = RAM8(0x0000 + sp0 - 1);
        uint8_t value57 = RAM8(0x0000 + sp0);
        r->a = (value57 << 8) | value56;
        r->z = ((value57 << 8) | value56) == 0;
        r->n = ((value57 << 8) | value56) & 0x8000;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    shared_BC08_3:;
    uint16_t value58 = BUS16_RDP(c, (uint16_t)(direct_page_bc084 + 0x1F));
    RAM8(0x0000 + sp0) = value58 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value58;
    BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), 0);
    r->a = value58;
    r->x = x_bc084;
    r->y = y_bc084;
    r->c = 1;
    r->z = value58 == 0;
    r->n = value58 & 0x8000;
    r->v = overflow_bc084;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_bc084;
    r->dp = direct_page_bc084;
    r->i = irq_disable_bc084;
    r->d = decimal_bc084;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 2;
    bool m_ret12 = r->mf;
    uint16_t a_all13 = r->a;
    bool carry_ret13 = r->c;
    if (carry_ret13) {
        if (m_ret12) {
            BUS8_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), RAM8(0x0000 + sp0 - 1));
            uint8_t value60 = BUS8_RDP(c, (uint16_t)(direct_page_bc084 + 0x1E));
            RAM8(0x0000 + sp0 - 1) = value60;
            BUS8_SET(c, (uint16_t)(direct_page_bc084 + 0x1E), 0);
            r->a = (a_all13 >> 8 << 8) | value60;
            r->c = 1;
            r->z = value60 == 0;
            r->n = value60 & 0x80;
            r->mf = 1;
            r->sp -= 2;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret7 = r->dp;
            bool m_ret13 = r->mf;
            bool carry_ret14 = r->c;
            if (carry_ret14) {
                if (m_ret13) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value62 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value63 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret7 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret7 + 0x1F), 0);
                    r->a = (value63 << 8) | value62;
                    r->c = 1;
                    r->z = ((value63 << 8) | value62) == 0;
                    r->n = ((value63 << 8) | value62) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret13) {
                c->fail = 3;
                return;
            } else {
                uint8_t value65 = RAM8(0x0000 + sp0 - 1);
                uint8_t value66 = RAM8(0x0000 + sp0);
                r->a = (value66 << 8) | value65;
                r->z = ((value66 << 8) | value65) == 0;
                r->n = ((value66 << 8) | value65) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1));
            uint16_t value69 = BUS16_RDP(c, (uint16_t)(direct_page_bc084 + 0x1E));
            RAM8(0x0000 + sp0) = value69 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)value69;
            BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1E), 0);
            r->a = value69;
            r->c = 1;
            r->z = value69 == 0;
            r->n = value69 & 0x8000;
            r->mf = 0;
            r->sp -= 2;
            if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret8 = r->dp;
            bool m_ret14 = r->mf;
            bool carry_ret15 = r->c;
            if (carry_ret15) {
                if (m_ret14) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value71 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value72 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret8 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret8 + 0x1F), 0);
                    r->a = (value72 << 8) | value71;
                    r->c = 1;
                    r->z = ((value72 << 8) | value71) == 0;
                    r->n = ((value72 << 8) | value71) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret14) {
                c->fail = 3;
                return;
            } else {
                uint8_t value74 = RAM8(0x0000 + sp0 - 1);
                uint8_t value75 = RAM8(0x0000 + sp0);
                r->a = (value75 << 8) | value74;
                r->z = ((value75 << 8) | value74) == 0;
                r->n = ((value75 << 8) | value74) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
    if (m_ret12) {
        c->fail = 3;
        return;
    } else {
        uint8_t value77 = RAM8(0x0000 + sp0 - 1);
        uint8_t value78 = RAM8(0x0000 + sp0);
        r->a = (value78 << 8) | value77;
        r->z = ((value78 << 8) | value77) == 0;
        r->n = ((value78 << 8) | value77) & 0x8000;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}

/* C1BAE2 test_actor_vertical_footprint_and_redirect_step_v4   [class A, 306 bytes, 169 instructions]
 * Source: src/rom/test_actor_horizontal_footprint_and_redirect_step.s
 * Subroutine of test_actor_horizontal_footprint_and_redirect_step, translated in place.
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void test_actor_vertical_footprint_and_redirect_step_v4(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_bb89 = 0;
    uint8_t a_hi_bb89 = 0;
    uint8_t x_bb89 = 0;
    uint8_t y_bb89 = 0;
    bool zero_bb89 = 0;
    bool negative_bb89 = 0;
    bool overflow_bb89 = 0;
    bool irq_disable_bb89 = 0;
    bool decimal_bb89 = 0;
    uint8_t a_bb892 = 0;
    uint8_t a_hi_bb892 = 0;
    uint16_t x_bb892 = 0;
    uint16_t y_bb892 = 0;
    bool zero_bb892 = 0;
    bool negative_bb892 = 0;
    bool overflow_bb892 = 0;
    bool irq_disable_bb892 = 0;
    bool decimal_bb892 = 0;
    uint8_t a_bb893 = 0;
    uint8_t a_hi_bb893 = 0;
    uint8_t x_bb893 = 0;
    uint8_t y_bb893 = 0;
    bool zero_bb893 = 0;
    bool negative_bb893 = 0;
    bool overflow_bb893 = 0;
    bool irq_disable_bb893 = 0;
    bool decimal_bb893 = 0;
    uint8_t a_bb894 = 0;
    uint8_t a_hi_bb894 = 0;
    uint16_t x_bb894 = 0;
    uint16_t y_bb894 = 0;
    bool zero_bb894 = 0;
    bool negative_bb894 = 0;
    bool overflow_bb894 = 0;
    bool irq_disable_bb894 = 0;
    bool decimal_bb894 = 0;
    uint8_t a_bb87 = 0;
    uint8_t a_hi_bb87 = 0;
    uint8_t x_bb87 = 0;
    uint8_t y_bb87 = 0;
    bool zero_bb87 = 0;
    bool negative_bb87 = 0;
    bool overflow_bb87 = 0;
    bool irq_disable_bb87 = 0;
    bool decimal_bb87 = 0;
    uint8_t a_bb872 = 0;
    uint8_t a_hi_bb872 = 0;
    uint16_t x_bb872 = 0;
    uint16_t y_bb872 = 0;
    bool zero_bb872 = 0;
    bool negative_bb872 = 0;
    bool overflow_bb872 = 0;
    bool irq_disable_bb872 = 0;
    bool decimal_bb872 = 0;
    uint8_t a_bbfb = 0;
    uint8_t a_hi_bbfb = 0;
    uint8_t x_bbfb = 0;
    uint8_t y_bbfb = 0;
    bool zero_bbfb = 0;
    bool negative_bbfb = 0;
    bool overflow_bbfb = 0;
    bool irq_disable_bbfb = 0;
    bool decimal_bbfb = 0;
    uint8_t a_bbfb2 = 0;
    uint8_t a_hi_bbfb2 = 0;
    uint16_t x_bbfb2 = 0;
    uint16_t y_bbfb2 = 0;
    bool zero_bbfb2 = 0;
    bool negative_bbfb2 = 0;
    bool overflow_bbfb2 = 0;
    bool irq_disable_bbfb2 = 0;
    bool decimal_bbfb2 = 0;
    uint8_t a_bb99 = 0;
    uint8_t a_hi_bb99 = 0;
    bool irq_disable_bb99 = 0;
    bool decimal_bb99 = 0;
    uint8_t a_bb992 = 0;
    uint8_t a_hi_bb992 = 0;
    bool irq_disable_bb992 = 0;
    bool decimal_bb992 = 0;
    uint8_t a_bb873 = 0;
    uint8_t a_hi_bb873 = 0;
    uint8_t x_bb873 = 0;
    uint8_t y_bb873 = 0;
    bool zero_bb873 = 0;
    bool negative_bb873 = 0;
    bool overflow_bb873 = 0;
    bool irq_disable_bb873 = 0;
    bool decimal_bb873 = 0;
    uint8_t a_bb874 = 0;
    uint8_t a_hi_bb874 = 0;
    uint16_t x_bb874 = 0;
    uint16_t y_bb874 = 0;
    bool zero_bb874 = 0;
    bool negative_bb874 = 0;
    bool overflow_bb874 = 0;
    bool irq_disable_bb874 = 0;
    bool decimal_bb874 = 0;
    uint8_t a_hi_bc08 = 0;
    uint8_t x_bc08 = 0;
    uint8_t y_bc08 = 0;
    bool overflow_bc08 = 0;
    uint16_t direct_page_bc08 = 0;
    uint8_t data_bank_bc08 = 0;
    bool irq_disable_bc08 = 0;
    bool decimal_bc08 = 0;
    uint8_t a_hi_bc082 = 0;
    uint16_t x_bc082 = 0;
    uint16_t y_bc082 = 0;
    bool overflow_bc082 = 0;
    uint16_t direct_page_bc082 = 0;
    uint8_t data_bank_bc082 = 0;
    bool irq_disable_bc082 = 0;
    bool decimal_bc082 = 0;
    uint8_t a_hi_bc083 = 0;
    uint8_t x_bc083 = 0;
    uint8_t y_bc083 = 0;
    bool overflow_bc083 = 0;
    uint16_t direct_page_bc083 = 0;
    uint8_t data_bank_bc083 = 0;
    bool irq_disable_bc083 = 0;
    bool decimal_bc083 = 0;
    uint8_t a_hi_bc084 = 0;
    uint16_t x_bc084 = 0;
    uint16_t y_bc084 = 0;
    bool overflow_bc084 = 0;
    uint16_t direct_page_bc084 = 0;
    uint8_t data_bank_bc084 = 0;
    bool irq_disable_bc084 = 0;
    bool decimal_bc084 = 0;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20 | 0x10) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = RAM8(0x001F);
    uint8_t a3;
    uint8_t a_hi3;
    if ((uint8_t)(value + 4) >= 0x80) {
        uint16_t value2 = RAM16(0x0014);
        uint8_t a1;
        uint8_t a_hi1;
        if (!((uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) & 0x8000)) {
            a1 = (uint8_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1);
            a_hi1 = (uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) >> 8;
        } else {
            uint16_t value3 = RAM16(0x00C2);
            a1 = (uint8_t)((uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) + value3);
            a_hi1 = (uint16_t)((uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) + value3) >> 8;
        }
        a3 = a1;
        a_hi3 = a_hi1;
    } else {
        uint16_t value4 = RAM16(0x0014);
        uint16_t value5 = RAM16(0x00C2);
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) < value5) {
            a2 = (uint8_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4);
            a_hi2 = (uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) >> 8;
        } else {
            a2 = (uint8_t)((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) - value5 - ((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) >= value5 ^ 1));
            a_hi2 = (uint16_t)((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) - value5 - ((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) >= value5 ^ 1)) >> 8;
        }
        a3 = a2;
        a_hi3 = a_hi2;
    }
    RAM16_SET(0x0004, (a_hi3 << 8) | a3);
    RAM16_SET(0x0008, (((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1);
    uint8_t value6 = RAM8(0x001E);
    uint8_t a4;
    if (!(value6 & 0x80)) {
        a4 = value6;
    } else {
        a4 = (uint8_t)((value6 ^ 0x7F) + 1);
    }
    RAM8(0x0000) = a4;
    uint8_t value7 = RAM8(0x001A);
    uint8_t value8 = RAM8(0x0000);
    uint8_t a7;
    uint8_t a_hi6;
    if (!((uint8_t)((value7 >> 1) + value8) & 0x80)) {
        uint16_t value9 = RAM16(0x0012);
        uint16_t value10 = RAM16(0x00C0);
        uint8_t a5;
        uint8_t a_hi4;
        if ((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9) < value10) {
            a5 = (uint8_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9);
            a_hi4 = (uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9) >> 8;
        } else {
            a5 = (uint8_t)((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9) - value10 - ((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9) >= value10 ^ 1));
            a_hi4 = (uint16_t)((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9) - value10 - ((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8)) & 0x7F) + value9) >= value10 ^ 1)) >> 8;
        }
        a7 = a5;
        a_hi6 = a_hi4;
    } else {
        uint16_t value11 = RAM16(0x0012);
        uint8_t a6;
        uint8_t a_hi5;
        if (!((uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8) | 0xFF00) + value11) & 0x8000)) {
            a6 = (uint8_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8) | 0xFF00) + value11);
            a_hi5 = (uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8) | 0xFF00) + value11) >> 8;
        } else {
            uint16_t value12 = RAM16(0x00C0);
            a6 = (uint8_t)((uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8) | 0xFF00) + value11) + value12);
            a_hi5 = (uint16_t)((uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value7 >> 1) + value8) | 0xFF00) + value11) + value12) >> 8;
        }
        a7 = a6;
        a_hi6 = a_hi5;
    }
    RAM8(0x0000 + sp0 - 1) = a_hi6;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)((a_hi6 << 8) | a7);
    RAM16_SET(0x0004, ((RAM8(0x0004) << 8) | a7) & 0x0F0F);
    uint16_t value14 = RAM16(0x0008);
    RAM16_SET(0x0008, ((((a_hi6 << 8) | a7) >> 4) & 0x7F) | value14);
    uint16_t value15 = BUS16_RDL(c, (RAM8(0x000C) << 0x10) + RAM16(0x000A) + (uint8_t)(((((a_hi6 << 8) | a7) >> 4) & 0x7F) | value14), RAM8(0x000C));
    uint8_t value16 = BUS8_RDL(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + (uint8_t)((value15 & 0xFF) << 1 << 1), RAM8(0x000F));
    RAM8(0x0007) = value16;
    uint8_t value17 = BUS8_RDL(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + (uint8_t)((uint8_t)((value15 & 0xFF) << 1 << 1) + 2), RAM8(0x000F));
    RAM8(0x0006) = value17;
    if ((value17 & 0xF0) != 0x10) {
        RAM8(0x0006) = 0;
    }
    r->a = (value15 & 0xFF) << 1 << 1 >> 8 << 8 | (value17 & 0xF0);
    r->y = (uint8_t)((uint8_t)((value15 & 0xFF) << 1 << 1) + 2);
    r->c = (value17 & 0xF0) >= 0x10;
    r->z = (value17 & 0xF0) == 0x10;
    r->n = (uint8_t)((value17 & 0xF0) - 0x10) & 0x80;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBB7A, 0xC1BC37); GUARD_JSR(c, sp_call, 0xBB7A); } /* test_horizontal_terrain_shape_and_preceding_cells */
    r->sp += 1;
    uint16_t a_all = r->a;
    uint8_t y_ret = r->y;
    bool carry_ret = r->c;
    if (carry_ret) {
        uint8_t value18 = RAM8(0x0000 + sp0);
        if (value18 & 0x01) {
            if (value18 & 0x20) {
                if (value18 & 0x10) {
                    a_bb89 = (uint8_t)a_all;
                    a_hi_bb89 = a_all >> 8;
                    x_bb89 = x;
                    y_bb89 = y_ret;
                    zero_bb89 = value18 & 0x02;
                    negative_bb89 = value18 & 0x80;
                    overflow_bb89 = value18 & 0x40;
                    irq_disable_bb89 = value18 & 0x04;
                    decimal_bb89 = value18 & 0x08;
                    goto shared_BB89;
                } else {
                    a_bb892 = (uint8_t)a_all;
                    a_hi_bb892 = a_all >> 8;
                    x_bb892 = x;
                    y_bb892 = y_ret;
                    zero_bb892 = value18 & 0x02;
                    negative_bb892 = value18 & 0x80;
                    overflow_bb892 = value18 & 0x40;
                    irq_disable_bb892 = value18 & 0x04;
                    decimal_bb892 = value18 & 0x08;
                    goto shared_BB89_1;
                }
            } else {
                if (value18 & 0x10) {
                    a_bb893 = (uint8_t)a_all;
                    a_hi_bb893 = a_all >> 8;
                    x_bb893 = x;
                    y_bb893 = y_ret;
                    zero_bb893 = value18 & 0x02;
                    negative_bb893 = value18 & 0x80;
                    overflow_bb893 = value18 & 0x40;
                    irq_disable_bb893 = value18 & 0x04;
                    decimal_bb893 = value18 & 0x08;
                    goto shared_BB89_2;
                } else {
                    a_bb894 = (uint8_t)a_all;
                    a_hi_bb894 = a_all >> 8;
                    x_bb894 = x;
                    y_bb894 = y_ret;
                    zero_bb894 = value18 & 0x02;
                    negative_bb894 = value18 & 0x80;
                    overflow_bb894 = value18 & 0x40;
                    irq_disable_bb894 = value18 & 0x04;
                    decimal_bb894 = value18 & 0x08;
                    goto shared_BB89_3;
                }
            }
        }
        if (value18 & 0x20) {
            uint8_t value19 = RAM8(0x0002);
            if (value19 != 0) {
                if (value19 < 8) {
                    uint8_t value20 = RAM8(0x001F);
                    if (value20 & 0x80) {
                        if (value19 != 5) {
                            if (value19 != 6) {
                                if (value18 & 0x10) {
                                    a_bb87 = value19;
                                    a_hi_bb87 = a_all >> 8;
                                    x_bb87 = x;
                                    y_bb87 = y_ret;
                                    zero_bb87 = value19 == 6;
                                    negative_bb87 = (uint8_t)(value19 - 6) & 0x80;
                                    overflow_bb87 = value20 & 0x40;
                                    irq_disable_bb87 = value18 & 0x04;
                                    decimal_bb87 = value18 & 0x08;
                                    goto shared_BB87;
                                } else {
                                    a_bb872 = value19;
                                    a_hi_bb872 = a_all >> 8;
                                    x_bb872 = x;
                                    y_bb872 = y_ret;
                                    zero_bb872 = value19 == 6;
                                    negative_bb872 = (uint8_t)(value19 - 6) & 0x80;
                                    overflow_bb872 = value20 & 0x40;
                                    irq_disable_bb872 = value18 & 0x04;
                                    decimal_bb872 = value18 & 0x08;
                                    goto shared_BB87_1;
                                }
                            }
                            RAM8(0x001E) = value20 ^ 0x80;
                            RAM8(0x001C)++;
                            if (value18 & 0x10) {
                                a_bbfb = value20 ^ 0x80;
                                a_hi_bbfb = a_all >> 8;
                                x_bbfb = x;
                                y_bbfb = y_ret;
                                zero_bbfb = RAM8(0x001C) == 0;
                                negative_bbfb = RAM8(0x001C) & 0x80;
                                overflow_bbfb = value20 & 0x40;
                                irq_disable_bbfb = value18 & 0x04;
                                decimal_bbfb = value18 & 0x08;
                                goto shared_BBFB;
                            } else {
                                a_bbfb2 = value20 ^ 0x80;
                                a_hi_bbfb2 = a_all >> 8;
                                x_bbfb2 = x;
                                y_bbfb2 = y_ret;
                                zero_bbfb2 = RAM8(0x001C) == 0;
                                negative_bbfb2 = RAM8(0x001C) & 0x80;
                                overflow_bbfb2 = value20 & 0x40;
                                irq_disable_bbfb2 = value18 & 0x04;
                                decimal_bbfb2 = value18 & 0x08;
                                goto shared_BBFB_1;
                            }
                        }
                        RAM8(0x001E) = value20;
                        RAM8(0x001C)++;
                        if (value18 & 0x10) {
                            a_bbfb = value20;
                            a_hi_bbfb = a_all >> 8;
                            x_bbfb = x;
                            y_bbfb = y_ret;
                            zero_bbfb = RAM8(0x001C) == 0;
                            negative_bbfb = RAM8(0x001C) & 0x80;
                            overflow_bbfb = value20 & 0x40;
                            irq_disable_bbfb = value18 & 0x04;
                            decimal_bbfb = value18 & 0x08;
                            goto shared_BBFB;
                        } else {
                            a_bbfb2 = value20;
                            a_hi_bbfb2 = a_all >> 8;
                            x_bbfb2 = x;
                            y_bbfb2 = y_ret;
                            zero_bbfb2 = RAM8(0x001C) == 0;
                            negative_bbfb2 = RAM8(0x001C) & 0x80;
                            overflow_bbfb2 = value20 & 0x40;
                            irq_disable_bbfb2 = value18 & 0x04;
                            decimal_bbfb2 = value18 & 0x08;
                            goto shared_BBFB_1;
                        }
                    }
                    if (value19 != 4) {
                        if (value19 != 7) {
                            if (value18 & 0x10) {
                                a_bb87 = value19;
                                a_hi_bb87 = a_all >> 8;
                                x_bb87 = x;
                                y_bb87 = y_ret;
                                zero_bb87 = value19 == 7;
                                negative_bb87 = (uint8_t)(value19 - 7) & 0x80;
                                overflow_bb87 = value20 & 0x40;
                                irq_disable_bb87 = value18 & 0x04;
                                decimal_bb87 = value18 & 0x08;
                                goto shared_BB87;
                            } else {
                                a_bb872 = value19;
                                a_hi_bb872 = a_all >> 8;
                                x_bb872 = x;
                                y_bb872 = y_ret;
                                zero_bb872 = value19 == 7;
                                negative_bb872 = (uint8_t)(value19 - 7) & 0x80;
                                overflow_bb872 = value20 & 0x40;
                                irq_disable_bb872 = value18 & 0x04;
                                decimal_bb872 = value18 & 0x08;
                                goto shared_BB87_1;
                            }
                        }
                        RAM8(0x001E) = value20 ^ 0x80;
                        RAM8(0x001C)++;
                        if (value18 & 0x10) {
                            a_bbfb = value20 ^ 0x80;
                            a_hi_bbfb = a_all >> 8;
                            x_bbfb = x;
                            y_bbfb = y_ret;
                            zero_bbfb = RAM8(0x001C) == 0;
                            negative_bbfb = RAM8(0x001C) & 0x80;
                            overflow_bbfb = value20 & 0x40;
                            irq_disable_bbfb = value18 & 0x04;
                            decimal_bbfb = value18 & 0x08;
                            goto shared_BBFB;
                        } else {
                            a_bbfb2 = value20 ^ 0x80;
                            a_hi_bbfb2 = a_all >> 8;
                            x_bbfb2 = x;
                            y_bbfb2 = y_ret;
                            zero_bbfb2 = RAM8(0x001C) == 0;
                            negative_bbfb2 = RAM8(0x001C) & 0x80;
                            overflow_bbfb2 = value20 & 0x40;
                            irq_disable_bbfb2 = value18 & 0x04;
                            decimal_bbfb2 = value18 & 0x08;
                            goto shared_BBFB_1;
                        }
                    }
                    RAM8(0x001E) = value20;
                    RAM8(0x001C)++;
                    if (value18 & 0x10) {
                        a_bbfb = value20;
                        a_hi_bbfb = a_all >> 8;
                        x_bbfb = x;
                        y_bbfb = y_ret;
                        zero_bbfb = RAM8(0x001C) == 0;
                        negative_bbfb = RAM8(0x001C) & 0x80;
                        overflow_bbfb = value20 & 0x40;
                        irq_disable_bbfb = value18 & 0x04;
                        decimal_bbfb = value18 & 0x08;
                        goto shared_BBFB;
                    } else {
                        a_bbfb2 = value20;
                        a_hi_bbfb2 = a_all >> 8;
                        x_bbfb2 = x;
                        y_bbfb2 = y_ret;
                        zero_bbfb2 = RAM8(0x001C) == 0;
                        negative_bbfb2 = RAM8(0x001C) & 0x80;
                        overflow_bbfb2 = value20 & 0x40;
                        irq_disable_bbfb2 = value18 & 0x04;
                        decimal_bbfb2 = value18 & 0x08;
                        goto shared_BBFB_1;
                    }
                }
                if (value19 == 8) {
                    uint8_t value21 = RAM8(0x001F);
                    if (value18 & 0x10) {
                        a_bb99 = value21;
                        a_hi_bb99 = a_all >> 8;
                        irq_disable_bb99 = value18 & 0x04;
                        decimal_bb99 = value18 & 0x08;
                        goto shared_BB99;
                    } else {
                        a_bb992 = value21;
                        a_hi_bb992 = a_all >> 8;
                        irq_disable_bb992 = value18 & 0x04;
                        decimal_bb992 = value18 & 0x08;
                        goto shared_BB99_1;
                    }
                }
                if (value19 != 9) {
                    if (value18 & 0x10) {
                        a_bb87 = value19;
                        a_hi_bb87 = a_all >> 8;
                        x_bb87 = x;
                        y_bb87 = y_ret;
                        zero_bb87 = value19 == 9;
                        negative_bb87 = (uint8_t)(value19 - 9) & 0x80;
                        overflow_bb87 = value18 & 0x40;
                        irq_disable_bb87 = value18 & 0x04;
                        decimal_bb87 = value18 & 0x08;
                        goto shared_BB87;
                    } else {
                        a_bb872 = value19;
                        a_hi_bb872 = a_all >> 8;
                        x_bb872 = x;
                        y_bb872 = y_ret;
                        zero_bb872 = value19 == 9;
                        negative_bb872 = (uint8_t)(value19 - 9) & 0x80;
                        overflow_bb872 = value18 & 0x40;
                        irq_disable_bb872 = value18 & 0x04;
                        decimal_bb872 = value18 & 0x08;
                        goto shared_BB87_1;
                    }
                }
                uint8_t value22 = RAM8(0x001F);
                if (value18 & 0x10) {
                    a_bb99 = value22 ^ 0x80;
                    a_hi_bb99 = a_all >> 8;
                    irq_disable_bb99 = value18 & 0x04;
                    decimal_bb99 = value18 & 0x08;
                    goto shared_BB99;
                } else {
                    a_bb992 = value22 ^ 0x80;
                    a_hi_bb992 = a_all >> 8;
                    irq_disable_bb992 = value18 & 0x04;
                    decimal_bb992 = value18 & 0x08;
                    goto shared_BB99_1;
                }
            }
            if (value18 & 0x10) {
                a_bb87 = value19;
                a_hi_bb87 = a_all >> 8;
                x_bb87 = x;
                y_bb87 = y_ret;
                zero_bb87 = value19 == 0;
                negative_bb87 = value19 & 0x80;
                overflow_bb87 = value18 & 0x40;
                irq_disable_bb87 = value18 & 0x04;
                decimal_bb87 = value18 & 0x08;
                goto shared_BB87;
            } else {
                a_bb872 = value19;
                a_hi_bb872 = a_all >> 8;
                x_bb872 = x;
                y_bb872 = y_ret;
                zero_bb872 = value19 == 0;
                negative_bb872 = value19 & 0x80;
                overflow_bb872 = value18 & 0x40;
                irq_disable_bb872 = value18 & 0x04;
                decimal_bb872 = value18 & 0x08;
                goto shared_BB87_1;
            }
        } else {
            uint16_t value23 = RAM16(0x0002);
            if (value23 != 0) {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
            if (value18 & 0x10) {
                a_bb873 = (uint8_t)value23;
                a_hi_bb873 = value23 >> 8;
                x_bb873 = x;
                y_bb873 = y_ret;
                zero_bb873 = value23 == 0;
                negative_bb873 = value23 & 0x8000;
                overflow_bb873 = value18 & 0x40;
                irq_disable_bb873 = value18 & 0x04;
                decimal_bb873 = value18 & 0x08;
                goto shared_BB87_2;
            } else {
                a_bb874 = (uint8_t)value23;
                a_hi_bb874 = value23 >> 8;
                x_bb874 = x;
                y_bb874 = y_ret;
                zero_bb874 = value23 == 0;
                negative_bb874 = value23 & 0x8000;
                overflow_bb874 = value18 & 0x40;
                irq_disable_bb874 = value18 & 0x04;
                decimal_bb874 = value18 & 0x08;
                goto shared_BB87_3;
            }
        }
    }
    uint8_t value24 = RAM8(0x0000 + sp0);
    r->c = 0;
    r->z = value24 & 0x02;
    r->n = value24 & 0x80;
    r->v = value24 & 0x40;
    r->mf = value24 & 0x20;
    r->xf = value24 & 0x10;
    r->i = value24 & 0x04;
    r->d = value24 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BB89:;
    r->a = (a_hi_bb89 << 8) | a_bb89;
    r->x = x_bb89;
    r->y = y_bb89;
    r->c = 1;
    r->z = zero_bb89;
    r->n = negative_bb89;
    r->v = overflow_bb89;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bb89;
    r->d = decimal_bb89;
    RETURN_RTS(c);
    shared_BB89_1:;
    r->a = (a_hi_bb892 << 8) | a_bb892;
    r->x = x_bb892;
    r->y = y_bb892;
    r->c = 1;
    r->z = zero_bb892;
    r->n = negative_bb892;
    r->v = overflow_bb892;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bb892;
    r->d = decimal_bb892;
    RETURN_RTS(c);
    shared_BB89_2:;
    r->a = (a_hi_bb893 << 8) | a_bb893;
    r->x = x_bb893;
    r->y = y_bb893;
    r->c = 1;
    r->z = zero_bb893;
    r->n = negative_bb893;
    r->v = overflow_bb893;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bb893;
    r->d = decimal_bb893;
    RETURN_RTS(c);
    shared_BB89_3:;
    r->a = (a_hi_bb894 << 8) | a_bb894;
    r->x = x_bb894;
    r->y = y_bb894;
    r->c = 1;
    r->z = zero_bb894;
    r->n = negative_bb894;
    r->v = overflow_bb894;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bb894;
    r->d = decimal_bb894;
    RETURN_RTS(c);
    shared_BB87:;
    RAM8(0x001F) = 0;
    a_bb89 = a_bb87;
    a_hi_bb89 = a_hi_bb87;
    x_bb89 = x_bb87;
    y_bb89 = y_bb87;
    zero_bb89 = zero_bb87;
    negative_bb89 = negative_bb87;
    overflow_bb89 = overflow_bb87;
    irq_disable_bb89 = irq_disable_bb87;
    decimal_bb89 = decimal_bb87;
    goto shared_BB89;
    shared_BB87_1:;
    RAM8(0x001F) = 0;
    a_bb892 = a_bb872;
    a_hi_bb892 = a_hi_bb872;
    x_bb892 = x_bb872;
    y_bb892 = y_bb872;
    zero_bb892 = zero_bb872;
    negative_bb892 = negative_bb872;
    overflow_bb892 = overflow_bb872;
    irq_disable_bb892 = irq_disable_bb872;
    decimal_bb892 = decimal_bb872;
    goto shared_BB89_1;
    shared_BBFB:;
    r->a = (a_hi_bbfb << 8) | a_bbfb;
    r->x = x_bbfb;
    r->y = y_bbfb;
    r->c = 1;
    r->z = zero_bbfb;
    r->n = negative_bbfb;
    r->v = overflow_bbfb;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bbfb;
    r->d = decimal_bbfb;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBBFE, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBBFE); } /* test_actor_horizontal_footprint_and_redirect_step */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    if (carry_ret2) {
        if (m_ret) {
            if (x_ret) {
                a_hi_bc08 = a_all2 >> 8;
                x_bc08 = x_bbfb;
                y_bc08 = (uint8_t)y_ret2;
                overflow_bc08 = overflow_ret2;
                direct_page_bc08 = 0;
                data_bank_bc08 = 0x7E;
                irq_disable_bc08 = irq_disable_bbfb;
                decimal_bc08 = decimal_bbfb;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all2 >> 8;
                x_bc082 = x_bbfb;
                y_bc082 = y_ret2;
                overflow_bc082 = overflow_ret2;
                direct_page_bc082 = 0;
                data_bank_bc082 = 0x7E;
                irq_disable_bc082 = irq_disable_bbfb;
                decimal_bc082 = decimal_bbfb;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret) {
                a_hi_bc083 = a_all2 >> 8;
                x_bc083 = x_bbfb;
                y_bc083 = (uint8_t)y_ret2;
                overflow_bc083 = overflow_ret2;
                direct_page_bc083 = 0;
                data_bank_bc083 = 0x7E;
                irq_disable_bc083 = irq_disable_bbfb;
                decimal_bc083 = decimal_bbfb;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all2 >> 8;
                x_bc084 = x_bbfb;
                y_bc084 = y_ret2;
                overflow_bc084 = overflow_ret2;
                direct_page_bc084 = 0;
                data_bank_bc084 = 0x7E;
                irq_disable_bc084 = irq_disable_bbfb;
                decimal_bc084 = decimal_bbfb;
                goto shared_BC08_3;
            }
        }
    }
    r->c = 1;
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); }
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret2 = r->mf;
    bool x_ret2 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    if (carry_ret3) {
        if (m_ret2) {
            if (x_ret2) {
                a_hi_bc08 = a_all3 >> 8;
                x_bc08 = x_bbfb;
                y_bc08 = (uint8_t)y_ret3;
                overflow_bc08 = overflow_ret3;
                direct_page_bc08 = dp_ret;
                data_bank_bc08 = db_ret;
                irq_disable_bc08 = irq_disable_bbfb;
                decimal_bc08 = decimal_bbfb;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all3 >> 8;
                x_bc082 = x_bbfb;
                y_bc082 = y_ret3;
                overflow_bc082 = overflow_ret3;
                direct_page_bc082 = dp_ret;
                data_bank_bc082 = db_ret;
                irq_disable_bc082 = irq_disable_bbfb;
                decimal_bc082 = decimal_bbfb;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret2) {
                a_hi_bc083 = a_all3 >> 8;
                x_bc083 = x_bbfb;
                y_bc083 = (uint8_t)y_ret3;
                overflow_bc083 = overflow_ret3;
                direct_page_bc083 = dp_ret;
                data_bank_bc083 = db_ret;
                irq_disable_bc083 = irq_disable_bbfb;
                decimal_bc083 = decimal_bbfb;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all3 >> 8;
                x_bc084 = x_bbfb;
                y_bc084 = y_ret3;
                overflow_bc084 = overflow_ret3;
                direct_page_bc084 = dp_ret;
                data_bank_bc084 = db_ret;
                irq_disable_bc084 = irq_disable_bbfb;
                decimal_bc084 = decimal_bbfb;
                goto shared_BC08_3;
            }
        }
    }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BBFB_1:;
    r->a = (a_hi_bbfb2 << 8) | a_bbfb2;
    r->x = x_bbfb2;
    r->y = y_bbfb2;
    r->c = 1;
    r->z = zero_bbfb2;
    r->n = negative_bbfb2;
    r->v = overflow_bbfb2;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bbfb2;
    r->d = decimal_bbfb2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBBFE, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBBFE); } /* test_actor_horizontal_footprint_and_redirect_step */
    bool m_ret3 = r->mf;
    bool x_ret3 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t y_ret4 = r->y;
    bool carry_ret4 = r->c;
    bool overflow_ret4 = r->v;
    if (carry_ret4) {
        if (m_ret3) {
            if (x_ret3) {
                a_hi_bc08 = a_all4 >> 8;
                x_bc08 = (uint8_t)x_bbfb2;
                y_bc08 = (uint8_t)y_ret4;
                overflow_bc08 = overflow_ret4;
                direct_page_bc08 = 0;
                data_bank_bc08 = 0x7E;
                irq_disable_bc08 = irq_disable_bbfb2;
                decimal_bc08 = decimal_bbfb2;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all4 >> 8;
                x_bc082 = x_bbfb2;
                y_bc082 = y_ret4;
                overflow_bc082 = overflow_ret4;
                direct_page_bc082 = 0;
                data_bank_bc082 = 0x7E;
                irq_disable_bc082 = irq_disable_bbfb2;
                decimal_bc082 = decimal_bbfb2;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret3) {
                a_hi_bc083 = a_all4 >> 8;
                x_bc083 = (uint8_t)x_bbfb2;
                y_bc083 = (uint8_t)y_ret4;
                overflow_bc083 = overflow_ret4;
                direct_page_bc083 = 0;
                data_bank_bc083 = 0x7E;
                irq_disable_bc083 = irq_disable_bbfb2;
                decimal_bc083 = decimal_bbfb2;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all4 >> 8;
                x_bc084 = x_bbfb2;
                y_bc084 = y_ret4;
                overflow_bc084 = overflow_ret4;
                direct_page_bc084 = 0;
                data_bank_bc084 = 0x7E;
                irq_disable_bc084 = irq_disable_bbfb2;
                decimal_bc084 = decimal_bbfb2;
                goto shared_BC08_3;
            }
        }
    }
    r->c = 1;
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); }
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret4 = r->mf;
    bool x_ret4 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t y_ret5 = r->y;
    bool carry_ret5 = r->c;
    bool overflow_ret5 = r->v;
    if (carry_ret5) {
        if (m_ret4) {
            if (x_ret4) {
                a_hi_bc08 = a_all5 >> 8;
                x_bc08 = (uint8_t)x_bbfb2;
                y_bc08 = (uint8_t)y_ret5;
                overflow_bc08 = overflow_ret5;
                direct_page_bc08 = dp_ret2;
                data_bank_bc08 = db_ret2;
                irq_disable_bc08 = irq_disable_bbfb2;
                decimal_bc08 = decimal_bbfb2;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all5 >> 8;
                x_bc082 = x_bbfb2;
                y_bc082 = y_ret5;
                overflow_bc082 = overflow_ret5;
                direct_page_bc082 = dp_ret2;
                data_bank_bc082 = db_ret2;
                irq_disable_bc082 = irq_disable_bbfb2;
                decimal_bc082 = decimal_bbfb2;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret4) {
                a_hi_bc083 = a_all5 >> 8;
                x_bc083 = (uint8_t)x_bbfb2;
                y_bc083 = (uint8_t)y_ret5;
                overflow_bc083 = overflow_ret5;
                direct_page_bc083 = dp_ret2;
                data_bank_bc083 = db_ret2;
                irq_disable_bc083 = irq_disable_bbfb2;
                decimal_bc083 = decimal_bbfb2;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all5 >> 8;
                x_bc084 = x_bbfb2;
                y_bc084 = y_ret5;
                overflow_bc084 = overflow_ret5;
                direct_page_bc084 = dp_ret2;
                data_bank_bc084 = db_ret2;
                irq_disable_bc084 = irq_disable_bbfb2;
                decimal_bc084 = decimal_bbfb2;
                goto shared_BC08_3;
            }
        }
    }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BB99:;
    RAM8(0x001E) = a_bb99;
    RAM8(0x001F) = 0;
    RAM8(0x001C)++;
    r->a = (a_hi_bb99 << 8) | a_bb99;
    r->c = 1;
    r->z = RAM8(0x001C) == 0;
    r->n = RAM8(0x001C) & 0x80;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bb99;
    r->d = decimal_bb99;
    TAIL_CALL(c, 0xC1B9EA, SOM_RTS); /* test_actor_horizontal_footprint_and_redirect_step */
    shared_BB99_1:;
    RAM8(0x001E) = a_bb992;
    RAM8(0x001F) = 0;
    RAM8(0x001C)++;
    r->a = (a_hi_bb992 << 8) | a_bb992;
    r->c = 1;
    r->z = RAM8(0x001C) == 0;
    r->n = RAM8(0x001C) & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->i = irq_disable_bb992;
    r->d = decimal_bb992;
    TAIL_CALL(c, 0xC1B9EA, SOM_RTS); /* test_actor_horizontal_footprint_and_redirect_step */
    shared_BB87_2:;
    RAM16_SET(0x001F, 0);
    a_bb893 = a_bb873;
    a_hi_bb893 = a_hi_bb873;
    x_bb893 = x_bb873;
    y_bb893 = y_bb873;
    zero_bb893 = zero_bb873;
    negative_bb893 = negative_bb873;
    overflow_bb893 = overflow_bb873;
    irq_disable_bb893 = irq_disable_bb873;
    decimal_bb893 = decimal_bb873;
    goto shared_BB89_2;
    shared_BB87_3:;
    RAM16_SET(0x001F, 0);
    a_bb894 = a_bb874;
    a_hi_bb894 = a_hi_bb874;
    x_bb894 = x_bb874;
    y_bb894 = y_bb874;
    zero_bb894 = zero_bb874;
    negative_bb894 = negative_bb874;
    overflow_bb894 = overflow_bb874;
    irq_disable_bb894 = irq_disable_bb874;
    decimal_bb894 = decimal_bb874;
    goto shared_BB89_3;
    shared_BC08:;
    uint8_t value25 = BUS8_RDP(c, (uint16_t)(direct_page_bc08 + 0x1F));
    RAM8(0x0000 + sp0) = value25;
    BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1F), 0);
    r->a = (a_hi_bc08 << 8) | value25;
    r->x = x_bc08;
    r->y = y_bc08;
    r->c = 1;
    r->z = value25 == 0;
    r->n = value25 & 0x80;
    r->v = overflow_bc08;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_bc08;
    r->dp = direct_page_bc08;
    r->i = irq_disable_bc08;
    r->d = decimal_bc08;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 1;
    bool m_ret5 = r->mf;
    uint16_t a_all6 = r->a;
    bool carry_ret6 = r->c;
    if (carry_ret6) {
        if (m_ret5) {
            BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1F), RAM8(0x0000 + sp0));
            uint8_t value27 = BUS8_RDP(c, (uint16_t)(direct_page_bc08 + 0x1E));
            RAM8(0x0000 + sp0) = value27;
            BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1E), 0);
            r->a = (a_all6 >> 8 << 8) | value27;
            r->c = 1;
            r->z = value27 == 0;
            r->n = value27 & 0x80;
            r->mf = 1;
            r->sp -= 1;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 1;
            uint16_t dp_ret3 = r->dp;
            bool m_ret6 = r->mf;
            bool carry_ret7 = r->c;
            if (carry_ret7) {
                if (m_ret6) {
                    uint8_t value28 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1E), 0);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1F), 0);
                    SET_A8(r, value28);
                    r->c = 1;
                    r->z = value28 == 0;
                    r->n = value28 & 0x80;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
            if (m_ret6) {
                uint8_t value29 = RAM8(0x0000 + sp0);
                SET_A8(r, value29);
                r->z = value29 == 0;
                r->n = value29 & 0x80;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            c->fail = 3;
            return;
        }
    }
    if (m_ret5) {
        uint8_t value30 = RAM8(0x0000 + sp0);
        SET_A8(r, value30);
        r->z = value30 == 0;
        r->n = value30 & 0x80;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
    shared_BC08_1:;
    uint8_t value31 = BUS8_RDP(c, (uint16_t)(direct_page_bc082 + 0x1F));
    RAM8(0x0000 + sp0) = value31;
    BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1F), 0);
    r->a = (a_hi_bc082 << 8) | value31;
    r->x = x_bc082;
    r->y = y_bc082;
    r->c = 1;
    r->z = value31 == 0;
    r->n = value31 & 0x80;
    r->v = overflow_bc082;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_bc082;
    r->dp = direct_page_bc082;
    r->i = irq_disable_bc082;
    r->d = decimal_bc082;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 1;
    bool m_ret7 = r->mf;
    uint16_t a_all8 = r->a;
    bool carry_ret8 = r->c;
    if (carry_ret8) {
        if (m_ret7) {
            BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1F), RAM8(0x0000 + sp0));
            uint8_t value33 = BUS8_RDP(c, (uint16_t)(direct_page_bc082 + 0x1E));
            RAM8(0x0000 + sp0) = value33;
            BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1E), 0);
            r->a = (a_all8 >> 8 << 8) | value33;
            r->c = 1;
            r->z = value33 == 0;
            r->n = value33 & 0x80;
            r->mf = 1;
            r->sp -= 1;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 1;
            uint16_t dp_ret4 = r->dp;
            bool m_ret8 = r->mf;
            bool carry_ret9 = r->c;
            if (carry_ret9) {
                if (m_ret8) {
                    uint8_t value34 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 0x1E), 0);
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 0x1F), 0);
                    SET_A8(r, value34);
                    r->c = 1;
                    r->z = value34 == 0;
                    r->n = value34 & 0x80;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
            if (m_ret8) {
                uint8_t value35 = RAM8(0x0000 + sp0);
                SET_A8(r, value35);
                r->z = value35 == 0;
                r->n = value35 & 0x80;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            c->fail = 3;
            return;
        }
    }
    if (m_ret7) {
        uint8_t value36 = RAM8(0x0000 + sp0);
        SET_A8(r, value36);
        r->z = value36 == 0;
        r->n = value36 & 0x80;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
    shared_BC08_2:;
    uint16_t value37 = BUS16_RDP(c, (uint16_t)(direct_page_bc083 + 0x1F));
    RAM8(0x0000 + sp0) = value37 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value37;
    BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), 0);
    r->a = value37;
    r->x = x_bc083;
    r->y = y_bc083;
    r->c = 1;
    r->z = value37 == 0;
    r->n = value37 & 0x8000;
    r->v = overflow_bc083;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_bc083;
    r->dp = direct_page_bc083;
    r->i = irq_disable_bc083;
    r->d = decimal_bc083;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 2;
    bool m_ret9 = r->mf;
    uint16_t a_all10 = r->a;
    bool carry_ret10 = r->c;
    if (carry_ret10) {
        if (m_ret9) {
            BUS8_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), RAM8(0x0000 + sp0 - 1));
            uint8_t value39 = BUS8_RDP(c, (uint16_t)(direct_page_bc083 + 0x1E));
            RAM8(0x0000 + sp0 - 1) = value39;
            BUS8_SET(c, (uint16_t)(direct_page_bc083 + 0x1E), 0);
            r->a = (a_all10 >> 8 << 8) | value39;
            r->c = 1;
            r->z = value39 == 0;
            r->n = value39 & 0x80;
            r->mf = 1;
            r->sp -= 2;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret5 = r->dp;
            bool m_ret10 = r->mf;
            bool carry_ret11 = r->c;
            if (carry_ret11) {
                if (m_ret10) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value41 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value42 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret5 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret5 + 0x1F), 0);
                    r->a = (value42 << 8) | value41;
                    r->c = 1;
                    r->z = ((value42 << 8) | value41) == 0;
                    r->n = ((value42 << 8) | value41) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret10) {
                c->fail = 3;
                return;
            } else {
                uint8_t value44 = RAM8(0x0000 + sp0 - 1);
                uint8_t value45 = RAM8(0x0000 + sp0);
                r->a = (value45 << 8) | value44;
                r->z = ((value45 << 8) | value44) == 0;
                r->n = ((value45 << 8) | value44) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1));
            uint16_t value48 = BUS16_RDP(c, (uint16_t)(direct_page_bc083 + 0x1E));
            RAM8(0x0000 + sp0) = value48 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)value48;
            BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1E), 0);
            r->a = value48;
            r->c = 1;
            r->z = value48 == 0;
            r->n = value48 & 0x8000;
            r->mf = 0;
            r->sp -= 2;
            if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret6 = r->dp;
            bool m_ret11 = r->mf;
            bool carry_ret12 = r->c;
            if (carry_ret12) {
                if (m_ret11) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value50 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value51 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret6 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret6 + 0x1F), 0);
                    r->a = (value51 << 8) | value50;
                    r->c = 1;
                    r->z = ((value51 << 8) | value50) == 0;
                    r->n = ((value51 << 8) | value50) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret11) {
                c->fail = 3;
                return;
            } else {
                uint8_t value53 = RAM8(0x0000 + sp0 - 1);
                uint8_t value54 = RAM8(0x0000 + sp0);
                r->a = (value54 << 8) | value53;
                r->z = ((value54 << 8) | value53) == 0;
                r->n = ((value54 << 8) | value53) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
    if (m_ret9) {
        c->fail = 3;
        return;
    } else {
        uint8_t value56 = RAM8(0x0000 + sp0 - 1);
        uint8_t value57 = RAM8(0x0000 + sp0);
        r->a = (value57 << 8) | value56;
        r->z = ((value57 << 8) | value56) == 0;
        r->n = ((value57 << 8) | value56) & 0x8000;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    shared_BC08_3:;
    uint16_t value58 = BUS16_RDP(c, (uint16_t)(direct_page_bc084 + 0x1F));
    RAM8(0x0000 + sp0) = value58 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value58;
    BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), 0);
    r->a = value58;
    r->x = x_bc084;
    r->y = y_bc084;
    r->c = 1;
    r->z = value58 == 0;
    r->n = value58 & 0x8000;
    r->v = overflow_bc084;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_bc084;
    r->dp = direct_page_bc084;
    r->i = irq_disable_bc084;
    r->d = decimal_bc084;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 2;
    bool m_ret12 = r->mf;
    uint16_t a_all13 = r->a;
    bool carry_ret13 = r->c;
    if (carry_ret13) {
        if (m_ret12) {
            BUS8_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), RAM8(0x0000 + sp0 - 1));
            uint8_t value60 = BUS8_RDP(c, (uint16_t)(direct_page_bc084 + 0x1E));
            RAM8(0x0000 + sp0 - 1) = value60;
            BUS8_SET(c, (uint16_t)(direct_page_bc084 + 0x1E), 0);
            r->a = (a_all13 >> 8 << 8) | value60;
            r->c = 1;
            r->z = value60 == 0;
            r->n = value60 & 0x80;
            r->mf = 1;
            r->sp -= 2;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret7 = r->dp;
            bool m_ret13 = r->mf;
            bool carry_ret14 = r->c;
            if (carry_ret14) {
                if (m_ret13) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value62 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value63 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret7 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret7 + 0x1F), 0);
                    r->a = (value63 << 8) | value62;
                    r->c = 1;
                    r->z = ((value63 << 8) | value62) == 0;
                    r->n = ((value63 << 8) | value62) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret13) {
                c->fail = 3;
                return;
            } else {
                uint8_t value65 = RAM8(0x0000 + sp0 - 1);
                uint8_t value66 = RAM8(0x0000 + sp0);
                r->a = (value66 << 8) | value65;
                r->z = ((value66 << 8) | value65) == 0;
                r->n = ((value66 << 8) | value65) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1));
            uint16_t value69 = BUS16_RDP(c, (uint16_t)(direct_page_bc084 + 0x1E));
            RAM8(0x0000 + sp0) = value69 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)value69;
            BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1E), 0);
            r->a = value69;
            r->c = 1;
            r->z = value69 == 0;
            r->n = value69 & 0x8000;
            r->mf = 0;
            r->sp -= 2;
            if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret8 = r->dp;
            bool m_ret14 = r->mf;
            bool carry_ret15 = r->c;
            if (carry_ret15) {
                if (m_ret14) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value71 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value72 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret8 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret8 + 0x1F), 0);
                    r->a = (value72 << 8) | value71;
                    r->c = 1;
                    r->z = ((value72 << 8) | value71) == 0;
                    r->n = ((value72 << 8) | value71) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret14) {
                c->fail = 3;
                return;
            } else {
                uint8_t value74 = RAM8(0x0000 + sp0 - 1);
                uint8_t value75 = RAM8(0x0000 + sp0);
                r->a = (value75 << 8) | value74;
                r->z = ((value75 << 8) | value74) == 0;
                r->n = ((value75 << 8) | value74) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
    if (m_ret12) {
        c->fail = 3;
        return;
    } else {
        uint8_t value77 = RAM8(0x0000 + sp0 - 1);
        uint8_t value78 = RAM8(0x0000 + sp0);
        r->a = (value78 << 8) | value77;
        r->z = ((value78 << 8) | value77) == 0;
        r->n = ((value78 << 8) | value77) & 0x8000;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}

/* C1BAE2 test_actor_vertical_footprint_and_redirect_step_v5   [class A, 306 bytes, 169 instructions]
 * Source: src/rom/test_actor_horizontal_footprint_and_redirect_step.s
 * Subroutine of test_actor_horizontal_footprint_and_redirect_step, translated in place.
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void test_actor_vertical_footprint_and_redirect_step_v5(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a_bb89 = 0;
    uint8_t a_hi_bb89 = 0;
    uint8_t x_bb89 = 0;
    uint8_t y_bb89 = 0;
    bool zero_bb89 = 0;
    bool negative_bb89 = 0;
    bool overflow_bb89 = 0;
    bool irq_disable_bb89 = 0;
    bool decimal_bb89 = 0;
    uint8_t a_bb892 = 0;
    uint8_t a_hi_bb892 = 0;
    uint16_t x_bb892 = 0;
    uint16_t y_bb892 = 0;
    bool zero_bb892 = 0;
    bool negative_bb892 = 0;
    bool overflow_bb892 = 0;
    bool irq_disable_bb892 = 0;
    bool decimal_bb892 = 0;
    uint8_t a_bb893 = 0;
    uint8_t a_hi_bb893 = 0;
    uint8_t x_bb893 = 0;
    uint8_t y_bb893 = 0;
    bool zero_bb893 = 0;
    bool negative_bb893 = 0;
    bool overflow_bb893 = 0;
    bool irq_disable_bb893 = 0;
    bool decimal_bb893 = 0;
    uint8_t a_bb894 = 0;
    uint8_t a_hi_bb894 = 0;
    uint16_t x_bb894 = 0;
    uint16_t y_bb894 = 0;
    bool zero_bb894 = 0;
    bool negative_bb894 = 0;
    bool overflow_bb894 = 0;
    bool irq_disable_bb894 = 0;
    bool decimal_bb894 = 0;
    uint8_t a_bb87 = 0;
    uint8_t a_hi_bb87 = 0;
    uint8_t x_bb87 = 0;
    uint8_t y_bb87 = 0;
    bool zero_bb87 = 0;
    bool negative_bb87 = 0;
    bool overflow_bb87 = 0;
    bool irq_disable_bb87 = 0;
    bool decimal_bb87 = 0;
    uint8_t a_bb872 = 0;
    uint8_t a_hi_bb872 = 0;
    uint16_t x_bb872 = 0;
    uint16_t y_bb872 = 0;
    bool zero_bb872 = 0;
    bool negative_bb872 = 0;
    bool overflow_bb872 = 0;
    bool irq_disable_bb872 = 0;
    bool decimal_bb872 = 0;
    uint8_t a_bbfb = 0;
    uint8_t a_hi_bbfb = 0;
    uint8_t x_bbfb = 0;
    uint8_t y_bbfb = 0;
    bool zero_bbfb = 0;
    bool negative_bbfb = 0;
    bool overflow_bbfb = 0;
    bool irq_disable_bbfb = 0;
    bool decimal_bbfb = 0;
    uint8_t a_bbfb2 = 0;
    uint8_t a_hi_bbfb2 = 0;
    uint16_t x_bbfb2 = 0;
    uint16_t y_bbfb2 = 0;
    bool zero_bbfb2 = 0;
    bool negative_bbfb2 = 0;
    bool overflow_bbfb2 = 0;
    bool irq_disable_bbfb2 = 0;
    bool decimal_bbfb2 = 0;
    uint8_t a_bb99 = 0;
    uint8_t a_hi_bb99 = 0;
    bool irq_disable_bb99 = 0;
    bool decimal_bb99 = 0;
    uint8_t a_bb992 = 0;
    uint8_t a_hi_bb992 = 0;
    bool irq_disable_bb992 = 0;
    bool decimal_bb992 = 0;
    uint8_t a_bb873 = 0;
    uint8_t a_hi_bb873 = 0;
    uint8_t x_bb873 = 0;
    uint8_t y_bb873 = 0;
    bool zero_bb873 = 0;
    bool negative_bb873 = 0;
    bool overflow_bb873 = 0;
    bool irq_disable_bb873 = 0;
    bool decimal_bb873 = 0;
    uint8_t a_bb874 = 0;
    uint8_t a_hi_bb874 = 0;
    uint16_t x_bb874 = 0;
    uint16_t y_bb874 = 0;
    bool zero_bb874 = 0;
    bool negative_bb874 = 0;
    bool overflow_bb874 = 0;
    bool irq_disable_bb874 = 0;
    bool decimal_bb874 = 0;
    uint8_t a_hi_bc08 = 0;
    uint8_t x_bc08 = 0;
    uint8_t y_bc08 = 0;
    bool overflow_bc08 = 0;
    uint16_t direct_page_bc08 = 0;
    uint8_t data_bank_bc08 = 0;
    bool irq_disable_bc08 = 0;
    bool decimal_bc08 = 0;
    uint8_t a_hi_bc082 = 0;
    uint16_t x_bc082 = 0;
    uint16_t y_bc082 = 0;
    bool overflow_bc082 = 0;
    uint16_t direct_page_bc082 = 0;
    uint8_t data_bank_bc082 = 0;
    bool irq_disable_bc082 = 0;
    bool decimal_bc082 = 0;
    uint8_t a_hi_bc083 = 0;
    uint8_t x_bc083 = 0;
    uint8_t y_bc083 = 0;
    bool overflow_bc083 = 0;
    uint16_t direct_page_bc083 = 0;
    uint8_t data_bank_bc083 = 0;
    bool irq_disable_bc083 = 0;
    bool decimal_bc083 = 0;
    uint8_t a_hi_bc084 = 0;
    uint16_t x_bc084 = 0;
    uint16_t y_bc084 = 0;
    bool overflow_bc084 = 0;
    uint16_t direct_page_bc084 = 0;
    uint8_t data_bank_bc084 = 0;
    bool irq_disable_bc084 = 0;
    bool decimal_bc084 = 0;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
    uint8_t a3;
    uint8_t a_hi3;
    if ((uint8_t)(value + 4) >= 0x80) {
        uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
        uint8_t a1;
        uint8_t a_hi1;
        if (!((uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) & 0x8000)) {
            a1 = (uint8_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1);
            a_hi1 = (uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) >> 8;
        } else {
            uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp + 0xC2));
            a1 = (uint8_t)((uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) + value3);
            a_hi1 = (uint16_t)((uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) + value3) >> 8;
        }
        a3 = a1;
        a_hi3 = a_hi1;
    } else {
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 0xC2));
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) < value5) {
            a2 = (uint8_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4);
            a_hi2 = (uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) >> 8;
        } else {
            uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp + 0xC2));
            a2 = (uint8_t)((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) - value6 - ((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) >= value5 ^ 1));
            a_hi2 = (uint16_t)((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) - value6 - ((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) >= value5 ^ 1)) >> 8;
        }
        a3 = a2;
        a_hi3 = a_hi2;
    }
    BUS16_SET(c, (uint16_t)(dp + 4), (a_hi3 << 8) | a3);
    BUS16_SET(c, (uint16_t)(dp + 8), (((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1);
    uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
    uint8_t a4;
    if (!(value7 & 0x80)) {
        a4 = value7;
    } else {
        a4 = (uint8_t)((value7 ^ 0x7F) + 1);
    }
    BUS8_SET(c, dp, a4);
    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp + 0x1A));
    uint8_t value9 = BUS8_RDP(c, dp);
    uint8_t a7;
    uint8_t a_hi6;
    if (!((uint8_t)((value8 >> 1) + value9) & 0x80)) {
        uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp + 0x12));
        uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp + 0xC0));
        uint8_t a5;
        uint8_t a_hi4;
        if ((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10) < value11) {
            a5 = (uint8_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10);
            a_hi4 = (uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10) >> 8;
        } else {
            uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp + 0xC0));
            a5 = (uint8_t)((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10) - value12 - ((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10) >= value11 ^ 1));
            a_hi4 = (uint16_t)((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10) - value12 - ((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10) >= value11 ^ 1)) >> 8;
        }
        a7 = a5;
        a_hi6 = a_hi4;
    } else {
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp + 0x12));
        uint8_t a6;
        uint8_t a_hi5;
        if (!((uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9) | 0xFF00) + value13) & 0x8000)) {
            a6 = (uint8_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9) | 0xFF00) + value13);
            a_hi5 = (uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9) | 0xFF00) + value13) >> 8;
        } else {
            uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp + 0xC0));
            a6 = (uint8_t)((uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9) | 0xFF00) + value13) + value14);
            a_hi5 = (uint16_t)((uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9) | 0xFF00) + value13) + value14) >> 8;
        }
        a7 = a6;
        a_hi6 = a_hi5;
    }
    RAM8(0x0000 + sp0 - 1) = a_hi6;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)((a_hi6 << 8) | a7);
    uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 4));
    BUS16_SET(c, (uint16_t)(dp + 4), ((value15 << 8) | a7) & 0x0F0F);
    uint8_t value16 = RAM8(0x0000 + sp0 - 2);
    uint8_t value17 = RAM8(0x0000 + sp0 - 1);
    uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp + 8));
    BUS16_SET(c, (uint16_t)(dp + 8), ((((value17 << 8) | value16) >> 4) & 0x7F) | value18);
    uint16_t value19 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x0C)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x0A)) + (((((value17 << 8) | value16) >> 4) & 0x7F) | value18), BUS8_RDP(c, (uint16_t)(dp + 0x0C)));
    uint8_t value20 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x0F)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x0D)) + ((value19 & 0xFF) << 1 << 1), BUS8_RDP(c, (uint16_t)(dp + 0x0F)));
    BUS8_SET(c, (uint16_t)(dp + 7), value20);
    uint8_t value21 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x0F)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x0D)) + (((value19 & 0xFF) << 1 << 1) + 2), BUS8_RDP(c, (uint16_t)(dp + 0x0F)));
    BUS8_SET(c, (uint16_t)(dp + 6), value21);
    if ((value21 & 0xF0) != 0x10) {
        BUS8_SET(c, (uint16_t)(dp + 6), 0);
    }
    r->a = (value19 & 0xFF) << 1 << 1 >> 8 << 8 | (value21 & 0xF0);
    r->y = ((value19 & 0xFF) << 1 << 1) + 2;
    r->c = (value21 & 0xF0) >= 0x10;
    r->z = (value21 & 0xF0) == 0x10;
    r->n = (uint8_t)((value21 & 0xF0) - 0x10) & 0x80;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBB7A, 0xC1BC37); GUARD_JSR(c, sp_call, 0xBB7A); } /* test_horizontal_terrain_shape_and_preceding_cells */
    r->sp += 1;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    if (carry_ret) {
        uint8_t value22 = RAM8(0x0000 + sp0);
        if (value22 & 0x01) {
            if (value22 & 0x20) {
                if (value22 & 0x10) {
                    a_bb89 = (uint8_t)a_all;
                    a_hi_bb89 = a_all >> 8;
                    x_bb89 = (uint8_t)x;
                    y_bb89 = (uint8_t)y_ret;
                    zero_bb89 = value22 & 0x02;
                    negative_bb89 = value22 & 0x80;
                    overflow_bb89 = value22 & 0x40;
                    irq_disable_bb89 = value22 & 0x04;
                    decimal_bb89 = value22 & 0x08;
                    goto shared_BB89;
                } else {
                    a_bb892 = (uint8_t)a_all;
                    a_hi_bb892 = a_all >> 8;
                    x_bb892 = x;
                    y_bb892 = y_ret;
                    zero_bb892 = value22 & 0x02;
                    negative_bb892 = value22 & 0x80;
                    overflow_bb892 = value22 & 0x40;
                    irq_disable_bb892 = value22 & 0x04;
                    decimal_bb892 = value22 & 0x08;
                    goto shared_BB89_1;
                }
            } else {
                if (value22 & 0x10) {
                    a_bb893 = (uint8_t)a_all;
                    a_hi_bb893 = a_all >> 8;
                    x_bb893 = (uint8_t)x;
                    y_bb893 = (uint8_t)y_ret;
                    zero_bb893 = value22 & 0x02;
                    negative_bb893 = value22 & 0x80;
                    overflow_bb893 = value22 & 0x40;
                    irq_disable_bb893 = value22 & 0x04;
                    decimal_bb893 = value22 & 0x08;
                    goto shared_BB89_2;
                } else {
                    a_bb894 = (uint8_t)a_all;
                    a_hi_bb894 = a_all >> 8;
                    x_bb894 = x;
                    y_bb894 = y_ret;
                    zero_bb894 = value22 & 0x02;
                    negative_bb894 = value22 & 0x80;
                    overflow_bb894 = value22 & 0x40;
                    irq_disable_bb894 = value22 & 0x04;
                    decimal_bb894 = value22 & 0x08;
                    goto shared_BB89_3;
                }
            }
        }
        if (value22 & 0x20) {
            uint8_t value23 = BUS8_RDP(c, (uint16_t)(dp + 2));
            if (value23 != 0) {
                if (value23 < 8) {
                    uint8_t value24 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                    if (value24 & 0x80) {
                        if (value23 != 5) {
                            if (value23 != 6) {
                                if (value22 & 0x10) {
                                    a_bb87 = value23;
                                    a_hi_bb87 = a_all >> 8;
                                    x_bb87 = (uint8_t)x;
                                    y_bb87 = (uint8_t)y_ret;
                                    zero_bb87 = value23 == 6;
                                    negative_bb87 = (uint8_t)(value23 - 6) & 0x80;
                                    overflow_bb87 = value24 & 0x40;
                                    irq_disable_bb87 = value22 & 0x04;
                                    decimal_bb87 = value22 & 0x08;
                                    goto shared_BB87;
                                } else {
                                    a_bb872 = value23;
                                    a_hi_bb872 = a_all >> 8;
                                    x_bb872 = x;
                                    y_bb872 = y_ret;
                                    zero_bb872 = value23 == 6;
                                    negative_bb872 = (uint8_t)(value23 - 6) & 0x80;
                                    overflow_bb872 = value24 & 0x40;
                                    irq_disable_bb872 = value22 & 0x04;
                                    decimal_bb872 = value22 & 0x08;
                                    goto shared_BB87_1;
                                }
                            }
                            uint8_t value25 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                            BUS8_SET(c, (uint16_t)(dp + 0x1E), value25 ^ 0x80);
                            uint8_t value26 = BUS8_RDP(c, (uint16_t)(dp + 0x1C));
                            BUS8_SET(c, (uint16_t)(dp + 0x1C), (uint8_t)(value26 + 1));
                            if (value22 & 0x10) {
                                a_bbfb = value25 ^ 0x80;
                                a_hi_bbfb = a_all >> 8;
                                x_bbfb = (uint8_t)x;
                                y_bbfb = (uint8_t)y_ret;
                                zero_bbfb = (uint8_t)(value26 + 1) == 0;
                                negative_bbfb = (uint8_t)(value26 + 1) & 0x80;
                                overflow_bbfb = value24 & 0x40;
                                irq_disable_bbfb = value22 & 0x04;
                                decimal_bbfb = value22 & 0x08;
                                goto shared_BBFB;
                            } else {
                                a_bbfb2 = value25 ^ 0x80;
                                a_hi_bbfb2 = a_all >> 8;
                                x_bbfb2 = x;
                                y_bbfb2 = y_ret;
                                zero_bbfb2 = (uint8_t)(value26 + 1) == 0;
                                negative_bbfb2 = (uint8_t)(value26 + 1) & 0x80;
                                overflow_bbfb2 = value24 & 0x40;
                                irq_disable_bbfb2 = value22 & 0x04;
                                decimal_bbfb2 = value22 & 0x08;
                                goto shared_BBFB_1;
                            }
                        }
                        uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                        BUS8_SET(c, (uint16_t)(dp + 0x1E), value27);
                        uint8_t value28 = BUS8_RDP(c, (uint16_t)(dp + 0x1C));
                        BUS8_SET(c, (uint16_t)(dp + 0x1C), (uint8_t)(value28 + 1));
                        if (value22 & 0x10) {
                            a_bbfb = value27;
                            a_hi_bbfb = a_all >> 8;
                            x_bbfb = (uint8_t)x;
                            y_bbfb = (uint8_t)y_ret;
                            zero_bbfb = (uint8_t)(value28 + 1) == 0;
                            negative_bbfb = (uint8_t)(value28 + 1) & 0x80;
                            overflow_bbfb = value24 & 0x40;
                            irq_disable_bbfb = value22 & 0x04;
                            decimal_bbfb = value22 & 0x08;
                            goto shared_BBFB;
                        } else {
                            a_bbfb2 = value27;
                            a_hi_bbfb2 = a_all >> 8;
                            x_bbfb2 = x;
                            y_bbfb2 = y_ret;
                            zero_bbfb2 = (uint8_t)(value28 + 1) == 0;
                            negative_bbfb2 = (uint8_t)(value28 + 1) & 0x80;
                            overflow_bbfb2 = value24 & 0x40;
                            irq_disable_bbfb2 = value22 & 0x04;
                            decimal_bbfb2 = value22 & 0x08;
                            goto shared_BBFB_1;
                        }
                    }
                    if (value23 != 4) {
                        if (value23 != 7) {
                            if (value22 & 0x10) {
                                a_bb87 = value23;
                                a_hi_bb87 = a_all >> 8;
                                x_bb87 = (uint8_t)x;
                                y_bb87 = (uint8_t)y_ret;
                                zero_bb87 = value23 == 7;
                                negative_bb87 = (uint8_t)(value23 - 7) & 0x80;
                                overflow_bb87 = value24 & 0x40;
                                irq_disable_bb87 = value22 & 0x04;
                                decimal_bb87 = value22 & 0x08;
                                goto shared_BB87;
                            } else {
                                a_bb872 = value23;
                                a_hi_bb872 = a_all >> 8;
                                x_bb872 = x;
                                y_bb872 = y_ret;
                                zero_bb872 = value23 == 7;
                                negative_bb872 = (uint8_t)(value23 - 7) & 0x80;
                                overflow_bb872 = value24 & 0x40;
                                irq_disable_bb872 = value22 & 0x04;
                                decimal_bb872 = value22 & 0x08;
                                goto shared_BB87_1;
                            }
                        }
                        uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                        BUS8_SET(c, (uint16_t)(dp + 0x1E), value29 ^ 0x80);
                        uint8_t value30 = BUS8_RDP(c, (uint16_t)(dp + 0x1C));
                        BUS8_SET(c, (uint16_t)(dp + 0x1C), (uint8_t)(value30 + 1));
                        if (value22 & 0x10) {
                            a_bbfb = value29 ^ 0x80;
                            a_hi_bbfb = a_all >> 8;
                            x_bbfb = (uint8_t)x;
                            y_bbfb = (uint8_t)y_ret;
                            zero_bbfb = (uint8_t)(value30 + 1) == 0;
                            negative_bbfb = (uint8_t)(value30 + 1) & 0x80;
                            overflow_bbfb = value24 & 0x40;
                            irq_disable_bbfb = value22 & 0x04;
                            decimal_bbfb = value22 & 0x08;
                            goto shared_BBFB;
                        } else {
                            a_bbfb2 = value29 ^ 0x80;
                            a_hi_bbfb2 = a_all >> 8;
                            x_bbfb2 = x;
                            y_bbfb2 = y_ret;
                            zero_bbfb2 = (uint8_t)(value30 + 1) == 0;
                            negative_bbfb2 = (uint8_t)(value30 + 1) & 0x80;
                            overflow_bbfb2 = value24 & 0x40;
                            irq_disable_bbfb2 = value22 & 0x04;
                            decimal_bbfb2 = value22 & 0x08;
                            goto shared_BBFB_1;
                        }
                    }
                    uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                    BUS8_SET(c, (uint16_t)(dp + 0x1E), value31);
                    uint8_t value32 = BUS8_RDP(c, (uint16_t)(dp + 0x1C));
                    BUS8_SET(c, (uint16_t)(dp + 0x1C), (uint8_t)(value32 + 1));
                    if (value22 & 0x10) {
                        a_bbfb = value31;
                        a_hi_bbfb = a_all >> 8;
                        x_bbfb = (uint8_t)x;
                        y_bbfb = (uint8_t)y_ret;
                        zero_bbfb = (uint8_t)(value32 + 1) == 0;
                        negative_bbfb = (uint8_t)(value32 + 1) & 0x80;
                        overflow_bbfb = value24 & 0x40;
                        irq_disable_bbfb = value22 & 0x04;
                        decimal_bbfb = value22 & 0x08;
                        goto shared_BBFB;
                    } else {
                        a_bbfb2 = value31;
                        a_hi_bbfb2 = a_all >> 8;
                        x_bbfb2 = x;
                        y_bbfb2 = y_ret;
                        zero_bbfb2 = (uint8_t)(value32 + 1) == 0;
                        negative_bbfb2 = (uint8_t)(value32 + 1) & 0x80;
                        overflow_bbfb2 = value24 & 0x40;
                        irq_disable_bbfb2 = value22 & 0x04;
                        decimal_bbfb2 = value22 & 0x08;
                        goto shared_BBFB_1;
                    }
                }
                if (value23 == 8) {
                    uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                    if (value22 & 0x10) {
                        a_bb99 = value33;
                        a_hi_bb99 = a_all >> 8;
                        irq_disable_bb99 = value22 & 0x04;
                        decimal_bb99 = value22 & 0x08;
                        goto shared_BB99;
                    } else {
                        a_bb992 = value33;
                        a_hi_bb992 = a_all >> 8;
                        irq_disable_bb992 = value22 & 0x04;
                        decimal_bb992 = value22 & 0x08;
                        goto shared_BB99_1;
                    }
                }
                if (value23 != 9) {
                    if (value22 & 0x10) {
                        a_bb87 = value23;
                        a_hi_bb87 = a_all >> 8;
                        x_bb87 = (uint8_t)x;
                        y_bb87 = (uint8_t)y_ret;
                        zero_bb87 = value23 == 9;
                        negative_bb87 = (uint8_t)(value23 - 9) & 0x80;
                        overflow_bb87 = value22 & 0x40;
                        irq_disable_bb87 = value22 & 0x04;
                        decimal_bb87 = value22 & 0x08;
                        goto shared_BB87;
                    } else {
                        a_bb872 = value23;
                        a_hi_bb872 = a_all >> 8;
                        x_bb872 = x;
                        y_bb872 = y_ret;
                        zero_bb872 = value23 == 9;
                        negative_bb872 = (uint8_t)(value23 - 9) & 0x80;
                        overflow_bb872 = value22 & 0x40;
                        irq_disable_bb872 = value22 & 0x04;
                        decimal_bb872 = value22 & 0x08;
                        goto shared_BB87_1;
                    }
                }
                uint8_t value34 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                if (value22 & 0x10) {
                    a_bb99 = value34 ^ 0x80;
                    a_hi_bb99 = a_all >> 8;
                    irq_disable_bb99 = value22 & 0x04;
                    decimal_bb99 = value22 & 0x08;
                    goto shared_BB99;
                } else {
                    a_bb992 = value34 ^ 0x80;
                    a_hi_bb992 = a_all >> 8;
                    irq_disable_bb992 = value22 & 0x04;
                    decimal_bb992 = value22 & 0x08;
                    goto shared_BB99_1;
                }
            }
            if (value22 & 0x10) {
                a_bb87 = value23;
                a_hi_bb87 = a_all >> 8;
                x_bb87 = (uint8_t)x;
                y_bb87 = (uint8_t)y_ret;
                zero_bb87 = value23 == 0;
                negative_bb87 = value23 & 0x80;
                overflow_bb87 = value22 & 0x40;
                irq_disable_bb87 = value22 & 0x04;
                decimal_bb87 = value22 & 0x08;
                goto shared_BB87;
            } else {
                a_bb872 = value23;
                a_hi_bb872 = a_all >> 8;
                x_bb872 = x;
                y_bb872 = y_ret;
                zero_bb872 = value23 == 0;
                negative_bb872 = value23 & 0x80;
                overflow_bb872 = value22 & 0x40;
                irq_disable_bb872 = value22 & 0x04;
                decimal_bb872 = value22 & 0x08;
                goto shared_BB87_1;
            }
        } else {
            uint16_t value35 = BUS16_RDP(c, (uint16_t)(dp + 2));
            if (value35 != 0) {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
            if (value22 & 0x10) {
                a_bb873 = (uint8_t)value35;
                a_hi_bb873 = value35 >> 8;
                x_bb873 = (uint8_t)x;
                y_bb873 = (uint8_t)y_ret;
                zero_bb873 = value35 == 0;
                negative_bb873 = value35 & 0x8000;
                overflow_bb873 = value22 & 0x40;
                irq_disable_bb873 = value22 & 0x04;
                decimal_bb873 = value22 & 0x08;
                goto shared_BB87_2;
            } else {
                a_bb874 = (uint8_t)value35;
                a_hi_bb874 = value35 >> 8;
                x_bb874 = x;
                y_bb874 = y_ret;
                zero_bb874 = value35 == 0;
                negative_bb874 = value35 & 0x8000;
                overflow_bb874 = value22 & 0x40;
                irq_disable_bb874 = value22 & 0x04;
                decimal_bb874 = value22 & 0x08;
                goto shared_BB87_3;
            }
        }
    }
    uint8_t value36 = RAM8(0x0000 + sp0);
    r->c = 0;
    r->z = value36 & 0x02;
    r->n = value36 & 0x80;
    r->v = value36 & 0x40;
    r->mf = value36 & 0x20;
    r->xf = value36 & 0x10;
    r->i = value36 & 0x04;
    r->d = value36 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BB89:;
    r->a = (a_hi_bb89 << 8) | a_bb89;
    r->x = x_bb89;
    r->y = y_bb89;
    r->c = 1;
    r->z = zero_bb89;
    r->n = negative_bb89;
    r->v = overflow_bb89;
    r->mf = 1;
    r->xf = 1;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bb89;
    r->d = decimal_bb89;
    RETURN_RTS(c);
    shared_BB89_1:;
    r->a = (a_hi_bb892 << 8) | a_bb892;
    r->x = x_bb892;
    r->y = y_bb892;
    r->c = 1;
    r->z = zero_bb892;
    r->n = negative_bb892;
    r->v = overflow_bb892;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bb892;
    r->d = decimal_bb892;
    RETURN_RTS(c);
    shared_BB89_2:;
    r->a = (a_hi_bb893 << 8) | a_bb893;
    r->x = x_bb893;
    r->y = y_bb893;
    r->c = 1;
    r->z = zero_bb893;
    r->n = negative_bb893;
    r->v = overflow_bb893;
    r->mf = 0;
    r->xf = 1;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bb893;
    r->d = decimal_bb893;
    RETURN_RTS(c);
    shared_BB89_3:;
    r->a = (a_hi_bb894 << 8) | a_bb894;
    r->x = x_bb894;
    r->y = y_bb894;
    r->c = 1;
    r->z = zero_bb894;
    r->n = negative_bb894;
    r->v = overflow_bb894;
    r->mf = 0;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bb894;
    r->d = decimal_bb894;
    RETURN_RTS(c);
    shared_BB87:;
    BUS8_SET(c, (uint16_t)(dp + 0x1F), 0);
    a_bb89 = a_bb87;
    a_hi_bb89 = a_hi_bb87;
    x_bb89 = x_bb87;
    y_bb89 = y_bb87;
    zero_bb89 = zero_bb87;
    negative_bb89 = negative_bb87;
    overflow_bb89 = overflow_bb87;
    irq_disable_bb89 = irq_disable_bb87;
    decimal_bb89 = decimal_bb87;
    goto shared_BB89;
    shared_BB87_1:;
    BUS8_SET(c, (uint16_t)(dp + 0x1F), 0);
    a_bb892 = a_bb872;
    a_hi_bb892 = a_hi_bb872;
    x_bb892 = x_bb872;
    y_bb892 = y_bb872;
    zero_bb892 = zero_bb872;
    negative_bb892 = negative_bb872;
    overflow_bb892 = overflow_bb872;
    irq_disable_bb892 = irq_disable_bb872;
    decimal_bb892 = decimal_bb872;
    goto shared_BB89_1;
    shared_BBFB:;
    r->a = (a_hi_bbfb << 8) | a_bbfb;
    r->x = x_bbfb;
    r->y = y_bbfb;
    r->c = 1;
    r->z = zero_bbfb;
    r->n = negative_bbfb;
    r->v = overflow_bbfb;
    r->mf = 1;
    r->xf = 1;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bbfb;
    r->d = decimal_bbfb;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBBFE, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBBFE); } /* test_actor_horizontal_footprint_and_redirect_step */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    if (carry_ret2) {
        if (m_ret) {
            if (x_ret) {
                a_hi_bc08 = a_all2 >> 8;
                x_bc08 = x_bbfb;
                y_bc08 = (uint8_t)y_ret2;
                overflow_bc08 = overflow_ret2;
                direct_page_bc08 = dp;
                data_bank_bc08 = db;
                irq_disable_bc08 = irq_disable_bbfb;
                decimal_bc08 = decimal_bbfb;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all2 >> 8;
                x_bc082 = x_bbfb;
                y_bc082 = y_ret2;
                overflow_bc082 = overflow_ret2;
                direct_page_bc082 = dp;
                data_bank_bc082 = db;
                irq_disable_bc082 = irq_disable_bbfb;
                decimal_bc082 = decimal_bbfb;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret) {
                a_hi_bc083 = a_all2 >> 8;
                x_bc083 = x_bbfb;
                y_bc083 = (uint8_t)y_ret2;
                overflow_bc083 = overflow_ret2;
                direct_page_bc083 = dp;
                data_bank_bc083 = db;
                irq_disable_bc083 = irq_disable_bbfb;
                decimal_bc083 = decimal_bbfb;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all2 >> 8;
                x_bc084 = x_bbfb;
                y_bc084 = y_ret2;
                overflow_bc084 = overflow_ret2;
                direct_page_bc084 = dp;
                data_bank_bc084 = db;
                irq_disable_bc084 = irq_disable_bbfb;
                decimal_bc084 = decimal_bbfb;
                goto shared_BC08_3;
            }
        }
    }
    r->c = 1;
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); }
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret2 = r->mf;
    bool x_ret2 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    if (carry_ret3) {
        if (m_ret2) {
            if (x_ret2) {
                a_hi_bc08 = a_all3 >> 8;
                x_bc08 = x_bbfb;
                y_bc08 = (uint8_t)y_ret3;
                overflow_bc08 = overflow_ret3;
                direct_page_bc08 = dp_ret;
                data_bank_bc08 = db_ret;
                irq_disable_bc08 = irq_disable_bbfb;
                decimal_bc08 = decimal_bbfb;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all3 >> 8;
                x_bc082 = x_bbfb;
                y_bc082 = y_ret3;
                overflow_bc082 = overflow_ret3;
                direct_page_bc082 = dp_ret;
                data_bank_bc082 = db_ret;
                irq_disable_bc082 = irq_disable_bbfb;
                decimal_bc082 = decimal_bbfb;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret2) {
                a_hi_bc083 = a_all3 >> 8;
                x_bc083 = x_bbfb;
                y_bc083 = (uint8_t)y_ret3;
                overflow_bc083 = overflow_ret3;
                direct_page_bc083 = dp_ret;
                data_bank_bc083 = db_ret;
                irq_disable_bc083 = irq_disable_bbfb;
                decimal_bc083 = decimal_bbfb;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all3 >> 8;
                x_bc084 = x_bbfb;
                y_bc084 = y_ret3;
                overflow_bc084 = overflow_ret3;
                direct_page_bc084 = dp_ret;
                data_bank_bc084 = db_ret;
                irq_disable_bc084 = irq_disable_bbfb;
                decimal_bc084 = decimal_bbfb;
                goto shared_BC08_3;
            }
        }
    }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BBFB_1:;
    r->a = (a_hi_bbfb2 << 8) | a_bbfb2;
    r->x = x_bbfb2;
    r->y = y_bbfb2;
    r->c = 1;
    r->z = zero_bbfb2;
    r->n = negative_bbfb2;
    r->v = overflow_bbfb2;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bbfb2;
    r->d = decimal_bbfb2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBBFE, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBBFE); } /* test_actor_horizontal_footprint_and_redirect_step */
    bool m_ret3 = r->mf;
    bool x_ret3 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t y_ret4 = r->y;
    bool carry_ret4 = r->c;
    bool overflow_ret4 = r->v;
    if (carry_ret4) {
        if (m_ret3) {
            if (x_ret3) {
                a_hi_bc08 = a_all4 >> 8;
                x_bc08 = (uint8_t)x_bbfb2;
                y_bc08 = (uint8_t)y_ret4;
                overflow_bc08 = overflow_ret4;
                direct_page_bc08 = dp;
                data_bank_bc08 = db;
                irq_disable_bc08 = irq_disable_bbfb2;
                decimal_bc08 = decimal_bbfb2;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all4 >> 8;
                x_bc082 = x_bbfb2;
                y_bc082 = y_ret4;
                overflow_bc082 = overflow_ret4;
                direct_page_bc082 = dp;
                data_bank_bc082 = db;
                irq_disable_bc082 = irq_disable_bbfb2;
                decimal_bc082 = decimal_bbfb2;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret3) {
                a_hi_bc083 = a_all4 >> 8;
                x_bc083 = (uint8_t)x_bbfb2;
                y_bc083 = (uint8_t)y_ret4;
                overflow_bc083 = overflow_ret4;
                direct_page_bc083 = dp;
                data_bank_bc083 = db;
                irq_disable_bc083 = irq_disable_bbfb2;
                decimal_bc083 = decimal_bbfb2;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all4 >> 8;
                x_bc084 = x_bbfb2;
                y_bc084 = y_ret4;
                overflow_bc084 = overflow_ret4;
                direct_page_bc084 = dp;
                data_bank_bc084 = db;
                irq_disable_bc084 = irq_disable_bbfb2;
                decimal_bc084 = decimal_bbfb2;
                goto shared_BC08_3;
            }
        }
    }
    r->c = 1;
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); }
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret4 = r->mf;
    bool x_ret4 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t y_ret5 = r->y;
    bool carry_ret5 = r->c;
    bool overflow_ret5 = r->v;
    if (carry_ret5) {
        if (m_ret4) {
            if (x_ret4) {
                a_hi_bc08 = a_all5 >> 8;
                x_bc08 = (uint8_t)x_bbfb2;
                y_bc08 = (uint8_t)y_ret5;
                overflow_bc08 = overflow_ret5;
                direct_page_bc08 = dp_ret2;
                data_bank_bc08 = db_ret2;
                irq_disable_bc08 = irq_disable_bbfb2;
                decimal_bc08 = decimal_bbfb2;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all5 >> 8;
                x_bc082 = x_bbfb2;
                y_bc082 = y_ret5;
                overflow_bc082 = overflow_ret5;
                direct_page_bc082 = dp_ret2;
                data_bank_bc082 = db_ret2;
                irq_disable_bc082 = irq_disable_bbfb2;
                decimal_bc082 = decimal_bbfb2;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret4) {
                a_hi_bc083 = a_all5 >> 8;
                x_bc083 = (uint8_t)x_bbfb2;
                y_bc083 = (uint8_t)y_ret5;
                overflow_bc083 = overflow_ret5;
                direct_page_bc083 = dp_ret2;
                data_bank_bc083 = db_ret2;
                irq_disable_bc083 = irq_disable_bbfb2;
                decimal_bc083 = decimal_bbfb2;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all5 >> 8;
                x_bc084 = x_bbfb2;
                y_bc084 = y_ret5;
                overflow_bc084 = overflow_ret5;
                direct_page_bc084 = dp_ret2;
                data_bank_bc084 = db_ret2;
                irq_disable_bc084 = irq_disable_bbfb2;
                decimal_bc084 = decimal_bbfb2;
                goto shared_BC08_3;
            }
        }
    }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BB99:;
    BUS8_SET(c, (uint16_t)(dp + 0x1E), a_bb99);
    BUS8_SET(c, (uint16_t)(dp + 0x1F), 0);
    uint8_t value37 = BUS8_RDP(c, (uint16_t)(dp + 0x1C));
    BUS8_SET(c, (uint16_t)(dp + 0x1C), (uint8_t)(value37 + 1));
    r->a = (a_hi_bb99 << 8) | a_bb99;
    r->c = 1;
    r->z = (uint8_t)(value37 + 1) == 0;
    r->n = (uint8_t)(value37 + 1) & 0x80;
    r->mf = 1;
    r->xf = 1;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bb99;
    r->d = decimal_bb99;
    TAIL_CALL(c, 0xC1B9EA, SOM_RTS); /* test_actor_horizontal_footprint_and_redirect_step */
    shared_BB99_1:;
    BUS8_SET(c, (uint16_t)(dp + 0x1E), a_bb992);
    BUS8_SET(c, (uint16_t)(dp + 0x1F), 0);
    uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp + 0x1C));
    BUS8_SET(c, (uint16_t)(dp + 0x1C), (uint8_t)(value38 + 1));
    r->a = (a_hi_bb992 << 8) | a_bb992;
    r->c = 1;
    r->z = (uint8_t)(value38 + 1) == 0;
    r->n = (uint8_t)(value38 + 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bb992;
    r->d = decimal_bb992;
    TAIL_CALL(c, 0xC1B9EA, SOM_RTS); /* test_actor_horizontal_footprint_and_redirect_step */
    shared_BB87_2:;
    BUS16_SET(c, (uint16_t)(dp + 0x1F), 0);
    a_bb893 = a_bb873;
    a_hi_bb893 = a_hi_bb873;
    x_bb893 = x_bb873;
    y_bb893 = y_bb873;
    zero_bb893 = zero_bb873;
    negative_bb893 = negative_bb873;
    overflow_bb893 = overflow_bb873;
    irq_disable_bb893 = irq_disable_bb873;
    decimal_bb893 = decimal_bb873;
    goto shared_BB89_2;
    shared_BB87_3:;
    BUS16_SET(c, (uint16_t)(dp + 0x1F), 0);
    a_bb894 = a_bb874;
    a_hi_bb894 = a_hi_bb874;
    x_bb894 = x_bb874;
    y_bb894 = y_bb874;
    zero_bb894 = zero_bb874;
    negative_bb894 = negative_bb874;
    overflow_bb894 = overflow_bb874;
    irq_disable_bb894 = irq_disable_bb874;
    decimal_bb894 = decimal_bb874;
    goto shared_BB89_3;
    shared_BC08:;
    uint8_t value39 = BUS8_RDP(c, (uint16_t)(direct_page_bc08 + 0x1F));
    RAM8(0x0000 + sp0) = value39;
    BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1F), 0);
    r->a = (a_hi_bc08 << 8) | value39;
    r->x = x_bc08;
    r->y = y_bc08;
    r->c = 1;
    r->z = value39 == 0;
    r->n = value39 & 0x80;
    r->v = overflow_bc08;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_bc08;
    r->dp = direct_page_bc08;
    r->i = irq_disable_bc08;
    r->d = decimal_bc08;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 1;
    bool m_ret5 = r->mf;
    uint16_t a_all6 = r->a;
    bool carry_ret6 = r->c;
    if (carry_ret6) {
        if (m_ret5) {
            BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1F), RAM8(0x0000 + sp0));
            uint8_t value41 = BUS8_RDP(c, (uint16_t)(direct_page_bc08 + 0x1E));
            RAM8(0x0000 + sp0) = value41;
            BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1E), 0);
            r->a = (a_all6 >> 8 << 8) | value41;
            r->c = 1;
            r->z = value41 == 0;
            r->n = value41 & 0x80;
            r->mf = 1;
            r->sp -= 1;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 1;
            uint16_t dp_ret3 = r->dp;
            bool m_ret6 = r->mf;
            bool carry_ret7 = r->c;
            if (carry_ret7) {
                if (m_ret6) {
                    uint8_t value42 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1E), 0);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1F), 0);
                    SET_A8(r, value42);
                    r->c = 1;
                    r->z = value42 == 0;
                    r->n = value42 & 0x80;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
            if (m_ret6) {
                uint8_t value43 = RAM8(0x0000 + sp0);
                SET_A8(r, value43);
                r->z = value43 == 0;
                r->n = value43 & 0x80;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            c->fail = 3;
            return;
        }
    }
    if (m_ret5) {
        uint8_t value44 = RAM8(0x0000 + sp0);
        SET_A8(r, value44);
        r->z = value44 == 0;
        r->n = value44 & 0x80;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
    shared_BC08_1:;
    uint8_t value45 = BUS8_RDP(c, (uint16_t)(direct_page_bc082 + 0x1F));
    RAM8(0x0000 + sp0) = value45;
    BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1F), 0);
    r->a = (a_hi_bc082 << 8) | value45;
    r->x = x_bc082;
    r->y = y_bc082;
    r->c = 1;
    r->z = value45 == 0;
    r->n = value45 & 0x80;
    r->v = overflow_bc082;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_bc082;
    r->dp = direct_page_bc082;
    r->i = irq_disable_bc082;
    r->d = decimal_bc082;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 1;
    bool m_ret7 = r->mf;
    uint16_t a_all8 = r->a;
    bool carry_ret8 = r->c;
    if (carry_ret8) {
        if (m_ret7) {
            BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1F), RAM8(0x0000 + sp0));
            uint8_t value47 = BUS8_RDP(c, (uint16_t)(direct_page_bc082 + 0x1E));
            RAM8(0x0000 + sp0) = value47;
            BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1E), 0);
            r->a = (a_all8 >> 8 << 8) | value47;
            r->c = 1;
            r->z = value47 == 0;
            r->n = value47 & 0x80;
            r->mf = 1;
            r->sp -= 1;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 1;
            uint16_t dp_ret4 = r->dp;
            bool m_ret8 = r->mf;
            bool carry_ret9 = r->c;
            if (carry_ret9) {
                if (m_ret8) {
                    uint8_t value48 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 0x1E), 0);
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 0x1F), 0);
                    SET_A8(r, value48);
                    r->c = 1;
                    r->z = value48 == 0;
                    r->n = value48 & 0x80;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
            if (m_ret8) {
                uint8_t value49 = RAM8(0x0000 + sp0);
                SET_A8(r, value49);
                r->z = value49 == 0;
                r->n = value49 & 0x80;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            c->fail = 3;
            return;
        }
    }
    if (m_ret7) {
        uint8_t value50 = RAM8(0x0000 + sp0);
        SET_A8(r, value50);
        r->z = value50 == 0;
        r->n = value50 & 0x80;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
    shared_BC08_2:;
    uint16_t value51 = BUS16_RDP(c, (uint16_t)(direct_page_bc083 + 0x1F));
    RAM8(0x0000 + sp0) = value51 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value51;
    BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), 0);
    r->a = value51;
    r->x = x_bc083;
    r->y = y_bc083;
    r->c = 1;
    r->z = value51 == 0;
    r->n = value51 & 0x8000;
    r->v = overflow_bc083;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_bc083;
    r->dp = direct_page_bc083;
    r->i = irq_disable_bc083;
    r->d = decimal_bc083;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 2;
    bool m_ret9 = r->mf;
    uint16_t a_all10 = r->a;
    bool carry_ret10 = r->c;
    if (carry_ret10) {
        if (m_ret9) {
            BUS8_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), RAM8(0x0000 + sp0 - 1));
            uint8_t value53 = BUS8_RDP(c, (uint16_t)(direct_page_bc083 + 0x1E));
            RAM8(0x0000 + sp0 - 1) = value53;
            BUS8_SET(c, (uint16_t)(direct_page_bc083 + 0x1E), 0);
            r->a = (a_all10 >> 8 << 8) | value53;
            r->c = 1;
            r->z = value53 == 0;
            r->n = value53 & 0x80;
            r->mf = 1;
            r->sp -= 2;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret5 = r->dp;
            bool m_ret10 = r->mf;
            bool carry_ret11 = r->c;
            if (carry_ret11) {
                if (m_ret10) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value55 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value56 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret5 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret5 + 0x1F), 0);
                    r->a = (value56 << 8) | value55;
                    r->c = 1;
                    r->z = ((value56 << 8) | value55) == 0;
                    r->n = ((value56 << 8) | value55) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret10) {
                c->fail = 3;
                return;
            } else {
                uint8_t value58 = RAM8(0x0000 + sp0 - 1);
                uint8_t value59 = RAM8(0x0000 + sp0);
                r->a = (value59 << 8) | value58;
                r->z = ((value59 << 8) | value58) == 0;
                r->n = ((value59 << 8) | value58) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1));
            uint16_t value62 = BUS16_RDP(c, (uint16_t)(direct_page_bc083 + 0x1E));
            RAM8(0x0000 + sp0) = value62 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)value62;
            BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1E), 0);
            r->a = value62;
            r->c = 1;
            r->z = value62 == 0;
            r->n = value62 & 0x8000;
            r->mf = 0;
            r->sp -= 2;
            if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret6 = r->dp;
            bool m_ret11 = r->mf;
            bool carry_ret12 = r->c;
            if (carry_ret12) {
                if (m_ret11) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value64 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value65 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret6 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret6 + 0x1F), 0);
                    r->a = (value65 << 8) | value64;
                    r->c = 1;
                    r->z = ((value65 << 8) | value64) == 0;
                    r->n = ((value65 << 8) | value64) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret11) {
                c->fail = 3;
                return;
            } else {
                uint8_t value67 = RAM8(0x0000 + sp0 - 1);
                uint8_t value68 = RAM8(0x0000 + sp0);
                r->a = (value68 << 8) | value67;
                r->z = ((value68 << 8) | value67) == 0;
                r->n = ((value68 << 8) | value67) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
    if (m_ret9) {
        c->fail = 3;
        return;
    } else {
        uint8_t value70 = RAM8(0x0000 + sp0 - 1);
        uint8_t value71 = RAM8(0x0000 + sp0);
        r->a = (value71 << 8) | value70;
        r->z = ((value71 << 8) | value70) == 0;
        r->n = ((value71 << 8) | value70) & 0x8000;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    shared_BC08_3:;
    uint16_t value72 = BUS16_RDP(c, (uint16_t)(direct_page_bc084 + 0x1F));
    RAM8(0x0000 + sp0) = value72 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value72;
    BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), 0);
    r->a = value72;
    r->x = x_bc084;
    r->y = y_bc084;
    r->c = 1;
    r->z = value72 == 0;
    r->n = value72 & 0x8000;
    r->v = overflow_bc084;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_bc084;
    r->dp = direct_page_bc084;
    r->i = irq_disable_bc084;
    r->d = decimal_bc084;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 2;
    bool m_ret12 = r->mf;
    uint16_t a_all13 = r->a;
    bool carry_ret13 = r->c;
    if (carry_ret13) {
        if (m_ret12) {
            BUS8_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), RAM8(0x0000 + sp0 - 1));
            uint8_t value74 = BUS8_RDP(c, (uint16_t)(direct_page_bc084 + 0x1E));
            RAM8(0x0000 + sp0 - 1) = value74;
            BUS8_SET(c, (uint16_t)(direct_page_bc084 + 0x1E), 0);
            r->a = (a_all13 >> 8 << 8) | value74;
            r->c = 1;
            r->z = value74 == 0;
            r->n = value74 & 0x80;
            r->mf = 1;
            r->sp -= 2;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret7 = r->dp;
            bool m_ret13 = r->mf;
            bool carry_ret14 = r->c;
            if (carry_ret14) {
                if (m_ret13) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value76 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value77 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret7 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret7 + 0x1F), 0);
                    r->a = (value77 << 8) | value76;
                    r->c = 1;
                    r->z = ((value77 << 8) | value76) == 0;
                    r->n = ((value77 << 8) | value76) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret13) {
                c->fail = 3;
                return;
            } else {
                uint8_t value79 = RAM8(0x0000 + sp0 - 1);
                uint8_t value80 = RAM8(0x0000 + sp0);
                r->a = (value80 << 8) | value79;
                r->z = ((value80 << 8) | value79) == 0;
                r->n = ((value80 << 8) | value79) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1));
            uint16_t value83 = BUS16_RDP(c, (uint16_t)(direct_page_bc084 + 0x1E));
            RAM8(0x0000 + sp0) = value83 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)value83;
            BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1E), 0);
            r->a = value83;
            r->c = 1;
            r->z = value83 == 0;
            r->n = value83 & 0x8000;
            r->mf = 0;
            r->sp -= 2;
            if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret8 = r->dp;
            bool m_ret14 = r->mf;
            bool carry_ret15 = r->c;
            if (carry_ret15) {
                if (m_ret14) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value85 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value86 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret8 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret8 + 0x1F), 0);
                    r->a = (value86 << 8) | value85;
                    r->c = 1;
                    r->z = ((value86 << 8) | value85) == 0;
                    r->n = ((value86 << 8) | value85) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret14) {
                c->fail = 3;
                return;
            } else {
                uint8_t value88 = RAM8(0x0000 + sp0 - 1);
                uint8_t value89 = RAM8(0x0000 + sp0);
                r->a = (value89 << 8) | value88;
                r->z = ((value89 << 8) | value88) == 0;
                r->n = ((value89 << 8) | value88) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
    if (m_ret12) {
        c->fail = 3;
        return;
    } else {
        uint8_t value91 = RAM8(0x0000 + sp0 - 1);
        uint8_t value92 = RAM8(0x0000 + sp0);
        r->a = (value92 << 8) | value91;
        r->z = ((value92 << 8) | value91) == 0;
        r->n = ((value92 << 8) | value91) & 0x8000;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}

/* C1BAE2 test_actor_vertical_footprint_and_redirect_step_v6   [class A, 306 bytes, 169 instructions]
 * Source: src/rom/test_actor_horizontal_footprint_and_redirect_step.s
 * Subroutine of test_actor_horizontal_footprint_and_redirect_step, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void test_actor_vertical_footprint_and_redirect_step_v6(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a_bb89 = 0;
    uint8_t a_hi_bb89 = 0;
    uint8_t x_bb89 = 0;
    uint8_t y_bb89 = 0;
    bool zero_bb89 = 0;
    bool negative_bb89 = 0;
    bool overflow_bb89 = 0;
    bool irq_disable_bb89 = 0;
    bool decimal_bb89 = 0;
    uint8_t a_bb892 = 0;
    uint8_t a_hi_bb892 = 0;
    uint16_t x_bb892 = 0;
    uint16_t y_bb892 = 0;
    bool zero_bb892 = 0;
    bool negative_bb892 = 0;
    bool overflow_bb892 = 0;
    bool irq_disable_bb892 = 0;
    bool decimal_bb892 = 0;
    uint8_t a_bb893 = 0;
    uint8_t a_hi_bb893 = 0;
    uint8_t x_bb893 = 0;
    uint8_t y_bb893 = 0;
    bool zero_bb893 = 0;
    bool negative_bb893 = 0;
    bool overflow_bb893 = 0;
    bool irq_disable_bb893 = 0;
    bool decimal_bb893 = 0;
    uint8_t a_bb894 = 0;
    uint8_t a_hi_bb894 = 0;
    uint16_t x_bb894 = 0;
    uint16_t y_bb894 = 0;
    bool zero_bb894 = 0;
    bool negative_bb894 = 0;
    bool overflow_bb894 = 0;
    bool irq_disable_bb894 = 0;
    bool decimal_bb894 = 0;
    uint8_t a_bb87 = 0;
    uint8_t a_hi_bb87 = 0;
    uint8_t x_bb87 = 0;
    uint8_t y_bb87 = 0;
    bool zero_bb87 = 0;
    bool negative_bb87 = 0;
    bool overflow_bb87 = 0;
    bool irq_disable_bb87 = 0;
    bool decimal_bb87 = 0;
    uint8_t a_bb872 = 0;
    uint8_t a_hi_bb872 = 0;
    uint16_t x_bb872 = 0;
    uint16_t y_bb872 = 0;
    bool zero_bb872 = 0;
    bool negative_bb872 = 0;
    bool overflow_bb872 = 0;
    bool irq_disable_bb872 = 0;
    bool decimal_bb872 = 0;
    uint8_t a_bbfb = 0;
    uint8_t a_hi_bbfb = 0;
    uint8_t x_bbfb = 0;
    uint8_t y_bbfb = 0;
    bool zero_bbfb = 0;
    bool negative_bbfb = 0;
    bool overflow_bbfb = 0;
    bool irq_disable_bbfb = 0;
    bool decimal_bbfb = 0;
    uint8_t a_bbfb2 = 0;
    uint8_t a_hi_bbfb2 = 0;
    uint16_t x_bbfb2 = 0;
    uint16_t y_bbfb2 = 0;
    bool zero_bbfb2 = 0;
    bool negative_bbfb2 = 0;
    bool overflow_bbfb2 = 0;
    bool irq_disable_bbfb2 = 0;
    bool decimal_bbfb2 = 0;
    uint8_t a_bb99 = 0;
    uint8_t a_hi_bb99 = 0;
    bool irq_disable_bb99 = 0;
    bool decimal_bb99 = 0;
    uint8_t a_bb992 = 0;
    uint8_t a_hi_bb992 = 0;
    bool irq_disable_bb992 = 0;
    bool decimal_bb992 = 0;
    uint8_t a_bb873 = 0;
    uint8_t a_hi_bb873 = 0;
    uint8_t x_bb873 = 0;
    uint8_t y_bb873 = 0;
    bool zero_bb873 = 0;
    bool negative_bb873 = 0;
    bool overflow_bb873 = 0;
    bool irq_disable_bb873 = 0;
    bool decimal_bb873 = 0;
    uint8_t a_bb874 = 0;
    uint8_t a_hi_bb874 = 0;
    uint16_t x_bb874 = 0;
    uint16_t y_bb874 = 0;
    bool zero_bb874 = 0;
    bool negative_bb874 = 0;
    bool overflow_bb874 = 0;
    bool irq_disable_bb874 = 0;
    bool decimal_bb874 = 0;
    uint8_t a_hi_bc08 = 0;
    uint8_t x_bc08 = 0;
    uint8_t y_bc08 = 0;
    bool overflow_bc08 = 0;
    uint16_t direct_page_bc08 = 0;
    uint8_t data_bank_bc08 = 0;
    bool irq_disable_bc08 = 0;
    bool decimal_bc08 = 0;
    uint8_t a_hi_bc082 = 0;
    uint16_t x_bc082 = 0;
    uint16_t y_bc082 = 0;
    bool overflow_bc082 = 0;
    uint16_t direct_page_bc082 = 0;
    uint8_t data_bank_bc082 = 0;
    bool irq_disable_bc082 = 0;
    bool decimal_bc082 = 0;
    uint8_t a_hi_bc083 = 0;
    uint8_t x_bc083 = 0;
    uint8_t y_bc083 = 0;
    bool overflow_bc083 = 0;
    uint16_t direct_page_bc083 = 0;
    uint8_t data_bank_bc083 = 0;
    bool irq_disable_bc083 = 0;
    bool decimal_bc083 = 0;
    uint8_t a_hi_bc084 = 0;
    uint16_t x_bc084 = 0;
    uint16_t y_bc084 = 0;
    bool overflow_bc084 = 0;
    uint16_t direct_page_bc084 = 0;
    uint8_t data_bank_bc084 = 0;
    bool irq_disable_bc084 = 0;
    bool decimal_bc084 = 0;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20 | 0x10) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
    uint8_t a3;
    uint8_t a_hi3;
    if ((uint8_t)(value + 4) >= 0x80) {
        uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
        uint8_t a1;
        uint8_t a_hi1;
        if (!((uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) & 0x8000)) {
            a1 = (uint8_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1);
            a_hi1 = (uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) >> 8;
        } else {
            uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp + 0xC2));
            a1 = (uint8_t)((uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) + value3);
            a_hi1 = (uint16_t)((uint16_t)(((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) ^ 0xFFFF) + value2 + 1) + value3) >> 8;
        }
        a3 = a1;
        a_hi3 = a_hi1;
    } else {
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 0xC2));
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) < value5) {
            a2 = (uint8_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4);
            a_hi2 = (uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) >> 8;
        } else {
            uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp + 0xC2));
            a2 = (uint8_t)((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) - value6 - ((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) >= value5 ^ 1));
            a_hi2 = (uint16_t)((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) - value6 - ((uint16_t)((((a_hi << 8) | (uint8_t)(value + 4)) & 0x7F) + value4) >= value5 ^ 1)) >> 8;
        }
        a3 = a2;
        a_hi3 = a_hi2;
    }
    BUS16_SET(c, (uint16_t)(dp + 4), (a_hi3 << 8) | a3);
    BUS16_SET(c, (uint16_t)(dp + 8), (((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1);
    uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
    uint8_t a4;
    if (!(value7 & 0x80)) {
        a4 = value7;
    } else {
        a4 = (uint8_t)((value7 ^ 0x7F) + 1);
    }
    BUS8_SET(c, dp, a4);
    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp + 0x1A));
    uint8_t value9 = BUS8_RDP(c, dp);
    uint8_t a7;
    uint8_t a_hi6;
    if (!((uint8_t)((value8 >> 1) + value9) & 0x80)) {
        uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp + 0x12));
        uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp + 0xC0));
        uint8_t a5;
        uint8_t a_hi4;
        if ((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10) < value11) {
            a5 = (uint8_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10);
            a_hi4 = (uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10) >> 8;
        } else {
            uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp + 0xC0));
            a5 = (uint8_t)((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10) - value12 - ((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10) >= value11 ^ 1));
            a_hi4 = (uint16_t)((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10) - value12 - ((uint16_t)(((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9)) & 0x7F) + value10) >= value11 ^ 1)) >> 8;
        }
        a7 = a5;
        a_hi6 = a_hi4;
    } else {
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp + 0x12));
        uint8_t a6;
        uint8_t a_hi5;
        if (!((uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9) | 0xFF00) + value13) & 0x8000)) {
            a6 = (uint8_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9) | 0xFF00) + value13);
            a_hi5 = (uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9) | 0xFF00) + value13) >> 8;
        } else {
            uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp + 0xC0));
            a6 = (uint8_t)((uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9) | 0xFF00) + value13) + value14);
            a_hi5 = (uint16_t)((uint16_t)((((((a_hi3 << 8) | a3) & 0x0FF0) << 1 << 1 << 1 >> 8 << 8) | (uint8_t)((value8 >> 1) + value9) | 0xFF00) + value13) + value14) >> 8;
        }
        a7 = a6;
        a_hi6 = a_hi5;
    }
    RAM8(0x0000 + sp0 - 1) = a_hi6;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)((a_hi6 << 8) | a7);
    uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 4));
    BUS16_SET(c, (uint16_t)(dp + 4), ((value15 << 8) | a7) & 0x0F0F);
    uint8_t value16 = RAM8(0x0000 + sp0 - 2);
    uint8_t value17 = RAM8(0x0000 + sp0 - 1);
    uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp + 8));
    BUS16_SET(c, (uint16_t)(dp + 8), ((((value17 << 8) | value16) >> 4) & 0x7F) | value18);
    uint16_t value19 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x0C)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x0A)) + (uint8_t)(((((value17 << 8) | value16) >> 4) & 0x7F) | value18), BUS8_RDP(c, (uint16_t)(dp + 0x0C)));
    uint8_t value20 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x0F)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x0D)) + (uint8_t)((value19 & 0xFF) << 1 << 1), BUS8_RDP(c, (uint16_t)(dp + 0x0F)));
    BUS8_SET(c, (uint16_t)(dp + 7), value20);
    uint8_t value21 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x0F)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x0D)) + (uint8_t)((uint8_t)((value19 & 0xFF) << 1 << 1) + 2), BUS8_RDP(c, (uint16_t)(dp + 0x0F)));
    BUS8_SET(c, (uint16_t)(dp + 6), value21);
    if ((value21 & 0xF0) != 0x10) {
        BUS8_SET(c, (uint16_t)(dp + 6), 0);
    }
    r->a = (value19 & 0xFF) << 1 << 1 >> 8 << 8 | (value21 & 0xF0);
    r->y = (uint8_t)((uint8_t)((value19 & 0xFF) << 1 << 1) + 2);
    r->c = (value21 & 0xF0) >= 0x10;
    r->z = (value21 & 0xF0) == 0x10;
    r->n = (uint8_t)((value21 & 0xF0) - 0x10) & 0x80;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBB7A, 0xC1BC37); GUARD_JSR(c, sp_call, 0xBB7A); } /* test_horizontal_terrain_shape_and_preceding_cells */
    r->sp += 1;
    uint16_t a_all = r->a;
    uint8_t y_ret = r->y;
    bool carry_ret = r->c;
    if (carry_ret) {
        uint8_t value22 = RAM8(0x0000 + sp0);
        if (value22 & 0x01) {
            if (value22 & 0x20) {
                if (value22 & 0x10) {
                    a_bb89 = (uint8_t)a_all;
                    a_hi_bb89 = a_all >> 8;
                    x_bb89 = x;
                    y_bb89 = y_ret;
                    zero_bb89 = value22 & 0x02;
                    negative_bb89 = value22 & 0x80;
                    overflow_bb89 = value22 & 0x40;
                    irq_disable_bb89 = value22 & 0x04;
                    decimal_bb89 = value22 & 0x08;
                    goto shared_BB89;
                } else {
                    a_bb892 = (uint8_t)a_all;
                    a_hi_bb892 = a_all >> 8;
                    x_bb892 = x;
                    y_bb892 = y_ret;
                    zero_bb892 = value22 & 0x02;
                    negative_bb892 = value22 & 0x80;
                    overflow_bb892 = value22 & 0x40;
                    irq_disable_bb892 = value22 & 0x04;
                    decimal_bb892 = value22 & 0x08;
                    goto shared_BB89_1;
                }
            } else {
                if (value22 & 0x10) {
                    a_bb893 = (uint8_t)a_all;
                    a_hi_bb893 = a_all >> 8;
                    x_bb893 = x;
                    y_bb893 = y_ret;
                    zero_bb893 = value22 & 0x02;
                    negative_bb893 = value22 & 0x80;
                    overflow_bb893 = value22 & 0x40;
                    irq_disable_bb893 = value22 & 0x04;
                    decimal_bb893 = value22 & 0x08;
                    goto shared_BB89_2;
                } else {
                    a_bb894 = (uint8_t)a_all;
                    a_hi_bb894 = a_all >> 8;
                    x_bb894 = x;
                    y_bb894 = y_ret;
                    zero_bb894 = value22 & 0x02;
                    negative_bb894 = value22 & 0x80;
                    overflow_bb894 = value22 & 0x40;
                    irq_disable_bb894 = value22 & 0x04;
                    decimal_bb894 = value22 & 0x08;
                    goto shared_BB89_3;
                }
            }
        }
        if (value22 & 0x20) {
            uint8_t value23 = BUS8_RDP(c, (uint16_t)(dp + 2));
            if (value23 != 0) {
                if (value23 < 8) {
                    uint8_t value24 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                    if (value24 & 0x80) {
                        if (value23 != 5) {
                            if (value23 != 6) {
                                if (value22 & 0x10) {
                                    a_bb87 = value23;
                                    a_hi_bb87 = a_all >> 8;
                                    x_bb87 = x;
                                    y_bb87 = y_ret;
                                    zero_bb87 = value23 == 6;
                                    negative_bb87 = (uint8_t)(value23 - 6) & 0x80;
                                    overflow_bb87 = value24 & 0x40;
                                    irq_disable_bb87 = value22 & 0x04;
                                    decimal_bb87 = value22 & 0x08;
                                    goto shared_BB87;
                                } else {
                                    a_bb872 = value23;
                                    a_hi_bb872 = a_all >> 8;
                                    x_bb872 = x;
                                    y_bb872 = y_ret;
                                    zero_bb872 = value23 == 6;
                                    negative_bb872 = (uint8_t)(value23 - 6) & 0x80;
                                    overflow_bb872 = value24 & 0x40;
                                    irq_disable_bb872 = value22 & 0x04;
                                    decimal_bb872 = value22 & 0x08;
                                    goto shared_BB87_1;
                                }
                            }
                            uint8_t value25 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                            BUS8_SET(c, (uint16_t)(dp + 0x1E), value25 ^ 0x80);
                            uint8_t value26 = BUS8_RDP(c, (uint16_t)(dp + 0x1C));
                            BUS8_SET(c, (uint16_t)(dp + 0x1C), (uint8_t)(value26 + 1));
                            if (value22 & 0x10) {
                                a_bbfb = value25 ^ 0x80;
                                a_hi_bbfb = a_all >> 8;
                                x_bbfb = x;
                                y_bbfb = y_ret;
                                zero_bbfb = (uint8_t)(value26 + 1) == 0;
                                negative_bbfb = (uint8_t)(value26 + 1) & 0x80;
                                overflow_bbfb = value24 & 0x40;
                                irq_disable_bbfb = value22 & 0x04;
                                decimal_bbfb = value22 & 0x08;
                                goto shared_BBFB;
                            } else {
                                a_bbfb2 = value25 ^ 0x80;
                                a_hi_bbfb2 = a_all >> 8;
                                x_bbfb2 = x;
                                y_bbfb2 = y_ret;
                                zero_bbfb2 = (uint8_t)(value26 + 1) == 0;
                                negative_bbfb2 = (uint8_t)(value26 + 1) & 0x80;
                                overflow_bbfb2 = value24 & 0x40;
                                irq_disable_bbfb2 = value22 & 0x04;
                                decimal_bbfb2 = value22 & 0x08;
                                goto shared_BBFB_1;
                            }
                        }
                        uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                        BUS8_SET(c, (uint16_t)(dp + 0x1E), value27);
                        uint8_t value28 = BUS8_RDP(c, (uint16_t)(dp + 0x1C));
                        BUS8_SET(c, (uint16_t)(dp + 0x1C), (uint8_t)(value28 + 1));
                        if (value22 & 0x10) {
                            a_bbfb = value27;
                            a_hi_bbfb = a_all >> 8;
                            x_bbfb = x;
                            y_bbfb = y_ret;
                            zero_bbfb = (uint8_t)(value28 + 1) == 0;
                            negative_bbfb = (uint8_t)(value28 + 1) & 0x80;
                            overflow_bbfb = value24 & 0x40;
                            irq_disable_bbfb = value22 & 0x04;
                            decimal_bbfb = value22 & 0x08;
                            goto shared_BBFB;
                        } else {
                            a_bbfb2 = value27;
                            a_hi_bbfb2 = a_all >> 8;
                            x_bbfb2 = x;
                            y_bbfb2 = y_ret;
                            zero_bbfb2 = (uint8_t)(value28 + 1) == 0;
                            negative_bbfb2 = (uint8_t)(value28 + 1) & 0x80;
                            overflow_bbfb2 = value24 & 0x40;
                            irq_disable_bbfb2 = value22 & 0x04;
                            decimal_bbfb2 = value22 & 0x08;
                            goto shared_BBFB_1;
                        }
                    }
                    if (value23 != 4) {
                        if (value23 != 7) {
                            if (value22 & 0x10) {
                                a_bb87 = value23;
                                a_hi_bb87 = a_all >> 8;
                                x_bb87 = x;
                                y_bb87 = y_ret;
                                zero_bb87 = value23 == 7;
                                negative_bb87 = (uint8_t)(value23 - 7) & 0x80;
                                overflow_bb87 = value24 & 0x40;
                                irq_disable_bb87 = value22 & 0x04;
                                decimal_bb87 = value22 & 0x08;
                                goto shared_BB87;
                            } else {
                                a_bb872 = value23;
                                a_hi_bb872 = a_all >> 8;
                                x_bb872 = x;
                                y_bb872 = y_ret;
                                zero_bb872 = value23 == 7;
                                negative_bb872 = (uint8_t)(value23 - 7) & 0x80;
                                overflow_bb872 = value24 & 0x40;
                                irq_disable_bb872 = value22 & 0x04;
                                decimal_bb872 = value22 & 0x08;
                                goto shared_BB87_1;
                            }
                        }
                        uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                        BUS8_SET(c, (uint16_t)(dp + 0x1E), value29 ^ 0x80);
                        uint8_t value30 = BUS8_RDP(c, (uint16_t)(dp + 0x1C));
                        BUS8_SET(c, (uint16_t)(dp + 0x1C), (uint8_t)(value30 + 1));
                        if (value22 & 0x10) {
                            a_bbfb = value29 ^ 0x80;
                            a_hi_bbfb = a_all >> 8;
                            x_bbfb = x;
                            y_bbfb = y_ret;
                            zero_bbfb = (uint8_t)(value30 + 1) == 0;
                            negative_bbfb = (uint8_t)(value30 + 1) & 0x80;
                            overflow_bbfb = value24 & 0x40;
                            irq_disable_bbfb = value22 & 0x04;
                            decimal_bbfb = value22 & 0x08;
                            goto shared_BBFB;
                        } else {
                            a_bbfb2 = value29 ^ 0x80;
                            a_hi_bbfb2 = a_all >> 8;
                            x_bbfb2 = x;
                            y_bbfb2 = y_ret;
                            zero_bbfb2 = (uint8_t)(value30 + 1) == 0;
                            negative_bbfb2 = (uint8_t)(value30 + 1) & 0x80;
                            overflow_bbfb2 = value24 & 0x40;
                            irq_disable_bbfb2 = value22 & 0x04;
                            decimal_bbfb2 = value22 & 0x08;
                            goto shared_BBFB_1;
                        }
                    }
                    uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                    BUS8_SET(c, (uint16_t)(dp + 0x1E), value31);
                    uint8_t value32 = BUS8_RDP(c, (uint16_t)(dp + 0x1C));
                    BUS8_SET(c, (uint16_t)(dp + 0x1C), (uint8_t)(value32 + 1));
                    if (value22 & 0x10) {
                        a_bbfb = value31;
                        a_hi_bbfb = a_all >> 8;
                        x_bbfb = x;
                        y_bbfb = y_ret;
                        zero_bbfb = (uint8_t)(value32 + 1) == 0;
                        negative_bbfb = (uint8_t)(value32 + 1) & 0x80;
                        overflow_bbfb = value24 & 0x40;
                        irq_disable_bbfb = value22 & 0x04;
                        decimal_bbfb = value22 & 0x08;
                        goto shared_BBFB;
                    } else {
                        a_bbfb2 = value31;
                        a_hi_bbfb2 = a_all >> 8;
                        x_bbfb2 = x;
                        y_bbfb2 = y_ret;
                        zero_bbfb2 = (uint8_t)(value32 + 1) == 0;
                        negative_bbfb2 = (uint8_t)(value32 + 1) & 0x80;
                        overflow_bbfb2 = value24 & 0x40;
                        irq_disable_bbfb2 = value22 & 0x04;
                        decimal_bbfb2 = value22 & 0x08;
                        goto shared_BBFB_1;
                    }
                }
                if (value23 == 8) {
                    uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                    if (value22 & 0x10) {
                        a_bb99 = value33;
                        a_hi_bb99 = a_all >> 8;
                        irq_disable_bb99 = value22 & 0x04;
                        decimal_bb99 = value22 & 0x08;
                        goto shared_BB99;
                    } else {
                        a_bb992 = value33;
                        a_hi_bb992 = a_all >> 8;
                        irq_disable_bb992 = value22 & 0x04;
                        decimal_bb992 = value22 & 0x08;
                        goto shared_BB99_1;
                    }
                }
                if (value23 != 9) {
                    if (value22 & 0x10) {
                        a_bb87 = value23;
                        a_hi_bb87 = a_all >> 8;
                        x_bb87 = x;
                        y_bb87 = y_ret;
                        zero_bb87 = value23 == 9;
                        negative_bb87 = (uint8_t)(value23 - 9) & 0x80;
                        overflow_bb87 = value22 & 0x40;
                        irq_disable_bb87 = value22 & 0x04;
                        decimal_bb87 = value22 & 0x08;
                        goto shared_BB87;
                    } else {
                        a_bb872 = value23;
                        a_hi_bb872 = a_all >> 8;
                        x_bb872 = x;
                        y_bb872 = y_ret;
                        zero_bb872 = value23 == 9;
                        negative_bb872 = (uint8_t)(value23 - 9) & 0x80;
                        overflow_bb872 = value22 & 0x40;
                        irq_disable_bb872 = value22 & 0x04;
                        decimal_bb872 = value22 & 0x08;
                        goto shared_BB87_1;
                    }
                }
                uint8_t value34 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                if (value22 & 0x10) {
                    a_bb99 = value34 ^ 0x80;
                    a_hi_bb99 = a_all >> 8;
                    irq_disable_bb99 = value22 & 0x04;
                    decimal_bb99 = value22 & 0x08;
                    goto shared_BB99;
                } else {
                    a_bb992 = value34 ^ 0x80;
                    a_hi_bb992 = a_all >> 8;
                    irq_disable_bb992 = value22 & 0x04;
                    decimal_bb992 = value22 & 0x08;
                    goto shared_BB99_1;
                }
            }
            if (value22 & 0x10) {
                a_bb87 = value23;
                a_hi_bb87 = a_all >> 8;
                x_bb87 = x;
                y_bb87 = y_ret;
                zero_bb87 = value23 == 0;
                negative_bb87 = value23 & 0x80;
                overflow_bb87 = value22 & 0x40;
                irq_disable_bb87 = value22 & 0x04;
                decimal_bb87 = value22 & 0x08;
                goto shared_BB87;
            } else {
                a_bb872 = value23;
                a_hi_bb872 = a_all >> 8;
                x_bb872 = x;
                y_bb872 = y_ret;
                zero_bb872 = value23 == 0;
                negative_bb872 = value23 & 0x80;
                overflow_bb872 = value22 & 0x40;
                irq_disable_bb872 = value22 & 0x04;
                decimal_bb872 = value22 & 0x08;
                goto shared_BB87_1;
            }
        } else {
            uint16_t value35 = BUS16_RDP(c, (uint16_t)(dp + 2));
            if (value35 != 0) {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
            if (value22 & 0x10) {
                a_bb873 = (uint8_t)value35;
                a_hi_bb873 = value35 >> 8;
                x_bb873 = x;
                y_bb873 = y_ret;
                zero_bb873 = value35 == 0;
                negative_bb873 = value35 & 0x8000;
                overflow_bb873 = value22 & 0x40;
                irq_disable_bb873 = value22 & 0x04;
                decimal_bb873 = value22 & 0x08;
                goto shared_BB87_2;
            } else {
                a_bb874 = (uint8_t)value35;
                a_hi_bb874 = value35 >> 8;
                x_bb874 = x;
                y_bb874 = y_ret;
                zero_bb874 = value35 == 0;
                negative_bb874 = value35 & 0x8000;
                overflow_bb874 = value22 & 0x40;
                irq_disable_bb874 = value22 & 0x04;
                decimal_bb874 = value22 & 0x08;
                goto shared_BB87_3;
            }
        }
    }
    uint8_t value36 = RAM8(0x0000 + sp0);
    r->c = 0;
    r->z = value36 & 0x02;
    r->n = value36 & 0x80;
    r->v = value36 & 0x40;
    r->mf = value36 & 0x20;
    r->xf = value36 & 0x10;
    r->i = value36 & 0x04;
    r->d = value36 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BB89:;
    r->a = (a_hi_bb89 << 8) | a_bb89;
    r->x = x_bb89;
    r->y = y_bb89;
    r->c = 1;
    r->z = zero_bb89;
    r->n = negative_bb89;
    r->v = overflow_bb89;
    r->mf = 1;
    r->xf = 1;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bb89;
    r->d = decimal_bb89;
    RETURN_RTS(c);
    shared_BB89_1:;
    r->a = (a_hi_bb892 << 8) | a_bb892;
    r->x = x_bb892;
    r->y = y_bb892;
    r->c = 1;
    r->z = zero_bb892;
    r->n = negative_bb892;
    r->v = overflow_bb892;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bb892;
    r->d = decimal_bb892;
    RETURN_RTS(c);
    shared_BB89_2:;
    r->a = (a_hi_bb893 << 8) | a_bb893;
    r->x = x_bb893;
    r->y = y_bb893;
    r->c = 1;
    r->z = zero_bb893;
    r->n = negative_bb893;
    r->v = overflow_bb893;
    r->mf = 0;
    r->xf = 1;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bb893;
    r->d = decimal_bb893;
    RETURN_RTS(c);
    shared_BB89_3:;
    r->a = (a_hi_bb894 << 8) | a_bb894;
    r->x = x_bb894;
    r->y = y_bb894;
    r->c = 1;
    r->z = zero_bb894;
    r->n = negative_bb894;
    r->v = overflow_bb894;
    r->mf = 0;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bb894;
    r->d = decimal_bb894;
    RETURN_RTS(c);
    shared_BB87:;
    BUS8_SET(c, (uint16_t)(dp + 0x1F), 0);
    a_bb89 = a_bb87;
    a_hi_bb89 = a_hi_bb87;
    x_bb89 = x_bb87;
    y_bb89 = y_bb87;
    zero_bb89 = zero_bb87;
    negative_bb89 = negative_bb87;
    overflow_bb89 = overflow_bb87;
    irq_disable_bb89 = irq_disable_bb87;
    decimal_bb89 = decimal_bb87;
    goto shared_BB89;
    shared_BB87_1:;
    BUS8_SET(c, (uint16_t)(dp + 0x1F), 0);
    a_bb892 = a_bb872;
    a_hi_bb892 = a_hi_bb872;
    x_bb892 = x_bb872;
    y_bb892 = y_bb872;
    zero_bb892 = zero_bb872;
    negative_bb892 = negative_bb872;
    overflow_bb892 = overflow_bb872;
    irq_disable_bb892 = irq_disable_bb872;
    decimal_bb892 = decimal_bb872;
    goto shared_BB89_1;
    shared_BBFB:;
    r->a = (a_hi_bbfb << 8) | a_bbfb;
    r->x = x_bbfb;
    r->y = y_bbfb;
    r->c = 1;
    r->z = zero_bbfb;
    r->n = negative_bbfb;
    r->v = overflow_bbfb;
    r->mf = 1;
    r->xf = 1;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bbfb;
    r->d = decimal_bbfb;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBBFE, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBBFE); } /* test_actor_horizontal_footprint_and_redirect_step */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    if (carry_ret2) {
        if (m_ret) {
            if (x_ret) {
                a_hi_bc08 = a_all2 >> 8;
                x_bc08 = x_bbfb;
                y_bc08 = (uint8_t)y_ret2;
                overflow_bc08 = overflow_ret2;
                direct_page_bc08 = dp;
                data_bank_bc08 = db;
                irq_disable_bc08 = irq_disable_bbfb;
                decimal_bc08 = decimal_bbfb;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all2 >> 8;
                x_bc082 = x_bbfb;
                y_bc082 = y_ret2;
                overflow_bc082 = overflow_ret2;
                direct_page_bc082 = dp;
                data_bank_bc082 = db;
                irq_disable_bc082 = irq_disable_bbfb;
                decimal_bc082 = decimal_bbfb;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret) {
                a_hi_bc083 = a_all2 >> 8;
                x_bc083 = x_bbfb;
                y_bc083 = (uint8_t)y_ret2;
                overflow_bc083 = overflow_ret2;
                direct_page_bc083 = dp;
                data_bank_bc083 = db;
                irq_disable_bc083 = irq_disable_bbfb;
                decimal_bc083 = decimal_bbfb;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all2 >> 8;
                x_bc084 = x_bbfb;
                y_bc084 = y_ret2;
                overflow_bc084 = overflow_ret2;
                direct_page_bc084 = dp;
                data_bank_bc084 = db;
                irq_disable_bc084 = irq_disable_bbfb;
                decimal_bc084 = decimal_bbfb;
                goto shared_BC08_3;
            }
        }
    }
    r->c = 1;
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); }
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret2 = r->mf;
    bool x_ret2 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    if (carry_ret3) {
        if (m_ret2) {
            if (x_ret2) {
                a_hi_bc08 = a_all3 >> 8;
                x_bc08 = x_bbfb;
                y_bc08 = (uint8_t)y_ret3;
                overflow_bc08 = overflow_ret3;
                direct_page_bc08 = dp_ret;
                data_bank_bc08 = db_ret;
                irq_disable_bc08 = irq_disable_bbfb;
                decimal_bc08 = decimal_bbfb;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all3 >> 8;
                x_bc082 = x_bbfb;
                y_bc082 = y_ret3;
                overflow_bc082 = overflow_ret3;
                direct_page_bc082 = dp_ret;
                data_bank_bc082 = db_ret;
                irq_disable_bc082 = irq_disable_bbfb;
                decimal_bc082 = decimal_bbfb;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret2) {
                a_hi_bc083 = a_all3 >> 8;
                x_bc083 = x_bbfb;
                y_bc083 = (uint8_t)y_ret3;
                overflow_bc083 = overflow_ret3;
                direct_page_bc083 = dp_ret;
                data_bank_bc083 = db_ret;
                irq_disable_bc083 = irq_disable_bbfb;
                decimal_bc083 = decimal_bbfb;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all3 >> 8;
                x_bc084 = x_bbfb;
                y_bc084 = y_ret3;
                overflow_bc084 = overflow_ret3;
                direct_page_bc084 = dp_ret;
                data_bank_bc084 = db_ret;
                irq_disable_bc084 = irq_disable_bbfb;
                decimal_bc084 = decimal_bbfb;
                goto shared_BC08_3;
            }
        }
    }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BBFB_1:;
    r->a = (a_hi_bbfb2 << 8) | a_bbfb2;
    r->x = x_bbfb2;
    r->y = y_bbfb2;
    r->c = 1;
    r->z = zero_bbfb2;
    r->n = negative_bbfb2;
    r->v = overflow_bbfb2;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bbfb2;
    r->d = decimal_bbfb2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBBFE, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBBFE); } /* test_actor_horizontal_footprint_and_redirect_step */
    bool m_ret3 = r->mf;
    bool x_ret3 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t y_ret4 = r->y;
    bool carry_ret4 = r->c;
    bool overflow_ret4 = r->v;
    if (carry_ret4) {
        if (m_ret3) {
            if (x_ret3) {
                a_hi_bc08 = a_all4 >> 8;
                x_bc08 = (uint8_t)x_bbfb2;
                y_bc08 = (uint8_t)y_ret4;
                overflow_bc08 = overflow_ret4;
                direct_page_bc08 = dp;
                data_bank_bc08 = db;
                irq_disable_bc08 = irq_disable_bbfb2;
                decimal_bc08 = decimal_bbfb2;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all4 >> 8;
                x_bc082 = x_bbfb2;
                y_bc082 = y_ret4;
                overflow_bc082 = overflow_ret4;
                direct_page_bc082 = dp;
                data_bank_bc082 = db;
                irq_disable_bc082 = irq_disable_bbfb2;
                decimal_bc082 = decimal_bbfb2;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret3) {
                a_hi_bc083 = a_all4 >> 8;
                x_bc083 = (uint8_t)x_bbfb2;
                y_bc083 = (uint8_t)y_ret4;
                overflow_bc083 = overflow_ret4;
                direct_page_bc083 = dp;
                data_bank_bc083 = db;
                irq_disable_bc083 = irq_disable_bbfb2;
                decimal_bc083 = decimal_bbfb2;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all4 >> 8;
                x_bc084 = x_bbfb2;
                y_bc084 = y_ret4;
                overflow_bc084 = overflow_ret4;
                direct_page_bc084 = dp;
                data_bank_bc084 = db;
                irq_disable_bc084 = irq_disable_bbfb2;
                decimal_bc084 = decimal_bbfb2;
                goto shared_BC08_3;
            }
        }
    }
    r->c = 1;
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC04, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC04); }
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret4 = r->mf;
    bool x_ret4 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t y_ret5 = r->y;
    bool carry_ret5 = r->c;
    bool overflow_ret5 = r->v;
    if (carry_ret5) {
        if (m_ret4) {
            if (x_ret4) {
                a_hi_bc08 = a_all5 >> 8;
                x_bc08 = (uint8_t)x_bbfb2;
                y_bc08 = (uint8_t)y_ret5;
                overflow_bc08 = overflow_ret5;
                direct_page_bc08 = dp_ret2;
                data_bank_bc08 = db_ret2;
                irq_disable_bc08 = irq_disable_bbfb2;
                decimal_bc08 = decimal_bbfb2;
                goto shared_BC08;
            } else {
                a_hi_bc082 = a_all5 >> 8;
                x_bc082 = x_bbfb2;
                y_bc082 = y_ret5;
                overflow_bc082 = overflow_ret5;
                direct_page_bc082 = dp_ret2;
                data_bank_bc082 = db_ret2;
                irq_disable_bc082 = irq_disable_bbfb2;
                decimal_bc082 = decimal_bbfb2;
                goto shared_BC08_1;
            }
        } else {
            if (x_ret4) {
                a_hi_bc083 = a_all5 >> 8;
                x_bc083 = (uint8_t)x_bbfb2;
                y_bc083 = (uint8_t)y_ret5;
                overflow_bc083 = overflow_ret5;
                direct_page_bc083 = dp_ret2;
                data_bank_bc083 = db_ret2;
                irq_disable_bc083 = irq_disable_bbfb2;
                decimal_bc083 = decimal_bbfb2;
                goto shared_BC08_2;
            } else {
                a_hi_bc084 = a_all5 >> 8;
                x_bc084 = x_bbfb2;
                y_bc084 = y_ret5;
                overflow_bc084 = overflow_ret5;
                direct_page_bc084 = dp_ret2;
                data_bank_bc084 = db_ret2;
                irq_disable_bc084 = irq_disable_bbfb2;
                decimal_bc084 = decimal_bbfb2;
                goto shared_BC08_3;
            }
        }
    }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_BB99:;
    BUS8_SET(c, (uint16_t)(dp + 0x1E), a_bb99);
    BUS8_SET(c, (uint16_t)(dp + 0x1F), 0);
    uint8_t value37 = BUS8_RDP(c, (uint16_t)(dp + 0x1C));
    BUS8_SET(c, (uint16_t)(dp + 0x1C), (uint8_t)(value37 + 1));
    r->a = (a_hi_bb99 << 8) | a_bb99;
    r->c = 1;
    r->z = (uint8_t)(value37 + 1) == 0;
    r->n = (uint8_t)(value37 + 1) & 0x80;
    r->mf = 1;
    r->xf = 1;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bb99;
    r->d = decimal_bb99;
    TAIL_CALL(c, 0xC1B9EA, SOM_RTS); /* test_actor_horizontal_footprint_and_redirect_step */
    shared_BB99_1:;
    BUS8_SET(c, (uint16_t)(dp + 0x1E), a_bb992);
    BUS8_SET(c, (uint16_t)(dp + 0x1F), 0);
    uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp + 0x1C));
    BUS8_SET(c, (uint16_t)(dp + 0x1C), (uint8_t)(value38 + 1));
    r->a = (a_hi_bb992 << 8) | a_bb992;
    r->c = 1;
    r->z = (uint8_t)(value38 + 1) == 0;
    r->n = (uint8_t)(value38 + 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    r->i = irq_disable_bb992;
    r->d = decimal_bb992;
    TAIL_CALL(c, 0xC1B9EA, SOM_RTS); /* test_actor_horizontal_footprint_and_redirect_step */
    shared_BB87_2:;
    BUS16_SET(c, (uint16_t)(dp + 0x1F), 0);
    a_bb893 = a_bb873;
    a_hi_bb893 = a_hi_bb873;
    x_bb893 = x_bb873;
    y_bb893 = y_bb873;
    zero_bb893 = zero_bb873;
    negative_bb893 = negative_bb873;
    overflow_bb893 = overflow_bb873;
    irq_disable_bb893 = irq_disable_bb873;
    decimal_bb893 = decimal_bb873;
    goto shared_BB89_2;
    shared_BB87_3:;
    BUS16_SET(c, (uint16_t)(dp + 0x1F), 0);
    a_bb894 = a_bb874;
    a_hi_bb894 = a_hi_bb874;
    x_bb894 = x_bb874;
    y_bb894 = y_bb874;
    zero_bb894 = zero_bb874;
    negative_bb894 = negative_bb874;
    overflow_bb894 = overflow_bb874;
    irq_disable_bb894 = irq_disable_bb874;
    decimal_bb894 = decimal_bb874;
    goto shared_BB89_3;
    shared_BC08:;
    uint8_t value39 = BUS8_RDP(c, (uint16_t)(direct_page_bc08 + 0x1F));
    RAM8(0x0000 + sp0) = value39;
    BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1F), 0);
    r->a = (a_hi_bc08 << 8) | value39;
    r->x = x_bc08;
    r->y = y_bc08;
    r->c = 1;
    r->z = value39 == 0;
    r->n = value39 & 0x80;
    r->v = overflow_bc08;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_bc08;
    r->dp = direct_page_bc08;
    r->i = irq_disable_bc08;
    r->d = decimal_bc08;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 1;
    bool m_ret5 = r->mf;
    uint16_t a_all6 = r->a;
    bool carry_ret6 = r->c;
    if (carry_ret6) {
        if (m_ret5) {
            BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1F), RAM8(0x0000 + sp0));
            uint8_t value41 = BUS8_RDP(c, (uint16_t)(direct_page_bc08 + 0x1E));
            RAM8(0x0000 + sp0) = value41;
            BUS8_SET(c, (uint16_t)(direct_page_bc08 + 0x1E), 0);
            r->a = (a_all6 >> 8 << 8) | value41;
            r->c = 1;
            r->z = value41 == 0;
            r->n = value41 & 0x80;
            r->mf = 1;
            r->sp -= 1;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 1;
            uint16_t dp_ret3 = r->dp;
            bool m_ret6 = r->mf;
            bool carry_ret7 = r->c;
            if (carry_ret7) {
                if (m_ret6) {
                    uint8_t value42 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1E), 0);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1F), 0);
                    SET_A8(r, value42);
                    r->c = 1;
                    r->z = value42 == 0;
                    r->n = value42 & 0x80;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
            if (m_ret6) {
                uint8_t value43 = RAM8(0x0000 + sp0);
                SET_A8(r, value43);
                r->z = value43 == 0;
                r->n = value43 & 0x80;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            c->fail = 3;
            return;
        }
    }
    if (m_ret5) {
        uint8_t value44 = RAM8(0x0000 + sp0);
        SET_A8(r, value44);
        r->z = value44 == 0;
        r->n = value44 & 0x80;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
    shared_BC08_1:;
    uint8_t value45 = BUS8_RDP(c, (uint16_t)(direct_page_bc082 + 0x1F));
    RAM8(0x0000 + sp0) = value45;
    BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1F), 0);
    r->a = (a_hi_bc082 << 8) | value45;
    r->x = x_bc082;
    r->y = y_bc082;
    r->c = 1;
    r->z = value45 == 0;
    r->n = value45 & 0x80;
    r->v = overflow_bc082;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_bc082;
    r->dp = direct_page_bc082;
    r->i = irq_disable_bc082;
    r->d = decimal_bc082;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 1;
    bool m_ret7 = r->mf;
    uint16_t a_all8 = r->a;
    bool carry_ret8 = r->c;
    if (carry_ret8) {
        if (m_ret7) {
            BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1F), RAM8(0x0000 + sp0));
            uint8_t value47 = BUS8_RDP(c, (uint16_t)(direct_page_bc082 + 0x1E));
            RAM8(0x0000 + sp0) = value47;
            BUS8_SET(c, (uint16_t)(direct_page_bc082 + 0x1E), 0);
            r->a = (a_all8 >> 8 << 8) | value47;
            r->c = 1;
            r->z = value47 == 0;
            r->n = value47 & 0x80;
            r->mf = 1;
            r->sp -= 1;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 1;
            uint16_t dp_ret4 = r->dp;
            bool m_ret8 = r->mf;
            bool carry_ret9 = r->c;
            if (carry_ret9) {
                if (m_ret8) {
                    uint8_t value48 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 0x1E), 0);
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 0x1F), 0);
                    SET_A8(r, value48);
                    r->c = 1;
                    r->z = value48 == 0;
                    r->n = value48 & 0x80;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
            if (m_ret8) {
                uint8_t value49 = RAM8(0x0000 + sp0);
                SET_A8(r, value49);
                r->z = value49 == 0;
                r->n = value49 & 0x80;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            c->fail = 3;
            return;
        }
    }
    if (m_ret7) {
        uint8_t value50 = RAM8(0x0000 + sp0);
        SET_A8(r, value50);
        r->z = value50 == 0;
        r->n = value50 & 0x80;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
    shared_BC08_2:;
    uint16_t value51 = BUS16_RDP(c, (uint16_t)(direct_page_bc083 + 0x1F));
    RAM8(0x0000 + sp0) = value51 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value51;
    BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), 0);
    r->a = value51;
    r->x = x_bc083;
    r->y = y_bc083;
    r->c = 1;
    r->z = value51 == 0;
    r->n = value51 & 0x8000;
    r->v = overflow_bc083;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_bc083;
    r->dp = direct_page_bc083;
    r->i = irq_disable_bc083;
    r->d = decimal_bc083;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 2;
    bool m_ret9 = r->mf;
    uint16_t a_all10 = r->a;
    bool carry_ret10 = r->c;
    if (carry_ret10) {
        if (m_ret9) {
            BUS8_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), RAM8(0x0000 + sp0 - 1));
            uint8_t value53 = BUS8_RDP(c, (uint16_t)(direct_page_bc083 + 0x1E));
            RAM8(0x0000 + sp0 - 1) = value53;
            BUS8_SET(c, (uint16_t)(direct_page_bc083 + 0x1E), 0);
            r->a = (a_all10 >> 8 << 8) | value53;
            r->c = 1;
            r->z = value53 == 0;
            r->n = value53 & 0x80;
            r->mf = 1;
            r->sp -= 2;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret5 = r->dp;
            bool m_ret10 = r->mf;
            bool carry_ret11 = r->c;
            if (carry_ret11) {
                if (m_ret10) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value55 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value56 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret5 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret5 + 0x1F), 0);
                    r->a = (value56 << 8) | value55;
                    r->c = 1;
                    r->z = ((value56 << 8) | value55) == 0;
                    r->n = ((value56 << 8) | value55) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret10) {
                c->fail = 3;
                return;
            } else {
                uint8_t value58 = RAM8(0x0000 + sp0 - 1);
                uint8_t value59 = RAM8(0x0000 + sp0);
                r->a = (value59 << 8) | value58;
                r->z = ((value59 << 8) | value58) == 0;
                r->n = ((value59 << 8) | value58) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1F), (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1));
            uint16_t value62 = BUS16_RDP(c, (uint16_t)(direct_page_bc083 + 0x1E));
            RAM8(0x0000 + sp0) = value62 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)value62;
            BUS16_SET(c, (uint16_t)(direct_page_bc083 + 0x1E), 0);
            r->a = value62;
            r->c = 1;
            r->z = value62 == 0;
            r->n = value62 & 0x8000;
            r->mf = 0;
            r->sp -= 2;
            if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret6 = r->dp;
            bool m_ret11 = r->mf;
            bool carry_ret12 = r->c;
            if (carry_ret12) {
                if (m_ret11) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value64 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value65 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret6 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret6 + 0x1F), 0);
                    r->a = (value65 << 8) | value64;
                    r->c = 1;
                    r->z = ((value65 << 8) | value64) == 0;
                    r->n = ((value65 << 8) | value64) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret11) {
                c->fail = 3;
                return;
            } else {
                uint8_t value67 = RAM8(0x0000 + sp0 - 1);
                uint8_t value68 = RAM8(0x0000 + sp0);
                r->a = (value68 << 8) | value67;
                r->z = ((value68 << 8) | value67) == 0;
                r->n = ((value68 << 8) | value67) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
    if (m_ret9) {
        c->fail = 3;
        return;
    } else {
        uint8_t value70 = RAM8(0x0000 + sp0 - 1);
        uint8_t value71 = RAM8(0x0000 + sp0);
        r->a = (value71 << 8) | value70;
        r->z = ((value71 << 8) | value70) == 0;
        r->n = ((value71 << 8) | value70) & 0x8000;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    shared_BC08_3:;
    uint16_t value72 = BUS16_RDP(c, (uint16_t)(direct_page_bc084 + 0x1F));
    RAM8(0x0000 + sp0) = value72 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value72;
    BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), 0);
    r->a = value72;
    r->x = x_bc084;
    r->y = y_bc084;
    r->c = 1;
    r->z = value72 == 0;
    r->n = value72 & 0x8000;
    r->v = overflow_bc084;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_bc084;
    r->dp = direct_page_bc084;
    r->i = irq_disable_bc084;
    r->d = decimal_bc084;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC10); } /* test_actor_horizontal_footprint_and_redirect_step */
    r->sp += 2;
    bool m_ret12 = r->mf;
    uint16_t a_all13 = r->a;
    bool carry_ret13 = r->c;
    if (carry_ret13) {
        if (m_ret12) {
            BUS8_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), RAM8(0x0000 + sp0 - 1));
            uint8_t value74 = BUS8_RDP(c, (uint16_t)(direct_page_bc084 + 0x1E));
            RAM8(0x0000 + sp0 - 1) = value74;
            BUS8_SET(c, (uint16_t)(direct_page_bc084 + 0x1E), 0);
            r->a = (a_all13 >> 8 << 8) | value74;
            r->c = 1;
            r->z = value74 == 0;
            r->n = value74 & 0x80;
            r->mf = 1;
            r->sp -= 2;
            if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v5, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v6, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret7 = r->dp;
            bool m_ret13 = r->mf;
            bool carry_ret14 = r->c;
            if (carry_ret14) {
                if (m_ret13) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value76 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value77 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret7 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret7 + 0x1F), 0);
                    r->a = (value77 << 8) | value76;
                    r->c = 1;
                    r->z = ((value77 << 8) | value76) == 0;
                    r->n = ((value77 << 8) | value76) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret13) {
                c->fail = 3;
                return;
            } else {
                uint8_t value79 = RAM8(0x0000 + sp0 - 1);
                uint8_t value80 = RAM8(0x0000 + sp0);
                r->a = (value80 << 8) | value79;
                r->z = ((value80 << 8) | value79) == 0;
                r->n = ((value80 << 8) | value79) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1F), (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1));
            uint16_t value83 = BUS16_RDP(c, (uint16_t)(direct_page_bc084 + 0x1E));
            RAM8(0x0000 + sp0) = value83 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)value83;
            BUS16_SET(c, (uint16_t)(direct_page_bc084 + 0x1E), 0);
            r->a = value83;
            r->c = 1;
            r->z = value83 == 0;
            r->n = value83 & 0x8000;
            r->mf = 0;
            r->sp -= 2;
            if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v7, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xBC20, test_actor_vertical_footprint_and_redirect_step_v8, sp_in, 2); GUARD_JSR(c, sp_call, 0xBC20); }
            r->sp += 2;
            uint16_t dp_ret8 = r->dp;
            bool m_ret14 = r->mf;
            bool carry_ret15 = r->c;
            if (carry_ret15) {
                if (m_ret14) {
                    c->fail = 3;
                    return;
                } else {
                    uint8_t value85 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value86 = RAM8(0x0000 + sp0);
                    BUS16_SET(c, (uint16_t)(dp_ret8 + 0x1E), 0);
                    BUS16_SET(c, (uint16_t)(dp_ret8 + 0x1F), 0);
                    r->a = (value86 << 8) | value85;
                    r->c = 1;
                    r->z = ((value86 << 8) | value85) == 0;
                    r->n = ((value86 << 8) | value85) & 0x8000;
                    r->mf = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            if (m_ret14) {
                c->fail = 3;
                return;
            } else {
                uint8_t value88 = RAM8(0x0000 + sp0 - 1);
                uint8_t value89 = RAM8(0x0000 + sp0);
                r->a = (value89 << 8) | value88;
                r->z = ((value89 << 8) | value88) == 0;
                r->n = ((value89 << 8) | value88) & 0x8000;
                r->mf = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
    if (m_ret12) {
        c->fail = 3;
        return;
    } else {
        uint8_t value91 = RAM8(0x0000 + sp0 - 1);
        uint8_t value92 = RAM8(0x0000 + sp0);
        r->a = (value92 << 8) | value91;
        r->z = ((value92 << 8) | value91) == 0;
        r->n = ((value92 << 8) | value91) & 0x8000;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}

/* C1BAE2 test_actor_vertical_footprint_and_redirect_step_v7   [class A, 306 bytes, 169 instructions]
 * Source: src/rom/test_actor_horizontal_footprint_and_redirect_step.s
 * Subroutine of test_actor_horizontal_footprint_and_redirect_step, translated in place.
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void test_actor_vertical_footprint_and_redirect_step_v7(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x1F));
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}

/* C1BAE2 test_actor_vertical_footprint_and_redirect_step_v8   [class A, 306 bytes, 169 instructions]
 * Source: src/rom/test_actor_horizontal_footprint_and_redirect_step.s
 * Subroutine of test_actor_horizontal_footprint_and_redirect_step, translated in place.
 * Entry: M=16 bit X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void test_actor_vertical_footprint_and_redirect_step_v8(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 1)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x10) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x1F));
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}
