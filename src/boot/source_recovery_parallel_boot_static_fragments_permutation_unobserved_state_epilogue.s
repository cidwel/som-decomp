; Exact static boot instruction fragment. Native execution and ABI unverified.
; BRK atB8CA saves returnB8CC, but actual vector00FFE6→00FFFF has no demonstrated RTI/handler return. Also no success loop termination.
.setcpu "65816"
.smart
.a16
.i16
.segment "CODE"
.org $B8CC
permutation_unobserved_state_epilogue:
    plp
    pld
    rts
