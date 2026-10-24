.setcpu "65816"
.segment "CODE"
.org $94C6
map_control_0f94c6:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
