.setcpu "65816"
.segment "CODE"
.org $23F0
map_control_0d23f0:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
