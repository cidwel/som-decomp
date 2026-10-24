.setcpu "65816"
.segment "CODE"
.org $FDD7
map_control_0dfdd7:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
