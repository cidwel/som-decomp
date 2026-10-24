.setcpu "65816"
.segment "CODE"
.org $FEF6
map_control_0dfef6:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
