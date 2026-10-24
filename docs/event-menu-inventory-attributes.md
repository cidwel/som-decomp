# Native inventory row ownership and selection attributes

D0D279/143 reconstructs owner-bit decoding, selected-owner tracking, compact armor indices across FF holes, rotated selection indices and paired row attribute writes. D0D275/4 is its public long wrapper. The helper restores the original registers/status and preserves native scratch writes.

Smoke3 and the first full capture7 passed without corrections. Primary evidence observes80/83 instruction starts, exact boundaries and immediate widths,80PC/M/Xstates and205 unchanged dependency hashes. D0D2F1/F2/F5 are still missing from the primary: the intended negative rotation fixture used slot3 minusoffset3, which reaches zero. A separate one-call supplement withoffset4 is prepared, preserving the seven-call tool/report/capture unchanged. The separate one-call supplement passed first time, reaching D0D2F1/F2/F5. Union evidence now covers **83/83 starts**, both exact boundaries and immediate widths, in 85 PC/M/X states; all 206 guard dependency hashes match. Complete audit is `data/event_menu_inventory_attributes.complete_source_audit.json`. Primary evidence remains unchanged.

Comparison covers full WRAM outside the native stack, registers/flags/context and graphics/input/audio peripherals, with all native bodies executed without hooks. The primary model/checker/report/capture are frozen.

Integration spec: `event_menu_inventory_attributes_check:EventMenuInventoryAttributes:event-menu-inventory-attributes:event_menu_inventory_attributes`; supplemental validator `event_menu_inventory_attributes_guard.py`.

The remaining inventory producers/status masks and outer interactive menu are separate unfinished contracts.

## Primary frozen hashes

- `tools/event_menu_inventory_attributes.py`: `d322a200fdab05edf177c213f73ad531c1bc5d22434d04d42add3697cbcfd8a0`
- `tools/event_menu_inventory_attributes_check.py`: `14f271472cbc5eb5cd271612ccce491ee71f0fa447651eb4876a502de6d28751`
- `data/event_menu_inventory_attributes.json`: `7d95251ad57b569bc3da8e32fbcc0e010f9049916caacffb35385b07f7d425ba`
- `data/event_menu_inventory_attributes.coverage.json`: `b367dc61e50fbac02a9d3c2b205e0eb874157b8056799d8c2996a9c94130384e`
- `data/event_menu_inventory_attributes.source_audit.json`: `4f8c7e18792f51a599df3924c579f57a6a1f2a9f435a4858c3cf587ce114fd88`
- `tools/event_menu_inventory_attributes_guard.py`: `98807198d7d5f88e28b4afd2a93c43222ca79ee629e021f956926b5701650621`
- `data/event_menu_inventory_attributes_guard.json`: `7b037fe2a3ef6a1baff144f52cdd3104244cd875d0865e790240d072a7155d53`
- `data/event_menu_inventory_attributes_guard.coverage.json`: `a91ea2d18a4faac48ba86feadf552cd5b0cb4e52e4376ba85446d4f803a551f4`
- `data/event_menu_inventory_attributes.complete_source_audit.json`: `6011b0c218e9db601f986b7ed1fbcb233eb3bda69f7b7bcf2d785b16c328cf9e`
