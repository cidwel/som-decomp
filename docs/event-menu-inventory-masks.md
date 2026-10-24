# Native inventory status and availability row masks

Ten reconstructed bodies cover 313 candidate bytes: D9FCBD/4 public wrapper, FCC1/79 mode/category dispatcher, FD2C/26 weapon owner-state test, FD46/35 hero-status mask, FD69/25 global or per-slot dispatch, FD82/98 armor owner/special-item logic, FDE4/24 per-slot status masks, FDFC/1 actual category return, FDFD/11 current-Y row marker, FE08/10 disabled-flag writer. Inline FD10 category pointers/masks and FE12 slot masks are data, excluded from code credit.

Smoke 3 passed. First full capture failed at trial 8 solely because the mutable model incorrectly updated N/V on immediate BIT. The original immediate instruction changes Z only. After correcting those two BIT sites, exact replay 8 and the complete 23-call capture passed. No frozen dependency changed.

The directed cases cover all seven categories, mode3 cooldowns, hero status4, global/per-slot status, weapon state, armor ownership and special-item branches, plus direct helper contracts. Tables are read from the original ROM at runtime. Full WRAM outside observed stack, CPU/context and graphics/input/audio peripherals match without native hooks.

Primary audit observes 141/147 instruction starts, with nine source bodies recovering exactly. FD82 lacks FDA2/A5/A7/AB/AD/AF and the immediate-width state at FDA2: its special-item branch for a nonzero hero was not covered. A separate two-call supplement (hero1, slot1 present/FF) is prepared. The independent two-call supplement passed without changes. Union evidence now observes **147/147 instruction starts**, all ten exact boundaries and immediate widths, in 158 PC/M/X states. Complete audit is `data/event_menu_inventory_masks.complete_source_audit.json`; all guard dependency hashes match. Primary model/checker/report/capture remain frozen. All 207 dependency hashes match.

Integration spec: `event_menu_inventory_masks_check:EventMenuInventoryMasks:event-menu-inventory-masks:event_menu_inventory_masks`; supplemental validator `event_menu_inventory_masks_guard.py`.

CF9C descriptor composition and the complete interactive menu are separate unfinished contracts.

## Primary frozen hashes

- `tools/event_menu_inventory_masks.py`: `4d0b54f1bf0a6247979734561fd2343516a4d1d2c07c687da2fe09d89022e515`
- `tools/event_menu_inventory_masks_check.py`: `87f8dd81b42a2dfc1a4feb2aedde7be68bf4170fac5d649e270d9883751591b7`
- `data/event_menu_inventory_masks.json`: `f14249af4bdd5d2393941931b254732fa7d5fdf27fcdaf190e1f8fc781431039`
- `data/event_menu_inventory_masks.coverage.json`: `a59edeac76107484f8c5c234ce38fdcbb251961f50c967591ac5e5d5f31e21f8`
- `data/event_menu_inventory_masks.source_audit.json`: `73df68c791cd5e5076b43d91a1bf9393b00059686371d751cb725ce4a9f8488e`
- `tools/event_menu_inventory_masks_guard.py`: `b18648125ac7f449ff812d68e405d464046e7d0acf9affb7f53cfcb1340c47d1`
- `data/event_menu_inventory_masks_guard.json`: `fecbc9767edbaa3a63160aa0187dc11087eaf0bc7861921a9318a4b8cb8c7a8d`
- `data/event_menu_inventory_masks_guard.coverage.json`: `7a3db4b8ce39f0415d1d12afbc6244e5f73dc7aff384f1a957c0a8ef6a79ab12`
- `data/event_menu_inventory_masks.complete_source_audit.json`: `1ce281b3306fe35e40680a8ca41cb2de94ba832135c36ab4545b027ce0a9fd5a`
