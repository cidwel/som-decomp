#include "som_c.h"

/* C1D107 test_hero_facing_and_contact_event_edge   [class B, 67 bytes, 36 instructions]
 * Source: src/rom/test_hero_facing_and_contact_event_edge.s
 * Documented in docs/actor-party-map-contacts.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYZ.
 */
static void test_hero_facing_and_contact_event_edge(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a_d112 = 0;
    uint8_t a_hi_d112 = 0;
    uint16_t x_d112 = 0;
    uint16_t y_d112 = 0;
    uint8_t a_d11c = 0;
    uint8_t a_hi_d11c = 0;
    uint16_t x_d11c = 0;
    uint16_t y_d11c = 0;
    bool zero_d11c = 0;
    uint8_t value = RAM8(0xE010 + x);
    if (value != 0) {
        a_d112 = value;
        a_hi_d112 = a_hi;
        x_d112 = x;
        y_d112 = y;
        goto shared_D112;
    }
    uint8_t value2 = RAM8(0x0007);
    if (value2 & 0x80) {
        r->z = 0;
        RETURN_RTS(c);
    }
    if (!(value2 & 0x80)) {
        RAM8(0x0000 + sp0) = x >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
        uint8_t a1;
        if (x >> 8 != 0) {
            a1 = x >> 8;
        } else {
            a1 = 1;
        }
        uint8_t a2;
        if (0) {
            a2 = a1;
        } else {
            a2 = (uint8_t)(a1 << 3);
        }
        RAM8(0x0000) = a2;
        uint8_t value3 = RAM8(0xE04E + y);
        bool zero1;
        if ((a2 & value3) != 0) {
            zero1 = (a2 & value3) == 0;
        } else {
            RAM8(0xE04E + y) = RAM8(0x0000) | value3;
            zero1 = 1;
        }
        r->z = zero1;
        RETURN_RTS(c);
    }
    a_d112 = value;
    a_hi_d112 = a_hi;
    x_d112 = x;
    y_d112 = y;
    shared_D112:;
    if (a_d112 >= 2) {
        a_d11c = a_d112;
        a_hi_d11c = a_hi_d112;
        x_d11c = x_d112;
        y_d11c = y_d112;
        zero_d11c = a_d112 == 2;
        goto shared_D11C;
    }
    uint8_t value5 = RAM8(0x0007);
    if (!(value5 & 0x80)) {
        r->x = x_d112;
        r->y = y_d112;
        r->z = 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    if (value5 & 0x80) {
        RAM8(0x0000 + sp0) = x_d112 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x_d112;
        uint8_t a3;
        if (x_d112 >> 8 != 0) {
            a3 = x_d112 >> 8;
        } else {
            a3 = 1;
        }
        uint8_t a4;
        if (0) {
            a4 = a3;
        } else {
            a4 = (uint8_t)(a3 << 3);
        }
        RAM8(0x0000) = a4;
        uint8_t value6 = RAM8(0xE04E + y_d112);
        bool zero2;
        if ((a4 & value6) != 0) {
            zero2 = (a4 & value6) == 0;
        } else {
            RAM8(0xE04E + y_d112) = RAM8(0x0000) | value6;
            zero2 = 1;
        }
        r->x = x_d112;
        r->y = y_d112;
        r->z = zero2;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    a_d11c = a_d112;
    a_hi_d11c = a_hi_d112;
    x_d11c = x_d112;
    y_d11c = y_d112;
    zero_d11c = (a_d112 & value5) == 0;
    goto shared_D11C;
    shared_D11C:;
    if (!zero_d11c) {
        if (!(RAM8(0x0006) & 0x80)) {
            RAM8(0x0000 + sp0) = x_d11c >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)x_d11c;
            uint8_t a5;
            if (x_d11c >> 8 != 0) {
                a5 = x_d11c >> 8;
            } else {
                a5 = 1;
            }
            uint8_t a6;
            if (0) {
                a6 = a5;
            } else {
                a6 = (uint8_t)(a5 << 3);
            }
            RAM8(0x0000) = a6;
            uint8_t value9 = RAM8(0xE04E + y_d11c);
            bool zero3;
            if ((a6 & value9) != 0) {
                zero3 = (a6 & value9) == 0;
            } else {
                RAM8(0xE04E + y_d11c) = RAM8(0x0000) | value9;
                zero3 = 1;
            }
            r->x = x_d11c;
            r->y = y_d11c;
            r->z = zero3;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        r->x = x_d11c;
        r->y = y_d11c;
        r->z = 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint8_t value11 = RAM8(0x0006);
    if (!(value11 & 0x80)) {
        r->x = x_d11c;
        r->y = y_d11c;
        r->z = 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    if (value11 & 0x80) {
        RAM8(0x0000 + sp0) = x_d11c >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x_d11c;
        uint8_t a7;
        if (x_d11c >> 8 != 0) {
            a7 = x_d11c >> 8;
        } else {
            a7 = 1;
        }
        uint8_t a8;
        if (0) {
            a8 = a7;
        } else {
            a8 = (uint8_t)(a7 << 3);
        }
        RAM8(0x0000) = a8;
        uint8_t value12 = RAM8(0xE04E + y_d11c);
        bool zero4;
        if ((a8 & value12) != 0) {
            zero4 = (a8 & value12) == 0;
        } else {
            RAM8(0xE04E + y_d11c) = RAM8(0x0000) | value12;
            zero4 = 1;
        }
        r->x = x_d11c;
        r->y = y_d11c;
        r->z = zero4;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    if (!(value11 & 0x80)) {
        RAM8(0x0000 + sp0) = x_d11c >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x_d11c;
        uint8_t a9;
        if (x_d11c >> 8 != 0) {
            a9 = x_d11c >> 8;
        } else {
            a9 = 1;
        }
        uint8_t a10;
        if (0) {
            a10 = a9;
        } else {
            a10 = (uint8_t)(a9 << 3);
        }
        RAM8(0x0000) = a10;
        uint8_t value14 = RAM8(0xE04E + y_d11c);
        bool zero5;
        if ((a10 & value14) != 0) {
            zero5 = (a10 & value14) == 0;
        } else {
            RAM8(0xE04E + y_d11c) = RAM8(0x0000) | value14;
            zero5 = 1;
        }
        r->x = x_d11c;
        r->y = y_d11c;
        r->z = zero5;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    r->x = x_d11c;
    r->y = y_d11c;
    r->z = 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1D107, SOM_RTS, "gen", test_hero_facing_and_contact_event_edge, 0, L_X | L_Y | L_Z, 2, 1, 0, 67, 36)
