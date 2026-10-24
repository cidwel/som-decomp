.setcpu "65816"
.segment "CODE"
.org $FC59
map_control_0efc59:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
