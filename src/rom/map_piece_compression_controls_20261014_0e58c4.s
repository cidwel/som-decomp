.setcpu "65816"
.segment "CODE"
.org $58C4
map_control_0e58c4:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
