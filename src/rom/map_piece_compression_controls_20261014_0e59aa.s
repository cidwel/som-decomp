.setcpu "65816"
.segment "CODE"
.org $59AA
map_control_0e59aa:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
