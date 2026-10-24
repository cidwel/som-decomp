.setcpu "65816"
.segment "CODE"
.org $DA0C
map_control_0dda0c:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
