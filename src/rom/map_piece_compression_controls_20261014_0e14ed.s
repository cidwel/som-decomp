.setcpu "65816"
.segment "CODE"
.org $14ED
map_control_0e14ed:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
