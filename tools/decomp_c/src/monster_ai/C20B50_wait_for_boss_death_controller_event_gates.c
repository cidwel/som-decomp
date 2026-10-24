#include "som_c.h"

/* C20B50 wait_for_boss_death_controller_event_gates   [class B, 59 bytes, 26 instructions]
 * Source: src/rom/wait_for_boss_death_controller_event_gates.s
 * Documented in docs/boss-native-linked-death-phases.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYCV.
 */
static void wait_for_boss_death_controller_event_gates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    if (value2 >= 0x80) {
        uint16_t value3 = RAM16(0x00D9);
        uint16_t value4 = RAM16(0x00DA);
        uint16_t value5 = RAM16(0x00DB);
        if (((value3 | value4 | value5) & 0x80) != 0) {
            r->a = value3 | value4 | value5;
            r->c = 0;
            RETURN_RTS(c);
        }
        uint16_t value6 = RAM16(0x1D04);
        if ((value6 & 0x20) != 0) {
            r->a = value6;
            r->c = 0;
            RETURN_RTS(c);
        }
        uint16_t value7 = RAM16(0x0072 + value);
        uint8_t a_hi1;
        uint16_t y1;
        bool overflow1;
        if (value7 == 0) {
            a_hi1 = value7 >> 8;
            y1 = y;
            overflow1 = overflow;
        } else {
            r->a = value7;
            r->x = value;
            r->c = value2 >= 0x80;
            JSR(c, 0x0B86, 0xC20C11); /* mark_controller_and_request_numeric_boss_death_event */
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            bool overflow_ret = r->v;
            a_hi1 = a_all >> 8;
            y1 = y_ret;
            overflow1 = overflow_ret;
        }
        r->a = (a_hi1 << 8) | (uint8_t)a;
        r->y = y1;
        r->c = 1;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t a_hi2;
    uint16_t y2;
    bool overflow2;
    if (value2 != 8) {
        a_hi2 = value2 >> 8;
        y2 = y;
        overflow2 = overflow;
    } else {
        r->a = value2;
        r->x = value;
        r->c = value2 >= 8;
        JSR(c, 0x0B61, 0xC23A9A); /* create_boss_terminal_visual_effect_pair */
        uint16_t a_all2 = r->a;
        uint16_t y_ret2 = r->y;
        bool overflow_ret2 = r->v;
        a_hi2 = a_all2 >> 8;
        y2 = y_ret2;
        overflow2 = overflow_ret2;
    }
    r->a = (a_hi2 << 8) | (uint8_t)a;
    r->y = y2;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x0B64, 0xC20C89); /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20B50, SOM_RTS, "gen", wait_for_boss_death_controller_event_gates, 0, L_B | L_Y | L_C | L_V, 1, 0, 0, 59, 26)
