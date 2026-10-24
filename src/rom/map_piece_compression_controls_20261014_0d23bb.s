.setcpu "65816"
.segment "CODE"
.org $23BB
map_control_0d23bb:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
