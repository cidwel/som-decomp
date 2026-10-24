# Animation-created linked child

`tools/boss_animation_linked_child.py` reconstructs definition C231D4 and bodies C231E0/C231F7: 76 instruction bytes and four dispatch-table bytes. State zero advances the state, activates the object, sets depth 07FF, and reuses the animation already stored in 9A as its seed. Both initialization and state one follow the parent's XY with signed word offsets B2/B4. The update returns carry one when animation field 9E is zero, retaining activity until the pool removes the object.

`data/boss_animation_linked_child.json` records 1,952 complete original no-hook calls: three entries × 512, 128 isolated pool calls and 32 real C21A3E explicit animation-object creations followed by eight original definition updates (288 persistent calls). All 34 instruction starts in the proposed ranges are visited; the tool/ROM/CPU and 96 dependency hashes match the evidence. Verification compares full 128 KiB WRAM outside the 129-byte caller stack window, nine CPU result fields, context, static peripherals and audio writes.

Inputs include both states, nine incoming/selected/parent actor slots, all 512 tested animation seeds, positive/negative and boundary word offsets, overflowing parent coordinates and zero/nonzero 9E. Pool flags 6000 produce 32 removals and 96 retentions. Persistent creation reads generated operand parameters from WRAM and executes the original animation command and actual allocator with flags 3821.

The persistent sequences invoke definitions manually and supply animation field 9E after initialization. They prove linked position, seed, completion result and creation wiring, but do not establish animation interpretation or continuous frame timing. This definition installs no independent position callback. No animation scripts, graphics or original ROM payload are saved.

Integrated source evidence: every listed candidate instruction body now has an independently assembled exact matching source. Numeric child state pointers are regenerated from their known destinations and verified against the ROM. The complete source composition matches; runtime boundaries above remain explicit.
