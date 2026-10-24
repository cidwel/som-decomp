; Numeric ten-byte finalchild descriptor selected at 7ED2F3; resource C7B480.
.setcpu "65816"
.segment "RODATA"
.org $5EAA
entry_finalchild = $7E8DCD
repeat_finalchild = $7E8E94
cold_finalchild_task_descriptor:
    .faraddr entry_finalchild
    .byte $78 ; AAFF task priority
    .word .loword(repeat_finalchild) ; AA42 repeated near target
    .word $0100 ; copied descriptor word6, no allocation interpretation
    .word $0000 ; AAFF optional workspace bytes
