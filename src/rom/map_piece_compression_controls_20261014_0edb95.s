.setcpu "65816"
.segment "CODE"
.org $DB95
map_control_0edb95:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
