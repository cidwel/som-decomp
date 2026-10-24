.setcpu "65816"
.segment "CODE"
.org $281F
map_control_0d281f:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
