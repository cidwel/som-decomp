#include "som_c.h"

static void cycle_descriptor_eight_child_end_palette_slot(SomCtx *c);

/* C2701A dispatch_descriptor_eight_child_animation_palette_cycle   [class C, 67 bytes, 28 instructions]
 * Source: src/rom/dispatch_descriptor_eight_child_animation_palette_cycle.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void dispatch_descriptor_eight_child_animation_palette_cycle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    if ((RAM16(OBJECT_AGE + x) & 1) == 0) {
        RETURN_RTS(c);
    }
    if (RAM16(0x009A + y) == 0) {
        RETURN_RTS(c);
    }
    uint16_t value3 = RAM16(0x009A + x);
    if (value3 == 0x0133) {
        uint16_t value6 = BUS16(c, 0xC270AF + RAM16(0x00B2 + RAM16(0x0287)));
        r->a = value6 & 0xFF;
        r->x = 0x0D;
        r->c = value3 >= 0x0133;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x7093, 0xC226F9); GUARD_JSR(c, sp_call, 0x7093); } /* copy_boss_palette_with_cpu_words */
        uint16_t value7 = RAM16(0x0287);
        RAM16_SET(0x00B2 + value7, (uint16_t)(RAM16(0x00B2 + value7) + 1));
        RAM16_SET(0x00B2 + value7, RAM16(0x00B2 + value7) & 3);
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if ((uint16_t)(value3 - 0xFA) & 0x8000) {
        RETURN_RTS(c);
    }
    r->a = (uint16_t)((uint16_t)(value3 - 0xFA) << 1);
    r->x = (uint16_t)((uint16_t)(value3 - 0xFA) << 1);
    r->c = (uint16_t)(value3 - 0xFA) & 0x8000;
    r->z = (uint16_t)((uint16_t)(value3 - 0xFA) << 1) == 0;
    r->n = (uint16_t)((uint16_t)(value3 - 0xFA) << 1) & 0x8000;
    r->v = ((value3 ^ 0xFA) & (value3 ^ (uint16_t)(value3 - 0xFA)) & 0x8000) != 0;
    switch ((uint16_t)((uint16_t)(value3 - 0xFA) << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC27041, SOM_RTS); /* cycle_descriptor_eight_child_three_palette_slots */
    case 0x0002: TAIL_CALL_DYN(c, 0xC27041, SOM_RTS); /* cycle_descriptor_eight_child_three_palette_slots */
    case 0x0004: cycle_descriptor_eight_child_end_palette_slot(c); return;
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x703B + ((uint16_t)((uint16_t)(value3 - 0xFA) << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC2701A, SOM_RTS, "gen", dispatch_descriptor_eight_child_animation_palette_cycle, SOM_UNWINDS, 0, 5, 0, 0, 137, 28)

/* C27081 cycle_descriptor_eight_child_end_palette_slot   [class A, 34 bytes, 13 instructions]
 * Source: src/rom/dispatch_descriptor_eight_child_animation_palette_cycle.s
 * Subroutine of dispatch_descriptor_eight_child_animation_palette_cycle, translated in place.
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void cycle_descriptor_eight_child_end_palette_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value3 = BUS16(c, 0xC270AF + RAM16(0x00B2 + RAM16(0x0287)));
    r->a = value3 & 0xFF;
    r->x = 0x0D;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7093, 0xC226F9); GUARD_JSR(c, sp_call, 0x7093); } /* copy_boss_palette_with_cpu_words */
    uint16_t value4 = RAM16(0x0287);
    RAM16_SET(0x00B2 + value4, (uint16_t)(RAM16(0x00B2 + value4) + 1));
    uint16_t value5 = RAM16(0x00B2 + value4);
    RAM16_SET(0x00B2 + value4, value5 & 3);
    r->a = value5 & 3;
    r->x = value4;
    r->z = (value5 & 3) == 0;
    r->n = value5 & 3 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
