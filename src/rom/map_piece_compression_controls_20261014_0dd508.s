.setcpu "65816"
.segment "CODE"
.org $D508
map_control_0dd508:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
