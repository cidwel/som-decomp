# Stack-argument copy and byte sign extension

C1479D/79 consumes a caller-owned destination24/source24/count16 parameter block
above its near return address. It saves the direct page and processor status,
allocates six scratch bytes below the saved state, saves the data bank and forces
bank0. A nonzero count copies the two long pointers into that actual stack frame.
Odd counts transfer one byte first, then the remaining words move forward. Each
word is read before its two writes; forward overlap therefore preserves the
original word-loop behavior, which differs from repeated byte copying. The
pointers are read from the live scratch frame on every iteration.

The copy requires incoming X16: its literal LDY immediate has two operand bytes
and the body does not widen the index registers. Both incoming accumulator
widths are accepted and restored. The helper returns the original data bank,
direct page, stack and processor status, with final N/Z from the restored direct
page. Its accumulator contains the temporary saved-stack position. The caller
continues to own its parameters above the return address.

C147EC/21 widens both register classes, interprets accumulator bit7 as the byte's
sign and publishes its 16-bit extension in X. It then restores processor status
and the direct page; restoring X8 narrows X again, while the accumulator retains
the full extension. Final N/Z again come from the restored direct page.

The independent model reproduces physical stack writes, including temporary bank
and scratch bytes. The strict comparison includes every WRAM byte with no stack
exclusions, SRAM, hardware state and all CPU/context fields through the actual
near return. Copy examples cover0..513 and32767/32768/65534/65535, WRAM/ROM/SRAM,
low-bank mirrors, bank boundaries, identity and forward/backward overlaps, and
caller stacks01FF/1F00. Extension examples cover all256 bytes, both M/X widths and
direct pages0/1/8000/FFFF. Binary native mode is explicit. No hooks, substituted
returns, original payload or saved-state blobs are used or persisted.


The frozen full proof passes4,572 complete original calls and1,828,268 original
instructions. All62 own starts are observed (50 copy and12 extension), with each
immediate width independently established from native capture. Temporary
ca65/ld65 assembly matches all100 ROM bytes. The audit verifies all four recursive
dependencies unchanged and the genuine report/coverage hashes.

`data/runtime_stack_copy.source_audit.json` records the audit;
`tools/runtime_stack_copy_source_adoption.py` contains the proposed adoption.
Single-case replay evidence is diagnostic only and excluded from adoption.
