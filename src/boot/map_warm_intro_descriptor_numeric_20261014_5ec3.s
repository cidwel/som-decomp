; Authentic warm AF28/AF2B intro task descriptor, resourceC7B480.
.setcpu "65816"
.segment "RODATA"
.org $5EC3
warm_intro_entry = $7E934F
warm_intro_repeat = $7E9364
warm_intro_task_descriptor:
    .faraddr warm_intro_entry
    .byte $80 ; AAFF priority
    .word .loword(warm_intro_repeat) ; AA42 repeated near target
    .word $0100 ; copied word6, no allocation interpretation
    .word $0000 ; AAFF optional workspace size
