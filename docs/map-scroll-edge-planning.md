# Coarse-scroll edge planning

The readable C0C59F body covers243 ROM instruction bytes. Native524 passes171,062 original instructions, captures all121 own instruction starts, and its independently recovered source assembles exactly. No additional resource or instruction bytes are credited for its already reconstructed row/column builders.

The planner compares four cached coarse coordinates with the corresponding current scroll words maskedFFF0. It preserves the native zero-cache sentinel and special16 transitions, and selects changed-coordinate direction from the sign of the literal CMP result. Each axis contributes0/1/2 to the pending row or column flags. A present second layer contributes its direction shifted two bits; map flag29.04 suppresses both published flags and returns after updating the caches. Other routes invoke actual row planning atC0C7C3 and tail-dispatch actual column planning atC0C8EF.

The model composes frozen `map_tile_planning` and both layer tile builders through `MapTileRefresh` state transfer. It pushes and consumes the real near return for the row helper. Queued rows remain handled by the existing native planning dependency. No original hook, simplified row-fill stub or artificial trace is used.

Directed480 cases cover five cache values and eight scroll boundaries for each of four axes across single-layer, second-layer and suppression routes. Twelve queued-row examples and32 mixed numeric worlds complete native524. Generated geometry, map indices and tile words are numeric decoder ABI inputs, with D0/binary, both incoming widths and DB0/7E/FF. These examples do not assert universal map-play reachability or a complete frame scheduler.

Every comparison preserves full WRAM outside observed native stack writes, SRAM, nine logical CPU values and CPU context, graphics/audio/arithmetic peripherals, raster/IRQ state and ordered arithmetic/audio writes. The saved preflight remains explicitly unverified and contains zero original instructions. The genuine native report/capture is separate and immutable.

`data/map_scroll_edge_planning.source_audit.json` records585 observed PC states,331 unchanged recursive dependency hashes, immutable report/capture hashes and complete own-start/source closure. Model SHA256: `fdba5fea4005b598e7bde561c8428eb6d70f69c8ef0c9fb4ffff1c23d88010a5`.

Integration spec: `map_scroll_edge_planning_check:MapScrollEdgePlanning:map-scroll-edge-planning:map_scroll_edge_planning`. Use its audited adoption adapter, recover C0C59F and run the independent full source build before source credit. No ROM, graphics, dialogue or savestate payload is stored.
