# Native consumable effects

C054E7 preparation53 bytes and C05536 effects182 bytes reconstruct the original consumable implementation; C0002A/C03812 aliases add6. Thirteen vector words atC0551C contribute26 independently typed numeric bytes, excluded from241 instruction bytes. They cover nine distinct destinations; no ROM or item payload is stored.

All13 produced IDs0..12 execute their real dispatch targets. Healing adds original ROM effect amounts only for living actors; full healing stores maximum HP into pending healing. MP uses original byte wrapping. Cure resets status timers while preserving death, revival restores HP and clears pending damage, and items8/9 retain both status toggle guards. IDs6/7/11/12 retain their original no-effect path. IDs13..15 pass the public mask but lie outside the original thirteen-entry vector and are excluded from the produced domain rather than given invented behavior.

Smoke3 and the first directed19-call capture pass without changes. It includes dead HP/MP guards, both status toggles turning off, three actor lanes, both public aliases, M8/16 and restoration of D0/0300 and DB0/7E. Full WRAM, CPU/context and peripherals match. Audit108/108 starts, exact widths/boundaries,226 dependencies intact. The numeric vector assembles exactly26 bytes independently and reuses this capture for all13 consumers without repeated original execution.

Integration spec: `event_menu_consumable_effects_check:EventMenuConsumableEffects:event-menu-consumable-effects:event_menu_consumable_effects`. Numeric manifest proposal: `data/event_menu_consumable_effects_numeric_manifest_proposal.json`.

## Frozen hashes

- `tools/event_menu_consumable_effects.py`: `f4f7b9169dafa98a345cf413c6ade8542924b00c8e515434ea497632370bcecf`
- `tools/event_menu_consumable_effects_check.py`: `23546e806a2aff0e7630f10729162c70ef58cda5f6c208713bdbdbdb99ef2f52`
- `tools/event_menu_consumable_effects_numeric.py`: `ca149d6c89c00d1e225ee40a933085d3363b989c62d2ea6d56dfc8c33c7d9bf3`
- `data/event_menu_consumable_effects.json`: `32282469de43e832c47eb64897c9fc060d40be326162419cef74b4fa6bbf0c09`
- `data/event_menu_consumable_effects.coverage.json`: `d9c189e503a74a58f75dab0cf22b007069da0ac15cb6b93bf68e0f6db31b1e7e`
- `data/event_menu_consumable_effects.source_audit.json`: `40c0768b7d7845e156d4771e58eda34b6cf93cf45470caad20ed00c3dd2963d2`
- `data/event_menu_consumable_effects_numeric.json`: `8a28015d0a8dc679a58e921df3b655efcf5242726a040ea3da7904ca899a2813`
- `data/event_menu_consumable_effects_numeric_manifest_proposal.json`: `f985c9a1b3e48eea559c5b75da7c395cd390f3d5fcdd050d281cd4add8fad8b6`
- `src/rom/native_consumable_effect_jump_targets.s`: `8462faf418aca267c964d5dd9df30508f028d8863ed8b149e4f87c930044a5c4`
