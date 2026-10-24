#include "som_c.h"

/* C20F91 emit_selected_boss_object_camera_palette_callback_and_sprites   [class B, 154 bytes, 70 instructions]
 * Source: src/rom/emit_selected_boss_object_camera_palette_callback_and_sprites.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABX.
 */
static void emit_selected_boss_object_camera_palette_callback_and_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x028B, x);
    RAM16_SET(0x0287, (uint16_t)(x + 0xE000));
    RAM16_SET(0x0289, (uint16_t)(((uint16_t)((uint16_t)(x + 0xE000) - 0xE600) >> 2) + 0xF800));
    uint16_t value = RAM16(0x0098 + (uint16_t)(x + 0xE000));
    RAM16_SET(0x028D, value);
    uint8_t a_hi1;
    uint16_t y1;
    bool overflow1;
    if ((value & 8) == 0) {
        a_hi1 = value >> 8;
        y1 = y;
        overflow1 = ((((uint16_t)((uint16_t)(x + 0xE000) - 0xE600) >> 2) ^ (uint16_t)(((uint16_t)((uint16_t)(x + 0xE000) - 0xE600) >> 2) + 0xF800)) & ((uint16_t)(((uint16_t)((uint16_t)(x + 0xE000) - 0xE600) >> 2) + 0xF800) ^ 0xF800) & 0x8000) != 0;
    } else {
        r->a = value;
        r->x = (uint16_t)(x + 0xE000);
        r->c = ((uint16_t)((uint16_t)(x + 0xE000) - 0xE600) >> 2) + 0xF800 > 0xFFFF;
        r->z = (value & 8) == 0;
        r->n = value & 0x8000;
        r->v = ((((uint16_t)((uint16_t)(x + 0xE000) - 0xE600) >> 2) ^ (uint16_t)(((uint16_t)((uint16_t)(x + 0xE000) - 0xE600) >> 2) + 0xF800)) & ((uint16_t)(((uint16_t)((uint16_t)(x + 0xE000) - 0xE600) >> 2) + 0xF800) ^ 0xF800) & 0x8000) != 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0FB3, 0xC2102B); GUARD_JSR(c, sp_call, 0x0FB3); } /* align_boss_camera_scroll_and_screen_position */
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        a_hi1 = a_all >> 8;
        y1 = y_ret;
        overflow1 = overflow_ret;
    }
    uint16_t value2 = RAM16(0x0287);
    uint16_t value3 = RAM16(0x00ED);
    if ((value3 & 0x40) == 0) {
        r->a = value3;
        r->x = value2;
        r->y = y1;
        r->z = (value3 & 0x40) == 0;
        r->n = value3 & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0FC9, 0xC210AC); GUARD_JSR(c, sp_call, 0x0FC9); } /* consume_boss_palette_commands */
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0FCC, 0xC211F4); GUARD_JSR(c, sp_call, 0x0FCC); } /* integrate_boss_height_and_dispatch_enabled_motion_callback */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret4 = r->xf;
        uint16_t y_ret3 = r->y;
        if (x_ret4) {
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 0x70 + value4);
            if ((value5 & 4) == 0) {
                uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 0x7C);
                BUS16_SET(c, (uint16_t)(dp_ret + 0x7F), value6 >> 2);
                uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0x59);
                BUS16_SET(c, (uint16_t)(dp_ret + 0x81), value7);
                BUS16_SET(c, (uint16_t)(dp_ret + 0x83), 0x80);
                r->a = 0x80;
                r->x = value4;
                r->y = (uint8_t)y_ret3;
                r->c = value6 >> 1 & 0x01;
                r->z = 0;
                r->n = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1002, 0xC21F80); GUARD_JSR(c, sp_call, 0x1002); } /* emit_boss_sprite_piece_list */
                bool x_ret6 = r->xf;
                uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                BUS16_SET(c, (db_ret << 0x10) + 0x7C, (uint16_t)(value8 << 2));
                uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                if (x_ret6) {
                    uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                    uint8_t value11 = BUS8(c, 0xD97F2D + (value9 & 3));
                    BUS8_SET(c, (db_ret << 0x10) + 0x59, value11);
                    BUS8_SET(c, (db_ret << 0x10) + 0x5A, (uint8_t)(value10 >> 2));
                    BUS16_SET(c, (db_ret << 0x10) + 0x0FAC, 1);
                    r->a = 1;
                    r->x = value9 & 3;
                    r->mf = 0;
                    r->xf = 1;
                    RETURN_RTS(c);
                } else {
                    uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                    uint8_t value13 = BUS8(c, 0xD97F2D + (value9 & 3));
                    BUS8_SET(c, (db_ret << 0x10) + 0x59, value13);
                    BUS8_SET(c, (db_ret << 0x10) + 0x5A, (uint8_t)(value12 >> 2));
                    BUS16_SET(c, (db_ret << 0x10) + 0x0FAC, 1);
                    r->a = 1;
                    r->x = value9 & 3;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
            if ((value5 & 2) == 0) {
                uint16_t value14 = BUS16_RDP(c, (db_ret << 0x10) + 0x70 + value4);
                BUS16_SET(c, (db_ret << 0x10) + 0x70 + value4, value14 | 2);
                uint16_t value15 = BUS16_RDP(c, (db_ret << 0x10) + 0x7C);
                BUS16_SET(c, (uint16_t)(dp_ret + 0x7F), value15 >> 2);
                uint16_t value16 = BUS16_RDP(c, (db_ret << 0x10) + 0x59);
                BUS16_SET(c, (uint16_t)(dp_ret + 0x81), value16);
                BUS16_SET(c, (uint16_t)(dp_ret + 0x83), 0x80);
                r->a = 0x80;
                r->x = value4;
                r->y = (uint8_t)y_ret3;
                r->c = value15 >> 1 & 0x01;
                r->z = 0;
                r->n = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1002, 0xC21F80); GUARD_JSR(c, sp_call, 0x1002); } /* emit_boss_sprite_piece_list */
                bool x_ret8 = r->xf;
                uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                BUS16_SET(c, (db_ret << 0x10) + 0x7C, (uint16_t)(value17 << 2));
                uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                if (x_ret8) {
                    uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                    uint8_t value20 = BUS8(c, 0xD97F2D + (value18 & 3));
                    BUS8_SET(c, (db_ret << 0x10) + 0x59, value20);
                    BUS8_SET(c, (db_ret << 0x10) + 0x5A, (uint8_t)(value19 >> 2));
                    BUS16_SET(c, (db_ret << 0x10) + 0x0FAC, 1);
                    r->a = 1;
                    r->x = value18 & 3;
                    r->mf = 0;
                    r->xf = 1;
                    RETURN_RTS(c);
                } else {
                    uint16_t value21 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                    uint8_t value22 = BUS8(c, 0xD97F2D + (value18 & 3));
                    BUS8_SET(c, (db_ret << 0x10) + 0x59, value22);
                    BUS8_SET(c, (db_ret << 0x10) + 0x5A, (uint8_t)(value21 >> 2));
                    BUS16_SET(c, (db_ret << 0x10) + 0x0FAC, 1);
                    r->a = 1;
                    r->x = value18 & 3;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
            uint16_t value23 = BUS16_RDP(c, (db_ret << 0x10) + 0x70 + value4);
            BUS16_SET(c, (db_ret << 0x10) + 0x70 + value4, value23 ^ 2);
            r->a = value23 ^ 2;
            r->x = value4;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value24 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            uint16_t value25 = BUS16_RDP(c, (db_ret << 0x10) + 0x70 + value24);
            if ((value25 & 4) == 0) {
                uint16_t value26 = BUS16_RDP(c, (db_ret << 0x10) + 0x7C);
                BUS16_SET(c, (uint16_t)(dp_ret + 0x7F), value26 >> 2);
                uint16_t value27 = BUS16_RDP(c, (db_ret << 0x10) + 0x59);
                BUS16_SET(c, (uint16_t)(dp_ret + 0x81), value27);
                BUS16_SET(c, (uint16_t)(dp_ret + 0x83), 0x80);
                r->a = 0x80;
                r->x = value24;
                r->c = value26 >> 1 & 0x01;
                r->z = 0;
                r->n = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1002, 0xC21F80); GUARD_JSR(c, sp_call, 0x1002); } /* emit_boss_sprite_piece_list */
                uint16_t value28 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                BUS16_SET(c, (db_ret << 0x10) + 0x7C, (uint16_t)(value28 << 2));
                uint16_t value29 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                uint16_t value30 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                uint8_t value31 = BUS8(c, 0xD97F2D + (value29 & 3));
                BUS8_SET(c, (db_ret << 0x10) + 0x59, value31);
                BUS8_SET(c, (db_ret << 0x10) + 0x5A, (uint8_t)(value30 >> 2));
                BUS16_SET(c, (db_ret << 0x10) + 0x0FAC, 1);
                r->a = 1;
                r->x = value29 & 3;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if ((value25 & 2) == 0) {
                uint16_t value32 = BUS16_RDP(c, (db_ret << 0x10) + 0x70 + value24);
                BUS16_SET(c, (db_ret << 0x10) + 0x70 + value24, value32 | 2);
                uint16_t value33 = BUS16_RDP(c, (db_ret << 0x10) + 0x7C);
                BUS16_SET(c, (uint16_t)(dp_ret + 0x7F), value33 >> 2);
                uint16_t value34 = BUS16_RDP(c, (db_ret << 0x10) + 0x59);
                BUS16_SET(c, (uint16_t)(dp_ret + 0x81), value34);
                BUS16_SET(c, (uint16_t)(dp_ret + 0x83), 0x80);
                r->a = 0x80;
                r->x = value24;
                r->c = value33 >> 1 & 0x01;
                r->z = 0;
                r->n = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1002, 0xC21F80); GUARD_JSR(c, sp_call, 0x1002); } /* emit_boss_sprite_piece_list */
                uint16_t value35 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                BUS16_SET(c, (db_ret << 0x10) + 0x7C, (uint16_t)(value35 << 2));
                uint16_t value36 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                uint16_t value37 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x7F));
                uint8_t value38 = BUS8(c, 0xD97F2D + (value36 & 3));
                BUS8_SET(c, (db_ret << 0x10) + 0x59, value38);
                BUS8_SET(c, (db_ret << 0x10) + 0x5A, (uint8_t)(value37 >> 2));
                BUS16_SET(c, (db_ret << 0x10) + 0x0FAC, 1);
                r->a = 1;
                r->x = value36 & 3;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value39 = BUS16_RDP(c, (db_ret << 0x10) + 0x70 + value24);
            BUS16_SET(c, (db_ret << 0x10) + 0x70 + value24, value39 ^ 2);
            r->a = value39 ^ 2;
            r->x = value24;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
    uint16_t value40 = RAM16(0x0098 + value2);
    if ((value40 & 0x1000) != 0) {
        r->a = value40;
        r->x = value2;
        r->y = y1;
        r->z = (value40 & 0x1000) == 0;
        r->n = value40 & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0FC9, 0xC210AC); GUARD_JSR(c, sp_call, 0x0FC9); } /* consume_boss_palette_commands */
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0FCC, 0xC211F4); GUARD_JSR(c, sp_call, 0x0FCC); } /* integrate_boss_height_and_dispatch_enabled_motion_callback */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret14 = r->xf;
        uint16_t y_ret9 = r->y;
        if (x_ret14) {
            uint8_t value41 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x87));
            uint16_t value42 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x70 + value41);
            if ((value42 & 4) == 0) {
                uint16_t value43 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x7C);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 0x7F), value43 >> 2);
                uint16_t value44 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x59);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 0x81), value44);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 0x83), 0x80);
                r->a = 0x80;
                r->x = value41;
                r->y = (uint8_t)y_ret9;
                r->c = value43 >> 1 & 0x01;
                r->z = 0;
                r->n = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1002, 0xC21F80); GUARD_JSR(c, sp_call, 0x1002); } /* emit_boss_sprite_piece_list */
                bool x_ret16 = r->xf;
                uint16_t value45 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                BUS16_SET(c, (db_ret2 << 0x10) + 0x7C, (uint16_t)(value45 << 2));
                uint16_t value46 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                if (x_ret16) {
                    uint16_t value47 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                    uint8_t value48 = BUS8(c, 0xD97F2D + (value46 & 3));
                    BUS8_SET(c, (db_ret2 << 0x10) + 0x59, value48);
                    BUS8_SET(c, (db_ret2 << 0x10) + 0x5A, (uint8_t)(value47 >> 2));
                    BUS16_SET(c, (db_ret2 << 0x10) + 0x0FAC, 1);
                    r->a = 1;
                    r->x = value46 & 3;
                    r->mf = 0;
                    r->xf = 1;
                    RETURN_RTS(c);
                } else {
                    uint16_t value49 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                    uint8_t value50 = BUS8(c, 0xD97F2D + (value46 & 3));
                    BUS8_SET(c, (db_ret2 << 0x10) + 0x59, value50);
                    BUS8_SET(c, (db_ret2 << 0x10) + 0x5A, (uint8_t)(value49 >> 2));
                    BUS16_SET(c, (db_ret2 << 0x10) + 0x0FAC, 1);
                    r->a = 1;
                    r->x = value46 & 3;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
            if ((value42 & 2) == 0) {
                uint16_t value51 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x70 + value41);
                BUS16_SET(c, (db_ret2 << 0x10) + 0x70 + value41, value51 | 2);
                uint16_t value52 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x7C);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 0x7F), value52 >> 2);
                uint16_t value53 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x59);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 0x81), value53);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 0x83), 0x80);
                r->a = 0x80;
                r->x = value41;
                r->y = (uint8_t)y_ret9;
                r->c = value52 >> 1 & 0x01;
                r->z = 0;
                r->n = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1002, 0xC21F80); GUARD_JSR(c, sp_call, 0x1002); } /* emit_boss_sprite_piece_list */
                bool x_ret18 = r->xf;
                uint16_t value54 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                BUS16_SET(c, (db_ret2 << 0x10) + 0x7C, (uint16_t)(value54 << 2));
                uint16_t value55 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                if (x_ret18) {
                    uint16_t value56 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                    uint8_t value57 = BUS8(c, 0xD97F2D + (value55 & 3));
                    BUS8_SET(c, (db_ret2 << 0x10) + 0x59, value57);
                    BUS8_SET(c, (db_ret2 << 0x10) + 0x5A, (uint8_t)(value56 >> 2));
                    BUS16_SET(c, (db_ret2 << 0x10) + 0x0FAC, 1);
                    r->a = 1;
                    r->x = value55 & 3;
                    r->mf = 0;
                    r->xf = 1;
                    RETURN_RTS(c);
                } else {
                    uint16_t value58 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                    uint8_t value59 = BUS8(c, 0xD97F2D + (value55 & 3));
                    BUS8_SET(c, (db_ret2 << 0x10) + 0x59, value59);
                    BUS8_SET(c, (db_ret2 << 0x10) + 0x5A, (uint8_t)(value58 >> 2));
                    BUS16_SET(c, (db_ret2 << 0x10) + 0x0FAC, 1);
                    r->a = 1;
                    r->x = value55 & 3;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
            uint16_t value60 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x70 + value41);
            BUS16_SET(c, (db_ret2 << 0x10) + 0x70 + value41, value60 ^ 2);
            r->a = value60 ^ 2;
            r->x = value41;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value61 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x87));
            uint16_t value62 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x70 + value61);
            if ((value62 & 4) == 0) {
                uint16_t value63 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x7C);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 0x7F), value63 >> 2);
                uint16_t value64 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x59);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 0x81), value64);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 0x83), 0x80);
                r->a = 0x80;
                r->x = value61;
                r->c = value63 >> 1 & 0x01;
                r->z = 0;
                r->n = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1002, 0xC21F80); GUARD_JSR(c, sp_call, 0x1002); } /* emit_boss_sprite_piece_list */
                uint16_t value65 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                BUS16_SET(c, (db_ret2 << 0x10) + 0x7C, (uint16_t)(value65 << 2));
                uint16_t value66 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                uint16_t value67 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                uint8_t value68 = BUS8(c, 0xD97F2D + (value66 & 3));
                BUS8_SET(c, (db_ret2 << 0x10) + 0x59, value68);
                BUS8_SET(c, (db_ret2 << 0x10) + 0x5A, (uint8_t)(value67 >> 2));
                BUS16_SET(c, (db_ret2 << 0x10) + 0x0FAC, 1);
                r->a = 1;
                r->x = value66 & 3;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if ((value62 & 2) == 0) {
                uint16_t value69 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x70 + value61);
                BUS16_SET(c, (db_ret2 << 0x10) + 0x70 + value61, value69 | 2);
                uint16_t value70 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x7C);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 0x7F), value70 >> 2);
                uint16_t value71 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x59);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 0x81), value71);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 0x83), 0x80);
                r->a = 0x80;
                r->x = value61;
                r->c = value70 >> 1 & 0x01;
                r->z = 0;
                r->n = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1002, 0xC21F80); GUARD_JSR(c, sp_call, 0x1002); } /* emit_boss_sprite_piece_list */
                uint16_t value72 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                BUS16_SET(c, (db_ret2 << 0x10) + 0x7C, (uint16_t)(value72 << 2));
                uint16_t value73 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                uint16_t value74 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x7F));
                uint8_t value75 = BUS8(c, 0xD97F2D + (value73 & 3));
                BUS8_SET(c, (db_ret2 << 0x10) + 0x59, value75);
                BUS8_SET(c, (db_ret2 << 0x10) + 0x5A, (uint8_t)(value74 >> 2));
                BUS16_SET(c, (db_ret2 << 0x10) + 0x0FAC, 1);
                r->a = 1;
                r->x = value73 & 3;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value76 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x70 + value61);
            BUS16_SET(c, (db_ret2 << 0x10) + 0x70 + value61, value76 ^ 2);
            r->a = value76 ^ 2;
            r->x = value61;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
    r->a = value40;
    r->x = value2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20F91, SOM_RTS, "gen", emit_selected_boss_object_camera_palette_callback_and_sprites, 0, L_A | L_B | L_X, 1, 0, 0, 154, 70)
