.setcpu "65816"
.segment "CODE"
.org $1ABC
map_control_0c1abc:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
