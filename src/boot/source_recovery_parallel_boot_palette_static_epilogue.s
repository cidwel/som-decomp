; Exact static palette-worker normal epilogue; native execution unobserved.
; Previous unconditional BRA D5AF returns D57C; stopped continuation starts D5B5.
.setcpu "65816"
.smart
.a16
.i16
.segment "CODE"
.org $D5B1
palette_worker_unexecuted_normal_epilogue:
    plb
    plp
    pld
    rtl
