# Spare actor record selection and action cloning

C2A360 (63 bytes) and C2A39F (104 bytes) are complete dependencies of action command 05 in C1D942. The selector requires the negative direct-page ED flag, scans actor offsets A00,800,600 and accepts a zero E000 byte or a record outside the original coordinate limits. It skips the invoking actor. Coordinates 0120..FFDF horizontally or 0100..FFDF vertically trigger reuse; the remaining signed boundary intervals stay inside. It returns carry set for an accepted record, with Y its actor offset; the caller interprets that result.

The clone copies three exact field groups from source to destination: offsets 000..06B (108 bytes),070..085 (22 bytes),08C..1FF (372 bytes). The four-byte and six-byte gaps retain destination data. It then combines the source's high E08B nibble with the destination's low nibble, sets E030=FF, and clears E104,E100,E083,E084,E01C,E00A,E064,E062. Destination becomes X and Y. The readable model preserves forward MVN copying, its DB=7E result, unchanged MVN flags and the native final register/width effects. An identical source/destination is also covered without substituting snapshot copying.

Validation: 52 complete original calls, all 83 instruction starts observed. The scanner uses M8/X16,D0,DB7E and positive/negative ED flags, inactive/reused/caller-skipped/all-in-range records and coordinate boundaries. Cloning covers all six aligned source records into each of the three spare records in M8 and M16, X16, D0/0300/1234, incoming DB0/7E. Entire WRAM outside the observed temporary call stack, SRAM, VRAM, CGRAM, OAM, hardware and returned CPU context agree; no hooks or instruction replacements. The failed first smoke was a harness peripheral-class mismatch (plain CPU had no VRAM field); the PPU-capable harness then passed the directed clone and full52 capture. Native code and model were not relaxed to omit peripherals.

The outer action dispatcher C1D942 and its remaining program-step, movement, appearance and installation paths remain open. These two complete callee bodies receive instruction-source credit only after independent assembly matches the ROM; they do not represent completed actor AI.

Reproduction:

```sh
python3 tools/coverage_run.py "baserom.sfc" data/actor_action_spare_records_proof.coverage.json tools/actor_action_spare_records_proof.py --json data/actor_action_spare_records_proof.json
python3 tools/event_native_menu_source_audit.py "baserom.sfc" actor_action_spare_records
```

Frozen evidence SHA-256:

- `tools/actor_action_spare_records.py`: `5a6dd67bea0fed7de85fccbb8df22c977d93be2314b3d26251bd6de591228859`.
- `tools/actor_action_spare_records_proof.py`: `e669f418a18ebe5017b392da5a1f443320211951cb229bf1ac29c10de4df5b78`.
- `data/actor_action_spare_records_proof.json`: `e4425aa4f66b3a0c436540e498c7d55999ab45df55112ac9dd415f1726da1f08`.
- `data/actor_action_spare_records_proof.coverage.json`: `7b70ccb1df6e0287bbee243f878cc3cce061932c9379617b401345488cb4476d`.
- `data/actor_action_spare_records_audit.json`: `fae3a3cd9ff16444ed4c6dae66bfa8cfcd11d8bb39467b94806331b7b3819edf`.
