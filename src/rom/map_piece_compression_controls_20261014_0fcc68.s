.setcpu "65816"
.segment "CODE"
.org $CC68
map_control_0fcc68:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
