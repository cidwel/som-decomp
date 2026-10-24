; Exact static boot instruction fragment. Native execution and ABI unverified.
; Normal continuation after actual JSRCB2B; callee repeats viaBRA CB52→CB37. Original status16 handler startsCA56.
.setcpu "65816"
.smart
.a16
.i16
.segment "CODE"
.org $CA52
warm_second_worker_normal_return:
    plb
    plp
    pld
    rtl
