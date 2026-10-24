#include "som_c.h"

/* 7EB081 allocate_boot_heap_bytes_without_fill   [class A, 32 bytes, 24 instructions]
 * Source: src/boot/allocate_boot_heap_bytes_without_fill.s
 * Documented in docs/boot-title-hdma-resources.md
 * Entry: M=any X=16 bit DB=$7F D=any.  Callers read: BXYCV.
 */
static void allocate_boot_heap_bytes_without_fill(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, -1, 0)) return;
    const uint8_t m_entry = r->mf;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    r->a = (uint16_t)(x + 0x7F) >> 7;
    r->c = (uint16_t)(x + 0x7F) >> 6 & 0x01;
    r->z = (uint16_t)(x + 0x7F) >> 7 == 0;
    r->n = (uint16_t)(x + 0x7F) >> 7 & 0x8000;
    r->v = ((x ^ (uint16_t)(x + 0x7F)) & ((uint16_t)(x + 0x7F) ^ 0x7F) & 0x8000) != 0;
    r->mf = 0;
    r->sp -= 4;
    JSR(c, 0xB09C, 0x7EAF59); /* allocate_128_byte_units */
    r->sp += 4;
    r->c = carry;
    r->v = overflow;
    r->mf = m_entry;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB081, SOM_RTS, "gen", allocate_boot_heap_bytes_without_fill, 0, L_B | L_X | L_Y | L_C | L_V, 5, -1, 0, 32, 24)
