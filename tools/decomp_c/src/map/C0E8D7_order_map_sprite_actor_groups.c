#include "som_c.h"

/* C0E8D7 order_map_sprite_actor_groups   [class C, 285 bytes, 142 instructions]
 * Source: src/rom/order_map_sprite_actor_groups.s
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCV.
 */
static void order_map_sprite_actor_groups(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint8_t a_hi_e8f8 = 0;
    uint16_t x_e8f8 = 0;
    uint16_t y_e8f8 = 0;
    uint8_t a_hi_e903 = 0;
    uint16_t y_e903 = 0;
    uint16_t direct_page_e903 = 0;
    uint8_t a_hi_e92b = 0;
    uint16_t x_e92b = 0;
    uint16_t y_e92b = 0;
    uint16_t direct_page_e92b = 0;
    uint8_t a_hi_e9032 = 0;
    uint16_t y_e9032 = 0;
    uint16_t direct_page_e9032 = 0;
    uint8_t a_e911 = 0;
    uint8_t a_hi_e911 = 0;
    uint16_t y_e911 = 0;
    uint16_t direct_page_e911 = 0;
    uint8_t a_hi_e8f82 = 0;
    uint16_t x_e8f82 = 0;
    uint16_t y_e8f82 = 0;
    uint16_t direct_page_e8f8 = 0;
    uint8_t a_e923 = 0;
    uint8_t a_hi_e923 = 0;
    uint16_t x_e923 = 0;
    uint16_t y_e923 = 0;
    uint16_t direct_page_e923 = 0;
    uint8_t a_e919 = 0;
    uint8_t a_hi_e919 = 0;
    uint16_t x_e919 = 0;
    uint16_t y_e919 = 0;
    uint16_t direct_page_e919 = 0;
    uint8_t a_hi_e927 = 0;
    uint16_t x_e927 = 0;
    uint16_t y_e927 = 0;
    uint16_t direct_page_e927 = 0;
    uint8_t a_e936 = 0;
    uint8_t a_hi_e936 = 0;
    uint16_t x_e936 = 0;
    uint16_t y_e936 = 0;
    uint16_t direct_page_e936 = 0;
    uint8_t a_hi_e9e4 = 0;
    uint16_t x_e9e4 = 0;
    uint16_t y_e9e4 = 0;
    uint16_t direct_page_e9e4 = 0;
    uint8_t a_hi_e9a4 = 0;
    uint16_t x_e9a4 = 0;
    uint16_t y_e9a4 = 0;
    uint16_t direct_page_e9a4 = 0;
    uint8_t a_hi_e984 = 0;
    uint16_t x_e984 = 0;
    uint16_t y_e984 = 0;
    uint16_t direct_page_e984 = 0;
    uint8_t a_hi_e99c = 0;
    uint16_t x_e99c = 0;
    uint16_t y_e99c = 0;
    uint16_t direct_page_e99c = 0;
    uint8_t a_hi_e994 = 0;
    uint16_t x_e994 = 0;
    uint16_t y_e994 = 0;
    uint16_t direct_page_e994 = 0;
    uint8_t a_hi_e98c = 0;
    uint16_t x_e98c = 0;
    uint16_t y_e98c = 0;
    uint16_t direct_page_e98c = 0;
    uint8_t a_hi_e9c4 = 0;
    uint16_t x_e9c4 = 0;
    uint16_t y_e9c4 = 0;
    uint16_t direct_page_e9c4 = 0;
    uint8_t a_hi_e9bc = 0;
    uint16_t x_e9bc = 0;
    uint16_t y_e9bc = 0;
    uint16_t direct_page_e9bc = 0;
    uint8_t a_hi_e9b4 = 0;
    uint16_t x_e9b4 = 0;
    uint16_t y_e9b4 = 0;
    uint16_t direct_page_e9b4 = 0;
    uint8_t a_hi_e9ac = 0;
    uint16_t x_e9ac = 0;
    uint16_t y_e9ac = 0;
    uint16_t direct_page_e9ac = 0;
    uint8_t a_hi_e9d4 = 0;
    uint16_t x_e9d4 = 0;
    uint16_t y_e9d4 = 0;
    uint16_t direct_page_e9d4 = 0;
    uint8_t a_hi_e9cc = 0;
    uint16_t x_e9cc = 0;
    uint16_t y_e9cc = 0;
    uint16_t direct_page_e9cc = 0;
    uint8_t a_hi_e9dc = 0;
    uint16_t x_e9dc = 0;
    uint16_t y_e9dc = 0;
    uint16_t direct_page_e9dc = 0;
    RAM8(0x0000 + sp0) = db;
    RAM8(0x0000 + sp0 - 1) = dp >> 8;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM16_SET(0x053E, 0);
    RAM16_SET(0x057E, 0);
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0xED));
    if (!(value & 0x80)) {
        a_hi_e8f8 = a >> 8;
        x_e8f8 = x;
        y_e8f8 = 0x1600;
        goto shared_E8F8;
    }
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp + 0x5C));
    if (value2 & 0x80) {
        a_hi_e8f8 = a >> 8;
        x_e8f8 = x;
        y_e8f8 = 0x1600;
        goto shared_E8F8;
    }
    a_hi_e8f8 = a >> 8;
    x_e8f8 = x;
    y_e8f8 = 0x0A00;
    shared_E8F8:;
    uint8_t value3 = RAM8(0xE000 + y_e8f8);
    if (value3 != 0) {
        a_hi_e903 = a_hi_e8f8;
        y_e903 = y_e8f8;
        direct_page_e903 = dp;
        goto shared_E903;
    }
    if (value3 == 0) {
        a_hi_e92b = a_hi_e8f8;
        x_e92b = x_e8f8;
        y_e92b = y_e8f8;
        direct_page_e92b = dp;
        goto shared_E92B;
    }
    a_hi_e9032 = a_hi_e8f8;
    y_e9032 = y_e8f8;
    direct_page_e9032 = dp;
    goto shared_E903_1;
    shared_E903:;
    if (!(RAM8(0xE00B + y_e903) & 0x01)) {
        a_e911 = 0;
        a_hi_e911 = 5;
        y_e911 = y_e903;
        direct_page_e911 = direct_page_e903;
        goto shared_E911;
    }
    a_e911 = 0x40;
    a_hi_e911 = 5;
    y_e911 = y_e903;
    direct_page_e911 = direct_page_e903;
    goto shared_E911;
    shared_E92B:;
    if (!((uint16_t)(y_e92b - 0x0200) & 0x8000)) {
        a_hi_e8f82 = (uint16_t)(y_e92b - 0x0200) >> 8;
        x_e8f82 = x_e92b;
        y_e8f82 = (uint16_t)(y_e92b - 0x0200);
        direct_page_e8f8 = direct_page_e92b;
        goto shared_E8F8_1;
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 2);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)(y_e92b - 0x0200);
    r->x = x_e92b;
    r->y = (uint16_t)(y_e92b - 0x0200);
    r->c = y_e92b >= 0x0200;
    r->v = ((y_e92b ^ 0x0200) & (y_e92b ^ (uint16_t)(y_e92b - 0x0200)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = value7;
    r->dp = (value6 << 8) | value5;
    RETURN_RTS(c);
    shared_E903_1:;
    if (!(RAM16(0xE00B + y_e9032) & 0x01)) {
        a_e911 = 0;
        a_hi_e911 = 5;
        y_e911 = y_e9032;
        direct_page_e911 = direct_page_e9032;
        goto shared_E911;
    }
    a_e911 = 0x40;
    a_hi_e911 = 5;
    y_e911 = y_e9032;
    direct_page_e911 = direct_page_e9032;
    goto shared_E911;
    shared_E911:;
    uint16_t value9 = RAM16(0xE022 + y_e911);
    uint16_t value10 = BUS16_RDP(c, (uint16_t)(((a_hi_e911 << 8) | a_e911) + 0x3E));
    if (value10 == 0) {
        a_e923 = (uint8_t)value9;
        a_hi_e923 = value9 >> 8;
        x_e923 = value10;
        y_e923 = y_e911;
        direct_page_e923 = (a_hi_e911 << 8) | a_e911;
        goto shared_E923;
    }
    a_e919 = (uint8_t)value9;
    a_hi_e919 = value9 >> 8;
    x_e919 = value10;
    y_e919 = y_e911;
    direct_page_e919 = (a_hi_e911 << 8) | a_e911;
    goto shared_E919;
    shared_E8F8_1:;
    uint8_t value11 = RAM8(0xE000 + y_e8f82);
    if (value11 != 0) {
        a_hi_e903 = a_hi_e8f82;
        y_e903 = y_e8f82;
        direct_page_e903 = direct_page_e8f8;
        goto shared_E903;
    }
    if (value11 == 0) {
        a_hi_e92b = a_hi_e8f82;
        x_e92b = x_e8f82;
        y_e92b = y_e8f82;
        direct_page_e92b = direct_page_e8f8;
        goto shared_E92B;
    }
    a_hi_e9032 = a_hi_e8f82;
    y_e9032 = y_e8f82;
    direct_page_e9032 = direct_page_e8f8;
    goto shared_E903_1;
    shared_E923:;
    BUS16_SET(c, (uint16_t)(direct_page_e923 + 0x20 + x_e923), (a_hi_e923 << 8) | a_e923);
    BUS16_SET(c, (uint16_t)(direct_page_e923 + x_e923), y_e923);
    a_hi_e927 = a_hi_e923;
    x_e927 = x_e923;
    y_e927 = y_e923;
    direct_page_e927 = direct_page_e923;
    goto shared_E927;
    shared_E919:;
    uint16_t value12 = BUS16_RDP(c, (uint16_t)(direct_page_e919 + 0x1E + x_e919));
    if (((a_hi_e919 << 8) | a_e919) >= value12) {
        a_e936 = a_e919;
        a_hi_e936 = a_hi_e919;
        x_e936 = x_e919;
        y_e936 = y_e919;
        direct_page_e936 = direct_page_e919;
        goto shared_E936;
    }
    if ((uint16_t)(x_e919 - 2) != 0) {
        x_e919 = (uint16_t)(x_e919 - 2);
        goto shared_E919;
    }
    if ((uint16_t)(x_e919 - 2) == 0) {
        a_e936 = a_e919;
        a_hi_e936 = a_hi_e919;
        x_e936 = (uint16_t)(x_e919 - 2);
        y_e936 = y_e919;
        direct_page_e936 = direct_page_e919;
        goto shared_E936;
    }
    a_e923 = a_e919;
    a_hi_e923 = a_hi_e919;
    x_e923 = (uint16_t)(x_e919 - 2);
    y_e923 = y_e919;
    direct_page_e923 = direct_page_e919;
    goto shared_E923;
    shared_E927:;
    uint16_t value13 = BUS16_RDP(c, (uint16_t)(direct_page_e927 + 0x3E));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_e927 + 0x3E), (uint16_t)(value13 + 1));
    uint16_t value14 = BUS16_RDP(c, (uint16_t)(direct_page_e927 + 0x3E));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_e927 + 0x3E), (uint16_t)(value14 + 1));
    a_hi_e92b = a_hi_e927;
    x_e92b = x_e927;
    y_e92b = y_e927;
    direct_page_e92b = direct_page_e927;
    goto shared_E92B;
    shared_E936:;
    uint16_t value15 = BUS16_RDP(c, (uint16_t)(direct_page_e936 + 0x3E));
    if (x_e936 == value15) {
        a_e923 = a_e936;
        a_hi_e923 = a_hi_e936;
        x_e923 = x_e936;
        y_e923 = y_e936;
        direct_page_e923 = direct_page_e936;
        goto shared_E923;
    }
    BUS16_SET(c, (uint16_t)(direct_page_e936 + 0x1E), x_e936);
    RAM8(0x0000 + sp0 - 3) = a_hi_e936;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi_e936 << 8) | a_e936);
    uint16_t value16 = BUS16_RDP(c, (uint16_t)(direct_page_e936 + 0x3E));
    uint16_t value17 = BUS16_RDP(c, (uint16_t)(direct_page_e936 + 0x1E));
    if ((uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) == 0) {
        a_hi_e9e4 = (uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >> 8;
        x_e9e4 = x_e936;
        y_e9e4 = y_e936;
        direct_page_e9e4 = direct_page_e936;
        goto shared_E9E4;
    }
    if ((uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >= 8) {
        if ((uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) == 8) {
            a_hi_e9a4 = (uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >> 8;
            x_e9a4 = x_e936;
            y_e9a4 = y_e936;
            direct_page_e9a4 = direct_page_e936;
            goto shared_E9A4;
        }
        if ((uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >= 0x0C) {
            if ((uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) == 0x0C) {
                a_hi_e984 = (uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >> 8;
                x_e984 = x_e936;
                y_e984 = y_e936;
                direct_page_e984 = direct_page_e936;
                goto shared_E984;
            }
            uint16_t value18 = BUS16_RDP(c, (uint16_t)(direct_page_e936 + 0x1A + x_e936));
            BUS16_SET(c, (uint16_t)(direct_page_e936 + 0x1C + x_e936), value18);
            uint16_t value19 = BUS16_RDP(c, (uint16_t)(direct_page_e936 + 0x3A + x_e936));
            BUS16_SET(c, (uint16_t)(direct_page_e936 + 0x3C + x_e936), value19);
            a_hi_e984 = value19 >> 8;
            x_e984 = x_e936;
            y_e984 = y_e936;
            direct_page_e984 = direct_page_e936;
            goto shared_E984;
        }
        if ((uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) < 0x0A) {
            a_hi_e99c = (uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >> 8;
            x_e99c = x_e936;
            y_e99c = y_e936;
            direct_page_e99c = direct_page_e936;
            goto shared_E99C;
        }
        if ((uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) == 0x0A) {
            a_hi_e994 = (uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >> 8;
            x_e994 = x_e936;
            y_e994 = y_e936;
            direct_page_e994 = direct_page_e936;
            goto shared_E994;
        }
        a_hi_e98c = (uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >> 8;
        x_e98c = x_e936;
        y_e98c = y_e936;
        direct_page_e98c = direct_page_e936;
        goto shared_E98C;
    }
    if ((uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >= 4) {
        if ((uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) == 4) {
            a_hi_e9c4 = (uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >> 8;
            x_e9c4 = x_e936;
            y_e9c4 = y_e936;
            direct_page_e9c4 = direct_page_e936;
            goto shared_E9C4;
        }
        if ((uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) < 6) {
            a_hi_e9bc = (uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >> 8;
            x_e9bc = x_e936;
            y_e9bc = y_e936;
            direct_page_e9bc = direct_page_e936;
            goto shared_E9BC;
        }
        if ((uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) == 6) {
            a_hi_e9b4 = (uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >> 8;
            x_e9b4 = x_e936;
            y_e9b4 = y_e936;
            direct_page_e9b4 = direct_page_e936;
            goto shared_E9B4;
        }
        a_hi_e9ac = (uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >> 8;
        x_e9ac = x_e936;
        y_e9ac = y_e936;
        direct_page_e9ac = direct_page_e936;
        goto shared_E9AC;
    }
    if ((uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >= 2) {
        if ((uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) == 2) {
            a_hi_e9d4 = (uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >> 8;
            x_e9d4 = x_e936;
            y_e9d4 = y_e936;
            direct_page_e9d4 = direct_page_e936;
            goto shared_E9D4;
        }
        a_hi_e9cc = (uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >> 8;
        x_e9cc = x_e936;
        y_e9cc = y_e936;
        direct_page_e9cc = direct_page_e936;
        goto shared_E9CC;
    }
    a_hi_e9dc = (uint16_t)(((uint16_t)(value16 - value17) >> 1) - 1) >> 8;
    x_e9dc = x_e936;
    y_e9dc = y_e936;
    direct_page_e9dc = direct_page_e936;
    goto shared_E9DC;
    shared_E9E4:;
    uint16_t value20 = BUS16_RDP(c, (uint16_t)(direct_page_e9e4 + x_e9e4));
    BUS16_SET(c, (uint16_t)(direct_page_e9e4 + 2 + x_e9e4), value20);
    uint16_t value21 = BUS16_RDP(c, (uint16_t)(direct_page_e9e4 + 0x20 + x_e9e4));
    BUS16_SET(c, (uint16_t)(direct_page_e9e4 + 0x22 + x_e9e4), value21);
    uint8_t value22 = RAM8(0x0000 + sp0 - 4);
    uint8_t value23 = RAM8(0x0000 + sp0 - 3);
    BUS16_SET(c, (uint16_t)(direct_page_e9e4 + 0x20 + x_e9e4), (value23 << 8) | value22);
    BUS16_SET(c, (uint16_t)(direct_page_e9e4 + x_e9e4), y_e9e4);
    a_hi_e927 = value23;
    x_e927 = x_e9e4;
    y_e927 = y_e9e4;
    direct_page_e927 = direct_page_e9e4;
    goto shared_E927;
    shared_E9A4:;
    uint16_t value24 = BUS16_RDP(c, (uint16_t)(direct_page_e9a4 + 0x10 + x_e9a4));
    BUS16_SET(c, (uint16_t)(direct_page_e9a4 + 0x12 + x_e9a4), value24);
    uint16_t value25 = BUS16_RDP(c, (uint16_t)(direct_page_e9a4 + 0x30 + x_e9a4));
    BUS16_SET(c, (uint16_t)(direct_page_e9a4 + 0x32 + x_e9a4), value25);
    a_hi_e9ac = value25 >> 8;
    x_e9ac = x_e9a4;
    y_e9ac = y_e9a4;
    direct_page_e9ac = direct_page_e9a4;
    goto shared_E9AC;
    shared_E984:;
    uint16_t value26 = BUS16_RDP(c, (uint16_t)(direct_page_e984 + 0x18 + x_e984));
    BUS16_SET(c, (uint16_t)(direct_page_e984 + 0x1A + x_e984), value26);
    uint16_t value27 = BUS16_RDP(c, (uint16_t)(direct_page_e984 + 0x38 + x_e984));
    BUS16_SET(c, (uint16_t)(direct_page_e984 + 0x3A + x_e984), value27);
    a_hi_e98c = value27 >> 8;
    x_e98c = x_e984;
    y_e98c = y_e984;
    direct_page_e98c = direct_page_e984;
    goto shared_E98C;
    shared_E99C:;
    uint16_t value28 = BUS16_RDP(c, (uint16_t)(direct_page_e99c + 0x12 + x_e99c));
    BUS16_SET(c, (uint16_t)(direct_page_e99c + 0x14 + x_e99c), value28);
    uint16_t value29 = BUS16_RDP(c, (uint16_t)(direct_page_e99c + 0x32 + x_e99c));
    BUS16_SET(c, (uint16_t)(direct_page_e99c + 0x34 + x_e99c), value29);
    a_hi_e9a4 = value29 >> 8;
    x_e9a4 = x_e99c;
    y_e9a4 = y_e99c;
    direct_page_e9a4 = direct_page_e99c;
    goto shared_E9A4;
    shared_E994:;
    uint16_t value30 = BUS16_RDP(c, (uint16_t)(direct_page_e994 + 0x14 + x_e994));
    BUS16_SET(c, (uint16_t)(direct_page_e994 + 0x16 + x_e994), value30);
    uint16_t value31 = BUS16_RDP(c, (uint16_t)(direct_page_e994 + 0x34 + x_e994));
    BUS16_SET(c, (uint16_t)(direct_page_e994 + 0x36 + x_e994), value31);
    a_hi_e99c = value31 >> 8;
    x_e99c = x_e994;
    y_e99c = y_e994;
    direct_page_e99c = direct_page_e994;
    goto shared_E99C;
    shared_E98C:;
    uint16_t value32 = BUS16_RDP(c, (uint16_t)(direct_page_e98c + 0x16 + x_e98c));
    BUS16_SET(c, (uint16_t)(direct_page_e98c + 0x18 + x_e98c), value32);
    uint16_t value33 = BUS16_RDP(c, (uint16_t)(direct_page_e98c + 0x36 + x_e98c));
    BUS16_SET(c, (uint16_t)(direct_page_e98c + 0x38 + x_e98c), value33);
    a_hi_e994 = value33 >> 8;
    x_e994 = x_e98c;
    y_e994 = y_e98c;
    direct_page_e994 = direct_page_e98c;
    goto shared_E994;
    shared_E9C4:;
    uint16_t value34 = BUS16_RDP(c, (uint16_t)(direct_page_e9c4 + 8 + x_e9c4));
    BUS16_SET(c, (uint16_t)(direct_page_e9c4 + 0x0A + x_e9c4), value34);
    uint16_t value35 = BUS16_RDP(c, (uint16_t)(direct_page_e9c4 + 0x28 + x_e9c4));
    BUS16_SET(c, (uint16_t)(direct_page_e9c4 + 0x2A + x_e9c4), value35);
    a_hi_e9cc = value35 >> 8;
    x_e9cc = x_e9c4;
    y_e9cc = y_e9c4;
    direct_page_e9cc = direct_page_e9c4;
    goto shared_E9CC;
    shared_E9BC:;
    uint16_t value36 = BUS16_RDP(c, (uint16_t)(direct_page_e9bc + 0x0A + x_e9bc));
    BUS16_SET(c, (uint16_t)(direct_page_e9bc + 0x0C + x_e9bc), value36);
    uint16_t value37 = BUS16_RDP(c, (uint16_t)(direct_page_e9bc + 0x2A + x_e9bc));
    BUS16_SET(c, (uint16_t)(direct_page_e9bc + 0x2C + x_e9bc), value37);
    a_hi_e9c4 = value37 >> 8;
    x_e9c4 = x_e9bc;
    y_e9c4 = y_e9bc;
    direct_page_e9c4 = direct_page_e9bc;
    goto shared_E9C4;
    shared_E9B4:;
    uint16_t value38 = BUS16_RDP(c, (uint16_t)(direct_page_e9b4 + 0x0C + x_e9b4));
    BUS16_SET(c, (uint16_t)(direct_page_e9b4 + 0x0E + x_e9b4), value38);
    uint16_t value39 = BUS16_RDP(c, (uint16_t)(direct_page_e9b4 + 0x2C + x_e9b4));
    BUS16_SET(c, (uint16_t)(direct_page_e9b4 + 0x2E + x_e9b4), value39);
    a_hi_e9bc = value39 >> 8;
    x_e9bc = x_e9b4;
    y_e9bc = y_e9b4;
    direct_page_e9bc = direct_page_e9b4;
    goto shared_E9BC;
    shared_E9AC:;
    uint16_t value40 = BUS16_RDP(c, (uint16_t)(direct_page_e9ac + 0x0E + x_e9ac));
    BUS16_SET(c, (uint16_t)(direct_page_e9ac + 0x10 + x_e9ac), value40);
    uint16_t value41 = BUS16_RDP(c, (uint16_t)(direct_page_e9ac + 0x2E + x_e9ac));
    BUS16_SET(c, (uint16_t)(direct_page_e9ac + 0x30 + x_e9ac), value41);
    a_hi_e9b4 = value41 >> 8;
    x_e9b4 = x_e9ac;
    y_e9b4 = y_e9ac;
    direct_page_e9b4 = direct_page_e9ac;
    goto shared_E9B4;
    shared_E9D4:;
    uint16_t value42 = BUS16_RDP(c, (uint16_t)(direct_page_e9d4 + 4 + x_e9d4));
    BUS16_SET(c, (uint16_t)(direct_page_e9d4 + 6 + x_e9d4), value42);
    uint16_t value43 = BUS16_RDP(c, (uint16_t)(direct_page_e9d4 + 0x24 + x_e9d4));
    BUS16_SET(c, (uint16_t)(direct_page_e9d4 + 0x26 + x_e9d4), value43);
    a_hi_e9dc = value43 >> 8;
    x_e9dc = x_e9d4;
    y_e9dc = y_e9d4;
    direct_page_e9dc = direct_page_e9d4;
    goto shared_E9DC;
    shared_E9CC:;
    uint16_t value44 = BUS16_RDP(c, (uint16_t)(direct_page_e9cc + 6 + x_e9cc));
    BUS16_SET(c, (uint16_t)(direct_page_e9cc + 8 + x_e9cc), value44);
    uint16_t value45 = BUS16_RDP(c, (uint16_t)(direct_page_e9cc + 0x26 + x_e9cc));
    BUS16_SET(c, (uint16_t)(direct_page_e9cc + 0x28 + x_e9cc), value45);
    a_hi_e9d4 = value45 >> 8;
    x_e9d4 = x_e9cc;
    y_e9d4 = y_e9cc;
    direct_page_e9d4 = direct_page_e9cc;
    goto shared_E9D4;
    shared_E9DC:;
    uint16_t value46 = BUS16_RDP(c, (uint16_t)(direct_page_e9dc + 2 + x_e9dc));
    BUS16_SET(c, (uint16_t)(direct_page_e9dc + 4 + x_e9dc), value46);
    uint16_t value47 = BUS16_RDP(c, (uint16_t)(direct_page_e9dc + 0x22 + x_e9dc));
    BUS16_SET(c, (uint16_t)(direct_page_e9dc + 0x24 + x_e9dc), value47);
    a_hi_e9e4 = value47 >> 8;
    x_e9e4 = x_e9dc;
    y_e9e4 = y_e9dc;
    direct_page_e9e4 = direct_page_e9dc;
    goto shared_E9E4;
}
SOM_REGISTER(0xC0E8D7, SOM_RTS, "gen", order_map_sprite_actor_groups, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 5, -1, -1, 285, 142)
