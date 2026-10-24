# Native event destination source inventory

The C1E922 table has81 destinations for event00..50; bytes50..FF are clamped to50. Currently72 destinations lie in independently assembled matching instruction sources. The C1E902 wait-state table has16 destinations and all16 lie in matching sources (eight distinct targets). This is destination availability, not a claim that complete handlers, callees, interactive menus, text or whole scripts are closed. No ROM bytes are added by this inventory.

Missing command destinations are09,0E..0F,1E..1F,2E and35..37. Several share a target, so destination counts are not unique routines or byte counts. Reserved3D..3F/44..47/4F are eight distinct bareRTS handlers now checked in persistent composition: they retain the event cursor and return, including repeated calls at44. Ordinary owns2E/35..37/0E..0F and its menu/text dependencies. Root can continue09/1E..1F; the full nonnumeric transition context atC1E76D has already passed4912calls and can supply that dependency after the inner-entry ABI is preserved.

The tool rereads both actual ROM tables, validates ROM/build/manifest hashes, and confirms the matched source file hash for every covered destination. Each row retains its existing model scope rather than equating source presence with complete runtime coverage.

Reproduce: `python3 tools/event_opcode_sources.py ROM --json data/event_opcode_sources.json`. This audit must be regenerated after source-manifest changes. Complete-code extent and the whole-ROM reconstruction remain open.
