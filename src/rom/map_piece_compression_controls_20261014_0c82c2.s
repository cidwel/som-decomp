.setcpu "65816"
.segment "CODE"
.org $82C2
map_control_0c82c2:
    .byte $EC ; backreference distance high bits
    .byte $CD ; distance low bit/count
