# Wall reflection and complete target hit delivery

D04C82 and its public jump chain now compose the complete C8E6D4 spell entry, real Wall reflection and actual reflection message. C18D12 composes this hit contract with target graphics transfer and previous-effect restoration. C18707 remains open because its sprite/entity coroutine chain is still being reconstructed.

| Entry | Candidate instruction bytes | Role |
|---|---:|---|
| D04C82 | 252 | Complete hit or Wall reflection |
| C00054 | 3 | Public jump |
| C0383C | 3 | Internal jump |
| C03866 | 4 | Native long jump |
| C0595F | 49 | Unique reflection notice |
| C18D12 | 110 | Deliver cast hit to target |

The six candidate ranges total421 bytes. Actual new credit is established by integration against existing matching sources; prior dependencies receive no repeated byte credit.

Wall honors dead hero bookkeeping, bypass spell IDs20/23/26, the caster's three recipient IDs and byte charge consumption. Zero initial charges wrap to255 literally; a decrement to zero clears the Wall bit. The real RNG chooses a three-candidate permutation, using the opposite hero/enemy pool. Each candidate must be active, living, outside flag30 and allowed by ED. Native signed absolute differences,16bit distance wrap and the strict distance<240 comparison are preserved. Exhaustion executes the full original spell hit, while a successful redirect returns candidate X and low A=FF with the caller's saved status/context.

The notice scans eleven original queue slots for an active record whose flag at1D is1. An existing record returns immediately; otherwise it allocates the actual reverse queue record, marks its reflection field and copies runtime ROM text. The twelfth slot is deliberately outside this native duplicate scan.

C18D12 retains ED/enemy/inactive guards, saves caster/target around the real hit, and returns redirect candidate A with carry set when reflection succeeds. Ordinary hit results set pending target spell fields; zero/40 state transfers immediately, C0 restores the old cast first, and other states defer transfer after recording the caster. C181F2/C03F94 events, attributes and palettes and C187C2 graphics/publication run through their actual readable contracts without bypasses.

## Native comparison

10,336 complete calls passed:2,016 each for the four reflection entries and C18D12,256 for C0595F. Coverage contains3,594 PC/M/X states, including successful redirection, both signed coordinate differences, all three candidates rejected and fallback, Wall exhaustion, previous-effect restoration and immediate/deferred transfer. All42 canonical spell IDs are actually dispatched. This fixture batch emits zero APU writes; ordered sound transcripts are compared, and the separate Dispatch proof exercises420 actual writes.

Comparison covers all WRAM outside129 temporary caller-stack bytes, fullCPU A/X/Y/C/N/Z/V/M/X-width, S/D/DB, peripherals and ordered APU writes. Original instructions run with zero hooks and no NMI. Domain: X16/binary,12aligned actors,42ROM spell rows, levels0..8, divisors0/1/2/3/255, bounded queues/palettes/RNG. Reflection wrappers vary both M widths, D0/0300/1234 and DB7E/42/7F; direct C0595F uses D0300/DB7E/M8, and C18D12 D0/DB7E/M8. Charges0/1/2/255, inactive/dead/flag30/ED rejects, signed coordinate and distance239/240/241 edges are sampled, not exhaustive combinations.

Dependency hashes and final coverage/tool hashes match. No ROM assets, tables or message payloads are saved.

## Next frontier

The global sprite chain can reuse native HUD, ordinary actor and shadow models and the real boss emission contracts, with new caller/workspace/ordering composition. C10038 still requires real entity heap initialization/allocation, construction, callbacks and scheduling; these are not replaced by empty nodes or fake completion tokens.
