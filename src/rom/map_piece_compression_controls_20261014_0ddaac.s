.setcpu "65816"
.segment "CODE"
.org $DAAC
map_control_0ddaac:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
