.setcpu "65816"
.segment "CODE"
.org $59A0
map_control_0e59a0:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
