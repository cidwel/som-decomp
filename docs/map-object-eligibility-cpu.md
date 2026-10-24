# Complete CPU contracts for map-object eligibility

`tools/map_object_eligibility_cpu.py:Eligibility` reconstructs three complete helpers already present in the matching assembly catalogue. This adds no new source-byte credit.

| Entry | Bytes | Behaviour |
| --- | ---: | --- |
| C0E2E1 | 67 | Releases an actor to its cached position and layer record |
| C0DF85 | 79 | Tests the cached position against the selected load window |
| C2C757 | 47 | Tests an event flag against inclusive packed minimum/maximum bounds |

Release converts the two actor coordinate words to seven-bit tile coordinates, propagates the actor layer bit into cache bit3, and clears the cached occupied bit. Its final N/Z flags come from restoring Y, while the accumulator retains the tile-coordinate high byte. The viewport gate uses byte subtraction and a single extent addition on underflow, preserving wrapped arithmetic rather than normalizing coordinates. Equality with a window extent rejects the object. Event bounds use the high nibble as minimum and low nibble as maximum; inverted ranges therefore reject every value. The event helper leaves its flag and both decoded bounds in direct-page scratch bytes0..2.

The report and coverage contain3,072 complete original calls without execution hooks,1,024 per helper. Comparisons cover randomized128KiB WRAM outside seven native caller-stack bytes, all processor outputs, restored stack/direct-page/data-bank context and static peripherals. The declared domain is D0/DB7E, binary arithmetic, X16 and both incoming accumulator widths;12 actor slots,48 cache records, boundary coordinate/extents and all256 packed event-bound bytes are exercised. This proves these helper contracts, not the full object scan, creator or live frame. Existing source contracts remain in the catalogue history.

Independent linear disassembly confirms coverage of every instruction start in these bodies:36 for release,42 for viewport and29 for event bounds.
