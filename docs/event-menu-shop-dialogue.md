# Native shop notice and confirmation loop

C07B7D/7 plays the error preset and tails into C07E95/74, which starts the actual D9 message, awaits full dialogue rendering, waits for held buttons to be released, then waits for a new button and refreshes the description when required. C07E30/80 marks the selected row, displays the actual confirmation message through the interior C07B81 JMP without that error preset, accepts confirm/cancel, advances frames while waiting and restores the literal confirmation status after clearing blink/phase flags. C07E80/21 composes actual vblank, controller poll and phase dispatch.

Smoke2 and the first full10 passed: ordinary/modal/prior-window notices, held-button release, error alias, confirm, cancel, delayed confirm after an irrelevant button, and plain/active-phase ticks. Window buffers come from the real dialogue geometry/transfer producers, rather than random DMA lengths. Explicit physical autojoypad events drive the original loops; NMI/RTI, renderer/parser/font/transfer and controller/reset implementations remain actual callees. No loop is replaced by a guard or synthetic return.

All75/75 own instruction starts and immediate widths are observed,2,508 distinct PCs and405 dependency hashes unchanged. Complete WRAM/CPU/context and render/audio/input peripherals match. The observed stack watermark excludes discarded call frames while preserving observable caller context and DMA. The existing interior D0D5C1 text-wait loop lies in D0D5B2/31 and is composed with its real long-call frame; it receives zero new source credit. Existing C07908 blink clear also receives zero duplicate credit.

Four bodies total182 candidate new instruction bytes with no physical manifest overlap at preparation. Buy/sell/service callbacks and the complete public ring remain open. Integration spec: `event_menu_shop_dialogue_check:EventMenuShopDialogue:event-menu-shop-dialogue:event_menu_shop_dialogue`.

## Frozen hashes

- `tools/event_menu_shop_dialogue.py`: `6b5dab1450a3a4834e15b985a961dfe25cbc3c9fed6b421172f33803553ffabb`
- `tools/event_menu_shop_dialogue_check.py`: `b177d0a819008ac79e97ba00ade83116951f920e3de5baf46d9e9408f9e966ce`
- `data/event_menu_shop_dialogue.json`: `15d7e7b99f7430bc2631261846931e94cbd726a9f198efd2b644030e0cd97981`
- `data/event_menu_shop_dialogue.coverage.json`: `cb07b66528a4822d7daaa37591045d2eca4cbb6df4ebec78d6e5721e09ea9e4c`
- `data/event_menu_shop_dialogue.source_audit.json`: `8ee2e27578937341c70f4dafe7cd1f30c584ae5011b9522298154be4efbb9b62`
