#include "som_c.h"

/* 7EB342 construct_warm_particle_sprite_and_six_byte_workspace   [class B, 102 bytes, 50 instructions]
 * Source: src/boot/construct_warm_particle_sprite_and_six_byte_workspace.s
 * Documented in docs/boot-native-warm-particle.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$06F4.  Callers read: BXCZNV.
 */
static void construct_warm_particle_sprite_and_six_byte_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x06F4) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 6;
    RAM8(0x0000 + sp0 - 1) = 0xF4;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->a = ((uint16_t)(sp0 - 7) >> 8 << 8) | 0;
    r->x = 6;
    r->c = (uint16_t)(sp0 - 3) >= 4;
    r->z = 1;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 4) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 7);
    r->sp -= 7;
    JSR(c, 0xB356, 0x7EB0A1); /* allocate_and_fill_bytes */
    r->sp += 7;
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), x_ret);
    r->a = (a_all >> 8 << 8) | 0x0B;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 7;
    JSR(c, 0xB35D, 0x7EB6D0); /* allocate_native_single_sprite_record_prefix */
    r->sp += 7;
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), x_ret2);
    RAM8(0x10001 + x_ret2) = 8;
    RAM8(0x10000 + x_ret2) = 0;
    r->a = (a_all2 >> 8 << 8) | 0x30;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 7;
    JSR(c, 0xB36C, 0x7EC288); /* draw_native_random_byte_below_low_byte_limit */
    r->sp += 7;
    uint16_t a_all3 = r->a;
    uint16_t value = RAM16(0x0003 + (uint16_t)(sp0 - 7));
    RAM16_SET(0x10002 + value, (uint16_t)(a_all3 + 0x38));
    r->a = 0x70;
    r->x = value;
    r->c = a_all3 + 0x38 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((a_all3 ^ (uint16_t)(a_all3 + 0x38)) & ((uint16_t)(a_all3 + 0x38) ^ 0x38) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 7;
    JSR(c, 0xB37D, 0x7EC288); /* draw_native_random_byte_below_low_byte_limit */
    r->sp += 7;
    uint16_t a_all4 = r->a;
    uint16_t value2 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
    RAM16_SET(0x10004 + value2, (uint16_t)(a_all4 + 0x80));
    RAM16_SET(0x10006 + value2, 0x20);
    uint16_t value3 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
    RAM16_SET(0x10000 + value3, value2);
    r->a = 0x10;
    r->x = value3;
    r->c = a_all4 + 0x80 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((a_all4 ^ (uint16_t)(a_all4 + 0x80)) & ((uint16_t)(a_all4 + 0x80) ^ 0x80) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 7;
    JSR(c, 0xB398, 0x7EC288); /* draw_native_random_byte_below_low_byte_limit */
    r->sp += 7;
    uint16_t a_all5 = r->a;
    uint16_t value4 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
    RAM16_SET(0x10004 + value4, (uint16_t)(a_all5 + 1));
    uint8_t value9 = RAM8(0x0000 + sp0 - 1);
    uint8_t value10 = RAM8(0x0000 + sp0);
    r->a = (r->a & 0x00FF) | (((uint16_t)(a_all5 + 1) >> 8) << 8);
    r->x = value4;
    r->c = carry;
    r->z = ((value10 << 8) | value9) == 0;
    r->n = ((value10 << 8) | value9) & 0x8000;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    r->dp = (value10 << 8) | value9;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB342, SOM_RTS, "gen", construct_warm_particle_sprite_and_six_byte_workspace, 0, L_B | L_X | L_C | L_Z | L_N | L_V, 7, 1, 0, 102, 50)
