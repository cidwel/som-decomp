.setcpu "65816"
.segment "CODE"
.org $1575
map_control_0e1575:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
