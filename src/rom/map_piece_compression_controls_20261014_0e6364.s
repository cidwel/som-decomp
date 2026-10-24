.setcpu "65816"
.segment "CODE"
.org $6364
map_control_0e6364:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
