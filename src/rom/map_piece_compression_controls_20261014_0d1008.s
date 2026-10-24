.setcpu "65816"
.segment "CODE"
.org $1008
map_control_0d1008:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
