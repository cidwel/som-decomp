; Exact static boot instruction fragment. Native execution and ABI unverified.
; Fallthrough release after B840 shared-counter success loop; conditional noIRQ/DB7F invariant excludes loop termination. No synthetic exit.
.setcpu "65816"
.smart
.a16
.i16
.segment "CODE"
.org $B8C1
permutation_unreached_heap_release:
    ldx $05
    jsr $B0D6
