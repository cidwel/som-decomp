.setcpu "65816"
.segment "CODE"
.org $DBD7
map_control_0ddbd7:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
