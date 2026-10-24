#include "som_c.h"

/* C0B330 advance_selected_hero_charge_timing_and_publish_native_gauge   [class C, 462 bytes, 198 instructions]
 * Source: src/rom/advance_selected_hero_charge_timing_and_publish_native_gauge.s
 * Documented in docs/hero-charge-input.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void advance_selected_hero_charge_timing_and_publish_native_gauge(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint8_t a_hi_b348 = 0;
    uint16_t x_b348 = 0;
    uint16_t y_b348 = 0;
    bool carry_b348 = 0;
    bool overflow_b348 = 0;
    uint8_t a_hi_b35c = 0;
    uint16_t x_b35c = 0;
    uint16_t y_b35c = 0;
    bool overflow_b35c = 0;
    uint8_t a_b380 = 0;
    uint8_t a_hi_b380 = 0;
    uint16_t x_b380 = 0;
    uint16_t y_b380 = 0;
    bool carry_b380 = 0;
    bool overflow_b380 = 0;
    uint8_t a_b381 = 0;
    uint8_t a_hi_b381 = 0;
    uint16_t x_b381 = 0;
    uint16_t y_b381 = 0;
    bool carry_b381 = 0;
    bool overflow_b381 = 0;
    uint8_t a_hi_b369 = 0;
    uint16_t x_b369 = 0;
    uint16_t y_b369 = 0;
    bool overflow_b369 = 0;
    uint8_t a_b37c = 0;
    uint8_t a_hi_b37c = 0;
    uint16_t x_b37c = 0;
    uint16_t y_b37c = 0;
    bool carry_b37c = 0;
    bool overflow_b37c = 0;
    uint8_t a_hi_b3a2 = 0;
    uint16_t y_b3a2 = 0;
    bool overflow_b3a2 = 0;
    uint8_t a_hi_b3ba = 0;
    uint16_t x_b3ba = 0;
    uint16_t y_b3ba = 0;
    bool overflow_b3ba = 0;
    uint16_t direct_page_b3ba = 0;
    uint8_t data_bank_b3ba = 0;
    uint8_t a_hi_b3a22 = 0;
    uint16_t y_b3a22 = 0;
    bool overflow_b3a22 = 0;
    uint8_t a_hi_b376 = 0;
    uint16_t x_b376 = 0;
    uint16_t y_b376 = 0;
    bool carry_b376 = 0;
    bool overflow_b376 = 0;
    uint8_t a_hi_b4cb = 0;
    uint16_t y_b4cb = 0;
    bool overflow_b4cb = 0;
    uint16_t direct_page_b4cb = 0;
    uint8_t data_bank_b4cb = 0;
    uint8_t a_b3df = 0;
    uint8_t a_hi_b3df = 0;
    uint16_t x_b3df = 0;
    uint16_t y_b3df = 0;
    bool overflow_b3df = 0;
    uint16_t direct_page_b3df = 0;
    uint8_t data_bank_b3df = 0;
    uint8_t a_b3df2 = 0;
    uint8_t a_hi_b3df2 = 0;
    uint8_t x_b3df2 = 0;
    uint8_t y_b3df2 = 0;
    bool overflow_b3df2 = 0;
    uint16_t direct_page_b3df2 = 0;
    uint8_t data_bank_b3df2 = 0;
    uint8_t a_hi_b4cb2 = 0;
    uint16_t y_b4cb2 = 0;
    bool overflow_b4cb2 = 0;
    uint16_t direct_page_b4cb2 = 0;
    uint8_t data_bank_b4cb2 = 0;
    uint8_t a_hi_b4d9 = 0;
    uint16_t x_b4d9 = 0;
    uint16_t y_b4d9 = 0;
    bool carry_b4d9 = 0;
    bool overflow_b4d9 = 0;
    uint16_t direct_page_b4d9 = 0;
    uint8_t data_bank_b4d9 = 0;
    uint8_t a_hi_b3f2 = 0;
    uint16_t x_b3f2 = 0;
    uint16_t y_b3f2 = 0;
    uint16_t direct_page_b3f2 = 0;
    uint8_t data_bank_b3f2 = 0;
    uint8_t a_hi_b3f22 = 0;
    uint8_t x_b3f22 = 0;
    uint8_t y_b3f22 = 0;
    uint16_t direct_page_b3f22 = 0;
    uint8_t data_bank_b3f22 = 0;
    uint8_t a_b44f = 0;
    uint8_t a_hi_b44f = 0;
    uint16_t x_b44f = 0;
    bool overflow_b44f = 0;
    uint16_t direct_page_b44f = 0;
    uint8_t data_bank_b44f = 0;
    uint8_t a_b448 = 0;
    uint8_t a_hi_b448 = 0;
    uint16_t x_b448 = 0;
    uint16_t y_b448 = 0;
    uint16_t direct_page_b448 = 0;
    uint8_t data_bank_b448 = 0;
    uint8_t a_b44f2 = 0;
    uint8_t a_hi_b44f2 = 0;
    uint8_t x_b44f2 = 0;
    bool overflow_b44f2 = 0;
    uint16_t direct_page_b44f2 = 0;
    uint8_t data_bank_b44f2 = 0;
    uint8_t a_hi_b465 = 0;
    uint16_t y_b465 = 0;
    bool overflow_b465 = 0;
    uint16_t direct_page_b465 = 0;
    uint8_t data_bank_b465 = 0;
    uint8_t a_hi_b4652 = 0;
    uint16_t y_b4652 = 0;
    bool overflow_b4652 = 0;
    uint16_t direct_page_b4652 = 0;
    uint8_t data_bank_b4652 = 0;
    uint8_t a_hi_b4653 = 0;
    uint8_t y_b4653 = 0;
    bool overflow_b4653 = 0;
    uint16_t direct_page_b4653 = 0;
    uint8_t data_bank_b4653 = 0;
    uint8_t a_hi_b4654 = 0;
    uint8_t y_b4654 = 0;
    bool overflow_b4654 = 0;
    uint16_t direct_page_b4654 = 0;
    uint8_t data_bank_b4654 = 0;
    uint8_t a_hi_b3ba2 = 0;
    uint8_t x_b3ba2 = 0;
    uint8_t y_b3ba2 = 0;
    bool overflow_b3ba2 = 0;
    uint16_t direct_page_b3ba2 = 0;
    uint8_t data_bank_b3ba2 = 0;
    uint8_t a_b4c5 = 0;
    uint8_t a_hi_b4c5 = 0;
    uint16_t y_b4c5 = 0;
    bool overflow_b4c5 = 0;
    uint16_t direct_page_b4c5 = 0;
    uint8_t data_bank_b4c5 = 0;
    uint8_t a_hi_b4cb3 = 0;
    uint8_t y_b4cb3 = 0;
    bool overflow_b4cb3 = 0;
    uint16_t direct_page_b4cb3 = 0;
    uint8_t data_bank_b4cb3 = 0;
    uint8_t a_hi_b4d92 = 0;
    uint8_t x_b4d92 = 0;
    uint8_t y_b4d92 = 0;
    bool carry_b4d92 = 0;
    bool overflow_b4d92 = 0;
    uint16_t direct_page_b4d92 = 0;
    uint8_t data_bank_b4d92 = 0;
    if (a & 0x01) {
        a_hi_b348 = a_hi;
        x_b348 = 0;
        y_b348 = 0;
        carry_b348 = a & 0x01;
        overflow_b348 = overflow;
        goto shared_B348;
    }
    if (a >> 1 & 0x01) {
        a_hi_b348 = a_hi;
        x_b348 = 0x0200;
        y_b348 = 0x10;
        carry_b348 = a >> 1 & 0x01;
        overflow_b348 = overflow;
        goto shared_B348;
    }
    a_hi_b348 = a_hi;
    x_b348 = 0x0400;
    y_b348 = 0x20;
    carry_b348 = a >> 1 & 0x01;
    overflow_b348 = overflow;
    shared_B348:;
    if (RAM8(0xE02C + x_b348) == 0) {
        a_hi_b35c = a_hi_b348;
        x_b35c = x_b348;
        y_b35c = y_b348;
        overflow_b35c = overflow_b348;
        goto shared_B35C;
    }
    RAM8(0xE085 + x_b348) = 0;
    uint8_t value2 = RAM8(ACTOR_WEAPON_LEVEL + x_b348);
    if (value2 == 0) {
        a_b380 = value2;
        a_hi_b380 = a_hi_b348;
        x_b380 = x_b348;
        y_b380 = y_b348;
        carry_b380 = carry_b348;
        overflow_b380 = overflow_b348;
        goto shared_B380;
    }
    if (value2 != 0) {
        a_b381 = value2;
        a_hi_b381 = a_hi_b348;
        x_b381 = x_b348;
        y_b381 = y_b348;
        carry_b381 = carry_b348;
        overflow_b381 = overflow_b348;
        goto shared_B381;
    }
    a_hi_b35c = a_hi_b348;
    x_b35c = x_b348;
    y_b35c = y_b348;
    overflow_b35c = overflow_b348;
    goto shared_B35C;
    shared_B35C:;
    if (x_b35c != 0) {
        a_hi_b369 = a_hi_b35c;
        x_b369 = x_b35c;
        y_b369 = y_b35c;
        overflow_b369 = overflow_b35c;
        goto shared_B369;
    }
    uint8_t value3 = RAM8(0xCC7D);
    if (value3 == 0) {
        a_b37c = value3;
        a_hi_b37c = a_hi_b35c;
        x_b37c = x_b35c;
        y_b37c = y_b35c;
        carry_b37c = x_b35c >= 0;
        overflow_b37c = overflow_b35c;
        goto shared_B37C;
    }
    if (value3 != 0) {
        a_b381 = value3;
        a_hi_b381 = a_hi_b35c;
        x_b381 = x_b35c;
        y_b381 = y_b35c;
        carry_b381 = x_b35c >= 0;
        overflow_b381 = overflow_b35c;
        goto shared_B381;
    }
    a_hi_b369 = a_hi_b35c;
    x_b369 = x_b35c;
    y_b369 = y_b35c;
    overflow_b369 = overflow_b35c;
    goto shared_B369;
    shared_B380:;
    r->a = (a_hi_b380 << 8) | a_b380;
    r->x = x_b380;
    r->y = y_b380;
    r->c = carry_b380;
    r->v = overflow_b380;
    r->mf = true;
    r->xf = false;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
    shared_B381:;
    RAM8(0x0001) = a_b381;
    uint8_t value4 = RAM8(ACTOR_STATUS_HIGH + x_b381);
    uint8_t value5 = RAM8(0xE01C + x_b381);
    uint8_t value6 = RAM8(0xE061 + x_b381);
    uint8_t value7 = RAM8(ACTOR_WEAPON_GAUGE + x_b381);
    if (((value4 & 2) | value5 | value6 | value7) != 0) {
        a_b380 = (value4 & 2) | value5 | value6 | value7;
        a_hi_b380 = a_hi_b381;
        x_b380 = x_b381;
        y_b380 = y_b381;
        carry_b380 = carry_b381;
        overflow_b380 = overflow_b381;
        goto shared_B380;
    }
    uint8_t value8 = RAM8(0xE01F + x_b381);
    RAM8(0xE01F + x_b381) = (uint8_t)(value8 - 1);
    if ((uint8_t)(value8 - 1) & 0x80) {
        RAM8(0x0000) = 0;
        RAM8(0xE01F + x_b381) = 1;
        uint8_t value9 = RAM8(0x0001);
        if (((value9 << 8) | 0x2C) == RAM16(0xE01A + x_b381)) {
            a_hi_b3a2 = value9;
            y_b3a2 = y_b381;
            overflow_b3a2 = overflow_b381;
            goto shared_B3A2;
        }
        a_hi_b3ba = value9;
        x_b3ba = x_b381;
        y_b3ba = y_b381;
        overflow_b3ba = overflow_b381;
        direct_page_b3ba = 0;
        data_bank_b3ba = 0;
        goto shared_B3BA;
    }
    a_hi_b3a22 = a_hi_b381;
    y_b3a22 = y_b381;
    overflow_b3a22 = overflow_b381;
    goto shared_B3A2_1;
    shared_B369:;
    if (x_b369 != 0x0200) {
        a_hi_b376 = a_hi_b369;
        x_b376 = x_b369;
        y_b376 = y_b369;
        carry_b376 = x_b369 >= 0x0200;
        overflow_b376 = overflow_b369;
        goto shared_B376;
    }
    uint8_t value11 = RAM8(0xCC7E);
    if (value11 == 0) {
        a_b37c = value11;
        a_hi_b37c = a_hi_b369;
        x_b37c = x_b369;
        y_b37c = y_b369;
        carry_b37c = x_b369 >= 0x0200;
        overflow_b37c = overflow_b369;
        goto shared_B37C;
    }
    if (value11 != 0) {
        a_b381 = value11;
        a_hi_b381 = a_hi_b369;
        x_b381 = x_b369;
        y_b381 = y_b369;
        carry_b381 = x_b369 >= 0x0200;
        overflow_b381 = overflow_b369;
        goto shared_B381;
    }
    a_hi_b376 = a_hi_b369;
    x_b376 = x_b369;
    y_b376 = y_b369;
    carry_b376 = x_b369 >= 0x0200;
    overflow_b376 = overflow_b369;
    goto shared_B376;
    shared_B37C:;
    RAM8(0xE085 + x_b37c) = a_b37c;
    a_b380 = a_b37c;
    a_hi_b380 = a_hi_b37c;
    x_b380 = x_b37c;
    y_b380 = y_b37c;
    carry_b380 = carry_b37c;
    overflow_b380 = overflow_b37c;
    goto shared_B380;
    shared_B3A2:;
    a_hi_b4cb = a_hi_b3a2;
    y_b4cb = y_b3a2;
    overflow_b4cb = overflow_b3a2;
    direct_page_b4cb = 0;
    data_bank_b4cb = 0;
    goto shared_B4CB;
    shared_B3BA:;
    uint16_t value12 = RAM16(0xE01A + x_b3ba);
    RAM16_SET(0x0002 + direct_page_b3ba, ((uint8_t)value12 << 8) | (value12 >> 8));
    RAM16_SET(0x0003 + direct_page_b3ba, ((uint8_t)value12 << 8) | (value12 >> 8));
    if ((uint8_t)((uint8_t)value12 + 1) < 0x2D) {
        a_b3df = (uint8_t)((uint8_t)value12 + 1);
        a_hi_b3df = value12 >> 8;
        x_b3df = x_b3ba;
        y_b3df = y_b3ba;
        overflow_b3df = overflow_b3ba;
        direct_page_b3df = direct_page_b3ba;
        data_bank_b3df = data_bank_b3ba;
        goto shared_B3DF;
    }
    r->a = (value12 >> 8 << 8) | 0xA8;
    r->x = x_b3ba;
    r->y = y_b3ba;
    r->v = overflow_b3ba;
    r->mf = true;
    r->xf = false;
    r->db = data_bank_b3ba;
    r->dp = direct_page_b3ba;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB3CF, 0xC0BB27); GUARD_JSR(c, sp_call, 0xB3CF); } /* publish_charge_sound_only_for_controlled_hero */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    RAM8(0x0002 + dp_ret) = (uint8_t)((a_all >> 8) + 1);
    if ((uint8_t)((a_all >> 8) + 1) < RAM8(0x0001 + dp_ret)) {
        if (x_ret) {
            a_b3df2 = 0;
            a_hi_b3df2 = (uint8_t)((a_all >> 8) + 1);
            x_b3df2 = (uint8_t)x_b3ba;
            y_b3df2 = (uint8_t)y_b3ba;
            overflow_b3df2 = overflow_b3ba;
            direct_page_b3df2 = dp_ret;
            data_bank_b3df2 = db_ret;
            goto shared_B3DF_1;
        } else {
            a_b3df = 0;
            a_hi_b3df = (uint8_t)((a_all >> 8) + 1);
            x_b3df = x_b3ba;
            y_b3df = y_b3ba;
            overflow_b3df = overflow_b3ba;
            direct_page_b3df = dp_ret;
            data_bank_b3df = db_ret;
            goto shared_B3DF;
        }
    }
    RAM8(0x0000 + dp_ret)++;
    if (x_ret) {
        a_b3df2 = 0x2C;
        a_hi_b3df2 = (uint8_t)((a_all >> 8) + 1);
        x_b3df2 = (uint8_t)x_b3ba;
        y_b3df2 = (uint8_t)y_b3ba;
        overflow_b3df2 = overflow_b3ba;
        direct_page_b3df2 = dp_ret;
        data_bank_b3df2 = db_ret;
        goto shared_B3DF_1;
    } else {
        a_b3df = 0x2C;
        a_hi_b3df = (uint8_t)((a_all >> 8) + 1);
        x_b3df = x_b3ba;
        y_b3df = y_b3ba;
        overflow_b3df = overflow_b3ba;
        direct_page_b3df = dp_ret;
        data_bank_b3df = db_ret;
        goto shared_B3DF;
    }
    shared_B3A2_1:;
    a_hi_b4cb2 = a_hi_b3a22;
    y_b4cb2 = y_b3a22;
    overflow_b4cb2 = overflow_b3a22;
    direct_page_b4cb2 = 0;
    data_bank_b4cb2 = 0;
    goto shared_B4CB_1;
    shared_B376:;
    uint8_t value14 = RAM8(0xCC7F);
    if (value14 != 0) {
        a_b381 = value14;
        a_hi_b381 = a_hi_b376;
        x_b381 = x_b376;
        y_b381 = y_b376;
        carry_b381 = carry_b376;
        overflow_b381 = overflow_b376;
        goto shared_B381;
    }
    a_b37c = value14;
    a_hi_b37c = a_hi_b376;
    x_b37c = x_b376;
    y_b37c = y_b376;
    carry_b37c = carry_b376;
    overflow_b37c = overflow_b376;
    goto shared_B37C;
    shared_B4CB:;
    uint16_t value15 = RAM16(0x00F4 + direct_page_b4cb);
    if (!(value15 & 0x01)) {
        a_hi_b4d9 = value15 >> 1 >> 8;
        x_b4d9 = y_b4cb >> 1;
        y_b4d9 = y_b4cb;
        carry_b4d9 = value15 & 0x01;
        overflow_b4d9 = overflow_b4cb;
        direct_page_b4d9 = direct_page_b4cb;
        data_bank_b4d9 = data_bank_b4cb;
        goto shared_B4D9;
    }
    a_hi_b4d9 = value15 >> 1 >> 8;
    x_b4d9 = y_b4cb >> 1;
    y_b4d9 = (uint16_t)(y_b4cb + 4);
    carry_b4d9 = value15 & 0x01;
    overflow_b4d9 = overflow_b4cb;
    direct_page_b4d9 = direct_page_b4cb;
    data_bank_b4d9 = data_bank_b4cb;
    goto shared_B4D9;
    shared_B3DF:;
    RAM16_SET(0xE01A + x_b3df, (a_hi_b3df << 8) | a_b3df);
    if ((a_b3df & 3) != 1) {
        a_hi_b3f2 = a_hi_b3df;
        x_b3f2 = x_b3df;
        y_b3f2 = y_b3df;
        direct_page_b3f2 = direct_page_b3df;
        data_bank_b3f2 = data_bank_b3df;
        goto shared_B3F2;
    }
    r->a = (a_hi_b3df << 8) | 0xA7;
    r->x = x_b3df;
    r->y = y_b3df;
    r->v = overflow_b3df;
    r->mf = true;
    r->xf = false;
    r->db = data_bank_b3df;
    r->dp = direct_page_b3df;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB3F1, 0xC0BB27); GUARD_JSR(c, sp_call, 0xB3F1); } /* publish_charge_sound_only_for_controlled_hero */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool x_ret2 = r->xf;
    uint16_t a_all2 = r->a;
    if (x_ret2) {
        a_hi_b3f22 = a_all2 >> 8;
        x_b3f22 = (uint8_t)x_b3df;
        y_b3f22 = (uint8_t)y_b3df;
        direct_page_b3f22 = dp_ret2;
        data_bank_b3f22 = db_ret2;
        goto shared_B3F2_1;
    } else {
        a_hi_b3f2 = a_all2 >> 8;
        x_b3f2 = x_b3df;
        y_b3f2 = y_b3df;
        direct_page_b3f2 = dp_ret2;
        data_bank_b3f2 = db_ret2;
        goto shared_B3F2;
    }
    shared_B3DF_1:;
    RAM16_SET(0xE01A + x_b3df2, (a_hi_b3df2 << 8) | a_b3df2);
    if ((a_b3df2 & 3) != 1) {
        a_hi_b3f22 = a_hi_b3df2;
        x_b3f22 = x_b3df2;
        y_b3f22 = y_b3df2;
        direct_page_b3f22 = direct_page_b3df2;
        data_bank_b3f22 = data_bank_b3df2;
        goto shared_B3F2_1;
    }
    r->a = (a_hi_b3df2 << 8) | 0xA7;
    r->x = x_b3df2;
    r->y = y_b3df2;
    r->v = overflow_b3df2;
    r->mf = true;
    r->xf = true;
    r->db = data_bank_b3df2;
    r->dp = direct_page_b3df2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB3F1, 0xC0BB27); GUARD_JSR(c, sp_call, 0xB3F1); } /* publish_charge_sound_only_for_controlled_hero */
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    bool x_ret3 = r->xf;
    uint16_t a_all3 = r->a;
    if (x_ret3) {
        a_hi_b3f22 = a_all3 >> 8;
        x_b3f22 = x_b3df2;
        y_b3f22 = y_b3df2;
        direct_page_b3f22 = dp_ret3;
        data_bank_b3f22 = db_ret3;
        goto shared_B3F2_1;
    } else {
        a_hi_b3f2 = a_all3 >> 8;
        x_b3f2 = x_b3df2;
        y_b3f2 = y_b3df2;
        direct_page_b3f2 = dp_ret3;
        data_bank_b3f2 = db_ret3;
        goto shared_B3F2;
    }
    shared_B4CB_1:;
    uint16_t value16 = RAM16(0x00F4 + direct_page_b4cb2);
    if (!(value16 & 0x01)) {
        a_hi_b4d9 = value16 >> 1 >> 8;
        x_b4d9 = y_b4cb2 >> 1;
        y_b4d9 = y_b4cb2;
        carry_b4d9 = value16 & 0x01;
        overflow_b4d9 = overflow_b4cb2;
        direct_page_b4d9 = direct_page_b4cb2;
        data_bank_b4d9 = data_bank_b4cb2;
        goto shared_B4D9;
    }
    a_hi_b4d9 = value16 >> 1 >> 8;
    x_b4d9 = y_b4cb2 >> 1;
    y_b4d9 = (uint16_t)(y_b4cb2 + 4);
    carry_b4d9 = value16 & 0x01;
    overflow_b4d9 = overflow_b4cb2;
    direct_page_b4d9 = direct_page_b4cb2;
    data_bank_b4d9 = data_bank_b4cb2;
    goto shared_B4D9;
    shared_B4D9:;
    if ((RAM16(0x1D04) & 0x20) != 0) {
        uint16_t value18 = BUS16(c, (data_bank_b4d9 << 0x10) + 0x0A58 + y_b4d9);
        RAM16_SET(0xDE0C + x_b4d9, value18);
        uint16_t value19 = BUS16(c, (data_bank_b4d9 << 0x10) + 0x0A5A + y_b4d9);
        RAM16_SET(0xDE0E + x_b4d9, value19);
        r->a = value19;
        r->x = x_b4d9;
        r->y = y_b4d9;
        r->c = carry_b4d9;
        r->v = overflow_b4d9;
        r->mf = false;
        r->xf = false;
        r->db = data_bank_b4d9;
        r->dp = direct_page_b4d9;
        RETURN_RTS(c);
    }
    uint16_t value20 = BUS16(c, (data_bank_b4d9 << 0x10) + 0x0A58 + y_b4d9);
    BUS16_SET(c, (data_bank_b4d9 << 0x10) + 0x060C + x_b4d9, value20);
    uint16_t value21 = BUS16(c, (data_bank_b4d9 << 0x10) + 0x0A5A + y_b4d9);
    BUS16_SET(c, (data_bank_b4d9 << 0x10) + 0x060E + x_b4d9, value21);
    r->a = value21;
    r->x = x_b4d9;
    r->y = y_b4d9;
    r->c = carry_b4d9;
    r->v = overflow_b4d9;
    r->mf = false;
    r->xf = false;
    r->db = data_bank_b4d9;
    r->dp = direct_page_b4d9;
    RETURN_RTS(c);
    shared_B3F2:;
    BUS8_SET(c, (data_bank_b3f2 << 0x10) + 0x4204, RAM8(0x0004 + direct_page_b3f2));
    BUS8_SET(c, (data_bank_b3f2 << 0x10) + 0x4205, 0);
    BUS8_SET(c, (data_bank_b3f2 << 0x10) + 0x4206, 9);
    RAM8(ACTOR_CHARGE_STAGE + x_b3f2) = a_hi_b3f2;
    BUS8_SET(c, (data_bank_b3f2 << 0x10) + 0x0A56 + y_b3f2, (uint8_t)(RAM8(0x0002 + direct_page_b3f2) + 0x18));
    BUS8_SET(c, (data_bank_b3f2 << 0x10) + 0x0A57 + y_b3f2, (uint8_t)(RAM8(ACTOR_WEAPON_LEVEL + x_b3f2) + 0x28));
    uint8_t value25 = BUS8(c, (data_bank_b3f2 << 0x10) + 0x4214);
    RAM8(0x0000 + sp0) = y_b3f2 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)y_b3f2;
    uint8_t value26 = RAM8(0x0003 + direct_page_b3f2);
    uint8_t value27 = BUS8(c, (data_bank_b3f2 << 0x10) + 0x4216);
    BUS8_SET(c, (data_bank_b3f2 << 0x10) + 0x0A50 + (uint8_t)((uint8_t)y_b3f2 + value25), (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) + value27 + ((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF) > 0xFF)));
    uint8_t value28 = RAM8(0x0029 + direct_page_b3f2);
    if ((value28 & 4) != 0) {
        a_b44f = value28;
        a_hi_b44f = (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) + value27 + ((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF) > 0xFF));
        x_b44f = x_b3f2;
        overflow_b44f = (((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) ^ (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) + value27 + ((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF) > 0xFF))) & (value27 ^ (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) + value27 + ((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF) > 0xFF))) & 0x80) != 0;
        direct_page_b44f = direct_page_b3f2;
        data_bank_b44f = data_bank_b3f2;
        goto shared_B44F;
    }
    if ((value28 & 2) == 0) {
        a_b44f = value28;
        a_hi_b44f = (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) + value27 + ((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF) > 0xFF));
        x_b44f = x_b3f2;
        overflow_b44f = (((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) ^ (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) + value27 + ((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF) > 0xFF))) & (value27 ^ (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) + value27 + ((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF) > 0xFF))) & 0x80) != 0;
        direct_page_b44f = direct_page_b3f2;
        data_bank_b44f = data_bank_b3f2;
        goto shared_B44F;
    }
    if (x_b3f2 == 0) {
        a_b44f = value28;
        a_hi_b44f = (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) + value27 + ((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF) > 0xFF));
        x_b44f = x_b3f2;
        overflow_b44f = (((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) ^ (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) + value27 + ((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF) > 0xFF))) & (value27 ^ (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) + value27 + ((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF) > 0xFF))) & 0x80) != 0;
        direct_page_b44f = direct_page_b3f2;
        data_bank_b44f = data_bank_b3f2;
        goto shared_B44F;
    }
    if (x_b3f2 == 0x0200) {
        a_b448 = 0x48;
        a_hi_b448 = (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) + value27 + ((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF) > 0xFF));
        x_b448 = x_b3f2;
        y_b448 = (uint8_t)((uint8_t)y_b3f2 + value25);
        direct_page_b448 = direct_page_b3f2;
        data_bank_b448 = data_bank_b3f2;
        goto shared_B448;
    }
    a_b448 = 0x90;
    a_hi_b448 = (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF)) + value27 + ((uint8_t)((uint8_t)(value26 << 3) + value26) + 0x38 + ((uint8_t)(value26 << 3) + value26 > 0xFF) > 0xFF));
    x_b448 = x_b3f2;
    y_b448 = (uint8_t)((uint8_t)y_b3f2 + value25);
    direct_page_b448 = direct_page_b3f2;
    data_bank_b448 = data_bank_b3f2;
    goto shared_B448;
    shared_B3F2_1:;
    BUS8_SET(c, (data_bank_b3f22 << 0x10) + 0x4204, RAM8(0x0004 + direct_page_b3f22));
    BUS8_SET(c, (data_bank_b3f22 << 0x10) + 0x4205, 0);
    BUS8_SET(c, (data_bank_b3f22 << 0x10) + 0x4206, 9);
    RAM8(ACTOR_CHARGE_STAGE + x_b3f22) = a_hi_b3f22;
    BUS8_SET(c, (data_bank_b3f22 << 0x10) + 0x0A56 + y_b3f22, (uint8_t)(RAM8(0x0002 + direct_page_b3f22) + 0x18));
    BUS8_SET(c, (data_bank_b3f22 << 0x10) + 0x0A57 + y_b3f22, (uint8_t)(RAM8(ACTOR_WEAPON_LEVEL + x_b3f22) + 0x28));
    uint8_t value32 = BUS8(c, (data_bank_b3f22 << 0x10) + 0x4214);
    RAM8(0x0000 + sp0) = y_b3f22;
    uint8_t value33 = RAM8(0x0003 + direct_page_b3f22);
    uint8_t value34 = BUS8(c, (data_bank_b3f22 << 0x10) + 0x4216);
    BUS8_SET(c, (data_bank_b3f22 << 0x10) + 0x0A50 + (uint8_t)(y_b3f22 + value32), (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF)) + value34 + ((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF) > 0xFF)));
    uint8_t value35 = RAM8(0x0029 + direct_page_b3f22);
    if ((value35 & 4) != 0) {
        a_b44f2 = value35;
        a_hi_b44f2 = (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF)) + value34 + ((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF) > 0xFF));
        x_b44f2 = x_b3f22;
        overflow_b44f2 = (((uint8_t)((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF)) ^ (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF)) + value34 + ((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF) > 0xFF))) & (value34 ^ (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF)) + value34 + ((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF) > 0xFF))) & 0x80) != 0;
        direct_page_b44f2 = direct_page_b3f22;
        data_bank_b44f2 = data_bank_b3f22;
        goto shared_B44F_1;
    }
    if ((value35 & 2) == 0) {
        a_b44f2 = value35;
        a_hi_b44f2 = (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF)) + value34 + ((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF) > 0xFF));
        x_b44f2 = x_b3f22;
        overflow_b44f2 = (((uint8_t)((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF)) ^ (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF)) + value34 + ((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF) > 0xFF))) & (value34 ^ (uint8_t)((uint8_t)((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF)) + value34 + ((uint8_t)((uint8_t)(value33 << 3) + value33) + 0x38 + ((uint8_t)(value33 << 3) + value33 > 0xFF) > 0xFF))) & 0x80) != 0;
        direct_page_b44f2 = direct_page_b3f22;
        data_bank_b44f2 = data_bank_b3f22;
        goto shared_B44F_1;
    }
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_B44F:;
    uint8_t value36 = RAM8(0x0000 + sp0 - 1);
    uint8_t value37 = RAM8(0x0000 + sp0);
    if (a_hi_b44f != 0x40) {
        a_hi_b465 = a_b44f;
        y_b465 = (value37 << 8) | value36;
        overflow_b465 = overflow_b44f;
        direct_page_b465 = direct_page_b44f;
        data_bank_b465 = data_bank_b44f;
        goto shared_B465;
    }
    uint8_t value38 = RAM8(0x0001 + direct_page_b44f);
    if (((value38 << 8) | 0x2C) == RAM16(0xE01A + x_b44f)) {
        a_hi_b4652 = value38;
        y_b4652 = (value37 << 8) | value36;
        overflow_b4652 = overflow_b44f;
        direct_page_b4652 = direct_page_b44f;
        data_bank_b4652 = data_bank_b44f;
        goto shared_B465_1;
    }
    a_hi_b3ba = value38;
    x_b3ba = x_b44f;
    y_b3ba = (value37 << 8) | value36;
    overflow_b3ba = overflow_b44f;
    direct_page_b3ba = direct_page_b44f;
    data_bank_b3ba = data_bank_b44f;
    goto shared_B3BA;
    shared_B448:;
    uint8_t value40 = BUS8(c, (data_bank_b448 << 0x10) + 0x0A50 + y_b448);
    BUS8_SET(c, (data_bank_b448 << 0x10) + 0x0A50 + y_b448, (uint8_t)(a_b448 + value40));
    a_b44f = (uint8_t)(a_b448 + value40);
    a_hi_b44f = a_hi_b448;
    x_b44f = x_b448;
    overflow_b44f = ((a_b448 ^ (uint8_t)(a_b448 + value40)) & (value40 ^ (uint8_t)(a_b448 + value40)) & 0x80) != 0;
    direct_page_b44f = direct_page_b448;
    data_bank_b44f = data_bank_b448;
    goto shared_B44F;
    shared_B44F_1:;
    uint8_t value41 = RAM8(0x0000 + sp0);
    if (a_hi_b44f2 != 0x40) {
        a_hi_b4653 = a_b44f2;
        y_b4653 = value41;
        overflow_b4653 = overflow_b44f2;
        direct_page_b4653 = direct_page_b44f2;
        data_bank_b4653 = data_bank_b44f2;
        goto shared_B465_2;
    }
    uint8_t value42 = RAM8(0x0001 + direct_page_b44f2);
    if (((value42 << 8) | 0x2C) == RAM16(0xE01A + x_b44f2)) {
        a_hi_b4654 = value42;
        y_b4654 = value41;
        overflow_b4654 = overflow_b44f2;
        direct_page_b4654 = direct_page_b44f2;
        data_bank_b4654 = data_bank_b44f2;
        goto shared_B465_3;
    }
    a_hi_b3ba2 = value42;
    x_b3ba2 = x_b44f2;
    y_b3ba2 = value41;
    overflow_b3ba2 = overflow_b44f2;
    direct_page_b3ba2 = direct_page_b44f2;
    data_bank_b3ba2 = data_bank_b44f2;
    goto shared_B3BA_1;
    shared_B465:;
    if (RAM8(0x0000 + direct_page_b465) == 0) {
        uint8_t value45 = RAM8(0x0002 + direct_page_b465);
        uint8_t value46 = RAM8(0x0002 + direct_page_b465);
        RAM8(0x0002 + direct_page_b465) >>= 1;
        if (!(value46 & 0x01)) {
            uint16_t value47 = BUS16(c, 0xD27E04 + (((a_hi_b465 << 8) | (uint8_t)(value45 << 2)) & 0x3F));
            BUS16_SET(c, (data_bank_b465 << 0x10) + 0x0A5A + y_b465, value47);
            uint16_t value48 = BUS16(c, 0xD27E06 + (((a_hi_b465 << 8) | (uint8_t)(value45 << 2)) & 0x3F));
            BUS16_SET(c, (data_bank_b465 << 0x10) + 0x0A5E + y_b465, value48);
            if ((((a_hi_b465 << 8) | (uint8_t)(value45 << 2)) & 0x3F) == 0) {
                a_b4c5 = 0;
                a_hi_b4c5 = 0;
                y_b4c5 = y_b465;
                overflow_b4c5 = overflow_b465;
                direct_page_b4c5 = direct_page_b465;
                data_bank_b4c5 = data_bank_b465;
                goto shared_B4C5;
            }
            uint16_t value49 = BUS16(c, 0xD27E00 + (((a_hi_b465 << 8) | (uint8_t)(value45 << 2)) & 0x3F));
            a_b4c5 = (uint8_t)value49;
            a_hi_b4c5 = value49 >> 8;
            y_b4c5 = y_b465;
            overflow_b4c5 = overflow_b465;
            direct_page_b4c5 = direct_page_b465;
            data_bank_b4c5 = data_bank_b465;
            goto shared_B4C5;
        }
        uint16_t value50 = BUS16(c, 0xD27E04 + (((a_hi_b465 << 8) | (uint8_t)(value45 << 2)) & 0x3F));
        BUS16_SET(c, (data_bank_b465 << 0x10) + 0x0A58 + y_b465, value50);
        uint16_t value51 = BUS16(c, 0xD27E06 + (((a_hi_b465 << 8) | (uint8_t)(value45 << 2)) & 0x3F));
        BUS16_SET(c, (data_bank_b465 << 0x10) + 0x0A5C + y_b465, value51);
        uint16_t value52 = BUS16(c, 0xD27E00 + (((a_hi_b465 << 8) | (uint8_t)(value45 << 2)) & 0x3F));
        BUS16_SET(c, (data_bank_b465 << 0x10) + 0x0A5A + y_b465, value52);
        BUS16_SET(c, (data_bank_b465 << 0x10) + 0x0A5E + y_b465, value52);
        a_hi_b4cb = value52 >> 8;
        y_b4cb = y_b465;
        overflow_b4cb = overflow_b465;
        direct_page_b4cb = direct_page_b465;
        data_bank_b4cb = data_bank_b465;
        goto shared_B4CB;
    }
    uint16_t value53 = BUS16(c, 0xD27E28);
    BUS16_SET(c, (data_bank_b465 << 0x10) + 0x0A58 + y_b465, value53);
    BUS16_SET(c, (data_bank_b465 << 0x10) + 0x0A5A + y_b465, value53);
    uint16_t value54 = BUS16(c, 0xD27E2A);
    BUS16_SET(c, (data_bank_b465 << 0x10) + 0x0A5C + y_b465, value54);
    BUS16_SET(c, (data_bank_b465 << 0x10) + 0x0A5E + y_b465, value54);
    a_hi_b4cb = value54 >> 8;
    y_b4cb = y_b465;
    overflow_b4cb = overflow_b465;
    direct_page_b4cb = direct_page_b465;
    data_bank_b4cb = data_bank_b465;
    goto shared_B4CB;
    shared_B465_1:;
    if (RAM8(0x0000 + direct_page_b4652) == 0) {
        uint8_t value56 = RAM8(0x0002 + direct_page_b4652);
        uint8_t value57 = RAM8(0x0002 + direct_page_b4652);
        RAM8(0x0002 + direct_page_b4652) >>= 1;
        if (!(value57 & 0x01)) {
            uint16_t value58 = BUS16(c, 0xD27E04 + (((a_hi_b4652 << 8) | (uint8_t)(value56 << 2)) & 0x3F));
            BUS16_SET(c, (data_bank_b4652 << 0x10) + 0x0A5A + y_b4652, value58);
            uint16_t value59 = BUS16(c, 0xD27E06 + (((a_hi_b4652 << 8) | (uint8_t)(value56 << 2)) & 0x3F));
            BUS16_SET(c, (data_bank_b4652 << 0x10) + 0x0A5E + y_b4652, value59);
            if ((((a_hi_b4652 << 8) | (uint8_t)(value56 << 2)) & 0x3F) == 0) {
                a_b4c5 = 0;
                a_hi_b4c5 = 0;
                y_b4c5 = y_b4652;
                overflow_b4c5 = overflow_b4652;
                direct_page_b4c5 = direct_page_b4652;
                data_bank_b4c5 = data_bank_b4652;
                goto shared_B4C5;
            }
            uint16_t value60 = BUS16(c, 0xD27E00 + (((a_hi_b4652 << 8) | (uint8_t)(value56 << 2)) & 0x3F));
            a_b4c5 = (uint8_t)value60;
            a_hi_b4c5 = value60 >> 8;
            y_b4c5 = y_b4652;
            overflow_b4c5 = overflow_b4652;
            direct_page_b4c5 = direct_page_b4652;
            data_bank_b4c5 = data_bank_b4652;
            goto shared_B4C5;
        }
        uint16_t value61 = BUS16(c, 0xD27E04 + (((a_hi_b4652 << 8) | (uint8_t)(value56 << 2)) & 0x3F));
        BUS16_SET(c, (data_bank_b4652 << 0x10) + 0x0A58 + y_b4652, value61);
        uint16_t value62 = BUS16(c, 0xD27E06 + (((a_hi_b4652 << 8) | (uint8_t)(value56 << 2)) & 0x3F));
        BUS16_SET(c, (data_bank_b4652 << 0x10) + 0x0A5C + y_b4652, value62);
        uint16_t value63 = BUS16(c, 0xD27E00 + (((a_hi_b4652 << 8) | (uint8_t)(value56 << 2)) & 0x3F));
        BUS16_SET(c, (data_bank_b4652 << 0x10) + 0x0A5A + y_b4652, value63);
        BUS16_SET(c, (data_bank_b4652 << 0x10) + 0x0A5E + y_b4652, value63);
        a_hi_b4cb = value63 >> 8;
        y_b4cb = y_b4652;
        overflow_b4cb = overflow_b4652;
        direct_page_b4cb = direct_page_b4652;
        data_bank_b4cb = data_bank_b4652;
        goto shared_B4CB;
    }
    uint16_t value64 = BUS16(c, 0xD27E28);
    BUS16_SET(c, (data_bank_b4652 << 0x10) + 0x0A58 + y_b4652, value64);
    BUS16_SET(c, (data_bank_b4652 << 0x10) + 0x0A5A + y_b4652, value64);
    uint16_t value65 = BUS16(c, 0xD27E2A);
    BUS16_SET(c, (data_bank_b4652 << 0x10) + 0x0A5C + y_b4652, value65);
    BUS16_SET(c, (data_bank_b4652 << 0x10) + 0x0A5E + y_b4652, value65);
    a_hi_b4cb = value65 >> 8;
    y_b4cb = y_b4652;
    overflow_b4cb = overflow_b4652;
    direct_page_b4cb = direct_page_b4652;
    data_bank_b4cb = data_bank_b4652;
    goto shared_B4CB;
    shared_B465_2:;
    if (RAM8(0x0000 + direct_page_b4653) == 0) {
        uint8_t value67 = RAM8(0x0002 + direct_page_b4653);
        uint8_t value68 = RAM8(0x0002 + direct_page_b4653);
        RAM8(0x0002 + direct_page_b4653) >>= 1;
        if (!(value68 & 0x01)) {
            uint16_t value69 = BUS16(c, 0xD27E04 + (((a_hi_b4653 << 8) | (uint8_t)(value67 << 2)) & 0x3F));
            BUS16_SET(c, (data_bank_b4653 << 0x10) + 0x0A5A + y_b4653, value69);
            uint16_t value70 = BUS16(c, 0xD27E06 + (((a_hi_b4653 << 8) | (uint8_t)(value67 << 2)) & 0x3F));
            BUS16_SET(c, (data_bank_b4653 << 0x10) + 0x0A5E + y_b4653, value70);
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        }
        uint16_t value71 = BUS16(c, 0xD27E04 + (((a_hi_b4653 << 8) | (uint8_t)(value67 << 2)) & 0x3F));
        BUS16_SET(c, (data_bank_b4653 << 0x10) + 0x0A58 + y_b4653, value71);
        uint16_t value72 = BUS16(c, 0xD27E06 + (((a_hi_b4653 << 8) | (uint8_t)(value67 << 2)) & 0x3F));
        BUS16_SET(c, (data_bank_b4653 << 0x10) + 0x0A5C + y_b4653, value72);
        uint16_t value73 = BUS16(c, 0xD27E00 + (((a_hi_b4653 << 8) | (uint8_t)(value67 << 2)) & 0x3F));
        BUS16_SET(c, (data_bank_b4653 << 0x10) + 0x0A5A + y_b4653, value73);
        BUS16_SET(c, (data_bank_b4653 << 0x10) + 0x0A5E + y_b4653, value73);
        a_hi_b4cb3 = value73 >> 8;
        y_b4cb3 = y_b4653;
        overflow_b4cb3 = overflow_b4653;
        direct_page_b4cb3 = direct_page_b4653;
        data_bank_b4cb3 = data_bank_b4653;
        goto shared_B4CB_2;
    }
    uint16_t value74 = BUS16(c, 0xD27E28);
    BUS16_SET(c, (data_bank_b4653 << 0x10) + 0x0A58 + y_b4653, value74);
    BUS16_SET(c, (data_bank_b4653 << 0x10) + 0x0A5A + y_b4653, value74);
    uint16_t value75 = BUS16(c, 0xD27E2A);
    BUS16_SET(c, (data_bank_b4653 << 0x10) + 0x0A5C + y_b4653, value75);
    BUS16_SET(c, (data_bank_b4653 << 0x10) + 0x0A5E + y_b4653, value75);
    a_hi_b4cb3 = value75 >> 8;
    y_b4cb3 = y_b4653;
    overflow_b4cb3 = overflow_b4653;
    direct_page_b4cb3 = direct_page_b4653;
    data_bank_b4cb3 = data_bank_b4653;
    goto shared_B4CB_2;
    shared_B465_3:;
    if (RAM8(0x0000 + direct_page_b4654) == 0) {
        uint8_t value77 = RAM8(0x0002 + direct_page_b4654);
        uint8_t value78 = RAM8(0x0002 + direct_page_b4654);
        RAM8(0x0002 + direct_page_b4654) >>= 1;
        if (!(value78 & 0x01)) {
            uint16_t value79 = BUS16(c, 0xD27E04 + (((a_hi_b4654 << 8) | (uint8_t)(value77 << 2)) & 0x3F));
            BUS16_SET(c, (data_bank_b4654 << 0x10) + 0x0A5A + y_b4654, value79);
            uint16_t value80 = BUS16(c, 0xD27E06 + (((a_hi_b4654 << 8) | (uint8_t)(value77 << 2)) & 0x3F));
            BUS16_SET(c, (data_bank_b4654 << 0x10) + 0x0A5E + y_b4654, value80);
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        }
        uint16_t value81 = BUS16(c, 0xD27E04 + (((a_hi_b4654 << 8) | (uint8_t)(value77 << 2)) & 0x3F));
        BUS16_SET(c, (data_bank_b4654 << 0x10) + 0x0A58 + y_b4654, value81);
        uint16_t value82 = BUS16(c, 0xD27E06 + (((a_hi_b4654 << 8) | (uint8_t)(value77 << 2)) & 0x3F));
        BUS16_SET(c, (data_bank_b4654 << 0x10) + 0x0A5C + y_b4654, value82);
        uint16_t value83 = BUS16(c, 0xD27E00 + (((a_hi_b4654 << 8) | (uint8_t)(value77 << 2)) & 0x3F));
        BUS16_SET(c, (data_bank_b4654 << 0x10) + 0x0A5A + y_b4654, value83);
        BUS16_SET(c, (data_bank_b4654 << 0x10) + 0x0A5E + y_b4654, value83);
        a_hi_b4cb3 = value83 >> 8;
        y_b4cb3 = y_b4654;
        overflow_b4cb3 = overflow_b4654;
        direct_page_b4cb3 = direct_page_b4654;
        data_bank_b4cb3 = data_bank_b4654;
        goto shared_B4CB_2;
    }
    uint16_t value84 = BUS16(c, 0xD27E28);
    BUS16_SET(c, (data_bank_b4654 << 0x10) + 0x0A58 + y_b4654, value84);
    BUS16_SET(c, (data_bank_b4654 << 0x10) + 0x0A5A + y_b4654, value84);
    uint16_t value85 = BUS16(c, 0xD27E2A);
    BUS16_SET(c, (data_bank_b4654 << 0x10) + 0x0A5C + y_b4654, value85);
    BUS16_SET(c, (data_bank_b4654 << 0x10) + 0x0A5E + y_b4654, value85);
    a_hi_b4cb3 = value85 >> 8;
    y_b4cb3 = y_b4654;
    overflow_b4cb3 = overflow_b4654;
    direct_page_b4cb3 = direct_page_b4654;
    data_bank_b4cb3 = data_bank_b4654;
    goto shared_B4CB_2;
    shared_B3BA_1:;
    uint16_t value86 = RAM16(0xE01A + x_b3ba2);
    RAM16_SET(0x0002 + direct_page_b3ba2, ((uint8_t)value86 << 8) | (value86 >> 8));
    RAM16_SET(0x0003 + direct_page_b3ba2, ((uint8_t)value86 << 8) | (value86 >> 8));
    if ((uint8_t)((uint8_t)value86 + 1) < 0x2D) {
        a_b3df2 = (uint8_t)((uint8_t)value86 + 1);
        a_hi_b3df2 = value86 >> 8;
        x_b3df2 = x_b3ba2;
        y_b3df2 = y_b3ba2;
        overflow_b3df2 = overflow_b3ba2;
        direct_page_b3df2 = direct_page_b3ba2;
        data_bank_b3df2 = data_bank_b3ba2;
        goto shared_B3DF_1;
    }
    r->a = (value86 >> 8 << 8) | 0xA8;
    r->x = x_b3ba2;
    r->y = y_b3ba2;
    r->v = overflow_b3ba2;
    r->mf = true;
    r->xf = true;
    r->db = data_bank_b3ba2;
    r->dp = direct_page_b3ba2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB3CF, 0xC0BB27); GUARD_JSR(c, sp_call, 0xB3CF); } /* publish_charge_sound_only_for_controlled_hero */
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret4 = r->db;
    bool x_ret4 = r->xf;
    uint16_t a_all4 = r->a;
    RAM8(0x0002 + dp_ret4) = (uint8_t)((a_all4 >> 8) + 1);
    if ((uint8_t)((a_all4 >> 8) + 1) < RAM8(0x0001 + dp_ret4)) {
        if (x_ret4) {
            a_b3df2 = 0;
            a_hi_b3df2 = (uint8_t)((a_all4 >> 8) + 1);
            x_b3df2 = x_b3ba2;
            y_b3df2 = y_b3ba2;
            overflow_b3df2 = overflow_b3ba2;
            direct_page_b3df2 = dp_ret4;
            data_bank_b3df2 = db_ret4;
            goto shared_B3DF_1;
        } else {
            a_b3df = 0;
            a_hi_b3df = (uint8_t)((a_all4 >> 8) + 1);
            x_b3df = x_b3ba2;
            y_b3df = y_b3ba2;
            overflow_b3df = overflow_b3ba2;
            direct_page_b3df = dp_ret4;
            data_bank_b3df = db_ret4;
            goto shared_B3DF;
        }
    }
    RAM8(0x0000 + dp_ret4)++;
    if (x_ret4) {
        a_b3df2 = 0x2C;
        a_hi_b3df2 = (uint8_t)((a_all4 >> 8) + 1);
        x_b3df2 = x_b3ba2;
        y_b3df2 = y_b3ba2;
        overflow_b3df2 = overflow_b3ba2;
        direct_page_b3df2 = dp_ret4;
        data_bank_b3df2 = db_ret4;
        goto shared_B3DF_1;
    } else {
        a_b3df = 0x2C;
        a_hi_b3df = (uint8_t)((a_all4 >> 8) + 1);
        x_b3df = x_b3ba2;
        y_b3df = y_b3ba2;
        overflow_b3df = overflow_b3ba2;
        direct_page_b3df = dp_ret4;
        data_bank_b3df = db_ret4;
        goto shared_B3DF;
    }
    shared_B4C5:;
    BUS16_SET(c, (data_bank_b4c5 << 0x10) + 0x0A58 + y_b4c5, (a_hi_b4c5 << 8) | a_b4c5);
    BUS16_SET(c, (data_bank_b4c5 << 0x10) + 0x0A5C + y_b4c5, (a_hi_b4c5 << 8) | a_b4c5);
    a_hi_b4cb = a_hi_b4c5;
    y_b4cb = y_b4c5;
    overflow_b4cb = overflow_b4c5;
    direct_page_b4cb = direct_page_b4c5;
    data_bank_b4cb = data_bank_b4c5;
    goto shared_B4CB;
    shared_B4CB_2:;
    uint16_t value88 = RAM16(0x00F4 + direct_page_b4cb3);
    if (!(value88 & 0x01)) {
        a_hi_b4d92 = value88 >> 1 >> 8;
        x_b4d92 = y_b4cb3 >> 1;
        y_b4d92 = y_b4cb3;
        carry_b4d92 = value88 & 0x01;
        overflow_b4d92 = overflow_b4cb3;
        direct_page_b4d92 = direct_page_b4cb3;
        data_bank_b4d92 = data_bank_b4cb3;
        goto shared_B4D9_1;
    }
    a_hi_b4d92 = value88 >> 1 >> 8;
    x_b4d92 = y_b4cb3 >> 1;
    y_b4d92 = (uint8_t)(y_b4cb3 + 4);
    carry_b4d92 = value88 & 0x01;
    overflow_b4d92 = overflow_b4cb3;
    direct_page_b4d92 = direct_page_b4cb3;
    data_bank_b4d92 = data_bank_b4cb3;
    goto shared_B4D9_1;
    shared_B4D9_1:;
    if ((RAM16(0x1D04) & 0x20) != 0) {
        uint16_t value90 = BUS16(c, (data_bank_b4d92 << 0x10) + 0x0A58 + y_b4d92);
        RAM16_SET(0xDE0C + x_b4d92, value90);
        uint16_t value91 = BUS16(c, (data_bank_b4d92 << 0x10) + 0x0A5A + y_b4d92);
        RAM16_SET(0xDE0E + x_b4d92, value91);
        r->a = value91;
        r->x = x_b4d92;
        r->y = y_b4d92;
        r->c = carry_b4d92;
        r->v = overflow_b4d92;
        r->mf = false;
        r->xf = true;
        r->db = data_bank_b4d92;
        r->dp = direct_page_b4d92;
        RETURN_RTS(c);
    }
    uint16_t value92 = BUS16(c, (data_bank_b4d92 << 0x10) + 0x0A58 + y_b4d92);
    BUS16_SET(c, (data_bank_b4d92 << 0x10) + 0x060C + x_b4d92, value92);
    uint16_t value93 = BUS16(c, (data_bank_b4d92 << 0x10) + 0x0A5A + y_b4d92);
    BUS16_SET(c, (data_bank_b4d92 << 0x10) + 0x060E + x_b4d92, value93);
    r->a = value93;
    r->x = x_b4d92;
    r->y = y_b4d92;
    r->c = carry_b4d92;
    r->v = overflow_b4d92;
    r->mf = false;
    r->xf = true;
    r->db = data_bank_b4d92;
    r->dp = direct_page_b4d92;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0B330, SOM_RTS, "hand", advance_selected_hero_charge_timing_and_publish_native_gauge, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 462, 198)
