# Previous cast restoration and event request composition

`CastRestore` reconstructs the target restoration C181F2 and follow-up
coordinator C03F94, including their native public jump chain and unused
completion stub. The spell-hit and coroutine dependencies of C18707 remain
open; this delivery does not close that coordinator.

| Entry | Instruction bytes | Model |
|---|---:|---|
| C181F2 | 83 | restore_target |
| C03F94 | 108 | finish_previous_cast |
| C0001E | 3 | public jump to C03806 |
| C03806 | 3 | internal jump to C0385E |
| C0385E | 4 | long jump to C03F94 |
| C00033 | 3 | unused completion public jump |
| C0381B | 3 | unused completion internal jump |
| C0385D | 1 | unused completion RTL |

The candidate span totals 208 instruction bytes before integration checks for
existing matching sources. C04000's four-byte context epilogue, C0395E context
normalization, C8E5FB attack-row selection, C04530 attribute rebuild, C1CA4F
palette restoration, and all event request/snapshot helpers are reused and
receive no additional byte credit.

C181F2 temporarily switches to target Y and its previous caster E10C. A type1
previous effect invokes the real C00033 stub, whose entire native chain returns
without changing registers or memory. Other types invoke C03F94. The routine
then preserves the original actor pair, restores target palettes, and restores
saved E01C/E05D/E104/E106/E006/E008/E05E fields. Its intermediate E008=FF byte
write is subsequently overwritten by the saved word E122, as in the ROM.

C03F94 normalizes combat coordinates into D0300/DB7E and reverses source/target
registers through C0395E. It clears E1F8 for both actors. A recipient with E1FB
bit10 records the previous caster's spell in E181 and submits its own masked
E03E event request. Otherwise spells20/23 can activate the Mana Sword when both
CC78 and CC79 are active: the previous weapon is saved in CC77, E1E8 becomes11,
attack selection and the full attribute rebuild run, then event8 is requested.
The final C04000 epilogue restores status, DB, and D; its final NZ derives from
restoring D, while A/X/Y retain callee results.

The event-request composition calls the existing independent readable memory
models `event_transition_native.command` and `event_request_native.request`.
Its register contracts follow the actual C1E753 wrapper, not a bypass: status,
X, D and DB are preserved, but A and some paths' Y change. Busy numeric requests
return the event-state byte; deferred requests return the pointer's high byte
with low1; newly started requests return A28FF and the actor animation-cache
index in Y. Map requests return the destination table word's high byte with
low40 and Y0090; scroll requests return A0300/Y0090; fades return the destination
word's high byte with low81/Y0201. Guarded and reserved formats retain A/Y.

## Validation domain

The report records 1,152 complete native comparisons (128 per each of the
eight listed entries plus128 public C18000 calls); coverage contains1,435
PC/M/X states. The harness compares complete original native calls without hooks against the
independent model. All WRAM is compared except 129 temporary caller-stack bytes,
with full A/X/Y/C/N/Z/V/M/X-width, S/D/DB and static peripheral state. The entries
include complete original event requests, full snapshots and cached actor
position updates, actual palette copies, Mana Sword attack selection and
attribute rebuild. No NMI is required by this block.

C181F2 uses its native D0/DB7E/M8/X16/binary calling convention. Public completion
and event entries additionally vary both accumulator widths, three D values
(0,0300,1234), and three DB values (7E,42,7F). Actor references use 12 aligned
slots and bounded palette destinations. The fixtures cover three event states,
all event request path classes, guarded fade conditions, the unused stub, and
Mana Sword completion. Numeric event ids and transition ids are sampled here;
existing request harnesses supply their broader id-domain evidence. This is
not an exhaustive state cross-product or a claim about subsequent event execution.

## Remaining coordinator dependencies

C18D12 needs the real C00054→D04C82 reflection/hit chain and C8E6D4's entire
spell handler. C18C96 additionally publishes sprites through C0E328/C0E351 and
calls C10038→C13B3C. C139CD constructs a temporary spell entity and selects seven
specific presentation types, rather than merely reading an empty queue. It
calls allocation/entity helpers C13BD3/C143F1/C14161/C1280F/C12896/C12997/C12EEC/
C139A1/C13D48 and later cleanup C13D7D. The dispatch table C13B2E maps seven types
to C12BE8/C12C06/C12BF7/C12800/C12EDD/C12C06/C14801. C12FE4 waits for a real
scheduler token at WRAM8230 and increments/decrements8232 around that wait.
A noncallback spell fixture cannot close these paths.

## Joint restoration/descriptor/child integration: 2026-10-09

Adds924matching instruction bytes and14numeric pointerbytes in21new sources/4contiguous components: cast restoration208, descriptor2 callbacks280, linked-child strip lifetime436. Complete original no-hook proofs1152/9216/4736calls pass, including actual event-request/attribute-rebuild paths, inactive-party X residue, child allocations/RNGaborts andsix request handoffs, persistent collapse/sound/64tick hiding/reset. The sound proof compares5680ordered CPU/APU writes under supplied acknowledgement timing; it doesnot claim SPC playback. All native aliases andscratch/state stores are retained literally.

SpellHit additionally upgrades583already matching arithmetic bytes acrossnine routines to full CPU/WRAM/peripheral contracts,1152original calls, withzero newbyte credit. The catalogue now selects the stronger proven model while preserving predecessors. Divisorzero remains a hardware boundary, not a bypass of full spell dispatch. C18707/fullspellhit/reflection/entity callbacks, later handed-off child programs andcontinuouslivegameplay remainopen.

Joint assembly verifies1,426blocks/278contiguous components. Sources86,642,instructions83,990,numericdata2,652;RAM14,148/ROM72,494. Documented ROM union818,252/2,097,152=39.017295837402344% isseparate fromcode decompilation;fullcode denominator null/ROMrebuildfalse.
