.setcpu "65816"
.segment "CODE"
.org $6E0B
map_control_0c6e0b:
    .byte $F1 ; progressive-copy count
    .byte $C4 ; same-value copy count/distance
