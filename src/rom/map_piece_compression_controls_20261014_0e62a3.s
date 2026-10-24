.setcpu "65816"
.segment "CODE"
.org $62A3
map_control_0e62a3:
    .byte $E8 ; backreference distance high bits
    .byte $44 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $C5 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
