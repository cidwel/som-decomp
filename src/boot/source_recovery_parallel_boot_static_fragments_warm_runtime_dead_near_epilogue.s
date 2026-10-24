; Exact static boot instruction fragment. Native execution and ABI unverified.
; Sequential epilogue after unconditional BRA9644→95F8; frozen ownCFG excludes from95E8 entry.
.setcpu "65816"
.smart
.a16
.i16
.segment "CODE"
.org $9646
warm_runtime_dead_near_epilogue:
    pla
    pla
    plp
    pld
    rts
