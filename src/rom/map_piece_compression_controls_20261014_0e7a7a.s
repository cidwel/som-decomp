.setcpu "65816"
.segment "CODE"
.org $7A7A
map_control_0e7a7a:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
