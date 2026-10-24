#include "som_c.h"

/* C1F0EC event_read_audio_request_and_dispatch_native_sender   [class A, 34 bytes, 15 instructions]
 * Source: src/rom/event_read_audio_request_and_dispatch_native_sender.s
 * Documented in docs/event-audio-requests.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_read_audio_request_and_dispatch_native_sender(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x1E00) = RAM8(0x0005);
    uint8_t value2;
    BUS8_OK(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, value2);
    RAM8(0x1E01) = value2;
    uint16_t value3;
    BUS16_OK(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 3, value3);
    RAM16_SET(0x1E02, value3);
    uint16_t value4 = RAM16(0x00D1);
    RAM16_SET(0x00D1, (uint16_t)(value4 + 5));
    r->a = (uint16_t)(value4 + 5);
    r->y = 3;
    r->c = value4 + 5 > 0xFFFF;
    r->z = (uint16_t)(value4 + 5) == 0;
    r->n = (uint16_t)(value4 + 5) & 0x8000;
    r->v = ((value4 ^ (uint16_t)(value4 + 5)) & ((uint16_t)(value4 + 5) ^ 5) & 0x8000) != 0;
    r->mf = 0;
    JSL(c, 0xF10C, 0xC30004); /* audio_command_sender_public_jump */
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F0EC, SOM_RTS, "hand", event_read_audio_request_and_dispatch_native_sender, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 34, 15)
