.setcpu "65816"
.segment "CODE"
.org $74E9
map_control_0e74e9:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
