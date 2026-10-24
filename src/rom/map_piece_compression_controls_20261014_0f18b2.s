.setcpu "65816"
.segment "CODE"
.org $18B2
map_control_0f18b2:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
