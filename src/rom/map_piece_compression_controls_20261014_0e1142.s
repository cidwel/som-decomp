.setcpu "65816"
.segment "CODE"
.org $1142
map_control_0e1142:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
