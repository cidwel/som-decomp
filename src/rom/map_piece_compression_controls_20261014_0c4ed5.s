.setcpu "65816"
.segment "CODE"
.org $4ED5
map_control_0c4ed5:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
