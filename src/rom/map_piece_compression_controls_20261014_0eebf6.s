.setcpu "65816"
.segment "CODE"
.org $EBF6
map_control_0eebf6:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
