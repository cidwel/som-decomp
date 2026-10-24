.setcpu "65816"
.segment "CODE"
.org $84F3
map_control_0e84f3:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
