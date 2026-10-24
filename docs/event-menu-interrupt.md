# Native menu NMI and scrolling tick

## Verified checkpoint — 2026-10-10

44 actual vector/RTI original calls,32/32 own instruction starts and61 matching instruction bytes. Every new source body independently assembles exactly to the original ROM. Own captured widths and current proof/dependency hashes pass data/event_native_menu_source_audit.json. Full C01D97 interaction, asynchronous timing and rendered pixels remain open. Preparation notes below describe the earlier pre-verification state, superseded by this checkpoint.


[C] C020A7..C020E3 is a61-byte interrupt callback installed by C0281E through the mutable RAM0100 JML vector. `tools/event_menu_interrupt.py` reconstructs its memory/peripheral effects; eight model-only preflight contexts pass. Own original proof remains queued and61 bytes remain uncredited.

The callback acknowledges4210, increments A20C and, every fourth tick, increments the low-byte scrolling counterA20B. It writes that byte followed byzero to both210D and210E, preserving the original ordered PPU latch effects. Both counters wrap asbytes; scrollFF becomeszero.

The native body saves X/Y/DB/A/status before selecting M8/DB7E. PLP restores widths before PLA; PLB/PLY/PLX temporarily alter N/Z, and the final RTI restores the interrupted status from the real hardware frame. The readable model preserves all caller registers/status while updating only the counters and actual NMI/scroll ports.

`tools/event_menu_interrupt_proof.py` plans44 actual vector-delivery comparisons across every M/X pair, decimal/status/D/DB contexts, mod4 branches and counter/scroll wrap. It constructs the native PB/PC/P hardware frame, runs RAM0100→C020A7→RTI without hooks, and compares complete return state and peripherals. It does not claim asynchronous console timing or rendering.
