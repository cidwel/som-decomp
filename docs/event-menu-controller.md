# Native event1F menu state and sprite dependencies

## Verified checkpoint — 2026-10-10

204 complete original calls,173/173 own instruction starts and367 matching instruction bytes. Every new source body independently assembles exactly to the original ROM. Own captured widths and current proof/dependency hashes pass data/event_native_menu_source_audit.json. Full C01D97 interaction, asynchronous timing and rendered pixels remain open. Preparation notes below describe the earlier pre-verification state, superseded by this checkpoint.


[C] `tools/event_menu_controller.py` reconstructs ten complete helpers totalling367 instruction bytes. Forty model-only cases execute without interpreting original instructions; original proof/source credit remains pending. These are the C01D97 menu dependencies, distinct from the other event menu atC0666F.

| Entry | Bytes | Behavior |
|---|---:|---|
| C028A6 | 51 | Page/request reset and six-byte record pointer780A+6*page |
| C028D9 | 38 | Title page idle timeout; input resets counter |
| C02955 | 48 | Match selected hero to one of three controller ids |
| C02985 | 32 | Clear title instruction strip only on page9/hero0 |
| C01ED1 | 44 | Actor sprite palette blink countdown |
| C01EFD | 27 | Highlight actor sprite palette and request OAM publication |
| C01F18 | 30 | Runtime-derived sprite start/count from C02A58 |
| C01F36 | 37 | Initialize128 low OAM records and32 high-table bytes |
| C01F5B | 45 | Complete544-byte DMA7 OAM transfer |
| C01F88 | 15 | Clear publication bit and reset scrolling/frame counter |

The title timeout compares incremented16-bit counter to0708. On that exact frame it sets A20A bit0 and returns before storing the increment;0707 remains in A213. Other values wrap literally, and non-title pages bypass the counter. Both input bytes A203/A204 reset it.

C02955 converts the current hero id to an8-bit doubled selector, replacing zero with1. It scans D9..DB after masking controller high bits, picks the first match and falls back to slot0. PHB/PLB restores caller DB; its final N/Z follow that restored bank.

The sprite-span helper uses the fourth table record when A212bit20 is set; normal hero ids0..2 use the other three records. Its direct caller requires B0/M8/X16. Highlight/blink callers explicitly establish B0 with LDA0/XBA. Their loops use the actual table count and preserve original per-record pointer changes. Blink triggers only when A19F decrements tozero, then reloads10; decrementing0 wrapsFF and does not trigger.

Sprite initialization writes F8F8 andzero pairs across512 bytes, then clears32 high OAM bytes. The DMA helper sets OAM address0, control0/target04, WRAM7E:9C00 and length0220, then restoresDB. It uses the shared peripheral data model for all544 transferred bytes, rather than copying only the visible sprite records.

The directed proof covers idle/input/wrap edges, all three controller matches and fallback, title strip guards, sprite spans and countdown branches, OAM publication and saved banks. Its complete originals are queued. No complete C01D97 loop, constructor, controller publication, fade/NMI timing or menu rendering is claimed yet.
