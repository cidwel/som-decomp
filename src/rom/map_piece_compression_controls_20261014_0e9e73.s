.setcpu "65816"
.segment "CODE"
.org $9E73
map_control_0e9e73:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
