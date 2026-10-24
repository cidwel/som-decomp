.setcpu "65816"
.segment "CODE"
.org $2DC7
map_control_0e2dc7:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
