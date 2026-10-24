# Native menu frame wait and brightness fades

C028FF/C02910/C02930 reconstruct 86 instruction bytes: wait for vblank,
conditional eight-edge fade-out, and nine-edge fade-in with the actual menu
sound request. The bus provides explicit4212 phases. The original executes
the installed RAM0100 JML C020A7 interrupt and native RTI at rising edges.

The comparison passed 24 complete calls. All 39 instruction starts were observed.
Counter, scroll and brightness wraps, initialization skip, sound/no-sound paths,
CPU state, memory and ordered peripheral writes match. Stack exclusion follows
the lowest address observed inside the actual interrupt as well as the caller.
No call hooks or synthetic return patches are used. This proves directed bus
inputs, not complete asynchronous console timing or rendered pixels.
