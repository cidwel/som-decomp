.setcpu "65816"
.segment "CODE"
.org $07F0
map_control_0e07f0:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
