.setcpu "65816"
.segment "CODE"
.org $BF16
map_control_0dbf16:
    .byte $F1 ; progressive-copy count
