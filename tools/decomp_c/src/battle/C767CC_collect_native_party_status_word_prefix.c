#include "som_c.h"

static void collect_native_party_status_byte_shared_tail(SomCtx *c);

/* C767CC collect_native_party_status_word_prefix   [class A, 12 bytes, 6 instructions]
 * Source: src/rom/collect_native_party_status_word_prefix.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void collect_native_party_status_word_prefix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR_LOCAL(c, 0x67CE, collect_native_party_status_byte_shared_tail); GUARD_JSR(c, sp_call, 0x67CE); }
    uint8_t db_ret = r->db;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    uint8_t value = BUS8(c, (db_ret << 0x10) + 0xE180 + y_ret);
    BUS8_SET(c, (db_ret << 0x10) + 0xA1E0 + x_ret, value);
    r->x = (uint16_t)(x_ret + 1);
    r->y = (uint16_t)(y_ret + 1);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC767CC, SOM_RTS, "gen", collect_native_party_status_word_prefix, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 12, 6)

/* C767CF collect_native_party_status_byte_shared_tail   [class A, 9 bytes, 5 instructions]
 * Source: src/rom/collect_native_party_status_word_prefix.s
 * Subroutine of collect_native_party_status_word_prefix, translated in place.
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void collect_native_party_status_byte_shared_tail(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0xE180 + y);
    RAM8(0xA1E0 + x) = value;
    SET_A8(r, value);
    r->x = (uint16_t)(x + 1);
    r->y = (uint16_t)(y + 1);
    r->z = (uint16_t)(y + 1) == 0;
    r->n = (uint16_t)(y + 1) & 0x8000;
    RETURN_RTS(c);
}
