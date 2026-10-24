.setcpu "65816"
.segment "CODE"
.org $F2C2
map_control_0ef2c2:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
