# Native public SPC command receive and complete downstream dispatch

The public entry SPC0CAF..0CF0 is **66 instruction bytes**, physically ROMC311F9..C3123A. A fixed mnemonic source independently regenerates all bytes; its terminal `music` label points to the adjacent 0CF1 body without counting that body again.

The entry first reads the command token and returns immediately on zero. Other requests copy all four input bytes into B4..B7. Command 83 additionally echoes the operand through F5; every nonzero request acknowledges its command through F4 and waits until the sender changes the input token. The retained command selects the exact downstream route: one enters native complete music initialization, FE enters the transfer trampoline, other negative commands enter the high macro trampoline, two selects mono/stereo sound setup, 10..1F selects builtin sound sequences, and other positive commands return after acknowledgement. Each route uses the complete reconstructed native dependencies rather than dispatch stubs.

The captured extensive proof passed **1,079 public original calls**, across 739 PC/P states, 13 dependency hashes and 44178 ordered I/O writes: all 255 non-musical command bytes across four parameter/voice-mask contexts, plus fresh real music transfers for all 59 ROM songs. For music, it presents the actual initial command one followed by token 81, retaining the command fields until the receiver next polls. It then transfers every song byte pair and reaches the real SP=FF/JMP0279 exit. Other routes execute original RET, including duplicate sound cancellation's removal of the nested caller frame. FE receives an actual pair packet stream rather than bypassing the transfer handler.

All six uploaded blocks are restored without instruction patches, and other RAM/DSP/ports/registers are randomized. The comparison covers full RAM outside six native nested caller-stack bytes 01EA..01EF, CPU/SP/PC, DSP, peripheral ports/control/targets, timer read profiles, ordered I/O and producer state. The boundary freezes elapsed clocks while supplying explicit timer reads, so hardware phase and waveforms remain outside the proof. Instrument/sample-cache upload composition and subsequent note sequencing are also open; real song data is read at runtime and never saved to the repository.

All 66 source bytes match and the process finished terminal exit zero; its saved report is `data/spc_audio_command_receiver.json`. The preceding 90-byte parameter/sample and 428-byte effect-allocation chains have independent successful captured proofs, closing these actual downstream command dependencies without duplicate byte credit.

```sh
python3 tools/spc_audio_command_receiver.py 'baserom.sfc' \
  --json data/spc_audio_command_receiver.json
```
