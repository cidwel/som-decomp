.setcpu "65816"
.segment "CODE"
.org $23A9
map_control_0e23a9:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
