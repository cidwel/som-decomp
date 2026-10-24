# Complete public buy, sale and weapon upgrade ring services

The three public APIs C00048/C0004B/C0004E and their aliases C06411/C06414/C06417 now enter actual C06617/C0663E/C06653 services. They save PHP/PHB/PHD, normalize the native menu context, resolve the original shop/controller descriptor, initialize text/palette/glyph/ring data and execute the complete C0666F controller/phase loop. Buy/sale/upgrade actions call the full original services. Closing restores the saved party categories, closes the actual dialogue and restores D/DB/P before returning RTL. Empty sale inventory takes the original early public exit.

Smoke2 and the first full7 passed: public alias cancellation for all three services, empty sale, positive purchase/sale/upgrade followed by real input-driven cancellation. Explicit input events contain an idle interval, confirmation/release/new presses and cancellation; original NMI/RTI and all text, ring, inventory, money, status/audio/render transfers execute fully. Positive purchase inserts the original shop item; sale reduces actual quantity; equipped upgrade increases grade and rebuilds the hero. Prior DB7F/D0300/P and the literal long return frame are restored.

All60/60 own starts and widths are observed,5,219 distinct PCs and491 captured dependency hashes unchanged. Ten independent bodies total145 new candidate instruction bytes with no physical manifest overlap at preparation. CPU/WRAM/context and all observable peripherals match. Discarded ordinary call-frame bytes are bounded by the observed watermark, preserving observable caller context and DMA contents.

The public service contract is buy/sale/upgrade modes1..3. The general ring loop C065D7 and category-two modal actions remain open and receive no source claim. The inherited selection model has its separate primary15 proof and an explicitly incomplete general contract; this capture proves the actual selection paths produced by the three complete public shop services.

Integration spec: `event_menu_shop_public_check:EventMenuShopPublic:event-menu-shop-public:event_menu_shop_public`.

## Frozen hashes

- `tools/event_menu_shop_public.py`: `269f6e29ff6d9f3688454830f7432536c36d6fa62ee42ab45296ef4ea20b910a`
- `tools/event_menu_shop_public_check.py`: `b52aa070ff1b60f831b4805b83c99ebdbc11d922c0a857077aa0830daa120606`
- `data/event_menu_shop_public.json`: `39c09b1b7b1cf9f05f4cd31e24cfb492fb5c7c5a0dc2ffa7c4982cd053c6a194`
- `data/event_menu_shop_public.coverage.json`: `cb4b499040517b90d7580cf631670c7a7b5127737d310d32db63d6700078abf3`
- `data/event_menu_shop_public.source_audit.json`: `42903c44228d337a3004e8b5dcd05e66e83f6405c54dcb25f00267b53eafa96c`
