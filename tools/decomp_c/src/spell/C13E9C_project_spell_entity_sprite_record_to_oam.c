#include "som_c.h"

/* C13E9C project_spell_entity_sprite_record_to_oam   [class B, 213 bytes, 108 instructions]
 * Source: src/rom/project_spell_entity_sprite_record_to_oam.s
 * Documented in docs/actor-cast-entity-oam.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01DA.  Callers read: Y.
 */
static void project_spell_entity_sprite_record_to_oam(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01DA) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xDA;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    uint8_t value = RAM8(0x000A + x);
    RAM8(0x0001 + (uint16_t)(sp0 - 6)) = value;
    uint16_t value2 = RAM16(0x841E);
    if ((RAM16(0x0008 + x) & 0xFF) == 0) {
        RAM8(0x0001 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2)) = 0xF0;
    } else {
        if ((uint16_t)(RAM16(0x0002 + x) + 0x10) >= 0xF0) {
            RAM8(0x0001 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2)) = 0xF0;
        } else {
            uint16_t value5 = RAM16(0x0004 + x);
            if ((uint16_t)(value5 + 0x10) < 0x0110) {
                RAM8(0x0000 + sp0 - 6) = (RAM8(0x000B + x) & 3) << 1 << 1 << 1;
                RAM8(0x0000 + sp0 - 6) = (uint8_t)(((RAM8(0x0001 + x) & 7) | RAM8(0x0000 + sp0 - 6)) << 1);
                RAM8(0x0000 + sp0 - 6) = (RAM8(0x0007 + x) & 1) | RAM8(0x0000 + sp0 - 6);
                RAM8(0x0003 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2)) = (RAM8(0x0000 + x) & 0xC0) | RAM8(0x0000 + sp0 - 6);
                RAM8(0x0002 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2)) = RAM8(0x0006 + x);
                RAM8(0x0001 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2)) = RAM8(0x0002 + x);
                RAM8(0x0000 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2)) = RAM8(0x0004 + x);
                if (RAM8(0x8421) == 0) {
                    RAM8(0x0000 + sp0 - 6) = RAM8(0x0000 + x) & 2;
                    RAM8(0x0000 + sp0 - 6) = (RAM8(0x0005 + x) & 1) | RAM8(0x0000 + sp0 - 6);
                    RAM8(0x0002 + (uint16_t)(sp0 - 6)) = (RAM8(0x0001 + (uint16_t)(sp0 - 6)) & 3) + 1;
                    RAM8(0x0003 + (uint16_t)(sp0 - 6)) = 3;
                    uint8_t a1 = RAM8(0x0000 + sp0 - 6);
                    uint8_t a_hi1 = (uint16_t)(value5 + 0x10) >> 8;
                    for (;;) {
                        RAM8(0x0002 + (uint16_t)(sp0 - 6))--;
                        if (RAM8(0x0002 + (uint16_t)(sp0 - 6)) != 0) {
                            RAM8(0x0003 + (uint16_t)(sp0 - 6)) <<= 1;
                            RAM8(0x0003 + (uint16_t)(sp0 - 6)) <<= 1;
                            a1 = (uint8_t)(a1 << 2);
                            continue;
                        }
                        break;
                    }
                    RAM8(0x0000 + sp0 - 6) = a1;
                    RAM8(0x0003 + (uint16_t)(sp0 - 6)) ^= 0xFF;
                    uint8_t value25 = RAM8(0x0001 + (uint16_t)(sp0 - 6));
                    uint16_t value26 = RAM16(0x841E);
                    RAM8(0x0200 + (uint16_t)((((a_hi1 << 8) | (value25 >> 2)) & 0x1F) + value26)) = (RAM8(0x0200 + (uint16_t)((((a_hi1 << 8) | (value25 >> 2)) & 0x1F) + value26)) & RAM8(0x0003 + (uint16_t)(sp0 - 6))) | RAM8(0x0000 + sp0 - 6);
                }
            } else {
                RAM8(0x0001 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2)) = 0xF0;
            }
        }
    }
    uint8_t value34 = RAM8(0x0000 + sp0 - 2);
    uint8_t value35 = RAM8(0x0000 + sp0 - 1);
    uint8_t value36 = RAM8(0x0000 + sp0);
    r->y = x;
    r->mf = value34 & 0x20;
    r->xf = value34 & 0x10;
    r->dp = (value36 << 8) | value35;
    r->i = value34 & 0x04;
    r->d = value34 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13E9C, SOM_RTS, "gen", project_spell_entity_sprite_record_to_oam, 0, L_Y, 7, 1, 0, 213, 108)
