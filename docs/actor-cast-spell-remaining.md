# Remaining spell effects and combat notices

This block closes complete native CPU/memory contracts for Analyzer, Dispel,
Lunar Magic and their message/formatting dependencies. Integration found three new matching sources: C05921(62),C05BA4(18) and
C05BB6(10), adding90instruction bytes. The other listed sources are reused
without duplicate credit.
C8E88E row-status preparation is reused from the stable SpellEffects block.
The C8E6D4/C8E7A7 full entry/dispatch, reflection and C18707 remain open.

| Entry | Existing bytes | Routine |
|---|---:|---|
| C8EC00 | 59 | resolve_analyzer_spell |
| C8EDCB | 236 | resolve_dispel_spell |
| C8EEF5 | 36 | resolve_lunar_magic_spell |
| C8EF2B | 29 | lunar_magic_full_heal_living_actors |
| C8EF48 | 22 | lunar_magic_set_all_target_buffs |
| C8EF5E | 22 | lunar_magic_set_all_target_debuffs |
| C8EF74 | 22 | lunar_magic_confuse_actors |
| C8EF8A | 22 | lunar_magic_weakness_actors |
| C8EFA0 | 22 | lunar_magic_slow_party |
| C8EFB6 | 26 | lunar_magic_freeze_enemies |
| C8EFD0 | 22 | lunar_magic_shrink_actors |
| C8EFE6 | 10 | lunar_magic_halve_caster_maximum_mp |
| C05921 | 62 | enqueue_new_spell_buff_notices |
| C0599D | 226 | enqueue_analyzer_actor_stats_and_weaknesses |
| C05A7F | 8 | change_previous_message_to_analyzer_style |
| C05BA4 | 18 | enqueue_lunar_magic_effect_notice |
| C05BB6 | 10 | enqueue_wall_expiration_notice |
| C05C6C | 89 | format_word_into_combat_message_digits |

Analyzer's objectEA route multiplies rowE1CA by5, reads the actual ROM threshold
and writes only the low byte of maximumHP when its level succeeds. The other
route constructs actual queue records for HP/MP, monsterEXP/gold and weaknesses.
Its PHX/PHY restoration really reverses incoming X/Y, matching the native
instructions. Style30, dynamic actor-name tokens, count/tail wrap, runtime ROM
text, temporary DP fields and multiply ports are included in the model.

Word formatting C05C6C retains its repeated signed subtraction and overlapping
word digit stores, rather than using Python decimal formatting. Values at and
above32768 are tested as literal machine behavior, not claimed to display
correct human decimal values. Byte formatting reuses the complete C05C38 model.
C05921 shifts each new buff bit in descending order and builds the actual
name/text queue records, preserving its high-residue and final flag effects.

Dispel reproduces full-reset guards, damage-derived timer reductions, signed
byte Saber/Wall timer subtraction, conditional attribute rebuild and Wall notice.
Lunar Magic invokes the actual additive RNG with bound8, queues its effect name,
and executes the selected real handler. C8EF19 contains nine pointers, but the
native bound8 selection reaches indices0..7; index8's halve-maximumMP helper is
validated independently through its real direct entry. The nine helpers cover
living actors'full healing, all buffs/debuffs, six-actor Confuse/Weakness/Shrink,
party Slow, enemy Freeze and the ninth maximumMP reduction.

## Native evidence

The report records4,608 complete original calls,256 per each of18 entries;
coverage contains1,501 PC/M/X states. All calls execute actual ROM instructions
without hooks. Comparisons include all WRAM outside129temporary caller-stack
bytes, fullA/X/Y/C/N/Z/V/M/X-width, S/D/DB, static peripherals and ordered APU
writes. This block emits zero APU writes in its fixtures and does not claim an
independent new sound-branch proof. No NMI is required.

Domain: D0300/DB7E/M8/X16/binary;12aligned actors;42actual ROM rows;level0..8;
divisors0/1/2/3/255;RNGindices0..14;valid message count/tail/reverse-tail cursors;
hero/ordinary/boss and sprite>=83guards;literal word-digit boundaries0/1/9999/
32767/32768/FFFF. All256input weakness/newbuffmasks/elementalobjectrow values
are supplied, but guard correlations suppress some paths, so this is not a
claim that every mask executes every message path. Analyzer normal/objectEA
branches and all Lunar direct helper entries execute. Dispel reset/reduction,
Saber/Wall timer zero/signed edges, rebuild and notice branches execute.
Inputs sample combinations rather than exhaust the state space.

Dependency and coverage hashes match current files. ROM text is read only at
runtime; reports and documentation contain no assets or encoded message payload.

## Next whole-hit chain

D04DCD progress and D04E6E spell-grade lookup must compose C05B75's actual magic
level notice and C03989 sound. Then C8E6D4 bookkeeping and C8E7A7 can dispatch
all42canonical spell rows through these closed handler bodies. Reflection
D04C82 and C18D12 target delivery follow. Sprite/entity coroutine dependencies
remain required before closing C18707.
