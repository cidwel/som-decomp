; Numeric ten-byte image descriptor selected at 7ED249; resource C7B480.
.setcpu "65816"
.segment "RODATA"
.org $5F12
entry_image = $7E968D
repeat_image = $7E9675
cold_image_task_descriptor:
    .faraddr entry_image
    .byte $90 ; AAFF task priority
    .word .loword(repeat_image) ; AA42 repeated near target
    .word $0100 ; copied descriptor word6, no allocation interpretation
    .word $0000 ; AAFF optional workspace bytes
