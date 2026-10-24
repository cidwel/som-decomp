#include "som_c.h"

/* C0F1CF publish_actor_frame_tiles_points_and_collision_rectangle   [class C, 1146 bytes, 599 instructions]
 * Source: src/rom/publish_actor_frame_tiles_points_and_collision_rectangle.s
 * Documented in docs/actor-visual-frame-geometry.md
 * Entry: M=any X=16 bit DB=any D=$0000.  Callers read: BXYCV.
 */
static void publish_actor_frame_tiles_points_and_collision_rectangle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a_hi_f21b = 0;
    uint16_t x_f21b = 0;
    uint16_t y_f21b = 0;
    bool carry_f21b = 0;
    bool overflow_f21b = 0;
    uint8_t a_hi_f20c = 0;
    uint16_t x_f20c = 0;
    uint16_t y_f20c = 0;
    bool carry_f20c = 0;
    bool overflow_f20c = 0;
    uint16_t direct_page_f20c = 0;
    uint8_t data_bank_f20c = 0;
    uint8_t a_f1e8 = 0;
    uint8_t a_hi_f1e8 = 0;
    uint16_t x_f1e8 = 0;
    uint16_t y_f1e8 = 0;
    bool overflow_f1e8 = 0;
    uint8_t a_hi_f224 = 0;
    uint16_t x_f224 = 0;
    uint16_t direct_page_f224 = 0;
    uint8_t data_bank_f224 = 0;
    uint8_t a_hi_f2242 = 0;
    uint8_t x_f2242 = 0;
    uint16_t direct_page_f2242 = 0;
    uint8_t data_bank_f2242 = 0;
    uint8_t a_hi_f20c2 = 0;
    uint8_t x_f20c2 = 0;
    uint8_t y_f20c2 = 0;
    bool carry_f20c2 = 0;
    bool overflow_f20c2 = 0;
    uint16_t direct_page_f20c2 = 0;
    uint8_t data_bank_f20c2 = 0;
    uint8_t a_f24f = 0;
    uint8_t a_hi_f24f = 0;
    uint16_t x_f24f = 0;
    uint16_t y_f24f = 0;
    bool overflow_f24f = 0;
    uint16_t direct_page_f24f = 0;
    uint8_t data_bank_f24f = 0;
    uint8_t a_f24f2 = 0;
    uint8_t a_hi_f24f2 = 0;
    uint8_t x_f24f2 = 0;
    uint8_t y_f24f2 = 0;
    bool overflow_f24f2 = 0;
    uint16_t direct_page_f24f2 = 0;
    uint8_t data_bank_f24f2 = 0;
    uint8_t a_hi_f2f9 = 0;
    uint16_t direct_page_f2f9 = 0;
    uint8_t data_bank_f2f9 = 0;
    uint8_t a_hi_f409 = 0;
    uint16_t y_f409 = 0;
    bool carry_f409 = 0;
    bool overflow_f409 = 0;
    uint16_t direct_page_f409 = 0;
    uint8_t data_bank_f409 = 0;
    uint8_t a_hi_f2f92 = 0;
    uint16_t direct_page_f2f92 = 0;
    uint8_t data_bank_f2f92 = 0;
    uint8_t a_hi_f4092 = 0;
    uint8_t y_f4092 = 0;
    bool carry_f4092 = 0;
    bool overflow_f4092 = 0;
    uint16_t direct_page_f4092 = 0;
    uint8_t data_bank_f4092 = 0;
    uint8_t a_f344 = 0;
    uint8_t a_hi_f344 = 0;
    uint16_t x_f344 = 0;
    uint16_t y_f344 = 0;
    uint16_t direct_page_f344 = 0;
    uint8_t data_bank_f344 = 0;
    RAM16_SET(0x0014, x);
    uint8_t value = BUS8(c, (db << 0x10) + 0xE02F + x);
    if (value != 0) {
        a_hi_f21b = a >> 8;
        x_f21b = x;
        y_f21b = y;
        carry_f21b = carry;
        overflow_f21b = overflow;
        goto shared_F21B;
    }
    uint8_t value2 = BUS8(c, (db << 0x10) + 0xE060 + x);
    if (value2 == 0) {
        uint8_t value3 = BUS8(c, (db << 0x10) + 0xE191 + x);
        if ((value3 & 0xC5) != 0) {
            a_hi_f21b = a >> 8;
            x_f21b = x;
            y_f21b = y;
            carry_f21b = carry;
            overflow_f21b = overflow;
            goto shared_F21B;
        }
        uint8_t value4 = RAM8(0x00ED);
        if (!(value4 & 0x80)) {
            a_hi_f20c = a >> 8;
            x_f20c = x;
            y_f20c = y;
            carry_f20c = carry;
            overflow_f20c = value4 & 0x40;
            direct_page_f20c = 0;
            data_bank_f20c = db;
            goto shared_F20C;
        }
        a_hi_f21b = a >> 8;
        x_f21b = x;
        y_f21b = y;
        carry_f21b = carry;
        overflow_f21b = value4 & 0x40;
        goto shared_F21B;
    }
    uint8_t value5 = RAM8(0x00ED);
    if (value5 & 0x80) {
        a_f1e8 = value2;
        a_hi_f1e8 = a >> 8;
        x_f1e8 = x;
        y_f1e8 = y;
        overflow_f1e8 = value5 & 0x40;
        goto shared_F1E8;
    }
    if (x >= 0x0600) {
        a_hi_f20c = a >> 8;
        x_f20c = x;
        y_f20c = y;
        carry_f20c = x >= 0x0600;
        overflow_f20c = value5 & 0x40;
        direct_page_f20c = 0;
        data_bank_f20c = db;
        goto shared_F20C;
    }
    a_f1e8 = value2;
    a_hi_f1e8 = a >> 8;
    x_f1e8 = x;
    y_f1e8 = y;
    overflow_f1e8 = value5 & 0x40;
    shared_F1E8:;
    if (a_f1e8 == 0x20) {
        a_hi_f21b = a_hi_f1e8;
        x_f21b = x_f1e8;
        y_f21b = y_f1e8;
        carry_f21b = a_f1e8 >= 0x20;
        overflow_f21b = overflow_f1e8;
        goto shared_F21B;
    }
    r->a = (a_hi_f1e8 << 8) | a_f1e8;
    r->x = x_f1e8;
    r->y = y_f1e8;
    r->v = overflow_f1e8;
    r->mf = true;
    r->xf = false;
    r->db = db;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF1EF, 0xC1818F); GUARD_JSL(c, sp_call, 0xF1EF); } /* dispatch_actor_visual_frame_script_by_effect_family */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    RAM8(0x0012 + dp_ret) = 0xD4;
    uint8_t value7 = BUS8(c, (db_ret << 0x10) + 0xE060 + x_ret2);
    bool carry1;
    if (!(value7 & 0xE0 & 0x80)) {
        carry1 = carry_ret;
    } else {
        RAM8(0x0012 + dp_ret)--;
        if ((value7 & 0xE0) < 0xC0) {
            RAM8(0x0012 + dp_ret) = 0xD0;
        }
        carry1 = (value7 & 0xE0) >= 0xC0;
    }
    uint8_t value8 = BUS8(c, (db_ret << 0x10) + 0xE00C + x_ret2);
    if (value8 != 0) {
        if (x_ret) {
            a_hi_f2242 = a_all >> 8;
            x_f2242 = (uint8_t)x_ret2;
            direct_page_f2242 = dp_ret;
            data_bank_f2242 = db_ret;
            goto shared_F224_1;
        } else {
            a_hi_f224 = a_all >> 8;
            x_f224 = x_ret2;
            direct_page_f224 = dp_ret;
            data_bank_f224 = db_ret;
            goto shared_F224;
        }
    }
    if (x_ret) {
        a_hi_f20c2 = a_all >> 8;
        x_f20c2 = (uint8_t)x_ret2;
        y_f20c2 = (uint8_t)y_ret;
        carry_f20c2 = carry1;
        overflow_f20c2 = overflow_ret;
        direct_page_f20c2 = dp_ret;
        data_bank_f20c2 = db_ret;
        goto shared_F20C_1;
    } else {
        a_hi_f20c = a_all >> 8;
        x_f20c = x_ret2;
        y_f20c = y_ret;
        carry_f20c = carry1;
        overflow_f20c = overflow_ret;
        direct_page_f20c = dp_ret;
        data_bank_f20c = db_ret;
        goto shared_F20C;
    }
    shared_F21B:;
    uint8_t value6 = BUS8(c, (db << 0x10) + 0xE00C + x_f21b);
    if (value6 == 0) {
        a_hi_f20c = a_hi_f21b;
        x_f20c = x_f21b;
        y_f20c = y_f21b;
        carry_f20c = carry_f21b;
        overflow_f20c = overflow_f21b;
        direct_page_f20c = 0;
        data_bank_f20c = db;
        goto shared_F20C;
    }
    RAM8(0x0012) = 0xD4;
    a_hi_f224 = a_hi_f21b;
    x_f224 = x_f21b;
    direct_page_f224 = 0;
    data_bank_f224 = db;
    goto shared_F224;
    shared_F20C:;
    BUS8_SET(c, (data_bank_f20c << 0x10) + 0xE00C + x_f20c, 0);
    r->a = (a_hi_f20c << 8) | (uint8_t)a;
    r->x = x_f20c;
    r->y = y_f20c;
    r->c = carry_f20c;
    r->v = overflow_f20c;
    r->mf = true;
    r->xf = false;
    r->db = data_bank_f20c;
    r->dp = direct_page_f20c;
    RETURN_RTS(c);
    shared_F224:;
    BUS8_SET(c, (data_bank_f224 << 0x10) + 0xE00C + x_f224, 0);
    uint16_t value9 = BUS16(c, (data_bank_f224 << 0x10) + 0xE06A + x_f224);
    uint16_t value10 = BUS16(c, (data_bank_f224 << 0x10) + 0xE026 + x_f224);
    RAM16_SET(0x0010 + direct_page_f224, (uint16_t)(value9 + value10));
    uint16_t value11 = BUS16(c, (RAM8(0x0012 + direct_page_f224) << 0x10) + RAM16(0x0010 + direct_page_f224));
    RAM16_SET(0x0010 + direct_page_f224, value11);
    RAM16_SET(0x000A + direct_page_f224, (uint16_t)((uint16_t)(x_f224 << 3) + 0x2000));
    uint16_t value12 = BUS16(c, (data_bank_f224 << 0x10) + 0xE06C + x_f224);
    RAM8(0x0001 + direct_page_f224) = 0;
    uint8_t value13 = BUS8(c, (RAM8(0x0012 + direct_page_f224) << 0x10) + RAM16(0x0010 + direct_page_f224));
    RAM8(0x0010 + direct_page_f224)++;
    if (RAM8(0x0010 + direct_page_f224) == 0) {
        RAM8(0x0011 + direct_page_f224)++;
    }
    a_f24f = value13;
    a_hi_f24f = (uint16_t)((uint16_t)(x_f224 << 3) + 0x2000) >> 8;
    x_f24f = x_f224;
    y_f24f = value12;
    overflow_f24f = (((uint16_t)(x_f224 << 3) ^ (uint16_t)((uint16_t)(x_f224 << 3) + 0x2000)) & ((uint16_t)((uint16_t)(x_f224 << 3) + 0x2000) ^ 0x2000) & 0x8000) != 0;
    direct_page_f24f = direct_page_f224;
    data_bank_f24f = data_bank_f224;
    goto shared_F24F;
    shared_F224_1:;
    BUS8_SET(c, (data_bank_f2242 << 0x10) + 0xE00C + x_f2242, 0);
    uint16_t value14 = BUS16(c, (data_bank_f2242 << 0x10) + 0xE06A + x_f2242);
    uint16_t value15 = BUS16(c, (data_bank_f2242 << 0x10) + 0xE026 + x_f2242);
    RAM16_SET(0x0010 + direct_page_f2242, (uint16_t)(value14 + value15));
    uint16_t value16 = BUS16(c, (RAM8(0x0012 + direct_page_f2242) << 0x10) + RAM16(0x0010 + direct_page_f2242));
    RAM16_SET(0x0010 + direct_page_f2242, value16);
    RAM16_SET(0x000A + direct_page_f2242, (x_f2242 << 1 << 1 << 1) + 0x2000);
    uint8_t value17 = BUS8(c, (data_bank_f2242 << 0x10) + 0xE06C + x_f2242);
    RAM8(0x0001 + direct_page_f2242) = 0;
    uint8_t value18 = BUS8(c, (RAM8(0x0012 + direct_page_f2242) << 0x10) + RAM16(0x0010 + direct_page_f2242));
    RAM8(0x0010 + direct_page_f2242)++;
    if (RAM8(0x0010 + direct_page_f2242) == 0) {
        RAM8(0x0011 + direct_page_f2242)++;
    }
    a_f24f2 = value18;
    a_hi_f24f2 = (x_f2242 << 1 << 1 << 1) + 0x2000 >> 8;
    x_f24f2 = x_f2242;
    y_f24f2 = value17;
    overflow_f24f2 = (((x_f2242 << 1 << 1 << 1) ^ (x_f2242 << 1 << 1 << 1) + 0x2000) & ((x_f2242 << 1 << 1 << 1) + 0x2000 ^ 0x2000) & 0x8000) != 0;
    direct_page_f24f2 = direct_page_f2242;
    data_bank_f24f2 = data_bank_f2242;
    goto shared_F24F_1;
    shared_F20C_1:;
    BUS8_SET(c, (data_bank_f20c2 << 0x10) + 0xE00C + x_f20c2, 0);
    r->a = (a_hi_f20c2 << 8) | (uint8_t)a;
    r->x = x_f20c2;
    r->y = y_f20c2;
    r->c = carry_f20c2;
    r->v = overflow_f20c2;
    r->mf = true;
    r->xf = true;
    r->db = data_bank_f20c2;
    r->dp = direct_page_f20c2;
    RETURN_RTS(c);
    shared_F24F:;
    BUS8_SET(c, (data_bank_f24f << 0x10) + 0xE024 + x_f24f, a_f24f);
    RAM8(0x0004 + direct_page_f24f) = a_f24f;
    RAM8(0x0005 + direct_page_f24f) = (uint8_t)(a_f24f << 2);
    uint8_t value19 = RAM8(0x0004 + direct_page_f24f);
    BUS8_SET(c, (data_bank_f24f << 0x10) + 0xE084 + x_f24f, value19 & 0x0F);
    if ((value19 & 0x0F) != 0) {
        if ((value19 & 0x0F) >= 0x0B) {
            BUS8_SET(c, (data_bank_f24f << 0x10) + 0xE084 + x_f24f, 0);
            r->a = a_hi_f24f << 8 | (value19 & 0x0F);
            r->x = x_f24f;
            r->y = y_f24f;
            r->c = (value19 & 0x0F) >= 0x0B;
            r->v = overflow_f24f;
            r->mf = true;
            r->xf = false;
            r->db = data_bank_f24f;
            r->dp = direct_page_f24f;
            RETURN_RTS(c);
        }
        RAM8(0x0000 + direct_page_f24f) = (value19 & 0x0F) << 1 << 1;
        uint16_t value20 = RAM16(0x0000 + direct_page_f24f);
        uint8_t a_hi1 = a_hi_f24f;
        uint16_t x1 = value20;
        uint16_t y1 = y_f24f;
        for (;;) {
            uint16_t value21 = BUS16(c, (RAM8(0x0012 + direct_page_f24f) << 0x10) + RAM16(0x0010 + direct_page_f24f));
            uint8_t a_hi26;
            if ((value21 & 0x80) != 0) {
                RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                uint8_t a_hi12;
                if ((value21 & 0x40) == 0) {
                    RAM8(0x0000 + sp0) = value21 >> 8;
                    RAM8(0x0000 + sp0 - 1) = (uint8_t)value21;
                    RAM16_SET(0x0002 + direct_page_f24f, value21 & 0x3F);
                    uint8_t value23 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value24 = RAM8(0x0000 + sp0);
                    uint8_t a1;
                    uint8_t a_hi2;
                    if ((((value24 << 8) | value23) & 0x7F00) != 0x7F00) {
                        uint16_t value25 = RAM16(0x000A + direct_page_f24f);
                        a1 = (uint8_t)(((((value24 << 8) | value23) & 0x7F00) >> 3) + value25 + (((((value24 << 8) | value23) & 0x7F00) >> 2) & 1));
                        a_hi2 = (uint16_t)(((((value24 << 8) | value23) & 0x7F00) >> 3) + value25 + (((((value24 << 8) | value23) & 0x7F00) >> 2) & 1)) >> 8;
                    } else {
                        a1 = 0;
                        a_hi2 = 0xCB;
                    }
                    uint16_t x2 = x1;
                    uint16_t y2 = y1;
                    bool negative1 = 0;
                    for (;;) {
                        BUS16_SET(c, (data_bank_f24f << 0x10) + y2, (a_hi2 << 8) | a1);
                        if ((uint16_t)(x2 - 1) != 0) {
                            RAM16_SET(0x0002 + direct_page_f24f, (uint16_t)(RAM16(0x0002 + direct_page_f24f) - 1));
                            if (!(RAM16(0x0002 + direct_page_f24f) & 0x8000)) {
                                x2 = (uint16_t)(x2 - 1);
                                y2 = (uint16_t)(y2 + 2);
                                negative1 = RAM16(0x0002 + direct_page_f24f) & 0x8000;
                                continue;
                            }
                            x2 = (uint16_t)(x2 - 1);
                            y2 = (uint16_t)(y2 + 2);
                            negative1 = RAM16(0x0002 + direct_page_f24f) & 0x8000;
                            break;
                        }
                        a_hi1 = a_hi2;
                        x1 = (uint16_t)(x2 - 1);
                        y1 = (uint16_t)(y2 + 2);
                        goto leave_loop_C0F282;
                    }
                    if (negative1) {
                        a_hi1 = a_hi2;
                        x1 = x2;
                        y1 = y2;
                        continue;
                    }
                    a_hi12 = a_hi2;
                } else {
                    RAM8(0x0000 + sp0) = value21 >> 8;
                    RAM8(0x0000 + sp0 - 1) = (uint8_t)value21;
                    RAM16_SET(0x0002 + direct_page_f24f, value21 & 0x3F);
                    uint8_t value27 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value28 = RAM8(0x0000 + sp0);
                    uint16_t value29 = RAM16(0x000A + direct_page_f24f);
                    uint8_t a2 = (uint8_t)(((((value28 << 8) | value27) & 0x7F00) >> 3) + value29 + (((((value28 << 8) | value27) & 0x7F00) >> 2) & 1));
                    uint8_t a_hi3 = (uint16_t)(((((value28 << 8) | value27) & 0x7F00) >> 3) + value29 + (((((value28 << 8) | value27) & 0x7F00) >> 2) & 1)) >> 8;
                    uint16_t x3 = x1;
                    uint16_t y3 = y1;
                    for (;;) {
                        BUS16_SET(c, (data_bank_f24f << 0x10) + y3, (a_hi3 << 8) | a2);
                        if ((uint16_t)(x3 - 1) != 0) {
                            RAM16_SET(0x0002 + direct_page_f24f, (uint16_t)(RAM16(0x0002 + direct_page_f24f) - 1));
                            if (RAM16(0x0002 + direct_page_f24f) & 0x8000) {
                                x3 = (uint16_t)(x3 - 1);
                                y3 = (uint16_t)(y3 + 2);
                                break;
                            }
                            uint8_t a2_next = (uint8_t)(((a_hi3 << 8) | a2) + 0x20);
                            uint8_t a_hi3_next = (uint16_t)(((a_hi3 << 8) | a2) + 0x20) >> 8;
                            uint16_t x3_next = (uint16_t)(x3 - 1);
                            uint16_t y3_next = (uint16_t)(y3 + 2);
                            a2 = a2_next;
                            a_hi3 = a_hi3_next;
                            x3 = x3_next;
                            y3 = y3_next;
                            continue;
                        }
                        a_hi1 = a_hi3;
                        x1 = (uint16_t)(x3 - 1);
                        y1 = (uint16_t)(y3 + 2);
                        goto leave_loop_C0F282;
                    }
                    uint8_t a_hi4 = a_hi3;
                    uint16_t x4 = x3;
                    uint16_t y4 = y3;
                    for (;;) {
                        uint16_t value30 = BUS16(c, (RAM8(0x0012 + direct_page_f24f) << 0x10) + RAM16(0x0010 + direct_page_f24f));
                        uint8_t a_hi11;
                        if ((value30 & 0x80) != 0) {
                            RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                            RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                            if ((value30 & 0x40) != 0) {
                                RAM8(0x0000 + sp0) = value30 >> 8;
                                RAM8(0x0000 + sp0 - 1) = (uint8_t)value30;
                                RAM16_SET(0x0002 + direct_page_f24f, value30 & 0x3F);
                                uint8_t value36 = RAM8(0x0000 + sp0 - 1);
                                uint8_t value37 = RAM8(0x0000 + sp0);
                                uint16_t value38 = RAM16(0x000A + direct_page_f24f);
                                uint8_t a4 = (uint8_t)(((((value37 << 8) | value36) & 0x7F00) >> 3) + value38 + (((((value37 << 8) | value36) & 0x7F00) >> 2) & 1));
                                uint8_t a_hi6 = (uint16_t)(((((value37 << 8) | value36) & 0x7F00) >> 3) + value38 + (((((value37 << 8) | value36) & 0x7F00) >> 2) & 1)) >> 8;
                                uint16_t x6 = x4;
                                uint16_t y6 = y4;
                                for (;;) {
                                    BUS16_SET(c, (data_bank_f24f << 0x10) + y6, (a_hi6 << 8) | a4);
                                    if ((uint16_t)(x6 - 1) != 0) {
                                        RAM16_SET(0x0002 + direct_page_f24f, (uint16_t)(RAM16(0x0002 + direct_page_f24f) - 1));
                                        if (RAM16(0x0002 + direct_page_f24f) & 0x8000) {
                                            x6 = (uint16_t)(x6 - 1);
                                            y6 = (uint16_t)(y6 + 2);
                                            break;
                                        }
                                        uint8_t a4_next = (uint8_t)(((a_hi6 << 8) | a4) + 0x20);
                                        uint8_t a_hi6_next = (uint16_t)(((a_hi6 << 8) | a4) + 0x20) >> 8;
                                        uint16_t x6_next = (uint16_t)(x6 - 1);
                                        uint16_t y6_next = (uint16_t)(y6 + 2);
                                        a4 = a4_next;
                                        a_hi6 = a_hi6_next;
                                        x6 = x6_next;
                                        y6 = y6_next;
                                        continue;
                                    }
                                    a_hi4 = a_hi6;
                                    x4 = (uint16_t)(x6 - 1);
                                    y4 = (uint16_t)(y6 + 2);
                                    goto leave_loop_C0F282_2;
                                }
                                a_hi1 = a_hi6;
                                x1 = x6;
                                y1 = y6;
                                goto next_pass_C0F282;
                            }
                            RAM8(0x0000 + sp0) = value30 >> 8;
                            RAM8(0x0000 + sp0 - 1) = (uint8_t)value30;
                            RAM16_SET(0x0002 + direct_page_f24f, value30 & 0x3F);
                            uint8_t value32 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value33 = RAM8(0x0000 + sp0);
                            uint8_t a3;
                            uint8_t a_hi5;
                            if ((((value33 << 8) | value32) & 0x7F00) != 0x7F00) {
                                uint16_t value34 = RAM16(0x000A + direct_page_f24f);
                                a3 = (uint8_t)(((((value33 << 8) | value32) & 0x7F00) >> 3) + value34 + (((((value33 << 8) | value32) & 0x7F00) >> 2) & 1));
                                a_hi5 = (uint16_t)(((((value33 << 8) | value32) & 0x7F00) >> 3) + value34 + (((((value33 << 8) | value32) & 0x7F00) >> 2) & 1)) >> 8;
                            } else {
                                a3 = 0;
                                a_hi5 = 0xCB;
                            }
                            uint16_t x5 = x4;
                            uint16_t y5 = y4;
                            bool negative2 = 0;
                            for (;;) {
                                BUS16_SET(c, (data_bank_f24f << 0x10) + y5, (a_hi5 << 8) | a3);
                                if ((uint16_t)(x5 - 1) != 0) {
                                    RAM16_SET(0x0002 + direct_page_f24f, (uint16_t)(RAM16(0x0002 + direct_page_f24f) - 1));
                                    if (!(RAM16(0x0002 + direct_page_f24f) & 0x8000)) {
                                        x5 = (uint16_t)(x5 - 1);
                                        y5 = (uint16_t)(y5 + 2);
                                        negative2 = RAM16(0x0002 + direct_page_f24f) & 0x8000;
                                        continue;
                                    }
                                    x5 = (uint16_t)(x5 - 1);
                                    y5 = (uint16_t)(y5 + 2);
                                    negative2 = RAM16(0x0002 + direct_page_f24f) & 0x8000;
                                    break;
                                }
                                a_hi4 = a_hi5;
                                x4 = (uint16_t)(x5 - 1);
                                y4 = (uint16_t)(y5 + 2);
                                goto leave_loop_C0F282_2;
                            }
                            if (negative2) {
                                a_hi4 = a_hi5;
                                x4 = x5;
                                y4 = y5;
                                continue;
                            }
                            a_hi11 = a_hi5;
                        } else {
                            RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                            uint8_t a5;
                            uint8_t a_hi7;
                            if (((((uint8_t)value30 << 8) | (value30 >> 8)) & 0x7F00) != 0x7F00) {
                                uint16_t value39 = RAM16(0x000A + direct_page_f24f);
                                a5 = (uint8_t)((((((uint8_t)value30 << 8) | (value30 >> 8)) & 0x7F00) >> 3) + value39 + ((((((uint8_t)value30 << 8) | (value30 >> 8)) & 0x7F00) >> 2) & 1));
                                a_hi7 = (uint16_t)((((((uint8_t)value30 << 8) | (value30 >> 8)) & 0x7F00) >> 3) + value39 + ((((((uint8_t)value30 << 8) | (value30 >> 8)) & 0x7F00) >> 2) & 1)) >> 8;
                            } else {
                                a5 = 0;
                                a_hi7 = 0xCB;
                            }
                            BUS16_SET(c, (data_bank_f24f << 0x10) + y4, (a_hi7 << 8) | a5);
                            if ((uint16_t)(x4 - 1) != 0) {
                                a_hi4 = a_hi7;
                                x4 = (uint16_t)(x4 - 1);
                                y4 = (uint16_t)(y4 + 2);
                                continue;
                            }
                            uint8_t a_hi10;
                            if ((uint16_t)(x4 - 1) == 0) {
                                a_hi10 = a_hi7;
                            } else {
                                RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                                RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                                if ((((a_hi7 << 8) | a5) & 0x40) != 0) {
                                    RAM8(0x0000 + sp0) = a_hi7;
                                    RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi7 << 8) | a5);
                                    RAM16_SET(0x0002 + direct_page_f24f, ((a_hi7 << 8) | a5) & 0x3F);
                                    uint8_t value45 = RAM8(0x0000 + sp0 - 1);
                                    uint8_t value46 = RAM8(0x0000 + sp0);
                                    uint16_t value47 = RAM16(0x000A + direct_page_f24f);
                                    uint8_t a7 = (uint8_t)(((((value46 << 8) | value45) & 0x7F00) >> 3) + value47 + (((((value46 << 8) | value45) & 0x7F00) >> 2) & 1));
                                    uint8_t a_hi9 = (uint16_t)(((((value46 << 8) | value45) & 0x7F00) >> 3) + value47 + (((((value46 << 8) | value45) & 0x7F00) >> 2) & 1)) >> 8;
                                    uint16_t x8 = (uint16_t)(x4 - 1);
                                    uint16_t y8 = (uint16_t)(y4 + 2);
                                    for (;;) {
                                        BUS16_SET(c, (data_bank_f24f << 0x10) + y8, (a_hi9 << 8) | a7);
                                        if ((uint16_t)(x8 - 1) != 0) {
                                            RAM16_SET(0x0002 + direct_page_f24f, (uint16_t)(RAM16(0x0002 + direct_page_f24f) - 1));
                                            if (RAM16(0x0002 + direct_page_f24f) & 0x8000) {
                                                x8 = (uint16_t)(x8 - 1);
                                                y8 = (uint16_t)(y8 + 2);
                                                break;
                                            }
                                            uint8_t a7_next = (uint8_t)(((a_hi9 << 8) | a7) + 0x20);
                                            uint8_t a_hi9_next = (uint16_t)(((a_hi9 << 8) | a7) + 0x20) >> 8;
                                            uint16_t x8_next = (uint16_t)(x8 - 1);
                                            uint16_t y8_next = (uint16_t)(y8 + 2);
                                            a7 = a7_next;
                                            a_hi9 = a_hi9_next;
                                            x8 = x8_next;
                                            y8 = y8_next;
                                            continue;
                                        }
                                        a_hi4 = a_hi9;
                                        x4 = (uint16_t)(x8 - 1);
                                        y4 = (uint16_t)(y8 + 2);
                                        goto leave_loop_C0F282_2;
                                    }
                                    a_hi1 = a_hi9;
                                    x1 = x8;
                                    y1 = y8;
                                    goto next_pass_C0F282;
                                }
                                RAM8(0x0000 + sp0) = a_hi7;
                                RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi7 << 8) | a5);
                                RAM16_SET(0x0002 + direct_page_f24f, ((a_hi7 << 8) | a5) & 0x3F);
                                uint8_t value41 = RAM8(0x0000 + sp0 - 1);
                                uint8_t value42 = RAM8(0x0000 + sp0);
                                uint8_t a6;
                                uint8_t a_hi8;
                                if ((((value42 << 8) | value41) & 0x7F00) != 0x7F00) {
                                    uint16_t value43 = RAM16(0x000A + direct_page_f24f);
                                    a6 = (uint8_t)(((((value42 << 8) | value41) & 0x7F00) >> 3) + value43 + (((((value42 << 8) | value41) & 0x7F00) >> 2) & 1));
                                    a_hi8 = (uint16_t)(((((value42 << 8) | value41) & 0x7F00) >> 3) + value43 + (((((value42 << 8) | value41) & 0x7F00) >> 2) & 1)) >> 8;
                                } else {
                                    a6 = 0;
                                    a_hi8 = 0xCB;
                                }
                                uint16_t x7 = (uint16_t)(x4 - 1);
                                uint16_t y7 = (uint16_t)(y4 + 2);
                                bool negative3 = 0;
                                for (;;) {
                                    BUS16_SET(c, (data_bank_f24f << 0x10) + y7, (a_hi8 << 8) | a6);
                                    if ((uint16_t)(x7 - 1) != 0) {
                                        RAM16_SET(0x0002 + direct_page_f24f, (uint16_t)(RAM16(0x0002 + direct_page_f24f) - 1));
                                        if (!(RAM16(0x0002 + direct_page_f24f) & 0x8000)) {
                                            x7 = (uint16_t)(x7 - 1);
                                            y7 = (uint16_t)(y7 + 2);
                                            negative3 = RAM16(0x0002 + direct_page_f24f) & 0x8000;
                                            continue;
                                        }
                                        x7 = (uint16_t)(x7 - 1);
                                        y7 = (uint16_t)(y7 + 2);
                                        negative3 = RAM16(0x0002 + direct_page_f24f) & 0x8000;
                                        break;
                                    }
                                    a_hi4 = a_hi8;
                                    x4 = (uint16_t)(x7 - 1);
                                    y4 = (uint16_t)(y7 + 2);
                                    goto leave_loop_C0F282_2;
                                }
                                if (negative3) {
                                    a_hi4 = a_hi8;
                                    x4 = x7;
                                    y4 = y7;
                                    continue;
                                }
                                a_hi10 = a_hi8;
                            }
                            a_hi11 = a_hi10;
                        }
                        a_hi4 = a_hi11;
                        break;
                    }
                    leave_loop_C0F282_2:;
                    a_hi12 = a_hi4;
                }
                a_hi26 = a_hi12;
            } else {
                RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                uint8_t a8;
                uint8_t a_hi13;
                if (((((uint8_t)value21 << 8) | (value21 >> 8)) & 0x7F00) != 0x7F00) {
                    uint16_t value48 = RAM16(0x000A + direct_page_f24f);
                    a8 = (uint8_t)((((((uint8_t)value21 << 8) | (value21 >> 8)) & 0x7F00) >> 3) + value48 + ((((((uint8_t)value21 << 8) | (value21 >> 8)) & 0x7F00) >> 2) & 1));
                    a_hi13 = (uint16_t)((((((uint8_t)value21 << 8) | (value21 >> 8)) & 0x7F00) >> 3) + value48 + ((((((uint8_t)value21 << 8) | (value21 >> 8)) & 0x7F00) >> 2) & 1)) >> 8;
                } else {
                    a8 = 0;
                    a_hi13 = 0xCB;
                }
                BUS16_SET(c, (data_bank_f24f << 0x10) + y1, (a_hi13 << 8) | a8);
                if ((uint16_t)(x1 - 1) != 0) {
                    a_hi1 = a_hi13;
                    x1 = (uint16_t)(x1 - 1);
                    y1 = (uint16_t)(y1 + 2);
                    continue;
                }
                uint8_t a_hi25;
                if ((uint16_t)(x1 - 1) == 0) {
                    a_hi25 = a_hi13;
                } else {
                    RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                    RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                    uint8_t a_hi24;
                    if ((((a_hi13 << 8) | a8) & 0x40) == 0) {
                        RAM8(0x0000 + sp0) = a_hi13;
                        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi13 << 8) | a8);
                        RAM16_SET(0x0002 + direct_page_f24f, ((a_hi13 << 8) | a8) & 0x3F);
                        uint8_t value50 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value51 = RAM8(0x0000 + sp0);
                        uint8_t a9;
                        uint8_t a_hi14;
                        if ((((value51 << 8) | value50) & 0x7F00) != 0x7F00) {
                            uint16_t value52 = RAM16(0x000A + direct_page_f24f);
                            a9 = (uint8_t)(((((value51 << 8) | value50) & 0x7F00) >> 3) + value52 + (((((value51 << 8) | value50) & 0x7F00) >> 2) & 1));
                            a_hi14 = (uint16_t)(((((value51 << 8) | value50) & 0x7F00) >> 3) + value52 + (((((value51 << 8) | value50) & 0x7F00) >> 2) & 1)) >> 8;
                        } else {
                            a9 = 0;
                            a_hi14 = 0xCB;
                        }
                        uint16_t x9 = (uint16_t)(x1 - 1);
                        uint16_t y9 = (uint16_t)(y1 + 2);
                        bool negative4 = 0;
                        for (;;) {
                            BUS16_SET(c, (data_bank_f24f << 0x10) + y9, (a_hi14 << 8) | a9);
                            if ((uint16_t)(x9 - 1) != 0) {
                                RAM16_SET(0x0002 + direct_page_f24f, (uint16_t)(RAM16(0x0002 + direct_page_f24f) - 1));
                                if (!(RAM16(0x0002 + direct_page_f24f) & 0x8000)) {
                                    x9 = (uint16_t)(x9 - 1);
                                    y9 = (uint16_t)(y9 + 2);
                                    negative4 = RAM16(0x0002 + direct_page_f24f) & 0x8000;
                                    continue;
                                }
                                x9 = (uint16_t)(x9 - 1);
                                y9 = (uint16_t)(y9 + 2);
                                negative4 = RAM16(0x0002 + direct_page_f24f) & 0x8000;
                                break;
                            }
                            a_hi1 = a_hi14;
                            x1 = (uint16_t)(x9 - 1);
                            y1 = (uint16_t)(y9 + 2);
                            goto leave_loop_C0F282;
                        }
                        if (negative4) {
                            a_hi1 = a_hi14;
                            x1 = x9;
                            y1 = y9;
                            continue;
                        }
                        a_hi24 = a_hi14;
                    } else {
                        RAM8(0x0000 + sp0) = a_hi13;
                        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi13 << 8) | a8);
                        RAM16_SET(0x0002 + direct_page_f24f, ((a_hi13 << 8) | a8) & 0x3F);
                        uint8_t value54 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value55 = RAM8(0x0000 + sp0);
                        uint16_t value56 = RAM16(0x000A + direct_page_f24f);
                        uint8_t a10 = (uint8_t)(((((value55 << 8) | value54) & 0x7F00) >> 3) + value56 + (((((value55 << 8) | value54) & 0x7F00) >> 2) & 1));
                        uint8_t a_hi15 = (uint16_t)(((((value55 << 8) | value54) & 0x7F00) >> 3) + value56 + (((((value55 << 8) | value54) & 0x7F00) >> 2) & 1)) >> 8;
                        uint16_t x10 = (uint16_t)(x1 - 1);
                        uint16_t y10 = (uint16_t)(y1 + 2);
                        for (;;) {
                            BUS16_SET(c, (data_bank_f24f << 0x10) + y10, (a_hi15 << 8) | a10);
                            if ((uint16_t)(x10 - 1) != 0) {
                                RAM16_SET(0x0002 + direct_page_f24f, (uint16_t)(RAM16(0x0002 + direct_page_f24f) - 1));
                                if (RAM16(0x0002 + direct_page_f24f) & 0x8000) {
                                    x10 = (uint16_t)(x10 - 1);
                                    y10 = (uint16_t)(y10 + 2);
                                    break;
                                }
                                uint8_t a10_next = (uint8_t)(((a_hi15 << 8) | a10) + 0x20);
                                uint8_t a_hi15_next = (uint16_t)(((a_hi15 << 8) | a10) + 0x20) >> 8;
                                uint16_t x10_next = (uint16_t)(x10 - 1);
                                uint16_t y10_next = (uint16_t)(y10 + 2);
                                a10 = a10_next;
                                a_hi15 = a_hi15_next;
                                x10 = x10_next;
                                y10 = y10_next;
                                continue;
                            }
                            a_hi1 = a_hi15;
                            x1 = (uint16_t)(x10 - 1);
                            y1 = (uint16_t)(y10 + 2);
                            goto leave_loop_C0F282;
                        }
                        uint8_t a_hi16 = a_hi15;
                        uint16_t x11 = x10;
                        uint16_t y11 = y10;
                        for (;;) {
                            uint16_t value57 = BUS16(c, (RAM8(0x0012 + direct_page_f24f) << 0x10) + RAM16(0x0010 + direct_page_f24f));
                            uint8_t a_hi23;
                            if ((value57 & 0x80) != 0) {
                                RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                                RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                                if ((value57 & 0x40) != 0) {
                                    RAM8(0x0000 + sp0) = value57 >> 8;
                                    RAM8(0x0000 + sp0 - 1) = (uint8_t)value57;
                                    RAM16_SET(0x0002 + direct_page_f24f, value57 & 0x3F);
                                    uint8_t value63 = RAM8(0x0000 + sp0 - 1);
                                    uint8_t value64 = RAM8(0x0000 + sp0);
                                    uint16_t value65 = RAM16(0x000A + direct_page_f24f);
                                    uint8_t a12 = (uint8_t)(((((value64 << 8) | value63) & 0x7F00) >> 3) + value65 + (((((value64 << 8) | value63) & 0x7F00) >> 2) & 1));
                                    uint8_t a_hi18 = (uint16_t)(((((value64 << 8) | value63) & 0x7F00) >> 3) + value65 + (((((value64 << 8) | value63) & 0x7F00) >> 2) & 1)) >> 8;
                                    uint16_t x13 = x11;
                                    uint16_t y13 = y11;
                                    for (;;) {
                                        BUS16_SET(c, (data_bank_f24f << 0x10) + y13, (a_hi18 << 8) | a12);
                                        if ((uint16_t)(x13 - 1) != 0) {
                                            RAM16_SET(0x0002 + direct_page_f24f, (uint16_t)(RAM16(0x0002 + direct_page_f24f) - 1));
                                            if (RAM16(0x0002 + direct_page_f24f) & 0x8000) {
                                                x13 = (uint16_t)(x13 - 1);
                                                y13 = (uint16_t)(y13 + 2);
                                                break;
                                            }
                                            uint8_t a12_next = (uint8_t)(((a_hi18 << 8) | a12) + 0x20);
                                            uint8_t a_hi18_next = (uint16_t)(((a_hi18 << 8) | a12) + 0x20) >> 8;
                                            uint16_t x13_next = (uint16_t)(x13 - 1);
                                            uint16_t y13_next = (uint16_t)(y13 + 2);
                                            a12 = a12_next;
                                            a_hi18 = a_hi18_next;
                                            x13 = x13_next;
                                            y13 = y13_next;
                                            continue;
                                        }
                                        a_hi16 = a_hi18;
                                        x11 = (uint16_t)(x13 - 1);
                                        y11 = (uint16_t)(y13 + 2);
                                        goto leave_loop_C0F282_3;
                                    }
                                    a_hi1 = a_hi18;
                                    x1 = x13;
                                    y1 = y13;
                                    goto next_pass_C0F282;
                                }
                                RAM8(0x0000 + sp0) = value57 >> 8;
                                RAM8(0x0000 + sp0 - 1) = (uint8_t)value57;
                                RAM16_SET(0x0002 + direct_page_f24f, value57 & 0x3F);
                                uint8_t value59 = RAM8(0x0000 + sp0 - 1);
                                uint8_t value60 = RAM8(0x0000 + sp0);
                                uint8_t a11;
                                uint8_t a_hi17;
                                if ((((value60 << 8) | value59) & 0x7F00) != 0x7F00) {
                                    uint16_t value61 = RAM16(0x000A + direct_page_f24f);
                                    a11 = (uint8_t)(((((value60 << 8) | value59) & 0x7F00) >> 3) + value61 + (((((value60 << 8) | value59) & 0x7F00) >> 2) & 1));
                                    a_hi17 = (uint16_t)(((((value60 << 8) | value59) & 0x7F00) >> 3) + value61 + (((((value60 << 8) | value59) & 0x7F00) >> 2) & 1)) >> 8;
                                } else {
                                    a11 = 0;
                                    a_hi17 = 0xCB;
                                }
                                uint16_t x12 = x11;
                                uint16_t y12 = y11;
                                bool negative5 = 0;
                                for (;;) {
                                    BUS16_SET(c, (data_bank_f24f << 0x10) + y12, (a_hi17 << 8) | a11);
                                    if ((uint16_t)(x12 - 1) != 0) {
                                        RAM16_SET(0x0002 + direct_page_f24f, (uint16_t)(RAM16(0x0002 + direct_page_f24f) - 1));
                                        if (!(RAM16(0x0002 + direct_page_f24f) & 0x8000)) {
                                            x12 = (uint16_t)(x12 - 1);
                                            y12 = (uint16_t)(y12 + 2);
                                            negative5 = RAM16(0x0002 + direct_page_f24f) & 0x8000;
                                            continue;
                                        }
                                        x12 = (uint16_t)(x12 - 1);
                                        y12 = (uint16_t)(y12 + 2);
                                        negative5 = RAM16(0x0002 + direct_page_f24f) & 0x8000;
                                        break;
                                    }
                                    a_hi16 = a_hi17;
                                    x11 = (uint16_t)(x12 - 1);
                                    y11 = (uint16_t)(y12 + 2);
                                    goto leave_loop_C0F282_3;
                                }
                                if (negative5) {
                                    a_hi16 = a_hi17;
                                    x11 = x12;
                                    y11 = y12;
                                    continue;
                                }
                                a_hi23 = a_hi17;
                            } else {
                                RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                                uint8_t a13;
                                uint8_t a_hi19;
                                if (((((uint8_t)value57 << 8) | (value57 >> 8)) & 0x7F00) != 0x7F00) {
                                    uint16_t value66 = RAM16(0x000A + direct_page_f24f);
                                    a13 = (uint8_t)((((((uint8_t)value57 << 8) | (value57 >> 8)) & 0x7F00) >> 3) + value66 + ((((((uint8_t)value57 << 8) | (value57 >> 8)) & 0x7F00) >> 2) & 1));
                                    a_hi19 = (uint16_t)((((((uint8_t)value57 << 8) | (value57 >> 8)) & 0x7F00) >> 3) + value66 + ((((((uint8_t)value57 << 8) | (value57 >> 8)) & 0x7F00) >> 2) & 1)) >> 8;
                                } else {
                                    a13 = 0;
                                    a_hi19 = 0xCB;
                                }
                                BUS16_SET(c, (data_bank_f24f << 0x10) + y11, (a_hi19 << 8) | a13);
                                if ((uint16_t)(x11 - 1) != 0) {
                                    a_hi16 = a_hi19;
                                    x11 = (uint16_t)(x11 - 1);
                                    y11 = (uint16_t)(y11 + 2);
                                    continue;
                                }
                                uint8_t a_hi22;
                                if ((uint16_t)(x11 - 1) == 0) {
                                    a_hi22 = a_hi19;
                                } else {
                                    RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                                    RAM16_SET(0x0010 + direct_page_f24f, (uint16_t)(RAM16(0x0010 + direct_page_f24f) + 1));
                                    if ((((a_hi19 << 8) | a13) & 0x40) != 0) {
                                        RAM8(0x0000 + sp0) = a_hi19;
                                        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi19 << 8) | a13);
                                        RAM16_SET(0x0002 + direct_page_f24f, ((a_hi19 << 8) | a13) & 0x3F);
                                        uint8_t value72 = RAM8(0x0000 + sp0 - 1);
                                        uint8_t value73 = RAM8(0x0000 + sp0);
                                        uint16_t value74 = RAM16(0x000A + direct_page_f24f);
                                        uint8_t a15 = (uint8_t)(((((value73 << 8) | value72) & 0x7F00) >> 3) + value74 + (((((value73 << 8) | value72) & 0x7F00) >> 2) & 1));
                                        uint8_t a_hi21 = (uint16_t)(((((value73 << 8) | value72) & 0x7F00) >> 3) + value74 + (((((value73 << 8) | value72) & 0x7F00) >> 2) & 1)) >> 8;
                                        uint16_t x15 = (uint16_t)(x11 - 1);
                                        uint16_t y15 = (uint16_t)(y11 + 2);
                                        for (;;) {
                                            BUS16_SET(c, (data_bank_f24f << 0x10) + y15, (a_hi21 << 8) | a15);
                                            if ((uint16_t)(x15 - 1) != 0) {
                                                RAM16_SET(0x0002 + direct_page_f24f, (uint16_t)(RAM16(0x0002 + direct_page_f24f) - 1));
                                                if (RAM16(0x0002 + direct_page_f24f) & 0x8000) {
                                                    x15 = (uint16_t)(x15 - 1);
                                                    y15 = (uint16_t)(y15 + 2);
                                                    break;
                                                }
                                                uint8_t a15_next = (uint8_t)(((a_hi21 << 8) | a15) + 0x20);
                                                uint8_t a_hi21_next = (uint16_t)(((a_hi21 << 8) | a15) + 0x20) >> 8;
                                                uint16_t x15_next = (uint16_t)(x15 - 1);
                                                uint16_t y15_next = (uint16_t)(y15 + 2);
                                                a15 = a15_next;
                                                a_hi21 = a_hi21_next;
                                                x15 = x15_next;
                                                y15 = y15_next;
                                                continue;
                                            }
                                            a_hi16 = a_hi21;
                                            x11 = (uint16_t)(x15 - 1);
                                            y11 = (uint16_t)(y15 + 2);
                                            goto leave_loop_C0F282_3;
                                        }
                                        a_hi1 = a_hi21;
                                        x1 = x15;
                                        y1 = y15;
                                        goto next_pass_C0F282;
                                    }
                                    RAM8(0x0000 + sp0) = a_hi19;
                                    RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi19 << 8) | a13);
                                    RAM16_SET(0x0002 + direct_page_f24f, ((a_hi19 << 8) | a13) & 0x3F);
                                    uint8_t value68 = RAM8(0x0000 + sp0 - 1);
                                    uint8_t value69 = RAM8(0x0000 + sp0);
                                    uint8_t a14;
                                    uint8_t a_hi20;
                                    if ((((value69 << 8) | value68) & 0x7F00) != 0x7F00) {
                                        uint16_t value70 = RAM16(0x000A + direct_page_f24f);
                                        a14 = (uint8_t)(((((value69 << 8) | value68) & 0x7F00) >> 3) + value70 + (((((value69 << 8) | value68) & 0x7F00) >> 2) & 1));
                                        a_hi20 = (uint16_t)(((((value69 << 8) | value68) & 0x7F00) >> 3) + value70 + (((((value69 << 8) | value68) & 0x7F00) >> 2) & 1)) >> 8;
                                    } else {
                                        a14 = 0;
                                        a_hi20 = 0xCB;
                                    }
                                    uint16_t x14 = (uint16_t)(x11 - 1);
                                    uint16_t y14 = (uint16_t)(y11 + 2);
                                    bool negative6 = 0;
                                    for (;;) {
                                        BUS16_SET(c, (data_bank_f24f << 0x10) + y14, (a_hi20 << 8) | a14);
                                        if ((uint16_t)(x14 - 1) != 0) {
                                            RAM16_SET(0x0002 + direct_page_f24f, (uint16_t)(RAM16(0x0002 + direct_page_f24f) - 1));
                                            if (!(RAM16(0x0002 + direct_page_f24f) & 0x8000)) {
                                                x14 = (uint16_t)(x14 - 1);
                                                y14 = (uint16_t)(y14 + 2);
                                                negative6 = RAM16(0x0002 + direct_page_f24f) & 0x8000;
                                                continue;
                                            }
                                            x14 = (uint16_t)(x14 - 1);
                                            y14 = (uint16_t)(y14 + 2);
                                            negative6 = RAM16(0x0002 + direct_page_f24f) & 0x8000;
                                            break;
                                        }
                                        a_hi16 = a_hi20;
                                        x11 = (uint16_t)(x14 - 1);
                                        y11 = (uint16_t)(y14 + 2);
                                        goto leave_loop_C0F282_3;
                                    }
                                    if (negative6) {
                                        a_hi16 = a_hi20;
                                        x11 = x14;
                                        y11 = y14;
                                        continue;
                                    }
                                    a_hi22 = a_hi20;
                                }
                                a_hi23 = a_hi22;
                            }
                            a_hi16 = a_hi23;
                            break;
                        }
                        leave_loop_C0F282_3:;
                        a_hi24 = a_hi16;
                    }
                    a_hi25 = a_hi24;
                }
                a_hi26 = a_hi25;
            }
            a_hi1 = a_hi26;
            break;
            next_pass_C0F282:;
        }
        leave_loop_C0F282:;
        a_hi_f2f9 = a_hi1;
        direct_page_f2f9 = direct_page_f24f;
        data_bank_f2f9 = data_bank_f24f;
        goto shared_F2F9;
    }
    uint8_t value75 = BUS8(c, (data_bank_f24f << 0x10) + 0xE074 + x_f24f);
    RAM8(0x0003 + direct_page_f24f) = value75 & 0x7F;
    uint8_t value76 = BUS8(c, (data_bank_f24f << 0x10) + 0xE028 + x_f24f);
    RAM8(0x0002 + direct_page_f24f) = value76 & 0xC0;
    a_hi_f409 = a_hi_f24f;
    y_f409 = y_f24f;
    carry_f409 = (uint8_t)(a_f24f << 1) & 0x80;
    overflow_f409 = overflow_f24f;
    direct_page_f409 = direct_page_f24f;
    data_bank_f409 = data_bank_f24f;
    goto shared_F409;
    shared_F24F_1:;
    BUS8_SET(c, (data_bank_f24f2 << 0x10) + 0xE024 + x_f24f2, a_f24f2);
    RAM8(0x0004 + direct_page_f24f2) = a_f24f2;
    RAM8(0x0005 + direct_page_f24f2) = (uint8_t)(a_f24f2 << 2);
    uint8_t value77 = RAM8(0x0004 + direct_page_f24f2);
    BUS8_SET(c, (data_bank_f24f2 << 0x10) + 0xE084 + x_f24f2, value77 & 0x0F);
    if ((value77 & 0x0F) != 0) {
        if ((value77 & 0x0F) >= 0x0B) {
            BUS8_SET(c, (data_bank_f24f2 << 0x10) + 0xE084 + x_f24f2, 0);
            r->a = a_hi_f24f2 << 8 | (value77 & 0x0F);
            r->x = x_f24f2;
            r->y = y_f24f2;
            r->c = (value77 & 0x0F) >= 0x0B;
            r->v = overflow_f24f2;
            r->mf = true;
            r->xf = true;
            r->db = data_bank_f24f2;
            r->dp = direct_page_f24f2;
            RETURN_RTS(c);
        }
        RAM8(0x0000 + direct_page_f24f2) = (value77 & 0x0F) << 1 << 1;
        uint8_t value78 = RAM8(0x0000 + direct_page_f24f2);
        uint8_t a_hi27 = a_hi_f24f2;
        uint8_t x16 = value78;
        uint8_t y16 = y_f24f2;
        for (;;) {
            uint16_t value79 = BUS16(c, (RAM8(0x0012 + direct_page_f24f2) << 0x10) + RAM16(0x0010 + direct_page_f24f2));
            uint8_t a_hi52;
            if ((value79 & 0x80) != 0) {
                RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                uint8_t a_hi38;
                if ((value79 & 0x40) == 0) {
                    RAM8(0x0000 + sp0) = value79 >> 8;
                    RAM8(0x0000 + sp0 - 1) = (uint8_t)value79;
                    RAM16_SET(0x0002 + direct_page_f24f2, value79 & 0x3F);
                    uint8_t value81 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value82 = RAM8(0x0000 + sp0);
                    uint8_t a16;
                    uint8_t a_hi28;
                    if ((((value82 << 8) | value81) & 0x7F00) != 0x7F00) {
                        uint16_t value83 = RAM16(0x000A + direct_page_f24f2);
                        a16 = (uint8_t)(((((value82 << 8) | value81) & 0x7F00) >> 3) + value83 + (((((value82 << 8) | value81) & 0x7F00) >> 2) & 1));
                        a_hi28 = (uint16_t)(((((value82 << 8) | value81) & 0x7F00) >> 3) + value83 + (((((value82 << 8) | value81) & 0x7F00) >> 2) & 1)) >> 8;
                    } else {
                        a16 = 0;
                        a_hi28 = 0xCB;
                    }
                    uint8_t x17 = x16;
                    uint8_t y17 = y16;
                    bool negative7 = 0;
                    for (;;) {
                        BUS16_SET(c, (data_bank_f24f2 << 0x10) + y17, (a_hi28 << 8) | a16);
                        if ((uint8_t)(x17 - 1) != 0) {
                            RAM16_SET(0x0002 + direct_page_f24f2, (uint16_t)(RAM16(0x0002 + direct_page_f24f2) - 1));
                            if (!(RAM16(0x0002 + direct_page_f24f2) & 0x8000)) {
                                x17 = (uint8_t)(x17 - 1);
                                y17 = (uint8_t)(y17 + 2);
                                negative7 = RAM16(0x0002 + direct_page_f24f2) & 0x8000;
                                continue;
                            }
                            x17 = (uint8_t)(x17 - 1);
                            y17 = (uint8_t)(y17 + 2);
                            negative7 = RAM16(0x0002 + direct_page_f24f2) & 0x8000;
                            break;
                        }
                        a_hi27 = a_hi28;
                        x16 = (uint8_t)(x17 - 1);
                        y16 = (uint8_t)(y17 + 2);
                        goto leave_loop_C0F282_4;
                    }
                    if (negative7) {
                        a_hi27 = a_hi28;
                        x16 = x17;
                        y16 = y17;
                        continue;
                    }
                    a_hi38 = a_hi28;
                } else {
                    RAM8(0x0000 + sp0) = value79 >> 8;
                    RAM8(0x0000 + sp0 - 1) = (uint8_t)value79;
                    RAM16_SET(0x0002 + direct_page_f24f2, value79 & 0x3F);
                    uint8_t value85 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value86 = RAM8(0x0000 + sp0);
                    uint16_t value87 = RAM16(0x000A + direct_page_f24f2);
                    uint8_t a17 = (uint8_t)(((((value86 << 8) | value85) & 0x7F00) >> 3) + value87 + (((((value86 << 8) | value85) & 0x7F00) >> 2) & 1));
                    uint8_t a_hi29 = (uint16_t)(((((value86 << 8) | value85) & 0x7F00) >> 3) + value87 + (((((value86 << 8) | value85) & 0x7F00) >> 2) & 1)) >> 8;
                    uint8_t x18 = x16;
                    uint8_t y18 = y16;
                    for (;;) {
                        BUS16_SET(c, (data_bank_f24f2 << 0x10) + y18, (a_hi29 << 8) | a17);
                        if ((uint8_t)(x18 - 1) != 0) {
                            RAM16_SET(0x0002 + direct_page_f24f2, (uint16_t)(RAM16(0x0002 + direct_page_f24f2) - 1));
                            if (RAM16(0x0002 + direct_page_f24f2) & 0x8000) {
                                x18 = (uint8_t)(x18 - 1);
                                y18 = (uint8_t)(y18 + 2);
                                break;
                            }
                            uint8_t a17_next = (uint8_t)(((a_hi29 << 8) | a17) + 0x20);
                            uint8_t a_hi29_next = (uint16_t)(((a_hi29 << 8) | a17) + 0x20) >> 8;
                            uint8_t x18_next = (uint8_t)(x18 - 1);
                            uint8_t y18_next = (uint8_t)(y18 + 2);
                            a17 = a17_next;
                            a_hi29 = a_hi29_next;
                            x18 = x18_next;
                            y18 = y18_next;
                            continue;
                        }
                        a_hi27 = a_hi29;
                        x16 = (uint8_t)(x18 - 1);
                        y16 = (uint8_t)(y18 + 2);
                        goto leave_loop_C0F282_4;
                    }
                    uint8_t a_hi30 = a_hi29;
                    uint8_t x19 = x18;
                    uint8_t y19 = y18;
                    for (;;) {
                        uint16_t value88 = BUS16(c, (RAM8(0x0012 + direct_page_f24f2) << 0x10) + RAM16(0x0010 + direct_page_f24f2));
                        uint8_t a_hi37;
                        if ((value88 & 0x80) != 0) {
                            RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                            RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                            if ((value88 & 0x40) != 0) {
                                RAM8(0x0000 + sp0) = value88 >> 8;
                                RAM8(0x0000 + sp0 - 1) = (uint8_t)value88;
                                RAM16_SET(0x0002 + direct_page_f24f2, value88 & 0x3F);
                                uint8_t value94 = RAM8(0x0000 + sp0 - 1);
                                uint8_t value95 = RAM8(0x0000 + sp0);
                                uint16_t value96 = RAM16(0x000A + direct_page_f24f2);
                                uint8_t a19 = (uint8_t)(((((value95 << 8) | value94) & 0x7F00) >> 3) + value96 + (((((value95 << 8) | value94) & 0x7F00) >> 2) & 1));
                                uint8_t a_hi32 = (uint16_t)(((((value95 << 8) | value94) & 0x7F00) >> 3) + value96 + (((((value95 << 8) | value94) & 0x7F00) >> 2) & 1)) >> 8;
                                uint8_t x21 = x19;
                                uint8_t y21 = y19;
                                for (;;) {
                                    BUS16_SET(c, (data_bank_f24f2 << 0x10) + y21, (a_hi32 << 8) | a19);
                                    if ((uint8_t)(x21 - 1) != 0) {
                                        RAM16_SET(0x0002 + direct_page_f24f2, (uint16_t)(RAM16(0x0002 + direct_page_f24f2) - 1));
                                        if (RAM16(0x0002 + direct_page_f24f2) & 0x8000) {
                                            x21 = (uint8_t)(x21 - 1);
                                            y21 = (uint8_t)(y21 + 2);
                                            break;
                                        }
                                        uint8_t a19_next = (uint8_t)(((a_hi32 << 8) | a19) + 0x20);
                                        uint8_t a_hi32_next = (uint16_t)(((a_hi32 << 8) | a19) + 0x20) >> 8;
                                        uint8_t x21_next = (uint8_t)(x21 - 1);
                                        uint8_t y21_next = (uint8_t)(y21 + 2);
                                        a19 = a19_next;
                                        a_hi32 = a_hi32_next;
                                        x21 = x21_next;
                                        y21 = y21_next;
                                        continue;
                                    }
                                    a_hi30 = a_hi32;
                                    x19 = (uint8_t)(x21 - 1);
                                    y19 = (uint8_t)(y21 + 2);
                                    goto leave_loop_C0F282_5;
                                }
                                a_hi27 = a_hi32;
                                x16 = x21;
                                y16 = y21;
                                goto next_pass_C0F282_2;
                            }
                            RAM8(0x0000 + sp0) = value88 >> 8;
                            RAM8(0x0000 + sp0 - 1) = (uint8_t)value88;
                            RAM16_SET(0x0002 + direct_page_f24f2, value88 & 0x3F);
                            uint8_t value90 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value91 = RAM8(0x0000 + sp0);
                            uint8_t a18;
                            uint8_t a_hi31;
                            if ((((value91 << 8) | value90) & 0x7F00) != 0x7F00) {
                                uint16_t value92 = RAM16(0x000A + direct_page_f24f2);
                                a18 = (uint8_t)(((((value91 << 8) | value90) & 0x7F00) >> 3) + value92 + (((((value91 << 8) | value90) & 0x7F00) >> 2) & 1));
                                a_hi31 = (uint16_t)(((((value91 << 8) | value90) & 0x7F00) >> 3) + value92 + (((((value91 << 8) | value90) & 0x7F00) >> 2) & 1)) >> 8;
                            } else {
                                a18 = 0;
                                a_hi31 = 0xCB;
                            }
                            uint8_t x20 = x19;
                            uint8_t y20 = y19;
                            bool negative8 = 0;
                            for (;;) {
                                BUS16_SET(c, (data_bank_f24f2 << 0x10) + y20, (a_hi31 << 8) | a18);
                                if ((uint8_t)(x20 - 1) != 0) {
                                    RAM16_SET(0x0002 + direct_page_f24f2, (uint16_t)(RAM16(0x0002 + direct_page_f24f2) - 1));
                                    if (!(RAM16(0x0002 + direct_page_f24f2) & 0x8000)) {
                                        x20 = (uint8_t)(x20 - 1);
                                        y20 = (uint8_t)(y20 + 2);
                                        negative8 = RAM16(0x0002 + direct_page_f24f2) & 0x8000;
                                        continue;
                                    }
                                    x20 = (uint8_t)(x20 - 1);
                                    y20 = (uint8_t)(y20 + 2);
                                    negative8 = RAM16(0x0002 + direct_page_f24f2) & 0x8000;
                                    break;
                                }
                                a_hi30 = a_hi31;
                                x19 = (uint8_t)(x20 - 1);
                                y19 = (uint8_t)(y20 + 2);
                                goto leave_loop_C0F282_5;
                            }
                            if (negative8) {
                                a_hi30 = a_hi31;
                                x19 = x20;
                                y19 = y20;
                                continue;
                            }
                            a_hi37 = a_hi31;
                        } else {
                            RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                            uint8_t a20;
                            uint8_t a_hi33;
                            if (((((uint8_t)value88 << 8) | (value88 >> 8)) & 0x7F00) != 0x7F00) {
                                uint16_t value97 = RAM16(0x000A + direct_page_f24f2);
                                a20 = (uint8_t)((((((uint8_t)value88 << 8) | (value88 >> 8)) & 0x7F00) >> 3) + value97 + ((((((uint8_t)value88 << 8) | (value88 >> 8)) & 0x7F00) >> 2) & 1));
                                a_hi33 = (uint16_t)((((((uint8_t)value88 << 8) | (value88 >> 8)) & 0x7F00) >> 3) + value97 + ((((((uint8_t)value88 << 8) | (value88 >> 8)) & 0x7F00) >> 2) & 1)) >> 8;
                            } else {
                                a20 = 0;
                                a_hi33 = 0xCB;
                            }
                            BUS16_SET(c, (data_bank_f24f2 << 0x10) + y19, (a_hi33 << 8) | a20);
                            if ((uint8_t)(x19 - 1) != 0) {
                                a_hi30 = a_hi33;
                                x19 = (uint8_t)(x19 - 1);
                                y19 = (uint8_t)(y19 + 2);
                                continue;
                            }
                            uint8_t a_hi36;
                            if ((uint8_t)(x19 - 1) == 0) {
                                a_hi36 = a_hi33;
                            } else {
                                RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                                RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                                if ((((a_hi33 << 8) | a20) & 0x40) != 0) {
                                    RAM8(0x0000 + sp0) = a_hi33;
                                    RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi33 << 8) | a20);
                                    RAM16_SET(0x0002 + direct_page_f24f2, ((a_hi33 << 8) | a20) & 0x3F);
                                    uint8_t value103 = RAM8(0x0000 + sp0 - 1);
                                    uint8_t value104 = RAM8(0x0000 + sp0);
                                    uint16_t value105 = RAM16(0x000A + direct_page_f24f2);
                                    uint8_t a22 = (uint8_t)(((((value104 << 8) | value103) & 0x7F00) >> 3) + value105 + (((((value104 << 8) | value103) & 0x7F00) >> 2) & 1));
                                    uint8_t a_hi35 = (uint16_t)(((((value104 << 8) | value103) & 0x7F00) >> 3) + value105 + (((((value104 << 8) | value103) & 0x7F00) >> 2) & 1)) >> 8;
                                    uint8_t x23 = (uint8_t)(x19 - 1);
                                    uint8_t y23 = (uint8_t)(y19 + 2);
                                    for (;;) {
                                        BUS16_SET(c, (data_bank_f24f2 << 0x10) + y23, (a_hi35 << 8) | a22);
                                        if ((uint8_t)(x23 - 1) != 0) {
                                            RAM16_SET(0x0002 + direct_page_f24f2, (uint16_t)(RAM16(0x0002 + direct_page_f24f2) - 1));
                                            if (RAM16(0x0002 + direct_page_f24f2) & 0x8000) {
                                                x23 = (uint8_t)(x23 - 1);
                                                y23 = (uint8_t)(y23 + 2);
                                                break;
                                            }
                                            uint8_t a22_next = (uint8_t)(((a_hi35 << 8) | a22) + 0x20);
                                            uint8_t a_hi35_next = (uint16_t)(((a_hi35 << 8) | a22) + 0x20) >> 8;
                                            uint8_t x23_next = (uint8_t)(x23 - 1);
                                            uint8_t y23_next = (uint8_t)(y23 + 2);
                                            a22 = a22_next;
                                            a_hi35 = a_hi35_next;
                                            x23 = x23_next;
                                            y23 = y23_next;
                                            continue;
                                        }
                                        a_hi30 = a_hi35;
                                        x19 = (uint8_t)(x23 - 1);
                                        y19 = (uint8_t)(y23 + 2);
                                        goto leave_loop_C0F282_5;
                                    }
                                    a_hi27 = a_hi35;
                                    x16 = x23;
                                    y16 = y23;
                                    goto next_pass_C0F282_2;
                                }
                                RAM8(0x0000 + sp0) = a_hi33;
                                RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi33 << 8) | a20);
                                RAM16_SET(0x0002 + direct_page_f24f2, ((a_hi33 << 8) | a20) & 0x3F);
                                uint8_t value99 = RAM8(0x0000 + sp0 - 1);
                                uint8_t value100 = RAM8(0x0000 + sp0);
                                uint8_t a21;
                                uint8_t a_hi34;
                                if ((((value100 << 8) | value99) & 0x7F00) != 0x7F00) {
                                    uint16_t value101 = RAM16(0x000A + direct_page_f24f2);
                                    a21 = (uint8_t)(((((value100 << 8) | value99) & 0x7F00) >> 3) + value101 + (((((value100 << 8) | value99) & 0x7F00) >> 2) & 1));
                                    a_hi34 = (uint16_t)(((((value100 << 8) | value99) & 0x7F00) >> 3) + value101 + (((((value100 << 8) | value99) & 0x7F00) >> 2) & 1)) >> 8;
                                } else {
                                    a21 = 0;
                                    a_hi34 = 0xCB;
                                }
                                uint8_t x22 = (uint8_t)(x19 - 1);
                                uint8_t y22 = (uint8_t)(y19 + 2);
                                bool negative9 = 0;
                                for (;;) {
                                    BUS16_SET(c, (data_bank_f24f2 << 0x10) + y22, (a_hi34 << 8) | a21);
                                    if ((uint8_t)(x22 - 1) != 0) {
                                        RAM16_SET(0x0002 + direct_page_f24f2, (uint16_t)(RAM16(0x0002 + direct_page_f24f2) - 1));
                                        if (!(RAM16(0x0002 + direct_page_f24f2) & 0x8000)) {
                                            x22 = (uint8_t)(x22 - 1);
                                            y22 = (uint8_t)(y22 + 2);
                                            negative9 = RAM16(0x0002 + direct_page_f24f2) & 0x8000;
                                            continue;
                                        }
                                        x22 = (uint8_t)(x22 - 1);
                                        y22 = (uint8_t)(y22 + 2);
                                        negative9 = RAM16(0x0002 + direct_page_f24f2) & 0x8000;
                                        break;
                                    }
                                    a_hi30 = a_hi34;
                                    x19 = (uint8_t)(x22 - 1);
                                    y19 = (uint8_t)(y22 + 2);
                                    goto leave_loop_C0F282_5;
                                }
                                if (negative9) {
                                    a_hi30 = a_hi34;
                                    x19 = x22;
                                    y19 = y22;
                                    continue;
                                }
                                a_hi36 = a_hi34;
                            }
                            a_hi37 = a_hi36;
                        }
                        a_hi30 = a_hi37;
                        break;
                    }
                    leave_loop_C0F282_5:;
                    a_hi38 = a_hi30;
                }
                a_hi52 = a_hi38;
            } else {
                RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                uint8_t a23;
                uint8_t a_hi39;
                if (((((uint8_t)value79 << 8) | (value79 >> 8)) & 0x7F00) != 0x7F00) {
                    uint16_t value106 = RAM16(0x000A + direct_page_f24f2);
                    a23 = (uint8_t)((((((uint8_t)value79 << 8) | (value79 >> 8)) & 0x7F00) >> 3) + value106 + ((((((uint8_t)value79 << 8) | (value79 >> 8)) & 0x7F00) >> 2) & 1));
                    a_hi39 = (uint16_t)((((((uint8_t)value79 << 8) | (value79 >> 8)) & 0x7F00) >> 3) + value106 + ((((((uint8_t)value79 << 8) | (value79 >> 8)) & 0x7F00) >> 2) & 1)) >> 8;
                } else {
                    a23 = 0;
                    a_hi39 = 0xCB;
                }
                BUS16_SET(c, (data_bank_f24f2 << 0x10) + y16, (a_hi39 << 8) | a23);
                if ((uint8_t)(x16 - 1) != 0) {
                    a_hi27 = a_hi39;
                    x16 = (uint8_t)(x16 - 1);
                    y16 = (uint8_t)(y16 + 2);
                    continue;
                }
                uint8_t a_hi51;
                if ((uint8_t)(x16 - 1) == 0) {
                    a_hi51 = a_hi39;
                } else {
                    RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                    RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                    uint8_t a_hi50;
                    if ((((a_hi39 << 8) | a23) & 0x40) == 0) {
                        RAM8(0x0000 + sp0) = a_hi39;
                        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi39 << 8) | a23);
                        RAM16_SET(0x0002 + direct_page_f24f2, ((a_hi39 << 8) | a23) & 0x3F);
                        uint8_t value108 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value109 = RAM8(0x0000 + sp0);
                        uint8_t a24;
                        uint8_t a_hi40;
                        if ((((value109 << 8) | value108) & 0x7F00) != 0x7F00) {
                            uint16_t value110 = RAM16(0x000A + direct_page_f24f2);
                            a24 = (uint8_t)(((((value109 << 8) | value108) & 0x7F00) >> 3) + value110 + (((((value109 << 8) | value108) & 0x7F00) >> 2) & 1));
                            a_hi40 = (uint16_t)(((((value109 << 8) | value108) & 0x7F00) >> 3) + value110 + (((((value109 << 8) | value108) & 0x7F00) >> 2) & 1)) >> 8;
                        } else {
                            a24 = 0;
                            a_hi40 = 0xCB;
                        }
                        uint8_t x24 = (uint8_t)(x16 - 1);
                        uint8_t y24 = (uint8_t)(y16 + 2);
                        bool negative10 = 0;
                        for (;;) {
                            BUS16_SET(c, (data_bank_f24f2 << 0x10) + y24, (a_hi40 << 8) | a24);
                            if ((uint8_t)(x24 - 1) != 0) {
                                RAM16_SET(0x0002 + direct_page_f24f2, (uint16_t)(RAM16(0x0002 + direct_page_f24f2) - 1));
                                if (!(RAM16(0x0002 + direct_page_f24f2) & 0x8000)) {
                                    x24 = (uint8_t)(x24 - 1);
                                    y24 = (uint8_t)(y24 + 2);
                                    negative10 = RAM16(0x0002 + direct_page_f24f2) & 0x8000;
                                    continue;
                                }
                                x24 = (uint8_t)(x24 - 1);
                                y24 = (uint8_t)(y24 + 2);
                                negative10 = RAM16(0x0002 + direct_page_f24f2) & 0x8000;
                                break;
                            }
                            a_hi27 = a_hi40;
                            x16 = (uint8_t)(x24 - 1);
                            y16 = (uint8_t)(y24 + 2);
                            goto leave_loop_C0F282_4;
                        }
                        if (negative10) {
                            a_hi27 = a_hi40;
                            x16 = x24;
                            y16 = y24;
                            continue;
                        }
                        a_hi50 = a_hi40;
                    } else {
                        RAM8(0x0000 + sp0) = a_hi39;
                        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi39 << 8) | a23);
                        RAM16_SET(0x0002 + direct_page_f24f2, ((a_hi39 << 8) | a23) & 0x3F);
                        uint8_t value112 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value113 = RAM8(0x0000 + sp0);
                        uint16_t value114 = RAM16(0x000A + direct_page_f24f2);
                        uint8_t a25 = (uint8_t)(((((value113 << 8) | value112) & 0x7F00) >> 3) + value114 + (((((value113 << 8) | value112) & 0x7F00) >> 2) & 1));
                        uint8_t a_hi41 = (uint16_t)(((((value113 << 8) | value112) & 0x7F00) >> 3) + value114 + (((((value113 << 8) | value112) & 0x7F00) >> 2) & 1)) >> 8;
                        uint8_t x25 = (uint8_t)(x16 - 1);
                        uint8_t y25 = (uint8_t)(y16 + 2);
                        for (;;) {
                            BUS16_SET(c, (data_bank_f24f2 << 0x10) + y25, (a_hi41 << 8) | a25);
                            if ((uint8_t)(x25 - 1) != 0) {
                                RAM16_SET(0x0002 + direct_page_f24f2, (uint16_t)(RAM16(0x0002 + direct_page_f24f2) - 1));
                                if (RAM16(0x0002 + direct_page_f24f2) & 0x8000) {
                                    x25 = (uint8_t)(x25 - 1);
                                    y25 = (uint8_t)(y25 + 2);
                                    break;
                                }
                                uint8_t a25_next = (uint8_t)(((a_hi41 << 8) | a25) + 0x20);
                                uint8_t a_hi41_next = (uint16_t)(((a_hi41 << 8) | a25) + 0x20) >> 8;
                                uint8_t x25_next = (uint8_t)(x25 - 1);
                                uint8_t y25_next = (uint8_t)(y25 + 2);
                                a25 = a25_next;
                                a_hi41 = a_hi41_next;
                                x25 = x25_next;
                                y25 = y25_next;
                                continue;
                            }
                            a_hi27 = a_hi41;
                            x16 = (uint8_t)(x25 - 1);
                            y16 = (uint8_t)(y25 + 2);
                            goto leave_loop_C0F282_4;
                        }
                        uint8_t a_hi42 = a_hi41;
                        uint8_t x26 = x25;
                        uint8_t y26 = y25;
                        for (;;) {
                            uint16_t value115 = BUS16(c, (RAM8(0x0012 + direct_page_f24f2) << 0x10) + RAM16(0x0010 + direct_page_f24f2));
                            uint8_t a_hi49;
                            if ((value115 & 0x80) != 0) {
                                RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                                RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                                if ((value115 & 0x40) != 0) {
                                    RAM8(0x0000 + sp0) = value115 >> 8;
                                    RAM8(0x0000 + sp0 - 1) = (uint8_t)value115;
                                    RAM16_SET(0x0002 + direct_page_f24f2, value115 & 0x3F);
                                    uint8_t value121 = RAM8(0x0000 + sp0 - 1);
                                    uint8_t value122 = RAM8(0x0000 + sp0);
                                    uint16_t value123 = RAM16(0x000A + direct_page_f24f2);
                                    uint8_t a27 = (uint8_t)(((((value122 << 8) | value121) & 0x7F00) >> 3) + value123 + (((((value122 << 8) | value121) & 0x7F00) >> 2) & 1));
                                    uint8_t a_hi44 = (uint16_t)(((((value122 << 8) | value121) & 0x7F00) >> 3) + value123 + (((((value122 << 8) | value121) & 0x7F00) >> 2) & 1)) >> 8;
                                    uint8_t x28 = x26;
                                    uint8_t y28 = y26;
                                    for (;;) {
                                        BUS16_SET(c, (data_bank_f24f2 << 0x10) + y28, (a_hi44 << 8) | a27);
                                        if ((uint8_t)(x28 - 1) != 0) {
                                            RAM16_SET(0x0002 + direct_page_f24f2, (uint16_t)(RAM16(0x0002 + direct_page_f24f2) - 1));
                                            if (RAM16(0x0002 + direct_page_f24f2) & 0x8000) {
                                                x28 = (uint8_t)(x28 - 1);
                                                y28 = (uint8_t)(y28 + 2);
                                                break;
                                            }
                                            uint8_t a27_next = (uint8_t)(((a_hi44 << 8) | a27) + 0x20);
                                            uint8_t a_hi44_next = (uint16_t)(((a_hi44 << 8) | a27) + 0x20) >> 8;
                                            uint8_t x28_next = (uint8_t)(x28 - 1);
                                            uint8_t y28_next = (uint8_t)(y28 + 2);
                                            a27 = a27_next;
                                            a_hi44 = a_hi44_next;
                                            x28 = x28_next;
                                            y28 = y28_next;
                                            continue;
                                        }
                                        a_hi42 = a_hi44;
                                        x26 = (uint8_t)(x28 - 1);
                                        y26 = (uint8_t)(y28 + 2);
                                        goto leave_loop_C0F282_6;
                                    }
                                    a_hi27 = a_hi44;
                                    x16 = x28;
                                    y16 = y28;
                                    goto next_pass_C0F282_2;
                                }
                                RAM8(0x0000 + sp0) = value115 >> 8;
                                RAM8(0x0000 + sp0 - 1) = (uint8_t)value115;
                                RAM16_SET(0x0002 + direct_page_f24f2, value115 & 0x3F);
                                uint8_t value117 = RAM8(0x0000 + sp0 - 1);
                                uint8_t value118 = RAM8(0x0000 + sp0);
                                uint8_t a26;
                                uint8_t a_hi43;
                                if ((((value118 << 8) | value117) & 0x7F00) != 0x7F00) {
                                    uint16_t value119 = RAM16(0x000A + direct_page_f24f2);
                                    a26 = (uint8_t)(((((value118 << 8) | value117) & 0x7F00) >> 3) + value119 + (((((value118 << 8) | value117) & 0x7F00) >> 2) & 1));
                                    a_hi43 = (uint16_t)(((((value118 << 8) | value117) & 0x7F00) >> 3) + value119 + (((((value118 << 8) | value117) & 0x7F00) >> 2) & 1)) >> 8;
                                } else {
                                    a26 = 0;
                                    a_hi43 = 0xCB;
                                }
                                uint8_t x27 = x26;
                                uint8_t y27 = y26;
                                bool negative11 = 0;
                                for (;;) {
                                    BUS16_SET(c, (data_bank_f24f2 << 0x10) + y27, (a_hi43 << 8) | a26);
                                    if ((uint8_t)(x27 - 1) != 0) {
                                        RAM16_SET(0x0002 + direct_page_f24f2, (uint16_t)(RAM16(0x0002 + direct_page_f24f2) - 1));
                                        if (!(RAM16(0x0002 + direct_page_f24f2) & 0x8000)) {
                                            x27 = (uint8_t)(x27 - 1);
                                            y27 = (uint8_t)(y27 + 2);
                                            negative11 = RAM16(0x0002 + direct_page_f24f2) & 0x8000;
                                            continue;
                                        }
                                        x27 = (uint8_t)(x27 - 1);
                                        y27 = (uint8_t)(y27 + 2);
                                        negative11 = RAM16(0x0002 + direct_page_f24f2) & 0x8000;
                                        break;
                                    }
                                    a_hi42 = a_hi43;
                                    x26 = (uint8_t)(x27 - 1);
                                    y26 = (uint8_t)(y27 + 2);
                                    goto leave_loop_C0F282_6;
                                }
                                if (negative11) {
                                    a_hi42 = a_hi43;
                                    x26 = x27;
                                    y26 = y27;
                                    continue;
                                }
                                a_hi49 = a_hi43;
                            } else {
                                RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                                uint8_t a28;
                                uint8_t a_hi45;
                                if (((((uint8_t)value115 << 8) | (value115 >> 8)) & 0x7F00) != 0x7F00) {
                                    uint16_t value124 = RAM16(0x000A + direct_page_f24f2);
                                    a28 = (uint8_t)((((((uint8_t)value115 << 8) | (value115 >> 8)) & 0x7F00) >> 3) + value124 + ((((((uint8_t)value115 << 8) | (value115 >> 8)) & 0x7F00) >> 2) & 1));
                                    a_hi45 = (uint16_t)((((((uint8_t)value115 << 8) | (value115 >> 8)) & 0x7F00) >> 3) + value124 + ((((((uint8_t)value115 << 8) | (value115 >> 8)) & 0x7F00) >> 2) & 1)) >> 8;
                                } else {
                                    a28 = 0;
                                    a_hi45 = 0xCB;
                                }
                                BUS16_SET(c, (data_bank_f24f2 << 0x10) + y26, (a_hi45 << 8) | a28);
                                if ((uint8_t)(x26 - 1) != 0) {
                                    a_hi42 = a_hi45;
                                    x26 = (uint8_t)(x26 - 1);
                                    y26 = (uint8_t)(y26 + 2);
                                    continue;
                                }
                                uint8_t a_hi48;
                                if ((uint8_t)(x26 - 1) == 0) {
                                    a_hi48 = a_hi45;
                                } else {
                                    RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                                    RAM16_SET(0x0010 + direct_page_f24f2, (uint16_t)(RAM16(0x0010 + direct_page_f24f2) + 1));
                                    if ((((a_hi45 << 8) | a28) & 0x40) != 0) {
                                        RAM8(0x0000 + sp0) = a_hi45;
                                        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi45 << 8) | a28);
                                        RAM16_SET(0x0002 + direct_page_f24f2, ((a_hi45 << 8) | a28) & 0x3F);
                                        uint8_t value130 = RAM8(0x0000 + sp0 - 1);
                                        uint8_t value131 = RAM8(0x0000 + sp0);
                                        uint16_t value132 = RAM16(0x000A + direct_page_f24f2);
                                        uint8_t a30 = (uint8_t)(((((value131 << 8) | value130) & 0x7F00) >> 3) + value132 + (((((value131 << 8) | value130) & 0x7F00) >> 2) & 1));
                                        uint8_t a_hi47 = (uint16_t)(((((value131 << 8) | value130) & 0x7F00) >> 3) + value132 + (((((value131 << 8) | value130) & 0x7F00) >> 2) & 1)) >> 8;
                                        uint8_t x30 = (uint8_t)(x26 - 1);
                                        uint8_t y30 = (uint8_t)(y26 + 2);
                                        for (;;) {
                                            BUS16_SET(c, (data_bank_f24f2 << 0x10) + y30, (a_hi47 << 8) | a30);
                                            if ((uint8_t)(x30 - 1) != 0) {
                                                RAM16_SET(0x0002 + direct_page_f24f2, (uint16_t)(RAM16(0x0002 + direct_page_f24f2) - 1));
                                                if (RAM16(0x0002 + direct_page_f24f2) & 0x8000) {
                                                    x30 = (uint8_t)(x30 - 1);
                                                    y30 = (uint8_t)(y30 + 2);
                                                    break;
                                                }
                                                uint8_t a30_next = (uint8_t)(((a_hi47 << 8) | a30) + 0x20);
                                                uint8_t a_hi47_next = (uint16_t)(((a_hi47 << 8) | a30) + 0x20) >> 8;
                                                uint8_t x30_next = (uint8_t)(x30 - 1);
                                                uint8_t y30_next = (uint8_t)(y30 + 2);
                                                a30 = a30_next;
                                                a_hi47 = a_hi47_next;
                                                x30 = x30_next;
                                                y30 = y30_next;
                                                continue;
                                            }
                                            a_hi42 = a_hi47;
                                            x26 = (uint8_t)(x30 - 1);
                                            y26 = (uint8_t)(y30 + 2);
                                            goto leave_loop_C0F282_6;
                                        }
                                        a_hi27 = a_hi47;
                                        x16 = x30;
                                        y16 = y30;
                                        goto next_pass_C0F282_2;
                                    }
                                    RAM8(0x0000 + sp0) = a_hi45;
                                    RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi45 << 8) | a28);
                                    RAM16_SET(0x0002 + direct_page_f24f2, ((a_hi45 << 8) | a28) & 0x3F);
                                    uint8_t value126 = RAM8(0x0000 + sp0 - 1);
                                    uint8_t value127 = RAM8(0x0000 + sp0);
                                    uint8_t a29;
                                    uint8_t a_hi46;
                                    if ((((value127 << 8) | value126) & 0x7F00) != 0x7F00) {
                                        uint16_t value128 = RAM16(0x000A + direct_page_f24f2);
                                        a29 = (uint8_t)(((((value127 << 8) | value126) & 0x7F00) >> 3) + value128 + (((((value127 << 8) | value126) & 0x7F00) >> 2) & 1));
                                        a_hi46 = (uint16_t)(((((value127 << 8) | value126) & 0x7F00) >> 3) + value128 + (((((value127 << 8) | value126) & 0x7F00) >> 2) & 1)) >> 8;
                                    } else {
                                        a29 = 0;
                                        a_hi46 = 0xCB;
                                    }
                                    uint8_t x29 = (uint8_t)(x26 - 1);
                                    uint8_t y29 = (uint8_t)(y26 + 2);
                                    bool negative12 = 0;
                                    for (;;) {
                                        BUS16_SET(c, (data_bank_f24f2 << 0x10) + y29, (a_hi46 << 8) | a29);
                                        if ((uint8_t)(x29 - 1) != 0) {
                                            RAM16_SET(0x0002 + direct_page_f24f2, (uint16_t)(RAM16(0x0002 + direct_page_f24f2) - 1));
                                            if (!(RAM16(0x0002 + direct_page_f24f2) & 0x8000)) {
                                                x29 = (uint8_t)(x29 - 1);
                                                y29 = (uint8_t)(y29 + 2);
                                                negative12 = RAM16(0x0002 + direct_page_f24f2) & 0x8000;
                                                continue;
                                            }
                                            x29 = (uint8_t)(x29 - 1);
                                            y29 = (uint8_t)(y29 + 2);
                                            negative12 = RAM16(0x0002 + direct_page_f24f2) & 0x8000;
                                            break;
                                        }
                                        a_hi42 = a_hi46;
                                        x26 = (uint8_t)(x29 - 1);
                                        y26 = (uint8_t)(y29 + 2);
                                        goto leave_loop_C0F282_6;
                                    }
                                    if (negative12) {
                                        a_hi42 = a_hi46;
                                        x26 = x29;
                                        y26 = y29;
                                        continue;
                                    }
                                    a_hi48 = a_hi46;
                                }
                                a_hi49 = a_hi48;
                            }
                            a_hi42 = a_hi49;
                            break;
                        }
                        leave_loop_C0F282_6:;
                        a_hi50 = a_hi42;
                    }
                    a_hi51 = a_hi50;
                }
                a_hi52 = a_hi51;
            }
            a_hi27 = a_hi52;
            break;
            next_pass_C0F282_2:;
        }
        leave_loop_C0F282_4:;
        a_hi_f2f92 = a_hi27;
        direct_page_f2f92 = direct_page_f24f2;
        data_bank_f2f92 = data_bank_f24f2;
        goto shared_F2F9_1;
    }
    uint8_t value133 = BUS8(c, (data_bank_f24f2 << 0x10) + 0xE074 + x_f24f2);
    RAM8(0x0003 + direct_page_f24f2) = value133 & 0x7F;
    uint8_t value134 = BUS8(c, (data_bank_f24f2 << 0x10) + 0xE028 + x_f24f2);
    RAM8(0x0002 + direct_page_f24f2) = value134 & 0xC0;
    a_hi_f4092 = a_hi_f24f2;
    y_f4092 = y_f24f2;
    carry_f4092 = (uint8_t)(a_f24f2 << 1) & 0x80;
    overflow_f4092 = overflow_f24f2;
    direct_page_f4092 = direct_page_f24f2;
    data_bank_f4092 = data_bank_f24f2;
    goto shared_F409_1;
    shared_F2F9:;
    uint16_t value135 = RAM16(0x0014 + direct_page_f2f9);
    uint16_t value136 = BUS16(c, (data_bank_f2f9 << 0x10) + 0xE084 + value135);
    RAM16_SET(0x0006 + direct_page_f2f9, value136 & 0x0F);
    uint16_t value137 = BUS16(c, (data_bank_f2f9 << 0x10) + 0xE028 + value135);
    RAM16_SET(0x0002 + direct_page_f2f9, value137 & 0xC0);
    uint16_t value138 = BUS16(c, (data_bank_f2f9 << 0x10) + 0xE086 + value135);
    RAM16_SET(0x000C + direct_page_f2f9, value138);
    uint8_t value139 = BUS8(c, (data_bank_f2f9 << 0x10) + 0xE093 + value135);
    RAM8(0x000D + direct_page_f2f9) = (value139 & 0x30) | RAM8(0x000D + direct_page_f2f9);
    uint8_t value141 = BUS8(c, (data_bank_f2f9 << 0x10) + 0xE074 + value135);
    RAM8(0x0003 + direct_page_f2f9) = value141 & 0x7F;
    uint8_t value142 = BUS8(c, (data_bank_f2f9 << 0x10) + 0xE025 + value135);
    uint8_t a33;
    if (value142 != 0) {
        RAM8(0x0000 + sp0) = value142;
        uint8_t a31;
        if ((value142 & 0x0F) < 8) {
            a31 = value142 & 0x0F;
        } else {
            a31 = (value142 & 0x0F) | 0xF0;
        }
        RAM8(0x000A + direct_page_f2f9) = a31;
        uint8_t value143 = RAM8(0x0000 + sp0);
        uint8_t a32;
        if (value143 >> 4 < 8) {
            a32 = value143 >> 4;
        } else {
            a32 = (value143 >> 4) | 0xF0;
        }
        a33 = a32;
    } else {
        RAM8(0x000A + direct_page_f2f9) = value142;
        a33 = value142;
    }
    a_f344 = a33;
    a_hi_f344 = value138 >> 8;
    x_f344 = value135;
    y_f344 = value136 & 0x0F;
    direct_page_f344 = direct_page_f2f9;
    data_bank_f344 = data_bank_f2f9;
    goto shared_F344;
    shared_F409:;
    uint16_t value144 = RAM16(0x0014 + direct_page_f409);
    uint8_t value145 = BUS8(c, (data_bank_f409 << 0x10) + 0xE060 + value144);
    if (value145 == 0) {
        uint8_t value146 = RAM8(0x0004 + direct_page_f409);
        if (!(value146 & 0x40)) {
            BUS8_SET(c, (data_bank_f409 << 0x10) + 0xE0C2 + value144, 0);
            BUS8_SET(c, (data_bank_f409 << 0x10) + 0xE0C3 + value144, 0);
            r->a = (a_hi_f409 << 8) | 0;
            r->x = value144;
            r->y = y_f409;
            r->c = carry_f409;
            r->v = value146 & 0x40;
            r->mf = true;
            r->xf = false;
            r->db = data_bank_f409;
            r->dp = direct_page_f409;
            RETURN_RTS(c);
        }
        uint8_t a42;
        uint16_t y31;
        bool overflow1;
        if ((value146 & 0x10) == 0) {
            uint8_t value147 = BUS8(c, (RAM8(0x0012 + direct_page_f409) << 0x10) + RAM16(0x0010 + direct_page_f409));
            RAM8(0x0000 + sp0) = value147;
            uint8_t a34;
            if ((value147 & 0x0F) < 8) {
                a34 = value147 & 0x0F;
            } else {
                a34 = (value147 & 0x0F) | 0xF0;
            }
            uint8_t value148 = RAM8(0x0002 + direct_page_f409);
            uint8_t a35;
            if (!(value148 & 0x40)) {
                a35 = (uint8_t)(a34 << 2);
            } else {
                a35 = (uint8_t)(((uint8_t)(a34 << 2) ^ 0xFF) + 1);
            }
            BUS8_SET(c, (data_bank_f409 << 0x10) + 0xE0C0 + value144, a35);
            uint8_t value149 = RAM8(0x0000 + sp0);
            uint8_t a36;
            if (value149 >> 4 < 8) {
                a36 = value149 >> 4;
            } else {
                a36 = (value149 >> 4) | 0xF0;
            }
            uint8_t value150 = RAM8(0x0002 + direct_page_f409);
            uint8_t a37;
            if (!(value150 & 0x80)) {
                a37 = (uint8_t)(a36 << 2);
            } else {
                a37 = (uint8_t)(((uint8_t)(a36 << 2) ^ 0xFF) + 1);
            }
            uint8_t value151 = RAM8(0x0003 + direct_page_f409);
            uint8_t value152 = BUS8(c, (data_bank_f409 << 0x10) + 0xE045 + value144);
            uint8_t a38;
            if ((((uint8_t)(a37 - value151) ^ value152) & ((uint8_t)(a37 - value151) ^ (uint8_t)((uint8_t)(a37 - value151) - value152 - (a37 >= value151 ^ 1))) & 0x80) == 0) {
                a38 = (uint8_t)((uint8_t)(a37 - value151) - value152 - (a37 >= value151 ^ 1));
            } else {
                a38 = 0x80;
            }
            BUS8_SET(c, (data_bank_f409 << 0x10) + 0xE0C1 + value144, a38);
            uint8_t value153 = BUS8(c, (RAM8(0x0012 + direct_page_f409) << 0x10) + RAM16(0x0010 + direct_page_f409) + 1);
            a42 = value153;
            y31 = 1;
            overflow1 = (((uint8_t)(a37 - value151) ^ value152) & ((uint8_t)(a37 - value151) ^ (uint8_t)((uint8_t)(a37 - value151) - value152 - (a37 >= value151 ^ 1))) & 0x80) != 0;
        } else {
            uint8_t value154 = BUS8(c, (RAM8(0x0012 + direct_page_f409) << 0x10) + RAM16(0x0010 + direct_page_f409));
            uint8_t value155 = RAM8(0x0002 + direct_page_f409);
            uint8_t a39;
            if (!(value155 & 0x80)) {
                a39 = value154;
            } else {
                a39 = (uint8_t)((value154 ^ 0xFF) + 1);
            }
            uint8_t value156 = RAM8(0x0003 + direct_page_f409);
            uint8_t value157 = BUS8(c, (data_bank_f409 << 0x10) + 0xE045 + value144);
            uint8_t a40;
            if ((((uint8_t)(a39 - value156) ^ value157) & ((uint8_t)(a39 - value156) ^ (uint8_t)((uint8_t)(a39 - value156) - value157 - (a39 >= value156 ^ 1))) & 0x80) == 0) {
                a40 = (uint8_t)((uint8_t)(a39 - value156) - value157 - (a39 >= value156 ^ 1));
            } else {
                a40 = 0x80;
            }
            BUS8_SET(c, (data_bank_f409 << 0x10) + 0xE0C1 + value144, a40);
            uint8_t value158 = BUS8(c, (RAM8(0x0012 + direct_page_f409) << 0x10) + RAM16(0x0010 + direct_page_f409) + 1);
            uint8_t value159 = RAM8(0x0002 + direct_page_f409);
            uint8_t a41;
            if (!(value159 & 0x40)) {
                a41 = value158;
            } else {
                a41 = (uint8_t)((value158 ^ 0xFF) + 1);
            }
            BUS8_SET(c, (data_bank_f409 << 0x10) + 0xE0C0 + value144, a41);
            uint8_t value160 = BUS8(c, (RAM8(0x0012 + direct_page_f409) << 0x10) + RAM16(0x0010 + direct_page_f409) + 2);
            a42 = value160;
            y31 = 2;
            overflow1 = value159 & 0x40;
        }
        RAM8(0x0000 + sp0) = a42;
        BUS8_SET(c, (data_bank_f409 << 0x10) + 0xE0C2 + value144, (a42 & 0x0F) << 1 << 1);
        uint8_t value161 = RAM8(0x0000 + sp0);
        BUS8_SET(c, (data_bank_f409 << 0x10) + 0xE0C3 + value144, (value161 >> 2) & 0x3C);
        r->a = a_hi_f409 << 8 | ((value161 >> 2) & 0x3C);
        r->x = value144;
        r->y = y31;
        r->c = value161 >> 1 & 0x01;
        r->v = overflow1;
        r->mf = true;
        r->xf = false;
        r->db = data_bank_f409;
        r->dp = direct_page_f409;
        RETURN_RTS(c);
    }
    bool x_flag2;
    uint8_t a_hi54;
    uint16_t x32;
    uint16_t y33;
    bool carry3;
    bool overflow3;
    if (value145 != 0xC0) {
        x_flag2 = 0;
        a_hi54 = a_hi_f409;
        x32 = value144;
        y33 = y_f409;
        carry3 = value145 >= 0xC0;
        overflow3 = overflow_f409;
    } else {
        BUS8_SET(c, (data_bank_f409 << 0x10) + 0xE114 + value144, 0);
        uint8_t value162 = RAM8(0x0005 + direct_page_f409);
        bool x_flag;
        uint8_t a_hi53;
        uint16_t x31;
        uint16_t y32;
        bool carry2;
        bool overflow2;
        if (!(value162 & 0x80)) {
            x_flag = 0;
            a_hi53 = a_hi_f409;
            x31 = value144;
            y32 = y_f409;
            carry2 = value145 >= 0xC0;
            overflow2 = value162 & 0x40;
        } else {
            r->a = (a_hi_f409 << 8) | value145;
            r->y = y_f409;
            r->v = value162 & 0x40;
            r->mf = true;
            r->xf = false;
            r->db = data_bank_f409;
            r->dp = direct_page_f409;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF420, 0xC2A480); GUARD_JSL(c, sp_call, 0xF420); } /* initialize_native_actor_point_or_trail_effect_from_frame */
            bool x_ret3 = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t x_ret4 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            x_flag = x_ret3;
            a_hi53 = a_all2 >> 8;
            x31 = x_ret4;
            y32 = y_ret2;
            carry2 = carry_ret2;
            overflow2 = overflow_ret2;
        }
        x_flag2 = x_flag;
        a_hi54 = a_hi53;
        x32 = x31;
        y33 = y32;
        carry3 = carry2;
        overflow3 = overflow2;
    }
    BUS8_SET(c, (data_bank_f409 << 0x10) + 0xE0C2 + x32, 0);
    BUS8_SET(c, (data_bank_f409 << 0x10) + 0xE0C3 + x32, 0);
    r->a = (a_hi54 << 8) | 0;
    r->x = x32;
    r->y = y33;
    r->c = carry3;
    r->v = overflow3;
    r->mf = true;
    r->xf = x_flag2;
    r->db = data_bank_f409;
    r->dp = direct_page_f409;
    RETURN_RTS(c);
    shared_F2F9_1:;
    uint16_t value163 = RAM16(0x0014 + direct_page_f2f92);
    uint16_t value164 = BUS16(c, (data_bank_f2f92 << 0x10) + 0xE084 + value163);
    RAM16_SET(0x0006 + direct_page_f2f92, value164 & 0x0F);
    uint16_t value165 = BUS16(c, (data_bank_f2f92 << 0x10) + 0xE028 + value163);
    RAM16_SET(0x0002 + direct_page_f2f92, value165 & 0xC0);
    uint16_t value166 = BUS16(c, (data_bank_f2f92 << 0x10) + 0xE086 + value163);
    RAM16_SET(0x000C + direct_page_f2f92, value166);
    uint8_t value167 = BUS8(c, (data_bank_f2f92 << 0x10) + 0xE093 + value163);
    RAM8(0x000D + direct_page_f2f92) = (value167 & 0x30) | RAM8(0x000D + direct_page_f2f92);
    uint8_t value169 = BUS8(c, (data_bank_f2f92 << 0x10) + 0xE074 + value163);
    RAM8(0x0003 + direct_page_f2f92) = value169 & 0x7F;
    uint8_t value170 = BUS8(c, (data_bank_f2f92 << 0x10) + 0xE025 + value163);
    uint8_t a45;
    if (value170 != 0) {
        RAM8(0x0000 + sp0) = value170;
        uint8_t a43;
        if ((value170 & 0x0F) < 8) {
            a43 = value170 & 0x0F;
        } else {
            a43 = (value170 & 0x0F) | 0xF0;
        }
        RAM8(0x000A + direct_page_f2f92) = a43;
        uint8_t value171 = RAM8(0x0000 + sp0);
        uint8_t a44;
        if (value171 >> 4 < 8) {
            a44 = value171 >> 4;
        } else {
            a44 = (value171 >> 4) | 0xF0;
        }
        a45 = a44;
    } else {
        RAM8(0x000A + direct_page_f2f92) = value170;
        a45 = value170;
    }
    a_f344 = a45;
    a_hi_f344 = value166 >> 8;
    x_f344 = value163;
    y_f344 = value164 & 0x0F;
    direct_page_f344 = direct_page_f2f92;
    data_bank_f344 = data_bank_f2f92;
    goto shared_F344;
    shared_F409_1:;
    uint8_t value172 = RAM8(0x0014 + direct_page_f4092);
    uint8_t value173 = BUS8(c, (data_bank_f4092 << 0x10) + 0xE060 + value172);
    if (value173 == 0) {
        uint8_t value174 = RAM8(0x0004 + direct_page_f4092);
        if (!(value174 & 0x40)) {
            BUS8_SET(c, (data_bank_f4092 << 0x10) + 0xE0C2 + value172, 0);
            BUS8_SET(c, (data_bank_f4092 << 0x10) + 0xE0C3 + value172, 0);
            r->a = (a_hi_f4092 << 8) | 0;
            r->x = value172;
            r->y = y_f4092;
            r->c = carry_f4092;
            r->v = value174 & 0x40;
            r->mf = true;
            r->xf = true;
            r->db = data_bank_f4092;
            r->dp = direct_page_f4092;
            RETURN_RTS(c);
        }
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    }
    bool x_flag4;
    uint8_t a_hi56;
    uint16_t x34;
    uint16_t y35;
    bool carry5;
    bool overflow5;
    if (value173 != 0xC0) {
        x_flag4 = 1;
        a_hi56 = a_hi_f4092;
        x34 = value172;
        y35 = y_f4092;
        carry5 = value173 >= 0xC0;
        overflow5 = overflow_f4092;
    } else {
        BUS8_SET(c, (data_bank_f4092 << 0x10) + 0xE114 + value172, 0);
        uint8_t value175 = RAM8(0x0005 + direct_page_f4092);
        bool x_flag3;
        uint8_t a_hi55;
        uint16_t x33;
        uint16_t y34;
        bool carry4;
        bool overflow4;
        if (!(value175 & 0x80)) {
            x_flag3 = 1;
            a_hi55 = a_hi_f4092;
            x33 = value172;
            y34 = y_f4092;
            carry4 = value173 >= 0xC0;
            overflow4 = value175 & 0x40;
        } else {
            r->a = (a_hi_f4092 << 8) | value173;
            r->y = y_f4092;
            r->v = value175 & 0x40;
            r->mf = true;
            r->xf = true;
            r->db = data_bank_f4092;
            r->dp = direct_page_f4092;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF420, 0xC2A480); GUARD_JSL(c, sp_call, 0xF420); } /* initialize_native_actor_point_or_trail_effect_from_frame */
            bool x_ret5 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t x_ret6 = r->x;
            uint16_t y_ret3 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            x_flag3 = x_ret5;
            a_hi55 = a_all3 >> 8;
            x33 = x_ret6;
            y34 = y_ret3;
            carry4 = carry_ret3;
            overflow4 = overflow_ret3;
        }
        x_flag4 = x_flag3;
        a_hi56 = a_hi55;
        x34 = x33;
        y35 = y34;
        carry5 = carry4;
        overflow5 = overflow4;
    }
    BUS8_SET(c, (data_bank_f4092 << 0x10) + 0xE0C2 + x34, 0);
    BUS8_SET(c, (data_bank_f4092 << 0x10) + 0xE0C3 + x34, 0);
    r->a = (a_hi56 << 8) | 0;
    r->x = x34;
    r->y = y35;
    r->c = carry5;
    r->v = overflow5;
    r->mf = true;
    r->xf = x_flag4;
    r->db = data_bank_f4092;
    r->dp = direct_page_f4092;
    RETURN_RTS(c);
    shared_F344:;
    RAM8(0x000B + direct_page_f344) = a_f344;
    uint8_t value176 = BUS8(c, (data_bank_f344 << 0x10) + 0xE060 + x_f344);
    if (value176 == 0) {
        uint8_t a_hi57 = a_hi_f344;
        uint16_t x35 = x_f344;
        uint16_t y36 = y_f344;
        bool carry6 = 0;
        bool overflow6 = 0;
        for (;;) {
            uint16_t value177 = BUS16(c, (RAM8(0x0012 + direct_page_f344) << 0x10) + RAM16(0x0010 + direct_page_f344));
            RAM16_SET(0x0010 + direct_page_f344, (uint16_t)(RAM16(0x0010 + direct_page_f344) + 1));
            RAM16_SET(0x0010 + direct_page_f344, (uint16_t)(RAM16(0x0010 + direct_page_f344) + 1));
            RAM8(0x0001 + direct_page_f344) = (RAM8(0x0001 + direct_page_f344) >> 1) | (value177 >> 0x0F << 7);
            RAM8(0x0001 + direct_page_f344) = (RAM8(0x0001 + direct_page_f344) >> 1) | ((uint8_t)value177 >> 7 << 7);
            uint8_t a53;
            if ((uint8_t)((uint8_t)value177 << 1) < 0x80) {
                uint8_t value180 = RAM8(0x0005 + direct_page_f344);
                uint8_t a46;
                if (value180 & 0x40) {
                    a46 = (uint8_t)((uint8_t)value177 << 1);
                } else {
                    a46 = (uint8_t)((uint8_t)value177 << 1) >> 1;
                }
                uint8_t value181 = RAM8(0x000B + direct_page_f344);
                uint8_t value182 = RAM8(0x0002 + direct_page_f344);
                uint8_t a47;
                if (!(value182 & 0x80)) {
                    a47 = (uint8_t)(a46 + value181);
                } else {
                    a47 = (uint8_t)((uint8_t)(a46 + value181) + 0x0F) ^ 0xFF;
                }
                a53 = a47;
            } else {
                uint8_t value183 = RAM8(0x0005 + direct_page_f344);
                uint8_t a48;
                if (value183 & 0x40) {
                    a48 = (uint8_t)((uint8_t)value177 << 1);
                } else {
                    a48 = ((uint8_t)((uint8_t)value177 << 1) >> 1) | (((uint8_t)((uint8_t)value177 << 1) >= 0x80) << 7);
                }
                uint8_t value184 = RAM8(0x000B + direct_page_f344);
                uint8_t value185 = RAM8(0x0002 + direct_page_f344);
                uint8_t a52;
                if (value185 & 0x80) {
                    a52 = (uint8_t)((uint8_t)(a48 + value184) + 0x0F) ^ 0xFF;
                } else {
                    uint8_t a51;
                    if (!(value185 & 0x80)) {
                        a51 = (uint8_t)(a48 + value184);
                    } else {
                        uint8_t a49;
                        if (value183 & 0x40) {
                            a49 = (uint8_t)(a48 + value184);
                        } else {
                            a49 = (uint8_t)(a48 + value184) >> 1;
                        }
                        uint8_t a50;
                        if (!(value185 & 0x80)) {
                            a50 = (uint8_t)(a49 + value184);
                        } else {
                            a50 = (uint8_t)((uint8_t)(a49 + value184) + 0x0F) ^ 0xFF;
                        }
                        a51 = a50;
                    }
                    a52 = a51;
                }
                a53 = a52;
            }
            uint8_t a61;
            if (!((uint8_t)(value177 >> 8 << 1) & 0x80)) {
                uint8_t value186 = RAM8(0x0005 + direct_page_f344);
                uint8_t a54;
                if (value186 & 0x40) {
                    a54 = (uint8_t)(value177 >> 8 << 1);
                } else {
                    a54 = (uint8_t)(value177 >> 8 << 1) >> 1;
                }
                uint8_t value187 = RAM8(0x000A + direct_page_f344);
                uint8_t value188 = RAM8(0x0002 + direct_page_f344);
                uint8_t a55;
                if (!(value188 & 0x40)) {
                    a55 = (uint8_t)(a54 + value187);
                } else {
                    a55 = (uint8_t)((uint8_t)(a54 + value187) + 0x0F) ^ 0xFF;
                }
                a61 = a55;
            } else {
                uint8_t value189 = RAM8(0x0005 + direct_page_f344);
                uint8_t a56;
                if (value189 & 0x40) {
                    a56 = (uint8_t)(value177 >> 8 << 1);
                } else {
                    a56 = ((uint8_t)(value177 >> 8 << 1) >> 1) | 0x80;
                }
                uint8_t value190 = RAM8(0x000A + direct_page_f344);
                uint8_t value191 = RAM8(0x0002 + direct_page_f344);
                uint8_t a60;
                if (value191 & 0x40) {
                    a60 = (uint8_t)((uint8_t)(a56 + value190) + 0x0F) ^ 0xFF;
                } else {
                    uint8_t a59;
                    if (!(value191 & 0x40)) {
                        a59 = (uint8_t)(a56 + value190);
                    } else {
                        uint8_t a57;
                        if (value189 & 0x40) {
                            a57 = (uint8_t)(a56 + value190);
                        } else {
                            a57 = (uint8_t)(a56 + value190) >> 1;
                        }
                        uint8_t a58;
                        if (!(value191 & 0x40)) {
                            a58 = (uint8_t)(a57 + value190);
                        } else {
                            a58 = (uint8_t)((uint8_t)(a57 + value190) + 0x0F) ^ 0xFF;
                        }
                        a59 = a58;
                    }
                    a60 = a59;
                }
                a61 = a60;
            }
            BUS16_SET(c, (data_bank_f344 << 0x10) + 0xE0D0 + x35, (a53 << 8) | a61);
            BUS8_SET(c, (data_bank_f344 << 0x10) + 0xE0D3 + x35, ((RAM8(0x0001 + direct_page_f344) ^ RAM8(0x0002 + direct_page_f344)) & 0xC0) | RAM8(0x000D + direct_page_f344));
            uint8_t value195 = RAM8(0x000C + direct_page_f344);
            BUS8_SET(c, (data_bank_f344 << 0x10) + 0xE0D2 + x35, value195);
            uint8_t a62;
            bool carry7;
            bool overflow7;
            if (((uint8_t)(value195 + 2) & 0x10) == 0) {
                a62 = (uint8_t)(value195 + 2);
                carry7 = value195 + 2 > 0xFF;
                overflow7 = ((value195 ^ (uint8_t)(value195 + 2)) & ((uint8_t)(value195 + 2) ^ 2) & 0x80) != 0;
            } else {
                if ((uint8_t)(value195 + 2) + 0x10 + (value195 + 2 > 0xFF) > 0xFF) {
                    RAM8(0x000D + direct_page_f344)++;
                }
                a62 = (uint8_t)((uint8_t)(value195 + 2) + 0x10 + (value195 + 2 > 0xFF));
                carry7 = (uint8_t)(value195 + 2) + 0x10 + (value195 + 2 > 0xFF) > 0xFF;
                overflow7 = (((uint8_t)(value195 + 2) ^ (uint8_t)((uint8_t)(value195 + 2) + 0x10 + (value195 + 2 > 0xFF))) & ((uint8_t)((uint8_t)(value195 + 2) + 0x10 + (value195 + 2 > 0xFF)) ^ 0x10) & 0x80) != 0;
            }
            RAM8(0x000C + direct_page_f344) = a62;
            if ((uint16_t)(y36 - 1) != 0) {
                a_hi57 = a53;
                x35 = (uint16_t)(x35 + 4);
                y36 = (uint16_t)(y36 - 1);
                carry6 = carry7;
                overflow6 = overflow7;
                continue;
            }
            a_hi57 = a53;
            x35 = (uint16_t)(x35 + 4);
            y36 = (uint16_t)(y36 - 1);
            carry6 = carry7;
            overflow6 = overflow7;
            break;
        }
        a_hi_f409 = a_hi57;
        y_f409 = y36;
        carry_f409 = carry6;
        overflow_f409 = overflow6;
        direct_page_f409 = direct_page_f344;
        data_bank_f409 = data_bank_f344;
        goto shared_F409;
    }
    RAM8(0x0000 + sp0) = value176;
    RAM8(0x000D + direct_page_f344) |= 0x30;
    uint8_t value197 = RAM8(0x0000 + sp0);
    if (value197 != 0xE0) {
        if (value197 != 0xC0) {
            uint8_t a_hi58 = a_hi_f344;
            uint16_t x36 = x_f344;
            uint16_t y37 = y_f344;
            bool carry8 = value197 >= 0xC0;
            bool overflow8 = 0;
            for (;;) {
                uint16_t value198 = BUS16(c, (RAM8(0x0012 + direct_page_f344) << 0x10) + RAM16(0x0010 + direct_page_f344));
                RAM16_SET(0x0010 + direct_page_f344, (uint16_t)(RAM16(0x0010 + direct_page_f344) + 1));
                RAM16_SET(0x0010 + direct_page_f344, (uint16_t)(RAM16(0x0010 + direct_page_f344) + 1));
                RAM8(0x0001 + direct_page_f344) = (RAM8(0x0001 + direct_page_f344) >> 1) | (value198 >> 0x0F << 7);
                RAM8(0x0001 + direct_page_f344) = (RAM8(0x0001 + direct_page_f344) >> 1) | ((uint8_t)value198 >> 7 << 7);
                uint8_t a70;
                if ((uint8_t)((uint8_t)value198 << 1) < 0x80) {
                    uint8_t value201 = RAM8(0x0005 + direct_page_f344);
                    uint8_t a63;
                    if (value201 & 0x40) {
                        a63 = (uint8_t)((uint8_t)value198 << 1);
                    } else {
                        a63 = (uint8_t)((uint8_t)value198 << 1) >> 1;
                    }
                    uint8_t value202 = RAM8(0x000B + direct_page_f344);
                    uint8_t value203 = RAM8(0x0002 + direct_page_f344);
                    uint8_t a64;
                    if (!(value203 & 0x80)) {
                        a64 = (uint8_t)(a63 + value202);
                    } else {
                        a64 = (uint8_t)((uint8_t)(a63 + value202) + 0x0F) ^ 0xFF;
                    }
                    a70 = a64;
                } else {
                    uint8_t value204 = RAM8(0x0005 + direct_page_f344);
                    uint8_t a65;
                    if (value204 & 0x40) {
                        a65 = (uint8_t)((uint8_t)value198 << 1);
                    } else {
                        a65 = ((uint8_t)((uint8_t)value198 << 1) >> 1) | (((uint8_t)((uint8_t)value198 << 1) >= 0x80) << 7);
                    }
                    uint8_t value205 = RAM8(0x000B + direct_page_f344);
                    uint8_t value206 = RAM8(0x0002 + direct_page_f344);
                    uint8_t a69;
                    if (value206 & 0x80) {
                        a69 = (uint8_t)((uint8_t)(a65 + value205) + 0x0F) ^ 0xFF;
                    } else {
                        uint8_t a68;
                        if (!(value206 & 0x80)) {
                            a68 = (uint8_t)(a65 + value205);
                        } else {
                            uint8_t a66;
                            if (value204 & 0x40) {
                                a66 = (uint8_t)(a65 + value205);
                            } else {
                                a66 = (uint8_t)(a65 + value205) >> 1;
                            }
                            uint8_t a67;
                            if (!(value206 & 0x80)) {
                                a67 = (uint8_t)(a66 + value205);
                            } else {
                                a67 = (uint8_t)((uint8_t)(a66 + value205) + 0x0F) ^ 0xFF;
                            }
                            a68 = a67;
                        }
                        a69 = a68;
                    }
                    a70 = a69;
                }
                uint8_t a78;
                if (!((uint8_t)(value198 >> 8 << 1) & 0x80)) {
                    uint8_t value207 = RAM8(0x0005 + direct_page_f344);
                    uint8_t a71;
                    if (value207 & 0x40) {
                        a71 = (uint8_t)(value198 >> 8 << 1);
                    } else {
                        a71 = (uint8_t)(value198 >> 8 << 1) >> 1;
                    }
                    uint8_t value208 = RAM8(0x000A + direct_page_f344);
                    uint8_t value209 = RAM8(0x0002 + direct_page_f344);
                    uint8_t a72;
                    if (!(value209 & 0x40)) {
                        a72 = (uint8_t)(a71 + value208);
                    } else {
                        a72 = (uint8_t)((uint8_t)(a71 + value208) + 0x0F) ^ 0xFF;
                    }
                    a78 = a72;
                } else {
                    uint8_t value210 = RAM8(0x0005 + direct_page_f344);
                    uint8_t a73;
                    if (value210 & 0x40) {
                        a73 = (uint8_t)(value198 >> 8 << 1);
                    } else {
                        a73 = ((uint8_t)(value198 >> 8 << 1) >> 1) | 0x80;
                    }
                    uint8_t value211 = RAM8(0x000A + direct_page_f344);
                    uint8_t value212 = RAM8(0x0002 + direct_page_f344);
                    uint8_t a77;
                    if (value212 & 0x40) {
                        a77 = (uint8_t)((uint8_t)(a73 + value211) + 0x0F) ^ 0xFF;
                    } else {
                        uint8_t a76;
                        if (!(value212 & 0x40)) {
                            a76 = (uint8_t)(a73 + value211);
                        } else {
                            uint8_t a74;
                            if (value210 & 0x40) {
                                a74 = (uint8_t)(a73 + value211);
                            } else {
                                a74 = (uint8_t)(a73 + value211) >> 1;
                            }
                            uint8_t a75;
                            if (!(value212 & 0x40)) {
                                a75 = (uint8_t)(a74 + value211);
                            } else {
                                a75 = (uint8_t)((uint8_t)(a74 + value211) + 0x0F) ^ 0xFF;
                            }
                            a76 = a75;
                        }
                        a77 = a76;
                    }
                    a78 = a77;
                }
                BUS16_SET(c, (data_bank_f344 << 0x10) + 0xE0D0 + x36, (a70 << 8) | a78);
                BUS8_SET(c, (data_bank_f344 << 0x10) + 0xE0D3 + x36, ((RAM8(0x0001 + direct_page_f344) ^ RAM8(0x0002 + direct_page_f344)) & 0xC0) | RAM8(0x000D + direct_page_f344));
                uint8_t value216 = RAM8(0x000C + direct_page_f344);
                BUS8_SET(c, (data_bank_f344 << 0x10) + 0xE0D2 + x36, value216);
                uint8_t a79;
                bool carry9;
                bool overflow9;
                if (((uint8_t)(value216 + 2) & 0x10) == 0) {
                    a79 = (uint8_t)(value216 + 2);
                    carry9 = value216 + 2 > 0xFF;
                    overflow9 = ((value216 ^ (uint8_t)(value216 + 2)) & ((uint8_t)(value216 + 2) ^ 2) & 0x80) != 0;
                } else {
                    if ((uint8_t)(value216 + 2) + 0x10 + (value216 + 2 > 0xFF) > 0xFF) {
                        RAM8(0x000D + direct_page_f344)++;
                    }
                    a79 = (uint8_t)((uint8_t)(value216 + 2) + 0x10 + (value216 + 2 > 0xFF));
                    carry9 = (uint8_t)(value216 + 2) + 0x10 + (value216 + 2 > 0xFF) > 0xFF;
                    overflow9 = (((uint8_t)(value216 + 2) ^ (uint8_t)((uint8_t)(value216 + 2) + 0x10 + (value216 + 2 > 0xFF))) & ((uint8_t)((uint8_t)(value216 + 2) + 0x10 + (value216 + 2 > 0xFF)) ^ 0x10) & 0x80) != 0;
                }
                RAM8(0x000C + direct_page_f344) = a79;
                if ((uint16_t)(y37 - 1) != 0) {
                    a_hi58 = a70;
                    x36 = (uint16_t)(x36 + 4);
                    y37 = (uint16_t)(y37 - 1);
                    carry8 = carry9;
                    overflow8 = overflow9;
                    continue;
                }
                a_hi58 = a70;
                x36 = (uint16_t)(x36 + 4);
                y37 = (uint16_t)(y37 - 1);
                carry8 = carry9;
                overflow8 = overflow9;
                break;
            }
            a_hi_f409 = a_hi58;
            y_f409 = y37;
            carry_f409 = carry8;
            overflow_f409 = overflow8;
            direct_page_f409 = direct_page_f344;
            data_bank_f409 = data_bank_f344;
            goto shared_F409;
        }
        uint8_t value217 = RAM8(0x0005 + direct_page_f344);
        if (!(value217 & 0x80)) {
            uint8_t a_hi59 = a_hi_f344;
            uint16_t x37 = x_f344;
            uint16_t y38 = y_f344;
            bool carry10 = value197 >= 0xC0;
            bool overflow10 = value217 & 0x40;
            for (;;) {
                uint16_t value218 = BUS16(c, (RAM8(0x0012 + direct_page_f344) << 0x10) + RAM16(0x0010 + direct_page_f344));
                RAM16_SET(0x0010 + direct_page_f344, (uint16_t)(RAM16(0x0010 + direct_page_f344) + 1));
                RAM16_SET(0x0010 + direct_page_f344, (uint16_t)(RAM16(0x0010 + direct_page_f344) + 1));
                RAM8(0x0001 + direct_page_f344) = (RAM8(0x0001 + direct_page_f344) >> 1) | (value218 >> 0x0F << 7);
                RAM8(0x0001 + direct_page_f344) = (RAM8(0x0001 + direct_page_f344) >> 1) | ((uint8_t)value218 >> 7 << 7);
                uint8_t a87;
                if ((uint8_t)((uint8_t)value218 << 1) < 0x80) {
                    uint8_t value221 = RAM8(0x0005 + direct_page_f344);
                    uint8_t a80;
                    if (value221 & 0x40) {
                        a80 = (uint8_t)((uint8_t)value218 << 1);
                    } else {
                        a80 = (uint8_t)((uint8_t)value218 << 1) >> 1;
                    }
                    uint8_t value222 = RAM8(0x000B + direct_page_f344);
                    uint8_t value223 = RAM8(0x0002 + direct_page_f344);
                    uint8_t a81;
                    if (!(value223 & 0x80)) {
                        a81 = (uint8_t)(a80 + value222);
                    } else {
                        a81 = (uint8_t)((uint8_t)(a80 + value222) + 0x0F) ^ 0xFF;
                    }
                    a87 = a81;
                } else {
                    uint8_t value224 = RAM8(0x0005 + direct_page_f344);
                    uint8_t a82;
                    if (value224 & 0x40) {
                        a82 = (uint8_t)((uint8_t)value218 << 1);
                    } else {
                        a82 = ((uint8_t)((uint8_t)value218 << 1) >> 1) | (((uint8_t)((uint8_t)value218 << 1) >= 0x80) << 7);
                    }
                    uint8_t value225 = RAM8(0x000B + direct_page_f344);
                    uint8_t value226 = RAM8(0x0002 + direct_page_f344);
                    uint8_t a86;
                    if (value226 & 0x80) {
                        a86 = (uint8_t)((uint8_t)(a82 + value225) + 0x0F) ^ 0xFF;
                    } else {
                        uint8_t a85;
                        if (!(value226 & 0x80)) {
                            a85 = (uint8_t)(a82 + value225);
                        } else {
                            uint8_t a83;
                            if (value224 & 0x40) {
                                a83 = (uint8_t)(a82 + value225);
                            } else {
                                a83 = (uint8_t)(a82 + value225) >> 1;
                            }
                            uint8_t a84;
                            if (!(value226 & 0x80)) {
                                a84 = (uint8_t)(a83 + value225);
                            } else {
                                a84 = (uint8_t)((uint8_t)(a83 + value225) + 0x0F) ^ 0xFF;
                            }
                            a85 = a84;
                        }
                        a86 = a85;
                    }
                    a87 = a86;
                }
                uint8_t a95;
                if (!((uint8_t)(value218 >> 8 << 1) & 0x80)) {
                    uint8_t value227 = RAM8(0x0005 + direct_page_f344);
                    uint8_t a88;
                    if (value227 & 0x40) {
                        a88 = (uint8_t)(value218 >> 8 << 1);
                    } else {
                        a88 = (uint8_t)(value218 >> 8 << 1) >> 1;
                    }
                    uint8_t value228 = RAM8(0x000A + direct_page_f344);
                    uint8_t value229 = RAM8(0x0002 + direct_page_f344);
                    uint8_t a89;
                    if (!(value229 & 0x40)) {
                        a89 = (uint8_t)(a88 + value228);
                    } else {
                        a89 = (uint8_t)((uint8_t)(a88 + value228) + 0x0F) ^ 0xFF;
                    }
                    a95 = a89;
                } else {
                    uint8_t value230 = RAM8(0x0005 + direct_page_f344);
                    uint8_t a90;
                    if (value230 & 0x40) {
                        a90 = (uint8_t)(value218 >> 8 << 1);
                    } else {
                        a90 = ((uint8_t)(value218 >> 8 << 1) >> 1) | 0x80;
                    }
                    uint8_t value231 = RAM8(0x000A + direct_page_f344);
                    uint8_t value232 = RAM8(0x0002 + direct_page_f344);
                    uint8_t a94;
                    if (value232 & 0x40) {
                        a94 = (uint8_t)((uint8_t)(a90 + value231) + 0x0F) ^ 0xFF;
                    } else {
                        uint8_t a93;
                        if (!(value232 & 0x40)) {
                            a93 = (uint8_t)(a90 + value231);
                        } else {
                            uint8_t a91;
                            if (value230 & 0x40) {
                                a91 = (uint8_t)(a90 + value231);
                            } else {
                                a91 = (uint8_t)(a90 + value231) >> 1;
                            }
                            uint8_t a92;
                            if (!(value232 & 0x40)) {
                                a92 = (uint8_t)(a91 + value231);
                            } else {
                                a92 = (uint8_t)((uint8_t)(a91 + value231) + 0x0F) ^ 0xFF;
                            }
                            a93 = a92;
                        }
                        a94 = a93;
                    }
                    a95 = a94;
                }
                BUS16_SET(c, (data_bank_f344 << 0x10) + 0xE0D0 + x37, (a87 << 8) | a95);
                BUS8_SET(c, (data_bank_f344 << 0x10) + 0xE0D3 + x37, ((RAM8(0x0001 + direct_page_f344) ^ RAM8(0x0002 + direct_page_f344)) & 0xC0) | RAM8(0x000D + direct_page_f344));
                uint8_t value236 = RAM8(0x000C + direct_page_f344);
                BUS8_SET(c, (data_bank_f344 << 0x10) + 0xE0D2 + x37, value236);
                uint8_t a96;
                bool carry11;
                bool overflow11;
                if (((uint8_t)(value236 + 2) & 0x10) == 0) {
                    a96 = (uint8_t)(value236 + 2);
                    carry11 = value236 + 2 > 0xFF;
                    overflow11 = ((value236 ^ (uint8_t)(value236 + 2)) & ((uint8_t)(value236 + 2) ^ 2) & 0x80) != 0;
                } else {
                    if ((uint8_t)(value236 + 2) + 0x10 + (value236 + 2 > 0xFF) > 0xFF) {
                        RAM8(0x000D + direct_page_f344)++;
                    }
                    a96 = (uint8_t)((uint8_t)(value236 + 2) + 0x10 + (value236 + 2 > 0xFF));
                    carry11 = (uint8_t)(value236 + 2) + 0x10 + (value236 + 2 > 0xFF) > 0xFF;
                    overflow11 = (((uint8_t)(value236 + 2) ^ (uint8_t)((uint8_t)(value236 + 2) + 0x10 + (value236 + 2 > 0xFF))) & ((uint8_t)((uint8_t)(value236 + 2) + 0x10 + (value236 + 2 > 0xFF)) ^ 0x10) & 0x80) != 0;
                }
                RAM8(0x000C + direct_page_f344) = a96;
                if ((uint16_t)(y38 - 1) != 0) {
                    a_hi59 = a87;
                    x37 = (uint16_t)(x37 + 4);
                    y38 = (uint16_t)(y38 - 1);
                    carry10 = carry11;
                    overflow10 = overflow11;
                    continue;
                }
                a_hi59 = a87;
                x37 = (uint16_t)(x37 + 4);
                y38 = (uint16_t)(y38 - 1);
                carry10 = carry11;
                overflow10 = overflow11;
                break;
            }
            a_hi_f409 = a_hi59;
            y_f409 = y38;
            carry_f409 = carry10;
            overflow_f409 = overflow10;
            direct_page_f409 = direct_page_f344;
            data_bank_f409 = data_bank_f344;
            goto shared_F409;
        }
        uint8_t value237 = BUS8(c, (data_bank_f344 << 0x10) + 0xE110 + x_f344);
        if (value237 != 5) {
            uint8_t a_hi60 = a_hi_f344;
            uint16_t x38 = x_f344;
            uint16_t y39 = y_f344;
            bool carry12 = value237 >= 5;
            bool overflow12 = value217 & 0x40;
            for (;;) {
                uint16_t value238 = BUS16(c, (RAM8(0x0012 + direct_page_f344) << 0x10) + RAM16(0x0010 + direct_page_f344));
                RAM16_SET(0x0010 + direct_page_f344, (uint16_t)(RAM16(0x0010 + direct_page_f344) + 1));
                RAM16_SET(0x0010 + direct_page_f344, (uint16_t)(RAM16(0x0010 + direct_page_f344) + 1));
                RAM8(0x0001 + direct_page_f344) = (RAM8(0x0001 + direct_page_f344) >> 1) | (value238 >> 0x0F << 7);
                RAM8(0x0001 + direct_page_f344) = (RAM8(0x0001 + direct_page_f344) >> 1) | ((uint8_t)value238 >> 7 << 7);
                uint8_t a104;
                if ((uint8_t)((uint8_t)value238 << 1) < 0x80) {
                    uint8_t value241 = RAM8(0x0005 + direct_page_f344);
                    uint8_t a97;
                    if (value241 & 0x40) {
                        a97 = (uint8_t)((uint8_t)value238 << 1);
                    } else {
                        a97 = (uint8_t)((uint8_t)value238 << 1) >> 1;
                    }
                    uint8_t value242 = RAM8(0x000B + direct_page_f344);
                    uint8_t value243 = RAM8(0x0002 + direct_page_f344);
                    uint8_t a98;
                    if (!(value243 & 0x80)) {
                        a98 = (uint8_t)(a97 + value242);
                    } else {
                        a98 = (uint8_t)((uint8_t)(a97 + value242) + 0x0F) ^ 0xFF;
                    }
                    a104 = a98;
                } else {
                    uint8_t value244 = RAM8(0x0005 + direct_page_f344);
                    uint8_t a99;
                    if (value244 & 0x40) {
                        a99 = (uint8_t)((uint8_t)value238 << 1);
                    } else {
                        a99 = ((uint8_t)((uint8_t)value238 << 1) >> 1) | (((uint8_t)((uint8_t)value238 << 1) >= 0x80) << 7);
                    }
                    uint8_t value245 = RAM8(0x000B + direct_page_f344);
                    uint8_t value246 = RAM8(0x0002 + direct_page_f344);
                    uint8_t a103;
                    if (value246 & 0x80) {
                        a103 = (uint8_t)((uint8_t)(a99 + value245) + 0x0F) ^ 0xFF;
                    } else {
                        uint8_t a102;
                        if (!(value246 & 0x80)) {
                            a102 = (uint8_t)(a99 + value245);
                        } else {
                            uint8_t a100;
                            if (value244 & 0x40) {
                                a100 = (uint8_t)(a99 + value245);
                            } else {
                                a100 = (uint8_t)(a99 + value245) >> 1;
                            }
                            uint8_t a101;
                            if (!(value246 & 0x80)) {
                                a101 = (uint8_t)(a100 + value245);
                            } else {
                                a101 = (uint8_t)((uint8_t)(a100 + value245) + 0x0F) ^ 0xFF;
                            }
                            a102 = a101;
                        }
                        a103 = a102;
                    }
                    a104 = a103;
                }
                uint8_t a112;
                if (!((uint8_t)(value238 >> 8 << 1) & 0x80)) {
                    uint8_t value247 = RAM8(0x0005 + direct_page_f344);
                    uint8_t a105;
                    if (value247 & 0x40) {
                        a105 = (uint8_t)(value238 >> 8 << 1);
                    } else {
                        a105 = (uint8_t)(value238 >> 8 << 1) >> 1;
                    }
                    uint8_t value248 = RAM8(0x000A + direct_page_f344);
                    uint8_t value249 = RAM8(0x0002 + direct_page_f344);
                    uint8_t a106;
                    if (!(value249 & 0x40)) {
                        a106 = (uint8_t)(a105 + value248);
                    } else {
                        a106 = (uint8_t)((uint8_t)(a105 + value248) + 0x0F) ^ 0xFF;
                    }
                    a112 = a106;
                } else {
                    uint8_t value250 = RAM8(0x0005 + direct_page_f344);
                    uint8_t a107;
                    if (value250 & 0x40) {
                        a107 = (uint8_t)(value238 >> 8 << 1);
                    } else {
                        a107 = ((uint8_t)(value238 >> 8 << 1) >> 1) | 0x80;
                    }
                    uint8_t value251 = RAM8(0x000A + direct_page_f344);
                    uint8_t value252 = RAM8(0x0002 + direct_page_f344);
                    uint8_t a111;
                    if (value252 & 0x40) {
                        a111 = (uint8_t)((uint8_t)(a107 + value251) + 0x0F) ^ 0xFF;
                    } else {
                        uint8_t a110;
                        if (!(value252 & 0x40)) {
                            a110 = (uint8_t)(a107 + value251);
                        } else {
                            uint8_t a108;
                            if (value250 & 0x40) {
                                a108 = (uint8_t)(a107 + value251);
                            } else {
                                a108 = (uint8_t)(a107 + value251) >> 1;
                            }
                            uint8_t a109;
                            if (!(value252 & 0x40)) {
                                a109 = (uint8_t)(a108 + value251);
                            } else {
                                a109 = (uint8_t)((uint8_t)(a108 + value251) + 0x0F) ^ 0xFF;
                            }
                            a110 = a109;
                        }
                        a111 = a110;
                    }
                    a112 = a111;
                }
                BUS16_SET(c, (data_bank_f344 << 0x10) + 0xE0D0 + x38, (a104 << 8) | a112);
                BUS8_SET(c, (data_bank_f344 << 0x10) + 0xE0D3 + x38, ((RAM8(0x0001 + direct_page_f344) ^ RAM8(0x0002 + direct_page_f344)) & 0xC0) | RAM8(0x000D + direct_page_f344));
                uint8_t value256 = RAM8(0x000C + direct_page_f344);
                BUS8_SET(c, (data_bank_f344 << 0x10) + 0xE0D2 + x38, value256);
                uint8_t a113;
                bool carry13;
                bool overflow13;
                if (((uint8_t)(value256 + 2) & 0x10) == 0) {
                    a113 = (uint8_t)(value256 + 2);
                    carry13 = value256 + 2 > 0xFF;
                    overflow13 = ((value256 ^ (uint8_t)(value256 + 2)) & ((uint8_t)(value256 + 2) ^ 2) & 0x80) != 0;
                } else {
                    if ((uint8_t)(value256 + 2) + 0x10 + (value256 + 2 > 0xFF) > 0xFF) {
                        RAM8(0x000D + direct_page_f344)++;
                    }
                    a113 = (uint8_t)((uint8_t)(value256 + 2) + 0x10 + (value256 + 2 > 0xFF));
                    carry13 = (uint8_t)(value256 + 2) + 0x10 + (value256 + 2 > 0xFF) > 0xFF;
                    overflow13 = (((uint8_t)(value256 + 2) ^ (uint8_t)((uint8_t)(value256 + 2) + 0x10 + (value256 + 2 > 0xFF))) & ((uint8_t)((uint8_t)(value256 + 2) + 0x10 + (value256 + 2 > 0xFF)) ^ 0x10) & 0x80) != 0;
                }
                RAM8(0x000C + direct_page_f344) = a113;
                if ((uint16_t)(y39 - 1) != 0) {
                    a_hi60 = a104;
                    x38 = (uint16_t)(x38 + 4);
                    y39 = (uint16_t)(y39 - 1);
                    carry12 = carry13;
                    overflow12 = overflow13;
                    continue;
                }
                a_hi60 = a104;
                x38 = (uint16_t)(x38 + 4);
                y39 = (uint16_t)(y39 - 1);
                carry12 = carry13;
                overflow12 = overflow13;
                break;
            }
            a_hi_f409 = a_hi60;
            y_f409 = y39;
            carry_f409 = carry12;
            overflow_f409 = overflow12;
            direct_page_f409 = direct_page_f344;
            data_bank_f409 = data_bank_f344;
            goto shared_F409;
        }
        r->x = x_f344;
        r->mf = true;
        r->xf = false;
        r->db = data_bank_f344;
        r->dp = direct_page_f344;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF37F, 0xC2ABCA); GUARD_JSL(c, sp_call, 0xF37F); } /* decode_and_publish_native_packed_visual_effect_trail */
        r->xf = false;
        RETURN_RTS(c);
    }
    uint8_t value257 = BUS8(c, (data_bank_f344 << 0x10) + 0xE110 + x_f344);
    uint8_t a114;
    uint8_t a_hi61;
    if (value257 != 4) {
        a114 = (uint8_t)(x_f344 >> 1);
        a_hi61 = x_f344 >> 1 >> 8;
    } else {
        uint16_t value258 = BUS16(c, (data_bank_f344 << 0x10) + 0xE11C + x_f344);
        a114 = (uint8_t)((x_f344 >> 1) | value258);
        a_hi61 = ((x_f344 >> 1) | value258) >> 8;
    }
    uint8_t a_hi62 = a_hi61;
    uint16_t x39 = (a_hi61 << 8) | a114;
    uint16_t y40 = y_f344;
    bool overflow14 = 0;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint16_t value259 = BUS16(c, (RAM8(0x0012 + direct_page_f344) << 0x10) + RAM16(0x0010 + direct_page_f344));
            RAM16_SET(0x0010 + direct_page_f344, (uint16_t)(RAM16(0x0010 + direct_page_f344) + 1));
            RAM16_SET(0x0010 + direct_page_f344, (uint16_t)(RAM16(0x0010 + direct_page_f344) + 1));
            RAM8(0x0001 + direct_page_f344) = (RAM8(0x0001 + direct_page_f344) >> 1) | (value259 >> 0x0F << 7);
            RAM8(0x0001 + direct_page_f344) = (RAM8(0x0001 + direct_page_f344) >> 1) | ((uint8_t)value259 >> 7 << 7);
            uint8_t a122;
            if ((uint8_t)((uint8_t)value259 << 1) < 0x80) {
                uint8_t value262 = RAM8(0x0005 + direct_page_f344);
                uint8_t a115;
                if (value262 & 0x40) {
                    a115 = (uint8_t)((uint8_t)value259 << 1);
                } else {
                    a115 = (uint8_t)((uint8_t)value259 << 1) >> 1;
                }
                uint8_t value263 = RAM8(0x000B + direct_page_f344);
                uint8_t value264 = RAM8(0x0002 + direct_page_f344);
                uint8_t a116;
                if (!(value264 & 0x80)) {
                    a116 = (uint8_t)(a115 + value263);
                } else {
                    a116 = (uint8_t)((uint8_t)(a115 + value263) + 0x0F) ^ 0xFF;
                }
                a122 = a116;
            } else {
                uint8_t value265 = RAM8(0x0005 + direct_page_f344);
                uint8_t a117;
                if (value265 & 0x40) {
                    a117 = (uint8_t)((uint8_t)value259 << 1);
                } else {
                    a117 = ((uint8_t)((uint8_t)value259 << 1) >> 1) | (((uint8_t)((uint8_t)value259 << 1) >= 0x80) << 7);
                }
                uint8_t value266 = RAM8(0x000B + direct_page_f344);
                uint8_t value267 = RAM8(0x0002 + direct_page_f344);
                uint8_t a121;
                if (value267 & 0x80) {
                    a121 = (uint8_t)((uint8_t)(a117 + value266) + 0x0F) ^ 0xFF;
                } else {
                    uint8_t a120;
                    if (!(value267 & 0x80)) {
                        a120 = (uint8_t)(a117 + value266);
                    } else {
                        uint8_t a118;
                        if (value265 & 0x40) {
                            a118 = (uint8_t)(a117 + value266);
                        } else {
                            a118 = (uint8_t)(a117 + value266) >> 1;
                        }
                        uint8_t a119;
                        if (!(value267 & 0x80)) {
                            a119 = (uint8_t)(a118 + value266);
                        } else {
                            a119 = (uint8_t)((uint8_t)(a118 + value266) + 0x0F) ^ 0xFF;
                        }
                        a120 = a119;
                    }
                    a121 = a120;
                }
                a122 = a121;
            }
            uint8_t a130;
            if (!((uint8_t)(value259 >> 8 << 1) & 0x80)) {
                uint8_t value268 = RAM8(0x0005 + direct_page_f344);
                uint8_t a123;
                if (value268 & 0x40) {
                    a123 = (uint8_t)(value259 >> 8 << 1);
                } else {
                    a123 = (uint8_t)(value259 >> 8 << 1) >> 1;
                }
                uint8_t value269 = RAM8(0x000A + direct_page_f344);
                uint8_t value270 = RAM8(0x0002 + direct_page_f344);
                uint8_t a124;
                if (!(value270 & 0x40)) {
                    a124 = (uint8_t)(a123 + value269);
                } else {
                    a124 = (uint8_t)((uint8_t)(a123 + value269) + 0x0F) ^ 0xFF;
                }
                a130 = a124;
            } else {
                uint8_t value271 = RAM8(0x0005 + direct_page_f344);
                uint8_t a125;
                if (value271 & 0x40) {
                    a125 = (uint8_t)(value259 >> 8 << 1);
                } else {
                    a125 = ((uint8_t)(value259 >> 8 << 1) >> 1) | 0x80;
                }
                uint8_t value272 = RAM8(0x000A + direct_page_f344);
                uint8_t value273 = RAM8(0x0002 + direct_page_f344);
                uint8_t a129;
                if (value273 & 0x40) {
                    a129 = (uint8_t)((uint8_t)(a125 + value272) + 0x0F) ^ 0xFF;
                } else {
                    uint8_t a128;
                    if (!(value273 & 0x40)) {
                        a128 = (uint8_t)(a125 + value272);
                    } else {
                        uint8_t a126;
                        if (value271 & 0x40) {
                            a126 = (uint8_t)(a125 + value272);
                        } else {
                            a126 = (uint8_t)(a125 + value272) >> 1;
                        }
                        uint8_t a127;
                        if (!(value273 & 0x40)) {
                            a127 = (uint8_t)(a126 + value272);
                        } else {
                            a127 = (uint8_t)((uint8_t)(a126 + value272) + 0x0F) ^ 0xFF;
                        }
                        a128 = a127;
                    }
                    a129 = a128;
                }
                a130 = a129;
            }
            BUS16_SET(c, (data_bank_f344 << 0x10) + 0xC000 + x39, (a122 << 8) | a130);
            BUS8_SET(c, (data_bank_f344 << 0x10) + 0xC003 + x39, ((RAM8(0x0001 + direct_page_f344) ^ RAM8(0x0002 + direct_page_f344)) & 0xC0) | RAM8(0x000D + direct_page_f344));
            uint8_t value277 = RAM8(0x000C + direct_page_f344);
            BUS8_SET(c, (data_bank_f344 << 0x10) + 0xC002 + x39, value277);
            uint8_t a131;
            bool overflow15;
            if (((uint8_t)(value277 + 2) & 0x10) == 0) {
                a131 = (uint8_t)(value277 + 2);
                overflow15 = ((value277 ^ (uint8_t)(value277 + 2)) & ((uint8_t)(value277 + 2) ^ 2) & 0x80) != 0;
            } else {
                if ((uint8_t)(value277 + 2) + 0x10 + (value277 + 2 > 0xFF) > 0xFF) {
                    RAM8(0x000D + direct_page_f344)++;
                }
                a131 = (uint8_t)((uint8_t)(value277 + 2) + 0x10 + (value277 + 2 > 0xFF));
                overflow15 = (((uint8_t)(value277 + 2) ^ (uint8_t)((uint8_t)(value277 + 2) + 0x10 + (value277 + 2 > 0xFF))) & ((uint8_t)((uint8_t)(value277 + 2) + 0x10 + (value277 + 2 > 0xFF)) ^ 0x10) & 0x80) != 0;
            }
            RAM8(0x000C + direct_page_f344) = a131;
            if ((uint16_t)(y40 - 1) != 0) {
                a_hi62 = a122;
                x39 = (uint16_t)(x39 + 4);
                y40 = (uint16_t)(y40 - 1);
                overflow14 = overflow15;
                first_pass = false;
                continue;
            }
            a_hi62 = a122;
            x39 = (uint16_t)(x39 + 4);
            y40 = (uint16_t)(y40 - 1);
            overflow14 = overflow15;
            break;
        } else {
            uint16_t value278 = BUS16(c, (RAM8(0x0012 + direct_page_f344) << 0x10) + RAM16(0x0010 + direct_page_f344));
            RAM16_SET(0x0010 + direct_page_f344, (uint16_t)(RAM16(0x0010 + direct_page_f344) + 1));
            RAM16_SET(0x0010 + direct_page_f344, (uint16_t)(RAM16(0x0010 + direct_page_f344) + 1));
            RAM8(0x0001 + direct_page_f344) = (RAM8(0x0001 + direct_page_f344) >> 1) | (value278 >> 0x0F << 7);
            RAM8(0x0001 + direct_page_f344) = (RAM8(0x0001 + direct_page_f344) >> 1) | ((uint8_t)value278 >> 7 << 7);
            uint8_t a139;
            if ((uint8_t)((uint8_t)value278 << 1) < 0x80) {
                uint8_t value281 = RAM8(0x0005 + direct_page_f344);
                uint8_t a132;
                if (value281 & 0x40) {
                    a132 = (uint8_t)((uint8_t)value278 << 1);
                } else {
                    a132 = (uint8_t)((uint8_t)value278 << 1) >> 1;
                }
                uint8_t value282 = RAM8(0x000B + direct_page_f344);
                uint8_t value283 = RAM8(0x0002 + direct_page_f344);
                uint8_t a133;
                if (!(value283 & 0x80)) {
                    a133 = (uint8_t)(a132 + value282);
                } else {
                    a133 = (uint8_t)((uint8_t)(a132 + value282) + 0x0F) ^ 0xFF;
                }
                a139 = a133;
            } else {
                uint8_t value284 = RAM8(0x0005 + direct_page_f344);
                uint8_t a134;
                if (value284 & 0x40) {
                    a134 = (uint8_t)((uint8_t)value278 << 1);
                } else {
                    a134 = ((uint8_t)((uint8_t)value278 << 1) >> 1) | (((uint8_t)((uint8_t)value278 << 1) >= 0x80) << 7);
                }
                uint8_t value285 = RAM8(0x000B + direct_page_f344);
                uint8_t value286 = RAM8(0x0002 + direct_page_f344);
                uint8_t a138;
                if (value286 & 0x80) {
                    a138 = (uint8_t)((uint8_t)(a134 + value285) + 0x0F) ^ 0xFF;
                } else {
                    uint8_t a137;
                    if (!(value286 & 0x80)) {
                        a137 = (uint8_t)(a134 + value285);
                    } else {
                        uint8_t a135;
                        if (value284 & 0x40) {
                            a135 = (uint8_t)(a134 + value285);
                        } else {
                            a135 = (uint8_t)(a134 + value285) >> 1;
                        }
                        uint8_t a136;
                        if (!(value286 & 0x80)) {
                            a136 = (uint8_t)(a135 + value285);
                        } else {
                            a136 = (uint8_t)((uint8_t)(a135 + value285) + 0x0F) ^ 0xFF;
                        }
                        a137 = a136;
                    }
                    a138 = a137;
                }
                a139 = a138;
            }
            uint8_t a147;
            if (!((uint8_t)(value278 >> 8 << 1) & 0x80)) {
                uint8_t value287 = RAM8(0x0005 + direct_page_f344);
                uint8_t a140;
                if (value287 & 0x40) {
                    a140 = (uint8_t)(value278 >> 8 << 1);
                } else {
                    a140 = (uint8_t)(value278 >> 8 << 1) >> 1;
                }
                uint8_t value288 = RAM8(0x000A + direct_page_f344);
                uint8_t value289 = RAM8(0x0002 + direct_page_f344);
                uint8_t a141;
                if (!(value289 & 0x40)) {
                    a141 = (uint8_t)(a140 + value288);
                } else {
                    a141 = (uint8_t)((uint8_t)(a140 + value288) + 0x0F) ^ 0xFF;
                }
                a147 = a141;
            } else {
                uint8_t value290 = RAM8(0x0005 + direct_page_f344);
                uint8_t a142;
                if (value290 & 0x40) {
                    a142 = (uint8_t)(value278 >> 8 << 1);
                } else {
                    a142 = ((uint8_t)(value278 >> 8 << 1) >> 1) | 0x80;
                }
                uint8_t value291 = RAM8(0x000A + direct_page_f344);
                uint8_t value292 = RAM8(0x0002 + direct_page_f344);
                uint8_t a146;
                if (value292 & 0x40) {
                    a146 = (uint8_t)((uint8_t)(a142 + value291) + 0x0F) ^ 0xFF;
                } else {
                    uint8_t a145;
                    if (!(value292 & 0x40)) {
                        a145 = (uint8_t)(a142 + value291);
                    } else {
                        uint8_t a143;
                        if (value290 & 0x40) {
                            a143 = (uint8_t)(a142 + value291);
                        } else {
                            a143 = (uint8_t)(a142 + value291) >> 1;
                        }
                        uint8_t a144;
                        if (!(value292 & 0x40)) {
                            a144 = (uint8_t)(a143 + value291);
                        } else {
                            a144 = (uint8_t)((uint8_t)(a143 + value291) + 0x0F) ^ 0xFF;
                        }
                        a145 = a144;
                    }
                    a146 = a145;
                }
                a147 = a146;
            }
            BUS16_SET(c, (data_bank_f344 << 0x10) + 0xC000 + x39, (a139 << 8) | a147);
            BUS8_SET(c, (data_bank_f344 << 0x10) + 0xC003 + x39, ((RAM8(0x0001 + direct_page_f344) ^ RAM8(0x0002 + direct_page_f344)) & 0xC0) | RAM8(0x000D + direct_page_f344));
            uint8_t value296 = RAM8(0x000C + direct_page_f344);
            BUS8_SET(c, (data_bank_f344 << 0x10) + 0xC002 + x39, value296);
            uint8_t a148;
            bool overflow16;
            if (((uint8_t)(value296 + 2) & 0x10) == 0) {
                a148 = (uint8_t)(value296 + 2);
                overflow16 = ((value296 ^ (uint8_t)(value296 + 2)) & ((uint8_t)(value296 + 2) ^ 2) & 0x80) != 0;
            } else {
                if ((uint8_t)(value296 + 2) + 0x10 + (value296 + 2 > 0xFF) > 0xFF) {
                    RAM8(0x000D + direct_page_f344)++;
                }
                a148 = (uint8_t)((uint8_t)(value296 + 2) + 0x10 + (value296 + 2 > 0xFF));
                overflow16 = (((uint8_t)(value296 + 2) ^ (uint8_t)((uint8_t)(value296 + 2) + 0x10 + (value296 + 2 > 0xFF))) & ((uint8_t)((uint8_t)(value296 + 2) + 0x10 + (value296 + 2 > 0xFF)) ^ 0x10) & 0x80) != 0;
            }
            RAM8(0x000C + direct_page_f344) = a148;
            if ((uint16_t)(y40 - 1) != 0) {
                a_hi62 = a139;
                x39 = (uint16_t)(x39 + 4);
                y40 = (uint16_t)(y40 - 1);
                overflow14 = overflow16;
                continue;
            }
            a_hi62 = a139;
            x39 = (uint16_t)(x39 + 4);
            y40 = (uint16_t)(y40 - 1);
            overflow14 = overflow16;
            break;
        }
    }
    uint16_t value297 = RAM16(0x0014 + direct_page_f344);
    uint8_t value298 = BUS8(c, (data_bank_f344 << 0x10) + 0xE110 + value297);
    if (value298 == 4) {
        uint8_t value299 = BUS8(c, (data_bank_f344 << 0x10) + 0xE084 + value297);
        BUS8_SET(c, (data_bank_f344 << 0x10) + 0xE113 + value297, (uint8_t)(value299 << 2));
        RAM16_SET(0x0000 + direct_page_f344, ((a_hi62 << 8) | (uint8_t)(value299 << 2)) & 0x7F);
        RAM8(0x0000 + sp0) = value297 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)value297;
        RAM16_SET(0x0002 + direct_page_f344, value297 >> 1);
        uint16_t value300 = BUS16(c, (data_bank_f344 << 0x10) + 0xE06C + value297);
        uint16_t value301 = BUS16(c, (data_bank_f344 << 0x10) + 0xE11C + value297);
        uint16_t value302 = RAM16(0x0002 + direct_page_f344);
        uint8_t a_hi63 = ((uint16_t)(value301 << 1) | value302) >> 8;
        uint16_t x40 = (uint16_t)(value301 << 1) | value302;
        uint16_t y41 = value300;
        do {
            uint16_t value303 = BUS16(c, (data_bank_f344 << 0x10) + y41);
            BUS16_SET(c, (data_bank_f344 << 0x10) + 0xC060 + x40, value303);
            RAM16_SET(0x0000 + direct_page_f344, (uint16_t)(RAM16(0x0000 + direct_page_f344) - 1));
            a_hi63 = value303 >> 8;
            x40 = (uint16_t)(x40 + 2);
            y41 = (uint16_t)(y41 + 2);
        } while (RAM16(0x0000 + direct_page_f344) != 0);
        uint8_t value304 = RAM8(0x0000 + sp0 - 1);
        uint8_t value305 = RAM8(0x0000 + sp0);
        RAM8(0x0000 + sp0) = value305;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((value305 << 8) | value304);
        uint16_t value306 = BUS16(c, (data_bank_f344 << 0x10) + 0xE123 + ((value305 << 8) | value304));
        RAM16_SET(0x0000 + direct_page_f344, value306 & 0x7F);
        uint16_t value307 = BUS16(c, (data_bank_f344 << 0x10) + 0xE12C + ((value305 << 8) | value304));
        uint16_t value308 = RAM16(0x0002 + direct_page_f344);
        uint8_t a_hi64 = ((uint16_t)(value307 << 1) | value308) >> 8;
        uint16_t x41 = (uint16_t)(value307 << 1) | value308;
        uint16_t y42 = y41;
        do {
            uint16_t value309 = BUS16(c, (data_bank_f344 << 0x10) + 0xC060 + x41);
            BUS16_SET(c, (data_bank_f344 << 0x10) + y42, value309);
            RAM16_SET(0x0000 + direct_page_f344, (uint16_t)(RAM16(0x0000 + direct_page_f344) - 1));
            a_hi64 = value309 >> 8;
            x41 = (uint16_t)(x41 + 2);
            y42 = (uint16_t)(y42 + 2);
        } while (RAM16(0x0000 + direct_page_f344) != 0);
        uint8_t value310 = RAM8(0x0000 + sp0 - 1);
        uint8_t value311 = RAM8(0x0000 + sp0);
        RAM8(0x0000 + sp0) = value311;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((value311 << 8) | value310);
        uint16_t value312 = BUS16(c, (data_bank_f344 << 0x10) + 0xE133 + ((value311 << 8) | value310));
        RAM16_SET(0x0000 + direct_page_f344, value312 & 0x7F);
        uint16_t value313 = BUS16(c, (data_bank_f344 << 0x10) + 0xE13C + ((value311 << 8) | value310));
        uint16_t value314 = RAM16(0x0002 + direct_page_f344);
        uint8_t a_hi65 = ((uint16_t)(value313 << 1) | value314) >> 8;
        uint16_t x42 = (uint16_t)(value313 << 1) | value314;
        uint16_t y43 = y42;
        do {
            uint16_t value315 = BUS16(c, (data_bank_f344 << 0x10) + 0xC060 + x42);
            BUS16_SET(c, (data_bank_f344 << 0x10) + y43, value315);
            RAM16_SET(0x0000 + direct_page_f344, (uint16_t)(RAM16(0x0000 + direct_page_f344) - 1));
            a_hi65 = value315 >> 8;
            x42 = (uint16_t)(x42 + 2);
            y43 = (uint16_t)(y43 + 2);
        } while (RAM16(0x0000 + direct_page_f344) != 0);
        uint8_t value316 = RAM8(0x0000 + sp0 - 1);
        uint8_t value317 = RAM8(0x0000 + sp0);
        uint8_t value318 = BUS8(c, (data_bank_f344 << 0x10) + 0xE113 + ((value317 << 8) | value316));
        uint8_t value319 = BUS8(c, (data_bank_f344 << 0x10) + 0xE123 + ((value317 << 8) | value316));
        uint8_t value320 = BUS8(c, (data_bank_f344 << 0x10) + 0xE133 + ((value317 << 8) | value316));
        BUS8_SET(c, (data_bank_f344 << 0x10) + 0xE084 + ((value317 << 8) | value316), (uint8_t)((uint8_t)(value318 + value319) + value320 + (value318 + value319 > 0xFF)) >> 2);
        uint16_t value321 = BUS16(c, (data_bank_f344 << 0x10) + 0xE113 + ((value317 << 8) | value316));
        uint16_t value322 = BUS16(c, (data_bank_f344 << 0x10) + 0xE11C + ((value317 << 8) | value316));
        uint16_t value324 = BUS16(c, (data_bank_f344 << 0x10) + 0xC000 + ((uint16_t)((uint16_t)((value321 & 0x7F) - 2) + value322) | RAM16(0x0002 + direct_page_f344)));
        RAM16_SET(0x0004 + direct_page_f344, value324 & 0x01FF);
        uint16_t value325 = BUS16(c, (data_bank_f344 << 0x10) + 0xE123 + ((value317 << 8) | value316));
        RAM16_SET(0x0000 + direct_page_f344, (value325 & 0x7F) >> 2);
        uint16_t value326 = BUS16(c, (data_bank_f344 << 0x10) + 0xE12C + ((value317 << 8) | value316));
        uint16_t value327 = RAM16(0x0002 + direct_page_f344);
        uint8_t a_hi66 = (value326 | value327) >> 8;
        uint16_t y44 = value326 | value327;
        do {
            uint16_t value328 = RAM16(0x0004 + direct_page_f344);
            uint8_t a149;
            uint8_t a_hi67;
            if (((uint16_t)(value328 + 2) & 0x10) == 0) {
                a149 = (uint8_t)(value328 + 2);
                a_hi67 = (uint16_t)(value328 + 2) >> 8;
            } else {
                a149 = (uint8_t)((uint16_t)(value328 + 2) + 0x10 + (value328 + 2 > 0xFFFF));
                a_hi67 = (uint16_t)((uint16_t)(value328 + 2) + 0x10 + (value328 + 2 > 0xFFFF)) >> 8;
            }
            RAM16_SET(0x0004 + direct_page_f344, (a_hi67 << 8) | a149);
            uint16_t value329 = BUS16(c, (data_bank_f344 << 0x10) + 0xC002 + y44);
            uint16_t value330 = RAM16(0x0004 + direct_page_f344);
            BUS16_SET(c, (data_bank_f344 << 0x10) + 0xC002 + y44, (value329 & 0xFE00) | value330);
            RAM16_SET(0x0000 + direct_page_f344, (uint16_t)(RAM16(0x0000 + direct_page_f344) - 1));
            a_hi66 = ((value329 & 0xFE00) | value330) >> 8;
            y44 = (uint16_t)(y44 + 4);
        } while (RAM16(0x0000 + direct_page_f344) != 0);
        uint16_t value331 = BUS16(c, (data_bank_f344 << 0x10) + 0xE133 + ((value317 << 8) | value316));
        RAM16_SET(0x0000 + direct_page_f344, (value331 & 0x7F) >> 2);
        uint16_t value332 = BUS16(c, (data_bank_f344 << 0x10) + 0xE13C + ((value317 << 8) | value316));
        uint16_t value333 = RAM16(0x0002 + direct_page_f344);
        uint8_t a_hi68 = (value332 | value333) >> 8;
        uint16_t y45 = value332 | value333;
        bool carry14 = (value331 & 0x7F) >> 1 & 0x01;
        bool overflow17 = 0;
        do {
            uint16_t value334 = RAM16(0x0004 + direct_page_f344);
            uint8_t a150;
            uint8_t a_hi69;
            bool carry15;
            bool overflow18;
            if (((uint16_t)(value334 + 2) & 0x10) == 0) {
                a150 = (uint8_t)(value334 + 2);
                a_hi69 = (uint16_t)(value334 + 2) >> 8;
                carry15 = value334 + 2 > 0xFFFF;
                overflow18 = ((value334 ^ (uint16_t)(value334 + 2)) & ((uint16_t)(value334 + 2) ^ 2) & 0x8000) != 0;
            } else {
                a150 = (uint8_t)((uint16_t)(value334 + 2) + 0x10 + (value334 + 2 > 0xFFFF));
                a_hi69 = (uint16_t)((uint16_t)(value334 + 2) + 0x10 + (value334 + 2 > 0xFFFF)) >> 8;
                carry15 = (uint16_t)(value334 + 2) + 0x10 + (value334 + 2 > 0xFFFF) > 0xFFFF;
                overflow18 = (((uint16_t)(value334 + 2) ^ (uint16_t)((uint16_t)(value334 + 2) + 0x10 + (value334 + 2 > 0xFFFF))) & ((uint16_t)((uint16_t)(value334 + 2) + 0x10 + (value334 + 2 > 0xFFFF)) ^ 0x10) & 0x8000) != 0;
            }
            RAM16_SET(0x0004 + direct_page_f344, (a_hi69 << 8) | a150);
            uint16_t value335 = BUS16(c, (data_bank_f344 << 0x10) + 0xC002 + y45);
            uint16_t value336 = RAM16(0x0004 + direct_page_f344);
            BUS16_SET(c, (data_bank_f344 << 0x10) + 0xC002 + y45, (value335 & 0xFE00) | value336);
            RAM16_SET(0x0000 + direct_page_f344, (uint16_t)(RAM16(0x0000 + direct_page_f344) - 1));
            a_hi68 = ((value335 & 0xFE00) | value336) >> 8;
            y45 = (uint16_t)(y45 + 4);
            carry14 = carry15;
            overflow17 = overflow18;
        } while (RAM16(0x0000 + direct_page_f344) != 0);
        r->a = (a_hi68 << 8) | (uint8_t)a;
        r->x = (value317 << 8) | value316;
        r->y = y45;
        r->c = carry14;
        r->v = overflow17;
        r->mf = false;
        r->xf = false;
        r->db = data_bank_f344;
        r->dp = direct_page_f344;
        RETURN_RTS(c);
    }
    if (value298 >= 4) {
        r->a = (a_hi62 << 8) | value298;
        r->x = value297;
        r->y = y40;
        r->c = value298 >= 4;
        r->v = overflow14;
        r->mf = true;
        r->xf = false;
        r->db = data_bank_f344;
        r->dp = direct_page_f344;
        RETURN_RTS(c);
    }
    if (value298 == 1) {
        r->a = (a_hi62 << 8) | value298;
        r->x = value297;
        r->y = y40;
        r->c = value298 >= 1;
        r->v = overflow14;
        r->mf = true;
        r->xf = false;
        r->db = data_bank_f344;
        r->dp = direct_page_f344;
        RETURN_RTS(c);
    }
    r->x = value297;
    r->y = y40;
    r->mf = true;
    r->xf = false;
    r->db = data_bank_f344;
    r->dp = direct_page_f344;
    { const uint16_t sp_call = r->sp; JSL(c, 0xFB8C, 0xC1924C); GUARD_JSL(c, sp_call, 0xFB8C); } /* expand_native_effect_points_into_horizontal_vertical_reflections */
    r->mf = false;
    r->xf = false;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0F1CF, SOM_RTS, "hand", publish_actor_frame_tiles_points_and_collision_rectangle, 0, L_B | L_X | L_Y | L_C | L_V, 2, -1, 0, 2496, 599)
