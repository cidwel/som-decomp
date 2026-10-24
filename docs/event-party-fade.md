# Party command world-fade requests

[V] `tools/event_party_fade.py` closes the full native `$C1EB63` entry for
selectors three and four, through the actual `$00BC01` fade request and
`$C1E9C4` event end. Both set destination coordinates `$0D80/$0D80`; the request
mode is respectively `$02` or `$84`. The model retains index-width changes,
accumulator residue, binding flag clears and literal cursor wrap.

The 4,608 original calls compare full CPU, WRAM including exact nested call
frames, SRAM and hardware. Both incoming M/X widths, all CNZV, three data banks,
four cursor boundaries and three terminal binding values are covered, with no
hooks or masked stack window. Every start in the new 47-byte source body and
its M/X widths are observed. `data/event_party_fade.json` freezes this evidence.

This proves issuing and returning from the request, not rendered fade timing.
Selectors zero through two, six, restart and remaining party operations still
need their own complete coordinator proofs. Previously reconstructed shared
entry, fade leaf and event-end instructions receive no duplicate byte credit.
