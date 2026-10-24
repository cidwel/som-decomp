#include "som_c.h"

/* C01E94 publish_pending_native_menu_tiles_oam_and_actor_color   [class D, 61 bytes, 23 instructions]
 * Source: src/rom/publish_pending_native_menu_tiles_oam_and_actor_color.s
 * Documented in docs/event-menu-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void publish_pending_native_menu_tiles_oam_and_actor_color(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint8_t value = RAM8(0xA20A);
    bool x_flag2;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    if ((value & 2) == 0) {
        x_flag2 = 0;
        a_hi2 = a_hi;
        x2 = x;
        y2 = y;
        carry2 = carry;
    } else {
        uint8_t value2 = RAM8(0xA202);
        bool x_flag;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        if (value2 != 5) {
            r->c = value2 >= 5;
            r->v = value & 0x40;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1EAC, 0xC025AD); GUARD_JSR(c, sp_call, 0x1EAC); } /* upload_complete_native_menu_tile_workspace */
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            x_flag = x_ret;
            a_hi1 = a_all >> 8;
            x1 = x;
            y1 = y;
            carry1 = value2 >= 5;
        } else {
            r->a = (a_hi << 8) | value2;
            r->c = value2 >= 5;
            r->v = value & 0x40;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1EA4, 0xC02082); GUARD_JSR(c, sp_call, 0x1EA4); } /* publish_native_menu_actor_text_and_palette */
            uint16_t x_ret3 = r->x;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1EA7, 0xC0279E); GUARD_JSR(c, sp_call, 0x1EA7); } /* upload_four_native_menu_description_rows */
            bool x_ret4 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t y_ret = r->y;
            bool carry_ret = r->c;
            x_flag = x_ret4;
            a_hi1 = a_all3 >> 8;
            x1 = x_ret3;
            y1 = y_ret;
            carry1 = carry_ret;
        }
        x_flag2 = x_flag;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
    }
    uint8_t value3 = RAM8(0xA20A);
    bool x_flag3;
    uint8_t a_hi3;
    uint16_t x3;
    if ((value3 & 4) == 0) {
        x_flag3 = x_flag2;
        a_hi3 = a_hi2;
        x3 = x2;
    } else {
        r->a = (a_hi2 << 8) | 4;
        r->y = y2;
        r->c = carry2;
        r->v = value3 & 0x40;
        r->mf = 1;
        r->xf = x_flag2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1EB6, 0xC01F5B); GUARD_JSR(c, sp_call, 0x1EB6); } /* upload_complete_native_menu_oam_table */
        bool x_ret5 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t x_ret6 = r->x;
        BUS8_SET(c, 0x002121, 0x1E);
        BUS8_SET(c, 0x002122, RAM8(0xA22D));
        BUS8_SET(c, 0x002122, RAM8(0xA22E));
        x_flag3 = x_ret5;
        a_hi3 = a_all4 >> 8;
        x3 = x_ret6;
    }
    RAM8(0xA20A) &= 0xF9;
    r->a = (a_hi3 << 8) | 6;
    r->x = x3;
    r->y = y2;
    r->v = value3 & 0x40;
    r->mf = 1;
    r->xf = x_flag3;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01E94, SOM_RTS, "gen", publish_pending_native_menu_tiles_oam_and_actor_color, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 61, 23)
