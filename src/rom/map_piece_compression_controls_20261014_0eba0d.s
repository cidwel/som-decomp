.setcpu "65816"
.segment "CODE"
.org $BA0D
map_control_0eba0d:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
