# Native spell arithmetic composition

This block upgrades nine existing reconstructed arithmetic/handler routines
from numeric or selected-field checks to complete CPU and WRAM contracts,
preparing their reuse by C8E6D4/C8E7A7 spell dispatch. Existing matching assembly
sources already account for their instruction bytes; this block adds **zero
new byte credit**. The full spell entry, other effects, reflection and C18707
coordinator remain open.

| Entry | Existing instruction bytes | Readable method |
|---|---:|---|
| C8E855 | 57 | spell_stat |
| C8E8A0 | 32 | spell_element |
| C8E8C0 | 208 | magic_attack |
| C8E990 | 79 | magic_defence |
| C8E9DF | 29 | spell_damage |
| C8E9FC | 109 | reduce_timers |
| C8EA69 | 34 | divided_level |
| C8EA8B | 12 | standard_damage |
| C8EBB3 | 23 | cure_water |

All 583 existing bytes receive complete native composition evidence. C8E855
uses the hardware remainder of spellid/6 to select INT/E1FD or WIS/E1FE.
C8E8A0 checks resistance before weakness and publishes multiplier1/4/2.
C8E990 performs the actual additive RNG and magic-evasion rolls, including
word wrap, defense caps and the complete C05437 percentage helper.
C8E8C0 preserves the literal byte overflow of power+stat and level+2, uses the
full C054B2 multiplication helper, rolls accuracy and the caster E1E6 bonus,
then multiplies by the element, divides by target count in hardware, and caps
the result. Scratch fields, arithmetic ports and final A/high byte/flags are
part of the model, rather than inferred only from pending damage.

C8E9DF applies a signed minimum-one difference before adding it to pending
E1F1 with word wrap. C8EBB3 separately queues E1F3 healing with multiplier4.
C8EA69 performs actual unsigned target-count division, including the SNES
zero-divisor quotientFFFF. C8E9FC implements both timer reset branches and
the five-timer reduction loop; only the reduction branch sets E1B1 bit04.

The model deliberately retains divisor0 as one hardware boundary alongside
1/2/3/255. Divisor0 does **not** bypass these handlers or claim closure of the
C8E7A7 branch that returns before dispatch when its target count is zero.

## Native evidence

`data/actor_cast_spell_hit.json` records 1,152 complete original native calls,
128 per entry. `data/actor_cast_spell_hit.coverage.json` contains401 PC/M/X
states across their original call chains. Every native invocation has an empty
hook map. Comparisons include all WRAM outside129 temporary caller-stack bytes,
all modeled CPU registers/status bits, S/D/DB and static peripheral state.
Dependencies are recorded by SHA256; the ROM and CPU fingerprints are in the
coverage file. No ROM bytes or asset payload are included in these reports.

Domain: D0300/DB7E/M8/X16/binary;12aligned actor slots;42actual ROM spell rows;
levels0..8; multipliers1/2/4; target divisors0/1/2/3/255; evasion0/1/50/99/255;
defense0/1/999/FFFF; pending and subtraction wrap/equality boundaries; additive
RNG indices0..14 and randomized RNG state. Inputs are sampled, not an exhaustive
spell/level/state cross-product. No NMI or audio call is present in this block.

## Next composition

C8E88E and the status/Saber/buff/drain/Revive/transform/Analyzer/Dispel/Wall/Lunar
handlers must use their real status, notices, RNG, rebuild and audio paths.
C8E6D4's bookkeeping and C8E7A7 dispatch can then compose these handlers for all
42spell ids. D04C82 supplies reflection and C18D12 delivers effects to targets.
C18707 additionally needs the entity/coroutine callbacks documented in
`docs/actor-cast-restore.md`; those remain open.

## Joint restoration/descriptor/child integration: 2026-10-09

Adds924matching instruction bytes and14numeric pointerbytes in21new sources/4contiguous components: cast restoration208, descriptor2 callbacks280, linked-child strip lifetime436. Complete original no-hook proofs1152/9216/4736calls pass, including actual event-request/attribute-rebuild paths, inactive-party X residue, child allocations/RNGaborts andsix request handoffs, persistent collapse/sound/64tick hiding/reset. The sound proof compares5680ordered CPU/APU writes under supplied acknowledgement timing; it doesnot claim SPC playback. All native aliases andscratch/state stores are retained literally.

SpellHit additionally upgrades583already matching arithmetic bytes acrossnine routines to full CPU/WRAM/peripheral contracts,1152original calls, withzero newbyte credit. The catalogue now selects the stronger proven model while preserving predecessors. Divisorzero remains a hardware boundary, not a bypass of full spell dispatch. C18707/fullspellhit/reflection/entity callbacks, later handed-off child programs andcontinuouslivegameplay remainopen.

Joint assembly verifies1,426blocks/278contiguous components. Sources86,642,instructions83,990,numericdata2,652;RAM14,148/ROM72,494. Documented ROM union818,252/2,097,152=39.017295837402344% isseparate fromcode decompilation;fullcode denominator null/ROMrebuildfalse.
