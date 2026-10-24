.setcpu "65816"
.segment "CODE"
.org $92D4
map_control_0c92d4:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
