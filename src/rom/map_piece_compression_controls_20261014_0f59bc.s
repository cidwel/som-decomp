.setcpu "65816"
.segment "CODE"
.org $59BC
map_control_0f59bc:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
