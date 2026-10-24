# Target casting presentation transfer

This delivery reconstructs two complete native routines used by the still-open
C18707 casting coordinator. It does not claim completion of that coordinator,
spell damage, coroutine callbacks, or live rendering.

| Entry | Instruction bytes | Readable model |
|---|---:|---|
| C187C2 | 214 | CastCoordinator.target_transfer |
| C1CA4F | 9 | CastCoordinator.target_palettes |

The two entries add 223 instruction bytes. Their graphic and palette callees
reuse previously reconstructed sources and receive no additional byte credit.
C186DA is the interior of the existing C186D1 presentation selector, entered
with the spell/level pair already in A; the local method preserves that contract.

C187C2 first clears target pending fields E121/E108, including on its early
returns. F1 bit7 suppresses transfer; an active event also suppresses its owning
actor (D4 for heroes, 3A for enemy actors). Otherwise the routine takes effect
type E109 and packed spell/level E10A/E10B from the target, loads the actual ROM
graphic planes, selects the spell's presentation record, and publishes the
palette and E060=C0 casting state. It saves position/motion/effect fields into
E128/E129/E12E/E124/E12A/E134/E122 before clearing motion and initializing the
presentation fields. Effect type7 is converted into a special vertical offset
FFC0 and its active type is cleared. The final palette copy uses the target's
actual E0FA destination and ROM table C1F600.

C1CA4F performs the existing C1CAAC effect-palette restoration for Y while
preserving the caller's X and Y. Deferred boss mode can skip the actor palette;
weapon palette restoration follows its separate active flag. The final NZ
flags come from restoring Y, rather than from the palette-copy result.

## Evidence and domains

`data/actor_cast_coordinator.json` records 384 complete native comparisons:
192 calls per entry. `data/actor_cast_coordinator.coverage.json` contains 631
PC/M/X states for the full call chains. Every invocation runs original ROM
instructions without hooks. Comparisons include all WRAM outside 129 temporary
caller-stack bytes, A/X/Y/C/N/Z/V/M/X-width, S/D/DB and static peripheral state.
No NMI is required by these two call chains.

Fixtures use D=0, DB=7E, M8, X16, binary arithmetic and 12 aligned actor slots.
All four transfer gates are exercised. Fixtures sample 99 actual ROM spell
indices and the 16 level nibbles with high-bit variants; the gate cases suppress
some graphical transfers, so this is not an exhaustive spell/level cross-product.
The effect7 branch, active/inactive actor and weapon palette restoration, and
deferred palette suppression are exercised. E0FA/E0F8 destinations are bounded
to valid palette cache locations. Arbitrary actor offsets and invalid palettes
remain outside this domain.

## Next dependencies

C181F2 (83 bytes) restores a previous target effect, and calls C00033 (a real
three-jump/RTL no-op chain) or C0001E → C03F94 before C1CA4F. C03F94 requires
CPU/register composition of the existing complete event request models:
`event_request_native.request` covers ids0000..07FF;
`event_transition_native.command` covers all request formats throughFFFF.
C03F94 masks its event to0FFF, so both models apply. Memory-only reuse is
insufficient because event requests change A/Y and preserve their caller's
flags/context.

C18D12 performs actual spell-hit resolution via C00054 → D04C82 → C8E6D4;
its reflection logic and full spell handler still need native composition.
C18C96 additionally calls C0E328/C0E351 sprite publication and C10038 → C13B3C.
The latter runs real object coroutine callbacks through its ROM dispatch table
and four callback slots. An empty queue or suppressed-target fixture cannot
close these dependencies or justify claiming all of C18707 decompiled.

## Joint movement/child/attack integration: 2026-10-09

Adds1,338 independently reconstructed instruction bytes and68numeric bytes in24sources/5contiguous components: rebound/landing236, parent-linked child81, target animation180, descriptor1 decisions359, cast target transfer/palette223 andattack selection/caller-unwinding259. Complete original no-hook proofs3584/4896/6144/8192/384/2176calls respectively. Numeric velocity pairs, state roots andanimation ids are regenerated explicitly from proven models andcompared toROM. Parent-mode termination is consumed byactual pool; its6000animation-disabled domain stays separate fromnormal2800animatedframes. Landing compareswrappedheight−32 withoutstoringpositive decrement. Bothnative PLA caller exits preserve realreturnword A. Descriptor1 HPphase andRNGaborts retainliteral A/C. This doesnot closeC18707,all boss scripts,state engine,animation advancement,full live scheduling orcompleteROM reconstruction.

All 1,405 blocks/274 contiguous components independently assemble andmatch. Sources85,704,instructions83,066,numericdata2,638,RAM14,148/ROM71,556. Documented ROM union817,320/2,097,152=38.97285461425781% remainsa separate lower-bound metric; full code percentage null/rebuildfalse.
