# Native seven-category ring action dispatcher

C071A2 implements the complete native normal-ring action dispatcher. It rejects disabled rows, enters the shop dispatcher in shop mode, calls the seven category callbacks, and publishes both stages of paired equipment selection. Its model is the frozen EventMenuGeneral dependency; the new checker supplies independent original-code comparison and source coverage.

Smoke3 and the first full13 passed without changing the model. The cases include real shop purchase, disabled row, inventory action, consumable healing, spell action, and both selection stages for categories3..6. Second-stage fixtures first execute the actual first-stage producer, rather than seeding a marked row. Descriptors and geometry are produced through their real frozen dependencies. Original code runs with no hooks, with actual controller and NMI events; WRAM, CPU/context, graphics/audio/input/arithmetic peripherals and frame histories match.

All41/41 own instruction starts and immediate widths are observed. Coverage contains4504 PC/width states and519 unchanged captured dependency hashes. The98 instruction bytes assemble exactly. The separate14-byte numeric vector C07204 is verified through native consumption of all seven indices and independent exact assembly. Categories4..6 share the same callback address; they remain three observed table indices. This vector is typed data, not instruction credit.

This closes the action dispatcher and its callees in the produced domains. It does not close the remaining selection/polling source routes in C067A8/C068A7, every previous game interrupt context, or the C7D000 exceptional restoration path. General/modal positive trajectories are validated by the separate frozen General19 proof.

Integration spec: `event_menu_ring_action_dispatch_check:EventMenuGeneral:event-menu-ring-action-dispatch:event_menu_ring_action_dispatch`.

Source proposal: C071A2/98 instructions; C07204/14 typed numeric callback addresses in `src/rom/native_ring_category_action_jump_targets.s`.

## Frozen hashes

- `tools/event_menu_ring_action_dispatch_check.py`: `e199a30cba9421a2707060d895f7131a37297039cea15994138d0454a66be1dd`
- `tools/event_menu_general.py`: `1fbb7aeb36eb9da700658aa12434f23d5093c43c1f3853b0d7265b9acbe5a778`
- `data/event_menu_ring_action_dispatch.json`: `74e663b3f2d09f6b5f6e1a7c94df619ee1c4f5defd44366d0b38475fe2b39fe8`
- `data/event_menu_ring_action_dispatch.coverage.json`: `5894b52ac4df3672d9bbdb7c0197f3f7259ae0a01368140b63039f7da862eaf0`
- `data/event_menu_ring_action_dispatch.source_audit.json`: `028309f4ecb4ab2c69fd5441de6ad3eb1d4af3e23f063253985286b99a0f8f9f`
- `data/event_menu_ring_action_dispatch_numeric.json`: `eed87aa5ff656d6b8c48954a472383a0c2e56044dff3fe349c8b204834950b7a`
- `src/rom/native_ring_category_action_jump_targets.s`: `873b39e9807729b845c9cf28571af88f7dfe601fcad069526ae44d4148e88073`
