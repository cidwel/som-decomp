#include "som_c.h"

/* 7EB416 release_warm_particle_sprite_and_heap_workspace   [class A, 21 bytes, 13 instructions]
 * Source: src/boot/release_warm_particle_sprite_and_heap_workspace.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$06F4.  Callers read: nothing.
 */
static void release_warm_particle_sprite_and_heap_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x06F4) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 6;
    RAM8(0x0000 + sp0 - 1) = 0xF4;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    uint16_t value = BUS16(c, 0x7F0000 + x);
    r->x = value;
    r->y = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB423, 0x7EB786); GUARD_JSR(c, sp_call, 0xB423); } /* release_native_sprite_or_linked_group */
    r->sp += 5;
    bool x_ret = r->xf;
    if (x_ret) {
        c->fail = 3;
        return;
    } else {
        uint8_t value6 = RAM8(0x0000 + sp0 - 4);
        uint8_t value7 = RAM8(0x0000 + sp0 - 3);
        r->x = (value7 << 8) | value6;
        r->z = ((value7 << 8) | value6) == 0;
        r->n = ((value7 << 8) | value6) & 0x8000;
        r->xf = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB427, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xB427); } /* release_native_heap_suffix_through_bank_7f_api */
        r->sp += 3;
        uint8_t value8 = RAM8(0x0000 + sp0 - 2);
        uint8_t value9 = RAM8(0x0000 + sp0 - 1);
        uint8_t value10 = RAM8(0x0000 + sp0);
        r->mf = value8 & 0x20;
        r->xf = value8 & 0x10;
        r->dp = (value10 << 8) | value9;
        r->i = value8 & 0x04;
        r->d = value8 & 0x08;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7EB416, SOM_RTS, "gen", release_warm_particle_sprite_and_heap_workspace, 0, 0, 5, 1, 0, 21, 13)
