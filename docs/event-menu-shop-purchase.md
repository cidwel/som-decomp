# Native complete shop purchase callback

C07AD1/47 composes the real confirmation loop, reads the selected item from the original shop list, resolves price and affordability, invokes complete inventory insertion, deducts actual persistent money and publishes the numeric window twice before showing the purchase notice. Cancel, insufficient money and inventory capacity failures retain their literal native paths. C07B00/13 is the sound/numeric publication helper; C07B0D/5 and C07B12/5 select the actual error messages and tail into the frozen notice loop.

Smoke2 and the first full8 passed without model or fixture changes: a real shop0 purchase, cancel, insufficient money, capped consumable quantity, full armor inventory, direct sound/window publication and both errors. Shop0 comes from the real D8:FB80 pointer table and its item list; geometry/descriptors/window buffers come from the complete producers. The positive purchase traverses94 real vblank frames, inserts Candy and deducts10 money. Complete text/render/input/palette/audio/NMI/RTI and all native dependencies remain composed, without hooks or empty success guards.

All26/26 own instruction starts and widths are observed,2,406 distinct PCs and407 dependency hashes unchanged. Full WRAM/CPU/context/peripherals match, with discarded ordinary call frames excluded by the observed watermark while caller context/DMA remain compared. Four bodies total70 candidate new instruction bytes with no manifest overlap at preparation. The full buy public-entry loop, sale and upgrade service remain separate open compositions.

Integration spec: `event_menu_shop_purchase_check:EventMenuShopPurchase:event-menu-shop-purchase:event_menu_shop_purchase`.

## Frozen hashes

- `tools/event_menu_shop_purchase.py`: `9b8732afd5f23722becd263b3973ee8e43193d1d582f920899d6176d34f197ac`
- `tools/event_menu_shop_purchase_check.py`: `3ed88e6c9c664dc70eb08e5bf4c48a9e64bae5f177a4262498f5e20f9579096b`
- `data/event_menu_shop_purchase.json`: `394c085d7564e22ab20d13a5e7c898d622fcf3ed22f98cf05509c7ff75b26dee`
- `data/event_menu_shop_purchase.coverage.json`: `d9905c42deae3ec18d16bd013662f510e5d3b370134e8ceadc51796b9e669ce5`
- `data/event_menu_shop_purchase.source_audit.json`: `ce825d1f93ac552fced00a29f5b0de78a49b1bc73bef2362e1d7ac01fe27c026`
