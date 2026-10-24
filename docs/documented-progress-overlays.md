# Reviewed Documented Progress Overlays


`data/documented_progress_overlays.json` registers independently reviewed,
hash-pinned proposals. `tools/documented_progress_overlay.py` composes them over
the existing audited base in memory and writes only `data/documented_progress.json`.
The root integrator remains responsible for public headers and global adoption.
Neither `data/progress.json` nor `data/rom_regions.json` is rewritten.

## Current combined checkpoint

After the 2026-10-16 batch 2 source integration (ledger entry 13, record), the documented union covers **1,513,728 / 2,097,152 bytes (72.1802%)**; 583,424 bytes remain unknown. The audited base is 1,287,390 B (61.3875%) and the overlays add 226,338 B; 8,383 integration bytes were already overlay-documented and are not double counted, 14,175 bytes are new documentation. The 470,177 added source bytes of element type `unclassified_rom_bytes` are matching source without semantic credit: they are excluded from the base and from the union (`tools/rom_progress_semantic_20261016.py`, entry 13 pins their exact mask).

Previous checkpoint: after the 2026-10-16 three-batch source integration (ledger entry 12), the documented union covers **1,499,553 / 2,097,152 bytes (71.5043%)**; 597,599 bytes remain unknown. The audited base is 1,264,832 B (60.3119%) and the overlays add 234,721 B; 226,746 integration bytes were already overlay-documented and are not double counted. See rebase record.

Previous checkpoint: SOURCE11/documentary26 covered 1,496,378 / 2,097,152 bytes (71.3529%); 600,774 bytes remained unknown. The latest2,606-byte admission adds one46-byte produced frame and two separate1,280-byte palette domains. It adds no matching source or instructions. Scope and evidence, current checkpoint. All earlier admission sections retain their historical scopes.

## Validation And Policy

The wrapper calls `rom_progress.build(rom, reuse_audited_regions=True)` directly.
The existing loader checks the intact non-source inventory and recursively hashed
tool/table inputs. Current source files, manifest and assembled ROM bodies are
validated by the base builder. No helper is imported into the base/cache dependency
graph. No cache refresh, assembly, old CPU proof or native C21CCF execution occurs.

Proposal, extent report and native evidence/review have explicit registry pins.
All three must match the ROM, verification flags, zero source credit and linked
extent report hash. The extent/native reports' direct semantic dependency hashes
are checked, without executing their tools. The existing audit cache separately
validates its own recursive input graph.

Historical `rom_regions.json`, source-build, manifest and progress
hashes are snapshots, not requirements that future source inventories remain
identical. Their reviewed/current hashes and equality are recorded separately.
In particular, the native proof's catalogue snapshot is not regenerated or
compared as a new native result. Each extent-report compiled-source pin must still
have the same address, size and compiled-body hash in the current verified ROM
build; source-text semantic dependency pins must also remain intact. Source
inventory updates do not invalidate a proof, but changed reviewed source text
requires a fresh semantic review rather than silently accepting a stale pin.

Every base region uses its actual offset, count, stride and fields. Each overlay
row must be a canonical physical interval: `status=documented`, `count=1`, positive
stride, one field at offset zero whose size equals the stride, in ROM and reviewed
scope bounds. Its ROM interval hash and report interval metadata must match.
All coverage is byte union, so overlapping fields, rows, base coverage or multiple
overlays never double-count. Per-overlay gain is measured against the base plus
earlier registered overlays; total gain is independent of registry order.

The wrapper hashes base catalogue, progress, cache, its recursively pinned inputs,
source build, manifest and source files before and after validation. Changes during
validation fail before writing. `--check` validates the stored combined report
without writing. Reports contain base metrics, hashes and only overlay region
metadata, not a copy of the base region definitions. Source and existing
execution-verified counters are copied unchanged from the validated base.

## Reviewed C1 Scope

The initial overlay adds 2,849 documented format/extent bytes in three physical
intervals: `014D80,015018)`, `[0150C0,0158C7)` and `[016138,0161BA)`.
See `docs/local-c1-documented-extent-20261014.md` for the original producers,
conditional retention guard and independent native comparison.

Successful original allocation, the existing source-selected frame path and
retention of actor98 mask0004 clear until C21CCF are required. This is not an
uninterrupted gameplay witness. The synthetic mask0004-set branch receives no
additional credit. Original payload loads are M8; fetched equals consumed bytes,
with zero lookahead. No padding, adjacency or unknown gap is included.

