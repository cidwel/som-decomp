.setcpu "65816"
.segment "CODE"
.org $5624
map_control_0d5624:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
