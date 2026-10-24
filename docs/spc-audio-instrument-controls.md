# Native SPC instrument and envelope controls

`InstrumentControls` reconstructs the complete130-byte interval0883..0904 in seven original entries. It publishes a voice's sample number, merges attack/decay/sustain-level/sustain-rate fields into native ADSR bytes, restores the envelope from the actual1880 table and publishes both envelope DSP registers through the original061B helper. The sample publication is unconditional; envelope publication respects the native music-channel override mask when an effect owns that voice. Effect channels use their own offsets directly.

Seven fixed mnemonic source files regenerate the unpatched physical ROM bytes using the real first boot-block mapping ROM=C3054A+SPC. The coordinated original proof completed with exit0: all3,584 calls match across 67 PC/P states and 10820 ordered I/O writes. Model SHA256 is `8a2adb31d85b08c342caba61e5c85a0ed9c47abd0eba81a99bdd1560b17f42d6`; source and dependency hashes are recorded in the report. It uses with native P0, even channel offsets0..30, all command bytes, sample indices0..11 and clear/set/random music override masks. It compares full RAM outside only the four occupied native stack bytes, processor state, DSP registers, ports and ordered writes. No instruction hooks are installed.

These bodies are actual dependencies of note playback03B1→0883 and six command-dispatch handlers; they do not close the note parser or the sample-cache upload protocol. No instrument/sample waveform payload is saved, and DSP publication is not a claim of synthesized waveform equivalence. Source credit requires the integration overlap check.

```sh
python3 tools/spc_audio_instrument_controls.py 'baserom.sfc' \
  --json data/spc_audio_instrument_controls.json
```
