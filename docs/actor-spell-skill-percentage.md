# Native spell-skill percentage query

`SpellSkillPercentage` reconstructs public JMP entries C00063/3 and C0384B/3 plus C0419C/103,109 instruction bytes. Twenty-two original calls passed on the first capture, executing1,185 instructions and covering all58 own instruction starts/PC/M/X states. All378 captured tool dependencies were revalidated unchanged. Full WRAM/SRAM, CPU/context/status, hardware, menu/NMI and ordered audio match outside the observed native stack without hooks.

The real consumer is C76619's spell-label construction: its actor offset and skill position select a packed E1C0 nibble, while its input byte is multiplied by99 through SNES hardware. The nibble selects one of sixteen denominators at C043AC; the native routine then divides the product and returns the low quotient byte. The model preserves the literal M8 final read and accumulator B byte, returns the native clobbered X/Y and restores incoming D/DB/P. It does not replace native division behavior with a floating-point ratio.

Directed cases cover skill indices0..15, even/high and odd/low nibble paths, actor offsets0/0200/0400, input0/1/99/255 and both public wrappers. The sixteen-byte historical consumer view is independently assembled with ca65/ld65 and byte-identical to the ROM. Its last five bytes overlap existing C043B7 instructions: B9 00 E0 C9 01. Only the preceding eleven bytes receive new typed-data credit; indices11..15 literally read those neighboring instruction bytes as divisors. The full16-byte proof and audit remain frozen, without duplicate source credit. No graphic or text assets are credited.

Frozen evidence: `data/actor_spell_skill_percentage_proof.json`, `.coverage.json`, `_audit.json`; numerical proposal and independent assembly: `data/actor_spell_skill_percentage_numeric_manifest_proposal.json`, `_numeric_audit.json`. Integration specification: `actor_spell_skill_percentage_proof:SpellSkillPercentage:actor-spell-skill-percentage`.

The percentage API contract is closed within native binary M8/X16 spell-label inputs. The complete C76619 caller, item/spell page constructors and interactive menu remain separate reconstruction blocks.

Source acceptance: 109 new instruction bytes are integrated and independently assemble to the original ROM. The joint checkpoint is `data/source_checkpoint_20261010_attack_entries_skill_shop_inventory.json`. Only eleven denominator bytes add physical data source; the remaining five observed bytes belong to the already recovered neighboring instruction body and add zero bytes.
