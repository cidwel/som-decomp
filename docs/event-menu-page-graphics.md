# Native party-page graphics and active hero

[V] Three bodies consume189 instruction bytes: C75DDC/29 selects the first of three party bytes with bit7 set (fallback hero0), C75DF9/156 uploads the page graphics and three palettes, and C02AEE/4 forwards the bank-selected tile DMA to the already recovered C025CE body.

The page uploader emits three256-byte tile transfers from D5:0000, D5:8000 and D6:0000 to consecutive VRAM addresses starting4300. Page7 additionally transfers512bytes from CC:FE00 and writes128 palette bytes from CC:FD80. It then writes three32-byte palette rows at CGRAM90: each has two current-accumulator prefix bytes followed by30 bytes from C8:1F00 onward. The actual prefixes are C8/C8,02/02,01/01; the model preserves those native writes rather than inventing transparent zero entries. These are byte-level hardware effects; rendered colour interpretation remains open.

The smoke3 and first complete36 original comparisons both pass: all eight party masks, page0/3/7, source banksD5/D6/7E/7F and four incoming flag contexts. Full memories/peripherals/registers/context match outside the observed stack. No hooks or synthetic interrupts are used. Tested entry contracts are D0,DB7E,M8/X16,binary arithmetic. Original DMA and CGRAM code executes; graphics/palette bytes are read from the supplied ROM at runtime and never saved as payloads.

Evidence: `data/event_menu_page_graphics_proof.json` and `.coverage.json`; dependency fingerprints are frozen there. Original instructions executed:9626. Complete interactive page initializers and their input/update loops remain open.
