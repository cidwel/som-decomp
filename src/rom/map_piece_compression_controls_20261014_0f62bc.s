.setcpu "65816"
.segment "CODE"
.org $62BC
map_control_0f62bc:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
