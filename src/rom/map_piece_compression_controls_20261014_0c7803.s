.setcpu "65816"
.segment "CODE"
.org $7803
map_control_0c7803:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
