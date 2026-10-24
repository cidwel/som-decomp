.setcpu "65816"
.segment "CODE"
.org $82C9
map_control_0c82c9:
    .byte $EC ; backreference distance high bits
    .byte $9A ; distance low bit/count
