.setcpu "65816"
.segment "CODE"
.org $231A
map_control_0d231a:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
