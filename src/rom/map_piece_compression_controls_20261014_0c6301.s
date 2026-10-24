.setcpu "65816"
.segment "CODE"
.org $6301
map_control_0c6301:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
