; Source-selected window child atD318 AB88, decoded C7B480 resource.
.setcpu "65816"
.segment "RODATA"
.org $5EA0
window_child_entry = $7E8D1A
window_child_repeat = $7E8DA0
title_window_child_descriptor:
    .faraddr window_child_entry
    .byte $78 ; AAFF task priority
    .word .loword(window_child_repeat) ; AA42 repeated near target
    .word $0100 ; copied descriptor word6, no allocation interpretation
    .word $0000 ; AAFF optional workspace bytes
