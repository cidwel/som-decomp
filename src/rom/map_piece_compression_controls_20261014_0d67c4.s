.setcpu "65816"
.segment "CODE"
.org $67C4
map_control_0d67c4:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
