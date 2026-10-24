.setcpu "65816"
.segment "CODE"
.org $1943
map_control_0e1943:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
