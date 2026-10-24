.setcpu "65816"
.segment "CODE"
.org $C50F
map_control_0fc50f:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
