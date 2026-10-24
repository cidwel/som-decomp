# External Secret of Mana reverse-engineering sources

Research checkpoint: 2026-10-09. These are leads for reconstructing the retail USA game, not newly credited decompilation. No external implementation, raw game data, patch output or ROM has been added to this repository. Statements below distinguish inspected source from claims in project descriptions.

## 1. Ancient Cave / Secret of Mana Randomizer — highest-priority reference

The requested Ancient Cave project is now [Moppu/SecretOfManaRandomizer](https://github.com/Moppu/SecretOfManaRandomizer). The [author’s project site](https://secretofmanaancientcave.blogspot.com/) identifies the former Ancient Cave name. Inspected source commit: `1404b7bd8552677399f24632c1e37cba37d491ef`. Source comments credit **Moppleton**; GitHub account is **Moppu**. The repository [license](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/LICENSE) is LGPL 2.1. It is a C# ROM randomizer with native code annotations and format readers, not a complete matching retail-game decompilation.

The [ROM loader](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/common/RomGenerator.cs#L208) accepts 2 MiB, optionally with a 512-byte copier header, strips that header, checks the internal title, region 1 and revision 0, and creates a 4 MiB output. It does not establish identity through a cryptographic hash. [RandoContext](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/common/RandoContext.cs#L25) starts injected space at file offset `0x200000`. Writes to `context.workingOffset` are generally new hack instructions; original-address comments and copied displaced instructions are the useful retail evidence.

The [vanilla offset catalog](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/common/VanillaRomOffsets.cs) provides these unheadered **file** offsets:

| Area | File offset | Useful structure |
| --- | --- | --- |
| Music pointers | `0x033D39` | 59 three-byte pointers |
| Sample pointers / loops / frequency / ADSR | `0x033DF9 / 0x033E5C / 0x033E9E / 0x033EE0` | 33 sample records |
| World-map row pointers | `0x068000` | 512 two-byte pointers; bank transition needs checking |
| Compressed title program / placements | `0x077C00 / 0x07B480` | Separate compressed code and tile arrangements |
| Doors | `0x083000` | 1,024 four-byte records |
| Map trigger / piece-list / object-list pointers | `0x084000 / 0x085000 / 0x087000` | 512 entries each |
| Event banks | `0x090000 / 0x0A0000` | Bank-relative two-byte pointers |
| Collision / 16×16 tile definitions | `0x0B0400 / 0x0B4000` | Collision stride `0x180` per tileset |
| Map palettes / compressed map-piece pointers | `0x0C8000 / 0x0D0004` | Piece-bank boundaries precede pointer table |

Further directly useful source files:

- [Door.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/common/structure/Door.cs): destination map uses byte 0 plus bit 0 of byte 1; X uses remaining byte-1 bits; byte-2 bit 0 selects layer-two collision, remaining bits carry Y; byte 3 controls transition.
- [MapHeader.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/common/structure/MapHeader.cs), [MapObject.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/common/structure/MapObject.cs) and [VanillaMapUtil.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/common/VanillaMapUtil.cs): independent record/layout cross-checks.
- [VanillaEventUtil.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/common/VanillaEventUtil.cs): event pointers use bank `0x090000` below ID `0x400`, otherwise `0x0A0000`; event `0x3FF` gets special end boundary `0x09F2D7`. [EventCommandEnum.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/common/EventCommandEnum.cs) and [EventScript.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/common/structure/EventScript.cs) expose event-building conventions, not a recovered interpreter implementation.
- [SomMapCompressor.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/common/SomMapCompressor.cs): encoder/decoder for map pieces. Its own summary says not every compression code is implemented; do not use it as completeness proof.
- [TitleScreenAddition.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/hacks/common/enhancement/TitleScreenAddition.cs): actually decompresses and modifies the title program, confirming that executable instructions also live inside compressed storage. Its replacement program/placements are patch output.
- [EnemyScaling.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/hacks/vanillarando/EnemyScaling.cs): native enemy records start at `0x101C00`, 128 × 29 bytes; weapon rows at `0x101000`, 12-byte stride; boss attacks at `0x10BDC1`, 115 × 7 bytes. Existing local combat reconstruction already uses these bases.
- [FastBosses.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/hacks/common/other/FastBosses.cs): native boss loader hook at CPU `$C23445`, actor flag `$7EE698 & $4000`, and pool branch at `$C20DF6`. This corroborates the already reconstructed phase-bypass flag; its prose “every 5” is not a substitute for local counter/phase execution evidence.
- [DamageCancelFix.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/hacks/common/fix/DamageCancelFix.cs): retail trace around `$C0550C–C05519`, clearing pending damage before item dispatch. [BossZPosition.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/hacks/common/fix/BossZPosition.cs) identifies native `$C216B0` height storage. [BossDeathFix.cs](https://github.com/Moppu/SecretOfManaRandomizer/blob/1404b7bd8552677399f24632c1e37cba37d491ef/SoMRandomizer/processing/hacks/common/fix/BossDeathFix.cs) identifies event `0x7F8` and a potentially hanging party-movement command near its end.

Local read-only checks: the current ROM is 2,097,152 bytes, region 1, revision 0. Its SHA-256 is `4c15013131351e694e05f22e38bb1b3e4031dedac77ec75abecebe8520d82d5f`. First map pointers resolve to file offsets `0x084400` (triggers), `0x085402` (pieces), `0x089000` (header/objects); event zero resolves to `0x090800`, and event `0x400` to `0x0A0C02`. These are sanity checks, not new format coverage credit.

## 2. Widescreen hack — exact retail revision, rendering leads

[tidyhf/secret-of-mana-widescreen](https://github.com/tidyhf/secret-of-mana-widescreen) supplies Asar assembly, inspected at `ffef85e3e710fef4a294a17b076db94d6f0d97de`. The README specifies headerless USA SHA-1 `8133041A363E3CC68CEDEF40B49B6D20D03C505D`; **the local ROM matches this SHA-1 exactly**. Account author: tidyhf. No repository-level license was present in the inspected tree; reference findings rather than importing its implementation. It is a rendering patch and expanded per-map edge tables, not a retail-game decompilation.

The [assembly](https://github.com/tidyhf/secret-of-mana-widescreen/blob/ffef85e3e710fef4a294a17b076db94d6f0d97de/src/somws.asm) identifies CPU-address hooks:

| Original address | Lead |
| --- | --- |
| `$C0C945 / C0D158` | Background column streaming |
| `$C0C859 / C0D0C2` | Background row construction |
| `$C0C702` | Row DMA during NMI |
| `$C0CA71 / C0D6AC` | Initial camera/map-fill path and camera following |
| `$C0E640 / C0E82F` | Actor sprite pieces and shadows |
| `$C220A9 / C220AF / C22118` | Multipart sprite clipping / X high bit |
| `$C0849B / C084D8 / C0851A / C08557` | Flammie sky streaming |
| `$C21069 / C2106F` | Large background-boss clipping |

Several are already reconstructed locally: `map_tile_buffers.py`, `map_tile_fill.py`, `map_actor_body_sprites.py`. Labels above describe patch hook locations; they are not automatically function entry points. Injected `ws_*` routines and [reach.asm](https://github.com/tidyhf/secret-of-mana-widescreen/blob/ffef85e3e710fef4a294a17b076db94d6f0d97de/src/reach.asm) tables are new behavior. The original camera/render paths should be compared before drawing conclusions from widened constants.

## 3. Editors and native data-format notes

[smkerz/secret-of-mana-hacking](https://github.com/smkerz/secret-of-mana-hacking) credits **Tomm and smK** and documents Excel/VBA room decompression/recompression. It is an editor/codec project. No repository-level license was established. [Hack of Mana’s map notes](https://hackofmana.com/maps/) are useful for original map structures alongside relocated/expanded editor formats; apply the same native-versus-modified distinction.

The editor authors’ [world-map documentation](https://hackofmana.com/world-map/) identifies native file offsets `0x067780` for 256 three-byte landing records, `0x067FC0` for bank selection, `0x068000` for row pointers and `0x068400` for compressed rows. It describes direct bytes below `0xC0` and run commands above it. Its take-off table at `0x220000` is **explicitly relocated hack data**, with original offset `0x067A80`; never assign the expanded address to our retail 2 MiB image. Cross-check bank-transition and landing-index details with native readers before adopting them.

The [Super Famicom Development Wiki](https://wiki.superfamicom.org/seiken-densetsu-2) collects ROM/RAM maps, script commands, audio structures and several compression formats. It mixes Seiken Densetsu 2 and Secret of Mana material, uncertain labels and contributor notes; each address needs region/header confirmation. Authorship/license for individual technical notes was not established. This is a format reference, not a complete matching-code source tree.

## 4. Other disassembly claims and cautions

2026-10-11 follow-up: the expanded GameInfo audit inventories 50 reference files at revision `7261ea0b26947fa1de36f686bd8da80d417b76d4`, verifies seven music offsets against native pointers, and records rejected map/stat/text formats and the placeholder ROM build. Use that audit for current GameInfo findings; the paragraph below preserves the earlier snapshot.

[TheAnsarya/GameInfo issue 146](https://github.com/TheAnsarya/GameInfo/issues/146) targets the **same local SHA-256**, but its [current repository overview](https://github.com/TheAnsarya/GameInfo) lists Secret of Mana as planned. Inspected tree `b25520afa942ed2d32053dddf35eb777a0d7a3b2` includes C# address/data/editor helpers; no complete Secret of Mana matching reconstruction was established. The issue’s `0x101DFA` enemy-table location is not the base: `0x101DFA = 0x101C00 + 18 × 29`. The local project and randomizer agree on `0x101C00`.

Its [address conversion helper](https://github.com/TheAnsarya/GameInfo/blob/b25520afa942ed2d32053dddf35eb777a0d7a3b2/src/GameInfoTools.Data/SecretOfMana/SecretOfManaAddresses.cs) uses a 32 KiB formula for low-bank ROM mirrors; do not import that formula into this HiROM project. Example: its `$008000` conversion gives file `0`, whereas this ROM’s HiROM high-half mirror corresponds to `$C08000`, file `0x008000`. High-bank `$C0–DF` offsets are straightforward, but lower mirrored banks must follow the actual local bus mapping.

A historical disassembly link, [Enker’s bank pages](http://www.darkwoodinc.com/~enker/banks.php), is cited by old resource lists. Direct HTTP and HTTPS retrieval failed during this research; completeness, files, authorship attribution beyond the URL and license remain unverified. Data Crystal’s direct ROM-map page also returned HTTP 403. Neither inaccessible reference has been used as code evidence.

## Integration order

1. Use Ancient Cave’s original trace comments to accelerate **unrecovered** item/menu/boss paths, checking catalog overlap first.
2. Cross-reference native format inventories against the vanilla readers; keep original and relocated tables separate.
3. Use the exact-revision widescreen hook map for remaining rendering/camera dependencies; reuse existing matching sources without double credit.
4. Reconstruct readable retail logic, execute the actual original routine and assemble matching source before adding instruction-byte credit. External notes alone increase neither documented coverage nor decompilation totals.
