#include "som_c.h"

/* C1C583 dispatch_explicit_graphics_plane_conversion   [class B, 22 bytes, 12 instructions]
 * Source: src/rom/dispatch_explicit_graphics_plane_conversion.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: Y.
 */
static void dispatch_explicit_graphics_plane_conversion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    BUS8_SET(c, (uint16_t)(dp + 8), a);
    if (a_hi != 0) {
        if ((uint8_t)(a_hi - 1) != 0) {
            r->a = (a << 8) | (uint8_t)(a_hi - 1);
            r->z = (uint8_t)(a_hi - 1) == 0;
            r->n = (uint8_t)(a_hi - 1) & 0x80;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC597, 0xC1C8A9); GUARD_JSR(c, sp_call, 0xC597); } /* convert_object_graphics_planes_inverted */
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        r->a = (a << 8) | (uint8_t)(a_hi - 1);
        r->z = (uint8_t)(a_hi - 1) == 0;
        r->n = (uint8_t)(a_hi - 1) & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC593, 0xC1C731); GUARD_JSR(c, sp_call, 0xC593); } /* convert_object_graphics_planes_xor */
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    r->a = (a << 8) | a_hi;
    r->z = a_hi == 0;
    r->n = a_hi & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC58C, 0xC1C5D1); GUARD_JSR(c, sp_call, 0xC58C); } /* convert_object_graphics_planes_masked */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1C583, SOM_RTL, "gen", dispatch_explicit_graphics_plane_conversion, 0, L_Y, 1, 1, 0, 22, 12)
