# Animation operand reader bus carry and fixture audit

Analysis 2026-10-09, during implementation of actor_animation_operands.py. No shared model was edited.

## First failing case: C1D52A trial103

Both CPU65816.ea(`[dp],y`) and AnimationOperands.operand already add Y to the full 24-bit pointer. This is not a missing bank carry. The fixture starts with DP00..02 =7F:FFFF, operand103, Y1. Its writes cross into bank80, whose low8KiB is a mirror of DP WRAM:

| Fixture write | Value | Pointer after write |
|---|---:|---|
| 80:0000 |103 |7F:FF67 |
| 80:0001 |0 |7F:0067 |
| 80:0002 |103 |67:0067 |

The routine consequently reads **67:0068**, not80:0000. Actual AckCPU inherits nmi_ppu.CPU.rd8, which treats bank67 as ROM and maps it using `address &0x1FFFFF`. It reads ROM070068/070069 and returns wordC21A (low26/high194). boss_loader_rle.read_word delegates to map_object_cache.read_byte, which masks ROM with0x3FFFFF, gets270068 beyond the2MiB ROM and returns0. A minimal reproduction using the real-ROM bus and synthetic three fixture writes confirms native49690 versus model0.

Correction: give AnimationOperands a local bus reader matching the actual AckCPU/nmi_ppu memory mapping, with WRAM7E/7F and bank00..3F/80..BF low WRAM mirrors, and a2MiB ROM mirror `address &0x1FFFFF` for mapped-ROM accesses. Preserve 24-bit carry when adding Y and when fetching the second byte. Do not change shared map_object_cache.read_byte as part of this narrow implementation: its other harness contracts and CPU classes must be audited separately before broadening them. The routine's later INC of wordDP00 wraps its low word independently and does not carry into DP02; this differs from the long operand access.

The current fixture loop also evaluates bankDP02 afresh for each injected byte. That can change later write destinations when the earlier write hits DP02. Maintain a separate immutable initial 24-bit fixture address when deliberately injecting a payload, or explicitly classify self-alias cases as such. Native execution must use the final mutated DP bytes.

## F0 exhaustive-operand claim

The arithmetic encoding is correct: values0..4095 contain every combination of X nibble bits0..3, Y bits4..7 and Z bits8..11, exactly4096 unique triples. Added bit15 controls fixture-facing E010bit80 while F0 masks the Z operand to its low nibble, so it does not change Z.

However, the current fixture generator does **not** deliver all intended operands to the routine: half the cases select ROM banksD1/D2, where boss_loader_rle.write_byte ignores injection. Some boundary WRAM7F writes cross to bank80 and overwrite the pointer. Thus iterating4096 values is insufficient evidence of4096 observed XYZ combinations.

Use a dedicated exhaustive F0 batch with source7E:4000, independent actor-facing0/128, and all4096 operand words. Then run a separate smaller bus-frontier batch for7E/7F/D1/D2 source banks andFFFD/FFFE/FFFF pointers, with expected operands derived from actual bus mapping, preserving the aliasing cases. Track observed operand XYZ/facing combinations before native execution (using an independent bus reader), then assert8192 combinations were actually read. No need to repeat unchanged full-game test batteries.
