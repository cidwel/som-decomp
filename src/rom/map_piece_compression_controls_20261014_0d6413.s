.setcpu "65816"
.segment "CODE"
.org $6413
map_control_0d6413:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
