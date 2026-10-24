#include "som_c.h"

/* C06F5E play_native_menu_ring_open_or_change_sound   [class A, 20 bytes, 8 instructions]
 * Source: src/rom/play_native_menu_ring_open_or_change_sound.s
 * Documented in docs/event-menu-ring-list.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCZV.
 */
static void play_native_menu_ring_open_or_change_sound(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint8_t value = RAM8(0x1812);
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool overflow1;
    if (value != 3) {
        r->a = (a >> 8 << 8) | value;
        r->c = value >= 3;
        r->z = value == 3;
        r->n = (uint8_t)(value - 3) & 0x80;
        r->mf = 1;
        JSL(c, 0x6F70, 0xD0CF18); /* request_native_menu_audio_2a */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool zero_ret = r->z;
        bool overflow_ret = r->v;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        carry1 = carry_ret;
        zero1 = zero_ret;
        overflow1 = overflow_ret;
    } else {
        r->a = (a >> 8 << 8) | value;
        r->c = value >= 3;
        r->z = value == 3;
        r->n = (uint8_t)(value - 3) & 0x80;
        r->mf = 1;
        JSL(c, 0x6F6A, 0xD0CF20); /* request_native_menu_audio_2b */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool zero_ret2 = r->z;
        bool overflow_ret2 = r->v;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret2;
        y1 = y_ret2;
        carry1 = carry_ret2;
        zero1 = zero_ret2;
        overflow1 = overflow_ret2;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06F5E, SOM_RTS, "gen", play_native_menu_ring_open_or_change_sound, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 0, 0, 20, 8)
