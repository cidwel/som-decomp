# Title colour HDMA resources and remaining corrupted-header continuation

The two constructor bodies8A54/8AB5 remain uncredited. Complete allocator
B08132 and forced-blank helper91A222 now pass552 original calls,632812
instructions, all35 own starts and exact independent assembly. Their54 decoded
RAM bytes are adopted with zero physical ROM credit. Frozen dependencies remain
unchanged. See data/boot_native_title_hdma_helpers_proof{,.coverage}.json, its
source audit and data/source_checkpoint_20261010_hdma_helpers_resume.json.

| Entry | Bytes | Complete body |
| --- | ---: | --- |
| 7E8A54 | 97 | Allocate a colour buffer and publish its HDMA descriptor |
| 7E8AB5 | 75 | Construct three colour buffers and the fourth fixed colour channel |
| 7EB081 | 32 | Round a byte request and allocate heap units without filling |
| 7E91A2 | 22 | Program pending transfers during forced blank and reclaim descriptors |

These are decoded RAM instructions from C77C00, with zero physical ROM byte
credit. The independent 21-byte body at 7E8B00 is outside this reservation.

`boot_native_title_hdma_resources.py` composes the unchanged readable heap,
pointer-copy and descriptor models. The new forced-blank adapter uses the
unchanged complete 305-byte descriptor-pass model and the existing cleanup
calculation. The checker compares full registers and context, WRAM outside the
observed physical nested stack, SRAM, peripherals and ordered hardware writes.
No scheduler or opcode hooks are installed.

Fixtures begin with the readable cold caller, complete startup resources,
actual scheduler launch and idle yield that produce main task600 at CD50.
The primary 744 fixtures cover helper and group with zero through eight free
channels, normal/fragmented/full heaps, and thirteen allocator sizes through
65535 in eight saved contexts. A further 240 fixtures exercise the new
forced-blank body with zero, one, two, eight and32 transfers to VRAM, CGRAM,
WRAM or OAM, three HDMA callback choices and four saved contexts.

The actual colour templates at 5D6C,5D79 and5D86 start with byte120. Although
8A54 requests a 13-byte copy, the existing C44E small odd-length path replaces
the accumulator low byte with that first byte before decrementing and shifting.
It consequently copies119 bytes into the reserved 128-byte heap unit. The
model retains this behavior.

When no HDMA channel is free, allocation clears the descriptor flag and returns
zero; these callers continue writing through offset zero. When the heap is
full, the template copy also writes through offset zero and can corrupt the
resource headers. In group fixture218 the resulting descriptor base is3F18,
vector0018, pending count6308, pass count840C and forced-blank flag15. The
subsequent full-pool path reaches8FFB and genuinely calls9164, which in this
state takes91A2. This is not a simple failed allocation return.

The current `DescriptorWait` checkpoint at8FFB records that unresolved path
explicitly. Both `verified` and `complete_source_contract` remain false; it
does not supply a completion or source-closure claim. The trial0 diagnostic
contains711 original instructions and335 observed PC/M/X states. Its strict
returned-state checks passed with zero free HDMA channels and a normal heap.
It is diagnostic evidence only and must not be integrated as a complete proof.

## Resumption and corrupted-header frontier after resume

`boot_native_title_hdma_retry_capture.py` passes both complete callers with
32 queued DMA descriptors. Its setup executes the actual CC16 timer producer
(27 instructions) and full installed-vector IRQ (1691 instructions), producing
a real main600 notification. The full calls traverse9164→91A2 reclamation,
ABE7 suspension and same-task resumption, then return with strict full state
and ordered I/O comparisons. This two-call valid-pool domain is execution
evidence only: it does not close the malformed heap-full group.

