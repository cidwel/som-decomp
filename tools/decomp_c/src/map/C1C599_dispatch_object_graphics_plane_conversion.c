#include "som_c.h"

/* C1C599 dispatch_object_graphics_plane_conversion   [class B, 56 bytes, 34 instructions]
 * Source: src/rom/dispatch_object_graphics_plane_conversion.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void dispatch_object_graphics_plane_conversion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    /* A.low becomes the data bank of the plane converters: every caller passes a ROM bank ($D4 in all captures); banks
     * $00-$3F/$80-$BF map hardware and open-bus reads there are outside the model. */
    if ((uint8_t)a < 0x40 || ((uint8_t)a >= 0x80 && (uint8_t)a < 0xC0)) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const bool overflow = r->v;
    const uint16_t sp0 = r->sp;
    /* PHB, PHA, PLB: the callee's source window walks over the stack, so the pushed bytes are real data. */
    RAM8(sp0) = r->db;
    RAM8(sp0 - 1) = (uint8_t)a;
    RAM16_SET(0x0002, x);
    uint8_t value = RAM8(0x0003);
    RAM8(0x0004) = value >> 1;
    RAM8(0x0001) = (uint8_t)(value >> 1 << 1 << 3) | RAM8(0x0001);
    RAM8(0x0000) = 0;
    uint16_t value3 = RAM16(0x0000);
    uint8_t value4 = RAM8(0x0004);
    uint8_t a1;
    bool overflow1;
    if (value4 < 3) {
        a1 = value4;
        overflow1 = overflow;
    } else {
        a1 = (uint8_t)(value4 - 3 - (value4 >= 3 ^ 1));
        overflow1 = ((value4 ^ 3) & (value4 ^ (uint8_t)(value4 - 3 - (value4 >= 3 ^ 1))) & 0x80) != 0;
    }
    r->v = overflow1;
    r->c = true; /* CMP #$00 */
    if (a1 == 0) {
        r->a = (a & 0xFF00) | a1;
        r->z = true;
        r->n = false;
        r->x = value3;
        r->mf = 1;
        r->db = (uint8_t)a;
        r->sp -= 1;
        JSR(c, 0xC5CE, 0xC1C5D1); /* convert_object_graphics_planes_masked */
        r->sp += 1;
        r->mf = 1;
        r->xf = 0;
        r->db = RAM8(sp0); /* PLB */
        RETURN_RTL(c);
    }
    const uint8_t a2 = (uint8_t)(a1 - 1); /* DEC */
    if (a2 == 0) {
        r->a = (a & 0xFF00) | a2;
        r->z = true;
        r->n = false;
        r->x = value3;
        r->mf = 1;
        r->db = (uint8_t)a;
        r->sp -= 1;
        JSR(c, 0xC5C9, 0xC1C731); /* convert_object_graphics_planes_xor */
        r->sp += 1;
        r->mf = 1;
        r->xf = 0;
        r->db = RAM8(sp0); /* PLB */
        RETURN_RTL(c);
    }
    r->a = (a & 0xFF00) | a2;
    r->z = false;
    r->n = a2 & 0x80;
    r->x = value3;
    r->mf = 1;
    r->db = (uint8_t)a;
    r->sp -= 1;
    JSR(c, 0xC5C4, 0xC1C8A9); /* convert_object_graphics_planes_inverted */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->db = RAM8(sp0); /* PLB */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1C599, SOM_RTL, "hand", dispatch_object_graphics_plane_conversion, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 0, 0, 56, 34)
