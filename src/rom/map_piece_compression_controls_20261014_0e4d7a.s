.setcpu "65816"
.segment "CODE"
.org $4D7A
map_control_0e4d7a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
