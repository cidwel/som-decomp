.setcpu "65816"
.segment "CODE"
.org $65F0
map_control_0e65f0:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
