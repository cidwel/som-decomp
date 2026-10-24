# Native menu descriptor initialization and row order

Three reconstructed bodies cover157bytes: D0D308/17 clears sixteen attribute words; D0D319/126 rotates descriptor and attribute pairs, applies the mode3 rotation override and adds the category tail descriptor; D0CB11/14 initializes twelve icon rows, clears attributes and publishes the actual upper palette. Original ROM descriptor/color tables are read at runtime.

Smoke2 and the first full capture7 passed unchanged. Directed cases cover no rotation, three rotations, mode3 override, both category-tail guards, clearing all sixteen words and complete upper-palette construction. Descriptor lists use the real FFFF terminator; the produced domain requires a terminator and bounded rotation count. The model preserves native carry/flags, scratch writes, descriptor/attribute pairing and original tail calls.

All **69/69 instruction starts**, three boundaries and all immediate widths are supported by original execution; capture171 PC/M/Xstates; all202 dependency hashes match. Comparison includes CPU/context/peripherals and full WRAM outside the observed stack. No native calls are replaced by hooks. Tools/checker/report/capture are frozen.

Integration spec: `event_menu_descriptor_order_check:EventMenuDescriptorOrder:event-menu-descriptor-order:event_menu_descriptor_order`.

The next strip caller and inventory/shop producers are separate contracts. The interactive menu remains unfinished.

## Frozen hashes

- `tools/event_menu_descriptor_order.py`: `cc426dc38a7260335c241e8d88ef953d0e8f94627a47f9b6691210a0aaccd61e`
- `tools/event_menu_descriptor_order_check.py`: `f00cc56fa194fffc91b14d307c6153efc1c8d7b73de4db04013b85a1f7e10633`
- `data/event_menu_descriptor_order.json`: `6b9e1d1c8d3292b8198018cf310ca8063cd6f330feca662a084b871058f35682`
- `data/event_menu_descriptor_order.coverage.json`: `243d1c5dfe8734d289d560fbb971c1bdff59cc67b0bf854e8035e4be9429f1cf`
- `data/event_menu_descriptor_order.source_audit.json`: `acb14ae8e2e583cbe70009321b5717a0fa100eb4f8dd335178afa0856d55b7e0`
