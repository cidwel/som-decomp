.setcpu "65816"
.segment "CODE"
.org $0ED6
map_control_0e0ed6:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
