.setcpu "65816"
.segment "CODE"
.org $59CE
map_control_0f59ce:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
