# Boot, the $C1:4C30 decompressor and the program in WRAM

Latest: the complete inactive sprite/group pool now matches original execution through7ECD63 (10,117 instructions/all6,829 writes). Both retained reviews pass; see the full-pool section below. Whole-boot/caller history remains separate.

Fresh first-fill comparison now passes711 original instructions and2302 ordered WRAM writes through actual B45F pointer publication. The real C3BF producer creates the four-byte MVN/RTL block; eight exact pairs copy2047 bytes after the initial zero, preserving all stack/local writes and CPU state. Root and independent retained receipts are `data/frontier_b0a1_first_fill_root_retained_result_review_20261016.json` and `data/frontier_b0a1_first_fill_retained_result_independent_peer_20261016.json`. This retains the declared A961 CPU entry and does not close full B42B or boot/caller history. No new source byte credit.

The first actual 0800-byte heap reservation now also passed a fresh source/literal/original comparison through the real B081 return to B0BF: 430 combined instructions, 814 fetch bytes and all 158 WRAM writes, including111 private stack/local writes. The allocation starts at $1000, hint32→48 and maximum31→47; sixteen countdown and owner2 records are written by the allocator. No fill or generated MVN has executed. See `data/frontier_b0a1_first_reservation_root_retained_result_review_20261016.json` and its independent peer.


The subsequent fresh B42B prologue now also matches the original CPU through the real first JSR B0A1: 56 combined instructions, 106 fetch bytes, 31 total ordered writes and 19 private stack/local writes. Entry to B0A1 has D=$02EC, S=$02E9, X=$0800, A=$0100, M8 and genuine heap hint32. The callee has not yet executed. See `data/frontier_b42b_first_fill_entry_root_retained_result_review_20261016.json` and its independent peer.


Tags: **[V]** executed in `cpu65816.py` and compared with an independent decoder; **[C]** read from instructions. No decoded game bytes are stored in the repository.

## Reproduce

```
python3 tools/boot_decode.py ROM --json data/boot.json --disasm /tmp/boot-disasm.txt
python3 tools/rom_map.py ROM --list-unknown 10
```

`boot_decode.py` compares the real boot block byte for byte, runs the reset vector up to `$7E:AF0B`, checks four additional initialization blocks and checks 240 generated streams (six selectors, two destination banks, 20 cases each). The generated streams mix literal runs of 1-128 bytes and backward copies, including overlapping copies; the header's second byte varies across cases. The optional disassembly contains addresses, mnemonics, operands and M/X states, without byte columns. Write it outside the repository.

## Calling convention [V, C]

- `$C1:4C30` is a **near subroutine**, returning with `RTS`; the public far-call wrapper is `$C1:0014` (`JSR $4C30; RTL`).
- Inputs: low byte of A = source bank, high byte of A = destination bank; X = source offset, Y = destination offset. Indices are 16-bit internally; the caller must supply their full offsets.
- The routine saves/restores P, D and DB. X and Y advance through input and output; A is scratch. It builds a direct-page workspace on the stack and copies a small executable kernel there. Both `MVN` instructions in that kernel are patched with the destination bank; the literal-copy instruction also receives the source bank.
- The apparent argument read at `$C1:4C6D` (`LDA $01,S`) retrieves the saved source X. `$C1:4C70` and `$C1:4C7B` consequently read the **compressed header**, not arguments following a call. This routine requires no inline-argument skipping in the disassembler.

The boot sets A to `$7EC7`, X to `$7C00`, Y to `$8000` and calls the routine at `$C1:4D40`. The returned X is `$B465`, Y is `$D6D3`. The far wrapper is also used from the decompressed program and from boss graphics code [C].

## Compressed format [V]

Four-byte header:

| Offset | Meaning |
|---|---|
| +0 | selector `s`, 0-5 |
| +1 | not read by this routine; zero in the five measured ROM blocks |
| +2, +3 | output length, **big endian** |

After the header, each token is either a literal run or a backward copy. Let `shift = 5 - s` and `mask = (1 << shift) - 1`.

- Token `t < 0x80`: copy the following `t + 1` bytes from the source bank to the destination bank.
- Token `t >= 0x80`: read one more byte `b`; distance = `((t & mask) << 8 | b) + 1`; length = `((t & 0x7F) >> shift) + 3`. Copy forward from `Y - distance` within the destination bank. Overlap is intentional: distance 1 repeats the preceding byte.

| Selector | Distance range | Copy length range |
|---|---|---|
| 0 | 1-8192 | 3-6 |
| 1 | 1-4096 | 3-10 |
| 2 | 1-2048 | 3-18 |
| 3 | 1-1024 | 3-34 |
| 4 | 1-512 | 3-66 |
| 5 | 1-256 | 3-130 |

The six masks live at `$C1:4C00`. The selector also adjusts the copied kernel's backward branch to skip that many of its five `LSR` instructions. `$C1:4CC0` reads a token and increments X **before** testing `Y >= destination + output_length`. Thus it consumes one lookahead byte beyond the encoded block; there is no terminator token. `encoded_size` excludes this read, `consumed_size` includes it. The code does not clip a token's copy to the declared output size [C]; the measured and generated valid blocks end exactly at it [V].

The decoder models the routine's bank-local copy and unsigned end check. It is not a general decoder for blocks whose destination-plus-length wraps: the original end check itself would terminate before producing that intended wrapped output. Selectors outside 0-5 are not assigned a format here.

## Measured blocks

All five decoded outputs match the original routine byte for byte [V]. The four initialization source/destination pairs are read from `$7E:AD75`; their place in a full hardware-driven boot has not been traced [C].

| Source | Encoded bytes including header, excluding lookahead | Destination | Output bytes | Selector |
|---|---:|---|---:|---:|
| `$C7:7C00` | 14,436 (`0x3864`) | `$7E:8000` | 22,227 (`0x56D3`) | 1 |
| `$C7:B480` | 3,389 (`0x0D3D`) | `$7E:5000` | 7,142 (`0x1BE6`) | 4 |
| `$DC:F240` | 1,466 (`0x05BA`) | `$7E:2000` | 8,192 (`0x2000`) | 5 |
| `$DC:E800` | 2,095 (`0x082F`) | `$7E:4000` | 3,072 (`0x0C00`) | 3 |
| `$C7:C1C0` | 821 (`0x0335`) | `$7E:4C00` | 1,024 (`0x0400`) | 3 |

The first block contains 1,717 literal runs and 2,941 backward copies. Its encoded range is `$C7:7C00-$C7:B463` inclusive; the extra read is `$C7:B464`. The recovered program occupies `$7E:8000-$7E:D6D2`, containing both instructions and data. `rom_map.py` now classifies the encoded range as a compressed program, excluding false instruction hits inside it; it does not classify every decoded byte as an instruction.

## Reset and software restart

The reset vector is `$00:8004`; it selects native mode and goes through `$C1:0010` to `$C1:4CE5`. That sets the stack to `$01FF`, DB to zero, invokes `$C1:4D0F` and jumps to `$7E:AF0B`. The initialization disables NMI/IRQ in `$4200`, forces blank in `$2100`, sets the two RAM interrupt entries to `RTI`, clears `$4200-$420D` and writes `$FF` to `$4201` before decompression [C]. Executing the complete reset path to, but not including, `$7E:AF0B` takes 146,524 interpreter steps and produces the same decoded block [V]. This is an instruction count, not SNES cycles or frames.

The ending's software restart through `$C1:0018` / `$C1:4CFA` repeats this loading sequence and jumps to `$7E:AF28` [C]. The newly readable entry points are:

| Entry | Call sequence [C] |
|---|---|
| `$7E:AF0B` | `$AD75`; X=`$6488`, A=`$7E`, call `$AB88`; `$A88F`; `$AE28`; `JSL $C0:0000`; `JSL $C0:0012`; `JML $C0:0009` |
| `$7E:AF28` | `$AD75`; X=`$5EC3`, A=`$7E`, call `$AB88`; `$A88F`; `$AE28`; `JMP $AF0B` |

This resolves the restart address to a distinct prelude that eventually reaches the cold-start entry. It does **not** yet establish what appears on screen or how input changes the path.

`flowdis.run` accepts optional RAM bank images, so these entries can now be followed at their actual addresses. The initial static walk reaches 1,757 RAM instructions, totalling 3,248 instruction bytes, within the recovered block. This is provisional static coverage: calls may change M/X and indirect targets are not resolved. The remaining output includes both unreached code and data; the count is not an executed-coverage claim.

## Interrupt setup [C]

Initially `$00:0100` (NMI) and `$00:0104` (IRQ) contain `RTI`, installed by `$C1:4D0F`.

The recovered routine `$7E:A1E2` sets the vertical timer word at `$00:4209` to `$00C0` (192), writes `JML $7E:A266` at `$00:0104-$00:0107`, keeps the NMI entry as `RTI`, clears pending IRQ/NMI status reads and waits for a transition into vertical blank through `$4212`. It then sets bit `0x20` in the `$0090` register shadow and `$4200` (vertical IRQ enable).

The handler at `$7E:A266` saves P, D, DB, A, X and Y, selects DB=`$7F`, D=`$4200`, and checks `$7F:008C`. Its active branch acknowledges `$4211`, enables NMI with bit `0x80` in the `$7F:0090` shadow / `$4200`, calls several RAM routines, and waits for `$4210` bit `0x80` before continuing; it later clears the enable bit. The callees, complete restore/return and later replacement of the NMI trampoline still need analysis. These reads are static; no interrupt or PPU timing is emulated for this finding.

## Next work

- Trace `$7E:AD75` and both entry preludes with explicitly modelled hardware waits; identify the role of `$AB88` and its two entry arguments.
- Resolve indirect calls in the recovered image and catalogue the remaining compressed-program instructions and data.
- Enumerate actual calls through `$C1:0014` in ROM and RAM, recovering their source/destination registers. A raw scan finds five ROM occurrences, but at least `$C7:9AAA` is inside the now-confirmed compressed block and cannot be treated as a call.
- Finish the IRQ/NMI bodies and find later trampoline writes.

M1 remains open until these items are complete; the decompression format, initial program block and four initialization blocks are now verified.

## Boot tasks and the priority queue (2026-10-08)

```
python3 tools/boot_tasks.py ROM --json data/boot_tasks.json
```

`$7E:AD75` now runs to its `RTS` in 55,642 interpreter steps from the recovered initial RAM image, with no hooks skipping its callees [V]. This verifies execution of resource initialization in this interpreter, not PPU/SPC/DMA timing. In particular it loads the four additional blocks listed above. The CPU does not implement a complete SNES hardware model; do not infer visible boot behaviour from this run.

`$7E:AB88` calls `$7E:AAFF` to obtain a task record, inserts it through `$7E:A8D6`, returns its task id and increments the active-task counter at `$7F:009A`. The task descriptors supplied by the two entry preludes are data, not executable entry addresses [V, C]:

| Descriptor | Task code entry (+0, 24-bit) | Priority (+3) | Result of creation [V] |
|---|---|---:|---|
| `$7E:6488` | `$7E:CD50` | 112 (`0x70`) | node `$7F:0600`, id 2 |
| `$7E:5EC3` | `$7E:934F` | 128 (`0x80`) | node `$7F:0600`, id 2 |

Each row was run independently after initialization. The source descriptors contain ten bytes, copied by `$7E:AAFF` through `$7E:C44E`. The meaning of all remaining descriptor fields and the generated task stack needs further work; no full descriptor schema is claimed yet. After each measured creation, the node status at +2 is `0x08`, its priority at +3 matches the descriptor, the free-list head advances from `$0600` to `$0610`, the run-list head becomes `$0600`, and the task counter becomes 1 [V]. These tests create the task; they do not execute its entry routine.

The recovered insertion operation, `$7E:A8D6-$7E:A90C`, is implemented as `enqueue` in `tools/boot_tasks.py` [V]:

1. Start at the sentinel word `$7F:00A0`.
2. Follow each node's link word at +0 while the successor's priority byte at +3 is less than or equal to the new priority.
3. Put the new node between the last such predecessor and its successor.

Thus the linked list is ordered by increasing numeric priority. New tasks go **after existing tasks of equal priority**. That ordering does not by itself prove which task the dispatcher chooses to run first.

The original routine and model were compared across the entire 64 KiB bank `$7F` in 320 generated cases: lists of 0-20 tasks, priorities spanning 0-255, head/tail/interior insertion and equal-priority insertion. Untouched bytes are randomized; the comparison consequently also checks for unexpected changes outside the link words. X returns the inserted node. This is a model of the queue mutation, not a register/cycle-accurate substitute for the entire task system.

The next analysis can use the actual task code entries `$7E:CD50` and `$7E:934F`, rather than disassembling the descriptor addresses as instructions.

### New-task dispatch [V]

The branch at `$7E:A961` was executed with a runnable new-task record (status `0x08`), DB=`$7F`, M=0 and X=0. It removes the selected node from the run-list head, clears its link, stores it as the current task at `$7F:009E`, loads S from record +6, changes status to `0x01`, enables interrupts and executes `RTL` into the entry address prepared on that stack. Both boot descriptors reach their expected entries in 16 interpreter steps. The transfer consumes three stack bytes: id-2 task `$7F:0600` reaches S=`$02F9`, and id-3 task `$7F:0610` reaches S=`$03F9`.

A third case creates the restart descriptor (priority 128) first and the cold-start descriptor (priority 112) second. The real queue selects the latter at `$7F:0610` and reaches `$7E:CD50`, leaving `$7F:0600` at the run-list head. Thus the runnable head used by this dispatch has the lowest numeric priority in this measured case. This probe enters at the dispatch branch and stops before executing the task body; it does not simulate interrupts or establish scheduling fairness. Results are in `data/boot_tasks.json`.

### Initial task stack frame [V]

`$7E:AA42-$7E:AA76` is now modelled by `prepare_frame` in `tools/boot_tasks.py`, checked against the original routine with 100 generated ten-byte descriptors, including entry/continuation offsets whose subtraction wraps. For stack page base B, it constructs three chained long returns:

| Address | Stored field |
|---|---|
| B + `0xF7-0xF8` | descriptor entry offset (+0 word) minus 1 |
| B + `0xF9` | descriptor entry bank (+2 byte) |
| B + `0xFA-0xFB` | `$AA21`, so the next `RTL` enters `$7E:AA22` |
| B + `0xFC` | `$7E` |
| B + `0xFD-0xFE` | descriptor continuation offset (+4 word) minus 1 |
| B + `0xFF` | descriptor entry bank (+2), reused for the continuation |

The initial S is B + `0xF6`. The dispatcher consumes the first chain element and starts the entry. When that task executes its own `RTL`, it reaches the task-completion stub at `$7E:AA22`, rather than returning directly into an ordinary caller. That stub marks the record `0x10`, links it into the list at `$7F:00A4`, decrements the active-task count at `$7F:009A` and jumps back to the scheduler [C]. The next dispatch of status `0x10` rearranges the stack for the continuation; that branch now has an execution/model check below. Descriptor bytes +6/+7 are not consulted by this frame builder; they are not assigned an overall meaning here.

### Bounded reset/title traces

```
python3 tools/coverage_run.py ROM /tmp/title-coverage.json tools/boot_trace.py /tmp/title-trace.json steps=2500000 pad=0x1000 pad_at=800000 irq_every=5000
```

`boot_trace.py` starts at the original reset vector, captures PPU/DMA writes with the existing `PpuCpu`, routes APU ports through `boot_audio.Transport`, toggles `$4212` on reads and delivers native IRQ/NMI entries at a specified instruction interval. The IRQ/NMI machine code and `RTI` execute; no game routine is bypassed. Interrupt timing, video blank timing and the APU transport's IPL phase are models, not cycle-accurate console emulation. The current PPU capture does not implement HDMA. Instruction counts below are consequently **not frames or seconds**, and input-path observations are conditional on this harness.

The current cold trace, `steps=2500000 pad=0x1000 pad_at=800000 irq_every=5000`, reaches `$C0:0009` after 2,009,156 instructions, then stops before the main-game entry executes. It records all five known decompressor calls, 178 IRQ deliveries, 177 NMI deliveries and the SPC driver running. At entry the map word is zero, event flag 0 is `0x20`, flag `0x4E` is 7 and S is `0x01FF`. These are harness observations, not a verified complete new-game initialization. The earlier trace that continued beyond this boundary eventually entered low-RAM interrupt code and is not used as coverage evidence for gameplay.

| Descriptor | Entry | Priority |
|---|---|---:|
| `$7E:6488` | `$7E:CD50` | 112 |
| `$7E:649C` | `$7E:D54C` | 114 |
| `$7E:5F12` | `$7E:968D` | 144 |
| `$7E:6492` | `$7E:D0CC` | 116 |

The fourth task is created after START becomes active. The trace logs observed control-transfer addresses/M/X states, task creation and decompressor registers; it stores no ROM bytes or screen content. `data/boot_trace_cold.json` holds the current report. A direct software-restart probe with zero-filled initial WRAM (`data/boot_trace_warm.json`) does not reach the game within its budget. This is not a faithful ending-state restart: it lacks the live game RAM and running APU context that the software path normally retains. Do not merge that probe as validated boot coverage.

The DMA capture now updates source and byte-count registers after transfer, matching the existing `MapEnv` harness. Interrupt status reads clear pending latches; `$4210` no longer unconditionally returns NMI pending. Timing remains approximate.

### Completion and continuation models [V]

`complete_task` models `$7E:AA22-$7E:AA41`: status becomes `0x10`, the current node is prepended to the completion list at `$7F:00A4`, and the 16-bit active count decrements, including wrap. Its mutation is checked in 160 randomized cases through the jump to `$7E:A948`; the test also accounts for the single scratch stack byte written while setting DB.

`dispatch_frame` models the new/completed task branches from `$7E:A961`. For status `0x10`, the dispatcher takes the page of saved S, resets S to page + `0xF6`, copies the continuation long-return address from page + `0xFD-0xFF` to `0xF7-0xF9`, marks the task running and enables interrupts before `RTL`. It does not increment the active count. Thus the completion continuation starts with S = page + `0xF9`, leaving the completion stub chain underneath it. Status `0x08` uses the originally prepared entry frame. In 320 generated cases, both branches match the model across the entire 128 KiB WRAM and reach the predicted PC/S. The suspended-task branch is now separately modelled below; synchronization/wait handling remains open. Completed-task cleanup is also checked below.

A separate fresh status08 composition now connects six source initializers and AB88 to a physical dispatcher comparison. AB88 supplies the actual task entry/completion frame; the dispatcher CPU registers and owned code are declared API inputs. Source, literal oracle and original match across fullCPU17/allWRAM including code/taskstack/SRAM/baseHW and nine ordered table writes, with no exclusions. Sixteen original instructions consume the entry frame and reach first7ECD50 atS02F9/M8/I0 before fetching taskbody code. Independent retained review binds that one case. This adds no wholeboot history, physical initializer CPU or genuine A90D caller claim.

