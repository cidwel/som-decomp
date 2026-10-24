.setcpu "65816"
.segment "CODE"
.org $D4D1
map_control_0fd4d1:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
