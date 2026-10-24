.setcpu "65816"
.segment "CODE"
.org $59E8
map_control_0d59e8:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
