.setcpu "65816"
.segment "CODE"
.org $0832
map_control_0e0832:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
