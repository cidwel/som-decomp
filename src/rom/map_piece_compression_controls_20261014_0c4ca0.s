.setcpu "65816"
.segment "CODE"
.org $4CA0
map_control_0c4ca0:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
