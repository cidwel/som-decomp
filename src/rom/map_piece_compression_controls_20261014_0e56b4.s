.setcpu "65816"
.segment "CODE"
.org $56B4
map_control_0e56b4:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
