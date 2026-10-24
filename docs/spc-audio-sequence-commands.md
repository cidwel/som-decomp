# Native SPC sequence commands

`SequenceCommands` reconstructs800 instruction bytes in0620..0865 and0905..09DE, split into38 complete original handler/fallthrough entries. The already verified instrument controls0866..0904 are reused without duplicate credit. Actual channel-stream arguments are read by0562; no injected command arguments replace that stream or its pointer carries.

The first group includes tempo/music gain, direct/faded volume and pan, pitch glides, absolute/relative transposition, vibrato/tremolo and signed envelope motion. Fade steps use the actual SPC700 division semantics and original saved subtraction status. Music and effect pan take distinct native paths. Zero-duration and zero-difference branches preserve their native register and flag behavior.

Noise, pitch-modulation and echo commands maintain separate music/effect masks and recompute their shared hardware publication masks. Noise-frequency selection follows B1 bit4 literally. Song control implements native relative jumps, counted jumps, conditional branches, four-level loop pointer state and loop counters; effect-channel guards preserve the original ignored-control behavior. Fine tuning and song gain retain their native channel restrictions.

The end handler09BC pops two bytes from its caller's frame before clearing active masks, resetting the released effect voice mapping and running the original pitch-modulation/echo/noise release chain. The model represents this actual channel exit explicitly. Its direct original proof supplies the real03BB parser-return frame above the outer call, rather than replacing the command with a generic return.

Fixed mnemonic sources regenerate all800 bytes. The refreshed coordinated proof completed with exit0: all9,728 calls match across 404 PC/P states, executing all398/398 original instruction starts in the800-byte interval. Directed native contexts add last-channel mask release (BF=B2), counted jump equality (FEA0=count−1) and lower loop-frame wrap (FEC0=1 at the lower slot); the semantic model and source are unchanged. Model/harness SHA256 is `d1a0a0cbeba1fede389bc5f049a47df7dc3e7c25168236dc5378a3acbbcb7f97`; the report binds source/dependency fingerprints and native stack watermarks. The cases cover across native P0/even channel offsets0..30, direct stream pointers crossing low-byteFF, argument boundaries0/1/2/3/4/7/15/16/31/63/127/128/129/254/255, zero/finite/infinite loop counters and random prior channel state. Full RAM outside each original call's instruction-observed occupied stack interval, complete processor/stack/peripherals and ordered DSP/port writes are compared without hooks.

The dispatcher054E, note parser03B1, lookahead056D and sequencer02F7 remain the next composition. No complete native song playback or sample-cache/waveform credit is claimed before those chains are verified.

```sh
python3 tools/spc_audio_sequence_commands.py 'baserom.sfc' \
  --json data/spc_audio_sequence_commands.json
```
