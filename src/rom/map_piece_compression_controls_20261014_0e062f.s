.setcpu "65816"
.segment "CODE"
.org $062F
map_control_0e062f:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
