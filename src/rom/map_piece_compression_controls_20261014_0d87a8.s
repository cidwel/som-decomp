.setcpu "65816"
.segment "CODE"
.org $87A8
map_control_0d87a8:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
