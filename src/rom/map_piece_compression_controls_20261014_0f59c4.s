.setcpu "65816"
.segment "CODE"
.org $59C4
map_control_0f59c4:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
