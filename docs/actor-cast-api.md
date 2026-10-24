# Native public cast context API

C1800F is the three-byte public jump and C1806F is its complete26-byte context wrapper. The corresponding01800F/01806F bank mirrors execute the same original code and receive no duplicate instruction credit. C0001B/C03803/C03862 belong to the earlier native MP/grade/message API; they are separate existing sources, not aliases newly recovered here.

The wrapper saves the original processor state, data bank and direct page; selects DB7E, D0 and M16; executes actual C188C7 request preparation and JSL018707 cast execution; then restores D/DB and all original C/N/Z/V/M/X flags. Register results remain those of the actual cast calls. The model passes the real seven-byte saved context/call boundary to previously verified helpers, preserving their native stack behavior. It reuses complete CastExecution without temporary adapters or hooks.

512 complete original calls passed on the first full comparison,128 per canonical/mirror entry, with3,365 PC/M/X states. The initial16-call smoke also passed. Domains cover hero and nine ordinary slots, all42 spell IDs sampled, original request guards for globalF1, eventD0/D4, inactive/dead and existing cast phase, actual graphics and target hit paths, M8/M16, X16, binary arithmetic, D0/0300/1234, DB7E/42/7F and all16 C/N/Z/V combinations. Full randomized WRAM outside the observed transient native stack, CPU results/S/D/DB and restored P, PPU/DMA/arithmetic/ACK/audio/IRQ inputs agree. This public API normally publishes cast presentation; its deeper execution/engine paths are reused from the separately complete CastExecution/Engine proofs rather than credited again.

Both selected bodies have complete unambiguous immediate-width and instruction-boundary evidence. Only29 canonical instruction bytes are candidates for integration; no ROM payload or assets are saved. Models and dependency hashes are stable. Arbitrary invalid X8 callers and console timing remain outside the finite domain.

tools/actor_cast_api.py: `99071287aa7611118bbc41ea3f32650d3c2957c341fd85c96096b074e175aca5`.

data/actor_cast_api.json: `ad6296eb3e5205597a8754abbbdaf8f8c2a29fe4636b7c4eeb0a5f7870e4ad81`.

data/actor_cast_api.coverage.json: `e60ddb038550783efcad3b1d03640fb6d18930c7fb9514af613d3c86a3b909bf`.
