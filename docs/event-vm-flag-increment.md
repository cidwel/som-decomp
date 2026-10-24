# Complete event opcode 29

`EventFlagIncrement` reconstructs C1EC46 (57 bytes), including its full scene-transition branch. For ordinary flags it increments the lower nibble, saturates at 15, preserves the upper nibble and advances the script cursor by two before resuming the original dispatcher. Flag 0 with value zero has two special paths. If ED is nonnegative, it sets ED's high bit, clears the three controller bytes, leaves flag 0 at zero and resumes dispatch. If ED is already negative, it activates flag 0, advances the script cursor, executes the complete radial graphics/HDMA/particle transition, then restores the entire party HUD through its real two-frame coordinator.

The special path is fully composed from stable native models: graphics and palette conversion, all native DMA transfers, every phase of the 512-frame expansion/contraction, twenty particle updates each frame, actual NMI/RTI events, and the HUD frames/numbers/icons. Each complete special call consumes exactly 515 native NMIs: one graphics preparation frame, 512 animation frames and two HUD restoration frames. Neither EC waits nor original callees are replaced.

The six-call smoke and first full 8,357-call capture passed without changes. The capture includes 8,192 ordinary flag cases (all 256 IDs, all 16 lower nibbles and upper bits 0/F0), 127 additional flag-zero guard cases, 36 actual dispatcher calls, and two complete scene-transition calls through direct handler and dispatcher entry. Together the first-activation cases cover all 128 nonnegative ED values. All C/N/Z/V combinations are represented. The event-handler caller contract is M8/X8, D=0, DB=7E and binary arithmetic.

Comparison includes all WRAM outside the observed native stack, complete CPU result and D/DB/stack context, plus all video and arithmetic peripherals. No instruction hooks or callback replacements are used. The two special calls total 1,030 original NMI/RTI events. Stack watermarks are 1EFE for ordinary cases and 1EE4 for the complete scene transition. The capture contains 1,209 PC/M/X states, all 99 dependency fingerprints match, and all immediate widths/instruction boundaries in the 57-byte body are captured unambiguously.

The normal continuation C1EC8D..EC9F is already contained in the existing 33-byte decrement handler and receives no duplicate byte credit. All scene and HUD dependency bodies are likewise reused without extra credit. This closes opcode 29, while other opcode families and the complete event VM remain open.

| Artifact | SHA-256 |
|---|---|
| tools/event_vm_flag_increment.py | a283ae9c3b630a8b4dffd6e9311afdd282552178cf97a04df841bb44802f8394 |
| data/event_vm_flag_increment.json | f87f53f6b523086bb968833984738fd829951daeb0b0d21c32be210b33f7032f |
| data/event_vm_flag_increment.coverage.json | 9d420643db1067449b16d5f7406328f1adb4f860d0bc2ae51bf6ffd2705d96c6 |
