.setcpu "65816"
.segment "CODE"
.org $CA67
map_control_0dca67:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
