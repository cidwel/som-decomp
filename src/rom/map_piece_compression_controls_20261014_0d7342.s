.setcpu "65816"
.segment "CODE"
.org $7342
map_control_0d7342:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
