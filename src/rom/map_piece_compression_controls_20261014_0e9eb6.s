.setcpu "65816"
.segment "CODE"
.org $9EB6
map_control_0e9eb6:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
