.setcpu "65816"
.segment "CODE"
.org $B596
map_control_0fb596:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
