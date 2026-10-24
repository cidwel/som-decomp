.setcpu "65816"
.segment "CODE"
.org $C465
map_control_0ec465:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
