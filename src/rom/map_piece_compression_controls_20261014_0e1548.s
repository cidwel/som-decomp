.setcpu "65816"
.segment "CODE"
.org $1548
map_control_0e1548:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
