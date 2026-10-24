# Native actor animation frame expansion

C0F5AC..C0F8B2 is the complete 775-byte frame continuation inside the ordinary actor updater C0F4CB. The readable model is tools/actor_animation_frames.py:AnimationFrames. It starts with the same caller-provided script long pointer in DP00..02, actor offset in DP14/X and initialized actor descriptor/piece/buffer fields. This is a frame continuation, not a complete proof of the surrounding combat/AI/command scheduler.

The first stage advances the low script pointer by two, increments the frame counter, decodes horizontal mirroring and frame duration/repeat fields, preserves high accumulator bytes across XBA, selects the frame override when E041 is nonzero and resolves the D1 descriptor. The descriptor's high byte indexes the actor's long piece table. The original native bank and low-pointer carry semantics are preserved.

The piece header supplies one to fifteen sprite pieces, with zero normalized to one. Each piece consumes four tile sources. Literal words produce one source; compressed words repeat a source or advance it in32-byte steps. Runs truncate at the exact output count, preserving the original scratch count, carry and final registers. Sources are written into the actor-selected software tile buffer.

The second stage unpacks the signed X/Y coordinates, mirrors them with the native minus16 adjustment, combines flip/palette bits and advances the packed tile/attribute pair with its original carry into the high byte. ED negative enables two collision rectangles. Each can use an explicit signed byte layout or two signed packed nibbles; both preserve height subtraction, native overflow saturation to80, mirroring and separate width/height fields. No rectangle data or output graphics are saved.

## Original execution comparison

7,168 complete original continuation calls pass:1,024 generated piece fixtures and6,144 original D1/D2 table lookups (three heroes, eight weapon frame tables and256 supplied frame indices each). These table inputs do not imply every index is a frame used during gameplay. Generated script/descriptor values live only in transient ROM copies; the original code remains untouched. Generated piece lists live in RAM banks7E/7F and cover every header count, raw/repeated/consecutive tile forms, both collision formats, palette modes, flips, frame override and duration fields. No raw fixture or original payload is stored.

The comparison checks all128KiB WRAM except129 native caller-stack bytes1E80..1F00, all CPU result flags/registers/modes and S/D/DB, and static PPU/DMA/peripheral state. Native domain D0/DB7E/M8/X16/binary and twelve aligned actor offsets. The proof has no hooks. A64-call smoke run initially stopped because the harness's bare CPU lacked the peripheral fields being compared; selecting the existing nmi_ppu.CPU fixed the harness without changing the readable body or original instructions. The smoke and first extensive comparison then passed.

There are 414 captured PC/M/X states. Tool/report/capture and dependency hashes are checked at integration. Full original actor update, animation command returns, AI/action coordination, continuous rendering and hardware timing remain open.

tools/actor_animation_frames.py: `ff2ca5e91d2b600e50b364f6bf39116d8c1a44401a8831c00cb84989805aadb6`.
data/actor_animation_frames.json: `c5d4646907b15e62bbfd707cf19e0de032fbaf9ce6b76ec12fd3ddc1f255dddb`.
data/actor_animation_frames.coverage.json: `9811e0be81622082eedc0d77232aef5763afec3aca7e6b2be16c19bf63687c25`.
