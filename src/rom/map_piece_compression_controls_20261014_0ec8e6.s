.setcpu "65816"
.segment "CODE"
.org $C8E6
map_control_0ec8e6:
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
