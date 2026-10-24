.setcpu "65816"
.segment "CODE"
.org $7D20
map_control_0d7d20:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