`boot_native_title_hdma_corruption_frontier.py` follows original group218
through the retained address0 writes and corrupted headers. It reaches9164,
91A2 and91B8, attempting DMA writes to213A..213D. The new isolated bus adapter
handles writes to read-only2134..213F as no-ops, consistent with the primary
[Snes9x S9xSetPPU source](https://github.com/snes9xgit/snes9x/blob/master/ppu.cpp).
Its48 directed synthetic cases cover all eight DMA patterns and
increment/fixed/decrement source addressing with lengths11/257, checking full
memory/peripherals and real source/count updates; this conformance adds no
native gameplay or source credit.

At instruction4981 (including the failing attempt), group218 reaches reverse
DMA read21F8 at7E9284. The frozen bus has no unsupported-port/open-bus
semantics for this operation. The diagnostic stays verified=false and
complete_source_contract=false. No zero read value or successful return is
invented. Next work: a new independently supported reverse-DMA/open-bus
adapter, then the actual corrupted cleanup/ABE7/IRQ/message continuation.
The pool/heap corruption is preserved, not sanitized. All comparisons are
terminal and the original CPU window is released.

## Unmapped reverse-DMA data latch — 2026-10-10

The new `boot_hdma_open_bus.py` leaves all frozen bus/CPU models unchanged.
It retains the actual CPU data latch: CPU writes update MDR; ordinary reads
update it except internal4000..43FF accesses; DMA reads update it. Unmapped
B-bus2184..21C1/21C4..21FF reads retain the current MDR and writes have no
device effect. Ports21C2/21C3, APU ports and other mapped unsupported devices
are deliberately still open. Existing BG-scroll handlers now accept DMA
writes210D..2114 without replacing their semantics.

Primary references: [bsnes CPU memory accesses](https://github.com/bsnes-emu/bsnes/blob/master/bsnes/sfc/cpu/memory.cpp),
[DMA readA/readB and transfer](https://github.com/bsnes-emu/bsnes/blob/master/bsnes/sfc/cpu/dma.cpp),
[unmapped bus reader](https://github.com/bsnes-emu/bsnes/blob/master/bsnes/sfc/memory/memory.cpp)
and [CPU device maps](https://github.com/bsnes-emu/bsnes/blob/master/bsnes/sfc/cpu/cpu.cpp).
This is data-effect support, not a claim of full cycle timing or every bus port.

`boot_hdma_open_bus_conformance.py` passes56 directed synthetic cases:
48 reverse-DMA cases cover all8 transfer patterns, increment/fixed/decrement
addressing and11/257-byte lengths, checking full memory/peripheral effects
and the MDR internal-read exception;8 native synthetic LDA1/STA420B sequences
prove the trigger's actual data value becomes1 independently of the incoming
MDR. These are processor/bus tests, not original gameplay comparisons.

`boot_native_title_hdma_open_bus_frontier.py` now follows original malformed
group218 for5218 attempted instructions to7E9284, through22696 reads21F8,
22694 reads21F9 and24320 each21C4/21C5. The retained MDR is1 for these reverse
transfers, rather than a fabricated zero. Earlier readonly213A..213D and
BG-scroll DMA effects are preserved. The next unsupported operation is DMA
write2101 (OAM/object graphics selection). The actual original PC after the
failing store has advanced to9288; `failed_instruction_entry` records9284.
No successful return or model comparison is claimed. Both constructors remain
uncredited, and source/progress metrics are unchanged. Next: independently
support2101, then continue the genuine corrupted DMA/cleanup/scheduler path.

## Object/PPU buses and retained vblank phase — 2026-10-10

`boot_hdma_object_bus.py` implements OBSEL2101 tile-base/name-select/size
fields while retaining the original screen register and write log. DMA writes
2101..2133 route to the existing explicit PPU handlers. Write-only register
reads now distinguish CPU MDR from the18 ports backed byPPU1 MDR, per the
[primary bsnes PPU I/O source](https://github.com/bsnes-emu/bsnes/blob/master/bsnes/sfc/ppu/io.cpp).
No unknown mapped register is silently treated as empty memory.

The original group218 diagnostic now reaches6614 attempted instructions and
stops on VRAM access with INIDISP enabled. The predecessor only permits forced
blank. A separate `boot_hdma_vblank_bus.py` adapter accepts video data effects
under an explicit static vblank input matching the existing all128 blank
samples. It does not change INIDISP or the actual forced-blank flag, nor claim
physical scanline timing. VRAM/CGRAM access preserves the existing address,
latch, mask and increment effects; visible unblanked access remains unsupported.

`boot_hdma_video_conformance.py` passes341 synthetic cases:256 OBSEL field
combinations throughDMA;52 write-only PPU reads with distinct CPU/PPU1 latch
values;32 complete video-data comparisons against the unchanged forced-blank
reference over all4 VRAM mappings,4 increments and both byte modes plus CGRAM
wrap/mask/readback;1 rejection of unsupported visible unblanked access.
These conformance cases add no original gameplay or reconstructed source bytes.

`boot_native_title_hdma_vblank_frontier.py` follows the retained corrupted
header fixture for23665 attempted instructions. The program transfers control
to7E02C4, within its stack page, and encounters opcode00/BRK. The frozen CPU
has no00 implementation; the diagnostic records that explicit boundary at
failed_instruction_entry7E02C4 (post-fetch PC02C5). It remains verified=false,
complete_source_contract=false and source_credit0. No completion or fabricated
return is reported. Next: compose the independently verified native BRK/COP
adapter to follow the actual vector/continuation, retaining all corrupted
WRAM/header/stack effects; full constructor closure still remains open.
All capture processes are terminal and the exclusive original window is free.

## Native software interrupt continuation — 2026-10-10

`boot_native_title_hdma_brk_frontier.py` composes the existing independently
verified native BRK/COP processor with the frozen vblank/bus diagnostic.
The original malformed group218 reaches the100000-instruction bound with289
software interrupts. First BRK at7E02C4 consumes signatureC3 and pushes
bank7E,PC02C6,status01, then reads the actual00FFE6 vector to00FFFF.
Later BRK/COP events read00FFE6/00FFE4 to00FFFF and retain actual stack writes
through stack wrap. No ABE7 resumption or normal return is reached within
this bound. Finite tracing does not establish permanent nontermination.

The report stores numeric event samples and their full-list hash, dependency
hashes and ROM identity; it contains no ROM/graphics payload. It remains
verified=false, complete_source_contract=false and source_credit0. The54
helper source bytes stay verified; the172 constructor bytes remain WIP.
All predecessor reports/tools remain unchanged. Capture is terminal and the
exclusive original CPU window is free. Further work should prioritize the
title parent188/full termination, retaining this malformed-path evidence for
the eventual full constructor contract. No local commit was made for this
adapter/report/documentation, following the user's updated preference.
