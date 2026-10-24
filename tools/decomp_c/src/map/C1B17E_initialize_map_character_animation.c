#include "som_c.h"

/* C1B17E initialize_map_character_animation   [class B, 82 bytes, 44 instructions]
 * Source: src/rom/initialize_map_character_animation.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: BX.
 */
static void initialize_map_character_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    uint8_t value = RAM8(0x001C);
    if ((value & 0x40) != 0) {
        RAM8(0x0012) = 0;
        RAM8(0x0000 + sp0) = db;
        RAM8(0x0000 + sp0 - 1) = 0x7F;
        uint16_t value2 = BUS16(c, 0xC80602 + ((((a_hi << 8) | value) & 0x3F) << 1));
        uint16_t value3 = BUS16(c, 0xC80600 + ((((a_hi << 8) | value) & 0x3F) << 1));
        uint8_t a1;
        uint8_t a_hi1;
        if ((uint16_t)(value2 - value3) >> 1 < 0x11) {
            a1 = (uint8_t)((uint16_t)(value2 - value3) >> 1);
            a_hi1 = (uint16_t)(value2 - value3) >> 1 >> 8;
        } else {
            a1 = 0x10;
            a_hi1 = 0;
        }
        RAM16_SET(0x0010, (a_hi1 << 8) | a1);
        RAM8(0x009A) = a1;
        uint16_t value4 = BUS16(c, 0xC80600 + ((((a_hi << 8) | value) & 0x3F) << 1));
        RAM16_SET(0x0006, 0x8400);
        RAM16_SET(0x0014, 0);
        uint8_t a_hi2 = 0x84;
        uint16_t x1 = value4;
        uint8_t data_bank = 0x7F;
        do {
            RAM8(0x0000 + sp0 - 1) = x1 >> 8;
            RAM8(0x0000 + sp0 - 2) = (uint8_t)x1;
            r->a = (a_hi2 << 8) | a;
            r->x = x1;
            r->mf = 0;
            r->xf = 0;
            r->db = data_bank;
            r->dp = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB1C2, 0xC1B1D0); GUARD_JSR(c, sp_call, 0xB1C2); } /* prepare_map_character_animation_record_and_frames */
            r->sp += 3;
            uint8_t db_ret = r->db;
            uint16_t a_all = r->a;
            uint8_t value5 = RAM8(0x0000 + sp0 - 2);
            uint8_t value6 = RAM8(0x0000 + sp0 - 1);
            RAM16_SET(0x0010, (uint16_t)(RAM16(0x0010) - 1));
            a_hi2 = a_all >> 8;
            x1 = (uint16_t)(((value6 << 8) | value5) + 2);
            data_bank = db_ret;
        } while (RAM16(0x0010) != 0);
        uint8_t value7 = RAM8(0x0000 + sp0);
        r->a = (a_hi2 << 8) | a;
        r->x = (uint8_t)x1;
        r->mf = 1;
        r->xf = 1;
        r->db = value7;
        r->dp = 0;
        RETURN_RTL(c);
    }
    RAM8(0x009A) = 0;
    r->x = value;
    r->xf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1B17E, SOM_RTL, "gen", initialize_map_character_animation, 0, L_B | L_X, 3, 1, -1, 82, 44)
