.setcpu "65816"
.segment "CODE"
.org $7D67
map_control_0e7d67:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
