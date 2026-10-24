# Main-frame menu transition and stripe publication

C0A462..A4ED (140 bytes) advances the native menu transition state, requests the slow fade, clears the normal/menu gauge rows, preserves the genuine EC wait and register writes, and dispatches the existing full C0C059 camera slide at its actual boundary. C0A4EE..A5CB (222 bytes) derives the shading parameter and publishes native HDMA stripes from C67400/C67520 ROM patterns into 7FFF00. Patterns stay volatile; no graphics/table payload is saved.

`tools/map_main_frame_transition.py:FrameTransition` is the readable implementation. Its first complete native capture passes 228 calls / 1,097,748 instructions, including four positive camera routes with all 128 native NMI/RTI frame edges each and the actual transition cleanup NMI. Strict WRAM outside the measured occupied stack, SRAM, logical CPU/context and peripherals match without hooks or patches. Transition progress/state and valid map actor/upload records are explicit input ABI.

`data/map_main_frame_transition_source_audit.json` observes all 195 own instruction starts (66/129), unique immediate M/X widths, and independent assembly matching all 362 original bytes. Existing camera79/NMI and bank/motion/menu dependencies retain their hashes and receive no additional source credit. `data/map_main_frame_transition_adoption_proposal.json` is ready for root integration; shared metadata and commits are untouched.

The base ring bridge appears in the frozen import closure but this proof executes only its scene service/NMI transport. The corrected modal installed-vector dispatcher lives in a separate new adapter; this transition does not assert the pending ring/coordinator closure or continuous gameplay frames.
