.setcpu "65816"
.segment "CODE"
.org $8BB9
map_control_0d8bb9:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
