.setcpu "65816"
.segment "CODE"
.org $1ED2
map_control_0d1ed2:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
