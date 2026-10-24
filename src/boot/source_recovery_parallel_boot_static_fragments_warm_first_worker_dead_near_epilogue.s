; Exact static boot instruction fragment. Native execution and ABI unverified.
; Sequential epilogue behind unconditional BRA BA1A→BA0C; frozen ownCFG excludes fromBA01 entry.
.setcpu "65816"
.smart
.a16
.i16
.segment "CODE"
.org $BA1C
warm_first_worker_dead_near_epilogue:
    pla
    pla
    plp
    pld
    rts
