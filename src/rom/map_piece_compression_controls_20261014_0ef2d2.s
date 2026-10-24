.setcpu "65816"
.segment "CODE"
.org $F2D2
map_control_0ef2d2:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
