.setcpu "65816"
.segment "CODE"
.org $3396
map_control_0c3396:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
