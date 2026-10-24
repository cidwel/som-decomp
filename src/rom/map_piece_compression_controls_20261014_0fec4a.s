.setcpu "65816"
.segment "CODE"
.org $EC4A
map_control_0fec4a:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
