# Reference-free sparse ROM build


Current verified layout (2026-10-15): 543,449 of 2,097,152 physical ROM bytes,
25.9137%, with 1,553,703 bytes still unknown. SOURCE429 adds285 typed numeric
metadata sources after79958 complete source-model reader calls and independent
schema, role and ROM verification. This session has added4,443 source/physical
bytes,1,543 newly documented source fields and zero instructions. Resource-format
documentation is measured separately. All old sources and127 existing LOW owners
are preserved; only285newfiles were assembled, with no assembly repetition.
See `data/session_checkpoint_20261015_codex_source550520_retainednumeric429.json`.
Persistent promoted build:
`~/.local/state/som-decomp/verified-baseline-20261015-retainednumeric429-rich-staged`.
The original private assembly/proof/receipt are preserved separately. Its richer
selection proof was bound AFTER assembly by exact metadata-only transformations,
with no changed artifact bytes; independent binding review8446f287 authenticates
both original and final objects.
The dated sections below retain their historical counts.

`tools/build_recovered_rom.py` independently assembles every manifest source
without accepting or loading a reference ROM. It places physical ROM blocks at
their HiROM offsets, rejecting overlap and incorrect lengths. SPC sources use
their separate native assembly addresses. Decoded boot sources are assembled
into a separate 64 KiB RAM image; they do not increase physical ROM coverage.

The build emits `rom.partial.bin`, `rom.known-mask.bin`, corresponding decoded
boot artifacts and `build.json` into an external output directory. Each mask
byte is one for a reconstructed byte and zero for an unknown byte. Unknown
bytes contain FF solely as a placeholder. The report lists all unknown spans,
source and assembled hashes, artifact hashes and the physical byte denominator.
The partial image is not a runnable or complete rebuilt game.

Build and compare separately:

```sh
make build-recovered-rom CA65=/path/to/ca65 LD65=/path/to/ld65
make verify-recovered-rom ROM="/path/to/ROM.sfc"
```

The comparison loads the reference only after assembly. It checks artifact
hashes, lengths, occupancy values and every known ROM/decoded RAM byte.
`data/recovered_rom_build_verification.json` records the result. Individual
sources and contiguous components still receive their independent checks from
`make verify-source`; this layout build supplements those checks.

## Cartridge metadata

[C] `src/rom/cartridge_header_and_interrupt_vectors.s` recovers all64 typed
bytes C0:FFC0..FFFF: the21-byte cartridge title, mapping21, cartridge type02,
ROM/SRAM exponents0B/03, region01, publisherC3, revision00, checksum/complement
and both vector groups. Exact independent assembly is required. These are data
bytes, not instruction coverage or a new executed routine contract.

The original2 MiB byte sum modulo65536 is51FC, matching FFDE; the stored
complement AE03 XOR51FC isFFFF. Native NMI/IRQ destinations0100/0104 refer to
the low WRAM mirror in bank00. Reset8004 is a bank00 ROM entry. FFFF and zero
vector values are preserved exactly; the build does not replace them with
inferred handlers.

## Boot-stream recomposition

`src/boot/encoded_boot_stream_plan.json` is a typed plan of4,658 runs. It stores
only literal lengths and backreference lengths/distances, plus the stream
header and extents. It contains no literal ROM or decoded byte payload.
`tools/boot_stream_recomposition.py` regenerates the original tokens and takes
literal bytes exclusively from independently assembled decoded boot sources.
Unknown literals retain a zero occupancy mask. Overlapping backreferences are
validated against all available assembled RAM pairs.

The current production build recovers14,430 of14,436 encoded bytes:
7,603 token/header bytes and6,827 independently assembled literal bytes.
Six encoded literal bytes remain unknown. The decoded program has22,194
matching source bytes within its22,227-byte output, leaving33 bytes without
source reconstruction. A fresh reader audit identifies32 of these bytes,
7EBCE9..7EBD08, as palette payload queued by7EBD09 for a32-byte CGRAM transfer;
they remain excluded from functional-source credit. The single byte7EBE5A
has no demonstrated reader/producer; adjacent RTS and entry labels do not prove
padding or an instruction. See `data/frontier_effect6_extra_pins_boot33_20261015.json`.
This physical encoded-stream metric is separate from RAM source bytes.
See the current persistent build's `boot_stream_recomposition` report; older
dated sections below retain their own stage-specific counts.

`data/boot_stream_recomposition_audit.json` additionally checks that the plan
reproduces the entire original stream when supplied complete reference-decoded
RAM for that audit only. Twelve generated overlap/sparse-mask cases cover all
six selectors. Audit-only reference RAM never supplies production literals or
grants credit. The production artifact is compared independently afterward.

Remaining code/data/assets, the6 missing encoded boot literals and a full ROM
checksum generated from a complete reconstructed image remain open.
The stored header checksum is the original metadata, not validation of the
FF-filled partial image. A complete rebuild requires every ROM mask byte to
be one and an exact full-image comparison.


## 2026-10-14: partial encoded control-resource reconstruction

The declared C7B480→7E5000 resource has593 bytes of independently assembled control metadata. Its symbolic compression plan supplies length/distance tokens; selected literal values come from these assembled sources. The builder emits1384 additional physical ROM bytes (1034 token/header metadata and350 control literals). It excludes uninterpreted header byte1, terminal lookahead and unknown asset literals. The sparse image therefore matches382858 bytes (18.2561%); its unknown mask remains authoritative. This is data reconstruction, not additional executable code or proof of complete decompilation.

The resource declaration pins its compression plan hash, source address, destination and decoded extent. Recomposition rejects inconsistent overlaps with known ROM bytes. The current incremental image is `/tmp/som-recovered-rom-20261014-decoded593-encoded`; the reference comparison and independent metadata review are recorded in `data/decoded_resource_encoded_control_integration_20261014.json`, `data/decoded_hdma_config16_source_integration_20261014.json` and `data/decoded_resource_encoded_control_review_20261014.json`. Prior507/577-byte reports retain their original snapshot scopes.
