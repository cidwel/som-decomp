#include "som_c.h"

/* D0D9DE read_item_base_stat_from_native_ten_byte_table   [class A, 24 bytes, 15 instructions]
 * Source: src/rom/read_item_base_stat_from_native_ten_byte_table.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABYV.
 */
static void read_item_base_stat_from_native_ten_byte_table(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t value = BUS16(c, 0xD03ED1 + ((a & 0x3F) << 1 << 1 << 1) + ((a & 0x3F) << 1));
    r->a = value & 0xFF;
    r->v = ((((a & 0x3F) << 1 << 1 << 1) ^ ((a & 0x3F) << 1 << 1 << 1) + ((a & 0x3F) << 1)) & (((a & 0x3F) << 1) ^ ((a & 0x3F) << 1 << 1 << 1) + ((a & 0x3F) << 1)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D9DE, SOM_RTS, "gen", read_item_base_stat_from_native_ten_byte_table, 0, L_A | L_B | L_Y | L_V, 4, 0, 0, 24, 15)
