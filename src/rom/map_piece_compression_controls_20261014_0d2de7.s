.setcpu "65816"
.segment "CODE"
.org $2DE7
map_control_0d2de7:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
