.setcpu "65816"
.segment "CODE"
.org $4F07
map_control_0c4f07:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
