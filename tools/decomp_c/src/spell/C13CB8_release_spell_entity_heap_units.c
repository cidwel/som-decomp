#include "som_c.h"

/* C13CB8 release_spell_entity_heap_units   [class B, 113 bytes, 63 instructions]
 * Source: src/rom/release_spell_entity_heap_units.s
 * Documented in docs/actor-cast-entity-memory.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01CC.  Callers read: BY.
 */
static void release_spell_entity_heap_units(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01CC) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xCC;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 9), x);
    if (x != 0) {
        if (((uint16_t)(x - 0x8200) & 0x3F) == 0) {
            uint16_t value = RAM16(0x0002 + (uint16_t)(sp0 - 9));
            RAM8(0x0001 + (uint16_t)(sp0 - 9)) = (uint8_t)((uint16_t)(value - 0x8200) >> 6);
            uint8_t value2 = RAM8(0x823A + (((uint16_t)(value - 0x8200) >> 6) & 0xFF));
            RAM8(0x0004 + (uint16_t)(sp0 - 9)) = value2;
            if (value2 != 0) {
                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = RAM8(0x823A + (((uint16_t)(value - 0x8200) >> 6) & 0xFF));
                RAM8(0x0000 + sp0 - 9) = 0;
                RAM8(0x0000 + sp0 - 0x0A) = ((uint16_t)(value - 0x8200) >> 6) & 0xFF;
                uint16_t x1 = ((uint16_t)(value - 0x8200) >> 6) & 0xFF;
                do {
                    RAM8(0x823A + x1) = 0;
                    RAM8(0x832A + x1) = 0;
                    RAM8(0x0006 + (uint16_t)(sp0 - 9))--;
                    x1 = (uint16_t)(x1 + 1);
                } while (RAM8(0x0006 + (uint16_t)(sp0 - 9)) != 0);
                uint8_t a_hi1 = 0;
                uint16_t x2 = ((uint16_t)(value - 0x8200) >> 6) & 0xFF;
                for (;;) {
                    uint8_t value5 = RAM8(0x823A + (uint16_t)(x2 - 1));
                    uint8_t value6 = RAM8(0x0004 + (uint16_t)(sp0 - 9));
                    if ((uint8_t)(value5 - value6) != 0) {
                        if (value5 >= value6) {
                            RAM8(0x823A + (uint16_t)(x2 - 1)) = (uint8_t)(value5 - value6);
                            x2 = (uint16_t)(x2 - 1);
                            continue;
                        }
                    }
                    x2 = (uint16_t)(x2 - 1);
                    break;
                }
                uint8_t value7 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
                if (value7 < RAM8(0x8238)) {
                    RAM8(0x8238) = value7;
                }
            }
        }
    }
    r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
    r->y = y;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13CB8, SOM_RTS, "gen", release_spell_entity_heap_units, 0, L_B | L_Y, 11, 1, 0, 113, 63)
