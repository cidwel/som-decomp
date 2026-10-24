.setcpu "65816"
.segment "CODE"
.org $9E95
map_control_0e9e95:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
