# Native spell effect handler composition

This block reconstructs the complete CPU/memory composition of25 existing spell
handler entries. Their matching assembly sources already exist, so these proofs
add no new instruction-byte credit. The C8E6D4 entry, C8E7A7 dispatch, reflection,
Analyzer/Dispel/LunarMagic and C18707 remain open.

| Entry | Existing bytes | Routine |
|---|---:|---|
| C8E88E | 18 | apply_spell_row_status |
| C8EA97 | 12 | resolve_speed_down_spell |
| C8EAA3 | 5 | resolve_ice_saber_spell |
| C8EAA8 | 5 | resolve_thunder_saber_spell |
| C8EAAD | 5 | resolve_flame_saber_spell |
| C8EAB2 | 5 | resolve_stone_saber_spell |
| C8EAB7 | 5 | resolve_moon_saber_spell |
| C8EABC | 3 | resolve_light_saber_spell |
| C8EB04 | 28 | resolve_speed_up_spell |
| C8EB20 | 25 | resolve_defender_spell |
| C8EB39 | 27 | resolve_acid_storm_spell |
| C8EB54 | 75 | resolve_hp_drain_spell |
| C8EB9F | 20 | resolve_remedy_spell |
| C8EBCA | 27 | resolve_lava_wave_spell |
| C8EBE5 | 15 | resolve_status_damage_spell |
| C8EBF4 | 12 | resolve_status_only_spell |
| C8EC3B | 122 | resolve_mp_drain_spell |
| C8ECB5 | 28 | resolve_lucent_beam_buffs |
| C8ECD1 | 25 | resolve_lunar_boost_spell |
| C8ECEA | 26 | prepare_first_mana_sword_spell |
| C8ED04 | 79 | resolve_revive_spell |
| C8ED53 | 21 | resolve_wall_spell |
| C8ED68 | 26 | prepare_second_mana_sword_spell |
| C8ED82 | 73 | resolve_change_hp_spell |
| C8EEB7 | 62 | resolve_lucid_barrier_spell |

The six Saber entries execute their shared C8EABF body (69 existing bytes);
that interior body expects an extra saved element byte on the caller's stack,
so the harness enters the real Saber wrappers instead of inventing a standalone
C8EABF ABI. Saber clears its old effect, rebuilds actual attributes, calculates
power with multiplier4, combines weapon element and row status, clears both
Mana Sword timers and publishes the divided-level gauge/duration.

Status spells use C8E88E and the existing general StatusApplication.apply_status
model. This includes its actual filters, transformations, recovery/stat rebuild,
message/program changes and scratch fields, rather than copying only a status
word from the old selected-field spell model. Buff spells retain their exact
bit masks and timer destinations. HP Drain switches to caster defense and
reverses recipient registers when target E192 bit20 is set; MP Drain reverses
its pair for bit40, clamps against the donor's availableMP, and keeps literal
byte wrap of pending MP fields. Both paths are compared in native execution.

Remedy composes timer reduction and actual controller status handling. Revive
checks hero/boss classification, reduces timers, clears death, calculates its
hardware healing fraction, guarantees minimum currentHP1 and clears pending
damage. Wall writes the divided-level reflection count. Mana Sword spells
retain the E1E4=1 guard. ChangeHP retains HP-sum wrap and boss minimum1. Lucid
Barrier stores both maximum-HP-clamped capacity and the hardware quotient's
low byte for physical-defense absorption.

## Native evidence

The report records3,200 complete original calls (128 per each of25 entries),
with1,867 PC/M/X coverage states across the full call chains. No instruction
bypass hooks are installed. The comparison checks all WRAM except129temporary
caller-stack bytes, fullA/X/Y/C/N/Z/V/M/X-width, S/D/DB, static peripherals and
ordered APU writes. These particular fixtures emitted **zero sound-port
writes**; actual sound handling remains in the reused StatusApplication model,
and this result does not independently prove a spell-triggered sound branch.
No NMI is required by this block.

Domains: D0300/DB7E/M8/X16/binary;12aligned actor slots;42actual ROM rows sampled
across each handler;level0..8;divisors0/1/2/3/255;RNGindices0..14;valid ordinary/
hero/boss classifications and message queue cursors;HP and defense word edges;
existing status/immunity/cachedstatus variants;both drain reversal bits;Mana
Sword gate active/inactive. Actual handler entry and row are varied independently
for compositional coverage, rather than asserting every combination corresponds
to a normal game cast. The subsequent dispatcher must verify canonical spell/
handler pairs. Fixtures do not exhaust all valid state cross-products.

All dependencies and harness hashes are recorded and checked against current
files. Reports contain addresses and numeric evidence only, with no ROM/assets.

## Remaining effects

Analyzer C8EC00 uses either its elemental-object branch or the full C0599D
message composition. Dispel C8EDCB composes its reduction/reset logic, attribute
rebuild and C05BB6 Wall notice. LunarMagic C8EEF5 requires C05BA4 effect notice
and all nine C8EF19 table entries before canonical dispatch is complete.
C8E7A7 additionally calls C05921 to report newly added buff bits. These message
contracts must be reconstructed as actual calls, without message/audio hooks.
