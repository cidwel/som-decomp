#include "som_c.h"

/* C295A0 publish_native7f_single_mode7_frame_dma_request   [class A, 29 bytes, 15 instructions]
 * Source: src/rom/publish_native7f_single_mode7_frame_dma_request.s
 * Documented in docs/boss-native7f-frame-requests.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void publish_native7f_single_mode7_frame_dma_request(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0352, 1);
    uint16_t value = RAM16(OBJECT_AGE + x);
    RAM16_SET(0x0395, (uint16_t)((((uint8_t)(value - 1) << 8) | ((uint16_t)(value - 1) >> 8)) << 3));
    RAM16_SET(0x0353, (uint16_t)((uint16_t)((((uint8_t)(value - 1) << 8) | ((uint16_t)(value - 1) >> 8)) << 3) + 0x4000));
    RAM16_SET(0x0355, RAM16(0x0395));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC295A0, SOM_RTS, "gen", publish_native7f_single_mode7_frame_dma_request, 0, 0, 1, 0, 0, 29, 15)
