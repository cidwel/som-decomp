.setcpu "65816"
.segment "CODE"
.org $9021
map_control_0e9021:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
