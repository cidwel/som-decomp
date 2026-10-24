#include "som_c.h"

/* C21CA4 prepare_boss_animation_background_blocks   [class B, 43 bytes, 26 instructions]
 * Source: src/rom/prepare_boss_animation_background_blocks.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=8 bit DB=$7E D=$0200.  Callers read: Y.
 */
static void prepare_boss_animation_background_blocks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = 0;
    uint8_t y1 = 0;
    for (;;) {
        uint16_t value = BUS16_RDL(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + y1, RAM8(0x027B));
        RAM16_SET(0x026C, value);
        uint16_t value2 = BUS16_RDL(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + (uint8_t)(y1 + 2), RAM8(0x027B));
        RAM16_SET(0x026E, value2);
        RAM16_SET(0x0FBA, RAM16(0x026F) & 0xFF);
        uint16_t value4 = BUS16_RDL(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + (uint8_t)(y1 + 4), RAM8(0x027B));
        RAM16_SET(0x0276, value4);
        RAM8(0x0000 + sp0) = x1;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)(y1 + 6);
        r->a = value4;
        r->x = x1;
        r->y = (uint8_t)(y1 + 6);
        r->mf = 0;
        r->xf = 1;
        r->db = 0x7E;
        r->dp = 0x0200;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1CC6, 0xC21CCF); GUARD_JSR(c, sp_call, 0x1CC6); } /* decode_boss_animation_background_block_to_tilemap */
        r->sp += 2;
        uint16_t a_all = r->a;
        uint8_t value5 = RAM8(0x0000 + sp0 - 1);
        uint8_t value6 = RAM8(0x0000 + sp0);
        uint8_t value7 = RAM8(0x0266);
        a_hi1 = a_all >> 8;
        x1 = (uint8_t)(value6 + 1);
        y1 = value5;
        if (!(x1 != value7)) break;
    }
    r->y = y1;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21CA4, SOM_RTS, "gen", prepare_boss_animation_background_blocks, 0, L_Y, 2, 0, 1, 43, 26)
