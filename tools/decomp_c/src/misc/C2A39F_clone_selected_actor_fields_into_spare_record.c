#include "som_c.h"

/* C2A39F clone_selected_actor_fields_into_spare_record   [class C, 104 bytes, 53 instructions]
 * Source: src/rom/clone_selected_actor_fields_into_spare_record.s
 * Documented in docs/actor-action-spare-records.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void clone_selected_actor_fields_into_spare_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    r->a = 0x6B;
    r->x = x | 0xE000;
    r->y = y | 0xE000;
    i_mvn(c, 0x7E, 0x7E); /* copy up bank $7E to bank $7E */
    uint16_t x_moved = r->x;
    uint16_t y_moved = r->y;
    r->a = 0x15;
    r->x = (uint16_t)(x_moved + 4);
    r->y = (uint16_t)(y_moved + 4);
    i_mvn(c, 0x7E, 0x7E); /* copy up bank $7E to bank $7E */
    uint16_t x_moved2 = r->x;
    uint16_t y_moved2 = r->y;
    r->a = 0x0173;
    r->x = (uint16_t)(x_moved2 + 6);
    r->y = (uint16_t)(y_moved2 + 6);
    i_mvn(c, 0x7E, 0x7E); /* copy up bank $7E to bank $7E */
    RAM8(0x0000) = RAM8(0xE08B + x) & 0xF0;
    RAM8(0xE08B + y) = (RAM8(0xE08B + y) & 0x0F) | RAM8(0x0000);
    RAM8(0xE030 + y) = 0xFF;
    RAM8(0xE104 + y) = 0;
    RAM8(0xE100 + y) = 0;
    RAM8(0xE083 + y) = 0;
    RAM8(0xE084 + y) = 0;
    RAM8(0xE01C + y) = 0;
    RAM8(0xE00A + y) = 0;
    RAM8(0xE064 + y) = 0;
    RAM8(0xE062 + y) = 0;
    r->x = y;
    r->y = y;
    r->c = x_moved2 + 6 > 0xFFFF;
    r->v = ((x_moved2 ^ (uint16_t)(x_moved2 + 6)) & ((uint16_t)(x_moved2 + 6) ^ 6) & 0x8000) != 0;
    r->mf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2A39F, SOM_RTL, "gen", clone_selected_actor_fields_into_spare_record, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 4, 0, 0, 104, 53)
