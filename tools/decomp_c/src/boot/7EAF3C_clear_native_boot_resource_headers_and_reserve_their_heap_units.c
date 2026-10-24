#include "som_c.h"

/* 7EAF3C clear_native_boot_resource_headers_and_reserve_their_heap_units   [class A, 29 bytes, 19 instructions]
 * Source: src/boot/clear_native_boot_resource_headers_and_reserve_their_heap_units.s
 * Documented in docs/boot-native-resource-memory.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: CV.
 */
static void clear_native_boot_resource_headers_and_reserve_their_heap_units(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    r->a = (a >> 8 << 8) | 0;
    r->x = 0;
    r->y = x;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->sp -= 6;
    JSR(c, 0xAF50, 0x7EC37D); /* fill_native_boot_memory_using_words_or_forward_copy */
    r->sp += 6;
    r->x = x;
    r->z = x == 0;
    r->n = x & 0x8000;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 4;
    JSR(c, 0xAF54, 0x7EB081); /* allocate_boot_heap_bytes_without_fill */
    r->sp += 4;
    r->c = carry;
    r->v = overflow;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EAF3C, SOM_RTS, "gen", clear_native_boot_resource_headers_and_reserve_their_heap_units, 0, L_C | L_V, 6, 0, 0, 29, 19)
