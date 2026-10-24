.setcpu "65816"
.segment "CODE"
.org $07B8
map_control_0e07b8:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
