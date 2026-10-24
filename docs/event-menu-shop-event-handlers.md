# Event shop handlers: complete native call chains

The three event dispatcher targets C1EAC1 (sale, 21 instruction bytes), C1EAD6 (upgrade, 21) and C1EDD2 (buy, 29) are reconstructed in `EventMenuShopHandlers`. Total: 71 new instruction bytes and no new data tables. The handlers widen registers, advance the actual script cursor, consume the buy operand, stage sprites through C1F3F3, call the complete native public ring, and restore sprites through C1F3EA. Existing callees contribute no duplicate source credit.

## Evidence

`data/event_menu_shop_event_handlers_proof.json` and its coverage file contain seven complete original executions, without hooks: buy/sell/upgrade cancellation, empty sale, and successful buy/sell/upgrade followed by cancellation. The terminal capture returned exit 0 after 2,091,821 original instructions. `data/event_menu_shop_event_handlers_audit.json` verifies all 28 own instruction starts (71 bytes), 5,733 PC/M/X states and 494 unchanged dependency hashes. Comparison covers WRAM/SRAM, CPU and saved context, native input phases, interrupts, audio and hardware state outside the observed stack frames. Model/checker/capture files are frozen after this result.

## Producer and limits

The directed event fixture uses DP3A as the real actor offset (0), rather than a ring inventory slot or an absolute E000 address. Sprite staging recomputes screen coordinates from world coordinates and camera offsets. An initial model-only fixture used visible screen positions but random world positions, so C0E40E overwrote the screen positions and the upgrade ring could not settle. The corrected producer supplies visible world coordinates with a zero camera before staging; no timer, phase or execution bypass is introduced. Both positive and cancellation paths retain the real staging, geometry, polling and restoration.

This proves the complete three handler chains in the documented producer domain. It does not close ordinary category-two menu pages, the general mode-zero interactive ring, or arbitrary gameplay reachability. Source recovery and joint byte-exact assembly remain the integrator's independent obligation.
