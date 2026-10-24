# Patch set for Mana Magic: ROM write-back (final, checked on a copy)

The Mana Magic project (`<local path>`) was never modified. Every patch was built and tested on a copy under `~/.local/state/som-decomp/godot-editor/mana-magic-copy/` (`pristine/` = the project as of 2026-10-18 including its uncommitted changes, `work/` = patched). The diffs in this folder are unified diffs against `pristine/`, for `patch -p1` from the project root, in this order. They were re-applied to a fresh copy of `pristine/` (`verify1/` for 0001-0008, `verify2/` for 0001-0012, `verify3/` for 0001-0015) and that copy passes all the headless tests below.

| patch | file(s) | what it does |
|---|---|---|
| 0001 | `tools/build_rom_map.py` | each map sidecar gets a `rom` block: ROM sha256, offsets, the 8-byte object records as stored, event words, piece records; each transition entry gets `rom_offset` |
| 0002 | `tools/build_rom_map.py` | `metadata/rom_record` on bosses, `metadata/rom_transition` on spawn markers |
| 0003 | `tools/build_rom_events.py` | `rom_sha256` in `data/rom_events.json` |
| 0004 | `data/databases/items.json` | `romRow` on the 11 consumables |
| 0005a | `addons/mana_magic_editor/mana_magic_editor_dock.gd` | adds the "ROM" tab |
| 0005b | `addons/mana_magic_editor/editors/rom_bridge_editor.gd` (new) | the ROM tab: embeds the Write to ROM panel of the add-on of 0006 (replaces the earlier snapshot / report / apply buttons) |
| 0006 | `addons/som_writeback/*` (new, 10 files) | the add-on: `write_to_rom.gd` (pipeline), `write_to_rom_panel.gd` (the dock), `som_edit.gd`, `som_panel.gd` (raw formats dock), `plugin.gd`, `plugin.cfg`, and four headless tests (`smoke_test.gd`, `mm_writeback_test.gd`, `panel_smoke_test.gd`, `dock_embed_test.gd`) |
| 0007 | `data/databases/elements.json` | optional fix: Salamando has `nameText` "Gnome" (copy mistake) |
| 0008 | `tools/build_rom_map.py` | one-layer maps no longer crash the converter (`layer_cells` got `layer2 = None`); 7 of the first 194 not-yet-converted maps failed on this |
| 0009 | `tools/build_rom_map.py` | no junk exits: trigger tile ids above 0xFF and event 0xFFFF are skipped (map 298 had 7,489), and the `rom.event_words` list of a map is cut at the 68 words a trigger can address |
| 0010 | `data/rom_events.json` | regenerated over all 394 maps: 459 -> 1,216 event scripts (the 459 are unchanged), 22 shop records |
| 0011 | 50 x `data/databases/rom_mobs/npc_<kind>.json`, 50 x `assets/sprites/sheets/rom_mob_npc_<kind>.png` | the NPC sprite sheets of the 50 kinds the other 327 maps use and the first 67 do not (binary: apply with `git apply`, not `patch`) |
| 0012 | `addons/som_writeback/mm_maps_test.gd`, `.tscn` (new) | headless test: 41 converted maps load with no error and a write-back round trip on a new map |
| 0013 | `engine/systems/rom_event_ops.gd` (new), `rom_event_runner.gd`, `rom_shops.gd` | the 11 event opcodes the runner lacked (0x0F, 0x1C, 0x1D, 0x1E, 0x1F, 0x2B, 0x2C, 0x2F, 0x35, 0x36, 0x37) and the real condition tests of 0x49-0x4E (they only skipped the next command before) |
| 0014 | `tools/build_rom_event_tables.py`, `data/rom_event_tables.json` (new) | the two position tables WARP (0x1C) and MAP_CHANGE_D (0x1D) read: 256 words at `$C6:7A80`, 64 x 4 bytes at `$C6:7C80` |
| 0015 | `tests/rom_events/rom_event_ops_test.gd`, `.tscn`, `rom_event_ops_vectors.json` (new) | headless test: 594 + 176 + 264 + 42 vectors made by running the game's own routines, plus the rest of the semantics, plus all 86 events that use the opcodes run to their end |

Godot creates `.uid` files for new scripts the first time the project is opened; they are not part of the diffs.

## Apply

