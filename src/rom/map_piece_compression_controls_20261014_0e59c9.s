.setcpu "65816"
.segment "CODE"
.org $59C9
map_control_0e59c9:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
