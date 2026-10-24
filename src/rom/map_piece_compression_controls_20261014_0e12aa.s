.setcpu "65816"
.segment "CODE"
.org $12AA
map_control_0e12aa:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
