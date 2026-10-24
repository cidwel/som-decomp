.setcpu "65816"
.segment "CODE"
.org $2358
map_control_0d2358:
    .byte $CC ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
