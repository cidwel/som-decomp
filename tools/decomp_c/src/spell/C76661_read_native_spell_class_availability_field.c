#include "som_c.h"

/* C76661 read_native_spell_class_availability_field   [class A, 15 bytes, 7 instructions]
 * Source: src/rom/read_native_spell_class_availability_field.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void read_native_spell_class_availability_field(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM16_SET(0xA171, 0x48);
    r->x = 0x48;
    r->z = 0;
    r->n = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x666A, 0xC766BF); GUARD_JSR(c, sp_call, 0x666A); } /* derive_native_selected_actor_field_offset */
    r->sp += 2;
    uint16_t x_ret = r->x;
    uint8_t value = RAM8(0xE180 + x_ret);
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    SET_A8(r, value);
    r->x = (value3 << 8) | value2;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76661, SOM_RTS, "gen", read_native_spell_class_availability_field, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 15, 7)
