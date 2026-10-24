.setcpu "65816"
.segment "CODE"
.org $F84B
map_control_0ff84b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
