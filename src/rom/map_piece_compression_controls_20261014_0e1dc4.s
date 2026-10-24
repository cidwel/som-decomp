.setcpu "65816"
.segment "CODE"
.org $1DC4
map_control_0e1dc4:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
