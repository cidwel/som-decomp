# Native SPC sequencer arithmetic dependencies

`SequenceParameters` reconstructs three complete original bodies: 09DF..0ABF (225 bytes) advances per-channel volume, pan, pitch-slide and envelope ramps; 04ED..054D (97 bytes) calculates tuned semitone pitch; 0562..056C (11 bytes) reads the current channel's stream byte and advances its 16-bit pointer. The proposed source is333 SPC700 instruction bytes and a separate twelve-word,24-byte numeric semitone table at14F2. Physical ROM mapping is the actual first boot block: ROM=C3054A+SPC. No65816 credit applies.

The two volume/pan ramps decrement byte counters, add signed word steps and dirty the voice mask only when the current high byte changes. Pitch sliding adds its full word step, clears the step when its counter expires and marks pitch dirty. Envelope motion saturates signed high-byte overflow to7F/80, dirties volume only on change and negates the full signed step at the period boundary.

Pitch calculation divides the note byte by12, indexes the native semitone word, multiplies tuning components with literal carry/status preservation, then shifts the full pitch word according to the octave. The original PUSH PSW protects the sign and carry from the tuning sum until after its products. CBNE performs no flag update. The stream helper preserves the fetched byte in A/DP04 while pointer increment supplies final flags, including low-byte FF and full FFFF wrap.

Independent literal mnemonic sources regenerate all333 instruction bytes. The typed `.word` table is kept separately from executable code. The coordinated original proof completed with exit0: all6,144 calls match across 154 PC/P states. Model SHA256 is `1d13abb2f2fa0af52fde14fda6671912754cb54262315fcac99d26b0a8e7214c`; all dependency fingerprints and matching source hashes are recorded in the report. It enters every native body without instruction replacement, supplies P0/even offsets0..30 and the caller's DP05/voice-bit state, compares RAM outside the five occupied caller/status/accumulator stack bytes, full registers/status/stack and ordered peripheral state. All note bytes, ramp stop/wrap counters, signed saturation and pointer carries are included. Integration must check source overlap before adding credit.

This closes actual dependencies of the02F7 sequencer; its03B1 note parser,056D lookahead,054E dispatcher and46 command handlers remain open. In particular the command09BC removes a caller frame and cannot be represented as a generic return. No full song playback, instrument-cache transfer or waveform-equivalence claim follows from these arithmetic bodies.

```sh
python3 tools/spc_audio_sequence_parameters.py 'baserom.sfc' \
  --json data/spc_audio_sequence_parameters.json
```
