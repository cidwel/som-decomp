.setcpu "65816"
.segment "CODE"
.org $DBD7
map_control_0fdbd7:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
