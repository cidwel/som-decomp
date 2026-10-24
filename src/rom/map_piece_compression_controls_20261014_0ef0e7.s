.setcpu "65816"
.segment "CODE"
.org $F0E7
map_control_0ef0e7:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
