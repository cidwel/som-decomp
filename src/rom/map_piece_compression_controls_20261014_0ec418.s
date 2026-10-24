.setcpu "65816"
.segment "CODE"
.org $C418
map_control_0ec418:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
