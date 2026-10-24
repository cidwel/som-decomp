.setcpu "65816"
.segment "CODE"
.org $7135
map_control_0c7135:
    .byte $F1 ; progressive-copy count
    .byte $C6 ; same-value copy count/distance
