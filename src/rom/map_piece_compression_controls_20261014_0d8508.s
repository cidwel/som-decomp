.setcpu "65816"
.segment "CODE"
.org $8508
map_control_0d8508:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
