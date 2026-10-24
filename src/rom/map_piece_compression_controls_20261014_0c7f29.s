.setcpu "65816"
.segment "CODE"
.org $7F29
map_control_0c7f29:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
