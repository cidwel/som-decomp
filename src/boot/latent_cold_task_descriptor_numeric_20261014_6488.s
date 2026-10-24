; Numeric ten-byte main descriptor selected at 7EAF13; resource C7B480.
.setcpu "65816"
.segment "RODATA"
.org $6488
entry_main = $7ECD50
repeat_main = $7ED3EA
cold_main_task_descriptor:
    .faraddr entry_main
    .byte $70 ; AAFF task priority
    .word .loword(repeat_main) ; AA42 repeated near target
    .word $0100 ; copied descriptor word6, no allocation interpretation
    .word $0000 ; AAFF optional workspace bytes
