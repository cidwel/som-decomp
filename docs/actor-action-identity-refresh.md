# Public actor identity refresh

Status: twelve complete original calls accepted, with both alias instruction
starts observed. All four source bytes are integrated and independently
assemble to the original ROM bytes.

`C0E034..C0E037` is the public long-call entry used by actor action 05. Its
`JSR $E038; RTL` sequence bridges the long caller to the existing short-call
implementation at `C0E038`. The implementation changes the actor identity,
refreshes its weapon graphics and palette, and initializes the associated
actor program. Those dependencies are already recovered in
`map_object_large_creation_cpu.LargeCreation.object_refresh`; they must not
receive new source credit for this alias.

The accepted model uses that complete implementation. The proof calls the
public alias with all three large actor records, identities `$00/$07/$7F/$FF`,
both palette pages and randomized surrounding memory. It compares returned
registers, flags, processor context, peripheral state, ordered audio writes,
and all WRAM outside the observed native stack. It does not substitute hooks
for identity, graphics, or program setup.

Evidence is recorded in `data/actor_action_identity_refresh_proof.json`, its
coverage report, and `data/actor_action_direction_refresh_audit.json`.
The four alias bytes are new source. Proving this entry does not close
the enclosing `C1D942` dispatcher, its other actions, or live-frame behavior.
