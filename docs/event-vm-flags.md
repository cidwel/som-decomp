# Event flag range and nibble operations

The direct handlers C1F140/47, C1F16F/79 and shared skip helper C1F1BE/13 total139 instruction bytes. The range handler compares the complete flag byte against packed inclusive bounds and advances the low script cursor by3 or5 before native dispatch. Bounds are not reordered. The nibble handler reads a flag index, optionally ORs or XORs its low nibble, optionally writes it while preserving the high nibble, and returns immediately for a zero result. Nonzero results advance the cursor by3 and resume dispatch. The shared helper advances it by5. None increments script bankD3.

All12,560 original calls pass:256 packed bounds crossed with values0..15 andFF (4,352);256 operation bytes crossed with16 low nibbles and high nibbles0/A (8,192);16 skip-helper contexts. The nonzero and range paths execute the original dispatcher and next NOP, rather than hooking that continuation. The zero nibble path returns through the native RTS. Coverage records99 PC/M/X states.

The direct-entry domain is D0/DB7E/M8/X8, binary arithmetic, valid runtime WRAM scripts and all flag combinations. Full randomized128KiB WRAM agrees outside only the instruction-observed stack, together with CPU/context and video/peripheral state. No NMI occurs. All local dependencies and ROM/checker/CPU hashes remain current. Runtime script bytes are not saved. This closes these handlers, not the complete interpreter or arbitrary resumed callback families.

The F175 interior primitive is used by opcode48 and requires its own composition adapter: it starts from DP04 and the caller's existingY, so replaying the F16F script-reading header would alter its behavior. The delivered model/checker are frozen; that adapter belongs in a separate module.
