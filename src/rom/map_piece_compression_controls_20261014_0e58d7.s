.setcpu "65816"
.segment "CODE"
.org $58D7
map_control_0e58d7:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
