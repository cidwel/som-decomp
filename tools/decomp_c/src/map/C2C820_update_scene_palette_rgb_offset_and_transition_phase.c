#include "som_c.h"

/* C2C820 update_scene_palette_rgb_offset_and_transition_phase   [class C, 342 bytes, 161 instructions]
 * Source: src/rom/update_scene_palette_rgb_offset_and_transition_phase.s
 * Documented in docs/event-vm-palette-transition.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void update_scene_palette_rgb_offset_and_transition_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    const bool carry = r->c;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    uint8_t value = RAM8(0x002A);
    uint16_t x1;
    if (value & 0x40) {
        x1 = 0x01FE;
    } else {
        x1 = 0xFE;
    }
    uint16_t value2 = RAM16(0x010A);
    RAM16_SET(0x0000, value2 & 0x1F);
    RAM16_SET(0x0002, value2 & 0x03E0);
    RAM16_SET(0x0004, value2 & 0x7C00);
    uint16_t value3 = RAM16(0x010C);
    uint8_t a_hi5;
    uint16_t x4;
    bool carry3;
    if (!(value3 & 0x8000)) {
        uint8_t a_hi1 = value3 >> 8;
        uint16_t x2 = x1;
        bool carry1 = carry;
        for (;;) {
            uint16_t value4 = RAM16(0x0600 + x2);
            RAM8(0x0000 + sp0 - 1) = value4 >> 8;
            RAM8(0x0000 + sp0 - 2) = (uint8_t)value4;
            uint8_t value5 = RAM8(0x0000);
            uint8_t a1;
            if ((uint8_t)(((uint8_t)value4 & 0x1F) + value5) < 0x20) {
                a1 = (uint8_t)(((uint8_t)value4 & 0x1F) + value5);
            } else {
                a1 = 0x1F;
            }
            uint8_t value6 = RAM8(0x0005);
            uint8_t a2;
            if (!((uint8_t)(((value4 >> 8) & 0x7C) + value6) & 0x80)) {
                a2 = (uint8_t)(((value4 >> 8) & 0x7C) + value6);
            } else {
                a2 = 0x7C;
            }
            RAM16_SET(0x0006, (a2 << 8) | a1);
            uint16_t value7 = RAM16(0x0002);
            uint8_t a3;
            uint8_t a_hi2;
            if ((uint16_t)((value4 & 0x03E0) + value7) < 0x0400) {
                a3 = (uint8_t)((value4 & 0x03E0) + value7);
                a_hi2 = (uint16_t)((value4 & 0x03E0) + value7) >> 8;
            } else {
                a3 = 0xE0;
                a_hi2 = 3;
            }
            uint16_t value8 = RAM16(0x0006);
            RAM16_SET(0xBE00 + x2, (a_hi2 << 8) | a3 | value8);
            uint8_t a_hi1_next = ((a_hi2 << 8) | a3 | value8) >> 8;
            uint16_t x2_next = (uint16_t)(x2 - 2);
            bool carry1_next = (uint16_t)(x2 - 2) >= 0x20;
            a_hi1 = a_hi1_next;
            x2 = x2_next;
            carry1 = carry1_next;
            if (!(carry1)) break;
        }
        a_hi5 = a_hi1;
        x4 = x2;
        carry3 = carry1;
    } else {
        uint8_t a_hi3 = value3 >> 8;
        uint16_t x3 = x1;
        bool carry2 = carry;
        for (;;) {
            uint16_t value9 = RAM16(0x0600 + x3);
            RAM8(0x0000 + sp0 - 1) = value9 >> 8;
            RAM8(0x0000 + sp0 - 2) = (uint8_t)value9;
            uint8_t value10 = RAM8(0x0000);
            uint8_t a4;
            if (!((uint8_t)(((uint8_t)value9 & 0x1F) - value10) & 0x80)) {
                a4 = (uint8_t)(((uint8_t)value9 & 0x1F) - value10);
            } else {
                a4 = 0;
            }
            uint8_t value11 = RAM8(0x0005);
            uint8_t a5;
            if (!((uint8_t)(((value9 >> 8) & 0x7C) - value11) & 0x80)) {
                a5 = (uint8_t)(((value9 >> 8) & 0x7C) - value11);
            } else {
                a5 = 0;
            }
            RAM16_SET(0x0006, (a5 << 8) | a4);
            uint16_t value12 = RAM16(0x0002);
            uint8_t a6;
            uint8_t a_hi4;
            if (!((uint16_t)((value9 & 0x03E0) - value12) & 0x8000)) {
                a6 = (uint8_t)((value9 & 0x03E0) - value12);
                a_hi4 = (uint16_t)((value9 & 0x03E0) - value12) >> 8;
            } else {
                a6 = 0;
                a_hi4 = 0;
            }
            uint16_t value13 = RAM16(0x0006);
            RAM16_SET(0xBE00 + x3, (a_hi4 << 8) | a6 | value13);
            uint8_t a_hi3_next = ((a_hi4 << 8) | a6 | value13) >> 8;
            uint16_t x3_next = (uint16_t)(x3 - 2);
            bool carry2_next = (uint16_t)(x3 - 2) >= 0x20;
            a_hi3 = a_hi3_next;
            x3 = x3_next;
            carry2 = carry2_next;
            if (!(carry2)) break;
        }
        a_hi5 = a_hi3;
        x4 = x3;
        carry3 = carry2;
    }
    uint8_t a_hi6 = a_hi5;
    uint16_t x5 = x4;
    for (;;) {
        uint16_t value14 = RAM16(0x0600 + x5);
        RAM16_SET(0xBE00 + x5, value14);
        a_hi6 = value14 >> 8;
        x5 = (uint16_t)(x5 - 2);
        if (!(x5 != 0)) break;
    }
    RAM16_SET(0xBE00, RAM16(0xBE20));
    uint8_t value16 = RAM8(0x002A);
    if (value16 & 0x80) {
        uint8_t value17 = RAM8(0x010A);
        uint8_t value18 = RAM8(0x010B);
        if ((value17 | value18) == 0) {
            RAM8(0x002A) = 0;
        }
        if ((value17 & 0x1F) != 0) {
            RAM8(0x010A) = (uint8_t)(value17 - 1);
        }
        bool carry4;
        bool overflow1;
        if ((value18 & 0x7C) == 0) {
            carry4 = carry3;
            overflow1 = value16 & 0x40;
        } else {
            RAM8(0x010B) = (uint8_t)(value18 - 4);
            carry4 = value18 >= 4;
            overflow1 = ((value18 ^ 4) & (value18 ^ (uint8_t)(value18 - 4)) & 0x80) != 0;
        }
        uint16_t value19 = RAM16(0x010A);
        uint8_t a_hi7;
        bool carry5;
        bool overflow2;
        if ((value19 & 0x03E0) == 0) {
            a_hi7 = (value19 & 0x03E0) >> 8;
            carry5 = carry4;
            overflow2 = overflow1;
        } else {
            RAM16_SET(0x010A, (uint16_t)(value19 - 0x20));
            a_hi7 = (uint16_t)(value19 - 0x20) >> 8;
            carry5 = value19 >= 0x20;
            overflow2 = ((value19 ^ 0x20) & (value19 ^ (uint16_t)(value19 - 0x20)) & 0x8000) != 0;
        }
        uint8_t value20 = RAM8(0x0000 + sp0);
        r->a = (a_hi7 << 8) | a;
        r->x = x5;
        r->y = y;
        r->c = carry5;
        r->v = overflow2;
        r->mf = 0;
        r->db = value20;
        RETURN_RTL(c);
    }
    uint16_t value21 = RAM16(0x010C);
    uint8_t a_hi9;
    bool carry7;
    bool overflow4;
    if ((value21 & 0x03E0) == 0) {
        a_hi9 = (value21 & 0x03E0) >> 8;
        carry7 = carry3;
        overflow4 = value16 & 0x40;
    } else {
        RAM16_SET(0x0000, value21 & 0x03E0);
        uint16_t value22 = RAM16(0x010A);
        uint16_t value23 = RAM16(0x0000);
        uint8_t a_hi8;
        bool carry6;
        bool overflow3;
        if ((value22 & 0x03E0) == value23) {
            a_hi8 = (value22 & 0x03E0) >> 8;
            carry6 = (value22 & 0x03E0) >= value23;
            overflow3 = value16 & 0x40;
        } else {
            RAM16_SET(0x010A, (uint16_t)(value22 + 0x20));
            a_hi8 = (uint16_t)(value22 + 0x20) >> 8;
            carry6 = value22 + 0x20 > 0xFFFF;
            overflow3 = ((value22 ^ (uint16_t)(value22 + 0x20)) & ((uint16_t)(value22 + 0x20) ^ 0x20) & 0x8000) != 0;
        }
        a_hi9 = a_hi8;
        carry7 = carry6;
        overflow4 = overflow3;
    }
    uint8_t value24 = RAM8(0x010C);
    bool carry8;
    if ((value24 & 0x1F) == 0) {
        carry8 = carry7;
    } else {
        RAM8(0x0000) = value24 & 0x1F;
        uint8_t value25 = RAM8(0x010A);
        uint8_t value26 = RAM8(0x0000);
        if ((value25 & 0x1F) != value26) {
            RAM8(0x010A) = (uint8_t)(value25 + 1);
        }
        carry8 = (value25 & 0x1F) >= value26;
    }
    uint8_t value27 = RAM8(0x010D);
    bool carry10;
    bool overflow6;
    if ((value27 & 0x7C) == 0) {
        carry10 = carry8;
        overflow6 = overflow4;
    } else {
        RAM8(0x0000) = value27 & 0x7C;
        uint8_t value28 = RAM8(0x010B);
        uint8_t value29 = RAM8(0x0000);
        bool carry9;
        bool overflow5;
        if ((value28 & 0x7C) == value29) {
            carry9 = (value28 & 0x7C) >= value29;
            overflow5 = overflow4;
        } else {
            RAM8(0x010B) = (uint8_t)(value28 + 4);
            carry9 = value28 + 4 > 0xFF;
            overflow5 = ((value28 ^ (uint8_t)(value28 + 4)) & ((uint8_t)(value28 + 4) ^ 4) & 0x80) != 0;
        }
        carry10 = carry9;
        overflow6 = overflow5;
    }
    uint8_t value30 = RAM8(0x0000 + sp0);
    r->a = (a_hi9 << 8) | a;
    r->x = x5;
    r->y = y;
    r->c = carry10;
    r->v = overflow6;
    r->db = value30;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2C820, SOM_RTL, "gen", update_scene_palette_rgb_offset_and_transition_phase, 0, L_B | L_X | L_Y | L_C | L_V, 3, 1, 0, 342, 161)
