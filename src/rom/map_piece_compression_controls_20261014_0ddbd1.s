.setcpu "65816"
.segment "CODE"
.org $DBD1
map_control_0ddbd1:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
