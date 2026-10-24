.setcpu "65816"
.segment "CODE"
.org $1EDD
map_control_0e1edd:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
