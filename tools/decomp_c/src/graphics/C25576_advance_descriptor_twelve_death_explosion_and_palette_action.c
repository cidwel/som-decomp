#include "som_c.h"

/* C25576 advance_descriptor_twelve_death_explosion_and_palette_action   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/advance_descriptor_twelve_death_explosion_and_palette_action.s
 * Documented in docs/boss-descriptor-twelve-death-action.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void advance_descriptor_twelve_death_explosion_and_palette_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(OBJECT_AGE + x);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if ((value & 3) != 0) {
        a1 = value & 3;
        a_hi1 = 0;
        x1 = x;
        y1 = y;
        zero1 = (value & 3) == 0;
        negative1 = value & 3 & 0x8000;
        overflow1 = overflow;
    } else {
        { const uint16_t sp_call = r->sp; JSR(c, 0x5580, 0xC20C33); GUARD_JSR(c, sp_call, 0x5580); } /* create_randomly_positioned_boss_death_explosion_actor */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5583, 0xC20C89); GUARD_JSR(c, sp_call, 0x5583); } /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25576, SOM_RTS, "gen", advance_descriptor_twelve_death_explosion_and_palette_action, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 16, 7)
