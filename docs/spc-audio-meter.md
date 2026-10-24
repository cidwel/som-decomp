# Native SPC voice meter publication

`tools/spc_audio_meter.py` reconstructs **SPC 138E..13E4, 87 instruction bytes**, physically **ROM C318D8..C3192E** in the original first upload block. Independent fixed mnemonic source with named branches is included and assembled against the immutable ROM. It has no external native calls.

B1 bit two selects one group of four voices. The routine reads two per-voice scale bytes and the selected DSP gain byte, performs both native unsigned eight-bit products, packs the specified nibbles and the group flag into one meter byte, and writes four resulting bytes through output ports F4..F7. It advances the native scratch pointers, DSP register selection and PSW exactly, then toggles B1 bit two. Remaining B1 bits and incoming port values are retained according to the original routine. DSP bytes are treated as the actual register inputs; the model does not infer signed audio amplitude or synthesize samples.

The final proof terminated with exit 0: **2,048 original calls**, **47 PC/P states**, **87 independently assembled matching bytes**, **7 fresh hashes** and **16,384 ordered I/O writes**. It covers all B1 bytes and native P0 PSW values, randomized DSP/RAM and explicit product, nibble and sign boundaries. It compares complete RAM except original stack bytes 01ED..01EF, processor/SP/PC, DSP/address, ports, control/timer targets and ordered I/O writes. Native uploaded code is restored without request stubs and executes without instruction hooks. The complete native comparisons pass. Literal source is `src/spc/publish_alternating_four_voice_spc_dsp_meter_packet.spc`, with its physical ROM and SPC execution addresses in the shared manifest. Main-loop pacing, timer phase, DSP audio synthesis and waveform equivalence remain open.

```sh
python3 tools/spc_audio_meter.py 'baserom.sfc' \
  --json data/spc_audio_meter.json
```
