# Readable SPC periodic fade updates

`tools/spc_audio_fade_updates.py` reconstructs SPC **13E5..1417, 51 bytes**, mapped to ROM **C3192F..C31961** in the native first boot-upload block. It includes independent fixed mnemonic source with named branches, assembled separately and compared with the immutable ROM. These51 recovered SPC bytes are included in the source manifest at their physical ROM address, with a separate SPC assembly address and architecture counter.

The driver periodically updates three fade accumulators. Each nonzero byte counter is decremented once, including the final counter-one update, and its complete sixteen-bit velocity is added to the corresponding sixteen-bit phase with native wrap and PSW carry/half-carry/overflow. The first and third fades compare their new high byte with the previous high byte; only an actual change ORs the current voice mask into their dirty masks. The middle fade stores its new phase unconditionally without setting a dirty mask. Existing dirty bits survive, and zero counters skip all phase/mask work. Native final A/Y and PSW effects are retained.

The final proof terminated with exit 0: **4,096 original SPC calls**, **25 PC/P states**, **51 independently assembled matching bytes** and **7 fresh dependency hashes**. It covers all byte counters and native P0 flag combinations, randomized word phase/velocity and explicit zero, byte-boundary, sign-boundary and full-word carry cases. It compares all 64 KiB RAM except the two original caller-stack bytes 01EE..01EF, CPU/SP/PC, DSP/address, ports, control/timer targets and I/O writes. The body performs no I/O. Native uploaded blocks are restored without extraction stubs. Timer progression, main-loop pacing, audio output and voice-DSP composition remain outside this functional proof. The original RAM, processor and peripheral comparisons all pass. Literal mnemonic source is available at `src/spc/advance_spc_three_fade_accumulators_and_dirty_voice_masks.spc`; the shared manifest now records the recovered source and its architecture.

```sh
python3 tools/spc_audio_fade_updates.py 'baserom.sfc' \
  --json data/spc_audio_fade_updates.json
```
