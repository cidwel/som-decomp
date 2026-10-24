; Exact static boot instruction fragment. Native execution and ABI unverified.
; Normal continuation after actual JSRBA01; callee repeats viaBRA BA1A→BA0C. Original status16 handler startsB96B.
.setcpu "65816"
.smart
.a16
.i16
.segment "CODE"
.org $B963
warm_first_worker_normal_return:
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rtl
