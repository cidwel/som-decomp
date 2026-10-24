#include "som_c.h"
#include "som_hand.h"

/* C144F7 release_spell_entity_register_record   [class A, 29 bytes, 18 instructions]
 * Source: src/rom/release_spell_entity_register_record.s
 * Documented in docs/actor-cast-entity-registers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void release_spell_entity_register_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;
    /* PHD, PHP */
    RAM8(sp0) = r->dp >> 8;
    RAM8((uint16_t)(sp0 - 1)) = (uint8_t)r->dp;
    RAM8((uint16_t)(sp0 - 2)) = hand_p_byte(r);
    RAM8((uint16_t)(sp0 - 3)) = r->db; /* PHB */
    r->db = 0x7E;
    r->sp = (uint16_t)(sp0 - 4);
    const uint16_t x = r->x;
    r->mf = 0;
    r->a = x;
    if (x != 0) {
        const uint16_t value = RAM16(0x8428);
        RAM16_SET(x, value);
        RAM16_SET(0x8428, x);
        r->a = value;
    }
    r->sp = (uint16_t)(sp0 - 4);
    hand_plb(c);
    hand_plp(c);
    hand_pld(c);
    r->z = r->dp == 0;
    r->n = (r->dp & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC144F7, SOM_RTS, "hand", release_spell_entity_register_record, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, -1, -1, 29, 18)