```
cd /path/to/mana-magic-godot          # a clean checkout is best; git stash your own changes first if a hunk is refused
for f in 0001-build-rom-map-provenance 0002-build-rom-map-record-metadata 0003-build-rom-events-provenance 0004-items-rom-row \
         0005a-editor-dock-rom-tab 0005b-editor-rom-bridge-tab 0006-addon-som-writeback 0007-elements-salamando-name \
         0008-build-rom-map-one-layer-maps 0009-build-rom-map-real-triggers 0010-rom-events-all-maps; do
  patch -p1 < ~/projects/som-decomp/docs/godot-mana-magic-patches-20261018/$f.diff || break
done
git apply ~/projects/som-decomp/docs/godot-mana-magic-patches-20261018/0011-npc-sheets-missing-kinds.diff   # binary hunks (PNG); works outside a git repository too
patch -p1 < ~/projects/som-decomp/docs/godot-mana-magic-patches-20261018/0012-addon-maps-test.diff
for f in 0013-event-runner-opcodes 0014-rom-event-tables 0015-rom-event-ops-test; do
  patch -p1 < ~/projects/som-decomp/docs/godot-mana-magic-patches-20261018/$f.diff || break
done
```

Prerequisites: python3 with numpy and Pillow (only for `tools/build_rom_map.py`), the som-decomp checkout at `~/projects/som-decomp` (or `export SOM_DECOMP=...`), the USA v1.0 ROM at `~/roms/snes/Secret of Mana (USA).sfc`. Work and output folders hold ROM-derived data: keep them outside any repository (`som_edit.py` refuses a folder inside som-decomp; the add-on's default work folder is `user://som_write_to_rom`).

## Use (in the editor)

1. Open the project, Mana Magic Editor dock, tab **ROM** (or enable the plugin "SoM Write-back" in Project Settings > Plugins for the same panel as a dock plus the raw-format panel).
2. Set the source ROM (the doctor button checks size, header, checksum and sha256).
3. Optional: run `python3 tools/godot/adapters/mana_magic.py export-map-data PROJECT` once to create `data/rom_map_data/rom_map_<id>.json` for the 327 maps Mana Magic has no scene for (header, objects, event words, piece lists, transitions; edit them as JSON).
4. **Take baseline** before editing (remembers every value), edit with the Mana Magic editors / by hand, then **Preview changes** (edits found, validation, byte diff in a scratch ROM in the work folder), then **Write ROM...** and choose a new file name. The source ROM and an existing file are refused.

## Commands that were run (all headless, Godot 4.7.1)

```
G=<local path>      # any 4.4+ binary
ROM="$HOME/roms/snes/Secret of Mana (USA).sfc"; RUN=$HOME/.local/state/som-decomp/godot-editor/mm-e2e/myrun   # RUN must not exist yet
cd /path/to/patched/mana-magic-godot
$G --headless --path . --script res://addons/som_writeback/mm_writeback_test.gd -- "$ROM" $RUN/e2e      # prints MM WRITEBACK OK
$G --headless --path . --script res://addons/som_writeback/panel_smoke_test.gd  -- "$ROM" $RUN/panel    # PANEL SMOKE OK
$G --headless --path . --script res://addons/som_writeback/dock_embed_test.gd                           # ok ... ROM tab embeds the panel
$G --headless --path . --script res://addons/som_writeback/smoke_test.gd -- "$ROM" $RUN/smoke ~/projects/som-decomp/tools/godot/som_edit.py   # SMOKE OK
$G --headless --editor --verbose --path . --quit-after 80 2>&1 | grep -E "Write to ROM|SCRIPT ERROR|Parse Error"   # panel embedded, no errors
# the bytes written are checked against offsets computed with no codec code; then the ROM is booted in snes9x and the edits are looked at:
cd ~/projects/som-decomp/tools/godot
python3 mm_writeback_e2e.py spec  /path/to/patched/mana-magic-godot $RUN/spec.json
python3 mm_writeback_e2e.py boot "$ROM" $RUN/e2e/edited.sfc $RUN/spec.json --frames 8400
# python side
cd tests && PYTHONPATH=.. python3 test_writeback.py && PYTHONPATH=.. python3 mutation_suite.py --only bridge
```

`mm_writeback_test.gd` makes six edits as an editor would (monster HP in `monsters.json`, a shop price in `rom_shops.json`, a dialogue line in `dialogs.json`, a map object moved in `rom_map_16.json`, one pixel of `hero_tiles_boy.png` with Godot's `Image`, one ADSR field of an instrument in `music_samples.json`) plus a seventh on a map without a scene (`rom_map_data/rom_map_17.json`), in a scratch copy of the project data, then runs baseline, gather, validate, plan and import and compares every differing byte of the new ROM with the expected set (16 bytes: the edits plus the header checksum pair). `boot` plays the new ROM next to the original and observes: Rabite HP 20 -> 777 in a fight, Candy price bar differs in the shop-0 buy menu, the Dark Lich line "It is TIME!" in the dialogue box, the boy tile in sprite VRAM, the map 16 object slot at (52, 34), the map 17 object one tile right, ADSR1 of song 7's voices and the audio hash, and 8,400 frames of a new game.

### Event opcodes (patches 0013-0015)

```
$G --headless --path . res://tests/rom_events/rom_event_ops_test.tscn --fixed-fps 60     # prints ROM EVENT OPS OK (about 40 s)
python3 ~/projects/som-decomp/tools/godot/mm_event_coverage.py . --out coverage.json     # 1216 events, 0 use an opcode the runner lacks
python3 tools/build_rom_event_tables.py "$ROM"                                           # rebuilds data/rom_event_tables.json (patch 0014)
python3 ~/projects/som-decomp/tools/godot/mm_event_ops_vectors.py "$ROM" tests/rom_events/rom_event_ops_vectors.json   # rebuilds the vectors (patch 0015)
```

The vectors are runs of the game's own 65816 routines (`$C1:F1F1`, `$C1:EFE7`, `$C1:EB50` / `$C1:E8D3`, `$C1:EDEF`) on the CPU model of `tools/combat_env.py` (no hooks, full WRAM), not a re-implementation. Python side: `tools/godot/tests/test_r4_events.py` states the rules and requires the game's results to follow them. Godot does not know a new script until the project is scanned once (`$G --headless --editor --path . --quit-after 60`), which also creates the `.uid` files.

### Converted maps beyond the first rooms (patches 0009-0012)

```
RUN=$HOME/.local/state/som-decomp/godot-editor/mm-e2e/maps1; mkdir -p $RUN/xdg      # the ROM pack goes to user://rompack, which XDG_DATA_HOME moves under $RUN
XDG_DATA_HOME=$RUN/xdg $G --headless --path . res://addons/som_writeback/mm_maps_test.tscn -- "$ROM" $RUN 41     # 41 maps; prints MM MAPS OK (about 5 minutes)
# the other pieces
python3 ~/projects/som-decomp/tools/godot/mm_event_coverage.py . --out coverage.json         # opcodes of data/rom_events.json the runner lacks
python3 ~/projects/som-decomp/tools/godot/mm_rip_npc_sheets.py "$ROM" . --work /tmp/npcwork --sidecars <folder of rom_map_<id>.json of all maps>   # rebuilds sheets (patch 0011 is its output)
python3 tools/build_rom_map.py "$ROM" --maps $(ids of all 394 maps) --out /path/for/all/rooms                  # about 6-25 s per map, 55 MB
python3 tools/build_rom_events.py "$ROM" --out /path/for/all/rooms                                            # reads data/rom_maps there, writes data/rom_events.json (patch 0010)
```

`mm_maps_test.gd` refuses to run unless `user://` is inside the run folder. It extracts N maps outside `FIRST_ROOMS` with `tools/extractor/som_extract.py`, loads each room, checks tiles, leader, mob / NPC counts, NPC sheets, event ids and that no error is logged (a `Logger`), then makes a write-back round trip on a new map (one record dragged in the scene, one edited in the sidecar) and compares every differing byte with `mm_maps_e2e.py expected` + `mm_writeback_e2e.py check`. Patch 0011 is a binary git diff (PNG sheets): apply it with `git apply` (it works outside a repository); the generated rooms themselves are not in the patches.

## Manual test checklist (needs a person in the real editor; not done headless)

- [ ] Enable the plugin; the dock "Write to ROM" and "SoM Formats" appear; the Mana Magic dock shows the ROM tab with the panel at a usable size.
- [ ] Browse buttons open the file dialogs; the chosen paths are remembered after restarting the editor.
- [ ] Check ROM with the right ROM: green lines, "writing is allowed"; with another file: red, Preview refuses.
- [ ] Take baseline, change a monster HP in the Enemies tab and save, Preview: the Edits list shows that one edit, the byte diff lists the monster table run (and the checksum pair), Write is enabled.
- [ ] Preview with no edits: "nothing to write", Write stays disabled.
- [ ] Write ROM...: the save dialog proposes `<work>/<rom>_edited.sfc`; choosing the source ROM or an existing file shows "Not written" in the log; a new name creates the file; the source ROM sha256 is unchanged.
- [ ] Drag a mob in a generated room scene, Preview: a map object edit appears; drag a spawn marker by whole tiles, same.
- [ ] Load the new ROM in an emulator and look at the edit.
- [ ] The editor stays responsive enough while Preview runs (it blocks for a few seconds: the panel calls Python synchronously).

## Not covered

Graphics of converted maps, collision, tile pictures, rendered audio and sprite sheets still have no reverse (they are derived by a lossy step). The data-only map files cover header, objects, events, pieces and transitions, not tiles or collision. Growth beyond the ROM's free space needs the "Expand to 4 MiB" option, which was proven in the emulator by the som-decomp cases but not by a Godot-driven run.
