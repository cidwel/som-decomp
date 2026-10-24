.setcpu "65816"
.segment "CODE"
.org $2CD1
map_control_0e2cd1:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
