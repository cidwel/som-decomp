.setcpu "65816"
.segment "CODE"
.org $2CCE
map_control_0e2cce:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
