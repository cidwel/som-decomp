.setcpu "65816"
.segment "CODE"
.org $383D
map_control_0f383d:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
