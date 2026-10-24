# Native single-tile menu icon conversion

C0640E→C0642E→D0CA10 saves the caller context, reads eight original three-plane rows from bankD4, converts them through the complete frozen CAD6 pixel engine, and writes sixteen four-plane output words to WRAM. It returns X advanced24 source bytes and Y advanced32 output bytes, with literal PHP/PHB/PHD restoration through existing C868.

Smoke1 and the first full5 passed without any model or frozen dependency change. Cases cover first/middle/end-of-bank source offsets and both native forwarding entries, including saved D300/DB7E and M8/X8. Original ROM graphics are read only at runtime; no asset payload is saved. Original native calls run without hooks. Complete WRAM and CPU/context, graphics/audio/input/arithmetic peripheral comparisons match.

All50/50 instruction starts and immediate widths are observed. Coverage contains102 PC/width states and509 unchanged dependency hashes. Three sources assemble exactly, totaling102 candidate instruction bytes: C0640E/3, C0642E/5 and D0CA10/94. The existing CAD6 pixel engine, C868 context tail and StateAPI context model receive no duplicate credit. This proves the produced direct tile conversion ABI, not a new claim about unrelated menu trajectories.

Integration spec: `event_menu_single_icon_check:EventMenuSingleIcon:event-menu-single-icon:event_menu_single_icon`.

## Frozen hashes

- `tools/event_menu_single_icon.py`: `286575f1e59fd630e8285987f7fd9197e04da8789f701042ab2156987cd88273`
- `tools/event_menu_single_icon_check.py`: `cb20598c654eabeb21d8e6ff1f5dfb9a16e5675f64cf706dd72d10a0a4d06273`
- `data/event_menu_single_icon.json`: `56eaa8ecbd4cd9f0bde86a99029b682725d3946bed39545d9c62f5e856308085`
- `data/event_menu_single_icon.coverage.json`: `121762a04d57ec83ebae39f198a6111a639fc6afb4203be37b5ff27e42c451d1`
- `data/event_menu_single_icon.source_audit.json`: `6df163a692c060407c00203a5a3f90e5df4ea70a5fe32357dce2e57e46885e6c`
