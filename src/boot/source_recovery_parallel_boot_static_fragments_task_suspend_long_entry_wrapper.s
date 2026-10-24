; Exact static boot instruction fragment. Native execution and ABI unverified.
; Exact long wrapper of adopted A911 near suspend entry; no genuine long caller discovered in frozen aggregate/ROM pointer audit.
.setcpu "65816"
.smart
.a16
.i16
.segment "CODE"
.org $A90D
task_suspend_long_entry_wrapper:
    jsr $A911
    rtl
