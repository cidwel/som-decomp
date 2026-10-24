.setcpu "65816"
.segment "CODE"
.org $6681
map_control_0c6681:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count
