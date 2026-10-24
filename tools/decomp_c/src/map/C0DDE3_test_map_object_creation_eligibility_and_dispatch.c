#include "som_c.h"

/* C0DDE3 test_map_object_creation_eligibility_and_dispatch   [class C, 366 bytes, 176 instructions]
 * Source: src/rom/test_map_object_creation_eligibility_and_dispatch.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void test_map_object_creation_eligibility_and_dispatch(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_ddf4 = 0;
    uint8_t a_hi_ddf4 = 0;
    uint16_t x_ddf4 = 0;
    uint16_t y_ddf4 = 0;
    bool carry_ddf4 = 0;
    bool overflow_ddf4 = 0;
    uint8_t value = RAM8(0xC807 + y);
    if ((value & 0x40) == 0) {
        a_ddf4 = value & 0x40;
        a_hi_ddf4 = a_hi;
        x_ddf4 = x;
        y_ddf4 = y;
        carry_ddf4 = carry;
        overflow_ddf4 = overflow;
        goto shared_DDF4;
    }
    r->a = a_hi << 8 | (value & 0x40);
    r->z = (value & 0x40) == 0;
    r->n = value & 0x40 & 0x80;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDDEF, 0x02C757); GUARD_JSL(c, sp_call, 0xDDEF); } /* test_map_object_event_flag_range */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    if (carry_ret) {
        uint8_t value2 = RAM8(0xC80D + y);
        if (value2 < 0x57) {
            RAM8(0xE000 + x_ret) = 1;
            RAM8(0xE001 + x_ret) = 0;
            uint8_t value3 = RAM8(0xE043 + x_ret);
            uint8_t a_hi1;
            uint16_t y1;
            if (value3 == 0) {
                a_hi1 = a_all >> 8;
                y1 = y;
            } else {
                r->a = (a_all >> 8 << 8) | value3;
                r->c = value2 >= 0x57;
                r->z = value3 == 0;
                r->n = value3 & 0x80;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xDE4A, 0xC0E2E1); GUARD_JSR(c, sp_call, 0xDE4A); } /* release_map_object_to_position_cache */
                uint16_t a_all2 = r->a;
                uint16_t y_ret = r->y;
                a_hi1 = a_all2 >> 8;
                y1 = y_ret;
            }
            RAM8(0x0000 + sp0) = x_ret >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret;
            RAM8(0x0000 + sp0 - 2) = y1 >> 8;
            RAM8(0x0000 + sp0 - 3) = (uint8_t)y1;
            uint16_t x1 = x_ret;
            uint16_t y2 = 0x30;
            for (;;) {
                RAM16_SET(0xE002 + x1, 0);
                x1 = (uint16_t)(x1 + 2);
                y2 = (uint16_t)(y2 - 1);
                if (!(y2 != 0)) break;
            }
            uint8_t value4 = RAM8(0x0000 + sp0 - 3);
            uint8_t value5 = RAM8(0x0000 + sp0 - 2);
            uint8_t value6 = RAM8(0x0000 + sp0 - 1);
            uint8_t value7 = RAM8(0x0000 + sp0);
            RAM16_SET(0xE03E + ((value7 << 8) | value6), RAM16(0xC80E + ((value5 << 8) | value4)));
            uint16_t value9 = RAM16(0xC80C + ((value5 << 8) | value4));
            RAM16_SET(0xE03C + ((value7 << 8) | value6), value9);
            RAM8(0xE045 + ((value7 << 8) | value6)) = 0;
            RAM8(0xE060 + ((value7 << 8) | value6)) = 0;
            RAM8(0xE061 + ((value7 << 8) | value6)) = 0;
            RAM8(0xE069 + ((value7 << 8) | value6)) = 0;
            RAM8(0xE100 + ((value7 << 8) | value6)) = 0;
            RAM8(0xE104 + ((value7 << 8) | value6)) = 0;
            RAM8(0xE108 + ((value7 << 8) | value6)) = 0;
            RAM8(0xE180 + ((value7 << 8) | value6)) = value9 >> 8;
            uint8_t a1;
            if (value9 >> 8 & 0x80) {
                a1 = 0xD2;
            } else {
                a1 = 0xD3;
            }
            RAM8(0xE033 + ((value7 << 8) | value6)) = a1;
            RAM8(0xE083 + ((value7 << 8) | value6)) = 0;
            r->a = ((uint8_t)value9 << 8) | 0;
            r->x = (value7 << 8) | value6;
            r->y = (value5 << 8) | value4;
            r->c = value9 >> 8 & 0x80;
            r->z = 1;
            r->n = 0;
            r->v = overflow;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xDE94, 0x01DFCF); GUARD_JSL(c, sp_call, 0xDE94); } /* load_actor_map_graphics_entry */
            uint16_t x_ret2 = r->x;
            uint16_t y_ret2 = r->y;
            uint16_t value10 = BUS16(c, 0xD0FFF0);
            RAM16_SET(0xE02A + x_ret2, value10);
            RAM16_SET(0xE002 + x_ret2, (((RAM16(0xC80A + y_ret2) & 0x7F) << 1 << 1) | 1) << 1 << 1);
            RAM16_SET(0xE004 + x_ret2, (((RAM16(0xC80B + y_ret2) & 0x7F) << 1 << 1) | 1) << 1 << 1);
            RAM16_SET(0xE034 + x_ret2, y_ret2);
            RAM16_SET(0xC802 + y_ret2, x_ret2);
            RAM8(0xE044 + x_ret2) = RAM8(0xC807 + y_ret2);
            RAM8(0xC800 + y_ret2) = 0x81;
            uint8_t value14 = RAM8(0xE03C + x_ret2);
            RAM8(0x0000 + sp0) = value14;
            RAM8(0xE00B + x_ret2) = (uint8_t)(value14 << 4) & 0x80;
            uint8_t value15 = RAM8(0x0000 + sp0);
            RAM8(0x0000 + sp0) = value15;
            uint8_t a3;
            bool carry1;
            if (((uint8_t)(((uint8_t)(((uint8_t)(value15 << 1) << 1) | (value15 >> 7)) << 1) | ((uint8_t)(value15 << 1) >> 7)) & 3) != 3) {
                uint8_t a2;
                if (((uint8_t)(((uint8_t)(((uint8_t)(value15 << 1) << 1) | (value15 >> 7)) << 1) | ((uint8_t)(value15 << 1) >> 7)) & 3) != 2) {
                    a2 = (uint8_t)(((uint8_t)(((uint8_t)(value15 << 1) << 1) | (value15 >> 7)) << 1) | ((uint8_t)(value15 << 1) >> 7)) & 3;
                } else {
                    a2 = 0x82;
                }
                a3 = a2;
                carry1 = ((uint8_t)(((uint8_t)(((uint8_t)(value15 << 1) << 1) | (value15 >> 7)) << 1) | ((uint8_t)(value15 << 1) >> 7)) & 3) >= 2;
            } else {
                a3 = 2;
                carry1 = ((uint8_t)(((uint8_t)(((uint8_t)(value15 << 1) << 1) | (value15 >> 7)) << 1) | ((uint8_t)(value15 << 1) >> 7)) & 3) >= 3;
            }
            RAM8(0xE010 + x_ret2) = a3;
            if ((RAM8(0xE071 + x_ret2) & 0x20) != 0) {
                RAM8(0xE010 + x_ret2) = 0;
            }
            RAM8(0xE011 + x_ret2) = 0;
            RAM8(0xE030 + x_ret2) = 0xFF;
            uint8_t value17 = RAM8(0x0000 + sp0);
            uint8_t value18 = RAM8(0x00ED);
            if (!(value18 & 0x80)) {
                RAM8(0x0000) = (value17 & 0x30) >> 3;
                uint8_t value19 = RAM8(0xE08B + x_ret2);
                uint8_t value20 = RAM8(0x0000);
                RAM8(0xE08B + x_ret2) = (value19 & 0xF9) | value20;
                RAM16_SET(0xE0F8 + x_ret2, (((x_ret2 >> 8 << 8) | ((((value19 & 0xF9) | value20) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2);
                r->a = (((x_ret2 >> 8 << 8) | ((((value19 & 0xF9) | value20) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2;
                r->c = (((value19 & 0xF9) | value20) & 0x0E) << 1 << 1 << 1 & 0x80;
                r->z = (((x_ret2 >> 8 << 8) | ((((value19 & 0xF9) | value20) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2 == 0;
                r->n = (((x_ret2 >> 8 << 8) | ((((value19 & 0xF9) | value20) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2 & 0x8000;
                r->v = value18 & 0x40;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xDF35, 0xC0DF55); GUARD_JSR(c, sp_call, 0xDF35); } /* assign_map_object_priority_and_terrain */
                uint16_t a_all4 = r->a;
                uint16_t x_ret4 = r->x;
                RAM8(0x0000 + sp0) = x_ret4 >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret4;
                uint8_t value21 = RAM8(0xE03D + x_ret4);
                r->a = (a_all4 >> 8 << 8) | value21;
                r->z = value21 == 0;
                r->n = value21 & 0x80;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSL(c, 0xDF41, 0xC10020); GUARD_JSL(c, sp_call, 0xDF41); } /* set_actor_program_long */
                r->sp += 2;
                bool x_ret5 = r->xf;
                if (x_ret5) {
                    c->fail = 3;
                    return;
                } else {
                    r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                    r->c = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
            r->a = (x_ret2 >> 8 << 8) | value17;
            r->c = carry1;
            r->z = (value17 & value18) == 0;
            r->n = value18 & 0x80;
            r->v = value18 & 0x40;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xDF47, 0xC0DF55); GUARD_JSR(c, sp_call, 0xDF47); } /* assign_map_object_priority_and_terrain */
            { const uint16_t sp_call = r->sp; JSL(c, 0xDF4B, 0x01E01E); GUARD_JSL(c, sp_call, 0xDF4B); } /* load_actor_map_palette_entry */
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xDF4E, 0xC0E038); GUARD_JSR(c, sp_call, 0xDF4E); } /* refresh_map_object_identity_graphics_and_ai */
            r->c = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        if (value2 >= 0x80) {
            RAM8(0xE000 + x_ret) = 1;
            RAM8(0xE001 + x_ret) = 0;
            uint8_t value25 = RAM8(0xE043 + x_ret);
            uint8_t a_hi2;
            uint16_t y3;
            if (value25 == 0) {
                a_hi2 = a_all >> 8;
                y3 = y;
            } else {
                r->a = (a_all >> 8 << 8) | value25;
                r->c = value2 >= 0x80;
                r->z = value25 == 0;
                r->n = value25 & 0x80;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xDE4A, 0xC0E2E1); GUARD_JSR(c, sp_call, 0xDE4A); } /* release_map_object_to_position_cache */
                uint16_t a_all9 = r->a;
                uint16_t y_ret8 = r->y;
                a_hi2 = a_all9 >> 8;
                y3 = y_ret8;
            }
            RAM8(0x0000 + sp0) = x_ret >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret;
            RAM8(0x0000 + sp0 - 2) = y3 >> 8;
            RAM8(0x0000 + sp0 - 3) = (uint8_t)y3;
            uint16_t x2 = x_ret;
            uint16_t y4 = 0x30;
            for (;;) {
                RAM16_SET(0xE002 + x2, 0);
                x2 = (uint16_t)(x2 + 2);
                y4 = (uint16_t)(y4 - 1);
                if (!(y4 != 0)) break;
            }
            uint8_t value26 = RAM8(0x0000 + sp0 - 3);
            uint8_t value27 = RAM8(0x0000 + sp0 - 2);
            uint8_t value28 = RAM8(0x0000 + sp0 - 1);
            uint8_t value29 = RAM8(0x0000 + sp0);
            RAM16_SET(0xE03E + ((value29 << 8) | value28), RAM16(0xC80E + ((value27 << 8) | value26)));
            uint16_t value31 = RAM16(0xC80C + ((value27 << 8) | value26));
            RAM16_SET(0xE03C + ((value29 << 8) | value28), value31);
            RAM8(0xE045 + ((value29 << 8) | value28)) = 0;
            RAM8(0xE060 + ((value29 << 8) | value28)) = 0;
            RAM8(0xE061 + ((value29 << 8) | value28)) = 0;
            RAM8(0xE069 + ((value29 << 8) | value28)) = 0;
            RAM8(0xE100 + ((value29 << 8) | value28)) = 0;
            RAM8(0xE104 + ((value29 << 8) | value28)) = 0;
            RAM8(0xE108 + ((value29 << 8) | value28)) = 0;
            RAM8(0xE180 + ((value29 << 8) | value28)) = value31 >> 8;
            uint8_t a4;
            if (value31 >> 8 & 0x80) {
                a4 = 0xD2;
            } else {
                a4 = 0xD3;
            }
            RAM8(0xE033 + ((value29 << 8) | value28)) = a4;
            RAM8(0xE083 + ((value29 << 8) | value28)) = 0;
            r->a = ((uint8_t)value31 << 8) | 0;
            r->x = (value29 << 8) | value28;
            r->y = (value27 << 8) | value26;
            r->c = value31 >> 8 & 0x80;
            r->z = 1;
            r->n = 0;
            r->v = overflow;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xDE94, 0x01DFCF); GUARD_JSL(c, sp_call, 0xDE94); } /* load_actor_map_graphics_entry */
            uint16_t x_ret13 = r->x;
            uint16_t y_ret9 = r->y;
            uint16_t value32 = BUS16(c, 0xD0FFF0);
            RAM16_SET(0xE02A + x_ret13, value32);
            RAM16_SET(0xE002 + x_ret13, (((RAM16(0xC80A + y_ret9) & 0x7F) << 1 << 1) | 1) << 1 << 1);
            RAM16_SET(0xE004 + x_ret13, (((RAM16(0xC80B + y_ret9) & 0x7F) << 1 << 1) | 1) << 1 << 1);
            RAM16_SET(0xE034 + x_ret13, y_ret9);
            RAM16_SET(0xC802 + y_ret9, x_ret13);
            RAM8(0xE044 + x_ret13) = RAM8(0xC807 + y_ret9);
            RAM8(0xC800 + y_ret9) = 0x81;
            uint8_t value36 = RAM8(0xE03C + x_ret13);
            RAM8(0x0000 + sp0) = value36;
            RAM8(0xE00B + x_ret13) = (uint8_t)(value36 << 4) & 0x80;
            uint8_t value37 = RAM8(0x0000 + sp0);
            RAM8(0x0000 + sp0) = value37;
            uint8_t a6;
            bool carry2;
            if (((uint8_t)(((uint8_t)(((uint8_t)(value37 << 1) << 1) | (value37 >> 7)) << 1) | ((uint8_t)(value37 << 1) >> 7)) & 3) != 3) {
                uint8_t a5;
                if (((uint8_t)(((uint8_t)(((uint8_t)(value37 << 1) << 1) | (value37 >> 7)) << 1) | ((uint8_t)(value37 << 1) >> 7)) & 3) != 2) {
                    a5 = (uint8_t)(((uint8_t)(((uint8_t)(value37 << 1) << 1) | (value37 >> 7)) << 1) | ((uint8_t)(value37 << 1) >> 7)) & 3;
                } else {
                    a5 = 0x82;
                }
                a6 = a5;
                carry2 = ((uint8_t)(((uint8_t)(((uint8_t)(value37 << 1) << 1) | (value37 >> 7)) << 1) | ((uint8_t)(value37 << 1) >> 7)) & 3) >= 2;
            } else {
                a6 = 2;
                carry2 = ((uint8_t)(((uint8_t)(((uint8_t)(value37 << 1) << 1) | (value37 >> 7)) << 1) | ((uint8_t)(value37 << 1) >> 7)) & 3) >= 3;
            }
            RAM8(0xE010 + x_ret13) = a6;
            if ((RAM8(0xE071 + x_ret13) & 0x20) != 0) {
                RAM8(0xE010 + x_ret13) = 0;
            }
            RAM8(0xE011 + x_ret13) = 0;
            RAM8(0xE030 + x_ret13) = 0xFF;
            uint8_t value39 = RAM8(0x0000 + sp0);
            uint8_t value40 = RAM8(0x00ED);
            if (!(value40 & 0x80)) {
                RAM8(0x0000) = (value39 & 0x30) >> 3;
                uint8_t value41 = RAM8(0xE08B + x_ret13);
                uint8_t value42 = RAM8(0x0000);
                RAM8(0xE08B + x_ret13) = (value41 & 0xF9) | value42;
                RAM16_SET(0xE0F8 + x_ret13, (((x_ret13 >> 8 << 8) | ((((value41 & 0xF9) | value42) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2);
                r->a = (((x_ret13 >> 8 << 8) | ((((value41 & 0xF9) | value42) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2;
                r->c = (((value41 & 0xF9) | value42) & 0x0E) << 1 << 1 << 1 & 0x80;
                r->z = (((x_ret13 >> 8 << 8) | ((((value41 & 0xF9) | value42) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2 == 0;
                r->n = (((x_ret13 >> 8 << 8) | ((((value41 & 0xF9) | value42) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2 & 0x8000;
                r->v = value40 & 0x40;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xDF35, 0xC0DF55); GUARD_JSR(c, sp_call, 0xDF35); } /* assign_map_object_priority_and_terrain */
                uint16_t a_all11 = r->a;
                uint16_t x_ret15 = r->x;
                RAM8(0x0000 + sp0) = x_ret15 >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret15;
                uint8_t value43 = RAM8(0xE03D + x_ret15);
                r->a = (a_all11 >> 8 << 8) | value43;
                r->z = value43 == 0;
                r->n = value43 & 0x80;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSL(c, 0xDF41, 0xC10020); GUARD_JSL(c, sp_call, 0xDF41); } /* set_actor_program_long */
                r->sp += 2;
                bool x_ret16 = r->xf;
                if (x_ret16) {
                    c->fail = 3;
                    return;
                } else {
                    r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                    r->c = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
            r->a = (x_ret13 >> 8 << 8) | value39;
            r->c = carry2;
            r->z = (value39 & value40) == 0;
            r->n = value40 & 0x80;
            r->v = value40 & 0x40;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xDF47, 0xC0DF55); GUARD_JSR(c, sp_call, 0xDF47); } /* assign_map_object_priority_and_terrain */
            { const uint16_t sp_call = r->sp; JSL(c, 0xDF4B, 0x01E01E); GUARD_JSL(c, sp_call, 0xDF4B); } /* load_actor_map_palette_entry */
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xDF4E, 0xC0E038); GUARD_JSR(c, sp_call, 0xDF4E); } /* refresh_map_object_identity_graphics_and_ai */
            r->c = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        RAM8(0x005C) = 0x80;
        RAM16_SET(0x0300, (RAM16(0xC80A + y) & 0x7F) << 1 << 1 << 1 << 1);
        uint16_t value48 = RAM16(0xC80B + y);
        RAM16_SET(0x0302, (value48 & 0x7F) << 1 << 1 << 1 << 1);
        uint16_t value49 = RAM16(0xC80D + y);
        r->a = value49 & 0xFF;
        r->c = (value48 & 0x7F) << 1 << 1 << 1 & 0x8000;
        r->z = (value49 & 0xFF) == 0;
        r->n = value49 & 0xFF & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xDE36, 0xC20000); GUARD_JSL(c, sp_call, 0xDE36); } /* initialize_boss_resources_public_jump */
        r->c = 1;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if (!carry_ret) {
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    a_ddf4 = (uint8_t)a_all;
    a_hi_ddf4 = a_all >> 8;
    x_ddf4 = x_ret;
    y_ddf4 = y;
    carry_ddf4 = carry_ret;
    overflow_ddf4 = overflow;
    shared_DDF4:;
    r->a = (a_hi_ddf4 << 8) | a_ddf4;
    r->x = x_ddf4;
    r->y = y_ddf4;
    r->c = carry_ddf4;
    r->v = overflow_ddf4;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDDF7, 0x02C757); GUARD_JSL(c, sp_call, 0xDDF7); } /* test_map_object_event_flag_range */
    uint16_t x_ret26 = r->x;
    bool carry_ret17 = r->c;
    if (!carry_ret17) {
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xDDFC, 0xC0DF85); GUARD_JSR(c, sp_call, 0xDDFC); } /* test_map_object_inside_load_window */
    uint16_t a_all18 = r->a;
    bool carry_ret18 = r->c;
    bool overflow_ret10 = r->v;
    if (carry_ret18) {
        uint8_t value50 = RAM8(0xC80D + y_ddf4);
        if (value50 < 0x57) {
            RAM8(0xE000 + x_ret26) = 1;
            RAM8(0xE001 + x_ret26) = 0;
            uint8_t value51 = RAM8(0xE043 + x_ret26);
            uint8_t a_hi3;
            uint16_t y5;
            if (value51 == 0) {
                a_hi3 = a_all18 >> 8;
                y5 = y_ddf4;
            } else {
                r->a = (a_all18 >> 8 << 8) | value51;
                r->c = value50 >= 0x57;
                r->z = value51 == 0;
                r->n = value51 & 0x80;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xDE4A, 0xC0E2E1); GUARD_JSR(c, sp_call, 0xDE4A); } /* release_map_object_to_position_cache */
                uint16_t a_all19 = r->a;
                uint16_t y_ret16 = r->y;
                a_hi3 = a_all19 >> 8;
                y5 = y_ret16;
            }
            RAM8(0x0000 + sp0) = x_ret26 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret26;
            RAM8(0x0000 + sp0 - 2) = y5 >> 8;
            RAM8(0x0000 + sp0 - 3) = (uint8_t)y5;
            uint16_t x3 = x_ret26;
            uint16_t y6 = 0x30;
            for (;;) {
                RAM16_SET(0xE002 + x3, 0);
                x3 = (uint16_t)(x3 + 2);
                y6 = (uint16_t)(y6 - 1);
                if (!(y6 != 0)) break;
            }
            uint8_t value52 = RAM8(0x0000 + sp0 - 3);
            uint8_t value53 = RAM8(0x0000 + sp0 - 2);
            uint8_t value54 = RAM8(0x0000 + sp0 - 1);
            uint8_t value55 = RAM8(0x0000 + sp0);
            RAM16_SET(0xE03E + ((value55 << 8) | value54), RAM16(0xC80E + ((value53 << 8) | value52)));
            uint16_t value57 = RAM16(0xC80C + ((value53 << 8) | value52));
            RAM16_SET(0xE03C + ((value55 << 8) | value54), value57);
            RAM8(0xE045 + ((value55 << 8) | value54)) = 0;
            RAM8(0xE060 + ((value55 << 8) | value54)) = 0;
            RAM8(0xE061 + ((value55 << 8) | value54)) = 0;
            RAM8(0xE069 + ((value55 << 8) | value54)) = 0;
            RAM8(0xE100 + ((value55 << 8) | value54)) = 0;
            RAM8(0xE104 + ((value55 << 8) | value54)) = 0;
            RAM8(0xE108 + ((value55 << 8) | value54)) = 0;
            RAM8(0xE180 + ((value55 << 8) | value54)) = value57 >> 8;
            uint8_t a7;
            if (value57 >> 8 & 0x80) {
                a7 = 0xD2;
            } else {
                a7 = 0xD3;
            }
            RAM8(0xE033 + ((value55 << 8) | value54)) = a7;
            RAM8(0xE083 + ((value55 << 8) | value54)) = 0;
            r->a = ((uint8_t)value57 << 8) | 0;
            r->x = (value55 << 8) | value54;
            r->y = (value53 << 8) | value52;
            r->c = value57 >> 8 & 0x80;
            r->z = 1;
            r->n = 0;
            r->v = overflow_ret10;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xDE94, 0x01DFCF); GUARD_JSL(c, sp_call, 0xDE94); } /* load_actor_map_graphics_entry */
            uint16_t x_ret27 = r->x;
            uint16_t y_ret17 = r->y;
            uint16_t value58 = BUS16(c, 0xD0FFF0);
            RAM16_SET(0xE02A + x_ret27, value58);
            RAM16_SET(0xE002 + x_ret27, (((RAM16(0xC80A + y_ret17) & 0x7F) << 1 << 1) | 1) << 1 << 1);
            RAM16_SET(0xE004 + x_ret27, (((RAM16(0xC80B + y_ret17) & 0x7F) << 1 << 1) | 1) << 1 << 1);
            RAM16_SET(0xE034 + x_ret27, y_ret17);
            RAM16_SET(0xC802 + y_ret17, x_ret27);
            RAM8(0xE044 + x_ret27) = RAM8(0xC807 + y_ret17);
            RAM8(0xC800 + y_ret17) = 0x81;
            uint8_t value62 = RAM8(0xE03C + x_ret27);
            RAM8(0x0000 + sp0) = value62;
            RAM8(0xE00B + x_ret27) = (uint8_t)(value62 << 4) & 0x80;
            uint8_t value63 = RAM8(0x0000 + sp0);
            RAM8(0x0000 + sp0) = value63;
            uint8_t a9;
            bool carry3;
            if (((uint8_t)(((uint8_t)(((uint8_t)(value63 << 1) << 1) | (value63 >> 7)) << 1) | ((uint8_t)(value63 << 1) >> 7)) & 3) != 3) {
                uint8_t a8;
                if (((uint8_t)(((uint8_t)(((uint8_t)(value63 << 1) << 1) | (value63 >> 7)) << 1) | ((uint8_t)(value63 << 1) >> 7)) & 3) != 2) {
                    a8 = (uint8_t)(((uint8_t)(((uint8_t)(value63 << 1) << 1) | (value63 >> 7)) << 1) | ((uint8_t)(value63 << 1) >> 7)) & 3;
                } else {
                    a8 = 0x82;
                }
                a9 = a8;
                carry3 = ((uint8_t)(((uint8_t)(((uint8_t)(value63 << 1) << 1) | (value63 >> 7)) << 1) | ((uint8_t)(value63 << 1) >> 7)) & 3) >= 2;
            } else {
                a9 = 2;
                carry3 = ((uint8_t)(((uint8_t)(((uint8_t)(value63 << 1) << 1) | (value63 >> 7)) << 1) | ((uint8_t)(value63 << 1) >> 7)) & 3) >= 3;
            }
            RAM8(0xE010 + x_ret27) = a9;
            if ((RAM8(0xE071 + x_ret27) & 0x20) != 0) {
                RAM8(0xE010 + x_ret27) = 0;
            }
            RAM8(0xE011 + x_ret27) = 0;
            RAM8(0xE030 + x_ret27) = 0xFF;
            uint8_t value65 = RAM8(0x0000 + sp0);
            uint8_t value66 = RAM8(0x00ED);
            if (!(value66 & 0x80)) {
                RAM8(0x0000) = (value65 & 0x30) >> 3;
                uint8_t value67 = RAM8(0xE08B + x_ret27);
                uint8_t value68 = RAM8(0x0000);
                RAM8(0xE08B + x_ret27) = (value67 & 0xF9) | value68;
                RAM16_SET(0xE0F8 + x_ret27, (((x_ret27 >> 8 << 8) | ((((value67 & 0xF9) | value68) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2);
                r->a = (((x_ret27 >> 8 << 8) | ((((value67 & 0xF9) | value68) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2;
                r->c = (((value67 & 0xF9) | value68) & 0x0E) << 1 << 1 << 1 & 0x80;
                r->z = (((x_ret27 >> 8 << 8) | ((((value67 & 0xF9) | value68) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2 == 0;
                r->n = (((x_ret27 >> 8 << 8) | ((((value67 & 0xF9) | value68) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2 & 0x8000;
                r->v = value66 & 0x40;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xDF35, 0xC0DF55); GUARD_JSR(c, sp_call, 0xDF35); } /* assign_map_object_priority_and_terrain */
                uint16_t a_all21 = r->a;
                uint16_t x_ret29 = r->x;
                RAM8(0x0000 + sp0) = x_ret29 >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret29;
                uint8_t value69 = RAM8(0xE03D + x_ret29);
                r->a = (a_all21 >> 8 << 8) | value69;
                r->z = value69 == 0;
                r->n = value69 & 0x80;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSL(c, 0xDF41, 0xC10020); GUARD_JSL(c, sp_call, 0xDF41); } /* set_actor_program_long */
                r->sp += 2;
                bool x_ret30 = r->xf;
                if (x_ret30) {
                    c->fail = 3;
                    return;
                } else {
                    r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                    r->c = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
            r->a = (x_ret27 >> 8 << 8) | value65;
            r->c = carry3;
            r->z = (value65 & value66) == 0;
            r->n = value66 & 0x80;
            r->v = value66 & 0x40;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xDF47, 0xC0DF55); GUARD_JSR(c, sp_call, 0xDF47); } /* assign_map_object_priority_and_terrain */
            { const uint16_t sp_call = r->sp; JSL(c, 0xDF4B, 0x01E01E); GUARD_JSL(c, sp_call, 0xDF4B); } /* load_actor_map_palette_entry */
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xDF4E, 0xC0E038); GUARD_JSR(c, sp_call, 0xDF4E); } /* refresh_map_object_identity_graphics_and_ai */
            r->c = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        if (value50 >= 0x80) {
            RAM8(0xE000 + x_ret26) = 1;
            RAM8(0xE001 + x_ret26) = 0;
            uint8_t value73 = RAM8(0xE043 + x_ret26);
            uint8_t a_hi4;
            uint16_t y7;
            if (value73 == 0) {
                a_hi4 = a_all18 >> 8;
                y7 = y_ddf4;
            } else {
                r->a = (a_all18 >> 8 << 8) | value73;
                r->c = value50 >= 0x80;
                r->z = value73 == 0;
                r->n = value73 & 0x80;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xDE4A, 0xC0E2E1); GUARD_JSR(c, sp_call, 0xDE4A); } /* release_map_object_to_position_cache */
                uint16_t a_all26 = r->a;
                uint16_t y_ret23 = r->y;
                a_hi4 = a_all26 >> 8;
                y7 = y_ret23;
            }
            RAM8(0x0000 + sp0) = x_ret26 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret26;
            RAM8(0x0000 + sp0 - 2) = y7 >> 8;
            RAM8(0x0000 + sp0 - 3) = (uint8_t)y7;
            uint16_t x4 = x_ret26;
            uint16_t y8 = 0x30;
            for (;;) {
                RAM16_SET(0xE002 + x4, 0);
                x4 = (uint16_t)(x4 + 2);
                y8 = (uint16_t)(y8 - 1);
                if (!(y8 != 0)) break;
            }
            uint8_t value74 = RAM8(0x0000 + sp0 - 3);
            uint8_t value75 = RAM8(0x0000 + sp0 - 2);
            uint8_t value76 = RAM8(0x0000 + sp0 - 1);
            uint8_t value77 = RAM8(0x0000 + sp0);
            RAM16_SET(0xE03E + ((value77 << 8) | value76), RAM16(0xC80E + ((value75 << 8) | value74)));
            uint16_t value79 = RAM16(0xC80C + ((value75 << 8) | value74));
            RAM16_SET(0xE03C + ((value77 << 8) | value76), value79);
            RAM8(0xE045 + ((value77 << 8) | value76)) = 0;
            RAM8(0xE060 + ((value77 << 8) | value76)) = 0;
            RAM8(0xE061 + ((value77 << 8) | value76)) = 0;
            RAM8(0xE069 + ((value77 << 8) | value76)) = 0;
            RAM8(0xE100 + ((value77 << 8) | value76)) = 0;
            RAM8(0xE104 + ((value77 << 8) | value76)) = 0;
            RAM8(0xE108 + ((value77 << 8) | value76)) = 0;
            RAM8(0xE180 + ((value77 << 8) | value76)) = value79 >> 8;
            uint8_t a10;
            if (value79 >> 8 & 0x80) {
                a10 = 0xD2;
            } else {
                a10 = 0xD3;
            }
            RAM8(0xE033 + ((value77 << 8) | value76)) = a10;
            RAM8(0xE083 + ((value77 << 8) | value76)) = 0;
            r->a = ((uint8_t)value79 << 8) | 0;
            r->x = (value77 << 8) | value76;
            r->y = (value75 << 8) | value74;
            r->c = value79 >> 8 & 0x80;
            r->z = 1;
            r->n = 0;
            r->v = overflow_ret10;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xDE94, 0x01DFCF); GUARD_JSL(c, sp_call, 0xDE94); } /* load_actor_map_graphics_entry */
            uint16_t x_ret38 = r->x;
            uint16_t y_ret24 = r->y;
            uint16_t value80 = BUS16(c, 0xD0FFF0);
            RAM16_SET(0xE02A + x_ret38, value80);
            RAM16_SET(0xE002 + x_ret38, (((RAM16(0xC80A + y_ret24) & 0x7F) << 1 << 1) | 1) << 1 << 1);
            RAM16_SET(0xE004 + x_ret38, (((RAM16(0xC80B + y_ret24) & 0x7F) << 1 << 1) | 1) << 1 << 1);
            RAM16_SET(0xE034 + x_ret38, y_ret24);
            RAM16_SET(0xC802 + y_ret24, x_ret38);
            RAM8(0xE044 + x_ret38) = RAM8(0xC807 + y_ret24);
            RAM8(0xC800 + y_ret24) = 0x81;
            uint8_t value84 = RAM8(0xE03C + x_ret38);
            RAM8(0x0000 + sp0) = value84;
            RAM8(0xE00B + x_ret38) = (uint8_t)(value84 << 4) & 0x80;
            uint8_t value85 = RAM8(0x0000 + sp0);
            RAM8(0x0000 + sp0) = value85;
            uint8_t a12;
            bool carry4;
            if (((uint8_t)(((uint8_t)(((uint8_t)(value85 << 1) << 1) | (value85 >> 7)) << 1) | ((uint8_t)(value85 << 1) >> 7)) & 3) != 3) {
                uint8_t a11;
                if (((uint8_t)(((uint8_t)(((uint8_t)(value85 << 1) << 1) | (value85 >> 7)) << 1) | ((uint8_t)(value85 << 1) >> 7)) & 3) != 2) {
                    a11 = (uint8_t)(((uint8_t)(((uint8_t)(value85 << 1) << 1) | (value85 >> 7)) << 1) | ((uint8_t)(value85 << 1) >> 7)) & 3;
                } else {
                    a11 = 0x82;
                }
                a12 = a11;
                carry4 = ((uint8_t)(((uint8_t)(((uint8_t)(value85 << 1) << 1) | (value85 >> 7)) << 1) | ((uint8_t)(value85 << 1) >> 7)) & 3) >= 2;
            } else {
                a12 = 2;
                carry4 = ((uint8_t)(((uint8_t)(((uint8_t)(value85 << 1) << 1) | (value85 >> 7)) << 1) | ((uint8_t)(value85 << 1) >> 7)) & 3) >= 3;
            }
            RAM8(0xE010 + x_ret38) = a12;
            if ((RAM8(0xE071 + x_ret38) & 0x20) != 0) {
                RAM8(0xE010 + x_ret38) = 0;
            }
            RAM8(0xE011 + x_ret38) = 0;
            RAM8(0xE030 + x_ret38) = 0xFF;
            uint8_t value87 = RAM8(0x0000 + sp0);
            uint8_t value88 = RAM8(0x00ED);
            if (!(value88 & 0x80)) {
                RAM8(0x0000) = (value87 & 0x30) >> 3;
                uint8_t value89 = RAM8(0xE08B + x_ret38);
                uint8_t value90 = RAM8(0x0000);
                RAM8(0xE08B + x_ret38) = (value89 & 0xF9) | value90;
                RAM16_SET(0xE0F8 + x_ret38, (((x_ret38 >> 8 << 8) | ((((value89 & 0xF9) | value90) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2);
                r->a = (((x_ret38 >> 8 << 8) | ((((value89 & 0xF9) | value90) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2;
                r->c = (((value89 & 0xF9) | value90) & 0x0E) << 1 << 1 << 1 & 0x80;
                r->z = (((x_ret38 >> 8 << 8) | ((((value89 & 0xF9) | value90) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2 == 0;
                r->n = (((x_ret38 >> 8 << 8) | ((((value89 & 0xF9) | value90) & 0x0E) << 1 << 1 << 1 << 1)) & 0xFF) + 2 & 0x8000;
                r->v = value88 & 0x40;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xDF35, 0xC0DF55); GUARD_JSR(c, sp_call, 0xDF35); } /* assign_map_object_priority_and_terrain */
                uint16_t a_all28 = r->a;
                uint16_t x_ret40 = r->x;
                RAM8(0x0000 + sp0) = x_ret40 >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret40;
                uint8_t value91 = RAM8(0xE03D + x_ret40);
                r->a = (a_all28 >> 8 << 8) | value91;
                r->z = value91 == 0;
                r->n = value91 & 0x80;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSL(c, 0xDF41, 0xC10020); GUARD_JSL(c, sp_call, 0xDF41); } /* set_actor_program_long */
                r->sp += 2;
                bool x_ret41 = r->xf;
                if (x_ret41) {
                    c->fail = 3;
                    return;
                } else {
                    r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                    r->c = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
            r->a = (x_ret38 >> 8 << 8) | value87;
            r->c = carry4;
            r->z = (value87 & value88) == 0;
            r->n = value88 & 0x80;
            r->v = value88 & 0x40;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xDF47, 0xC0DF55); GUARD_JSR(c, sp_call, 0xDF47); } /* assign_map_object_priority_and_terrain */
            { const uint16_t sp_call = r->sp; JSL(c, 0xDF4B, 0x01E01E); GUARD_JSL(c, sp_call, 0xDF4B); } /* load_actor_map_palette_entry */
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xDF4E, 0xC0E038); GUARD_JSR(c, sp_call, 0xDF4E); } /* refresh_map_object_identity_graphics_and_ai */
            r->c = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        RAM8(0x005C) = 0x80;
        RAM16_SET(0x0300, (RAM16(0xC80A + y_ddf4) & 0x7F) << 1 << 1 << 1 << 1);
        uint16_t value96 = RAM16(0xC80B + y_ddf4);
        RAM16_SET(0x0302, (value96 & 0x7F) << 1 << 1 << 1 << 1);
        uint16_t value97 = RAM16(0xC80D + y_ddf4);
        r->a = value97 & 0xFF;
        r->c = (value96 & 0x7F) << 1 << 1 << 1 & 0x8000;
        r->z = (value97 & 0xFF) == 0;
        r->n = value97 & 0xFF & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xDE36, 0xC20000); GUARD_JSL(c, sp_call, 0xDE36); } /* initialize_boss_resources_public_jump */
        r->c = 1;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DDE3, SOM_RTS, "gen", test_map_object_creation_eligibility_and_dispatch, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 366, 176)
