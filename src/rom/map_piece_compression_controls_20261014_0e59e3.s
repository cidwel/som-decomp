.setcpu "65816"
.segment "CODE"
.org $59E3
map_control_0e59e3:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
