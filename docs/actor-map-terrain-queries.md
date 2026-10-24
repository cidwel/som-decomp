# Terrain point, footprint and slope queries

Seven readable functions reconstruct 1,698 physical ROM instruction bytes at C1B93E–C1BFE0. The model implements signed movement deltas, toroidal coordinates, terrain gates for heroes/enemies, both footprint axes, wall layers, slope profiles 0–7, preceding wrapped cells, blocked-step redirects and diagonal retries.

Horizontal motion probes the vertical footprint helper C1BE15; vertical motion probes the horizontal helper C1BC37. PHP/PLP restores the incoming logical flags before redirect selection. Positive and negative steps can be redirected to the other axis, with the native direct-page count and delta updates preserved.

The contract is D=0, DB=7E, M8/X16, binary arithmetic, direct-page map and attribute pointers, aligned actor indices, and the explicit numeric footprint/cache ABI. Primary 1,016 comparisons include three real ROM map-piece producer checkpoints. Separate frozen captures explore independent preceding-cell shapes, signed edges and wrapped wall seams. All comparisons check complete WRAM outside observed native stack scratch, SRAM, registers, context, peripherals and audio; no original CPU hooks or fabricated trace states are used. Gameplay scheduling and universal reachability of numeric cache profiles remain separate.

## Native coverage and static dead branch

`data/actor_map_terrain_queries.source_audit.json` reproduces the union and validates every imported dependency hash. Every immediate width is taken from actual passing PC/M/X captures. All instruction starts are observed except SEC/RTS at C1BE62/C1BE63, two bytes reconstructed statically.

From entry C1BE15, the wall path at BE4F branches away whenever unsigned DP5>=8. The remaining path has DP5<8. BE19 fixes the extent to8, and BE5E executes byte SBC8 with carry set. The result is always negative, so BE60 always branches to BEF6. Consequently BE62/BE63 cannot execute from the modeled entries. They are implicit instructions with no guessed operand width; the source build checks their exact bytes. No claim is made about independent entry points into the middle of this routine. The audit reports these two static instructions separately from observed starts.

The readable models and genuine primary/supplement reports remain frozen. Source attribution includes the statically explained two-byte branch; it does not claim a native execution of it or full-ROM decompilation.
