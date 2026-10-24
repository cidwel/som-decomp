.setcpu "65816"
.segment "CODE"
.org $DBD4
map_control_0ddbd4:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
