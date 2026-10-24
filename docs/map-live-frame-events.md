# Continuous moving map and event commands

This extension starts from the same ROM-map16/four-actor fixture as the closed
C0B070 frame loop and retains the entire evolving state across 25 consecutive
iterations. Direction5 is supplied through the controller bus. The five phases
continue to cycle without resetting actors, the event interpreter or peripherals.

Movement reaches the ROM event stream at CA988B and follows its own flag-range,
branch, music and state commands. The local adapter composes the existing
inventory/event model with the verified C1F0EC audio-command body and real
APU acknowledgement model. It reads the actual four-byte command operands;
neither a replacement event script nor an audio completion is supplied.

In addition to the inherited full state and ordered-bus checks at every B070
boundary, the proof records each original event dispatcher opcode and 24-bit
script pointer and requires exact equality to the model's command log. The
original CPU enters the real NMI handler at the loop wait. Physical interrupt
timing remains outside this explicit input domain.

The work composes already reconstructed instruction bodies and claims zero
additional source bytes. It establishes bounded continuity from the declared
fixture, not unrestricted gameplay reachability. Frozen preceding tools and
captures remain unchanged.

The original comparison passes all 25 consecutive iterations, 297,177 original
instructions, 25 loop NMIs and five complete phase cycles. Its 8,641 PC/M/X
states are saved in `data/map_live_frame_events.coverage.json`; the full result
is `data/map_live_frame_events.json`. The exact native/model event sequence is
06 at CA988B, 42 at CA988C, 17 at CA988F, 27 at CA981F, 40 at CA9656, 02 at
CA965B, 2D at CA9821 and 28 at CA9825. The CPU capture finished successfully
and the exclusive execution window was released.

The separate model-only frontier diagnostic reaches 31 iterations before a
missing `hw['wa']` value in the composed boss loader at iteration32/phase1.
The inherited fixture starts with a synthetic object cache (BC=228, cursor181,
E800=0); the map layers use ROM map16, but the whole state is not produced from
boot or a complete native map load. This matters when the moving party reaches
actor refill. The next useful extension should first compose genuine object
cache/map initialization. No hardware default or cache entry has been supplied
to get past this boundary. `data/map_live_frame_frontier.json` is explicitly
unverified, contains zero original instructions and grants no source credit.
