# Literal magnitude helper

C22B6844bytes enters M8, stores the XOR of byte46/4E on the native stack, converts negative byte operands to magnitudes, calls the complete C22AA6 hardware multiplier, then restores the sign byte. Matching signs return after that load. Opposite signs take an unexpected but valid instruction sequence: LDA56, EOR#$FF, SBC$56851A,X, RTS.

The misleading alternative is to decode the last EOR as sixteen-bit EOR#$FFFF and infer INC/store56. C22AA6 does not change M8, so the actual bytes FF1A8556 decode as a long indexed SBC. The new model preserves that ROM read and returned byte/flags; it does not manufacture a conventional signed-product result or patch the original.

Twelve directed model-only contexts cover both signs, zero,128/255 boundaries, initial M8/M16 and X0/7FFF/FFFF. The native product remains in56/57 and the opposite-sign transform affects the returned A rather than writing it back to56. ROM data is read only at runtime and never saved. No direct JSR/JMP/JSL caller pattern was found in the ROM, so game reachability remains unknown.

Twelve original calls passed on the first capture. All own instruction starts were executed, including the opposite-sign long read/subtract. Full WRAM outside the observed native stack, CPU/context and peripherals agree; audit and hashes are in `data/boss_byte_magnitude_product_audit.json`. Model/checker/report/coverage are frozen. Native D0200/DB7E/X16, binary arithmetic and C5=0 are explicit contracts; SEP20 narrows A regardless of its incoming width. Gameplay reachability and the programmer's intended arithmetic remain unknown.
