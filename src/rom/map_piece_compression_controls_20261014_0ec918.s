.setcpu "65816"
.segment "CODE"
.org $C918
map_control_0ec918:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
