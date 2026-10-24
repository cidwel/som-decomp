# Native SPC sound-effect parameter dependencies

Two complete readable helpers recover **90 SPC700 instruction bytes**, with independent fixed mnemonic sources matching the ROM: sample/envelope lookup at SPC0866..0882 (29 bytes, ROMC30DB0..C30DCC) and signed effect fade preparation at SPC0F91..0FCD (61 bytes, ROMC314DB..C31517). They read the original uploaded numeric tables directly; no table credit or original audio payload is added by this batch.

Sample selection writes the channel's selected slot, doubles its byte index and copies two pitch/sample-table bytes from 1800 and two envelope bytes from 1880 to the native channel arrays. The proof domain uses the 12 complete entries actually present in both 24-byte uploaded tables and even channel offsets 0..30. The full SFX setup uses sample slot four.

Fade preparation maps both parameter nibbles to multiples of sixteen, with zero initial/target positions becoming 80. Duration is the high nibble of B6. The saved subtraction status chooses the final signed velocity. Nonzero duration executes two divisions for the integer/fractional result; the model preserves their final A/Y registers and the restored PSW before the literal direct-page complement and full word increment. At zero duration, native **POP A discards the saved PSW** rather than restoring it; A becomes that saved status byte while current flags remain those of the duration test. This distinct path is preserved.

The captured extensive proof passed **2,048 complete native entries**, across 45 PC/P states and 10 dependency hashes. It compares random uploaded RAM/DSP/ports and P0 register states, all B7 bytes, all native duration high nibbles, zero duration, signed deltas and complete sample/channel indices. Every RAM byte outside the three native caller/saved-status stack bytes 01ED..01EF is compared, together with CPU/SP/PC, DSP/ports/control/targets and ordered I/O. The same explicit timer boundary is used as previous functional SPC batches; timing/waveform equivalence and the later sequencer remain open. The process finished terminal exit zero; its saved report is `data/spc_audio_sfx_parameters.json`.

```sh
python3 tools/spc_audio_sfx_parameters.py 'baserom.sfc' \
  --json data/spc_audio_sfx_parameters.json
```

The subsequent mono/stereo effect-allocation chain has its own separate matching source and complete original-call capture. In particular, its duplicate-priority helper at 0FCE can discard its caller's return address. The allocation model must preserve that protocol before the complete SFX entry can receive source credit.
