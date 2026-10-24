; Numeric ten-byte palette descriptor selected at 7ED481; resource C7B480.
.setcpu "65816"
.segment "RODATA"
.org $649C
entry_palette = $7ED54C
repeat_palette = $7ED5B5
cold_palette_task_descriptor:
    .faraddr entry_palette
    .byte $72 ; AAFF task priority
    .word .loword(repeat_palette) ; AA42 repeated near target
    .word $0100 ; copied descriptor word6, no allocation interpretation
    .word $0000 ; AAFF optional workspace bytes
