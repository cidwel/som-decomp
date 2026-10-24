# Native SPC control flags and timer-mode helpers

`tools/spc_audio_control_flags.py` reconstructs the contiguous **SPC12AC..12DD block, 50 instruction bytes**, physically **ROMC317F6..C31827**. This closes the small gap between the pending transfer receiver and the verified echo configuration. Its three bodies are the 26-byte mode toggle at 12AC, the 23-byte marker recognizer at 12C6 and the one-byte return at 12DD. Independent fixed mnemonic source is assembled and compared with the immutable ROM.

The mode toggle inverts B4 bit one, copies that bit through carry into B1 bit one, chooses timer-zero target one or 24, disables timer control, writes the selected target and reenables timer zero. It preserves all other B1 bits and the native CPU flag effects. Timer-register reset effects are compared through the explicit peripheral boundary, including counter, divider and subcounter state; real elapsed timer phase remains outside scope.

The marker recognizer compares the exact byte sequence **FF, FE, FD, FC** in B4..B7. It sets B1 bit seven only after both original word comparisons succeed and clears it otherwise. Its complete native A/Y and compare flags are retained for first-word misses, second-word misses and matches. The final body returns without modifying processor or memory state.

The final proof finished with exit 0: **2,304 original calls**, **24 PC/P states**, **7 fresh hashes**, **2,304 ordered I/O writes** and **50 independently assembled matching bytes**: 768 per body, all B4 bytes, all B1 bytes, all native P0 flag combinations, randomized RAM/DSP/ports and timer registers/state, and all three marker outcomes. It compares full RAM except caller-stack bytes 01EE..01EF, processor/SP/PC, DSP/address, ports, control, timer targets/counters/dividers/subcounters and ordered I/O writes. Uploaded native code is unpatched; no instructions are hooked. All native comparisons pass; three literal SPC sources and proposed manifest rows are saved separately. Complete command dispatch, sequencing and audio synthesis remain open.

SPC NOT1/MOV1 operands pack a thirteen-bit address plus the bit index in the upper three bits of their native word. The matching helper normalizes `$00B4.1` to packed word `$20B4` before invoking the existing independent assembler, without changing its stable source or the previously integrated SPC bodies.

```sh
python3 tools/spc_audio_control_flags.py 'baserom.sfc' \
  --json data/spc_audio_control_flags.json
```
