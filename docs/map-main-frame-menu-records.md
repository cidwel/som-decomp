# Map Main Frame Menu Records

The full even-frame dispatcher and two complete record workers publish timed menu tiles: byte timers, direction changes, original hardware multiplication, C80000 ROM words/rows, WRAM row copies, restoration and rotation. Numerical descriptors/tile workspaces are explicit input ABI; no tile payload is saved.

The readable model is `tools/map_main_frame_menu_records.py:FrameMenuRecords`. The first complete native capture passed: 244 original calls / 9,443 instructions. Strict WRAM outside the measured occupied stack, SRAM, nine CPU fields, native context and peripherals match without hooks or ROM patches.

`data/map_main_frame_menu_records_source_audit.json` observes every one of the 209 own instruction starts with unique immediate M/X widths. Independent assembly matches 424 bytes exactly. Frozen Schedule657 and inherited callees retain their hashes and receive no additional source credit. `data/map_main_frame_menu_records_adoption_proposal.json` is for root integration; shared metadata and commits are untouched.

Main frame C0B08C, menu scheduler C0B136 and live caller-produced descriptors remain separate pending comparisons; this helper proof does not close continuous frame execution.
