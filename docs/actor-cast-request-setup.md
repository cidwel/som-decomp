# Guarded native cast-request setup

C188C7..C1894C is reconstructed completely,134 instruction bytes. CastRequestSetup prepares the request before the later C18707 execution coordinator. It preserves the native F1 pause bit, controlled-actor exclusion, active/sign and current-state guards, including exact incoming accumulator and flags on each early return.

Accepted requests derive the level nibble and linked-target marker in E111, clear E108 and set actor state20. Ordinary actors run the complete existing directional-offset helper. Party actors select paletteCE/CF, set animation/state/velocity fields, convert the actual secondary effect graphics and copy its native palette. The original multiplier, software graphics output and restored actor offset are retained. This closes a helper used by the action dispatcher and boss cast initiation; it does not claim subsequent cast execution or cancellation callbacks.

## Original comparison

1,536 complete original calls pass, including all guard outcomes, all twelve aligned actor offsets, both incoming accumulator widths, levels/linked-target marker combinations, four facings and16 valid palette cursors. Full randomized128KiB WRAM outside129 native caller-stack bytes, CPU/context and static graphics/PPU/DMA/multiplier state match. There are 576 accepted requests, including 144 party graphics calls, and 505 PC/M/X states. D0/DB7E/X16/binary. The smoke64 and first extensive comparison both passed without hooks; unchanged dependencies reuse their saved proofs.

C18707 execution, C18C96 cancellation and C10038/C13B3C dynamic callback engine remain open. No ROM, graphics, palette or script payload is saved.

tools/actor_cast_request_setup.py: `0fd8db8bedf72b8db4356070f14ed419e1a674e98735ff93d7198c19eda47eee`.
data/actor_cast_request_setup.json: `578de061643ba0fc0c2e17e5bc0a7079b9ab94b295de66f7bfd5bbaca44f996b`.
data/actor_cast_request_setup.coverage.json: `e1b00aabe173f1779b26976b4e6bb1b7de72264a0f79b19628d5e30dc7deb215`.
