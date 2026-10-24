.setcpu "65816"
.segment "CODE"
.org $2493
map_control_0d2493:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
