# Native actor-field predicates and real dispatch continuation

`EventFieldBranches` reconstructs C1F1F1/136, shared by event commands49..4E. It selects the controlled actor for argument0, the native shifted actor offset for1..127, or the current NPC for80..FF; combines the preserved high accumulator byte with the field operand to read the exact original absolute-indexed address; evaluates unsigned greater-or-equal, less-or-equal, AND, OR, XOR or equality; advances D1 by four on acceptance or six on rejection; and resumes the actual dispatcher. Low predicate selectors0/7 retain the original equality fallback for direct entry. Reads for large raw actor selectors carry from bank7E into7F exactly as the original indexed addressing does.

The eight-case smoke initially found an invalid fixture stateF9 before original execution. Setting the native active stateD0=1 corrected the fixture; no semantic model change was required. The first complete4,144-call capture passes:4,096 direct calls crossing all256 actor selector bytes, all eight predicate selectors and two resume environments, plus48 public C1E8D3 calls for all six actual opcodes and representative current/hero/NPC/raw actor selectors. Generated field offsets cover all256 bytes. Test values include0/255,127/128,equality and complementary85/170 bit masks, with all16 incoming CNZV combinations.

Half the direct cases execute the actual next END opcode. The other half use the original E2-bit0 dispatch pause guard after fully executing the predicate, exposing word cursor wrap and long operand bank carry without subsequently executing scratch memory as a script. The predicate itself is never bypassed. Public dispatcher cases always use the normal END continuation. D1 boundaries include signed overflow transitions andFFFF wrap; generated operands remain runtime-only data.

Coverage records111 PC/M/X states. Full randomized WRAM outside only observed native stack writes, complete CPU/context and all video/DMA/peripherals agree. Inputs use D0/DB7E, M8/X8 and binary arithmetic; no instruction hooks or interrupts are installed. Other VM families remain explicitly unresolved through the stable dispatcher rather than modeled as successful returns.

All73 dependency hashes and the captured tool hash match disk. In-memory source recovery confirms the complete136-byte body, every immediate width and exact instruction boundary. Physical source checks found no existing overlap; parent independently assembles and compares the original bytes before assigning new credit. Existing dispatch/control dependencies receive no duplicate credit.

Stable SHA-256:

- tools/event_vm_field_branches.py: 36ae10c68b0d3c208008115f558ade8387c4302eb06aebde4b2ffab4113644bf
- data/event_vm_field_branches.json: 47a7c30f31e67c8d4018c9f71f80cd174f24574223766f3875ad0edab1499e03
- data/event_vm_field_branches.coverage.json: e18f593e5e7e73d92a6f10bb201b0d92786091a123d541c85cb3bb71c4cbc500

Indexed flag command48 is prepared in a separate module, with the literal F175 primitive continuation and the stable root flag model. It has not received proof or source credit from this capture.
