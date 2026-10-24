.setcpu "65816"
.segment "CODE"
.org $1453
map_control_0c1453:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
