# Cyclic party-controller transfer

The complete C0BCF3/74 entry builds three candidate offsets from the previous
controller binding. Odd bindings try actor1, then actor2, and release actor0;
bit1 bindings try actor2, then actor0, and release actor1; other bindings try
actor0, then actor1, and release actor2. It saves the incoming bank, forces7E
for party records, tries the first candidate and tries the second only after a
rejection. The incoming bank is restored on every route.

C0BD3D/84 rejects inactive, negative, restricted-status, already controlled or
deferred-binding actors. Success publishes the selected controller and actor,
clears the displaced actor's binding, initializes its existing program when
required, and updates the actual controller HUD. The existing readable program
and HUD models supply those calculations. The new adapter also publishes the
actual4202/4203 multiplier input writes through the hardware bus, retaining their
ordered trace alongside the frozen program calculation. The new adapter retains the physical
caller stack during the complete frame handler rather than using the older
fixed stack checkpoint. An external NMI edge is supplied at the literal BF47
wait, with all original NMI instructions, callees and RTI executed.

The strict proof samples each of seven candidate states, both candidate
positions, three controllers, six previous bindings, enabled/disabled HUD and
three incoming banks. Direct-helper inputs use bank7E and X16, as required by
its caller. Outer inputs cover both incoming register widths. Full CPU/context,
peripherals, ordered arithmetic/audio writes and WRAM outside the observed
native stack interval are compared. No scheduler/opcode hook or fabricated
return substitutes any instruction. Existing program/NMI bytes receive no
additional source credit. No ROM payload or saved state is persisted.


The immutable full proof passes1,890 complete original calls and150,624 original
instructions, including243 actual NMI/RTI deliveries. It observes all80 own
starts (39 outer selection and41 transfer) with uniquely observed immediate
widths. Independent temporary ca65/ld65 assembly matches all158 ROM bytes.
The source audit verifies178 unchanged recursive dependencies and the hashes of
the genuine primary report and capture. The displaced program inputs are1/127/255;
hero rebuild calculations remain supplied by the unchanged complete existing
program model, with no extra byte credit from these caller examples.

`data/actor_controller_cycle.source_audit.json` records the source audit;
`tools/actor_controller_cycle_source_adoption.py` contains the proposed adoption.
The earlier single-case replay is diagnostic and excluded from adoption.
