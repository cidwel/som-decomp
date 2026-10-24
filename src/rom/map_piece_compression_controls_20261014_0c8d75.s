.setcpu "65816"
.segment "CODE"
.org $8D75
map_control_0c8d75:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
