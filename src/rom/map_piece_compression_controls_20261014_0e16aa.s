.setcpu "65816"
.segment "CODE"
.org $16AA
map_control_0e16aa:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $61 ; distance low bit/count
