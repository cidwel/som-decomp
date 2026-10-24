.setcpu "65816"
.segment "CODE"
.org $1855
map_control_0c1855:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $74 ; row-distance/count