At initial C1 integration, the base union was 1,016,937 bytes. Its gain was 2,849 bytes,
giving **1,019,786 / 2,097,152 = 48.627185821533203125%** documented coverage.
Source credit is zero; the base's 532,495 matching-source bytes and 66,765 total
source blocks (66,117 ROM blocks) stay unchanged.
These are documented lower bounds, not completed decompilation percentages.
Future valid base updates can reduce overlay gain through overlap without
invalidating the reviewed extent.

## Reviewed Audio Scope

The `native_audio_transfer` overlay adds 176,784 previously uncovered bytes in
92 intervals: counted source headers/transport reads for 59 songs and 33 samples.
Its independent review explicitly uses hash-revalidated cached native loader/SPC
comparisons, not new executions. See `docs/local-audio-extent-review-20261014.md`.
Song sign-test overreads are transport reads, not proof of logical song grammar;
BRR END classification is static and does not establish DSP hardware playback.

Reader kinds are explicit in the registry. The C1 kind requires its original
mask0004-clear producer qualification; the audio kind requires the qualified
cached-native review, exact finite song/sample domains and intact cached reports.
Unknown kinds fail rather than bypassing either review.

Current combined union is **1,434,031 / 2,097,152 = 68.37992668151855%**:
base 1,033,735 plus 292,346 reviewed overlay bytes after the exact control-source
rebase below. The six-overlay union remains 1,313,733 bytes. Matching sources are
549,377 bytes / 80,285 blocks; instruction
bytes remain 217,923. Existing execution-verification counters remain unchanged;
this is not a code-completion percentage or permission to export asset payloads.

## Qualified Admission Union

The explicit `qualified_admission_union` reader binds the frozen independent
report `data/review_scale_union_20261014.json`, its proposal and its review tool.
Classification is `qualified_raw_tile_and_name_batch`; evidence mode is
`independent_admission_union`, not a fabricated new native evidence unit.
The 97 canonical intervals add 11,948 net bytes, with no registered overlap.
Member footprints total 12,588 bytes, but 608 low/high and 32 low/NPC bytes overlap.
Both member masks and combined masks, interval ROM hashes, guard memberships,
selected proposal masks, all critical inputs and compiled source pins validate.

Each output member points to `/members/<index>/review_metadata` in the exact
hash-pinned union report and records its canonical metadata hash. The reader
compares the complete frozen member metadata with its independently pinned review,
including the low immutable prior review. This preserves every per-case qualifier,
source/native pin, admission limit and held profile without copying giant evidence
members into the public metric. Children, recovery, fill/events and normal768 are
component evidence already included in the union, never additional overlays.

The low accounting addendum supersedes only the old helper-hash batch hold.
Low05 count3 and unit230 remain held; low09 count3 requires original initializer
completion and retained tail. Count5/6 unconsumed words earn no credit. Hero0000
AD count3 and original name54/55/56 holds remain. NPC83 palette and A7 velocity
producer holds remain. Actual-record identity, allocation, latest writer/resource
epoch, controller/prefix, buffer/padding, separate uploader API and name/window
retention guards are binding. No authentic event history, uninterrupted encounter,
full scene, NMI, PPU/display, whole namespace or complete CPU equivalence is proved.

Only adoption-time registry/output snapshots and the unchanged pure
`coverage`/`require`/`check_hash`/`sha` AST closure receive their explicit accounting
qualification. The original six-overlay registry is canonically pinned and its
occupancy mask is rechecked. Apart from the exact source rebase below, every other
critical input remains an exact current hash requirement; historical member differences must match the frozen report's
exact owner/path/hash tuples. No CPU, producer, native or source-code hash waiver,
native replay, assembly or source credit is introduced. The previous 16 matching
header bytes are unknown-role metadata already in the base, not new semantic credit.

## Exact Control Source Rebase

`data/overlay_rebase_controls13566_20261015.json` records only the ROOT-adopted
`data/recon_controls13566_integration_20261015.json` transition. It is not a generic
source-growth waiver. The receipt pins the prepared 11,051-row proof, manifest
proposal, adopted source build, manifest and persistent physical build. Its source
authority is the existing reviewed semantic compression-control proof; its code
authority and all frozen producer/CPU/source-body pins remain unchanged. No new
documentation or instruction credit comes from this wrapper.

