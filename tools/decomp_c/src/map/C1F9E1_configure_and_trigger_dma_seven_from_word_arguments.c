#include "som_c.h"

/* C1F9E1 configure_and_trigger_dma_seven_from_word_arguments   [class D, 17 bytes, 7 instructions]
 * Source: src/rom/configure_and_trigger_dma_seven_from_word_arguments.s
 * Documented in docs/ui-native-vram-initialization.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void configure_and_trigger_dma_seven_from_word_arguments(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    BUS16_SET(c, 0x004370, a);
    BUS16_SET(c, 0x004372, x);
    BUS16_SET(c, 0x004375, y);
    /* Open-bus and hardware reads whose bytes land in WRAM are outside the contract: B-bus registers that return no
     * data, or an A-bus source (bank in $4374, set earlier) that is not memory, copied into the WRAM port. */
    {
        const bool b_to_a = (a & 0x80) != 0;
        /* B-bus registers touched in one unit of each transfer mode */
        static const uint8_t pattern[8][4] = { {0, 0, 0, 0}, {0, 1, 0, 1}, {0, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 2, 3}, {0, 1, 0, 1}, {0, 0, 0, 0}, {0, 0, 1, 1} };
        static const uint8_t span[8] = { 1, 2, 1, 4, 4, 4, 1, 4 };
        bool wram_port = false;
        for (unsigned k = 0; k < span[a & 7]; k++) {
            const unsigned reg = (a >> 8) + pattern[a & 7][k];
            if (reg == 0x80) wram_port = true;
            else if (b_to_a && !(reg >= 0x34 && reg <= 0x3F)) { c->fail = 3; return; }
        }
        if (!b_to_a && wram_port) {
            const int step = (a & 0x08) ? 0 : (a & 0x10) ? -1 : 1;
            uint16_t src = x;
            uint32_t n = y ? y : 0x10000;
            for (uint32_t i = 0; i < n; i++, src = (uint16_t)(src + step))
                if (!hand_rd_ok(((uint32_t)c->dmareg[0x74] << 16) | src)) { c->fail = 3; return; }
        }
    }
    BUS8_SET(c, 0x00420B, 0x80);
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F9E1, SOM_RTS, "hand", configure_and_trigger_dma_seven_from_word_arguments, 0, L_B | L_Y | L_C | L_V, 1, 0, 0, 17, 7)
