# Native shop tile frame and selection snapshot

[V] `C76170..C76255` renders the selected item frame. `C7626A..C76291` snapshots selection state. Both complete native RTL calls are reconstructed in `tools/event_menu_shop_tiles.py`; 64 original comparisons cover all eight item selectors and four incoming flag patterns. All memory, peripherals, result registers and caller context match outside the observed native stack, without hooks or interrupt injection. The own-source audit observes all 129 instruction starts and establishes each immediate width. The 270 instruction bytes assemble independently against the ROM.

The first frame strip indexes `C77169` with `30 * item`: seven ascending two-byte tile records followed by eight descending records. The second half toggles horizontal flip; both strips publish vertically mirrored copies separated by $C0 bytes. A separate record at `C77259 + ((item * 8) & $FF)` supplies four corner anchors; three byte shifts retain the original wrap for the eight-bit item calculation. Two rows of thirteen `$3C3E` words fill the interior. Table graphics are read from the supplied ROM at runtime; their payload is not stored or credited as typed data.

The snapshot copies the selected byte `A222` to `A24E`, sixteen bytes from `A136` to `A23E`, and eight bytes from `A223` to `A24F`. Original M8/X16, D0, DB7E and binary arithmetic form the checked contract. It returns with Y0 and X8. The frame returns M8/X16 and preserves its actual carry and overflow from the final word addition.

Evidence: `data/event_menu_shop_tiles_proof.json`, its coverage companion and `data/event_menu_shop_tiles_source_audit.json`. This closes the two bodies, not the full interactive shop coordinator or all exceptional caller contexts.
