.setcpu "65816"
.segment "CODE"
.org $65A6
map_control_0f65a6:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
