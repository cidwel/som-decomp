#include "som_c.h"

/* C28528 choose_native59_distinct_color_and_publish_status_palette_sound   [class B, 77 bytes, 32 instructions]
 * Source: src/rom/choose_native59_distinct_color_and_publish_status_palette_sound.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABY.
 */
static void choose_native59_distinct_color_and_publish_status_palette_sound(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(OBJECT_AGE + x, 0);
    r->a = 3;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8530, 0xC2300B); GUARD_JSR(c, sp_call, 0x8530); } /* draw_boss_frame_random_number */
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B0 + value);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t y1;
    if (a_all == value2) {
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        y1 = y_ret;
    } else {
        RAM16_SET(0x00B0 + value, a_all);
        uint16_t value3 = BUS16(c, 0xC28575 + (uint16_t)(a_all << 1));
        uint16_t value4 = RAM16(0x0287);
        RAM16_SET(0x0192 + value4, value3);
        uint16_t value5 = RAM16(0x00B0 + value4);
        RAM8(0x033F + 7) = (uint8_t)(value5 + 0x5B);
        r->a = 0x10;
        r->x = (uint16_t)(value5 + 0x5B);
        r->y = 7;
        r->c = value5 + 0x5B > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = ((value5 ^ (uint16_t)(value5 + 0x5B)) & ((uint16_t)(value5 + 0x5B) ^ 0x5B) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x855E, 0xC2272D); GUARD_JSR(c, sp_call, 0x855E); } /* allocate_boss_palette_transition_object */
        r->a = 0x86;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8564, 0xC230E3); GUARD_JSR(c, sp_call, 0x8564); } /* request_boss_sound_with_parameter_word */
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t value7 = RAM16(0x00B0 + RAM16(0x0287));
        r->a = (uint16_t)(value7 + 0x5B);
        r->x = 0x0D;
        r->c = value7 + 0x5B > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = ((value7 ^ (uint16_t)(value7 + 0x5B)) & ((uint16_t)(value7 + 0x5B) ^ 0x5B) & 0x8000) != 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8573, 0xC226F9); GUARD_JSR(c, sp_call, 0x8573); } /* copy_boss_palette_with_cpu_words */
        uint16_t a_all4 = r->a;
        uint16_t y_ret4 = r->y;
        a1 = (uint8_t)a_all4;
        a_hi1 = a_all4 >> 8;
        y1 = y_ret4;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28528, SOM_RTS, "gen", choose_native59_distinct_color_and_publish_status_palette_sound, 0, L_A | L_B | L_Y, 1, 0, 0, 77, 32)
