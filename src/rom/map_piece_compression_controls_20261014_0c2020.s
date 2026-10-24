.setcpu "65816"
.segment "CODE"
.org $2020
map_control_0c2020:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
