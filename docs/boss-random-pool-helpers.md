# Direct boss random-pool helper contracts

The existing matching sources C2302C/28 and C23048/15 now have standalone
readable models and direct original-call evidence. Their earlier evidence came
from the C2300B public bounded generator. This adds no source bytes or ROM
coverage: the 43 instruction bytes were already reconstructed.

`BossRandomPool` preserves the native byte accumulator and index contract,
including the accumulator's high byte, carry from the last comparison, flags
from the final index increment or XOR, and unchanged caller context. Index
advancement increments a byte and clears it only when the result equals 55.
Invalid values therefore retain the original byte arithmetic rather than being
normalized modulo 55. The pool helper performs both index advances before
reading the second pool byte, storing it in D+46, and reading the first index.
This ordering matters when that scratch byte overlaps the pool or its indices.

The new capture `data/boss_random_pool_helpers_proof.json` passes 4,217 complete
native RTS calls and 84,120 instructions: 768 index-helper calls and 3,449 pool
calls. It covers every byte increment value at X=0/1/255, all 55×55 valid index
pairs, every byte first index paired with a permutation of second indices,
and directed scratch aliases at 0306/0307/033C/033D/033E/033F/03FF. All 18 own
instruction starts execute. Full randomized WRAM, returned CPU/context,
arithmetic hardware, video state, DMA and SRAM compare, excluding only the
stack bytes consumed by the real call. No instruction hooks are installed.

The direct ABI is native M8/X8, DB=0 or 7E, caller stack 1F00, and the tested
direct-page layouts. Both values of the decimal flag remain unchanged because
the helpers perform no decimal arithmetic. Arbitrary widths, banks, stack
aliases, seed initialization and complete boss trajectories remain outside
this direct contract. These standalone cases supplement the frozen public
generator capture without modifying it.

Reproduce with:

```sh
python3 tools/coverage_run.py ROM data/boss_random_pool_helpers_proof.coverage.json tools/boss_random_pool_helpers_proof.py --json data/boss_random_pool_helpers_proof.json
```

The source audit independently assembles the two existing mnemonic files and
checks every original byte, all own instruction starts, and unchanged capture
dependencies. Its hashes are recorded in
`data/boss_random_pool_helpers_source_audit.json`.
