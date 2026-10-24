.setcpu "65816"
.segment "CODE"
.org $9CCB
map_control_0e9ccb:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
