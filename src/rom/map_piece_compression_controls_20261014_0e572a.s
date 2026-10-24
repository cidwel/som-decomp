.setcpu "65816"
.segment "CODE"
.org $572A
map_control_0e572a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
