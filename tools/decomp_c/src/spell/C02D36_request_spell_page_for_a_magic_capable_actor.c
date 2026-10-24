#include "som_c.h"

/* C02D36 request_spell_page_for_a_magic_capable_actor   [class B, 57 bytes, 22 instructions]
 * Source: src/rom/request_spell_page_for_a_magic_capable_actor.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void request_spell_page_for_a_magic_capable_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x19FE);
    if (value == 0) {
        SET_A8(r, value);
        r->z = value == 0;
        r->n = value & 0x80;
        RETURN_RTS(c);
    }
    RAM8(0xA210) = 8;
    RAM8(0xA17A) = RAM8(0xA211);
    uint8_t value3 = RAM8(0xA17B);
    RAM8(0xA211) = value3;
    r->a = (a_hi << 8) | value3;
    r->z = value3 == 0;
    r->n = value3 & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2D63, 0xC01BA5); GUARD_JSR(c, sp_call, 0x2D63); } /* preserve_accumulator_byte_and_request_fixed_local_audio_presets */
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xA20A);
    BUS8_SET(c, (db_ret << 0x10) + 0xA20A, value4 & 0xBF);
    uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0xA20A);
    BUS8_SET(c, (db_ret << 0x10) + 0xA20A, value5 | 1);
    SET_A8(r, 1);
    r->z = (value5 & 1) == 0;
    r->n = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02D36, SOM_RTS, "gen", request_spell_page_for_a_magic_capable_actor, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 57, 22)
