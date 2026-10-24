.setcpu "65816"
.segment "CODE"
.org $5EB9
map_control_0e5eb9:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
