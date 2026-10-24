# Indexed flag opcode48 and literal F175 continuation

`EventIndexedFlag` reconstructs C1F1CF/34. It reads the target flag ID from script byte2 and the source flag ID from byte3, combines the original operation operand's high nibble with the source flag's low nibble, advances the word script cursor by one, and executes the actual F175 continuation body. That body is translated literally from the stable root flag model after its six-byte header; it does not rerun F16F's LDY2/script read or replace any original instruction. Native Y3 remains intact. The containing F16F source already covers F175, so the primitive receives zero extra byte credit.

The new adapter composes the stable field-branch and flag families without modifying them. Its dispatcher routes42/43/48 and49..4E through real reconstructed handlers, while unresolved opcode dependencies remain explicit errors. Zero nibble results return with D1 advanced by exactly one; nonzero results advance by four total and resume the original dispatcher.

The first eight-call smoke and first full4,160-call capture pass unchanged. Coverage includes4,096 direct calls crossing all16 operation high nibbles and all256 source flag bytes, plus64 actual core-dispatch calls to opcode48. All256 target/source IDs appear, with alias,+1 and-1 relationships, varied target low/upper nibbles and ignored original operand low nibbles. Cursor4000/7FFC exercises normal addition and signed overflow. Native results confirm only the two actual pointer increments,1 and4.

Coverage records97 PC/M/X states. All randomized WRAM outside only observed stack writes, full returned CPU/context and video/DMA/peripheral state agree. Inputs use D0/DB7E,M8/X8,binary arithmetic and all16 CNZV combinations. Nonzero cases execute actual END continuation; zero cases execute the actual primitive return. No instruction hooks, false header, artificial success or interrupts are installed. This proves the indexed operation family rather than the complete event VM.

All75 dependency hashes and captured tool hash match disk. In-memory source recovery succeeds for all34 bytes with exact boundaries and unambiguous immediate widths. Parent independently assembles and compares the new header body; previously recovered flag primitives and dispatcher sources receive no duplicate credit.

Stable SHA-256:

- tools/event_vm_indexed_flag.py: 01feb5073fa0759b334a5a5cd9f8025c734bff591db6b2e78f6e906d61f45f90
- data/event_vm_indexed_flag.json: 821f82f081caf8ea18adcbd64d4295d48600a2f075926ab7e786673ab3d57d47
- data/event_vm_indexed_flag.coverage.json: b43ddb9e5e3afd7d81f907a31748787726a9a9caf1c685a9d13aededc6e7d6cf

Numeric event jumps10..17 and the full numeric-request CPU contract are the next prepared family, separately unverified until its original comparison.
