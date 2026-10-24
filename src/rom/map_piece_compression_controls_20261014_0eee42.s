.setcpu "65816"
.segment "CODE"
.org $EE42
map_control_0eee42:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