The authenticated historical files are under
`~/.local/state/som-decomp/verified-baseline-20261014-header16/`: `binding.json`,
`source_build.json`, `manifest.json`, `build.json`, cached verification and image/mask
artifacts. The source-build and manifest hashes must equal the frozen admission
pins, including the previous 16 unknown-role header bytes. Every old block must
remain exactly identical in the current build, not merely retain a source filename.
The base builder still hashes every source body and verifies original ROM slices.

Only the proof's exact new addresses, sizes and hashes may be added, all as ROM
data: 13,566 bytes and 11,051 blocks. The exact old catalogue snapshot is reconstructed
by removing these matching-source regions; its serialized SHA-256 must equal the
frozen `rom_regions.json` pin. Subtracting only the same data/ROM/total-source and
region counters reconstructs the old serialized `progress.json` snapshot, whose
SHA-256 must also equal its frozen pin. This authenticates historical snapshots
without rewriting them or rerunning the old audit.

Subtracting the exact new control mask from the current base must recover the
1,016,953-byte historical field mask, SHA-256
`f7940c44a1a71af8115e854e9ca028956f52c25ed2bdf24fa524f321de41d7a7`.
The controls must be disjoint from that base and entirely inside the already
reviewed six-overlay union. Its exact old count and mask remain required, as do
the final 1,325,681-byte mask, member qualifiers and original admission gains.
The new persistent physical image/mask must differ from the header16 build only
at these controls; decoded images/masks must remain identical.

The only replaced current critical pins are source build, manifest, catalogue,
progress and recovered-build verification, each validated through this exact
transition. Every other frozen pin stays strict. Rebase evidence is hashed again
at completion. Base/cache inputs, registry, native proofs and public headers are
not written. The output records both historical and current pins and masks.

Actual source counters are 546,077 total bytes: 523,153 direct ROM and 22,924
decoded RAM; 328,154 typed data and 217,923 instructions. Persistent reconstructed
physical ROM coverage is 539,006 bytes, including previously reconstructed encoded
resource bytes; it is not interchangeable with direct source coverage. Documented
coverage is unchanged at 63.213396072387695%, not completed decompilation.

## Commands

```sh
python3 -B tools/documented_progress_overlay.py --self-test
python3 -B tools/documented_progress_overlay.py "ROM_PATH" --write
python3 -B tools/documented_progress_overlay.py "ROM_PATH" --check
```

Self-tests cover overlapping multistride fields, duplicate overlay union, zero
overlap gain, interval/artifact hash tampering, invalid geometry/status and every
member's frozen metadata keys, including inherited low holds. They read pinned
evidence but perform no native execution or filesystem edits. Rebase regressions
reject missing, changed or replaced old source blocks, unrelated base additions,
removed historical bytes, controls outside reviewed overlays and instruction
additions. Run with
assertions enabled, as required by the existing audited base validator.

## Projectile source adoption — 2026-10-15

The append-only ledger now records the actual 1,152-byte / 820-block projectile
03..0B adoption after the 13,566-byte control batch. Each append binds the exact
prior five snapshots, proof, proposal, adoption receipt, new snapshots and both
persistent builds. The independently approved canonical entry hash is pinned in
the validator. Original source rows and decoded images remain unchanged; only
the exact reviewed ROM data delta is accepted. The documented union stays
1,325,681 bytes: these controls were already inside the reviewed overlays.

`data/recon_projectiles_03_0b_actual_append_review_20261015.json` records the
independent review. The six ledger regressions and original negative qualifier
checks pass. The original control self-test reads its pinned historical snapshots
after append, rather than expecting the current manifest to remain at one entry.

## New documented source controls — 2026-10-15

The fourth actual source receipt adds 24 functional controls previously outside
the reviewed documentary union. Its independently reviewed authority pins the
exact proof/proposal, both semantic admission reports and fourteen canonical
intervals. The validator requires those intervals to equal the selected source
mask minus the preceding documented union, preserving the original frozen
1,325,681-byte mask exactly. The current union is 1,325,705 bytes.

