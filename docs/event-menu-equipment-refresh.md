# Native equipped sprite and stats refresh

C07699/46 reads the selected equipment field and updates the sprite selector while clearing pose offsets. The original intermediate computes twelvefold arithmetic but PLA restores the fourfold value before the ROM lookup; the reconstructed model preserves that literal result. C07A28/44 executes the existing complete public C00036 stat rebuild and caps persistent mana against the rebuilt actor maximum, preserving the original status and data bank.

Smoke2 and first full4 pass: direct/weapon-palette-alias sprite fields and mana cap/retain branches. Three valid classified hero records and aligned actor indices supply the stat-rebuild ABI. Full WRAM/CPU/context and peripherals, including real arithmetic latches, match without hooks. All48/48 instruction starts and widths are audited,570 distinct PC addresses captured,239 dependencies unchanged. No existing manifest overlap for90 bytes; the stat rebuild contributes zero duplicate credit. Equipment ownership transactions and full menu dispatch remain open.

Integration spec: `event_menu_equipment_refresh_check:EventMenuEquipmentRefresh:event-menu-equipment-refresh:event_menu_equipment_refresh`.

## Frozen hashes

- `tools/event_menu_equipment_refresh.py`: `b8a8c1bcaa9ee89ec4bfe726531bd996f1267c056423f02221872f2a40e2ecb6`
- `tools/event_menu_equipment_refresh_check.py`: `7a8b34bbdad0acd9a1b7ded5d48120ec7453bb20885fe4d1fa18ec0cbc5959d4`
- `data/event_menu_equipment_refresh.json`: `884dfe039ec2bed2d69ce97f785fdfdd54e07a2c74fc53e07e9f4bd4f9bd3029`
- `data/event_menu_equipment_refresh.coverage.json`: `f2f7cc9ecfd2dde2211e6e92043866bd6d46f5d81715c61569a5c234c4195670`
- `data/event_menu_equipment_refresh.source_audit.json`: `0263dcf0c55be782c6726da82bf6c9d0283ef8c5b1ef247439fb8c53675fb6f6`
