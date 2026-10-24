.setcpu "65816"
.segment "CODE"
.org $330A
map_control_0e330a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
