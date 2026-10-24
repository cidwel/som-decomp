# Directional actor command and facing decoder

Status: 80 complete original calls accepted, with all 64 instruction starts
observed across the two routines. The model preserves returned processor
state and all checked memory and peripherals. All 142 source bytes are
integrated and independently assemble to the original ROM bytes.

`C1DADD..C1DB26` applies command `C1` to the actor selected by `X`.
It marks directional control, clears the diagonal marker, preserves the old
direction and animation in direct-page `$0C/$0D`, copies the requested
animation, and installs a movement duration. A zero duration sets the
immediate movement flag instead. The routine then decodes the direction and
resets the animation phase and movement words when the pose changes.

`C1DB27..C1DB6A` decodes the low four direction bits at actor offset `$141`.
Bit 0 takes priority over bit 1, followed by bit 2 and bit 3. Vertical choices
produce direction 2 or `$82`; horizontal choices produce 1 or 0. Combined
vertical/horizontal bits also write the diagonal marker at offset `$13`.
The upper nibble is ignored. A standalone decoder call preserves the previous
diagonal marker when the input has no diagonal combination; the consumer
clears it before calling.

The phase-`$FF` branch preserves a native accumulator detail: `LDA` and `CMP`
run with an eight-bit accumulator, then `REP #$20` exposes its retained high
byte. The phase word therefore receives `$xxFF`, where `xx` is the incoming
high accumulator byte. Replacing that store with a constant `$00FF` changes
the original behavior. The changed-pose branch explicitly loads `$00FF`.
The consumer returns with a sixteen-bit accumulator.

The accepted proof has 80 cases: all sixteen direction nibbles with and
without upper bits for the decoder, plus unchanged pose, changed pose, and
prior phase `$FF` for the consumer. It uses six aligned actor records, zero
and nonzero duration, direct pages 0 and `$0300`, and accumulator high bytes
`$00/$1E/$AB`. Its original-execution comparison checks returned registers,
flags, processor context, peripherals, and all WRAM outside the observed
native stack. Evidence is recorded in
`data/actor_action_direction_proof.json`, its coverage report, and
`data/actor_action_direction_refresh_audit.json`.

The enclosing dispatcher at `C1D942` remains open. Its action-05 identity and
graphics refresh calls the four-byte public alias `C0E034`, whose body reaches
the already recovered `C0E038` implementation in `LargeCreation`. The
four-byte alias is now independently recovered. The existing identity,
graphics, and program-initialization dependencies receive no duplicate
source credit; the complete dispatcher composition still remains open.
