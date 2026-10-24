.setcpu "65816"
.segment "CODE"
.org $58E3
map_control_0c58e3:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
