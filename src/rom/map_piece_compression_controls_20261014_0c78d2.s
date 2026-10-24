.setcpu "65816"
.segment "CODE"
.org $78D2
map_control_0c78d2:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
