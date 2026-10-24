.setcpu "65816"
.segment "CODE"
.org $927B
map_control_0e927b:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
