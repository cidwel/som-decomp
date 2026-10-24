.setcpu "65816"
.segment "CODE"
.org $3541
map_control_0e3541:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
