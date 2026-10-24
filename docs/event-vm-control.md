# Event control family, wait states and party freeze

`EventControl` reconstructs19 complete bodies totaling468 candidate instruction bytes: dispatch C1E8D3/47, party-ready freeze C2B053/62, eight control handlers spanningE9C4..EA62/158, text enqueueF27A/34 and eight wait handlers spanningF2E9..F390/167. Physical interval checks against catalogued matching sources found no prior overlap. Parent assembly verifies the final new-byte count independently.

The family covers END, NOP, RETURN, GATHER, both visibility aliases, FREEZE, UNFREEZE, WAIT_IDLE and text enqueue. RETURN and all ready wait states re-enter the actual dispatch loop. Gather invokes the existing complete CA6C motion cleanup for the other heroes. The freeze helper scans all three original hero slots, returns carry while an active hero is busy, and otherwise clears all three velocity pairs and motion state bytes. The wait family handles party gather, text readiness and restored script pointer, frame countdown, selected-actor pad mapping/latches, immediate resume, active-actor busy scan with ED/5C-selected limits, camera readiness and all reserved state aliases87..8F.

The dispatcher preserves the actual E2/FF/52/E8 guards, reads the long script word into04/05, distinguishes state80..8F from opcode dispatch, and clamps opcodes50..FF into the real text enqueue handler. That handler publishes the pointer and palette selector, sets48 and yields in state81. It does not replace or simulate the text renderer. The translated dispatcher rejects opcode dependencies outside the reconstructed family explicitly. Its validated opcode domain here is00..08 and50..FF; reconstructed0A/41 calls remain available through the stable previous model but were not redundantly rerun in this family capture. Other event handlers and full VM completion remain open.

The38-call smoke exposed a model byte-mask error on RETURN→dispatch: retained high A bits incorrectly affected Z after OR. Masking the native eight-bit OR/XOR input fixed it, and the smoke then passed. The first full4,864-call capture passed:256 original calls per body, all16 wait selectors, ready/blocked/resume routes, all three selected heroes and12 active-actor slots, direct control families, dispatch guards and text clamp, cursor boundaries, all16 CNZV combinations, and both M/X entry widths for dispatch/freeze. Every resume fixture executes the actual next END handler. No instruction hooks or successful-return stubs are installed.

Coverage records293 PC/M/X states. Full randomized WRAM agrees outside only observed native stack writes, with minimum address1EFA, together with complete returned CPU/context and video/DMA/peripheral state. The explicit environment uses D0/DB7E, binary arithmetic and natural M8/X8 handler inputs; dispatch/freeze normalize all four width combinations. Valid actor/pad controls, cleared palette-effect guards and generated runtime scripts are supplied. No interrupt occurs in this family capture; no renderer or NMI work is substituted. The previous0A/41 proof separately preserves their real interrupt-dependent redraw chain.

All72 dependency hashes and the captured tool hash match disk. In-memory source recovery succeeds for every one of the19 bodies with unambiguous immediate widths and exact instruction boundaries. Existing CA6C/palette support and map redraw dependencies receive no duplicate byte credit. Future opcode families should subclass this stable dispatcher and supply their actual handlers; the stable delivered files remain unchanged.

Stable SHA-256:

- tools/event_vm_control.py: 1f5241c9b6d1b24b0931bab01ecb90948a7c490fdbe2c6add8f9e216ff216d87
- data/event_vm_control.json: ae69cf7a0a36114aaf6129138a1d6c7c8f6a88a76410be08a167d0a188bfcf72
- data/event_vm_control.coverage.json: 46a4b333eebe8d60468ea0d5b25bf92603a39131b8bb7a0baac381f590110f94

Root owns flags42/43. Flags48, field branches49..4E, event jumps10..17 and other coherent opcode families are separate remaining frontiers; none is silently accepted by this dispatcher.
