# Complete main map frame coordinator

`tools/map_main_frame.py` reconstructs C0B08C..B0D2 (71 bytes),
C0B0D3..B101 (47), C0B136..B21B (230), and C0BEFC..BF37 (60).
These 408 instruction bytes have complete original comparison, own-start coverage
and independent exact assembly evidence.

The main frame advances party messages and event execution, spell/OAM requests,
scene transitions, effects, layer motion, hardware controller input, motion and
contacts, map control and scrolling, graphics animation, menu records, obstacle
detours, the five actor phases, sprite publication, and OAM finalization.
The controller phase consumes all three pads and executes the full general ring,
partner selection, controller cycle, or controller reassignment as selected by
actual edges. Ring invocation performs both camera phases and sprite services
around the complete scene menu. Callees retain their immutable proofs.

`tools/map_main_frame_actor_cells.py` adapts the frozen actor consumer to the
caller's live stack. The earlier standalone `Creation.wait` model fixed S to
1EC0. In a nested F4AB call that displaced the caller's saved data bank and made
OAM finalization address the wrong bank. The new portrait wait retains S and
executes the native NMI handler; controller HUD publication reuses the verified
ControllerCycle adapter. No existing dependency is edited.

The current fixture includes ROM-produced map16/cache state, four live actors
with actual animation/weapon descriptors and incoming sprite-order lists, real
three-controller/Multi5 serial input, and complete menu/NMI buses. Comparison
checks WRAM outside the observed original stack footprint, CPU and context,
video/DMA/arithmetic state, ordered controller/audio operations, and interrupt
and menu phases. No instruction hooks or original payloads are retained.

The resumed sixty-case capture passes 2,309,404 original instructions and
covers all 186 own instruction starts with unique immediate widths. All four
sources independently assemble exactly, and the complete source build passes.
Evidence: `data/map_main_frame_proof{,.coverage}.json`,
`data/map_main_frame_source_audit.json` and
`data/source_checkpoint_20261010_main_frame_resume.json`.

The initial resumed full run stopped at case28 after 20,000,000 instructions
at 01CB4A: the capture adapter delivered ring wait NMIs only at canonical C1
addresses, while the real caller uses JSL01CB38. The new
`map_main_frame_resume_proof.py` adapter also delivers actual native NMI/RTI
at 01CB48/01CB7D, without altering the frozen CPU/model/prior proofs. Its
isolated case28 passes 268,751 instructions, followed by the complete60 pass.
The failed timeout grants no evidence or bytes. Stack/audio/NMI/peripheral
comparisons remain unchanged. The outer repeating frame loop and broader
continuous gameplay reachability are still open.
