.setcpu "65816"
.segment "CODE"
.org $78DE
map_control_0e78de:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
