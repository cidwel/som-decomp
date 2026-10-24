#include "som_c.h"

static void append_native_saved_slot_text_space_token(SomCtx *c);

/* C75386 append_two_native_saved_slot_text_space_tokens   [class C, 14 bytes, 7 instructions]
 * Source: src/rom/append_two_native_saved_slot_text_space_tokens.s
 * Documented in docs/ui-native-loaded-game-slot-descriptions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void append_two_native_saved_slot_text_space_tokens(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR_LOCAL(c, 0x5388, append_native_saved_slot_text_space_token); GUARD_JSR(c, sp_call, 0x5388); }
    uint8_t db_ret = r->db;
    uint16_t x_ret = r->x;
    BUS8_SET(c, (db_ret << 0x10) + 0x9C00 + x_ret, 0x80);
    SET_A8(r, 0x80);
    r->x = (uint16_t)(x_ret + 1);
    r->z = (uint16_t)(x_ret + 1) == 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75386, SOM_RTS, "gen", append_two_native_saved_slot_text_space_tokens, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 14, 7)

/* C75389 append_native_saved_slot_text_space_token   [class A, 9 bytes, 5 instructions]
 * Source: src/rom/append_two_native_saved_slot_text_space_tokens.s
 * Subroutine of append_two_native_saved_slot_text_space_tokens, translated in place.
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void append_native_saved_slot_text_space_token(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM8(0x9C00 + x) = 0x80;
    SET_A8(r, 0x80);
    r->x = (uint16_t)(x + 1);
    r->z = (uint16_t)(x + 1) == 0;
    r->n = (uint16_t)(x + 1) & 0x8000;
    RETURN_RTS(c);
}
