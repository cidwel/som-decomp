# Native shop money operations

C07C86/31 tests whether persistent24bit money covers the selected16bit price, returning X=1 only when both low-word subtraction borrows and the high byte is zero. C07D0D/39 deducts the selected price with the literal high-byte borrow; C07D34/79 credits it with high-byte carry and caps at9999999 ($98967F). The functions restore their saved price in A and preserve the native final carry behavior. The original does not reinterpret a high-byte wrap as an arbitrary precision integer.

Smoke2 and first full9 passed: insufficient/sufficient low/high money, deduction with/without borrow, credit carry, high-byte cap, equal-limit cap and just-below-limit credit. All67/67 instruction starts and exact widths are observed,67 distinct PCs and287 dependency hashes unchanged. Complete WRAM/CPU/context and all peripherals compare without hooks. No dependency body is bypassed. Discarded ordinary call frames use the observed stack watermark, while caller context remains compared.

Three bodies total149 candidate new instruction bytes with no manifest overlap at preparation. Item-price lookup and outer shop transactions are separate pending compositions; this does not close the shop or full menu.

Integration spec: `event_menu_shop_currency_check:EventMenuShopCurrency:event-menu-shop-currency:event_menu_shop_currency`.

## Frozen hashes

- `tools/event_menu_shop_currency.py`: `132fe9968555219e3acd9dfb5909202767157e16fe7b8b34f694094635328537`
- `tools/event_menu_shop_currency_check.py`: `e5297e14459c3a9940f7dc8212096a32d65992704fa42d8b177131a6d619fbad`
- `data/event_menu_shop_currency.json`: `8252d68565f78e677b0ee761d273ffc072005377eb3d4e910052a7d469e49411`
- `data/event_menu_shop_currency.coverage.json`: `98d5f3749cfc5bcd856b6e8e0d776b4a2fddc15115320db39a86b5f129763f01`
- `data/event_menu_shop_currency.source_audit.json`: `8677e5fa439e3a7385fe3c1d5800fe54ddaa43d15b08f6c368a89a57f378ad92`

Source acceptance: 149 new instruction bytes are integrated and independently assemble to the original ROM. The joint checkpoint is `data/source_checkpoint_20261010_controller_shop_attack_palette.json`.
