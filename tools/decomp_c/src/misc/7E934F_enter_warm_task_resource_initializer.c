#include "som_c.h"

/* 7E934F enter_warm_task_resource_initializer   [class C, 21 bytes, 14 instructions]
 * Source: src/boot/enter_warm_task_resource_initializer.s
 * Documented in docs/boot-native-warm-sprite-pool.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void enter_warm_task_resource_initializer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    r->z = 0;
    r->n = 0;
    r->db = 0x7F;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x935C, 0x7E9558); GUARD_JSR(c, sp_call, 0x935C); } /* initialize_warm_task_sprite_pool_prefix */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x935F, 0x7E95E8); GUARD_JSR(c, sp_call, 0x935F); } /* enter_warm_runtime_and_call_brightness_fade */
    r->sp += 4;
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->c = value2 & 0x01;
    r->z = ((value4 << 8) | value3) == 0;
    r->n = ((value4 << 8) | value3) & 0x8000;
    r->v = value2 & 0x40;
    r->mf = value2 & 0x20;
    r->xf = value2 & 0x10;
    r->db = value;
    r->dp = (value4 << 8) | value3;
    r->i = value2 & 0x04;
    r->d = value2 & 0x08;
    RETURN_RTL(c);
}
SOM_REGISTER(0x7E934F, SOM_RTL, "gen", enter_warm_task_resource_initializer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 21, 14)
