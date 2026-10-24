# Native shop and fixed category descriptor producers

Three reconstructed bodies cover110bytes: D0CF61/59 builds a shop descriptor list from the original D8 table, clears attributes and tail-calls the complete row-order routine; D0D1AE/33 publishes a fixed seven-row category; D0D263/18 appends one descriptor from the native category table while preserving X.

Smoke2 and the first full capture6 passed without model corrections. Cases cover a twelve-item original shop list FB9C, its shorter suffix and empty terminator, paired row rotation, seven fixed descriptors and one appended descriptor. The original lists/tables are read at runtime; payload bytes are not persisted. The produced ABI uses native D0/DB0/M16/X16, valid shop pointers, real FFFF terminators and bounded row counts.

All **55/55 instruction starts**, all three boundaries and immediate widths were observed and recover exactly. Capture99 PC/M/Xstates; all204dependency hashes match. Comparison covers full WRAM outside observed stack, CPU/context and graphics/input/audio peripherals; no native callees are bypassed. Models/checker/report/capture are frozen.

Integration spec: `event_menu_descriptor_sources_check:EventMenuDescriptorSources:event-menu-descriptor-sources:event_menu_descriptor_sources`.

The general inventory coordinator CF9C, its row attributes and status masks, and the complete interactive menu remain open.

## Frozen hashes

- `tools/event_menu_descriptor_sources.py`: `7942436a8865bc5e30a6f931cc075ac6e0d884b878b2d7cedc1b2df825698444`
- `tools/event_menu_descriptor_sources_check.py`: `c43e0300eb351f3ca6afed0f3aee37cdc48e4e5296aee6da18a39375560c3e0b`
- `data/event_menu_descriptor_sources.json`: `999d8510504e1a1e03e42e2d302260b44e780ae250b3dc5248c035d09504966a`
- `data/event_menu_descriptor_sources.coverage.json`: `92a937b39a614b44df88af751db78b47b98830ce44cdfcc65ee678845c2fce56`
- `data/event_menu_descriptor_sources.source_audit.json`: `f1bee9c46bd8051d17dea72532d0ba836070362d073ed11d6bc4dc0cba140a59`
