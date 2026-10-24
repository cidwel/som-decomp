# Complete native scrolling dialogue states

`EventDialogueScroll` reconstructs all seven CC0900 states and all five line-command vectors. Sixteen contiguous instruction bodies total603 new candidate bytes. It retains script copying through the actual7E terminator, indentation, space/dot/letter glyph tile selection, the128-byte ring cursor, timed line production, the final256-tick ring clearing sequence, register restoration and sprite graphics publication. Native table bytes and their payloads are not saved.

`DialogueScrollObjects` reconstructs C10030/4, C1481F/41, D3F4F1/118 and C12E80/4, another167 candidate bytes. The existing heap, OAM, individual sprite activation and allocator are reused. The real initializer supplies A=0F03 to C13D8F, which writes request&1 into8420. This establishes individual-sprite mode before D3F4F1 activates all64 records: forty reserved records and twenty-four records linked into the allocated scrolling list. These are successful allocations and activations, not allocation-failure bypasses. The unrelated generic C1402F quad-success ABI remains open; this native producer never selects it.

The existing ROM literal/backreference decoder is composed with its native CPU epilogue in `event_dialogue_scroll_decode.py`. Original C10014/C14C30 and its copied stack decoder execute in the checker, reading actual compressed block C7C1C0 into7E9400. Caller stack depth, final accumulator derived from TSC, source lookahead pointer, output pointer, preserved status/D/DB and index truncation are retained. Existing decoder source receives no duplicate credit.

The first22-case smoke exposed only an observation defect: ResourceIRQCPU did not maintain the stack watermark. A local subclass now observes S before and after each original instruction; no model or dependency was changed. The corrected smoke22 and first full1,408-call capture passed. The domain is fifteen helper entries×64 contexts plus seven dispatcher phases×64. It includes all five commands, letters/spaces/dots, continued/end lines, ring wrap, timer16/256 boundaries, real compressed graphics, successful64-sprite construction and every publication/restore phase. The native ABI is D=0, DB=7E, M8/X16, binary arithmetic, with CC0900 entered through JSL/RTL and internal helpers through JSR/RTS. Full WRAM outside the observed occupied stack, CPU/status/S/D/DB, graphics/arithmetic peripherals, IRQ state and audio acknowledgement agree; there are no hooks or injected interrupts.

The capture records961 PC/M/X states and169 dependency fingerprints. All357/357 instruction starts across the twenty new bodies are observed, and all twenty pass immediate-width/boundary source recovery. Stack watermarks are1EB7/1EBB/1EC1/1EC5/1EF6/1EF7/1EF8/1EFA/1EFB/1EFC/1EFE. The combined new instruction candidate total is770 bytes, with no manifest overlap. All six tools/reports/captures listed below are frozen. The whole public dialogue coordinator and interactive menu loop remain separate compositions.

| Artifact | SHA-256 |
|---|---|
| tools/event_dialogue_scroll.py | e67ece250f357a4e1a85729b0287242bcb02ed062c10be5a7003a5d6814ca271 |
| tools/event_dialogue_scroll_check.py | 76e1a2b02e57d4e203528c9a66e96c3ff26dfebe17a5b1d05cdce922b45f625f |
| tools/event_dialogue_scroll_objects.py | 14711b367bbafb897503877216657f3123b3ef3c79083640c1c5575a49ef23a8 |
| tools/event_dialogue_scroll_decode.py | aa080eb69791706f18d871e88f3872b9154ba65240a10f5b736f745c4f5ca4b0 |
| data/event_dialogue_scroll.json | db7fafe211267e59a6408bde012c34d53499826de6dc2f9da4990162e172cd7f |
| data/event_dialogue_scroll.coverage.json | 1bcb55bf226175b157bc419e55f9ce6e6d15346330927b733ddf1a3fb369e9e2 |
