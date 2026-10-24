.setcpu "65816"
.segment "CODE"
.org $18F7
map_control_0e18f7:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
