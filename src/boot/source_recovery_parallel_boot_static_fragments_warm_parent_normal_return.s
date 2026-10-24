; Exact static boot instruction fragment. Native execution and ABI unverified.
; Normal continuation after actual JSR95E8, unreachable under frozen intact-frame loop contract; status16 handler instead starts9364.
.setcpu "65816"
.smart
.a16
.i16
.segment "CODE"
.org $9360
warm_parent_normal_return:
    plb
    plp
    pld
    rtl