Interpreter prerequisites fixed for this work: SRAM reads now reach the same mapped array as SRAM writes (they were previously hidden behind the unmapped-register return), and opcode `RTI` now restores P/PC and native PBR. Native/emulation restore sizes and forced emulation M/X were checked against the [WDC W65C816S specification](https://www.westerndesigncenter.com/wdc/documentation/w65c816s.pdf), with stack/register probes. These changes enable the native RAM IRQ handler to return instead of requiring the harness to stop before `RTI`.

### Interrupt restoration and trampoline writes [V, C]

`tools/boot_interrupts.py` verifies the inactive IRQ branch (`$7F:008C == 0`) and the initial bare-RTI NMI trampoline. Each path is checked with all 256 status-byte values and randomized A/X/Y/D/DB. Both preserve the interrupted native CPU registers, flags, PC/PBR and S; memory changes are confined to the saved/scratch stack frame. The inactive IRQ path returns without reading `$4211`. These are frame-restoration probes, including forced test entries with I set; they do not claim that hardware would deliver a maskable IRQ in that state. The active IRQ's larger workload remains outside the readable model.

The title trace records only four trampoline installations: initial IRQ/NMI `RTI` at steps 20/21, IRQ `JML $7E:A266` at step 202,492, and NMI kept as `RTI` at step 202,494. No further trampoline replacement is observed before `$C0:0009` in this input/timing scenario.

Reading the full active IRQ body shows this call order: `$B804`, `$9164`, `$C0C2`, `$CCB7`; wait for the NMI status latch; `$91B8`, `$C0FD`, `$C9E5`, `$92E9`, `$C18B`, `$CD05`, `$A6FF`, `$A9C7`; disable NMI again; `$AC44`, followed conditionally by `$ACE9` and `$B2AB`; then restore Y/X/A/DB/P/D and `RTI` [C]. `$A9C7` removes **one** node from the completion list and calls the resource cleanup routines; it is not a loop over the whole list. The status-`0x10` dispatch model covers an explicit dispatch of such a node, without claiming every completed node normally reenters the runnable queue before cleanup.

The separate A90D long wrapper calls suspension through A911 and then returns with RTL. A911 saves the incoming status before changing register widths or masking interrupts; the resume path restores it. Thus the M8/X16/I0 state produced by new-task dispatch is a legitimate declared API condition. A separate readable adapter now represents that condition, with independent code-only review. Its one declared M8/I0 API case now matches an independent literal expectation and original execution across fullCPU17/allWRAM including code and stack/SRAM/baseHW and39 ordered stack writes (121 original instructions), under an explicit no-asynchronous-IRQ/NMI premise. The finite catalogue adoption retains genuine longcaller, physical producer CPU, boot loading and full contract as unproved. This establishes no hardware scheduling history.

### Eight-byte record pool [V]

`tools/boot_pool.py` reconstructs four operations used by the recovered scheduler/resource code. Each has 240 original-routine comparisons across the entire bank `$7F`, with randomized untouched memory, root/current task ids, null/FFFF sentinels and chains of 0-20 records. Payload fields remain unnamed.

| Routine | Model | Mutation |
|---|---|---|
| `$7E:B1A9-$B1DC` | `allocate` | Take head `$02C6`, advance to the old link, clear the selected link, set +2 to current task id (1 when no current task), and clear **both +3 and +4** |
| `$7E:B1DD-$B20A` | `release` | Ignore 0/FFFF; prepend to free head `$02C6`, clear byte +2, leave the other payload bytes alone |
| `$7E:B20B-$B239` | `take_link` | Return the old link and replace its word with current task id; 0/FFFF return zero |
| `$7E:B23A-$B257` | `release_chain` | Follow the returned old links, releasing each node until 0/FFFF |

The two-byte `STZ` at `$B1D1` clears +3/+4 because M=0 there; the initial model cleared only +3 and the whole-bank comparison caught it. The corrected model passes. Allocation has no empty-list guard in the original code; no invented failure return has been added. `$ACE9` supplies the current task id, while `$B16F` scans 256 eight-byte records starting at the base held in `$02C4` during task cleanup [C]. The wider resource ownership/protocol is still under investigation.

### Task identifiers and stack-page reservation [V]

`$7E:AA77-$AAD6` scans twenty bytes at `$7F:00AA-$00BD` for the first zero entry. A nonzero value is the parent id passed in A; the selected id is index + 2, hence ids **2-21**. The task record receives that id at +4 and initial S = `(id << 8) + 0xF6` at +6. The corresponding page starts at `id << 8`, and `$AA42` builds its entry/completion/continuation frame. The root/parent fallback id 1 has no slot in this array. If all twenty bytes are nonzero, X returns zero without changing a task record or page.

`allocate_task_frame` is checked in 240 cases, covering every first-free index and the exhausted array with randomized nonzero parent ids/descriptors. All task pages and the entire bank 7F are compared; only the caller's known scratch stack range 1FE0-1FFF is excluded. The test also checks returned X and restored S. This is the page/identifier reservation routine; its caller exhaustion behaviour and descriptor workspace field are now checked below. Descriptor bytes +6/+7 remain unused by this constructor.

`$7E:AAD7-$AAFE` releases the task's identifier using the **page of saved S at record +6**, rather than reading the id byte at +4. The table slot is `0xAA + (((S - 0x200) & 0xFF00) >> 8)`. It clears that byte and prepends the record to the free list at `$7F:00A6`. It leaves other record fields and the stack page contents alone; the caller's earlier cleanup clears other task fields. `free_task_frame` matches original execution across bank 7F in 240 cases spanning all twenty pages and randomized saved-stack offsets. X returns the table-slot offset, and Y returns the freed record. The routine expects DB=7F and a valid task stack page; no additional validity check has been invented.

### Cleanup ownership scans [V]

Three further routines have models in `tools/boot_pool.py`, each checked across the entire bank 7F in 160 cases. The cases include no/all/sparse/edge matches, randomized untouched bytes, owner ids including zero, search-hint limits and record words whose high byte prevents a low-byte-only match.

| Routine | Scope and exact mutation |
|---|---|
| `$7E:B0E8-$B128` | Scan 256 owner bytes at `01C4` backwards; clear each matching owner and usage byte at `00C4`. Lower byte `00C2` to the lowest matching index only when it was higher. No match leaves the hint alone. |
| `$7E:B16F-$B1A8` | Scan 256 eight-byte records from word `02C4`; compare the **whole word at +0** to the task id masked to 8 bits, and call `$B1DD` for matches. Free-list order follows the ascending scan, so the highest matching record becomes head. |
| `$7E:CBDC-$CC15` | Scan 32 four-byte records from word `0302`; compare byte +1 to the task id and clear **only byte +0**. It does not clear the owner or remaining payload. |

The eight-byte records use +0 both as a link and, after `$B20B`, as a holding task id. Byte +2 receives the allocating task id in `$B1A9`; its wider protocol and the remaining payload still need analysis. The four-byte registration payload is not fully named.

### 128-byte heap units [V]

`tools/boot_heap.py` models `$7E:AF59-$B00E` allocation and `$7E:B00F-$B080` release (the latter tested through its bank-setting wrapper `$B0D6`). There are 256 units of 128 bytes in the lower 32 KiB of bank 7F. Usage bytes are at `00C4-01C3`, owner bytes at `01C4-02C3`, high-water index at byte `00C0`, and search hint at word `00C2`. The boot initialization leaves high-water 0x32 and next-free hint 0x33; zero-pointer unit 0 is reserved. Allocation records the current task id, or root id 1 when no task is current.

Allocation scans forward from the hint for a contiguous free run. It uses 8-bit counters, writes a decreasing remaining-length byte per unit, writes the task id per unit, and returns X = unit index * 128. The low-byte count zero runs the counter through 256 iterations; it is not an ordinary zero-byte allocation. When allocation starts at the hint, the routine advances the hint by looking for the next free usage byte; when it finds a later run, the hint remains at its previous value. The search includes an end sentinel read at usage index 256 (the first owner byte); the reserved unit's nonzero owner makes a fully occupied tail wrap the hint to zero. These details are preserved in the model rather than replaced with a different allocator.

`$B081` rounds the byte size in X to units using a **16-bit wrapping** add of 127 and seven shifts [C]. `$B0A1` then fills the requested byte range through `$C37D`. The readable `allocate_bytes` model matches 96 original-routine executions, including zero/edge lengths, fragmented/full heaps and byte fills. The original still fills at offset zero when allocation fails; the model preserves that behaviour. These cases execute the fill helper and its stack-generated overlap-copy kernel without hooks. Source/base immediates in this allocator remain zero after `$AD75`, so the returned offset is bank-7F-local.

Release ignores a zero or unaligned pointer. For a nonzero usage byte, it clears the suffix beginning at that unit, clears its owners, then adjusts larger countdowns to its left by subtracting the released suffix length. Thus releasing an interior aligned unit retains a shorter prefix allocation. It lowers the hint byte when the released unit lies before it. The tested/modelled domain is valid 256-unit tables with reserved unit 0 and ordinary heap pointers; arbitrary malformed table/pointer behaviour is not claimed.

There are 320 allocation and 320 release comparisons against original execution, checking every bank-7F byte, plus returned allocation X. They cover fragmented runs, hint 0/1/128/255, small/large/zero unit counts, allocation failure, whole/interior release, zero and unaligned release pointers. The counters, owners and hint changes match.

**Declared B8C1 source composition (2026-10-15; no new native comparison).** The readable physical adapter now models the prefix at B8C1 through B0D6/B00F, retaining every consumed stack byte and stopping before B8C6. Three actual source allocator calls reserve4,2,3 units, producing offsets0080/0280/0380. Two separate declared inputs then release either the first allocation or its interior suffix; the latter keeps its one-unit prefix. The guarded source runner completed all five source calls once. Input digests match an independent literal derivation; both releases returned with32/30 completed logged writes and all23 runtime-protected inputs unchanged. Root review and scope, independent metadata peer.

The earlier source-only run above did not compare release outputs against an independent oracle or original execution. Its receipts remain historical evidence.

**Two positive B8C1 original comparisons (2026-10-16).** A separate new input includes all137 authenticated instruction bytes before three AF59 source allocations. Independent literal expectations were frozen before either release was observed. The readable adapter and the unmodified original interpreter then agree for head release0080/count4 and interior release0100/count3: all17 CPU fields, all128KiB WRAM including code and physical stack,8KiB SRAM, base hardware state and all32/30 ordered bus writes. Original execution takes92/95 instructions and stops at the first7EB8C6 boundary before fetching its next instruction. No scratch exclusions, hooks or output repairs are used. Root comparison review, independent retained-output peer.

This proves those two declared positive inputs. The genuine B840 caller, other heap/stack/register domains and the complete caller body remain open. The137 bytes were already owned source; this comparison adds zero source or documentary bytes.

### One completed task reaped per IRQ call [V]

`tools/boot_cleanup.py:reap_one` now models the **complete** body `$7E:A9C7-$AA21` by composing the checked operations. It removes one completion-list head, clears heap units and registrations belonging to its id, releases its pending record chain, releases held records, frees its explicit workspace at task +8 when nonzero, zeros the status/priority word (+2) and id/parent word (+4), then releases the stack-page id and prepends the task record to free head `00A6`. The task count is not decremented here; `$AA22` already did that on completion. An empty completion list changes none of these bank-7F fields.

160 generated contexts compare every bank-7F byte with the original cleanup and **all its callees executing without hooks**. They include empty/nonempty completion lists, records held by this/other owners, pending chains ending in 0/FFFF, registrations, workspace zero/nonzero, and workspace owned by the completed task or root. Order matters: the owner scan may already clear the workspace's usage entry, making the later explicit free a no-op. No task body or interrupt timing is modelled by this cleanup test.

## Suspended-task restoration

`tools/boot_resume.py:resume` covers the remaining branch of `$7E:A961`, reached for any status other than 08/10. It pops the run-list head as usual, marks the task running, takes the old link from the record at task +0A through `$B20B`, replaces that record link with the current task id and writes the old link back to task +0A. Sentinels 0/FFFF yield zero. This clarifies +0A as a pending record-chain link, though the record payload/protocol is still unresolved.

At saved S, the stack layout above it is first P (+1), DB (+2), final P (+3), D (+4/+5), near-return address minus one (+6/+7). The first P can already truncate X/Y; the final P can truncate them again. PLD overrides N/Z using the restored direct-page value, and RTS retains bank 7E. Thus a resumed task returns to S+7; its A is the old record link, X is the record pointer (FFFF becomes zero), and Y is the task pointer, subject to those index-width truncations. This is a near return rather than the initial/completion RTL chain.

All 320 generated cases match A/X/Y/DB/D/P/PC/S and all WRAM except the 33 scratch bytes at/below saved S used by nested calls. They include both saved index widths, varied interrupt masks, zero/high-bit direct pages, sentinel/ordinary records and seven non-08/10 statuses. The saved frame and all other WRAM remain compared. Entry ABI is native mode, DB=7F and M/X=0. Together with the earlier 320 new/completed cases, both dispatcher branches now have readable models; this does not yet reconstruct the producer's full wait/resume protocol.

## Suspending a task

`tools/boot_resume.py:suspend` reconstructs `$7E:A911-$A947`, stopping at the common scheduling continuation `$A948`. The routine saves D, the caller's P/DB and a second P with M/X cleared and N/Z from loading bank 7F. It records S five bytes below entry S in task +6, then masks interrupts. This generates exactly the five-byte restoration frame described above; the caller's near-return address is already above entry S.

A nonzero task +0A sets status 02 and reinserts the task into the stable priority run list through `$A8D6`; zero sets status 04 and prepends it to waiting head `00A2`. A further 320 generated executions check both branches, empty/populated queues, sentinel/ordinary pending records and varied caller flags/banks/direct pages. They compare WRAM apart from 33 scratch bytes below/at saved S, plus S/DB/I at `$A948`. The saved frame is included. Next-task selection and its fallback are checked below; waiting-list wakeup is also checked below.

## Waiting-task wakeup and pending-record delivery [V]

`tools/boot_wait.py` models `$AC69`, `$AD02`, `$B2AB` and `$B258`. Each has 240 full-bank-7F comparisons, including waiting-list head/middle/tail/missing cases, varied statuses, sentinel/ordinary pending links, empty/populated ready queues and valid/missing recipient ids. Delivery also checks the returned low A byte; lookup checks X.

`$AC69` acts only on status 04. It removes that task from waiting head `00A2`, sets status 02 and inserts it into the stable priority run list. If a status-04 task is missing from the waiting list, it changes to status 80; it is not inserted. Other statuses are untouched. `$AD02` rejects id zero and otherwise scans twenty 16-byte task records at the base in `009C`, returning the first matching +4 byte without checking status. Parent bytes at +5 do not participate.

Both delivery routines clear the new record's link before lookup, including a failed lookup. On success the low A result is FF; on failure it is zero. Task +0A is the pending-record queue head. A head of zero or FFFF is replaced by the new record and triggers `$AC69`. For an ordinary nonempty chain, `$B2AB` prepends the new record, whereas `$B258` follows zero-terminated links and appends it. Failed delivery does not release the supplied record. This explains the earlier link/holding-id union: dispatch consumes the queue head through `$B20B`, replacing the consumed record's link with the receiving task id; task +0A advances to the old link. Full record payload formats beyond the timer message below remain open.

## Task timer registrations and IRQ scanning [V]

Each four-byte registration at the base in `0302` is status (+0), task id (+1), and countdown word (+2/+3). `$CB86` reserves the first status-zero record among 32, setting status 1 and id while retaining the countdown; exhaustion returns X=0. `$CC57` sets status 2 when the countdown is nonzero, otherwise status 1. `$CC43` and `$CC78` set only status 1. These operations add 240 cases each (120 per identical status-1 entry), checking the entire bank and allocation X. Cleanup `$CBDC` already clears status by task id.

`$CCB7-$CD04`, called by the active IRQ, scans up to 32 registrations. Before each one it latches the PPU counter through `$2137`, reads `$213D` twice and compares the **first/low counter byte** against DE. At or above DE it stops, retaining the number of unprocessed records at byte `0304`. Otherwise status-2 countdowns decrement with 16-bit wrap: zero becomes FFFF. A transition from 1 to 0 calls `$CC8C-$CCB6`.

That notification allocates an eight-byte record through `$B1A9`, overwrites tag +2 with FF, stores the registration pointer as word +4/+5, and appends it to the registration's task through `$B258`. The registration then returns to status 1, even if its task id was not found. The original allocation/free-head behaviour is retained; no additional failure guard or automatic release is inserted.

Timer scanning and notification each pass 160 full-bank comparisons, executing every original callee without game hooks. Inputs include scans stopping before the first/at intermediate/after all records, varied inactive/waiting statuses, countdowns 0/1/2/FFFF, existing pending chains and missing/valid task ids. Notification's entry requires DB=7F. The scanner supplies its own bank. A small PPU-read harness supplies specified latched counter bytes, including varied high bytes that the original comparison ignores; these checks establish behaviour for those reads, not accurate scanline timing. No ROM bytes or message contents are saved.

## Complete task creation and next-task selection [V]

`tools/boot_create.py` composes the checked frame, timer and heap operations to reconstruct `$7E:AAFF-$AB87`. It copies the ten-byte descriptor from the supplied A-low bank/X offset into caller-stack workspace using `$C44E`, pops the free task record from `00A6`, clears its link, and sets its parent byte +5 to the current task id (root 1 when no task is current). `$AA77` reserves the id/page and prepares the RTL frame. Descriptor byte +3 supplies priority, and the new status is 08. A timer registration for the new task id is stored at task +0C.

Descriptor word +8 is the workspace size in bytes. A zero size stores a zero workspace pointer. Otherwise `$B0A1` reserves and fills that range with the **low byte of the timer-registration pointer**, because A holds that pointer after `$CB86` and TXA. The returned pointer is stored at task +8. Allocation ownership still comes from the current/parent task, not the newly created task, which explains the explicit workspace release during reaping. The constructor does not clear pending link +0A or trailing word +0E. Descriptor +6/+7 is unused by these operations; the continuation's bank comes from the entry bank (+2) in the separately checked frame builder.

The original has no rollback after the free record is popped. If no task record is available, it returns X=0. If id/page reservation is exhausted, `$AA77` returns X=0 but the constructor continues: priority/status are written at bank-7F offsets 3/2, registration ownership is taken from offset 4, and subsequent registration/workspace fields are still written to the original popped record. Registration exhaustion stores a zero timer pointer. Workspace failure still fills at offset zero as `$B0A1` does. These are checked original behaviours, not inferred error handling.

`spawn` models `$AB88-$ABAC`: a nonzero returned record is enqueued and increments the 16-bit active count, including wrap. It does so even after partial-resource failure. Both creation and spawn pass 320 generated comparisons apiece, with every original callee executing. They cover all twenty first-free page positions/exhaustion, timer positions/exhaustion, parent/root contexts, varied priorities/workspace sizes, source descriptors in banks 7E and 7F, and unavailable heap/records. The test's disjoint failure groups are 40 no-record, 13 page-exhausted, 6 timer-exhausted and 39 heap-full inputs, each checked through both entries. All WRAM is compared except caller scratch `1F80-1FFF`; returned X is checked. Task pages and the bank-7F side effects remain included. Native creation ABI requires DB=7F.

`select_next` separately models `$A948-$A960`: choose ready head `00A0`, or create a task from `$7E:600A` when it is empty, then copy the returned record's id to byte `00BE`. This path does not enqueue the fallback or increment the active count; `$A961` immediately dispatches it. The original also proceeds with X=0 after failed fallback record allocation. A further 160 initialized contexts check ready/nonready lists and page/record exhaustion through the boundary before dispatch, including WRAM, X, S and M. They do not execute a malformed failed fallback as a task. Together with the existing suspension/dispatch models, this closes the selection gap while leaving the fallback task body and wider timer/message consumers for further analysis.

The initialized fallback descriptor `$7E:600A` resolves to `$7E:A8BE`, priority FF, continuation offset zero and no workspace. Its body repeatedly calls `$ABE7` with X=0 while active count `009A` is nonzero, then restores S from `0098`, calls `$A241` and unwinds the scheduler caller [C]. The zero continuation is not exercised by this body: it exits by restoring the outer stack. The `$ABE7` wait/receive consumer and the full fallback execution are next analysis targets.

## Receive consumers and idle outer return [V]

`tools/boot_receive.py` reconstructs the timer/receive phases of `$ABAD` and `$ABE7`, with original suspension, selection and dispatch executing between them. `$CC16-$CC42` replaces the registration countdown from Y, setting status 2 for nonzero or 1 for zero; it passes 240 full-bank comparisons across zero, byte/word boundaries and FFFF.

`$ABAD` arms the current task's existing countdown through `$CC57` and suspends. On resumption it disarms the timer and returns the received record in X, except that **any** record tagged FF is released and X becomes zero. `$ABE7` instead takes a countdown in X: nonzero replaces/arms the current timer; zero does not arm it and replaces an empty pending head with sentinel FFFF, ensuring a ready-queue yield rather than entering the waiting list. After resumption it disarms the timer, but consumes an FF record only when its +4/+5 pointer matches this task's timer registration. Other records, including unrelated FF records, are returned for the caller to handle. A preloaded pending record can therefore end either receive immediately, even with a nonzero timeout.

There are 320 complete original-call comparisons per entry with preloaded ordinary/FF records or FFFF sentinel, matching/nonmatching timer pointers, pending successors and varied caller DB/D. The bank-7F mutations and returned X match the phase model; no game routine is hooked. An additional 96 empty-queue cases wait for countdowns 1-4: the real fallback task runs and the harness calls the real `$CCB7` scanner from its loop with controlled PPU reads. Its allocation, append delivery, wakeup and the dispatch back to the original waiter all execute. The final full bank, X=0, restored caller S and number of timer-service calls match the composed model. These are controlled service calls, not a claim of hardware IRQ timing.

The fallback at `$A8BE` calls `$ABE7` with zero repeatedly while active count `009A` is nonzero. Once it is zero, it restores outer S from `0098`, calls `$A241` and pulls the outer DB/P/D/near-return frame. `$A241-$A265` decrements nonzero use counter `008C`; at zero (including already zero on entry), it clears vertical-IRQ bit 20 in shadow `0090` and writes `$4200`. Higher counts leave the register untouched. This is reference-counted IRQ use, not unconditional disabling.

IRQ release passes 160 full-bank/control-write comparisons. Another 96 complete fallback-exit calls compare the full bank, actual `$4200` writes and outer DB/D/P/PC/S restoration, including varied status widths/masks, N/Z from final PLD, and use counts 0/1/2/FF. The `finish_idle` model covers the zero-active-count exit with an empty ready queue, normal id/page-2 fallback stack and controlled context; its active-task loop is exercised by the timed receive tests but remains represented through those composed operations rather than a standalone general scheduling model. Remaining work includes other message payloads/callers and the rest of the active IRQ workload.

## Deferred timer suffix [V]

`tools/boot_wait.py:finish_registrations` reconstructs `$7E:CD05-$CD4F`, the later IRQ timer pass. It reads the **word** at `0304`, starts at timer base + `(32 - remaining) * 4` and decrements/possibly notifies that suffix without reading the PPU counter. It leaves `0304` unchanged. The earlier `$CCB7` pass writes its low byte; initialized `0304/0305` is zero, and these models assume a valid remaining word 0-32 with high byte zero. No malformed high-byte behaviour is claimed.

160 suffix-only cases and 160 combined first/second scans compare the full bank with every original notification/delivery callee executing. They cover all cutoff positions, counts 0/1/2/FFFF, valid/missing recipients and queue wakeups. The combined scan reaches every registration once in that IRQ workload, including when the first pass stops immediately. Together these two routines finish the timer scan across the NMI-latch wait in the active IRQ.

## PPU register queues and mirror [V]

`tools/boot_ppu_queue.py` reconstructs `$C0C2-$C0FC` counting, `$C0FD-$C18A` ordered register writes and `$C18B-$C25A` mirror updates/reclamation. Queue records have register offset (+0), next record's **byte offset** relative to pool base `02D6` (+1), and value word (+2/+3). Persistent-list sentinel is `02DA`; one-shot sentinel is `02DE`. Zero next offset ends either list. `02D8` holds an **absolute** free-record pointer. Initialized pool base is 0400, free pointer 0494 and mirror base `02E2` is 0380.

Counting includes both lists and excludes sentinels. Register writes first traverse the persistent list, then the one-shot list, preserving both. The class table at `$7E:603E + register` determines the second write: class zero emits only low byte at `$2100 + register`; class one emits high byte at the next register; any other nonzero class emits high byte again at the same register. The PPU latch behaviour itself is outside this write-log model.

The 38 startup selectors loaded by BFDA are separately checked against their matching one-byte sources: every selector lies in00..33. With valid original free records, queues and call frames, allocation stores that selector in record +0 and append changes only link byte +1. C0FD can therefore write at most port2134, including the class-one second byte, and these startup records cannot select WRAM port2180. Source-only certificate, retained-result peer, allocation/link coupling. The check constructed no state and executed no game routine. Later queue producers, pool preservation and a global invariant for0316 remain open.

Mirror update always stores the low byte at mirror base + register. Class one stores the high byte at the next mirror position. Other nonzero classes additionally store the full value word at mirror base + class, preserving the raw low byte at the original register offset. It leaves the persistent list in place. The one-shot nodes are returned to free head `02D8` in traversal order (the resulting free list reverses them); each freed node's first word becomes the old absolute free head, replacing its register/relative-next fields. The one-shot header word is cleared and tail `02E0` resets to the sentinel 02DE.

All three models pass 240 cases each, comparing the entire bank 7F. Count A and the exact ordered PPU address/byte writes are also checked. Inputs cover empty/unequal lists, 0-20 records per list, all register offsets 00-33, random value words and randomized untouched memory. Test pool 3000 and shadow 5000 are separate, with valid acyclic offset chains. Original routines execute without hooks; a capture records PPU writes without rendering or inventing their hardware effects. All classification values are read from the supplied boot image; no image/register payload bytes are saved.

## Controller states and input messages [V, C]

`tools/boot_input.py` models interface detection `$A4E9-$A572` and the standard-controller path in `$A6FF-$A813`. Detection writes FF to `$4201` and strobes `$4016`; each of two serial ports is polled up to eight times in two phases, stopping when bit 1 clears. Detection bits 40/80 reflect a port whose first phase stays high but whose second phase clears. When the resulting byte differs from `0096`, it is stored there and, if recipient id `0097` is nonzero, an eight-byte FE-tagged record is appended to that task. Subtype +4 is 03. Payload byte +5 is the **saved caller status P** read from `$01,S`, not a reconstructed device type. That literal stack read is retained and passes randomized-status comparisons.

The input updater is skipped unless shadow `0090` bit 0 is set. It processes five 16-byte controller states starting at the pointer in `0092`. In the standard-interface path, indices 0/2 read words `$4218/$421A`; remaining indices return invalid marker 0001. A nonzero low nibble marks the state inactive, stores zero buttons, and leaves its old edge fields intact. Value 3030 instead transfers to the reset vector [C]; that transfer is excluded from the returning-update tests.

For a valid button word, state +2 becomes the current buttons, +4 records `(old ^ new) & new`, and +6 records `(old ^ new) & (new ^ FFF0)`. Masks +8/+0A select pressed/released edges. A selected nonzero edge with recipient byte +1 at least 2 allocates a record, writes tag FE (+2), subtype 01 pressed or 02 released (+4), zero-based controller index (+5) and masked buttons word (+6/+7), then appends it to the task. The state becomes active byte 1. Missing task ids retain the original failed-delivery effects; no record is automatically released. The ordering is port order, pressed before released.

240 detection comparisons cover all four interface-bit results, changes/no changes, serial polling lengths, recipient ids and saved status bytes. 320 full updater comparisons execute detection and every allocation/lookup/delivery callee, checking the entire bank 7F. They include enabled/disabled input, masks, valid/invalid words, recipient ids and untouched-state bytes. Controlled serial and automatic-joypad register reads are supplied; these are input-data checks, not electrical timing or controller-emulation claims.

`$A6B7` also dispatches through two four-entry near-pointer tables: `$7E:A60D` at call `$A6C9` and `$7E:A6AF` at call `$A6E3`, both M=1/X=0. Targets are recorded in `data/boot_input.json` from the recovered image. Interface bits 40/80 alter index selection and choose those indirect readers. Their complete hardware reads, the reset transfer and other input-message consumers remain open; the current input model does not claim those paths.

## Alternate input readers and full interface update [V]

`tools/boot_input_interfaces.py` reconstructs all eight near readers in the two tables and the selection at `$A6B7-$A6FE`. Each reader has 96 all-WRAM comparisons outside caller scratch; A, `$4201` writes and restored DB/D/P are checked. 320 dispatcher cases cover every combination of flags 00/40/80/C0 and index 0/2/4/6/8. Another 160 full `$A6FF` calls run detection, indirect readers and all message callees, comparing WRAM outside caller scratch plus control-write order. Inputs are supplied register bytes rather than hardware timing.

| First-port entry | Second-port entry | Behaviour |
|---|---|---|
| A573 | A615 | Read automatic word 4218/421A and clear word **00:0094** |
| A5A4 | A646 | Read automatic word 421C/421E OR the caller-bank word at 0094 |
| A5B2 | A654 | Select with 4201=BF/7F, read 16 bytes from 4016/4017, shift bit 0 into returned word and bit 1 into cache **00:0094**, then restore 4201=FF |
| A603 | A6A5 | Return the caller-bank word at 0094 |

The cache bank distinction is literal: the first/serial readers select DB=00 for the cache store and restore the caller DB; the other two retain their caller bank for the cache load. Thus with the input updater's DB=7F they read **7F:0094**, independently of the stores to 00:0094. Tests randomize both locations and compare all WRAM, retaining that behaviour rather than assuming they alias.

The automatic first entries also zero a word at their temporary direct-page +4 that overlaps the saved P byte. Their final PLP therefore restores zero (with N/Z subsequently set by PLD), including M/X=0; the tests check this. The outer `$A6B7` dispatcher has its own saved P and restores it afterward. The serial entries use a five-byte temporary area, so that same store does not overwrite saved P. Serial noise/high bits are randomized; only the two shifted low-bit lanes contribute to the words.

Flag 40 sends indices below 8 to the first table. For index 8 it subtracts 6, leaving index/A=2; the later BIT 80 tests this new A, not the earlier detection byte, so the final index reads standard 421A even when both interface flags are set. With flag 40 clear, nonzero indices and flag 80 select the second table at `(index-2)/2`; index zero stays the standard 4218 read. Without either applicable flag, indices 0/2 are standard reads and the remaining indices yield invalid marker 0001. All twenty selections are tested.

The returning full-update tests now cover all four detection flags. They exclude word 3030, which transfers to the reset vector; that transfer and controller-message consumers remain open. Reader tests exclude caller scratch 1FC0-1FFF; complete updater tests exclude 1F80-1FFF. Cache words and all task/state/message mutations remain compared.

The 3030 input reset transfer now has 96 original-routine comparisons, alternating its first/second controller position. Earlier-port state/messages are included in the full-bank comparison, while the reset-triggering state is left untouched. Execution stops at bank-00 PC equal to the original reset-vector word, before the reset body executes; S, DB and temporary D are also checked. This proves the transfer boundary, not a complete hot restart with live APU/hardware state.

## IRQ memory-copy queues [V]

`tools/boot_copy_queue.py` reconstructs `$C8C8-$C914` initialization, `$C915-$C939` allocation, `$C93A-$C959` release, `$C95A-$C984` one-shot append, `$C985-$C9E4` copy and `$C9E5-$CA40` execution. This IRQ queue invokes the CPU copy helper `$C44E`, rather than programming DMA. The remaining DMA/transfer workload is elsewhere.

Initialization reserves 256 bytes through the 128-byte-unit heap, stores pool base `02F6`, links 31 eight-byte free records at offsets 08-F8 and stores free head `02F8`. The persistent sentinel/tail are `02FA/02FC`; one-shot sentinel/tail are `02FE/0300`. Queue links are the first **byte**, interpreted as offsets from `02F6`; the free-list link is an absolute first word. Initialization still writes a low-memory pool/list when heap allocation returned zero, preserving the original absence of rollback. Allocation returns zero for an empty free head; otherwise it pops the record and writes word 007F at +3/+4 (length becomes zero). Appending ignores zero, writes the relative low-byte offset into the previous tail, clears only the new record's next byte and updates `0300`.

Copy records encode length at +4: zero means 256. Lengths 1-3 copy inline bytes +5 onward to the ordinary little-endian 24-bit destination at +1..+3. Larger lengths pass the pointer fields through the literal stack arguments to `$C44E`: the effective destination is `(record[2] << 16) | (record[1] << 8) | record[3]`, and source similarly uses bytes 6/5/7. This is the measured call-stack interpretation, not an assumed common pointer layout. Queue payload producers still need auditing against it.

`$C44E` uses long-address word loads/stores below length 17 and a generated forward-MVN kernel from length 17 upward. The direct path can carry across a bank boundary, whereas MVN wraps each 16-bit source/destination offset within its own bank. Word copies read both bytes before writing them; MVN overlap propagates byte by byte. The small **odd** path first loads/copies a byte, then decrements and shifts the now-replaced accumulator to obtain its word count: the first source byte, rather than the requested odd length, controls the remainder. For example, an odd request whose first source byte is 9 copies one byte plus four words. Source byte 1 exits after one byte. Bytes 0/2 produce large/zero-counter loops and are outside this validation's valid test domain. The model retains this literal behaviour. The helper/queue instruction bytes were also compared with the post-`AD75` image and are unchanged there.

Queue execution traverses persistent then one-shot records. Persistent records stay linked. Each one-shot record is copied and then prepended to the absolute free list; its next offset is saved before its first word is overwritten. At the end, one-shot header word becomes zero and tail becomes 02FE. Release ignores zero only: FFFF is treated as a pointer, and its high link byte is written through the `80:0000` mirror into `7E:0000`; that boundary effect is checked, unlike the earlier generic message-pool sentinel rules.

The six models pass 1,280 original-routine comparisons: initialization 160, allocation 240, append 240, individual copy 240, release 240 and full queue execution 160. They cover empty/populated queues, partial heap failure, 1/2/3/4/5/6/7/15/16/17/255/encoded-256 lengths, selected odd-path first bytes 1/3/9/17, ROM/RAM sources, forward overlap and bank-boundary differences. Copies/queue execution/release compare all WRAM except caller scratch 1F80-1FFF; pool operations compare the whole bank 7F and allocation X. No game helper is hooked and no original payload bytes are saved. Non-WRAM destinations and the extreme odd-counter cases remain outside the current model validation.

## DMA programming and processed-descriptor cleanup [V]

`tools/boot_dma.py` reconstructs `$91B8-$92E8`, `$9066-$90D9` and `$92E9-$934E`. Pending descriptor-pointer vector is at the address in `0066`; `006C` is total pending count and `006E` is the count submitted for this pass, later replaced with the count eligible for cleanup. A descriptor's first seven bytes are channel-0 DMA registers 4300-4306: mode, B-bus target, source offset, source bank and byte count. Byte +9 supplies VMAIN (2115); low three bits of +0F select destination setup: 1 writes VRAM address 2116/2117, 2 writes CGRAM index 2121, 3 writes WRAM address bytes 2181-2183, and other values write OAM address 2102/2103.

An empty `006E` performs no programming. Otherwise HDMA is temporarily disabled through 420C=0. A caller A word supplies limit `(0106 - A) & FFFF`. Before each descriptor, the PPU counter is latched/read and converted to `(vertical & 1FF) << 7`. After adding the byte count with 16-bit wrap and shifting right seven, a value at least the limit ends the pass before that descriptor. This captures the original count-based time estimate, not measured DMA duration.

A fitting descriptor writes 420B=0, channel registers and PPU destination setup, then starts channel 0 through 420B=1. If the next blank read is clear or channel count remains nonzero, the routine clears 4305/4306 and stores the number of **earlier** descriptors in `006E`: the descriptor just attempted remains pending. The same earlier-count calculation is used on budget failure before a transfer. On a completed full pass, a final clear blank read with flag `0010` zero decrements only the low byte of `006E` and writes 420B=0, likewise retaining the last descriptor. Otherwise the original count is retained. Before restoring HDMA enable from byte `0070`, the pass calls `$90DA` with pointer `007A`; null pointers do nothing. The callback is reconstructed below.

Descriptor release ignores X=0. Reference byte +0D in 1-32 indexes the table at `0068`; its count decrements with byte wrap, then results 0/1 are cleared to zero. Thus original 1/2 become zero, original zero becomes FF. Exact flag byte +0F equal to 05 clears its mask +9 from shadow `0070` and clears byte `0072 + highest-set-bit-index`; mask zero uses index 7 from the helper's FF result. Mask 1 also clears word `007A`. Other flags, including 0D, do not perform that HDMA cleanup. Every nonzero descriptor has byte +0F cleared at the end.

Processed cleanup uses each of the first `006E` vector entries. Flag bit 08 frees the aligned bank-7F workspace offset at descriptor +2 through the checked heap release, then `$9066` releases the descriptor. The remaining pointers move to the beginning with the original `$C3BF` helper; `006C` decreases and `006E` clears. Source index uses the original eight-bit mask on twice the processed count. The model/test domain is at most twenty descriptors, so that mask does not truncate a valid pointer index.

320 programming comparisons check the full bank and exact ordered DMA/PPU/HDMA-enable writes. They cover empty lists, cutoff/continuation, all eight destination selectors, wrapped limits, varied vertical counters, flag `0010`, and complete/partial DMA results. The harness provides controlled counter/blank reads and specified completion/residual counts for channel-0 incrementing modes 0-7; no game routine is hooked. It does not render or independently validate DMA destination bytes/timing, the scanline effects of HDMA or zero-byte-count 64-KiB transfer.

240 release cases and 160 vector-cleanup cases check the entire bank with every original heap/bit-index/copy helper executing. They include reference bounds/counts, zero/varied HDMA masks, exact versus combined flags, prefix lengths 0-20, workspace release and pointer compaction. All original RAM images are supplied privately from the ROM; no transfer payload bytes are saved. Further work includes descriptor producers, full hardware transfer effects and active IRQ composition.

## Transfer submission, HDMA callback and pass preparation [V]

`$90DA-$9163` ignores X=0. A descriptor whose flag byte +0F is not exactly 05 is marked with bit 80 and appended to the pointer vector at `word(0066) + 2 * word(006C)`. Only the low byte of `006C` increments; its high byte survives even when the low byte wraps. No capacity or duplicate check is added.

Exact flag 05 instead programs an HDMA channel selected by the highest set bit of descriptor mask +9. It writes four words, in order, to channel offsets 0, 1, 4 and 2 from descriptor offsets 0, 1, 4 and 2. The first two stores overlap; their redundant byte writes remain in the model and checked trace. The mask is ORed into shadow `0070`; exact mask 01 also stores the descriptor pointer word in `007A`. Multiple-bit masks select their highest channel while setting all those shadow bits. Zero-mask programming is outside the validated domain. There are 240 full-bank and ordered-register comparisons covering null, ordinary queued and HDMA descriptors, mask variants and pending-count low-byte overflow. The 320 DMA-pass cases now also include nonzero HDMA callbacks.

`$9193-$91A1` copies only byte `006C` to `006E`, retaining `006F`; 240 randomized whole-bank comparisons check that distinction. `$9164-$9192` does nothing to transfer state when word `0064` is zero or the low pending-count byte is zero. Otherwise flag `0010` zero stages that low count; a nonzero flag calls `$91A2-$91B7`, which copies the full count word, programs a pass with A=0107, then reclaims processed entries. The wrapped limit FFFF makes this immediate pass independent of the usual vertical-budget cutoff within the checked input range. The temporary byte increment/decrement of `008E` leaves its final value unchanged.

160 full-bank and ordered-write comparisons execute this preparation entry and every original DMA, cleanup and copy callee. They cover enabled/disabled transfer state, empty lists, deferred/immediate selection and 0-8 valid descriptors with controlled completion and blank reads. This is a memory/register model, not a complete processor-register ABI or hardware timing model. Combined with the earlier transfer checks, `boot_dma.py` now passes 1,360 comparisons.

## Transfer descriptor allocation and exhaustion retry [V]

`$8FC7-$9065` scans exactly 32 sixteen-byte records from pointer `0064`, choosing the first whose flag byte +0F is zero. Argument A is a word: its low byte is the flag and its high byte the reference index written to +0D. References 1-32 increment a byte at `word(0068) + reference - 1`, with byte wrap. Other references leave that table untouched. The selector `((flag & 7) - 1) & FF` indexes three recovered-image tables at 5EB4, 5EB9 and 5EBE to write descriptor mode +0, VMAIN/mask +9 and B-bus target +1. Values outside normal selectors 1-5 still perform the literal adjacent-image lookup; the model does not silently clamp them. Source/count/destination fields and other bytes remain unchanged.

Only exact flag 05 invokes `$8F8F-$8FC6`. This scans ownership bytes `0072-0079` from channel 7 down to channel 0, selecting the highest free byte. It stores the current task id (task +4 reached through `009E`, or 1 when no current task), then stores the selected single-bit mask at descriptor +9. A zero task id literally stores zero, leaving ownership apparently free. When all channels are occupied, it clears descriptor +0F and returns X=0; the already incremented reference remains incremented, with no rollback.

A full descriptor pool returns X=0 immediately only when the argument's **reference/high byte is FF**. Otherwise it calls transfer preparation `$9164`, then the original one-tick receive `$ABE7` and retries the entire scan. This condition tests the saved argument high byte, not the flag byte. The readable allocator reports `None` for that initial blocking state; its complete tested retry is composed with the existing preparation, task-selection, timer, queue and receive models.

240 reservation comparisons check all-bank effects and X, including highest-free choices and no-free-channel failure. 320 allocation comparisons check first-free selection, untouched fields, reference bounds and byte overflow, selector lookups, exact/combined flags, HDMA failure and immediate pool-exhaustion failure. Another 96 complete retry cases begin with all 32 descriptors occupied and one pending transfer. The original preparation frees that entry; the original receive suspends the caller, creates/runs the fallback, expires its timer, wakes/resumes the caller and retries allocation. The harness calls the real timer scanner from the fallback with controlled PPU reads; no game routine is skipped. All bank-7F mutations, ordered hardware writes, returned X, stack restoration and one service tick agree with the composed model.

These cases use valid pool/table addresses and returning one-tick retries with an immediately reclaimable descriptor. Repeated waits without reclaimable work, malformed/wrapping pool addresses, physical interrupt scheduling and transfer rendering remain open. The transfer tool now passes 2,016 original-routine comparisons in total. All image/table bytes are read privately from the supplied ROM.

## Real configuration tables and OAM/VRAM producers [V]

The transfer and PPU-queue harnesses now load both the executable block C77C00 -> 7E8000 and the configuration block C7B480 -> 7E5000. Their earlier isolated tests left the low configuration area zero, so they exercised table-addressing semantics but not the real classification values. All existing 2,016 transfer and 720 PPU-queue comparisons were repeated successfully with the real block. The PPU cases now execute classes 0, 1 and even mirror offsets 40-5E, including high-byte stores that the earlier zero table did not reach. New traces replace the earlier evidence; the case counts are not added twice. Initialization-based retry tests already executed the real AD75 load.

`$B804-$B83F`, the first active-IRQ workload call, queues the OAM shadow whose bank-7F source offset is word `02CC`. A zero pointer skips it. Otherwise argument FF04 allocates the first free descriptor or returns immediately on exhaustion. With the real kind-4 tables its channel mode is 0, B-bus target 04 (2104), and VMAIN is 0. It sets source bank 7F, source offset from `02CC`, byte count 0220 (544), and OAM address word +0A to zero, then submits the descriptor. Submission changes flag 04 to 84 and appends its pointer; no source payload is copied by this producer itself. 320 full-bank comparisons cover disabled source, first-free slots, exhaustion and count low-byte overflow. Another 160 composed cases execute this producer followed by immediate preparation/programming/cleanup, comparing the entire bank and ordered register writes with controlled transfer completion.

`$C73B-$C76C` searches four eight-byte VRAM buffer registrations from pointer `02F4` for the first source word at +2 equal to X; it returns that record or zero. `$C870-$C8C7` uses that record's byte +0 as a VRAM page (`byte << 10`, wrapped to 16 bits), and byte +1 as the transfer size in 256-byte units. It allocates kind 1/reference 0, sets source offset to the caller's X, source bank 7F, size word +5 and VRAM destination word +0A, then submits. With real tables this is mode 1, B-bus target 18 and VMAIN 80. An absent registration is not checked: it reads bank-7F bytes 0000/0001 as the page/size and still queues the source. The model preserves this original fallthrough.

320 lookup comparisons check first matches, duplicates, missing entries, returned X and unchanged bank. 320 producer comparisons cover those cases, arbitrary page/size bytes and pending-count byte wrap, with an available descriptor. Zero size is checked as descriptor data here, not as a completed 64-KiB DMA operation. Pool-exhaustion waits for this producer, malformed/wrapping registration addresses and full hardware destination effects remain open. The transfer tool now has 3,136 passing comparisons, of which 1,120 are new producer/lookup/composition cases. No transfer or decompressed-image payload bytes are saved.

## VRAM page ownership and registered-buffer lifecycle [V]

`tools/boot_vram.py` reconstructs allocation `$D5F3-$D677`, release `$D678-$D6B2`, registration selection `$C710-$C73A`, creation `$C76D-$C825` and table/buffer cleanup `$C6CB-$C70F`. The bitmap pointer is word `032C`; each byte describes a 2-KiB VRAM page. Allocation argument low byte is the number of pages. Its high byte is a packed tag whose high nibble supplies the candidate stride. The number of candidates starts at 32 and halves for each trailing zero in that nibble. Candidate starts advance by the original stride; the requested consecutive bytes must all be zero before the tag is written to them. The return's low byte is the chosen offset from the bitmap base, or FF on exhaustion. No task-id owner substitution is made. The unused returned high A byte is outside this memory/low-result model.

320 allocation cases cover strides 1/2/4/8, varied tag low nibbles, lengths 1/2/4/8, fragmentation and empty/full candidates. Zero stride would loop indefinitely in the original; zero length invokes a 256-byte counter loop and is not part of the checked allocation domain. Release takes a low-byte page offset, reads its tag, then clears **every** matching byte among the first 32 bitmap bytes, rather than freeing a suffix or only a contiguous span. 320 full-bank release comparisons include shared and zero tags.

`$C710` selects one of four eight-byte registrations at `word(02F4) + 8 * ((argument >> 2) & 3)` with 16-bit wrap. It uses the original multiply registers; 320 cases check unchanged bank and full A. Creation uses low argument bits 0-1 for byte sizes 0800/1000/1000/2000. It allocates and zero-fills bank-7F RAM, stores source word +2, clears words +4/+6 and stores size/256 at +1. It then allocates `size/2048` VRAM pages with tag `argument & FC`, storing the returned page byte at +0. This page byte agrees with the transfer producer's word-address shift by ten: one VRAM word-address page contains 2048 bytes.

Creation forms `((page << 2) | kind) & FF` for the selected BG register 07-0A. It queues that byte and two zero words for the matching horizontal/vertical scroll registers 0D-14. `$C030-$C076` pops a PPU record, writes its register word (clearing next byte), and seeds its value word from the shadow: class 0/1 uses the register offset; other classes use their dedicated mirror offset. `$C097-$C0C1` appends a nonzero record to the one-shot byte-offset queue; zero is ignored. These two new helpers pass 240 original-routine comparisons each, including empty free head, all 52 supported registers and sentinel/record tails. Total PPU-queue comparisons are now 1,200.

160 full creation calls execute every original heap, multiply, page and PPU queue helper, checking the whole bank and returned buffer X. They include independent and combined RAM/VRAM reservation failures. Failed RAM allocation still zero-fills from offset zero and clears low bookkeeping; failed VRAM allocation still stores page FF and derives wrapped BG settings. Empty PPU allocations are not checked by the caller before it stores the value at node +2. The model retains those effects. Successful inputs reserve low RAM for bookkeeping and keep the registration table, bitmap, PPU records and shadow outside allocated buffers.

Cleanup skips a null registration-table pointer. It walks four records, freeing nonzero RAM source words through `$B0D6` and freeing pages through `$D678` only when the record's **page byte is nonzero**. Thus page zero takes no page-release call. It finally frees the RAM unit containing the table but does not clear pointer `02F4` or the record bytes. 160 full-bank comparisons execute the original heap/page callees for null/populated tables and mixed buffer/page values. The VRAM tool passes 1,280 comparisons total; the two new PPU helpers add 480 more. Malformed/wrapping tables, unsupported stride/count combinations, repeated allocation policies and physical PPU rendering remain open.

## Palette slots, colour copies and transfer producers [V]

`tools/boot_palette.py` reconstructs `$BBAB-$BBE6` allocation, `$BBE7-$BBFD` release, `$BC9A-$BCE8` colour copy, `$BBFE-$BC42` palette upload preparation and `$BC43-$BC99` reverse-read preparation. The palette RAM base is word `02D2`. Allocation starts at low argument nibble times 32 bytes from that base, then scans exactly eight slots. First-colour word bit 8000 means free; selection clears only that first word and returns X. Exhaustion returns zero. It does not clamp the eight-slot scan to a presumed sixteen-palette region. Release writes word 8000 to X, including X=0, and leaves other colours untouched.

240 allocation comparisons cover first-free selection, occupied scans, all requested starting indices and random lower colour bits. 240 release cases check the entire bank, including the original zero-pointer write. No unused palette payload bytes are saved.

Colour copy takes its source bank from the high A byte and source offset from Y. Low A bits 0-3 encode a colour count minus one (1-16 word copies); bits 4-7 select the destination starting colour. It reads each complete source word before writing, then advances both offsets by two. Copies are forward, so an overlapping source can incorporate earlier writes. The source uses long addressing and can carry across a bank boundary. No palette-size clamp is added when start plus count exceeds sixteen. 320 original calls check all WRAM outside caller scratch 1F80-1FFF, covering ROM and both RAM banks, all encoded counts/offsets, forward overlap and a ROM-bank crossing. Destination pointer wrapping and other source banks remain outside this test domain.

Upload preparation allocates kind 2/reference 0, writes source bank 7F, source offset X, byte count 0020 and CGRAM index byte `((((X - word(02D2)) & FFFF) >> 1) & FF)`. With the real configuration, this is channel mode 0 and B-bus target 22 (2122); submission marks flag 02 as 82 and appends the descriptor. The returned low A byte is CGRAM index >> 4, identifying the 16-colour palette group. It retains literal subtract/shift/truncation for odd or out-of-range source offsets.

Reverse preparation starts with the same kind/count/index, then overrides channel mode to 80 and B-bus target to 3B (213B), preparing a PPU-to-CPU CGRAM read into bank-7F RAM. After submission it clears the first source word immediately. The producer comparison establishes this descriptor and RAM change, not the later hardware read contents or timing. Each direction passes 320 full-bank comparisons with returned low A, varied pointer/index arithmetic and pending-count low-byte wrap.

Another 160 composed cases execute allocation, colour copying and upload preparation consecutively, checking the full bank, selected pointer and returned group index. All original callees execute; the transfer descriptor pool has space in these producer tests. The palette tool passes 1,600 cases total. Pool-exhaustion waits, complete physical CGRAM transfer effects and further palette consumers remain open.

## Graphics registration, base settings and full scene preparation [V]

`tools/boot_graphics.py` reconstructs `$805F-$809A`, `$809B-$81A9` and the complete `$BA7F-$BB66` producer. Graphics registrations are eight-byte records at pointer word `0016`. The slot helper selects `((flags >> 2) | (flags >> 4)) & 7`, multiplies by eight using the original hardware registers and adds the table base. 320 randomized comparisons check the entire bank and returned A, including all byte flag values. The helper retains the caller's data bank; the test uses DB=7F as its creation caller does.

Creation reserves and zero-fills a RAM workspace of the requested X byte size, storing its pointer at both registration +4 and +6. Field +2 receives low flag bits 0-1 (`kind`). For checked kinds 1-3, the VRAM page count is `(((size << (kind - 1)) + 127) & FF80) >> 7`, with 16-bit wrapping before rounding. Its low byte is stored at +1 and passed to the existing page allocator, with packed tag `flags & FC` as the high byte. The returned page byte is stored at +0. Workspace byte size and page count have distinct roles; they are not substituted for one another.

A one-shot PPU entry changes the graphics base setting from the old shadow value. Family 40 updates register 0B with `(old & F0) | (page >> 2)`; family 44 uses `(old & 0F) | ((page >> 2) << 4)`. Families 48 and 4C do the same to register 0C. Family 80 instead updates register 01 with `(old & F8) | (page >> 3)`. The literal ORs are retained even on failed page FF; no extra masking or rollback is introduced. Other families use the original default register-0C high-nibble branch but are outside creation validation. The function returns the wrapped VRAM word address `(page << 10) & FFFF` in both A and X.

240 complete creation comparisons cover each checked family, kinds 1-3, workspace sizes 64/128/256/512, independent RAM/VRAM failures, untouched fields and PPU free/shadow/list effects. Every original allocation, fill, multiply and PPU helper executes. RAM failure retains its low-memory fill effects. Kind zero, zero page counts and malformed table/heap layouts remain open.

`$BA7F` composes these resources into a complete scene workload. It creates graphics registration 49 with workspace 0200, then queues two 4096-byte kind-1 transfers from 7E:2000 and 7E:3000 to the returned VRAM word address and address+0800. It allocates a palette from requested slot zero, copies three colours from 7E:5150 into starting colour one (argument 7E12), and queues the palette upload. The returned palette group sets the attribute word used below.

It creates background registration 19 and its 4096-byte RAM map. Fourteen pairs of half-rows each contain sixteen incrementing tile words; the second half uses XOR 0100. The remaining 0640 words become 210F, filling the rest of the 4096-byte buffer. It queues that buffer through `$C870`, then appends scroll register 12=FFC8 and register 11=0000. 96 complete calls start from real AD75 resource initialization, vary prior VRAM-page and palette occupancy, and include exhausted eight-slot palette scans. They compare every bank-7F byte against the composed model with all game callees executing; no rendered graphics or transfer payloads are claimed. The graphics tool has 656 passing comparisons.

The palette producer `$BD09-$BD4E` is also reconstructed: it computes the target CGRAM index/group from the caller's palette pointer but supplies the constant 32-byte source at 7E:BCE9, rather than copying that RAM palette. It leaves the target palette untouched and queues kind 2. A further 320 full-bank/returned-low-A comparisons cover pointer arithmetic and pending-count wrap. The palette tool now has 1,920 passing comparisons. Constant source payload bytes are read privately from the supplied boot program and are not saved.

## Graphics workspace blocks and release [V]

`$81AA-$81D5` selects a graphics registration from the packed flags, saves workspace +6 and page +0, then clears **word** +6 and **word** +0 (the page and count bytes). It frees the RAM workspace through `$B0D6` and calls `$D678` with the saved page, including page zero. It leaves kind +2/+3 and current pointer +4/+5 intact. Unlike the background-table cleanup `$C6CB`, it does not skip a zero page. 240 whole-bank comparisons cover null/populated workspaces, page zero and shared page tags, executing both original resource callees.

`$81D6-$8276` allocates one graphics block by scanning the byte workspace cyclically. Base is registration +6, current scan pointer +4, and span is `(count_byte << 8) >> kind_byte` for checked kinds 1-3. It tests the current byte first, increments over occupied bytes, wraps at the end, and returns X=FFFF after a full occupied cycle. On success it writes the current task id (default 1 without a current task) into the free byte and leaves the registration cursor on that selected byte. A zero task id literally writes zero; no invented nonzero owner is substituted.

The returned VRAM word address adds a scaled workspace index to the registration page. It initially multiplies the index by 32. Its format comparisons read the **full word at +2**, rather than masking the stored kind byte: word 3 keeps factor 32, word 2 uses 16, and any other word uses 8. Thus a nonzero adjacent byte +3 changes the result even when +2 says kind 2/3; randomized cases retain this original behaviour. The page conversion also follows the literal word shifts/XBA, without silently replacing them with the creation helper's byte-shift sequence. Validation uses page bytes 1-20. 320 whole-bank/returned-X comparisons cover cyclic selection, wraps, exhaustion, root/current/zero task ids and zero/nonzero adjacent kind bytes.

`$D6B3-$D6D2` maps a VRAM address to bitmap index `(address & FC00) >> 10` and returns the **word** at bitmap base plus that index. The tag's low byte supplies the flags used by release `$8277-$82D3` to select a registration. Release masks its kind word with 3, computes the block's workspace offset from the VRAM-address difference with factors 8/16/32, stores that byte address as the new cursor at +4, and clears its owner byte. The tag word's high byte is not a second registration selector. 320 tag-lookup cases check whole-bank preservation and full A; 320 block-release cases check the whole bank and returned workspace X, including random adjacent kind bytes.

160 further composed calls allocate then release the sole free byte in a cyclic workspace, with canonical zero adjacent-kind bytes. They check both returned addresses, the cleared owner, cursor and all other bank memory through the original routines. This proves their normal mapping relationship independently of the noncanonical full-word comparison cases. The graphics tool now passes 2,016 comparisons in total; this continuation adds 1,360. Invalid/wrapping workspaces, kind zero, inconsistent page tags and full processor-register ABI remain open.

## Individual graphics-block submission and auxiliary buffers [V]

`$82D4-$833D` queues one graphics block. Caller X is the VRAM destination word address, Y the source offset, and low A the source bank. High A is a boolean cleanup policy: zero allocates kind 1, any nonzero value allocates kind 9 (kind 1 plus source-release bit 08). Both use reference index zero. The producer resolves the destination's page tag through `$D6B3`, selects the graphics registration through `$805F`, and computes byte count `(8 << (word(registration + 2) & 0F)) & FFFF`. Unlike the block allocator's full-word comparisons, this power helper ignores all but the low nibble. Normal kinds 1/2/3 yield 16/32/64 bytes. It writes destination +0A, source +2, source bank +4 and count +5, then submits the descriptor as flag 81 or 89.

320 whole-bank comparisons cover format nibble 0-15 with random adjacent high bytes, varied source banks/offsets, high policy bytes 00/01/80/FF and pending-count wrap. Nibbles 13-15 wrap the count to zero; these cases verify descriptor data only, not a 64-KiB hardware operation. The descriptor pool has an available entry. Another 160 calls allocate a graphics block through `$81D6` and then submit it through `$82D4`, comparing the complete bank, allocated destination and 16/32/64-byte descriptor. Pool-exhaustion waits and actual source-to-VRAM transfer effects remain open.

160 further cases submit a block and run original processed-descriptor cleanup after supplying a completed-count boundary of one. This does not invent a DMA completion result or claim a transfer ran: it checks the cleanup policy at that explicit phase boundary. Flag 89 frees the aligned bank-7F source allocation, flag 81 retains it, and both clear the descriptor and compact/reset the pending vector. Every original heap/descriptor/copy callee executes. Cleanup uses the bank-7F source offset even though descriptor source-bank programming is independently supplied by the caller.

`$833E-$8362` allocates zero-filled auxiliary buffers of 0034 (52) and 0400 (1024) bytes, storing their offsets in words `0018` and `001A`. These buffer names describe the reconstructed allocation phase; their remaining consumers still require auditing. 200 whole-bank comparisons cover both successful reservations, failure of both and failure after the first succeeds. There is no rollback: a failed second reservation still zero-fills from offset zero, which can erase the first saved pointer and low heap/resource bookkeeping. This behaviour is retained through the original heap/fill helpers.

`$8363-$837D` frees the offsets currently stored at `0018` and `001A`, in that order, without clearing either pointer. 200 full-bank cases execute both original heap releases, including zero pointers, shared allocation pointers and distinct allocations. The graphics tool now passes 3,056 cases total; this continuation adds 1,040. Invalid pointers/bitmap layouts and complete caller-register behaviour remain outside these memory models.

## Bit-tree deltas and colour-cube construction [V]

`tools/boot_colour.py` reconstructs ten original routines linking the auxiliary buffers to component samples and colour lookup construction. Their names describe the recovered operations; the original compressed-tree/stream producers remain open. No tree, stream or colour payload bytes are saved.

`$A14E-$A1A6` traverses a binary word-pointer tree rooted at bank-7F word `008A`. Each branch contains two child pointers. At a child, a first word with a nonzero high byte means another branch; a zero high byte means an eight-bit leaf value. Decoder state is an eight-byte record: source offset word +0, source bank byte +2, unused adjacent byte +3, shifted bits word +4, remaining-bit byte +6 and cached symbol/repetition byte +7. When +6 is zero, the routine adds 16 to **word** +6, reads two source bytes, swaps their order into the shift word and increments the 16-bit source offset by two without carrying to the source bank. Each branch decrements word +6 and shifts +4 left; carry chooses the second pointer. The source offset is stored back when a leaf is reached. Consumption is MSB-first, first source byte then second.

`$A1A7-$A1E1` turns these leaves into signed deltas or zero runs. Cached bit 80 set yields zero and decrements that cache byte without decoding. Otherwise it decodes and caches a leaf: 80-FF begins a zero run of 1-128 calls including the current call; 40-7F becomes signed -64 through -1; 00-3F becomes 0-63. The cached high byte shares the decoder's word counter storage; the model preserves both byte/word operations rather than treating the state as independent counters. Each entry passes 240 whole-bank/result comparisons with generated valid depth-three trees, boundary leaf values, selected ROM/RAM sources and randomized refill/cache state. These prove the decoder operations for those inputs, not that every real ROM stream has been located.

`$837E-$83AC` emits a cumulative byte ramp at four-byte spacing, starting from zero and wrapping each signed addition. Count zero means 256 iterations. `$83AD-$83E1` invokes it three times on the same advancing decoder, emitting 232 samples into lanes 0, 1 and 2 of the buffer at `001A`. Each lane starts its own running sum at zero; the fourth byte of each record remains untouched. The resulting used sample area is 928 of the allocated 1024 bytes. Each entry has 96 full-bank comparisons, with every original decoder callee executing and no game hooks.

`$83E2-$8410` packs an index `((r & 1E) >> 1) | ((g & 1E) << 3) | ((b & 1E) << 7)`: a 16-by-16-by-16 cube using the upper four bits of each five-bit component. `$8411-$8443` packs `(r & 1F) | ((g & 1F) << 5) | ((b & 1F) << 10)` into a fifteen-bit colour word. 320 cases each randomize whole input bytes, check returned X and verify that the bank is unchanged; overlapping original word loads still give these masked component formulas.

`$8444-$84AD` adds a three-byte offset to each of the 232 samples with byte wrap. It rejects the candidate as soon as any summed component has bits E0 set, preserving partial writes to the first scratch triple at pointer `0018`. Valid triples produce the cube index above. A zero cell at `7F:8000 + index` is marked with sample position+15; occupied cells are retained. Returned A counts new cells. `$84AE-$84EA` tests whether a triple differs from all earlier four-byte records, comparing only their first three bytes; it returns low A=0 for a match and 1 otherwise. Each entry has 160 whole-bank/result comparisons, covering valid/invalid sums, empty/occupied lookup cells, duplicate triples and empty earlier ranges.

`$84EB-$8576` tries all eight sign combinations of an offset triple with modular two's-complement negation. It writes candidate offset records starting at scratch+4, skips triples already stored there, and runs the marking routine for each distinct offset, advancing the record cursor only for distinct triples. `$8577-$8606` stores three cyclic permutations at scratch+24 onward. It runs the first reflection group, tests the second permutation for equality with the first, and only if distinct runs the second and third groups; the third is not separately deduplicated. Each complete entry passes 48 whole-bank/returned-count comparisons with zero/equal/distinct component offsets, high-byte values and varied prior lookup occupancy. All original marking, deduplication and conversion callees execute.

The observed scratch layout explains the 52-byte `0018` allocation: one working triple, up to eight reflected four-byte records at +04-23, and cyclic-permutation records at +24/+28/+2C. The fourth bytes and unused tail are retained. The colour tool has 1,728 passing cases total. Tree construction, actual compressed-stream/catalogue provenance, callers of the completed lookup and malformed/wrapping pointer state remain open. The lookup samples and generated trees are synthetic validation inputs; the report contains counts/addresses only.


## Colour-tree construction and real ROM stream [V]

`$A061-$A07A` reserves and zero-fills 0600 bytes through the original heap helper, saving the pointer at `008A`. `$A07B-$A08F` releases that allocation without clearing the pointer. `$A12E-$A14D` initializes an eight-byte decoder record with the supplied source word and bank byte, clears words +4/+6 and retains byte +3. Each reconstructed entry passes 240 full-bank comparisons, including allocation failure and retained-pointer effects.

`$A090-$A12D` builds the tree from a two-byte header whose high byte is the branch count n. The low header byte is retained but its meaning remains unresolved. It reads two encoded child bytes per branch. At node `root + 4*i`, each child byte b first maps to `node + 4*(b+1)`. Addresses at or above the fixed leaf table `root + 03FC` are converted to `leaf_base + (address-leaf_base)/2`. Finally it writes n+1 leaf bytes as words at that fixed table. Serialized size is `3*(n+1)`, including the header. The final word read has an unused lookahead byte, excluded from the asset extent. Zero branch count would execute a 65,536-iteration original loop and is outside the checked model domain. 240 construction cases and 96 composed depth-1-to-8 tree/decoder cases agree with original execution.

The caller at `$968D` supplies the real tree at `D2:E536` and initializes the stream immediately after it at `D2:E6BC`. This tree has 129 branches, 130 leaves and 390 serialized bytes. Eight composed checks vary heap placement and execute original tree allocation, staging allocation, tree construction, decoder initialization and all three component lanes. The entire bank 7F agrees with the readable composition after 232 samples per lane. The remaining setup and complete caller/task lifecycle are not yet reconstructed.

Those samples cause 352 source bytes to be fetched, ending with the decoder refill cursor at `D2:E81C`, 15 buffered bits and cached symbol 80. Only 351 bytes contribute consumed bits: the last fetched byte is wholly unused. The catalogue therefore adds the 390-byte tree and the 351-byte verified stream prefix ending exclusively at `D2:E81B`, a total of 741 new ROM bytes. This boundary describes the checked prefix, not a proven end of the complete compressed asset. No tree, stream or colour payload bytes are saved. The colour tool now passes 2,792 cases; remaining work includes the header low-byte meaning, further stream consumers, lookup callers and malformed pointer states.


## Initial colour lookup, packed sample upload and nearest-sample fallback [V]

`$8607-$8620` clears all 32,768 bytes at `7F:8000-FFFF`, not only the 4096-cell lookup. The bank is selected internally and the caller's bank register is restored. `$8621-$8685` then reads eight overlapping four-byte words at three-byte intervals from the real configuration area `7E:59E0`. It copies each into scratch+30 and invokes the complete cyclic-permutation/reflection/marking group. Each result accumulates with word wrap; a total at least 8000 returns that total, otherwise finishing all eight groups returns zero. Only the first three copied bytes form the offset triple; the fourth scratch byte is also overwritten. This consumer makes use of the previously unexplained final four bytes of the 52-byte scratch allocation.

`$8686-$86F0` reserves 0200 zero-filled RAM bytes, saving the offset at word `001C`. It packs all 232 component triples from `001A` into consecutive fifteen-bit colour words. It allocates descriptor flag 0A (CGRAM kind 2 with source-release policy), sets bank 7F, the saved source pointer, length 01D0 (464 bytes) and starting CGRAM index 0F, then submits as flag 8A. These colours occupy indices 15-246. The model checks descriptor preparation and RAM effects, not hardware CGRAM payload or timing. Descriptor availability is required; exhausted-pool wait and allocation-failure aliasing remain open for this entry.

`$86F1-$87C8` searches the 232 sample triples for the first distance strictly below the current best, then stores its palette index at `7F:8000 + X`. Each component difference follows byte subtraction and modular negation; its square comes from the hardware multiplier. The three squares are summed with 16-bit wrap. Ties preserve the earlier sample. Initial selected marker F7 gives palette index zero if no candidate improves the initial threshold. Selection otherwise produces indices 15-246. This is the nearest-sample fallback for the lookup consumer at `$87C9`.

The initial threshold is **not necessarily 00FF**: the routine initializes only its low stack byte to FF, retaining the high byte from the caller's stack. The checked model therefore accepts that threshold explicitly. It returns the cached low palette byte; the processor's unused high A byte and complete register ABI are outside this model. Tests vary threshold high bytes 00/01/0F/FF, ordinary five-bit and arbitrary byte components, and existing cube contents. All comparisons retain the original word overflow and strict tie rule.

The four new entries pass 312 original-routine comparisons: 32 complete clears, 24 complete initializations with real configuration offsets, 96 palette packing/submission calls and 160 nearest-sample fallback calls. The colour tool now passes 3,104 cases total. The long initialization is allowed a five-million-instruction harness bound; the default bound for other boot calls remains one million. No game helper is bypassed. Full caller lifecycle, cache hit/miss composition and actual PPU payload remain open.


## Cached colour lookup and unfilled workspace initialization [V]

`$87C9-$87DE` takes a bank-7F component triple at caller X, converts it to a cube index through `$83E2` and reads `7F:8000 + index`. A nonzero cell returns immediately. A zero cell invokes the full `$86F1` nearest-sample fallback using the original triple and that cube index. The returned X is the cube index; the checked A result is its low palette byte. No validity check restricts cached nonzero bytes to the usual palette indices. If fallback produces zero, it writes zero and the next call performs the search again. The supplied fallback threshold includes the high stack byte left at this call depth, just as for a direct fallback call. These comparisons use caller DB=7F; other-bank fallback addressing and the complete high-A ABI remain open.

`$87DF-$881F` sign-extends the low argument byte into word `0020` and its high byte into word `001E`. It stores caller X/Y in words `0024`/`0022`, clears **only bytes** `0026` and `0034`, and saves a raw 32-byte reservation pointer at word `0030`. The raw `$B081` allocator rounds to one 128-byte unit but does not fill it. Upper bytes `0027`/`0035` and the reserved payload are retained. Exhaustion stores a zero pointer; it does not zero low memory as the fill allocator would. The current task owns successful reservations, with root owner 1 if there is no current task. The caller's bank register is restored.

The static callers identify distinct roles: `$9558` invokes workspace initialization with zero signed offsets and dimensions 0100/00E0. `$9D1E` repeatedly consults the colour table for 64 component triples before packing their indices into tile bitplanes. The complete packing/transfer routine still needs reconstruction; only its observed calls and loop structure are recorded here.

Cache lookup passes 240 original calls and 160 repeated calls, checking the entire bank, low A and returned cube-index X. Workspace initialization passes 320 original calls with sign-boundary arguments, randomized dimensions, current/root/zero task owners, full-heap failures and varied caller DB. Allocator callees execute without hooks. Colour total is now 3,824 cases. No newly unpacked RAM bytes are added to the ROM percentage.


## Eight-bit colour tiles and temporary graphics submission [V]

`tools/boot_tiles.py` reconstructs the complete `$BF2A-$BF6D` producer. It reserves one raw 128-byte unit for a 64-byte tile, copies exactly 64 bytes from source bank low A/caller X, allocates graphics kind 43 through `$81D6`, and submits through `$82D4` with argument FF7F. The queued source is bank 7F with release policy set; descriptor size follows the selected registration kind, normally 64 bytes. Copying leaves the unused upper half of the raw allocation untouched. The full graphics workspace has no guard here: block-allocation result FFFF is still passed to the producer, retaining the original tag lookup and descriptor effects. Available RAM and transfer descriptors are required by this checked model; exhausted descriptor waits and heap-failure aliasing remain open.

`$9D1E-$9DB5` converts 64 four-byte-spaced component triples into palette indices, compacting them into the first 64 source bytes. It then destructively shifts those index bytes into an eight-bit planar tile beginning at source+C0. For row r and plane p, destination is `source+C0+2*r+16*(p//2)+(p&1)`; the first column contributes bit 7. All eight shifts leave the compact index bytes zero. Bytes +40 through +BF are retained. Every original lookup, nearest-search, copy, heap, graphics and descriptor callee executes in the comparisons.

Bank addressing matters: target components use the caller's DB, while fallback selects DB=7F before reading the sample pointer `001A` and sample records. The cube cache also always resides in bank 7F. A DB=7E caller therefore reads its target from 7E and compares it with 7F samples. The checked components are five-bit values; arbitrary-byte modular distance behaviour remains covered by the standalone fallback model, not this composition. The fallback high threshold byte is reused on the caller's stack and can retain the high byte of a preceding improved distance between pixel calls.

The final tile producer receives **source bank 00**, so tests use source offsets within its low WRAM mirror. Its pointer is also formed literally from the high byte of `source+4E` and low byte of `source+C0`; no carry from the latter byte is applied. For source offsets whose low byte crosses C0, that can point to a different page than the planar destination. The model preserves this original arithmetic rather than replacing it with a full-word addition. The caller output-bank cases 7E/7F also retain the independent bank-00 transfer read; a successful comparison establishes those effects, not a claim that every such input is used by the game or renders the intended tile.

The tile producer passes 240 complete original calls with varied source banks, caller DB, graphics-workspace fragmentation and complete block exhaustion. Conversion passes 96 complete calls covering cache hits/misses, retained threshold high bytes, two output banks and pointer-low-byte carry boundaries. Comparisons cover all WRAM outside caller stack scratch 1F80-1FFF and check DB restoration; no game routine is bypassed. Transfer descriptor programming is established, while physical DMA payload, IRQ timing and exhaustion waits remain open.

Two additional complete compositions use the actual D2E536 tree and D2E6BC stream at different heap placements. The model and original execute allocation, tree construction, decoder initialization, all 232 samples per channel, complete lookup initialization, palette packing/submission and a 64-pixel planar tile conversion/submission. A domain check confirms the real decoded components are below 32. The conversion input uses the first 64 decoded samples copied into the tested caller buffer; this is an explicit composition boundary, not a claim that the original task itself selects that exact tile. The entire checked WRAM agrees. Tile tool total is 338 cases; remaining open work includes complete scene/task callers and physical transfer/IRQ effects.


## Colour-scene resources, map templates and complete teardown [V]

`tools/boot_colour_scene.py` reconstructs `$BE5B-$BEDC` preparation. It creates graphics registration 43 with a 0180-byte owner workspace, then background registration 10 with an 0800-byte RAM map. The saved map pointer is word `02D4`. The first 0600 bytes form twelve pairs of 32-column rows, filled from bottom toward top. Each 2-by-2 tile group contains consecutive indices in top-left/bottom-left/bottom-right/top-right order. All 768 indices are generated. `$9763-$9792` copies the next 0100 bytes from the real `7E:50C0` configuration template into map+0600; the final 0100 bytes retain the allocation's zero fill. Preparation queues the registered map through `$C870`. The original heap, VRAM, PPU and descriptor helpers all execute.

`$C826-$C857` releases the first registered buffer whose source matches caller X. It clears the source word +2, frees that RAM allocation, saves then clears the page/count word +0, and releases every matching page tag through `$D678`, including page zero. Cursor words +4/+6 are retained. Unlike the four-buffer cleanup, it does not skip a zero page. The checked domain has a matching registration; absent-record low-memory effects remain open. `$BF10-$BF29` composes this release using saved pointer `02D4` with graphics registration 43 release. Neither the saved scene pointer nor pending transfer descriptors are cleared by this teardown.

`$991C-$994C` copies exactly 64 real configuration bytes `7E:5FCA-6009` into low WRAM `1D00-1D3F` through the bank-00 mirror and clears only the terminator byte `1D40`. Later bytes are retained. `$994D-$995B` saves/selects/restores the bank and has no persistent memory effect.

`$964B-$965F` composes complete resource setup: scene preparation, expanded-tree allocation, the 52/1024-byte staging reservations, and the low-WRAM template. `$9660-$9674` composes teardown in the opposite grouping: template release, both staging releases, tree release, then scene release. Pointer words `0018`, `001A`, `008A` and `02D4` are retained. Pending descriptor data still refers to its original sources, so this resource comparison does not establish that an earlier transfer has completed; complete task synchronization/physical DMA remain open.

The tool passes 1,120 original-routine comparisons: registered-buffer release (240), map-template copy (240), low-WRAM template copy/terminator (240), template-release bank restoration (16), scene setup/release (96 each), and complete colour resource setup/release (96 each). The whole WRAM outside caller stack scratch 1F80-1FFF and restored DB agree. Cases vary caller bank, record cursors, template tails, prior VRAM occupancy and complete VRAM exhaustion. Heap, descriptor and PPU record availability are required for composed setup; resource-failure aliasing outside the checked domain remains open. No decompressed configuration/map payload bytes are saved.


## Raw colour-task receives, parent identifiers and graphics replacement [V]

`tools/boot_colour_protocol.py` reconstructs parent lookup `$ACD0-$ACE8`, current-task id lookup `$ACE9-$AD01`, raw receive `$B2FB-$B311` and graphics replacement `$BEDD-$BF0F`. Parent lookup returns byte +5 of the current task, or root id 1 if there is no task. Current id uses +4 with the same root fallback. Only the returned low A byte is part of these models; caller DB is restored.

Raw receive repeatedly calls the original scheduler suspension until returned X is nonzero. It neither arms/disarms a timer nor filters FF-tagged records. For a preloaded record with no competing ready task, suspension/enqueue/selection/resumption consumes the pending queue head, replaces that record's link with the receiving task id and advances task +0A. The existing registration state/count is retained. Empty-queue tests create and run the original fallback task; the harness supplies a record at its A8C0 service boundary by calling original B258 delivery. That call wakes the waiting receiver. The fallback then performs its original yield, allowing the receiver to resume and return the delivered record. Supplied records include FF tags, which are returned unchanged. This explicit message boundary does not establish real interrupt or parent-task timing.

The colour task at `$968D` sends opcode words 2 and 4 to its parent at +3 of allocated records and performs raw receive after each send, releasing the received records afterwards. Consequently its waits do not themselves test an acknowledgement opcode or prove that DMA has finished. The intervening `$A009` image-generation body is now checked continuously in the section below; complete parent-task synchronization remains open.

Graphics replacement first releases registration 43, recreates it with a zero-filled 0300-byte workspace and invokes block allocation exactly the supplied positive word count times. It does not stop when block allocation returns FFFF. Zero count would run 65,536 iterations and is outside this checked composition. Tests cover positive counts 1-1024, including full 768-block workspace and further failed reservations. Prior occupied VRAM pages are retained while the old graphics pages are released; those cases independently force the larger reservation to fail. Heap and PPU records remain available in the checked domain.

Protocol total is 992 passing cases: parent/id lookup (240 each), preloaded raw receive (320), original fallback/delivery/resume (96) and graphics replacement (96). Comparisons cover the entire bank 7F and applicable returned id/X/S/DB; caller/fallback RAM stack bytes and physical scheduling remain outside this memory model. No game suspension, delivery, allocation or resume routine is bypassed.


## Diagonal coefficient blocks and verified full image-read sequence [V]

`tools/boot_coefficients.py` reconstructs `$995C-$9AA3` for native M=0/X=0 callers. Output is an 8-by-8 array of 16-bit coefficients at the caller's low-WRAM direct page. It first stores incoming A as the DC predictor, reads one signed/zero-run delta and adds it with 16-bit wrap. The remaining 63 deltas are stored directly as signed words. Stores follow alternating diagonals across the 8-by-8 array, beginning at offsets 00/02/10/20/12/04 and ending 6E/7C/7E. The return is the updated first coefficient; the output pointer and caller DB are preserved. 240 constructed-tree comparisons cover predictor wrap, cache/refill boundaries, RAM/ROM sources and retained fourth/adjacent state, checking all WRAM outside caller stack scratch and full returned A.

The image body at `$A009` iterates twelve outer groups by sixteen inner groups. `$9DB6` requests six coefficient blocks per group, writing at direct pages 1600/1700/1800/1900/1A00/1B00. The first four share predictor word `0110`; the last two use `0112` and `0114`. `$9D0E` saves the returned DC before scaling/transforming the coefficients and restores it into X afterwards. The initial predictors are the tree header's low byte and two zeroes: the real header initializes them to 6/0/0. This resolves the header low byte's observed role as the first predictor's initial value, without inventing additional header semantics.

The verifier executes the real tree/decoder/component prelude and compares all 1,152 sequential coefficient calls (73,728 coefficients) with the readable model. The scaling/transform closures contain no calls to the symbol/delta/block decoder; omitting them from this **read projection** therefore preserves stream consumption and saved DC progression. They are not yet reconstructed or compared here. Likewise the task's inter-phase message and rendering behaviour is outside this projection.

After the palette prelude and every coefficient block, the refill cursor is `D2:FDFE`. A total of 5,954 bytes was fetched from `D2:E6BC`, with 14 bits still buffered and cached symbol 7F. The wholly unused final fetched byte is excluded: the verified consumed prefix is 5,953 bytes, ending exclusively at `D2:FDFD`. The catalogue extends the previous 351-byte prefix by 5,602 bytes. It does not claim that every remaining buffered bit is padding or that the complete asset endpoint has been proven. No decoded coefficients, colour payloads or compressed bytes are saved.

The coefficient tool passes 240 generated block comparisons plus one complete real-image read sequence containing 1,152 individually compared original blocks. The real sequence checks all WRAM outside caller stack scratch after each block and full returned DC. Non-native width, wrapping/aliased direct pages, transforms, rendering and complete task synchronization remain open.


## Coefficient scaling and complete two-pass image transform [V]

`tools/boot_transform.py` reconstructs scaling `$9AA4-$9AD3`, the two-pass integer transform `$9AD4-$9D0D`, saved-predictor block processing `$9D0E-$9D1D` and complete six-block groups `$9DB6-$9DF4`. The base CPU previously ignored these Mode-7 register writes/reads, returning zero for multiplier results. The new harness subclasses it with a functional shared latch and multiplier; existing base-CPU traces are not retroactively claimed as successful image transformation evidence.

The hardware contract follows [bsnes's PPU register implementation](https://github.com/bsnes-emu/bsnes/blob/master/bsnes/sfc/ppu/io.cpp): Mode-7 word-register writes combine the current byte with the shared previous-byte latch; result registers 2134-2136 expose signed 16-bit M7A multiplied by signed high byte of M7B. The harness supports the shared-latch registers used here and mirrored PPU addressing. It models arithmetic/register values, not physical chip timing or interrupt interleaving. 512 boundary/random arithmetic checks include signed operands and an interleaved shared-latch write.

Scaling uses zero-terminated byte weights at caller-DB address 1D00. For each coefficient it writes weight then zero to M7A, then writes the coefficient's **low byte twice** to M7B. Thus the scaled word is `unsigned_weight * signed_low_coefficient_byte`, truncated to sixteen bits; the incoming coefficient high byte is ignored. It writes the result back to that coefficient and advances. The real configuration template has 64 nonzero weights followed by the installed zero terminator. The original routine restores D, advances X/Y by the processed length and returns with M=1. Tests check exact ordered multiplier writes and WRAM, including early terminators and arbitrary incoming high bytes.

The transform uses the eight sign rows `++++++++`, `++++----`, `++----++`, `++--++--`, `+--++--+`, `+--+-++-`, `+-+--+-+`, `+-+-+-+-`. The first pass transforms columns into the 128-byte scratch half at direct page+80. The second pass transforms that intermediate into the first 128 bytes. Both stages retain sixteen-bit wrap; the second adds bias 4 before converting the wrapped signed word with arithmetic shift right by three. In matrix notation it implements the separable sign transform `H * C * H^T`, with that final rounding/scaling and intermediate wrap. The original leaves the intermediate scratch intact, advances D by sixteen and returns X=70/A=0. The checked domain uses page-aligned nonwrapping low-WRAM coefficient blocks and native index width.

`$9D0E` preserves the decoded DC before scaling and transforming, then returns that saved predictor in X. `$9DB6` executes all six blocks, updates shared predictor 0110 after the first four and predictors 0112/0114 after the last two, and restores its caller D. The verifier processes all 192 real image groups with original decoder/scaler/transform code and compares every group's WRAM outside caller stack scratch, ordered multiplier writes and saved predictor. The final stream cursor remains D2FDFE, independently agreeing with the coefficient-only read projection. This now verifies the transformations, but component-to-colour conversion and complete task/render synchronization remain open.

The tool passes 1,424 checks: 512 functional hardware-contract checks, 240 original scaling calls, 320 original transform calls, 160 complete decode/scale/transform calls and 192 complete real-image groups. Hardware-contract checks are distinct from the 912 original routine/group comparisons. No coefficient matrices, configuration weights, decoded image or ROM payload bytes are saved. The ROM coverage union remains 32.9219% because these routines and configuration data are inside already counted compressed blocks.

Bank-source correction: re-reading the internal `$86F1` bank switch resolved an earlier incorrect tile-composition assumption that samples followed caller DB. Earlier DB=7E fixtures duplicated the samples/pointer between banks and did not distinguish these sources. The model now reads samples/pointer from 7F and the repeated tile comparisons deliberately give the caller bank different samples and a different pointer. Earlier traces are replaced; case counts are not added twice.


## Image component mixing and four-tile colour expansion [V]

`tools/boot_pixels.py` reconstructs chroma-component mixing `$9DF5-$9E3C`, one-tile expansion/submission `$9E3D-$9F73` and complete four-tile mixing/submission `$9F74-$9FA3`. Mixing reads 64 word pairs from planes 1A00/1B00. For each pair u/v it writes words `v >> 1`, `-((u >> 3) + (v >> 2))` and `u >> 1` at offsets 0/1/2 of a four-byte record at 1C00. The shifts are logical word shifts and the negated sum wraps to a word. These overlapping stores leave three low component bytes and the high byte of the last word as the fourth byte; that fourth byte is not silently cleared.

Expansion processes luminance words in reverse pixel order, using low byte of `word >> 2`. Each chroma triple is shared by a 2-by-2 group of pixels. The four callers select quadrants at 1C00/1C80/1C90/1C10 for luminance blocks 1600/1700/1800/1900. Chroma-pointer updates operate on the low byte and preserve its high byte. The tested callers use four-byte-aligned quadrants whose triples remain within the page. Expansion writes three component bytes at four-byte spacing and retains each fourth byte before the destructive tile conversion.

Byte adjustment adds luminance to each component in blue/green/red order, selecting an excursion outside the desired 0-63 range. It then folds/corrects the three values relative to that excursion and halves them. The original comparison branches combine CMP's negative/zero flags with **V retained from preceding arithmetic**. Consequently the readable model carries that overflow state explicitly, including between the three component adjustments. Replacing this sequence with independent signed clamps would change arbitrary-byte behaviour. Tests compare the complete original sequence, not merely a simplified colour formula.

The one-tile entry invokes the complete original palette lookup, planar conversion, temporary copying and descriptor submission. The four-tile entry first mixes chroma, then expands and submits all four quadrants. Target colours use the caller's low-WRAM bank, while reference samples/pointer and cache remain in 7F. The preceding tile-bank assumption was corrected and its 338 comparisons repeated with deliberately different caller-bank samples/pointer; no extra case count is credited for that repeat.

The tool passes 656 original comparisons/compositions: 240 chroma mixes, 160 complete tile expansions/submissions, 64 constructed four-tile groups and 192 real image groups. The real sequence combines decoding, scaling, integer transforms, component mixing, nearest palette selection, eight-bit planar conversion and descriptor submission for all 768 tiles/49,152 pixels. The final stream cursor remains D2FDFE. Every real cache miss has nearest squared distance at most 51, below the minimum retained-byte threshold 255; this establishes independence from its uninitialized high byte for this real sequence. All WRAM outside caller stack scratch 1F80-1FFF agrees. Each group uses an explicitly supplied four-descriptor completion count for original cleanup and the corresponding model; physical DMA payload/completion and full parent-task/message timing remain open. No decoded image or palette payload is saved.


## Image-row requests and conditional palette/workspace replacement [V]

`tools/boot_image_protocol.py` reconstructs `$9FA4-$A008`. It allocates an eight-byte message record, writes opcode word 3 at +3, then writes the caller's word argument at +4. The latter overlaps the opcode's high byte; the resulting opcode field is therefore a low-byte 3, followed by the complete argument. Original `$B258` sends it to the low byte of caller X; X's high byte does not select another task. The routine performs raw `$B2FB` receive and tests the returned word +3, without validating a particular opcode/tag. A zero response word skips replacement; any nonzero word submits the packed sample palette and replaces graphics workspace 43. It finally releases the response record and restores caller D/DB/status/stack.

The replacement count uses hardware byte multiplication. After a word ASL and XBA, the byte LDA 20 replaces the low half of A; the remaining high half is the **low byte of the shifted argument**, not its high byte. Thus count is `((argument << 1) & FF) * 32`. Argument high bytes do not affect that count. For image row r in 1-11 it is 64*r. A zero count makes the downstream decrement loop run 65,536 allocations, so zero-count positive acknowledgements remain outside this harness's checked domain.

The harness passes 320 complete original calls: 160 zero response words and 160 nonzero response words with palette upload and workspace replacement through 768 blocks. Cases vary caller DB, argument/recipient high bytes, raw response tags including FF, and sample values. Original allocation, message delivery, suspension/selection/resumption, palette and graphics callees execute without hooks. All WRAM outside caller stack scratch 1F80-1FFF agrees, as do restored D/DB/S/M/X. The response is preloaded, so real parent response generation/timing, exhausted record/descriptor waits and physical DMA remain open.


## Complete twelve-row image body [V]

`tools/boot_image.py` reconstructs `$A009-$A060` as `initialize_image` and `image_groups`. The caller word combines the recipient's low-byte id with the tree header's low byte in the argument high half. Initialization stores decoder X at low-WRAM 0116, installs that high-half byte as predictor 0110, and clears predictors 0112/0114. The outer loop starts row zero, calls the row exchange with that row value and the saved recipient word, executes sixteen complete decode/transform/four-tile groups, then advances the row through eleven. There are 192 six-block groups, 1,152 coefficient blocks and 768 submitted tiles.

The verifier runs the **continuous original A009 body**, rather than restarting its callees with a new stack per group. It independently models scene/tree/staging/template preparation and the real D2E536/D2E6BC palette prelude before entering the body. At each row's original call boundary it supplies one raw response through original record allocation and B258 delivery. The supplied response word is zero for row zero and one for rows 1-11. This tests the full conditional renewal sequence without claiming that the original parent has itself been reconstructed. Renewals reserve the preceding rows' 64*r blocks before each subsequent row adds 64 more tiles.

The harness also supplies completion counts at explicit transfer boundaries, invoking original 92E9 cleanup while preserving the interrupted register state. It does not reset the active outer stack or replace any image routine with a hook. Pending map/palette descriptors are cleaned before entry, renewed palettes before row output, and four tile descriptors after every group. These boundaries establish original memory and resource effects for that supplied completion sequence, not physical DMA payload, IRQ timing or real completion acknowledgements.

The complete real body passes: twelve compared row exchanges, 192 compared image groups and 781 descriptor completions (two initial map/palette, eleven renewed palettes and 768 tiles). All 49,152 pixels are converted/submitted. Full WRAM outside caller stack 1F80-1FFF agrees after preparation, every row/group/cleanup and final return, together with exact ordered multiplier writes and restored D/DB/S/M/X. The final stream cursor is D2FDFE; real cache misses retain the maximum nearest distance 51. No image, palette or compressed payload bytes are saved. This proves the complete A009 body within its documented boundaries; the surrounding 968D task and physical synchronization remain open.


## Complete colour-image task lifecycle [V]

`tools/boot_image_task.py` reconstructs `$968D-$9715` as `prepare_image_task`, `send_phase` and `colour_image_task`. The task reads the current task's parent id, prepares the scene/tree/staging/template resources, expands the real D2E536 tree, and derives stream start from the tree header as `E536 + 3*(branch_count+1)` (word wrap). It initializes decoder 80 and reads all three sets of 232 palette samples, then builds the lookup and submits the packed palette. The header word is stored starting one byte after the saved parent id; this overlap forms the word passed to A009: parent in the low byte and header low byte in the high byte.

The task allocates a record and sends opcode word 2 at +3 to its parent, receives any raw record and releases it. It executes the complete twelve-row image body, then sends opcode word 4, performs another unfiltered raw receive/release and tears down all colour-scene resources before RTL. Unlike the row message, the phase messages do not write a word at +4 after the opcode; remaining record payload bytes retain allocation history. Neither phase receive validates a response opcode or establishes hardware completion.

The verifier runs the continuous original 968D task, including setup, both phase exchanges, every image row/group and teardown. A live current task id 3 and parent id 7 are configured before allocation, so owner-sensitive resource/pool effects are compared. At explicit send/row boundaries the harness supplies responses through original record allocation and B258 delivery, with FF tags. Phase responses carry word 8002/8004; row zero carries zero and later rows one. Original raw receive/scheduler/resume/release and all image/resource callees execute. Transfer completion counts are supplied through original cleanup while preserving active registers/stack; real parent logic and physical IRQ/DMA remain outside these boundaries.

The complete task passes original execution comparison: two phase exchanges, twelve row exchanges, 192 groups/768 tiles/49,152 pixels and 781 descriptor completions. Full WRAM outside caller stack 1F80-1FFF agrees at every boundary and after teardown/RTL; exact multiplier writes and restored D/DB/S/M/X agree. At final return there are zero task-owned heap pages and zero pending descriptors. Fourteen outgoing records remain queued to the parent, in exact order: phase 2, twelve rows, phase 4. Those records belong to the unexecuted parent interaction and are not incorrectly reported as a pool leak or as consumed replies. Real cache-miss maximum remains 51 and the retained stream cursor D2FDFE. No raw image/palette/configuration payload is saved.

Caller investigation identifies `$D23E` loading descriptor `7E:5F12` at D244 and invoking original AB88 task creation. The parent caller and its D17F/D1DA/D20D helpers now have verified models within the controlled message/service boundaries described below; concurrent parent/child scheduling remains open.


## Parent image, tracked-task and shared-buffer messages [V]

`tools/boot_parent_messages.py` reconstructs three handlers called by the parent receive loop D17F. They use caller DB=7F for absolute fields; the helpers do not switch it themselves. `$CFE2-$D022` reads incoming opcode byte +3 and row byte +4, then immediately releases the record. Opcodes 1/2/4 return that opcode in low A without allocating a reply. Every other opcode allocates and sends a reply to image-task id byte 0311 and returns zero. Pool allocation clears reply bytes +3/+4; only an incoming row byte equal to 4 installs byte +3=1. Therefore ordinary opcode3 rows 0-3/5-11 receive word zero, and **row4 alone receives word1**, renewing the palette and replacing graphics workspace while reserving the first 256 blocks. Subsequent 512 tile reservations fit the resulting 768-block workspace. The high argument byte is irrelevant to this handler.

Earlier complete image/body/task comparisons explicitly supplied zero for row0 and one for all later rows; those remain tests of that documented boundary sequence. They are not evidence that the original parent makes those decisions. The now-verified parent handler establishes the actual row-response decision and the next full composition must use it. Phase2/4 do not get an automatic CFE2 reply: their acknowledgements belong to the surrounding parent caller and remain open.

`$D023-$D050` saves the incoming record's byte +2, releases the record and scans exactly twenty id bytes 0318-032B. It clears only the first matching byte, including a matching zero; later duplicates remain. `$D081-$D0AD` releases its record, then clears auxiliary task-id byte0312 unless opcode byte+3 is1. For opcode1 it allocates a cleared-header reply, writes shared buffer pointer word0306 at +4 and sends it to low id0312. Other payload bytes retain pool allocation history.

All three handlers pass 384 complete original calls each, for 1,152 comparisons. Cases enumerate all opcode byte values before extra phase/row4 boundary cases, vary valid/zero/missing recipients, existing destination chains, record tails and duplicated tracked ids. All WRAM outside caller stack1F80-1FFF agrees, as do restored D/DB/S/M/X; image-handler low-A results agree. Original pool allocation/release and delivery execute. Checked recipients are running tasks; waiting-recipient wakeups, the complete D17F parent loop and physical IRQ timing remain open. No ROM payload bytes are saved.


## Complete image task with original parent row responses [V]

`tools/boot_image_task.py --parent-rows` composes the continuous original 968D task with original parent handler CFE2. For every row the verifier stops at the original 9FD4 raw-receive call after the outgoing request is sent. It supplies a parent execution context, consumes the head through original B20B link replacement, advances the parent queue at the supplied context boundary, then executes original CFE2 allocation/decision/delivery. The independent model performs the same record and handler operations. The original child resumes its untouched receive/expansion/generation code; no row-response value is installed by the harness.

Only row4 consequently renews the palette and graphics workspace, reserving 256 previous blocks before producing the remaining 512. This sequence needs 771 supplied descriptor completions: two initial map/palette descriptors, one renewed palette and 768 tiles. Phase2/4 responses remain externally supplied FF-tagged records because their surrounding parent caller is not yet reconstructed; CFE2 does consume those outgoing phase requests afterwards, returning their opcode without a reply. All fourteen outgoing messages are thus consumed instead of left on the parent queue.

Parent context changes and queue-head advancement are explicit harness boundaries, not a claim to execute the full D17F receive loop or its scheduling. The original link helper/handler/child routines all execute, and physical transfer completion remains supplied. This composition narrows the remaining gap to phase acknowledgement, full parent loop, pause/timing and physical IRQ/DMA.

The parent-row composition passes: two phase exchanges, twelve row exchanges, 192 groups/768 tiles/49,152 pixels and 771 descriptor completions. At return, task-owned heap pages, pending descriptors and parent queued messages are all zero. Every phase/row/group/cleanup and teardown agrees across full WRAM outside caller scratch1F80-1FFF, together with multiplier writes and restored D/DB/S/M/X. Original CFE2 generates all twelve row replies and consumes both phase requests. Phase replies and transfer completion remain supplied boundaries; whole parent scheduling/phase acknowledgement are not inferred.

## Parent receive filtering outside pause [V]

`tools/boot_parent_receive.py` reconstructs `$AEC4-$AF0A` when pause bit40 of 7F0096 is clear. It first executes AE37 (which has no persistent effect in that branch), then chooses ABE7 for a nonzero initial delay or ABAD for zero. Those original wrappers suspend/resume and handle timer notifications. A zero returned record gives low A=1. An ordinary record returns X unchanged and low A=`(tag-FE)&FF`; this return byte is not simply a boolean. A tagFE record with byte+4 equal1 is released and returns X=0/A=0 (cancellation). Other FE records are released and retried with X/delay zero, using the existing timer rather than reinstalling the original delay. Cancellation compares only byte+4, even if +5 is nonzero.

The tool passes 480 complete original calls: 160 ordinary records, 160 cancellations and 160 matching FF timer notices, each with zero to three preceding discarded FE records. Initial delays cover zero/1/4/256/7FFF/FFFF; caller DB varies and is restored. Full WRAM outside caller scratch1F80-1FFF, returned X/lowA and restored D/DB/S/M/X agree. Original AE37/ABAD/ABE7/timer/scheduler/pool helpers execute. Cases use preloaded chains without competing ready tasks; actual empty-queue timing, the pause branch and complete D17F loop remain open.


## Controller routing and parent receive dispatch [V]

`tools/boot_parent_dispatch.py` reconstructs four controller-field helpers. Five sixteen-byte records begin at the pointer in 7F0092. All selectors use the caller's **low A byte**: values0-4 select one record, values5-FF select a group. `$A351-$A3A4` assigns current task id (root1 if absent) to selected owner byte+1; its group form assigns all five. `$A3A5-$A3FB` clears a selected single owner unconditionally, while its group form clears only owners matching the current task. `$A3FC-$A45E` writes the supplied word X to pressed-event mask+8, and `$A45F-$A4C1` writes it to released-event mask+A. Single-record mask writes ignore ownership; group mask writes affect only current-task-owned records. Other bytes, ownership and masks are retained as applicable.

`$D0AE-$D0CB` releases its incoming notice, claims all controllers for the current task, installs pressed mask F0F0 on all of them and sets byte0316=1. This is input routing, not an audio command. Its original callees execute inside the checked parent-loop compositions.

`$D17F-$D1D9` repeatedly calls AEC4, using the initial delay once and zero on subsequent receives. Sender byte+2 is classified in **ordered** comparison against0312 (shared-buffer task),0314 (control task),0315 (input-completion task), then0311 (image task); everything else is a tracked-task message. Buffer, input-completion, tracked and image-row handlers continue waiting. An image handler phase1/2/4 result returns X=0 with that low-A opcode. A control-task message clears0314 and returns **the record in X with low A=0 without releasing it**. A zero record/nonzero receive result returns immediately. A cancellation calls D14C: its existing-control-task branch has no memory effect, then the loop continues. New control-task creation is not modelled by this checked loop scope.

Four controller helpers pass 240 original calls each (960 total), varying selector low/high bytes, root/live/zero task identities, ownership and arbitrary masks. The dispatch loop passes 480 complete original calls with zero to five preceding row/buffer/input/tracked/cancellation records and terminal image-phase/control/FF timer records. Cancellation cases retain an existing control task, so original D14C takes its no-op branch. All original receive/scheduler/handler/pool/input callees execute; full WRAM outside caller stack1F80-1FFF, restored D/DB/S/M/X and dispatch X/lowA agree. Pause is disabled and queues are preloaded with no competing ready tasks. New-control spawning, empty-queue timing, the surrounding parent caller and physical IRQ timing remain open.


## Parent control-task creation and fade-out [V]

`tools/boot_parent_control.py` reconstructs `$D14C-$D17E`. A nonzero control id0314 returns without changing resources. Otherwise, if byte0316 is nonzero, the routine writes request80/20 at low-WRAM1E00/1E01 and executes original C30004. Command80 sends retained parameters1E02/1E03 through ports3/2, parameter20 through port1, command80 through port0 and a final port0 zero; original command consumption clears1E00. The harness supplies immediate APU-port echoes, not SPC command execution or audio output. It then spawns the real descriptor7E6492, stores the returned **task id byte** at0314, and releases only controller owner bytes matching the current task. Input release still executes when there is no free task record and spawn returns zero.

320 complete original calls pass: existing control(80), new control without audio(80), new control with audio(80) and missing free task record(80). Cases randomize controller ownership and retained request bytes, reserve the live parent id/page and remove its record from the free list. Original descriptor/frame/timer/heap creation, input release and the complete C30004 command80 sender all execute. Full WRAM outside caller scratch1F80-1FFF, ordered port writes and restored D/DB/S/M/X agree. Task-frame/timer/heap availability bounds successful creation; SPC processing, frame timing and the complete parent caller remain open.

`tools/boot_parent_fade.py` reconstructs `$D1DA-$D20C`. Each iteration calls the original D17F dispatch with delay4. A zero result stops with low A=0. A nonzero result with an existing control id continues waiting without allocating a video record. Otherwise it allocates a register00 record seeded from the PPU shadow, tests the low brightness byte and decrements that byte by one before queueing it. A resulting zero returns low A=1 after submission. If the initial byte is already zero, the allocated record is **not queued or returned to the free list**; the model preserves this literal effect. High record bytes retain their original shadow seed. Brightness bytes80/8F are likewise decremented literally rather than masked to four bits.

192 continuous original fade calls pass: 144 complete fades and 48 control-message terminations, with **6,936 individually compared PPU updates**. The independent model compares all WRAM outside caller scratch after every queued step, original C18B shadow service and final return, as well as X/lowA and restored D/DB/S/M/X. Original receive/timer/scheduler/handler/allocation/queue helpers execute. The harness applies original C18B at explicit service boundaries while preserving the active registers/stack; this establishes queue/shadow/resource effects, not physical video writes or IRQ timing. Timer/control records are preloaded, pause is disabled, and no new control is created within the fade comparisons.


## Parent fade-in and two title tilemaps [V]

`tools/boot_parent_transition.py` reconstructs `$D20D-$D23D`. Each iteration receives through original D17F with delay4. A zero result stops with low A=0; a nonzero result while a control task exists continues waiting. Otherwise register00 is allocated from the PPU shadow. If its low byte is already at least0F, the routine returns that byte and leaves the allocated record unqueued/unreleased. Lower values increment by one and are submitted; reaching0F returns that literal value, not boolean1. Values80/8F/FF also return unchanged, without clearing their forced-blank bit. Queued values are tested with original C18B shadow service at explicitly supplied boundaries.

192 continuous original fade-in calls pass: 144 brightness sequences and48 control-message terminations, with684 individually compared PPU updates. Cases include initial values0/1/7/14/15/80/8F/FF, retained high shadow bytes and preloaded timer/control messages. Full WRAM outside caller scratch1F80-1FFF agrees after each queued step/service and return, together with returned X/lowA and restored D/DB/S/M/X. Original dispatch/timer/scheduler/allocation/queue routines execute; pause/new control creation and physical video/IRQ timing remain open.

`$CD82-$CDBE` reads 29 rows of32 source bytes from configuration bank7E at64A6+callerX. Each byte becomes the low half of a bank7F map word; byte0310 is repeated as every high half. It writes exactly928 tile entries/1856 bytes at the registered destination word0306, leaving the remaining192 bytes of an0800-byte buffer unchanged. It then executes the original C870 registered-map transfer producer. The checked caller offsets0/03A0 select two disjoint928-byte maps at64A6/6846, ending at6BE6, the existing decoded configuration endpoint. It neither saves nor exports those map bytes.

256 complete original map calls pass: both real configuration maps plus254 randomized map cases. Cases vary repeated attribute byte, all destination bytes (including the retained tail), and zero to three prior submitted descriptors. Full WRAM outside caller scratch agrees. Final X points to the newly appended pending-vector entry and Y to its descriptor; these are the transfer helper's return values, not the copy's intermediate source/destination cursors. Restored D/DB/S/M/X agree. Heap/PPU/DMA resources and a matching registration are available; transfer programming is verified, physical DMA payload/rendering remains open.


## Complete title parent sequence [V, controlled scheduling]

`tools/boot_title_sequence.py` reconstructs `$D23E-$D2FB`: launch the image task through descriptor5F12, submit the second map, fade in, wait for input completion, load song2D, wait7FFF, acknowledge the image phase, wait010E, fade out, submit the first map, wait001E, load song2C, fade in, set0317 and launch the text task through descriptor5EAA. An unsuccessful dispatch/transition returns immediately. The phase acknowledgement is an allocated cleared record; no invented message opcode is inserted.

Fifteen continuous original calls pass: two successes with one/two input waits and13 control aborts across all seven dispatch/transition exits. Each fade is interrupted before updates, after7 and after14 updates; the four waits are also interrupted. Across these calls363 PPU shadow updates and16 native song loads agree, with the real SPC driver running where music is reached. Final task ids are image2/text3 on success and image2/text0 on the early abort. All original game callees execute. The model compares WRAM at each wait/fade/map/music boundary and final return, excluding music-loader private variables/workspace1E04-1FFF and caller stack0740-07FF. The request bytes1E00-1E03, descriptor/message/queue effects and restored D/DB/S/M/X are checked. The task7 stack is placed at07FF so it does not overlap the loader's actual instrument tables at1F00/1F40/1FC0.

The parent has higher priority than the spawned children in these fixtures. Completion, phase and timer records are preloaded; original C18B shadow service runs at explicit boundaries. Thus the image/text children are created but are not concurrently executed by this parent harness. The separate complete968D image-task probes establish image generation/parent row handling. Joining these tasks under actual scheduler/IRQ timing, resource exhaustion/pause/cancellation and readable music-loader internals remain open; no full audiovisual rendering or complete decompilation percentage is claimed.


Control-abort fixtures supply one sender6 record at the selected wait/transition boundary, replacing the remaining preloaded input chain equally in model and original memory. D17F clears0314 and returns this record without releasing it; D23E immediately returns, retaining the notice and previously created image task. No abort sets0317 or creates the text task. Partial fades preserve their exact last applied brightness, and music executes only if its request was reached. This validates all seven parent control-return branches, not the concurrent execution of the producer or natural arrival timing.


## Complete title control task [V, controlled scheduling]

The existing descriptor at7E6492 starts `$7E:D0CC`; its entry is the first three descriptor bytes, followed by priority74. `tools/boot_control_task.py` reconstructs `$D0CC-$D14B`, the producer of the parent's control-completion record. If0317 is zero, the task dims through register00 records, copies the first title map through CD82 with X=0, increases brightness until literal0F and waits001E. A nonzero0317 skips that entire prelude. Both paths then dim to zero with delay4 between queued steps, obtain the parent id through ACD0, allocate a cleared message through B1A9, append it through B258 and return RTL.

The first dimming loop does not queue its allocation when the initial value is zero or its decrement reaches zero; it proceeds to the map instead. The last dimming loop queues its final zero record before notifying the parent. Brightening tests equality with0F, rather than the >=0F test in D20D. These effects now match continuous original task calls. The ABE7 waits consume matching FF timer records internally, unlike the image task's unfiltered B2FB receive. The parent/control pair now has original scheduler compositions below; completed-task reaping and complete title/image concurrency under physical IRQ timing remain open.


54 continuous D0CC calls pass:18 complete map transitions and36 final-dim-only calls, with0317 values0/1/FF and initial brightness0/1/2/7/14/15/80/8F/FF. Half use matching FF timer notices; half use ordinary sender5 records. The latter are consumed from the queue but are not released by this caller, while matching timer records are released inside ABE7. The literal byte dimming is preserved even for forced-blank/high values. Every call ends with shadow brightness0, no pending input records and exactly one cleared parent notification whose sender id is7. Caller D/DB/S/M/X restore.

There are3,902 individually compared PPU queue/shadow updates and3,848 waits. All WRAM outside caller scratch1F80-1FFF agrees at every queue, wait, map submission, notification and final RTL. Original task/scheduler/receive/pool/map/queue callees execute; C18B shadow service is explicitly supplied at each queue boundary. Only the control task is ready, the parent record is running and available, and records are preloaded. Resource exhaustion, parent consumption, completed-task cleanup, concurrent parent/child scheduling and physical PPU/DMA/IRQ timing are not established by this probe.


### Parent/control scheduling composition [V, explicit service boundaries]

A further12 original compositions begin with no parent input records. Original D14C creates descriptor6492/id2 and releases parent input ownership; its complete WRAM effects agree with the creation model outside parent stack0740-07FF. Original D17F suspends the parent. Original dispatch enters D0CC, its empty waits create the fallback task, original CCB7 generates timer messages and wakes the child, and the child's actual parent notice wakes/resumes the parent. D17F consumes that notice, clears0314 and returns low A=0/X=the unreleased record. The child is linked on completed-list A4 with status16. No queue records or game routine results are preloaded or substituted in these compositions.

Cases use0317=0/FF and brightness0/1/7/15/80/FF. The entire expected brightness submission sequence, all child wait delays, total timer-service calls, exactly one child entry, map-call presence/absence, parent return/restore, retained sender id and completed-child state are checked. They add983 compared PPU updates and2,600 original timer-service calls. This composition checks these observations and full spawn memory, rather than claiming a whole-WRAM independent scheduler model. CCB7 is invoked explicitly at the fallback boundary with supplied PPU reads, and C18B shadow service at each queue boundary. Physical IRQ timing, task reaping and concurrent image/text/title execution remain open.


Completed control-task reaping is now checked in all12 scheduler compositions. After the parent returns, original A9C7 is explicitly invoked and its full WRAM effects agree with `boot_cleanup.reap_one` outside parent stack0740-07FF. The completed-list head is removed, the task record is prepended to the free list, status/id/parent words and page reservation clear, its timer disables and no heap unit remains owned by its former id. The retained notice's link word is the parent id7 after B20B consumption; its sender byte remains the child's former id2. Child cleanup preserves this whole record. These are supplied post-return cleanup boundaries, not a physical IRQ chronology. Initial unqueued PPU allocations retain the original effect already described above.

## Title scanline-table producer [V]

`tools/boot_title_window.py` reconstructs `$CE6B-$CFE1`, called by D2FC with widths2..64 and centre0070. It doubles the centre modulo65536, computes a nonnegative top from `(doubled-width)>>1`, and computes bottom from `min((doubled+width) mod65536,447)>>1`. Height is the word difference. Subsequent packet decisions use only low bytes: a nonzero top masks bits11 off the seeded register2C byte; zero top sets those bits. Nonzero top/height values at least80 split into literal127 and remainder packets. If top is nonzero, bottom's low byte is at least223 and height's low byte is nonzero, the routine decrements only their low bytes. Returned X/Y retain these exact word/byte effects.

The producer allocates inline-copy records containing count/mask pairs to table word030C. Top packets use the outside mask, height packets OR11, and a final three-byte packet is `(1,seeded outside mask,0)`. It queues register2C itself. If030E is zero it allocates kind05 HDMA, records it at030E, selects mode0/register2C and bank7F/table030C, and executes original submission; an existing030E skips registration. No packet/table bytes are exported.

336 complete original comparisons cover14 widths x12 centres xboth new/existing registration, including word-overflow, byte boundaries and large generated values. Full WRAM outside caller scratch1F80-1FFF, X/Y, restored D/DB/S/M/X and ordered HDMA-register writes agree. Each case also runs original C9E5 copy-queue service and C18B shadow service and compares their entire memory effects. Configuration classes are real, the table is valid at7F3000 and PPU/copy/HDMA resources are available. Physical scanline behaviour and resource exhaustion remain open; the complete D2FC caller now has the controlled-service comparisons below.


## Complete title window opening [V, controlled service]

`tools/boot_title_reveal.py` reconstructs `$D2FC-$D347`. It allocates a register0E record, replaces only its low value byte with2F and queues it, preserving the seeded high byte. Register0E uses actual configuration shadow class42. It launches descriptor5EA0 (entry7E8D1A) and stores the returned task id byte at0312. A stack counter starts at zero; each pass increases it by2, calls CE6B with centre0070, then D17F with delay3. Widths2..64 are all processed, including equality with0040; the following width0042 terminates. A zero dispatch result exits immediately. The result byte is copied through the reused stack local into low A: complete timer-driven runs return1, control exits return0. Normal X is0042; an abort returns the unreleased control-record pointer. The original entry X is a discarded stack local, not a preserved register.

66 continuous original calls pass: two complete32-step openings and64 exits, one at every step with both new and existing HDMA registration. All1,120 generated windows and1,120 dispatches agree. Cases randomize table canaries, main-mask shadow, actual class42 scroll shadow (including retained high byte) and entry X. Every launch, window, wait, original C9E5 copy service, original C18B shadow service and final return compares full WRAM outside caller scratch1F80-1FFF. Ordered HDMA-register writes, dispatch X, final X/lowA and restored D/DB/S/M/X also agree. Pending one-shot copy/PPU queues are empty after the supplied services.

The parent has higher priority than the created8D1A child in these fixtures; creation is executed but the child itself is not run. Timer records are preloaded, and a sender6 completion is supplied at the chosen wait boundary in abort cases. The original parent handler clears0314 without releasing that record; all preceding table and shadow updates remain. These probes establish the entire caller and its resource/queue effects within those boundaries, not natural concurrency, exhausted resources, pause/cancellation or physical HDMA/IRQ timing.

The adjacent D348 word-scroll and D377 expansion now have the verified models below.


## Complete title word-scroll continuation [V, controlled service]

`tools/boot_title_scroll.py` reconstructs `$D348-$D376`. Each iteration allocates register0E, decrements its seeded **word** modulo65536 and queues the whole result. A resultingFFF0 terminates immediately, without a following wait; the final XOR0080 returns full A=FF70 (low70 for a byte caller). Other values dispatch through D17F with delay8. A zero dispatch result takes the LDA0080/XOR0080 path and returns full A=0. Final X is the last queued PPU record on success, or the unreleased control notice on abort. The native caller temporarily uses16-bit A even if entered with M=1; D/DB/S/M/X restore.

86 continuous original calls pass: eight complete sequences and78 control exits, including all62 early exits from the ordinary initial002F. Generated starting words coverFFF1/FFF2/FFF8/0000/0030/0100 and early exits fromFFF0. Starting atFFF0 does not complete immediately: decrement precedes comparison. One unbroken original call is compared through all65,536 values and returns toFFF0. Its65,535 required notifications are generated with original CC8C at supplied boundaries, using the real allocation/delivery/release path instead of an oversized synthetic record chain.

All68,466 PPU updates and68,458 dispatches across these cases compare full WRAM outside caller stack1F80-1FFF, plus queue/wait/final X, full return A and caller restoration. Original C18B service applies each queued word; the actual class42 shadow is used. Other cases preload matching timer/control records. Available resources and supplied video/timer service remain explicit bounds; empty-queue concurrency, exhaustion/pause/cancellation and physical IRQ/video timing remain open.

## Complete title window expansion [V, controlled service]

`tools/boot_title_expand.py` reconstructs `$D377-$D3A9`. Its stack counter starts at0040 and increments by1 before each CE6B call with centre0070. Crucially, the endpoint compares the **returned top bound X**, not that width counter, to0010. This processes widths65..191, or127 table updates. When the top becomes16 the caller returns low A=1 without another wait. Every earlier update calls D17F with delay3; zero returns immediately. Normal final X=0010; abort X is the retained control record.

254 continuous original calls pass: two complete127-step expansions and252 aborts, at each of126 waits with both new and existing HDMA registration. All16,256 windows and16,254 dispatches compare full WRAM outside caller scratch at window/wait/copy/shadow/return boundaries, ordered HDMA-register writes, X/lowA and restored D/DB/S/M/X. Original C9E5 and C18B service run at explicit boundaries. Only the parent is ready, notifications are preloaded and control arrival is supplied. Exhaustion/pause/cancellation, complete title concurrency and physical timing remain open.

The following D3AA teardown and ACAC stop entry now have the verified models below.


## Title teardown and task-stop requests [V]

`tools/boot_title_teardown.py` reconstructs `$ACAC-$ACCF`. Only the selector's low byte is used. Original AD02 returns the first id match among20 records, without filtering task status; zero/missing ids do nothing. A match calls AC69 and then writes status10. A linked status04 task is removed from the waiting list and inserted by priority into the ready list before that final status assignment. An unlinked status04 task temporarily becomes80 inside AC69, then becomes10 without insertion. Other statuses retain their original list membership. This call does not link completion-list A4, decrement active count9A, release resources or generate a parent FE message. Later scheduler dispatch/continuation is a separate phase.

480 complete original stop calls pass:336 missing selectors and144 existing matches. Fixtures include byte selectors with nonzero high bytes, first duplicate id200, statuses00/01/02/04/08/10/80, sorted ready chains and linked/unlinked waiting nodes. Full WRAM outside caller stack1F80-1FFF, lookup X and restored D/DB/S/M/X agree; caller D/DB vary.

The same tool reconstructs `$D3AA-$D3E9`: release descriptor word030E via9066, clear030E/030F, allocate register2C and clear only bit0 of its low value byte, append that PPU record, then request stop for and clear each tracked id0318..032B. It processes all20 bytes in order, including zero, duplicate and missing identifiers. It does not clear the separate image/text/control/input ids0311..0315. Final X is032C; the saved bank byte is discarded as a stack local while DB itself remains unchanged.

240 continuous original teardown calls pass, split equally between no descriptor and an allocated kind05 descriptor. The latter cover all eight HDMA channels, including channel0 callback-pointer cleanup, and varied reference counters. Mixed tracked ids/statuses and randomized register2C word seeds retain unrelated fields. Full WRAM, final X and caller restoration agree, followed by an independently compared original C18B shadow service proving only bit0 clears. These checks establish descriptor/channel ownership release and queued software effects; physical channel disable timing, stopped-task continuations/reaping and PPU exhaustion remain open.

Descriptor5EA0 has entry8D1A and continuation8DA0 [C]. The latter calls8CA6 before returning through the task exit chain. Its cleanup/forced-stop dispatch now have the comparisons below; normal8D1A execution and natural title-teardown concurrency remain open; a zero continuation on an unrelated descriptor must not be treated as the same task lifecycle.


## Buffer-task cleanup and stopped continuation [V]

`tools/boot_buffer_cleanup.py` reconstructs `$88CF-$88E6`: release the descriptor word at the caller's slot+2 and free the heap allocation whose pointer is the slot word. It retains both words. `$8CA6-$8D19` releases descriptor3A, auxiliary slots4A/46/42 in that order, then descriptor40/3E/3C. It queues five low-byte defaults `(register,value)=(26,00),(30,30),(31,00),(2E,00),(23,00)`, retaining the seeded high bytes. Descriptor and heap pointer fields3A..4D are not zeroed, and submitted-vector bookkeeping is not compacted by this routine. `$8DA0-$8DAB`, descriptor5EA0's stopped continuation, wraps this same cleanup and returns RTS through the prepared task exit chain.

480 complete original calls pass:160 auxiliary releases,160 resource cleanups and160 stopped-wrapper entries. Fixtures use mixed absent/live descriptors, kinds01/05, zero/allocated heap pointers and randomized actual shadow seeds. Full WRAM outside caller scratch1F80-1FFF, retained resource words and caller restoration agree. Both cleanup entries also execute and compare original C18B shadow service. Resource availability bounds the probes; normal8D1A preparation/body and physical transfer timing are not established.

A further32 compositions execute the original forced-stop chain: AB88 creates the real5EA0 frame/id2, ACAC marks a ready or linked waiting task10, A961 dispatches its **8DA0 continuation**, 8CA6 releases the prepared resources, the RTS exit reaches AA22, and original completion reduces the active count to1 and links the child on A4. Supplied original C18B and A9C7 services then apply queued defaults and reap the child. Sixteen cases use a ready child; sixteen use a waiting child with saved stack02D0. A961 resets that stopped frame to02F6, copies the actual continuation from02FD..02FF, and enters8DA0 with S02F9/D0200. It does not resume the saved waiting return address.

Full WRAM compares at spawn/stop/dispatch entry. Continuation/completion/shadow/reap compare all WRAM outside the active child stack page0200-02FF and parent call scratch1F80-1FFF. The final free-list head is the child, its id/status words and page reservation clear, its timer disables, its explicit workspace is freed and no heap allocation remains owned by id2. Resources are prepared at an explicit boundary with child ownership; no game routine is bypassed. These compositions prove this stopped continuation and its cleanup chain, not the normal8D1A body, concurrent parent execution or physical IRQ chronology.

## Title buffer rows and auxiliary tables

[V] `tools/boot_buffer_rows.py` reconstructs `$8820-$886D` and `$886E-$88CE`. The row parser reads long-addressed bytes at7E59F8+X. A zero leading byte ends the stream and returns X0 without writing. A nonzero prefix emits that many blank low bytes60, then zero-terminated characters (space20 becomes60), and pads to a byte count32. Tile high bytes are retained; destination Y advances by two with word wrap. Source X wraps independently of the long-address bank carry. Character count is a byte and can wrap on oversized rows.

Auxiliary preparation reserves one raw heap unit, copies52 bytes from bank7E, stores the pointer/descriptor pair at the supplied bank7F slot, configures bank7F/mode02/register22 HDMA and submits it. Its descriptor reference is the retained accumulator high byte of the restored temporary stack pointer: `(entry_S-11)>>8`, with word wrap. It therefore differs between parent probe stack1FFF and real child stack02F9. Descriptor submission returns X as the channel register offset, rather than the saved descriptor pointer.

All320 row comparisons and192 auxiliary comparisons pass against complete original calls. They compare full WRAM outside the active caller stack, row X/Y, auxiliary channel offset X, ordered HDMA writes and restored caller state. Row cases exercise leading/count byte edges, source bank carry and destination wrap; auxiliary cases cover three slots, all eight channels, three stack pages and real/synthetic52-byte templates. The report stores only counts, not text or table payloads. Resource exhaustion, normal8D1A composition and physical timing remain open.

## Normal title-buffer display preparation

[V] `tools/boot_buffer_setup.py` reconstructs `$88E7-$8A53`. It builds the scrolling HDMA table in7F0056..0062, reserves seven descriptors, and submits them in order: register10/mode02 from7F0056; three register22/mode02 auxiliary tables copied from7E5CFB/5CC7/5C93; register21/mode00 from7E5C75; register2D/mode00 from a17-byte copy of7E5C64; register27/mode00 from a17-byte copy of7E5C53. The three52-byte copies and two17-byte copies each reserve one raw heap unit. Saved descriptor words are3A/4C/48/44/40/3E/3C; auxiliary pointer words4A/46/42 and remaining pointers54/52 are retained.

The first descriptor has reference zero. Auxiliary references inherit the nested temporary stack high byte `(entry_S-17)>>8`; descriptor40 uses `(entry_S-11)>>8`; descriptor3E/3C use `(entry_S-5)>>8`, all after word wrap. This follows literal accumulator high-byte retention across byte-sized LDA instructions. Six queued low-byte defaults are26=00,27=FF,30=02,31=31,2E=02,23=30; seeded high bytes are preserved.

All96 continuous original calls pass, comparing full WRAM outside active caller stack, final X, seven ordered HDMA submissions and caller restoration. Fixtures cover three caller stack pages, four resource owners, seven/eight available channels, real/synthetic table payloads and randomized shadow seeds. Original C18B applies setup defaults; original8CA6 releases resources and queues cleanup defaults; a second C18B applies those defaults. All seven acquired channels are released, and a preoccupied channel7 remains owned by its original owner. Explicit services also exclude their caller scratch1F80-1FFF. Normal8D1A message/animation composition, resource exhaustion and physical timing remain open.

## Title row colour and animation

[V] `tools/boot_buffer_animation.py` recovers8B15-8B5C and8B5D-8BA4: for each nonzero buffer pointer at42/46/4A/4E, copy the word at7E5DA0/5DE0/5E20/5E60+X to buffer offset4 or7. Source long addressing carries into the next bank. Absolute indexed destination addressing also carries; a pointer nearFFFF can reach bank80's low-WRAM mirror. The routines retain X and caller D/DB/status. All512 isolated original calls pass, with absent/live/edge pointers and source-bank carry.

[V] The complete8BA5-8CA5 row animation increments byte63 with wrap. Ordinary rows wait1, set scroll5D toFFF8 and perform eight wait8/increment steps. Counts26..2A compare auxiliary46+4 to7E5E1E: equality switches bytes52-pointer+3 toFF and54-pointer+3 to00 and follows ordinary scrolling; inequality expands a row from index01A0 into buffer+80 and performs32 forward colour steps (wait2 each), incrementing the scroll every fourth step. Count2B sets those two control bytes00/02, waits1 twice with scroll resets, performs32 reverse colour steps and expands from index019E afterward.

All256 incoming counter bytes compare against continuous original8BA5 execution at2,377 wait boundaries and final return. Original8B00/A814/ABE7, scheduler/receive and row/colour callees all execute. Matching timer records are preloaded, pause bit40 is cleared and other ready tasks are absent; the model preserves scheduler ownership, saved frame pointer and message release effects. Full WRAM outside caller scratch1F80-1FFF, each wait argument and restored caller state agree. Empty-queue concurrency, progression while paused, the complete8D1A task and physical timing remain open.

Matching assembly sources for these three routines join the six buffer routines in `src/boot/`. Independent ca65/ld65 assembly reproduces all1,093 bytes exactly; `make verify-source` and `data/source_build.json` record this separate reconstruction result. No full ROM build or high-level-decompilation percentage is claimed.

Matching source reconstruction has expanded from1,093 to13,954 bytes across166 independently assembled boot routines. These include title control, task/record/heap/timer operations, input readers, display/copy/transfer queues, VRAM/palette/graphics resources and the complete previously modelled image coefficient/colour pipeline. `data/source_build.json` confirms each source/result fingerprint and exact comparison against the original decoded boot program. Assembly receives no original ROM bytes as inputs. This remains matching assembly reconstruction; full compressed-ROM recomposition, assets and the rest of the game are unfinished, so no whole-game decompilation percentage is inferred.

The ABAD body extent was corrected from63 to58 bytes: ABE6 is its RTS and ABE7 is the adjacent supplied-delay entry. Its zero-record branch shares the epilogue atAC3F. Blocks are checked for overlap before assembly/counting. The former transfer-pass91B8 source gap is now closed by the separate frozen `boot_dma_descriptor_pass` proof:788 original calls,110426 instructions and153/153 own starts, including actual immediate-width evidence at92BC. Its305 decoded bytes independently assemble exactly; the original `boot_dma.py` report remains historical and unchanged.

The newer complete DMA-pass adapter also compares full CPU/context, ordered IO and actual PPU/WRAM DMA data effects, including zero-byte-count64KiB transfers and destination selectors0..7. External forced-blank, vertical/blank and residual bus inputs are explicit. This closes the standalone pass's tested ABI and source; physical timing, scanline HDMA rendering and unrestricted continuous IRQ workloads remain separate. See boot-dma-descriptor-pass.md for the exact input domain and immutable evidence.

The ROM decompressor is now reconstructed as four ca65 sources spanningC14C00-C14CE4: six shift-selector distance masks, the42-byte stack-execution loop template, the144-byte setup routine and the37-byte token reader. The setup copies and patches the loop banks/entry point; the token reader consumes a lookahead byte before checking the output end, reads backreference distance operands and discards three return-address bytes at termination. These sources also assemble as one contiguous229-byte component; every byte matches the supplied USA ROM. Block and component counts are deduplicated.

The matching-source total is14,183 bytes:13,954 expanded RAM bytes and229 direct ROM bytes, including six numeric mask bytes. No expanded RAM bytes are added to the ROM-coverage numerator. `tools/rom_progress.py` audits report/manifest/source/ROM hashes before adding direct-ROM source ranges as matching-source evidence, distinct from execution-verified regions. Full ROM recomposition, assets and complete code decompilation remain unfinished.

## Reconstructed startup sources

[V] `tools/boot_startup.py` models C14D0F initialization: disable interrupts via4200, force blank via2100, set RTI bytes at0104/0100, clear4200..420D, set4201=FF and decompressC77C00 into7E8000. The cold/native entry selectsAF0B; the warm entry selectsAF28. Both reset S to01FF and DB to zero while retaining incoming D. Cold00:8004 enters native mode through CLC/XCE and selectsC10010.

All36 original calls pass (12 each cold/native/warm), comparing full WRAM outside temporary stack0180-01FF, ordered hardware writes and final target/S/D/DB/E/M/X. Original decoder/template code executes with randomized initial WRAM and incomingD/DB. These probes stop before the decoded program executes; they do not establish live PPU/APU reset timing.

Seven startup/wrapper sources add115 direct ROM bytes. The324-byte integrated loader/decompressor and12-byte entry-wrapper components match exactly, alongside the standalone cold-mode trampoline. AD75 initialization and994D scene-release sources add194 RAM bytes but retain `documented_executed` status because their complete callee semantics are not yet modelled. Source assembly alone does not upgrade those claims. The matching-source total is14,492 bytes across179 blocks (14,148 RAM/344 ROM, including six mask constants).
## Verified full inactive sprite/group initialization (2026-10-16)

The fresh source-prefix/declaration/A961/CD50/B42B composition matches original execution through7ECD63:10,117 instructions,18,337 instruction fetch bytes and all6,829 ordered WRAM writes, including2,016 low-WRAM writes. All128 inactive sprite publications and32 groups complete. Three physically produced MVN/RTL generations account for13 pairs/52 dynamic fetch bytes/3,101 copy writes and retire through real returns. Full CPU17, WRAM, SRAM, hardware and primitive telemetry match; only native instruction steps differ. CPU/code input remains declared, with no whole-boot or active-sprite claim.

Root retained review: `data/frontier_b42b_full_pool_v3_root_retained_result_review_20261016.json`; independent peer: `data/frontier_b42b_full_pool_v3_retained_result_independent_peer_20261016.json`. Preserve the completed attempt. Current native accounting:157 calls,150 successes,seven diagnostics;154 measured calls/1,259,353 known instructions plus three unmeasured historical calls. This adds no source/documentary bytes.
