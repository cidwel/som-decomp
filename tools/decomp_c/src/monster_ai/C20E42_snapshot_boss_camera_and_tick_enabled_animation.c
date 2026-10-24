#include "som_c.h"

/* C20E42 snapshot_boss_camera_and_tick_enabled_animation   [class B, 40 bytes, 17 instructions]
 * Source: src/rom/snapshot_boss_camera_and_tick_enabled_animation.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: YV.
 */
static void snapshot_boss_camera_and_tick_enabled_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0098 + x);
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    if ((value & 8) == 0) {
        a_hi1 = value >> 8;
        carry1 = carry;
        overflow1 = overflow;
    } else {
        RAM16_SET(0x0FB0, RAM16(0x002B + x));
        uint16_t value3 = RAM16(0x0066 + x);
        uint16_t value4 = RAM16(0x02C7);
        uint16_t value5 = RAM16(0x0032 + x);
        RAM16_SET(0x0FB2, (uint16_t)((uint16_t)(((value3 >> 1) ^ value4) + 1) + value5));
        a_hi1 = (uint16_t)((uint16_t)(((value3 >> 1) ^ value4) + 1) + value5) >> 8;
        carry1 = (uint16_t)(((value3 >> 1) ^ value4) + 1) + value5 > 0xFFFF;
        overflow1 = (((uint16_t)(((value3 >> 1) ^ value4) + 1) ^ (uint16_t)((uint16_t)(((value3 >> 1) ^ value4) + 1) + value5)) & (value5 ^ (uint16_t)((uint16_t)(((value3 >> 1) ^ value4) + 1) + value5)) & 0x8000) != 0;
    }
    uint16_t value6 = RAM16(0x0098 + x);
    uint16_t y1;
    bool overflow2;
    if ((value6 & 0x0800) == 0) {
        y1 = y;
        overflow2 = overflow1;
    } else {
        r->a = value6;
        r->c = carry1;
        r->v = overflow1;
        JSR(c, 0x0E68, 0xC213AD); /* tick_boss_animation_and_prepare_frame_graphics */
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        y1 = y_ret;
        overflow2 = overflow_ret;
    }
    r->y = y1;
    r->v = overflow2;
    r->mf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20E42, SOM_RTS, "gen", snapshot_boss_camera_and_tick_enabled_animation, 0, L_Y | L_V, 1, 0, 0, 40, 17)