This source-only documentary addition is separate from the seven historical
overlays and adds no instructions. Sources are independently assembled and
compared by the adopter. The nine regression tests cover new-documentation
pin/mask/count/source tampering as well as old source/receipt invariants.
See [the authority design,
`data/session_controls24_actual_append_review_20261015.json` and the fourth
entry in `data/overlay_source_rebase_ledger_20261015.json`.

## Source adoption inside existing base fields — 2026-10-15

The fifth receipt adds 84 matching dialogue-control bytes in 59 sources that
were already documented by the base catalogue itself. Source bytes increase
84, base documented bytes increase zero, and the complete documented union
remains 1,325,705. Physical reconstruction increases 84 after exact new-source
assembly and comparison. The canonical entry explicitly pins base delta0,
overlap84 and the exact overlap mask. Without this opt-in the original
no-overlap guard still rejects the batch. Existing old source ownership,
source/proof/ROM hashes, historical base masks and physical0→1 additions all
remain checked. The twelve regression tests include wrong/missing overlap
approval and physical source ownership conflicts.

`data/frontier_text84_fifth_ledger_review_20261015.json` validates the complete
chronological five-receipt chain independently. Its 84-byte source gain does
not become new documentary credit or instruction credit.


## 2026-10-15: actual controls376 source and documentary adoption

The sixth chronological source receipt adds 376 independently assembled ROM
control bytes in 45 sources: actor0088 words32, four produced cache sentinel
arrays308, sound request low bytes23, and linked-effect timer/collision13.
Every selected byte lies outside the prior base and reviewed documentary union;
the exact new documentary mask is authenticated by
`data/session_new_documented_controls376_authority_20261015.json`.
The graphical exclusion includes the newly reached CABE70 frame and 669 boss
frames. Sound high bytes are excluded because the handler discards them; linked
frame graphic headers, pieces and script pointers are likewise excluded.

`data/frontier_controls376_sixth_ledger_review_20261015.json` independently
approves the actual receipt chain and masks. The canonical sixth entry is
`37a055dbbfc799229f791c60fcc7483d43aea5270ad00e01d6b3cf7fba80d749`.
The unchanged strict no-overlap path applies to these376 bytes; the earlier
text84 base-overlap exception is not needed. All four historical guard ASTs,
source bodies and old CPU proofs remain intact. Write/check/self-tests and all
twelve ledger regression tests pass without old native replay or reassembly.

Current base is1,033,735; combined documentary union1,326,081(63.23246955871582%).
Matching sources are549,377 bytes in80,274 blocks; instructions remain217,923.
These guarded functional-source admissions do not establish a complete game
trajectory or a whole-code decompilation percentage. Earlier dated sections
retain their historical totals. Current checkpoint:
`data/session_checkpoint_20261015_codex_source549377.json`.


## 2026-10-15: explicit graphical-alias12 withdrawal

A later authentic map418/descriptor9 source composition produces linked mode4,
animation6 and sprite frameCABE7A. Its regular header and four pieces consume
CABE7A..CABE8B, including all twelve newly admitted collision bytes. Root reproduced
the producer independently and another agent checked every retained source hash.
The original669-frame admission did not include this new effect6 producer and
was insufficient. Its historical authority is preserved with an explicit correction.

The seventh canonical ledger entry
`ad0d80ec7ede9bad1e163d8ad15eacf3d87b5494c4dcc58a8bc3bec5da0cb357`
removes that one12-byte source from the active manifest/cache/sparse mask and
withdraws exactly its original new-documentation region. The retired source file
remains immutable for historical checks. No source was reassembled, no native
proof replayed and no image/decoded byte outside that interval changed.
`data/session_effect6_alias12_withdrawal_integration_20261015.json` records the
actual correction; `data/frontier_effect6_alias12_seventh_ledger_review_20261015.json`
independently approves the whole chain. The source count is549365, base1033723,
and reviewed documentation1326069. New documentation since the initial frozen
1325681 union is388bytes. All16 regression tests and original-ROM write/check/
self-tests pass; no whole-code denominator or completion claim follows.

The fresh target-control role exclusion additionally includes table modes0/3/4
conservatively and the authentic effect5/6 producers. Those first-frame additions
bring the finite boss-frame inventory to672. This is a finite known-role review,
not a proof excluding every future runtime-generated address.


## 2026-10-15: active0-current12 actual adoption after correction

Entry8 adds twelve different source-produced target01E5 LOW controls, preserving
all per-field activeparty0/nearest-found/status/control/A9/identity/allocation
retention premises. The reader advances one byte after an M16 fetch; the high
lookahead belongs to the next command and is not credited. The fresh finite
role review has1323 normal and672 boss frames, including all linked mode-table
first frames as explicit conservative exclusions. Conditional producer/read scope
does not establish a complete scene or twelve actual gameplay fetches.

`data/session_active0current12_integration_20261015.json` records actual assembly
and reference verification; new documentation authority24ec8bbe... fixes exactly
the twelve new bytes outside the corrected prior union. Entry8 is
`ccebc8cdc273a31cc75dd4dbbc562729232967fc64f306ae5e5bb58493ce929e`.
The seven-entry correction remains intact and CABE7A..85 stays unknown in the
active sparse mask. Although total source549377 and documentation1326081 equal
the earlier pre-withdrawal numbers, their byte masks, manifest hashes and block
counts differ: current80,285 blocks versus historical80,274. The historical
checkpoint is not rewritten. Current evidence:
`data/session_checkpoint_20261015_codex_source549377_active0current12.json`.
All16 ledger tests, original-ROM documentary write/check/self-tests and the
independent actual8 chain pass without old native replay or old source assembly.


## C6 consumed resource formats, 2026-10-15

The independently reviewed C6 overlay adds exactly57,022 previously undocumented
bytes:48,702 consumed RLE bytes,8,192 packed-nibble bytes and128 fixed attribute
bytes. Its three exact intervals exclude unknown tails and copied template bytes.
The RLE API requires program bank00 and its retained WRAM template, with the
original two word patches; the packed constructor has its separate device/API
qualifications. Cached952 row and336 constructor comparisons were revalidated
without replay. No source, instruction, scene or rendering credit is added.

Frozen authority: `data/session_c6_resources57022_overlay_admission_20261015.json`;
helper simulation: `data/frontier_c6_overlay_helper_simulated_review_20261015.json`.
Current base remains1,033,735; current combined union is1,383,103. Earlier dated
source checkpoints and their documentary totals remain historical evidence.


## Conditional actual-record NPC raw resources, 2026-10-15

The new independently reviewed NPC authority admits129 source-model profiles
from actual record selectors, yielding23,936 new bytes in209 exact intervals.
Its69 identities retain their constructor-selected fields and frame-produced
pointer buffers. CreationED.N1 and phase0 uploaderED00 remain separate declared
APIs with explicit caller gates and field retention. Cached native proofs bind
algorithms and their API domains; this adds no129-profile native comparison or
continuous gameplay history. The historical normal768 qualifier is unchanged.

The actual original-ROM write/check/self-tests and27unit tests pass. Base
coverage1,033,735 and source549,377/80,285 blocks remain unchanged. The actual
combined documentary union is1,407,039/2,097,152 (67.09284782409668%).
Receipt: `data/session_npc23936_actual_adoption_review_20261015.json`.


## Conditional hero-status icons, 2026-10-15

The separate reviewed authority adds1,920 bytes in20 exact intervals. Literal
hero original IDs80..82 and conditional status inputs (bit15clear, otherbits
free) derive sixteen appearances and64 packed descriptor reads. Original ID
and kind must remain intact until the status API, and published appearance
until the separately declared icon API. This does not prove an upstream status
writer or continuous initializer/status/HUD history. Cached69632icon,656status
and6initializer comparisons remain historical algorithm evidence. No source or
new native credit is added. Actualwrite/check and33unit tests PASS; current
checkpoint: `data/session_checkpoint_20261015_icons1920.json`.


## Conditional spell D4 converter inputs, 2026-10-15

Seven original initializer APIs produce ten literal resource headers. Their
retained header count/source fields feed the synchronous three-plane converter,
consuming5,040 new bytes in six exact intervals. Existing native algorithm proofs
are revalidated; no per-header original comparison, upstream spell selection,
IRQ/gameplay history or rendering claim is added. Dynamic projection pointers
F8E7/FE82 are excluded. Actualwrite/check,39unit tests and281self-regressions PASS.
Checkpoint: `data/session_checkpoint_20261015_spellD4_5040.json`.


## Odd-count subsets and synchronous weapon0 inputs, 2026-10-15

Two separate authorities add4,960 and1,536bytes. Odd28 includes only frame-produced
pointer words that the original paired uploader actually reads; four residual
words per profile remain excluded. Weapon0 documents the exact24-byte-per-tile
input to a synchronous64-tile constructor conversion, without any uploader join.
The E1A8 slot clear produces highE1E4zero; the later identity path preserves it.
Actualwrite/check and51unit tests PASS. No source, original execution, scene or
rendering credit is added. Checkpoint:
`data/session_checkpoint_20261015_odd4960_weapon1536.json`.


## Actual first-frame command contexts, 2026-10-15

The AB120 and remaining58 authorities add8,992 and4,544bytes. They follow actual
commands before the first literal, retain21 source-produced selector fields and
include only pointer words both produced and actually read by the capped uploader.
Residual words and unread tails remain excluded. Remaining58 uses the C2AEF4
source-copy memory postcondition for112bytes atC700 with a separate constructor
ABI; it makes no register-continuity or C1DC8F history claim. Existing84ABprefix
bytes and25remaining command starts add no instruction/control credit.
Actualwrite/check and63unit tests PASS; source549377/80285 remains unchanged.
Checkpoint: `data/session_checkpoint_20261015_AB8992_remaining4544.json`.


## Actual335 constructor weapon inputs, 2026-10-15

The independently reviewed call-time trace adds15,504 bytes in four intervals.
Each actual constructor call retains its source-produced weapon identity,
64-tile count and D4 pointer through synchronous conversion. The full18,408-byte
input union overlaps existing spell and weapon0 extents, which receive no
duplicate credit. This proves conditional converter inputs; it adds no source,
uploader continuity, gameplay or rendering credit. Actualwrite/check,68unit tests,
274qualifier negatives and7source-rebase negatives PASS. Combined documentation
is1,449,535/2,097,152 (69.11921501159668%); source remains549,377/80,285.
Checkpoint: `data/session_checkpoint_20261015_actualWeapon335_15504.json`.


## Retained finite reader prefixes, 2026-10-15

Two distinct authorities add384+448bytes in seven intervals from four actual-record
reader prefixes of3/3/2/4 complete calls, including each tick0 firstframe baseline.
Retained output hashes connect successive calls. Only produced pointer words read
by the separate conditional uploader API qualify; residual words and unread tails
remain excluded. Finite prefixes add no unbounded animation closure, source or
new original execution credit. Actualwrite/check,74unit tests and281negative
self-regressions PASS. Documentation is1,450,367/2,097,152 (69.15888786315918%).
Checkpoint: `data/session_checkpoint_20261015_retained832.json`.


## SOURCE714 and exact historical documentary reconciliation, 2026-10-15

410new RODATA sources reproduce714 numeric frame-index/descriptor/directory/collision
bytes. All original sources, LOW owners and old18 documentary authorities stay
unchanged. The default index retains its E041/E040 override. Exact ledger9 validates
the714 source-mask gain and permits66 owner/path/digest historical resolutions
only for three aggregate objects; compiled producers, ROM, source/model/CPU
dependencies stay strict. The ledger documentation prior is1326081, distinct from
the actual18 union1450367. These714 bytes are new to both. Actual11 tests,write/check
and281self-regressions PASS; source550091/80695, base1034449 and combined1451081
(69.19293403625488%). No new instructions or native execution. Checkpoint:
`data/session_checkpoint_20261015_codex_source550091_encodednumeric714.json`.


## Actual335 encoded frame consumer inputs, 2026-10-15

Entry19 adds5,028 bytes in163 intervals:220header,3288tile and1520coordinate
input bytes. The original775-byte reader consumes5,956 bytes across335 qualified
source-produced firstframes. Existing SOURCE8 controls214 and SOURCE9 metadata714
are excluded, as are70 host-only HIGH lookahead bytes. Seventeen original width
sites and232 producer pins stay strict; default-index E041/E040 override is retained.
This credits conditional encoded input formats, with no graphical payload export,
source, per-profile original execution, scene or rendering claim. Actualwrite/check,
six current contract tests, seven candidate tests independently repeated, and281
self-regressions PASS. Current union1,456,109/2,097,152=69.43268775939941%; source
550091/80695 and ledger9 unchanged. Checkpoint:
`data/session_checkpoint_20261015_encoded5028.json`.


## SOURCE429 actual source and numeric documentation, 2026-10-15

Actual SOURCE10 is promoted and write/check/self-tests pass:550520sourcebytes,
80980blocks,217923instructions unchanged,1034878basebytes and1456538combined
reviewed bytes (69.45314407348633%). Five actual contract tests pass; development
separately passed23 candidate tests,8 staged contract groups and independent17+6
reviews. SOURCE429 assembled only285 new RODATA files once:127 default frame-index
HIGH bytes,65 descriptor words,79 directory words and14 collision bytes. Default
index fetch retains the E041/E040 override; all127 LOW owners and all80695 prior
compiled rows remain identical. No native execution or asset export was added.

The exact ten-entry ledger preserves the old66 SOURCE8 accounting resolutions and
adds only8 owner/path/digest edges for the original nineteenth SOURCE9 documentary
entry. Its ledger9 archive is separate from the exact five prior snapshots. All
live source/model/ROM and compiled four-field pins remain strict. Newsource429 is
disjoint from both full documentary19 (1456109) and ledger-reviewed prior1326795;
these two denominators are independently reconstructed rather than interchanged.

The assembly's original prepared proof lacked rich cache/ROM fields. Both original
and final objects remain immutable; an acyclic reviewed authority permits only
selected-proof hash changes in cache/build, consequent verification/receipt pins
and four added per-row fields checked against original reader hashes, genuinely
compiled rows and ROM. No old proof was rewritten or old sources reassembled.

Checkpoint: `data/session_checkpoint_20261015_codex_source550520_retainednumeric429.json`.
Approval: `data/frontier_source429_stage10_final_promotion_review_20261015.json`.
Binding: `data/frontier_retainednumeric429_postassembly_20261015_binding_authority.json`.
The separate1961encodedgraphic+12640RAW documentary candidate remains unadopted
until its fresh SOURCE10 admission and helper receive independent approval.


## Documentary14601 actual twentieth entry, 2026-10-15

Actual registry20 and helper3125f320 are promoted; original-ROM write/check,
274+7 self-tests and8 actual contract tests PASS. The union is1471139/2097152
(70.14937400817871%): base1034878 plus436261 overlay bytes. Source550520,
80980blocks,217923instructions, SOURCE10ledger and sparse artifacts are unchanged.
The new entry contributes1961encoded graphic inputs and12640conditionalRAW inputs
in107intervals. Numeric429, host-only lookahead, failed partial calls and RAW
residual/unproduced/unread tails remain excluded. These are335 authentic retained
contexts with79958complete source-model calls, at most256TOTAL each; no exhaustive
animation, native-per-profile, uploader/DMA/scene or whole-game claim is added.

The full775-byte/17-widthsite encoded reader and separate ED00 RAW cap8/16 packet
order intersected with currentframe-produced4*countwords retain distinct guards.
Every1265compiled producer4pin and all fresh2227dependencies stay strict; only
four exact preflight historical accounting snapshots are authenticated. The full
new registry entry (including qualified scope) and report/proposal/authority are
fixed. External module80333a8d is hashed before exact-file import, recorded as an
explicit result pin and rehashed at completion, without a report/module hash cycle.

Fullsimulation compares all old19 semantic results exactly. Only16 pre-existing
historical registry metadata current_sha fields change f579→0d2127, reflecting
normal registry append. Reviewed hashes and false membership flags stay identical;
no semantic evidence hash or source/producer guard is waived. Separate7 candidate
contract groups and3 independent module-provenance tests passed before promotion.

Checkpoint: `data/session_checkpoint_20261015_retained14601.json`.
See admission details.

## Fixed map patterns and HUD: actual entry21, 2026-10-15

The exact four input intervals add3,004 documented bytes with zero source credit. Actual write/check,274+7 self-tests and8 actual contract groups pass; source550520/instructions217923/base1034878 remain unchanged. The reviewed union is1474143/2097152 (70.29261589050293%). Native E0/binary/D0/DB0/validstack/forcedblank/VMAIN80 and inherited DMA/API premises remain explicit, including conditional E8-lowbit transfer; no arbitrary caller or wholemap-production claim. Padding/RAM/output/lookahead excluded.

Fullsim preserves prior20 semantic results, allowing17 registry-current SHA metadata updates and entry20's independently reviewed append-prefix20 module transition8033→9f. Actual promotion additionally updates3 historical helper-current SHA metadata fields at indices3,4,5; reviewed hashes/false membership and every other result field remain exact. All source/cache/ledger inputs remain unchanged. See admission details and checkpoint `data/session_checkpoint_20261015_fixed3004.json`.

## Map header inputs: actual entry22, 2026-10-15

The new entry adds 7,395 bytes in 58 sparse intervals: 5,851 scroll template bytes, 91 M8 selectors and 1,453 M16 palette bytes. Of these, 5,868 have an actual394-header producer; the remaining 1,527 retain explicit conditional API qualification. No descriptor extension or zero-length fixture is admitted. Actual write/check, 274+7 self-tests and 10 actual contract groups pass, and the written result equals the reviewed full simulation exactly.

The union is 1,481,538 / 2,097,152 (70.64523696899414%); source550520 and instructions217923 remain unchanged. Only eighteen registry-current and three helper-current SHA metadata fields change in prior results; every other old field remains deeply identical. See admission details and checkpoint `data/session_checkpoint_20261015_header7395.json`.

## Object palettes and fixed map/cursor inputs: actual entry23

The new entry adds 7,912 bytes in three intervals: palette rows7,680, background192 and cursor40. Palette DB7E/X16 and map/cursor DB0 contracts remain separate; cursor incomingX8 is mandatory. Palette full-byte API7,680, complete-table subset2,250 and actual-header subset2,160 are distinguished. Actual write/check, 274+7 self-tests and eleven actual helper contract groups passed. The complete output equals the reviewed full simulation.

The documented union is 1,489,450 / 2,097,152 (71.02251052856445%). Sources550520/instructions217923 remain unchanged. All old validator functions and module9f remain intact; prior results change only nineteen registry-current and three helper-current SHA metadata fields. See admission details and checkpoint `data/session_checkpoint_20261015_palette_worldmap7912.json`.

## SOURCE11 numeric source admission: actual verified state, 2026-10-15

SOURCE11 admits33 numeric ROM bytes in28 sources, preserving all80,980 old rows and instruction217,923. Sixteen FE bytes are newly documented; seventeen actual-header scroll selectors transfer from entry22. Registry23 remains unchanged; entry22 retains its7,395-byte extent with gain7,378/overlap17. Current source550,553, physical sparse ROM543,482 (25.915241241455078%), documented ROM1,489,466 (71.02327346801758%). Code percentage remains unknown and full-ROM reconstruction remains false.

Actual write/check,274+7 negative self-tests and nine postpromotion contract groups pass. The complete actual/private JSON comparison differs only in the three historical helper-current SHA metadata fields at overlays3,4,5. Source33 was assembled once privately; actual adoption uses zeroASM/native/recomposition. See admission and provenance and immutable checkpoint `data/session_checkpoint_20261015_numeric33.json`.

## Dialogue and menu inputs: actual entry24, 2026-10-15

Entry24 adds2,720 documented input bytes in three intervals: C67400/432 stripe
patterns, C77169/240 border tile-code/attribute bytes and D2D080/2,048 dialogue
bitmap-plane bytes. Border pairs use separate M8 reads across fifteen cells per
style; they are not M16 loads. Dialogue DB7E/M8/X16 and stripe DB0/M8/X8 APIs keep
separate caller, geometry, buffer and device guards. The full24-column stripe
extent is source-derived; cached direct native coverage samples seven columns.
No wholemenu/gameplay trajectory or additional native execution is asserted.

Actual write/check,274+7 self-tests, fifteen documentary and nine SOURCE11 contract
groups pass. Whole actual output equals the captured V6 private result5d32ac5a.
The V4 ordered-prefix serialization failure and V5 generic historical-helper-edge
failure remain preserved. V6 reuses the captured actual23 baseline; all prior23
semantics are identical except twenty registry-current and three helper-current
SHA metadata leaves, with reviewed hashes and false membership flags unchanged.

The union is1,492,186/2,097,152 (71.15297317504883%): base1,034,911 plus457,275
overlay bytes. Source550,553/81,008blocks and instructions217,923 remain unchanged;
this admission uses zero source credit, ASM, new native/model execution or asset
export. Global code percentage remains unknown and full-ROM reconstruction false.
See scope and provenance and
checkpoint `data/session_checkpoint_20261015_dialogue_menu2720.json`.

## Produced icon, high glyph and fixed menu inputs: actual entry25, 2026-10-15

Entry25 adds1,586 input bytes in19 disjoint intervals under three separate conditional cached-native API contracts:288 produced icon bytes,828 newly documented high-glyph bytes and470 fixed menu inputs. It excludes low-glyph underflow, unselected icon IDs, zero-filled output planes, RAM/VRAM/CGRAM output and DMA endpoints. Source credit is0.

The current union is1,493,772/2,097,152 (71.22859954833984%): base1,034,911 plus458,861 overlay bytes. Source550,553/81,008blocks and instruction217,923 counts remain unchanged. One private candidate build reused the genuine captured24 baseline, then actual write/check and274+7 self-tests plus12 focused contracts passed. Old24 fields remain identical except21 current-registry hashes,4 current-helper hashes and the separately reviewed entry24 validator module pin. The original9cb module remains intact; its successor accepts only the exact reviewed25 extension before the original23/24 checks.

See scope and provenance, checkpoint `data/session_checkpoint_20261015_menu_inputs1586.json` and final validation `data/frontier_menu_inputs1586_actual25_root_final_validation_20261015.json`. No new assembly, native proof rerun, model API or payload export occurred for this admission.
