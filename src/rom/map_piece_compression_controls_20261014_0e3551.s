.setcpu "65816"
.segment "CODE"
.org $3551
map_control_0e3551:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count
