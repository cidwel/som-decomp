.setcpu "65816"
.segment "CODE"
.org $75DD
map_control_0d75dd:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
