#include "som_c.h"
#include "som_hand_b.h"

/* C2A7AD set_map_layer_paired_parameters   [class A, 40 bytes, 19 instructions]
 * Source: src/rom/set_map_layer_paired_parameters.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void set_map_layer_paired_parameters(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t selector = (uint8_t)((r->a & 0x0F) << 1); /* AND #$0F, ASL: overwritten by the first load below */
    r->a = (r->a & 0xFF00) | selector;
    i_phx(c);
    r->mf = 0; /* REP #$20 */
    r->a = BUS16(c, 0x480000u + r->x);
    hand_nz16(r, r->a);
    JSR_CHK(c, 0xA7B9, 0xC2A7D5); /* set_map_layer_packed_parameters */
    r->mf = 0; /* REP #$20 */
    uint16_t y = r->y;
    uint16_t next = (uint16_t)(y + 0x10);
    r->v = (((y ^ next) & (0x10 ^ next)) & 0x8000) != 0;
    r->c = (uint32_t)y + 0x10 > 0xFFFF;
    r->a = next;
    r->y = next;
    hand_nz16(r, next);
    r->a = BUS16(c, 0x480002u + r->x);
    hand_nz16(r, r->a);
    JSR_CHK(c, 0xA7C8, 0xC2A7D5);
    r->mf = 1; /* SEP #$20 */
    r->a = (r->a & 0xFF00) | 3;
    hand_nz8(r, 3);
    BUS8_SET(c, 0x000A82u + r->y, 3);
    BUS8_SET(c, 0x000A92u + r->y, 3);
    i_plx(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A7AD, SOM_RTS, "hand", set_map_layer_paired_parameters, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 40, 19)
