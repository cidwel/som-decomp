.setcpu "65816"
.segment "CODE"
.org $07D2
map_control_0e07d2:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
