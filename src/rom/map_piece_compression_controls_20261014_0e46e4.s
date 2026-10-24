.setcpu "65816"
.segment "CODE"
.org $46E4
map_control_0e46e4:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
