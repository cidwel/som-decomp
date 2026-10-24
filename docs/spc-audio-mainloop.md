# Complete native SPC driver iteration

`MainLoop` reconstructs the126-byte body0279..02F6 and composes the original command receiver, packet ACK/transfer, music/SFX/macros, timer polling, global DSP publication, voice meter, fades, note sequencer and per-voice publication. Six numeric DSP register identifiers and six corresponding direct-page fields at158C..1597 are kept as a separate12-byte typed table. Existing bodies are reused without duplicate instruction credit.

Each iteration polls the real receiver until timer0 returns a nonzero count, writes six native global DSP fields, publishes active channel masks or a meter packet, advances fades every seventh eligible cycle, processes music/effect streams and publishes eligible voice updates. A fresh music request resets the native stack and jumps directly back to0279; it does not continue a fictitious generic receiver return. Zero-timer retries remain actual original polling loops. The readable model records the loader's distinct reset/jump outcome without injecting extra F4 reads or changing the sender protocol.

The final original proof completed with exit0:8,631 calls/iterations match across1,737 PC/P states and214,329 ordered I/O writes. All59/59 native instruction starts in these126 bytes were executed. It includes all256 command values in four explicit peripheral/control contexts, all59 fresh songs through command1→81 and128 complete subsequent mainloop iterations per song. Model/harness SHA256 is `53c7f77275d8eaf4bd54413d7fc65736b04af1b8d2867b8a96bf83af0ce878b8`; source and dependency fingerprints are recorded in the report. It compares full RAM outside the instruction-observed occupied stack, CPU/DSP/ports/control/targets and ordered writes. The input timer profiles are the same explicit peripheral boundary used by the other SPC proofs; this does not establish hardware timer phase or synthesized waveforms. The mainloop composition explicitly routes12AC to the preexisting ControlFlags tempo-mode contract, keeping the separate sequence-tempo0620 contract intact; no integrated dependency was modified. The126instruction bytes and12numeric data bytes are independently assembled and integrated without overlaps. The full0200..1417 instruction region now builds as one4632-byte SPC component from89 mnemonic sources, with local labels scoped per source; every physical and native address is contiguous. This establishes exact source reconstruction for that code region, not the entire audio hardware or sample cache.

Full sample/instrument-cache upload and waveform synthesis remain separate. No ROM/song/sample/audio payload is saved.

```sh
python3 tools/spc_audio_mainloop.py 'baserom.sfc' \
  --json data/spc_audio_mainloop.json
```
