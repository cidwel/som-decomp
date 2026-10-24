.setcpu "65816"
.segment "CODE"
.org $68B4
map_control_0e68b4:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
