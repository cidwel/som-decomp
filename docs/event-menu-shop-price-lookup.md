# Native shop price lookup and affordability wrapper

C07CA5/47 masks the item ID to a byte, searches the four descending native category records (consumables186, accessories165, bodies144, heads123), resolves the price pointer and delegates the existing full C07CD4 price adjustment. C07C7B/11 saves the original item, resolves/adjusts its price, tests persistent money and restores the entire original accumulator. Lookup/money X and native flags remain literal.

Smoke2 and first full9 passed: all four category boundaries, a real non-sale item192 with priceFFFF, double-buy and fractional-sell adjustment, and sufficient/insufficient money wrappers retaining A's upper byte. All30/30 instruction starts and widths are observed,86 distinct PCs and288 dependencies unchanged. Full WRAM/CPU/context and hardware division peripherals match without hooks; discarded ordinary call-frame bytes use the observed stack watermark, with caller context retained.

The item domain is the four real shop groups,123..197 as represented by their original category records and prices; inputs below123 are not produced by those groups and run beyond the native range table. No sentinel outside that table is treated as a fifth valid category. Tables remain read from the original at runtime; no price payload was exported. Existing C07CD4/57, its hardware division and the complete currency helpers receive zero duplicate source credit.

Two bodies total58 candidate new instruction bytes with no manifest overlap at preparation. Buy/sell/service callbacks and the complete interactive shop remain open. Integration spec: `event_menu_shop_price_lookup_check:EventMenuShopPriceLookup:event-menu-shop-price-lookup:event_menu_shop_price_lookup`.

## Frozen hashes

- `tools/event_menu_shop_price_lookup.py`: `143ffc26c978e9e8f1fa184573cf8d451bb647f762f38a998d19073e011d8a27`
- `tools/event_menu_shop_price_lookup_check.py`: `e3288af94bbe515451bf1bd112aec93d7854b92a3df942aefb9d2a54defc18a7`
- `data/event_menu_shop_price_lookup.json`: `b9d1abc2738b615854cd40885a9b6a1ba6dcd40acc71377de449973c29c9c224`
- `data/event_menu_shop_price_lookup.coverage.json`: `f8984993f9cfc7c78da518a2462e4a00c40be21c3ff0955d177266ff91822bf8`
- `data/event_menu_shop_price_lookup.source_audit.json`: `c3d419b80067e6158a9d3f48dc96d69daed2aa91c575e60b852b7175ee049d74`

Source acceptance: 58 new instruction bytes are integrated and independently assemble to the original ROM. The joint checkpoint is `data/source_checkpoint_20261010_controller_shop_attack_palette.json`.
