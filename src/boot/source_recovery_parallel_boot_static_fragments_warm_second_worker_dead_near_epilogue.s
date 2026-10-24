; Exact static boot instruction fragment. Native execution and ABI unverified.
; Sequential epilogue behind unconditional BRA CB52→CB37; frozen ownCFG excludes fromCB2B entry.
.setcpu "65816"
.smart
.a16
.i16
.segment "CODE"
.org $CB54
warm_second_worker_dead_near_epilogue:
    plp
    pld
    rts
