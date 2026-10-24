.setcpu "65816"
.segment "CODE"
.org $4262
map_control_0d4262:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
