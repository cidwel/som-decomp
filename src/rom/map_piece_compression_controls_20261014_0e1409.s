.setcpu "65816"
.segment "CODE"
.org $1409
map_control_0e1409:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
