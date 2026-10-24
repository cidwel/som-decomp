# Charge effect update, contact and homing

`tools/actor_charge_effect_update.py:ChargeEffectUpdate` reconstructs eight complete bodies, totalling 1,055 instruction bytes. Source recovery and physical overlap accounting remain the integrator's independent checks.

| Entry | Bytes | Behavior |
|---|---:|---|
| C2C183 | 78 | Read terrain and start the actual tile event |
| C2C221 | 75 | Update all three charge records belonging to an actor |
| C2C26C | 341 | Advance phases, countdown, height, motion and terrain collision |
| C2C526 | 40 | Contact test or native homing continuation transfer |
| C2C54E | 102 | Select opposing actors and mark the source |
| C2C5B4 | 154 | Test contact geometry and mark the target |
| C2C64E | 51 | Test the homing distance threshold |
| C2C681 | 214 | Steer towards the target and wrap both map axes |

The wrapper visits three 16-byte records at actor-offset divided by eight. Its idle path updates the actor flags literally. Records preserve the native phase and countdown saturation behavior, use the original angular coefficient words, and compose the existing screen-position, terrain and event-command implementations. A positive terrain event reaches the actual event initializer; it is not replaced by a success adapter.

C2C526 is deliberately verified through its callers. Its two byte PLA operations remove the worker's return word before transferring to the homing continuation. The model expresses that transfer explicitly instead of inventing a standalone RTS contract. C2C5B4 separately preserves the PHX/two-PLA actor-mask calculation. Incoming D=0, DB=7E, M=8, X=16 and binary arithmetic are required by this native family.

## Evidence

All comparisons executed the original instructions without hooks and compared full WRAM, SRAM, CPU context and peripherals. Only the observed native stack footprint was excluded from memory equality.

- Primary proof: 44 directed calls, 6,027 original instructions; 478 of 527 own instruction starts.
- Directed branch supplement: 19 calls, 2,003 instructions, bringing own coverage to 522 starts.
- Map-wrap supplement: three calls, 195 instructions, covering the remaining five starts.
- Union: **66 calls, 8,225 instructions, 678 PC/M/X states, 527/527 own starts**. All 99 dependency hashes were revalidated unchanged.

`data/actor_charge_effect_update_audit.json` records the union and hashes of all three immutable reports and captures. The primary report retains its original standalone coverage; it has not been rewritten to imply that it covered the supplemental branches.

Directed cases include both opposing actor groups, later contact targets, inactive/immunity/plane/hitbox rejections, positive contacts, timers, phase overflow, height underflow, near/far homing, positive terrain events, and both signs of map wrapping. Boundary fixtures correlate world coordinates and camera coordinates under a 512-unit extent. The final wrap cases use acceleration 56 advancing to 64, whose actual ROM coefficient produces a nonzero displacement; the earlier angle nine legitimately had zero displacement.

An initial CPU flag mismatch identified an incorrect model comparison after negative-coordinate wrapping. Native BPL bypasses the extent CMP after a nonnegative addition; the corrected model preserves that path. The exact failed case then passed before the primary capture. No frozen dependency was modified.

## Limits

The domain uses valid synthetic terrain caches and aligned native actor records. It does not establish reachability of every tested state from a complete battle, arbitrary malformed cache behavior, or frame scheduling. Existing screen-position and event helpers contribute behavior but no duplicate source credit. Angular tables and graphics/assets are not credited by this batch.
