.setcpu "65816"
.segment "CODE"
.org $8C34
map_control_0d8c34:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
