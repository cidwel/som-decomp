#include "som_c.h"

/* C18707 execute_actor_cast_request   [class B, 110 bytes, 53 instructions]
 * Source: src/rom/execute_actor_cast_request.s
 * Documented in docs/actor-cast-execution-check.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void execute_actor_cast_request(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM8(0xE012 + x) = 0;
    RAM8(0xE025 + x) = 0;
    RAM8(0xE084 + x) = 0;
    uint8_t value = RAM8(0x00F1);
    if (!(value & 0x80)) {
        if (x < 0x0600) {
            RAM16_SET(0x0014, x);
            r->c = x >= 0x0600;
            r->v = value & 0x40;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8727, 0xC18898); GUARD_JSR(c, sp_call, 0x8727); } /* prepare_actor_cast_directional_offset */
            uint16_t a_all = r->a;
            RAM8(0xE060 + x) = 0x80;
            uint16_t value3 = BUS16(c, 0xD02AA0 + ((((a_all >> 8 << 8) | RAM8(0xE170 + x)) & 0x7F) << 1 << 1 << 1 << 1 << 1 << 1));
            RAM16_SET(0xE0FC + x, value3);
            uint16_t value4 = RAM16(0xE177 + x);
            uint16_t value5 = BUS16(c, 0xD02A82 + ((value4 & 7) << 1 << 1));
            RAM16_SET(0xE06A + x, value5);
            uint16_t value6 = BUS16(c, 0xD02A80 + ((value4 & 7) << 1 << 1));
            RAM16_SET(0x0000, value6);
            uint8_t a1;
            bool carry1;
            if (x < 0x0400) {
                a1 = (uint8_t)value6;
                carry1 = x >= 0x0400;
            } else {
                a1 = (uint8_t)value6 >> 4;
                carry1 = (uint8_t)value6 >> 3 & 0x01;
            }
            RAM8(0xE04F + x) = a1 | 0xF0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8773, 0xC1860A); GUARD_JSR(c, sp_call, 0x8773); } /* load_hero_cast_graphics_and_palette */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
        r->c = x >= 0x0600;
        r->v = value & 0x40;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8721, 0xC18775); GUARD_JSR(c, sp_call, 0x8721); } /* execute_ordinary_actor_cast_presentation */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
    RAM8(0xE060 + x) = 0;
    r->v = value & 0x40;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC18707, SOM_RTL, "gen", execute_actor_cast_request, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 110, 53)
