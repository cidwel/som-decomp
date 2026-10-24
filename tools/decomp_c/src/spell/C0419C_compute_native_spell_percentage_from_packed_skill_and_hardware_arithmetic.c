#include "som_c.h"

/* C0419C compute_native_spell_percentage_from_packed_skill_and_hardware_arithmetic   [class B, 103 bytes, 56 instructions]
 * Source: src/rom/compute_native_spell_percentage_from_packed_skill_and_hardware_arithmetic.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABCV.
 */
static void compute_native_spell_percentage_from_packed_skill_and_hardware_arithmetic(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = 0x7E;
    RAM8(0x0000 + sp0 - 3) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 4) = a_hi;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)((a_hi << 8) | a);
    BUS8_SET(c, 0x004202, ((a_hi << 8) | a) & 0xFF);
    BUS8_SET(c, 0x004203, 0x63);
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    RAM16_SET(BATTLE_TEMP_A4, y);
    RAM8(BATTLE_TEMP_A6) = RAM8(0xE1C0 + ((x >> 8 << 8) | ((uint8_t)y >> 1)));
    if ((RAM8(BATTLE_TEMP_A4) & 1) == 0) {
        RAM8(BATTLE_TEMP_A6) >>= 1;
        RAM8(BATTLE_TEMP_A6) >>= 1;
        RAM8(BATTLE_TEMP_A6) >>= 1;
        RAM8(BATTLE_TEMP_A6) >>= 1;
    }
    uint8_t battle_temp_a65 = RAM8(BATTLE_TEMP_A6);
    uint16_t value2 = BUS16(c, 0x004216);
    BUS16_SET(c, 0x004204, value2);
    uint8_t value3 = BUS8(c, 0xC043AC + (battle_temp_a65 & 0x0F));
    BUS8_SET(c, 0x004206, value3);
    uint8_t value4 = BUS8(c, 0x004214);
    r->a = (value2 >> 8 << 8) | value4;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0419C, SOM_RTL, "gen", compute_native_spell_percentage_from_packed_skill_and_hardware_arithmetic, 0, L_A | L_B | L_C | L_V, 6, 1, 0, 103, 56)
