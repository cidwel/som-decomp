# OAM workspace and spell-frame renderer

The new readable model closes the complete software OAM finalizer C0BCAB/33 and
initializer C0BCCC/39, together with their complete optional spell-frame chain:
C10034/4, C14848/74, C14892/71, D3F567/81, D3F5B8/203, D3F683/70,
D3F6C9/126, D3F747/88, D3F79F/146 and C12E84/4. These twelve bodies total939
ROM instruction bytes. RNG and individual-sprite projection models are reused
unchanged and receive no additional source credit.

Finalization writes the hidden sprite sentinel E0FF from the current cursor7C
until the previous watermark0120 or the01FC limit, then writes a final sentinel
unconditionally and publishes the cursor as the new watermark. Literal unsigned
comparisons and the unconditional final write are retained, including odd and
out-of-range cursor examples. Initialization resets phase59/5A and cursor7C/7D,
clears the32-byte high OAM buffer and invokes the complete optional renderer
when byteCFF7 is nonzero. Values whose low nibble is zero still execute the
original renderer wrapper and restoration.

The optional renderer uses the low nibble of CFF7 to fetch the actual interval
word at DCFE8A. It clamps the current expansion countdown to that interval,
clears the first24 OAM entries toF0 and the six packed high OAM bytes, and advances
the actual group pointed to by8436. Expansion grows to24 records, wraps its
replacement cursor, resets the selected record with the real bounded RNG,
refreshes three signed velocity groups and projects every active sprite through
the existing complete C14118 implementation. The per-record fractional adds
retain byte carry into the integer coordinate words.

Velocity damping follows the literal native integer sequence: take signed
absolute magnitudes, approximate their length from the maximum plus half the
minimum, halve it, multiply through211B/211C and derive the seven-bit damping
coefficient from the low product word. A second multiplication for each doubled
signed component publishes the middle/high product word. Zero results clear
the adjacent high word before the main store, preserving the original overlap.
The new bus composes the frozen `layer_ppu.CPU` signed product read behavior with
the existing real resource/IRQ bus. Mode7 latch/matrix and ordered writes are
compared, rather than replaced with fixed product values.

The proof fixtures cover both incoming accumulator widths, native binary status,
three dependency direct pages, all256 CFF7 bytes, expansion counts0/1/2/23/24,
countdown and random-refresh gates, signed velocity boundaries and OAM cursor/
watermark boundaries. Complete CPU/context, all WRAM outside observed native
stack bytes, video/DMA/PPU/multiply state, IRQ/audio state and ordered arithmetic
writes are compared. All original callees execute with no scheduler/opcode hooks.
Allocated group/individual-sprite records are valid caller inputs; full frame
scheduling, visible rendering and cycle timing remain outside this proof.

The source audit must establish every own instruction start and immediate width,
immutable recursive dependencies and exact independent ca65/ld65 assembly before
source credit. Numeric fixture results and hashes are retained; original ROM,
graphics and save-state payloads are not saved.

All1,280 complete original calls pass, executing923,290 original instructions.
The successful capture verifies460/460 own instruction starts and all immediate
widths; all twelve sources independently assemble to their exact939 ROM bytes.
All126 recursive dependency hashes remain unchanged. The source audit uses only
the final complete capture; earlier successful smoke replays with older proof
fingerprints remain diagnostics and receive no source credit.
