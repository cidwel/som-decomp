.setcpu "65816"
.segment "CODE"
.org $8630
map_control_0e8630:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
