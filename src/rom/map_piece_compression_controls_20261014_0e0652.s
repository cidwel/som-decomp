.setcpu "65816"
.segment "CODE"
.org $0652
map_control_0e0652:
    .byte $C7 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
