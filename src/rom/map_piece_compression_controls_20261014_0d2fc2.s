.setcpu "65816"
.segment "CODE"
.org $2FC2
map_control_0d2fc2:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
