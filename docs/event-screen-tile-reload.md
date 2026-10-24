# Screen character reload used by event1F restoration

Readable model: `tools/event_screen_tile_reload.py`. All10,368 complete original calls pass in `tools/event_screen_tile_reload_proof.py`; see the frozen report and own coverage in `data/event_screen_tile_reload_proof.json` and `.coverage.json`. The physical bodies add168 instruction bytes and their77-word destination table adds154 typed bytes after independent assembly verification.

## Complete physical bodies

| Entry | Bytes | Behavior |
|---|---:|---|
| DBF900 | 54 | Configure DMA6/7 and scan all77 character slots |
| DBF936 | 114 | Map one slot to two64-byte graphics transfers |

`C2019E` calls DBF900 after restoring boss resources and palette rows. This is a real native graphics call, rather than an empty return dependency. Completing this leaf does not complete C2019E, FF6B or the event1F command.

DBF900 changes DB to00, truncates X/Y to8 bits, and visits WRAM7E0F55..7E0FA1. Entries with bit7 set are skipped. Each accepted entry is copied to direct-page68 and the slot index is passed to DBF936. The scan leaves the table unchanged, finishes with X77 and C1/N0/Z1, and widens M/X before its RTL. DB is left00; Y retains its initial low byte. A and V depend on the last accepted transfer or skipped entry.

## Packed positions and destinations

For a nonnegative position p, the first source offset is:

```
q = ((p & F8) * 4 + (p & 07) * 2) * 32
source = q + (4000 if q >= 2000 else 2000)
```

All constants above are hexadecimal. DMA6 reads64 bytes from bank7F at `source`; DMA7 reads64 bytes at `source+0200`. The transfer sources wrap as native16-bit DMA addresses. No graphics bytes are saved by the model or checker.

The destination comes from a77-word numeric table at D97F35. A slot index is doubled with M16 but transferred to X8; the arbitrary high byte of direct-page6A does not extend the table index. The fetched word is shifted four times and added to6000 with native word wrapping. It is stored in7E0E7F and written to2116 before DMA6; the second VRAM address is100 words later. The source word is stored in7E0E7D. Both transfers use mode1 to ports2118/2119, source bank7F and size0040. Their actual VRAM result also depends on inherited VMAIN; the routines do not overwrite2115.

DBF936 requires the caller's DB00/M8/X8 and configured channels6/7. It writes byte6A, word6C, source/destination scratch and both DMA register groups; it returns M8/X8, X80, leaves Y unchanged, and preserves neither A nor arithmetic flags. The parent restores its scan index using PHX/PLX.

## Evidence domain

The20-case model-only smoke and10,368-case full model-only preflight passed, including every77 destination indices ×128 accepted positions. The model-only checks independently calculate source/destination formulas; they do not constitute original execution evidence.

The passing original comparison covers512 whole scans: empty, single, mixed and all-active entries, incoming DB00/7E/7F/42, D0000/0200/0300 and four inherited VRAM increment/remapping configurations. It compares complete WRAM outside the actual observed stack, SRAM, VRAM, CGRAM, DMA state, port latches, hardware, CPU registers and native context. Forced blank and binary arithmetic are explicit domains. Cycle timing, the upstream forced-blank producer and complete event1F restoration are separate unfinished requirements.

Own capture covers all80 instruction starts with unambiguous immediate widths; see `data/event_screen_tile_reload_source_audit.json`. Both body entries are executed through native return instructions.
