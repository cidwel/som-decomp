.setcpu "65816"
.segment "CODE"
.org $F1D5
map_control_0ef1d5:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7E ; row-distance/count
