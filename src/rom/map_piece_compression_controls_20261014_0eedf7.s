.setcpu "65816"
.segment "CODE"
.org $EDF7
map_control_0eedf7:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
