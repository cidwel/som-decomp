.setcpu "65816"
.segment "CODE"
.org $DCE3
map_control_0ddce3:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
