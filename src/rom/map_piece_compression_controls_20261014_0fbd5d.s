.setcpu "65816"
.segment "CODE"
.org $BD5D
map_control_0fbd5d:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
