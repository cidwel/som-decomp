.setcpu "65816"
.segment "CODE"
.org $1201
map_control_0c1201:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
