# Camera retreat and special scene slide

`tools/map_camera_transition.py` reconstructs the complete C0BFA2/183 retreat,
C0C059/79 special scene slide and C1FD37/23 party-position helper. Together they
cover 285 new ROM instruction bytes. All camera movement, tile planning, OAM
workspace, sprite emission and frame-handler dependencies are composed from
unchanged complete readable models; those existing bytes receive no new credit.

With carry clear, the retreat starts from the selected actor's screen depth and
finds the smallest depth among active, nonnegative, uncontrolled party members.
Depth100 or greater returns carry clear and publishes zero in scratch1F.
Otherwise the distance to100 is capped at28 and emitted as one negative step,
or14 followed by the remaining negative step. Carry set instead consumes the
positive distance already supplied in1F; zero returns immediately and distances
at least15 split at14. The original literal control-byte behavior is retained.

Each step moves the actual camera, prepares actual scrolling tile edges, resets
OAM, emits the actual sorted HUD/actor sprites, finalizes the hidden-sprite tail,
and resets the workspace again before publishing EC1. The complete original NMI
handler runs through RTI at the live BIT wait instruction. The model composes its
independently verified frame translation, including real OAM upload, tile/HUD/
actor graphics, scroll/PPU writes and caller restoration. Request completion is
produced by the handler, never by clearing EC externally.

The special route requires word010E exactly80FF. It subtracts0400 from the first
party member's horizontal position and publishes that wrapped word to all three
members. It then performs all128 horizontal camera steps of negative8, tile
planning, OAM reset/emission/finalization, party pose-byte08 publication and actual
NMI/RTI waits. The final low countdown byte is zero and both register widths
narrow, matching the complete native loop matching all live loop iterations.

The external bus supplies one NMI edge at each requested live wait point. All
original frame instructions and callees execute and are captured; no scheduler
or opcode hook substitutes an instruction. This explicit interrupt input proves
the complete call/data behavior, not console vector timing or concurrent gameplay.

Fixtures include all256 initial nearest-depth candidates, both carry paths,
positive distances0..31, four complete128-frame runs and both special guard
failures, along with32 wrapped party-position examples. Actual map headers and
tile buffers are prepared privately from the ROM. Prepared ordinary actors,
HUD entries and hero tile tables are live inputs; all static video/PPU/DMA state,
full returned CPU/context, IRQ/audio state and ordered arithmetic writes are
compared. WRAM excludes only the stack interval observed during original outer
and nested NMI instructions. No original payload or save-state blob is retained.


The immutable primary428 and directed minimum-store supplement3 jointly pass431
complete original calls and3,077,515 original instructions, including896 actual
NMI/RTI frame deliveries. The supplement starts from selected actor3 and uses
party depths80/70/60,60/80/90,90/80/60 to retain the first and third minimum stores.
All122 own instruction starts are observed:81 retreat,33 slide and8 alignment.
Every immediate operand has a unique observed width. Independent temporary
ca65/ld65 assembly matches all285 ROM bytes exactly. The union audit verifies176
unchanged recursive dependencies and the hashes of both genuine captures.

Primary and supplement reports are `data/map_camera_transition.json` and
`data/map_camera_transition_boundaries.json`; their corresponding coverage files
are the sole source evidence. `data/map_camera_transition.source_audit.json`
records the union and `tools/map_camera_transition_source_adoption.py` contains
the proposed metadata adoption. Earlier replay0/replay384 captures are diagnostic
only and are excluded from adoption.
