#include "som_c.h"

/* C26678 refresh_descriptor_nine_child_animation_from_parent_byte_key   [class B, 40 bytes, 21 instructions]
 * Source: src/rom/refresh_descriptor_nine_child_animation_from_parent_byte_key.s
 * Documented in docs/boss-descriptor-nine-child.md
 * Entry: M=any X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void refresh_descriptor_nine_child_animation_from_parent_byte_key(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = 0;
    for (;;) {
        uint8_t value = BUS8(c, 0xDCE34A + x1);
        if (value == RAM8(0x0299)) {
            uint16_t value3 = BUS16(c, 0xDCE34E + ((((a_hi1 << 8) | x1) & 0xFF) << 1));
            uint16_t value4 = RAM16(0x0287);
            r->a = value3;
            r->x = value4;
            r->y = (uint8_t)y;
            r->c = ((a_hi1 << 8) | x1) & 0xFF & 0x8000;
            r->v = overflow;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x669D, 0xC21394); GUARD_JSR(c, sp_call, 0x669D); } /* select_boss_animation_and_reset_frame_cursor */
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if ((uint8_t)(x1 + 1) != 4) {
            x1 = (uint8_t)(x1 + 1);
            continue;
        }
        r->mf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC26678, SOM_RTS, "gen", refresh_descriptor_nine_child_animation_from_parent_byte_key, 0, 0, 1, -1, 0, 40, 21)
