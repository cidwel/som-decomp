.setcpu "65816"
.segment "CODE"
.org $4292
map_control_0d4292:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
