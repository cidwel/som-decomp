# Public party services

Two public services add110instruction bytes: C20363 checks contact between the first three active boss actors E600/E800/EA00 and the three party members through the complete C2125B helper. It saves Y around each contact call, so the outer actor loop does not inherit the helper's hero index. C20396 scans relative slots3..5, setting control byte61 to1 when control byte60 equals40 and animation byte180 is57..7F. It preserves other control values.

Their public jumps C20015/C20018 add six bytes; the missing C2000F initialization alias adds three, reusing the frozen complete public initializer. The new119-byte family has a26-case prepared checker with initialization/retry, actor activation low byte, height/contact gates, control/animation thresholds and original caller context restoration. Model-only preflight passes. Actual contact helper execution is composed directly because its existing class exports `party()`, not `run()`.

The first original capture stopped at animation case15: high accumulator B had contaminated carry in three model byte comparisons, suppressing legitimate control61 publication. Those new CMP operands now explicitly use A&FF, retaining the original expectations. Directed case15 passed, then the complete26call capture passed. All68 own instruction starts and339PC/M/X states are covered;137 dependency hashes were revalidated. Final evidence is in `data/boss_public_party_services_audit.json`; model/checker/report/coverage are frozen for source recovery.

Contact/animation services normalize D0200/DB7E/M16/X16 internally and restore M8/M16/X8/X16 caller state in directed contexts. Initialization alias requires M16 because of its original underlying PHA/PLA contract. No full frame scheduling is claimed.
