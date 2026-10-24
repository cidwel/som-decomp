.setcpu "65816"
.segment "CODE"
.org $1763
map_control_0e1763:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E7 ; previous-row copy count
