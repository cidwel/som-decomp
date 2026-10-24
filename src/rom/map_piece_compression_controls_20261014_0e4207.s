.setcpu "65816"
.segment "CODE"
.org $4207
map_control_0e4207:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
