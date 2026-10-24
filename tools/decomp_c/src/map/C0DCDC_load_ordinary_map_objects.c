#include "som_c.h"

/* C0DCDC load_ordinary_map_objects   [class B, 32 bytes, 16 instructions]
 * Source: src/rom/load_ordinary_map_objects.s
 * Documented in docs/maps.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void load_ordinary_map_objects(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint8_t value = RAM8(0xE800);
    RAM8(0x00BC) = value;
    bool carry1 = carry;
    for (;;) {
        carry1 = value >= 0x31;
        if (!(carry1)) break;
    }
    RAM8(0x000F) = RAM8(0xE804);
    r->y = y;
    r->c = carry1;
    r->mf = 1;
    r->db = 0x7E;
    r->sp -= 1;
    JSR(c, 0xDCF3, 0xC0E1A8); /* prepare_map_object_slots_and_buffers */
    r->sp += 1;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    JSR(c, 0xDCF6, 0xC0DCFC); /* initialize_map_object_cache_and_saved_positions */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    JSR(c, 0xDCF9, 0xC0DD8B); /* scan_initial_map_object_slots */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DCDC, SOM_RTS, "gen", load_ordinary_map_objects, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, -1, 0, 32, 16)
