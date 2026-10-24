.setcpu "65816"
.segment "CODE"
.org $62AA
map_control_0d62aa:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
