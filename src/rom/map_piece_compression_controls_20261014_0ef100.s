.setcpu "65816"
.segment "CODE"
.org $F100
map_control_0ef100:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
