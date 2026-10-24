.setcpu "65816"
.segment "CODE"
.org $434D
map_control_0d434d:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
