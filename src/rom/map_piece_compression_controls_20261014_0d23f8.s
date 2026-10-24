.setcpu "65816"
.segment "CODE"
.org $23F8
map_control_0d23f8:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
