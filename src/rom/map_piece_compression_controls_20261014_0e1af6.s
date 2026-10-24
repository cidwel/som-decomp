.setcpu "65816"
.segment "CODE"
.org $1AF6
map_control_0e1af6:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
