.setcpu "65816"
.segment "CODE"
.org $CA48
map_control_0dca48:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
