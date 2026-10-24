.setcpu "65816"
.segment "CODE"
.org $8126
map_control_0d8126:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
