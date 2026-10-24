.setcpu "65816"
.segment "CODE"
.org $41A4
map_control_0e41a4:
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
