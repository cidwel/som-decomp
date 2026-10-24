.setcpu "65816"
.segment "CODE"
.org $AAC9
map_control_0eaac9:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
