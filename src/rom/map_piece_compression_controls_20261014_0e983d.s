.setcpu "65816"
.segment "CODE"
.org $983D
map_control_0e983d:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
