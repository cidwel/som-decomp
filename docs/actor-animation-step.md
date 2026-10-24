# Actor animation step and command continuation

The readable animation step/reader reconstructs five complete entries totaling 575 ROM instruction bytes. The immutable primary42 and separate guard4 native captures contain 46 actual original calls and 25,004 executed instructions. Their union observes every one of the 260 own instruction starts, with unambiguous captured M/X immediate widths. The saved audit reproduced on resumption without executing the original again; independent ca65/ld65 assembly of all five sources matches every original byte.

| Entry | Bytes | Purpose | Own starts |
|---|---:|---|---:|
| C0F4AB | 32 | Step all three heroes and publish primary geometry | 15/15 |
| C0F4CB | 225 | Step one actor, refill, consume action and resume frame stream | 101/101 |
| C0F8B3 | 59 | Trigger actor program under native animation guards | 26/26 |
| C0F8EE | 29 | Restart frame after discarding the reader return | 12/12 |
| C0F90B | 230 | Read animation commands and perform native nonlocal returns | 106/106 |

`ActorAnimationStep` composes the frozen frame expander, visual geometry, actor consumer, world-action caller, cast engine, special helpers and operand decoders. Physical native near/long call frames are pushed and consumed; reader restart and abort discard their actual caller return instead of faking a normal return. The three-hero alias preserves and restores DB, including its DB0/M16/X8 input example. Trigger guards cover frozen/requested state, hidden actors, hero restrictions and selected enemy suppression, plus a positive world-action call.

Primary42 includes new/resumed frames, timers, special and negative poses, ordinary consumer/effect exits, seven trigger gates, three-hero composition and command FF/FE/FB/FC/FD plus low/high, packed motion and velocity forms. FD cast must produce a real hero80 result. Guard4 independently adds the high pose table, FE reached through the actual animation JSR, nested restart trigger and a linked ordinary map-cache replacement by a second eligible record. Its local `StepRefillArithmetic` preserves native multiplier transactions without modifying frozen imported models.

Every successful comparison checks full WRAM outside the observed stack interval, SRAM, nine logical CPU values, S/D/DB/status context, graphics/audio/arithmetic peripherals, raster and IRQ state, and ordered arithmetic/audio writes. No original hooks, synthesized instruction traces or replacement ROM payloads are used. Directed ROM decoder inputs and coherent map-cache ABI examples do not claim universal gameplay reachability or a complete actor scheduler.

`data/actor_animation_step.source_audit.json` records both immutable report/capture hashes, 1,961 observed PC states, 317 recursively captured primary dependencies and no changed dependencies. The frozen primary checker includes a trailing-space line that must remain unchanged. Model SHA256: `d6049dee1754ec4c948a6aa96837e5d8d63378397f2d1af996a30d36157f78a9`.

Integration proposal: run `tools/actor_animation_step_source_adoption.py`, then recover the five entries using the usual source recovery and independent full source build. The adoption adapter validates saved hashes and supplements the primary model rather than replacing it. Source credit remains contingent on manifest adoption and the independent build; this document alone grants no bytes.
