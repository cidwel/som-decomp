# Native repeating map frame loop

`tools/map_live_frame_loop.py` reconstructs C0B070..B08B, 28 instruction bytes.
This is the actual nonreturning gameplay loop: run the complete B08C frame,
set request bit1 while retaining other EC bits, wait for a real NMI, increment
phase56 and wrap5 to0, then branch back to B070. Its model exposes one iteration
at the natural loop boundary; the proof never fabricates an RTS or RTL.

The successful capture retains its complete state across ten original
iterations, covering two consecutive cycles of phases0..4. It starts with the
existing ROM-produced map16/four-live-actor ABI and the real S01FF stack. Each
iteration executes the full frozen main-frame composition and actual NMI/RTI
with a busy BIT/BNE pass before the external frame edge. Input consists of the
existing controller bus plan with zero direction. Memory, actor animation,
graphics and counters are not reset between iterations.

Ten comparisons pass117142 original instructions. Full WRAM outside each
observed consumed stack interval, SRAM, CPU/context, video/DMA/arithmetic state,
controller/audio buses and ordered arithmetic writes match. The new arithmetic
trace initially detected missing bus transactions in the frozen actor consumer
on phase3 although final memory/register state agreed. `LiveActorConsumer`
composes the existing `ConsumerArithmetic` predictor with the live-stack actor
adapter; it retains every original multiplication without altering frozen tools.
The fresh complete capture then passed. Failed attempts supply no coverage or
source credit; the first one-iteration replay also preceded the corrected
shared coverage sink and is excluded from source recovery.

This closes a bounded continuous loop ABI, not every map/gameplay trajectory.
A moving preflight reaches actual ROM events42 and40; the old scene dispatcher
only handled basic events. The new loop selects the existing broader event
composition for reconstructed commands, while event40 is the next unsupported
dispatch link. No event script is changed to avoid it. Moving trajectories and
the actual map-entry-to-loop connection remain subsequent work.

Source audit and coordinator integration are separate from the original proof.
Use integration specification
`map_live_frame_loop_proof:LiveMapFrameLoop:map-live-frame-loop:map_live_frame_loop`.
Only28 bytes are new; B08C, event, actor and NMI callees receive no duplicate
credit. The CPU window was released after the terminal successful capture.
