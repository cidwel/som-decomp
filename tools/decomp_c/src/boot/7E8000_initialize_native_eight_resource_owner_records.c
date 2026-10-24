#include "som_c.h"

/* 7E8000 initialize_native_eight_resource_owner_records   [class A, 26 bytes, 16 instructions]
 * Source: src/boot/initialize_native_eight_resource_owner_records.s
 * Documented in docs/boot-native-subsystem-resources.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: BYCZNV.
 */
static void initialize_native_eight_resource_owner_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool overflow = r->v;
    r->a = (a >> 8 << 8) | 0;
    r->x = 0x40;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->sp -= 4;
    JSR(c, 0x8012, 0x7EB0A1); /* allocate_and_fill_bytes */
    r->sp += 4;
    uint16_t x_ret = r->x;
    RAM16_SET(0x10016, x_ret);
    r->c = carry;
    r->z = 1;
    r->n = 0;
    r->v = overflow;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E8000, SOM_RTS, "gen", initialize_native_eight_resource_owner_records, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 5, 0, 0, 26, 16)
