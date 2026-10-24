#include "som_c.h"
#include "som_hand_b.h"

/* C223DA boss_loader_create_descriptor_object   [class A, 13 bytes, 6 instructions]
 * Source: src/rom/boss_loader_create_descriptor_object.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void boss_loader_create_descriptor_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value; BUS16_OK(c, ((uint32_t)RAM8(0x0032 + dp) << 0x10) + RAM16(0x0030 + dp), value);
    RAM16_SET(0x0030 + dp, (uint16_t)(RAM16(0x0030 + dp) + 1));
    RAM16_SET(0x0030 + dp, (uint16_t)(RAM16(0x0030 + dp) + 1));
    r->a = value;
    { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0x23E2, 0xC23438); GUARD_JSR_DB(c, sp_call, 0x23E2, db_call); } /* allocate_boss_object_from_descriptor */
    { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0x23E5, 0xC22293); GUARD_JSR_DB(c, sp_call, 0x23E5, db_call); } /* prepare_boss_object_identity_palette_and_terrain */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC223DA, SOM_RTS, "hand", boss_loader_create_descriptor_object, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 13, 6)
