.setcpu "65816"
.segment "CODE"
.org $01AC
map_control_0e01ac:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
