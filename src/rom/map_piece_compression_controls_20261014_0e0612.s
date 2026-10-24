.setcpu "65816"
.segment "CODE"
.org $0612
map_control_0e0612:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
