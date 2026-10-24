#include "som_c.h"

/* D04E6E read_actor_element_spell_level   [class A, 62 bytes, 30 instructions]
 * Source: src/rom/read_actor_element_spell_level.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void read_actor_element_spell_level(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    if (RAM8(ACTOR_KIND_FLAGS + y) & 0x80) {
        uint16_t battle_attacker_ptr = RAM16(BATTLE_ATTACKER_PTR);
        RAM16_SET(BATTLE_MUL_WORK, battle_attacker_ptr);
        RAM8(BATTLE_MUL_WORK) = RAM8(0xE177 + battle_attacker_ptr);
        RAM8(0x039E) = RAM8(0xE1D8 + RAM16(BATTLE_MUL_WORK));
        uint8_t battle_mul_work2 = RAM8(BATTLE_MUL_WORK);
        RAM8(BATTLE_MUL_WORK) >>= 1;
        RAM8(0x0000 + sp0) = (((((RAM8(BATTLE_MUL_WORK) >> 7 << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | ((RAM8(BATTLE_MUL_WORK) == 0) << 1)) | (battle_mul_work2 & 1);
        RAM8(0x03D0) = RAM8(0xE1C4 + RAM16(BATTLE_MUL_WORK));
        bool carry1;
        if (battle_mul_work2 & 0x01) {
            carry1 = battle_mul_work2 & 0x01;
        } else {
            RAM8(0x03D0) >>= 1;
            RAM8(0x03D0) >>= 1;
            RAM8(0x03D0) >>= 1;
            uint8_t value8 = RAM8(0x03D0);
            RAM8(0x03D0) >>= 1;
            carry1 = value8 & 0x01;
        }
        RAM8(0x039D) = RAM8(0x03D0) & 0x0F;
        r->y = RAM16(BATTLE_ATTACKER_PTR);
        r->c = carry1;
        RETURN_RTS(c);
    }
    RAM8(0x039D) = RAM8(0xE1C4 + y);
    RAM8(0x039E) = RAM8(0xE1D8 + y);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD04E6E, SOM_RTS, "gen", read_actor_element_spell_level, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 62, 30)
