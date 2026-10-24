.setcpu "65816"
.segment "CODE"
.org $7BA7
map_control_0c7ba7:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
