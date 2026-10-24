# Native menu constructor — verified

## Verified checkpoint — 2026-10-10

112 complete original calls,229/229 own instruction starts and541 matching instruction bytes; all actual nested setup calls execute. Every new source body independently assembles exactly to the original ROM. Own captured widths and current proof/dependency hashes pass data/event_native_menu_source_audit.json. Full C01D97 interaction, asynchronous timing and rendered pixels remain open. Preparation notes below describe the earlier pre-verification state, superseded by this checkpoint.


`event_menu_constructor.py` reconstructs 541 matching instruction bytes in
seven complete bodies. C0281E composes the actual frame tile/palette setup,
background registers, fixed ROM grid and bitplane conversion, tile uploads,
actor tile/palette setup and page palette initialization. It saves the old RAM
interrupt vector and installs the actual C020A7 callback. Its dependencies are
the complete pending menu graphics/text-tile models, rather than blank calls.

The other six bodies expose frame initialization, its four tile chunks, actor
tile/palette upload, actor text publication, page palette setup and the page
4/5 color overrides. They read actual ROM tables at runtime and use the real
DMA/video peripheral bus. No graphics or palette payload is stored.

The frozen112-call comparison covers four selectors and four contexts,
with full memory, peripheral, register and caller-context comparisons outside
the observed native stack. Own coverage observes229/229 instruction starts;
all seven bodies independently assemble exactly. Full C01D97 interaction and
asynchronous rendering timing remain open.
