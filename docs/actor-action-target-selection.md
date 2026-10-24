# Actor target selection and attack animation

`C1E4CC..C1E61C` selects an actor target and a distance class. With carry set,
it uses the low nibble of the actor's `$1AC` field as a target-record offset.
With carry clear, it compares the three opposing records, excluding inactive
records and applying the native scene flag to the second and third targets.
Paired distance bytes use their maximum; the final distance class shifts the
retained comparison accumulator four bits and clamps it to three.

The native enemy path indexes `$E050/$E253/$E456` by the caller's `X`.
These addresses are intentionally reproduced literally. The final selection
branches also retain the last loaded comparison operand when choosing the
third target; they do not reload the third distance. Replacing either detail
with a symmetric nearest-target abstraction would change the original.

`C1E40E..C1E4CB` composes that selector with the attack-animation lookup. It
stores the target offset at actor field `$05E`, combines distance, actor attack
mode, target status flags, target facing and the frame parity bit, then
selects the actual ROM table entry. Hero callers use their weapon index;
enemy callers use their program identity and the high bit of `$1E4`.
The model preserves both hardware multiplication results and processor state.

The primary 264 complete original calls pass with six aligned actors, direct
target nibbles 0..15, both selector modes, candidate choices, scene exclusions,
paired-distance ordering, hero and enemy callers, target statuses and frame
parity. Animation calls restrict direct targets to the six actor records.
A separate six-call supplement exercises ascending distance pairs in the
free-selector path. The union observes all 234 instruction starts across
527 instruction bytes without changing the frozen primary capture.

Full WRAM outside the observed native stack, returned registers and flags,
processor context and peripherals match. Entry context is M8/X16, DB7E,
binary arithmetic, with D0 or D0300 in the primary. No hooks replace callees.
Evidence is in `data/actor_action_target_selection_proof.json`,
`data/actor_action_target_selection_pairs_proof.json` and
`data/actor_action_target_selection_complete_source_audit.json`.

This closes the selector and animation lookup, not attack installation or
the complete `C1D942` action dispatcher. All 527 source bytes are integrated
and independently assemble to the original ROM. The joint acceptance is
`data/source_checkpoint_20261010_actor_targets_equipment_ring_name.json`.
