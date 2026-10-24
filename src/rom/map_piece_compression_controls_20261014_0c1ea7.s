.setcpu "65816"
.segment "CODE"
.org $1EA7
map_control_0c1ea7:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
