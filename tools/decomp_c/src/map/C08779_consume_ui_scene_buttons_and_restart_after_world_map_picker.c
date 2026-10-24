#include "som_c.h"

/* C08779 consume_ui_scene_buttons_and_restart_after_world_map_picker   [class B, 40 bytes, 18 instructions]
 * Source: src/rom/consume_ui_scene_buttons_and_restart_after_world_map_picker.s
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void consume_ui_scene_buttons_and_restart_after_world_map_picker(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x00CC);
    RAM8(0x00CC) &= 0xCF;
    uint8_t a_hi2;
    uint8_t x2;
    uint8_t y2;
    bool carry2;
    bool overflow2;
    if ((value & 0x30) == 0) {
        a_hi2 = a >> 8;
        x2 = x;
        y2 = y;
        carry2 = carry;
        overflow2 = overflow;
    } else {
        uint8_t value2 = RAM8(0x00BE);
        uint8_t a_hi1;
        uint8_t x1;
        uint8_t y1;
        bool carry1;
        bool overflow1;
        if (value2 & 0x80) {
            a_hi1 = a >> 8;
            x1 = x;
            y1 = y;
            carry1 = carry;
            overflow1 = value2 & 0x40;
        } else {
            r->a = (a >> 8 << 8) | 0x30;
            r->z = (value2 & 0x30) == 0;
            r->n = value2 & 0x80;
            r->v = value2 & 0x40;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8789, 0xC087A2); GUARD_JSR(c, sp_call, 0x8789); } /* request_native_ui_scene_window_or_confirm_transition */
            uint16_t a_all = r->a;
            uint8_t x_ret = r->x;
            uint8_t y_ret = r->y;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y_ret;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
        }
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        overflow2 = overflow1;
    }
    RAM8(0x00CC) &= 0xFD;
    uint8_t value4 = RAM8(0x00CC);
    RAM8(0x00CC) &= 0xFE;
    if ((value4 & 1) == 0) {
        r->x = x2;
        r->y = y2;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    r->a = (a_hi2 << 8) | 1;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->z = (value4 & 1) == 0;
    r->n = 0;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8798, 0xC0A5CC); GUARD_JSR(c, sp_call, 0x8798); } /* initialize_and_run_complete_world_map_picker_scene */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x879C, 0x02B091); GUARD_JSL(c, sp_call, 0x879C); } /* adjust_ui_focus_coordinate_near_confirmed_world_map_position */
    r->mf = 0;
    TAIL_CALL(c, 0xC0803C, SOM_RTS); /* external */
}
SOM_REGISTER(0xC08779, SOM_RTS, "gen", consume_ui_scene_buttons_and_restart_after_world_map_picker, 0, L_X | L_Y, 1, 0, 1, 41, 18)
