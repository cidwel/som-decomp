.setcpu "65816"
.segment "CODE"
.org $F2C7
map_control_0ef2c7:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4C ; row-distance/count
