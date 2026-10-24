.setcpu "65816"
.segment "CODE"
.org $65DE
map_control_0f65de:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
