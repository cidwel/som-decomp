.setcpu "65816"
.segment "CODE"
.org $59C1
map_control_0e59c1:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
