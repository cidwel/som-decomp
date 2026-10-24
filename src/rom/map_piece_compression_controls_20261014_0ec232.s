.setcpu "65816"
.segment "CODE"
.org $C232
map_control_0ec232:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
