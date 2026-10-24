# Native SPC per-voice modulation and DSP publication

The readable `VoiceUpdates` model and fixed mnemonic sources reconstruct **495 additional SPC700 instruction bytes**, from SPC0AC0..0CAE, physically ROMC3100A..C311F8. The complete public update is 414 bytes at 0AC0, with its complete 81-byte modulation helper at 0C5E. Neither body depends on an unreconstructed callback. This joins the already recovered public command interval beginning at 0CAF without claiming the earlier note sequencer.

The first two stages advance pitch and amplitude modulations only when the channel parameter is enabled, its initial delay is clear and its per-modulation counter expires. The helper retains waveform phase bits, one-shot/sign controls and native quarter/half/three-quarter increments, including minimum-one behavior. Pitch modulation performs the original fixed-point products, saves/restores the sign PSW and writes the complete signed word displacement; amplitude modulation writes the packed native step and marks the channel dirty. Counters reload from each voice's literal period field.

The output stage computes pan with exact signed saturation. Its **PUSH A / MOV A,offset / POP A** sequence leaves the addition result in A while preserving N from the offset load and C from the addition; testing N from the result would choose the wrong saturation branch. The model preserves this instruction-defined behavior. It then applies the native modulation product, separate music/effect gain rules, sample identity/master gain and mute mask. Both stereo values are written to the meter byte array and DSP volume registers, including upper-channel stereo swapping controlled by B1 bit three. Pitch publication performs native signed gain scaling, emits the low/high DSP pitch bytes and restores X from caller field 05. Finally the selected dirty bits are cleared with their original comparison flags.

The captured proof passed **4,096 complete original entries**, across 254 PC/P states, 11 dependency hashes and 14236 ordered I/O writes, 2,048 for each body. It uses all 16 even channel offsets 0..30, their actual B2 bit, caller field 05=X, P0 and random other RAM/DSP/ports/registers. Directed delay/counter/dirty and signed byte boundaries exercise bypass, period expiry, pan saturation, modulation and both channel groups. The helper additionally receives all parameter byte values with caller-consistent Y=35, phase branches and counter values. All RAM outside five native caller/status/value stack bytes 01EB..01EF is compared, as are CPU/SP/PC, DSP/address, peripheral controls/targets/ports and ordered I/O. Six original uploaded blocks are restored without instruction stubs or hooks.

All 495 bytes match independently assembled source. The process completed terminal exit zero; its saved report is `data/spc_audio_voice_updates.json`. This establishes directed DSP register publication; subsequent note parsing, song sequencing, complete sample/instrument-cache composition and hardware timing/waveform equivalence remain open. No audio payload is saved.

```sh
python3 tools/spc_audio_voice_updates.py 'baserom.sfc' \
  --json data/spc_audio_voice_updates.json
```
