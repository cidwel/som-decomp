#include "som_c.h"

/* C2C9E0 update_event_radial_window_and_wait_frame   [class D, 314 bytes, 157 instructions]
 * Source: src/rom/update_event_radial_window_and_wait_frame.s
 * Documented in docs/event-menu-effect-animation.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void update_event_radial_window_and_wait_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    BUS8_SET(c, 0x004204, 0);
    BUS8_SET(c, 0x004205, 0xFF);
    uint8_t value = RAM8(0x0018 + dp);
    uint8_t a1;
    if (value != 0) {
        a1 = value;
    } else {
        a1 = 1;
    }
    BUS8_SET(c, 0x004206, a1);
    uint8_t value2 = BUS8(c, 0x004214);
    RAM8(0x0006 + dp) = value2;
    RAM8(0x0007 + dp) = value2;
    uint8_t value3 = BUS8(c, 0x004215);
    RAM8(0x0008 + dp) = value3;
    RAM8(0x0009 + dp) = 0;
    BUS8_SET(c, 0x004202, RAM8(0x0018 + dp));
    BUS8_SET(c, 0x004203, RAM8(0xF700 + 0));
    uint8_t value6 = BUS8(c, 0x004217);
    RAM8(0xF500 + 0) = value6;
    uint8_t value7 = RAM8(0x0008 + dp);
    uint8_t a_hi1 = 0;
    uint16_t x1 = 2;
    uint16_t y1 = value7;
    for (;;) {
        BUS8_SET(c, 0x004203, RAM8(0xF700 + y1));
        uint8_t value9 = BUS8(c, 0x004217);
        RAM8(0xF500 + x1) = value9;
        uint8_t value10 = RAM8(0xF4FE + x1);
        RAM8(0xF4FF + x1) = ((uint8_t)(value9 + value10) >> 1) | ((value9 + value10 > 0xFF) << 7);
        if ((uint16_t)(x1 + 2) < 0xE0) {
            uint8_t value11 = RAM8(0x0006 + dp);
            uint8_t value12 = RAM8(0x0007 + dp);
            RAM8(0x0006 + dp) = (uint8_t)(value11 + value12);
            uint8_t value13 = RAM8(0x0008 + dp);
            if ((uint8_t)y1 + value13 + (value11 + value12 > 0xFF) <= 0xFF) {
                x1 = (uint16_t)(x1 + 2);
                y1 = (a_hi1 << 8) | (uint8_t)((uint8_t)y1 + value13 + (value11 + value12 > 0xFF));
                continue;
            }
            uint16_t x2 = (uint16_t)(x1 + 1);
            for (;;) {
                RAM8(0xF500 + x2) = 0;
                x2 = (uint16_t)(x2 + 1);
                if (!(x2 < 0xE0)) break;
            }
        }
        break;
    }
    uint16_t value14 = RAM16(0x001F + dp);
    RAM8(0x0000 + sp0) = (value14 & 0xFF) << 1 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)((value14 & 0xFF) << 1);
    uint8_t a_hi2 = (value14 & 0xFF) << 1 >> 8;
    uint16_t x3 = 0;
    uint16_t y2 = (value14 & 0xFF) << 1;
    for (;;) {
        uint8_t value15 = RAM8(0x001E + dp);
        uint8_t value16 = RAM8(0xF500 + x3);
        uint8_t a2;
        if (value15 >= value16) {
            a2 = (uint8_t)(value15 - value16);
        } else {
            a2 = 0;
        }
        RAM8(0xF220 + y2) = a2;
        uint8_t value17 = RAM8(0x001E + dp);
        uint8_t a4;
        if (a2 != value17) {
            uint8_t value18 = RAM8(0xF500 + x3);
            uint8_t a3;
            if (value17 + value18 <= 0xFF) {
                a3 = (uint8_t)(value17 + value18);
            } else {
                a3 = 0xFF;
            }
            a4 = a3;
        } else {
            a4 = (uint8_t)(a2 - 1);
        }
        RAM8(0xF221 + y2) = a4;
        x3 = (uint16_t)(x3 + 1);
        y2 = (uint16_t)(y2 - 2);
        if (!(!(y2 & 0x8000))) break;
    }
    uint8_t value19 = RAM8(0x0000 + sp0 - 1);
    uint8_t value20 = RAM8(0x0000 + sp0);
    RAM8(0x0008 + dp) = (uint8_t)(0xE0 - RAM8(0x001F + dp));
    uint8_t a_hi3 = a_hi2;
    uint16_t x4 = 0;
    uint16_t y3 = (value20 << 8) | value19;
    do {
        uint8_t value22 = RAM8(0x001E + dp);
        uint8_t value23 = RAM8(0xF500 + x4);
        uint8_t a5;
        if (value22 >= value23) {
            a5 = (uint8_t)(value22 - value23);
        } else {
            a5 = 0;
        }
        RAM8(0xF220 + y3) = a5;
        uint8_t value24 = RAM8(0x001E + dp);
        uint8_t a7;
        if (a5 != value24) {
            uint8_t value25 = RAM8(0xF500 + x4);
            uint8_t a6;
            if (value24 + value25 <= 0xFF) {
                a6 = (uint8_t)(value24 + value25);
            } else {
                a6 = 0xFF;
            }
            a7 = a6;
        } else {
            a7 = (uint8_t)(a5 - 1);
        }
        RAM8(0xF221 + y3) = a7;
        RAM8(0x0008 + dp)--;
        x4 = (uint16_t)(x4 + 1);
        y3 = (uint16_t)(y3 + 2);
    } while (RAM8(0x0008 + dp) != 0);
    RAM8(0x002C + dp) = 4;
    uint8_t value26 = RAM8(0x0018 + dp);
    RAM8(0x0000 + sp0) = (value26 >> 3) | 0xE0;
    RAM8(0x00EC + dp) = 0x0C;
    bool overflow1 = 0;
    for (;;) {
        uint8_t value27 = RAM8(0x00EC + dp);
        overflow1 = value27 & 0x40;
        if (!((value27 & 0x0C) != 0)) break;
    }
    BUS8_SET(c, 0x002132, RAM8(0x0000 + sp0));
    BUS8_SET(c, 0x002125, 0x30);
    BUS8_SET(c, 0x002130, 0x20);
    BUS8_SET(c, 0x00212C, 0x13);
    BUS8_SET(c, 0x002131, 0x33);
    uint8_t a_hi4 = a_hi3;
    uint16_t x5 = 0;
    bool carry1 = value26 >> 2 & 0x01;
    for (;;) {
        uint16_t value29 = RAM16(0xF220 + x5);
        RAM16_SET(0xF020 + x5, value29);
        uint8_t a_hi4_next = value29 >> 8;
        uint16_t x5_next = (uint16_t)(x5 + 2);
        bool carry1_next = (uint16_t)(x5 + 2) >= 0x01C0;
        a_hi4 = a_hi4_next;
        x5 = x5_next;
        carry1 = carry1_next;
        if (!(x5 < 0x01C0)) break;
    }
    r->a = (a_hi4 << 8) | (uint8_t)a;
    r->x = x5;
    r->y = y3;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C9E0, SOM_RTS, "gen", update_event_radial_window_and_wait_frame, 0, L_B | L_X | L_Y | L_C | L_V, 2, -1, 0, 314, 157)
