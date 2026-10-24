.setcpu "65816"
.segment "CODE"
.org $6612
map_control_0d6612:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
