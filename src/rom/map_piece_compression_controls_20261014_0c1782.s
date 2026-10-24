.setcpu "65816"
.segment "CODE"
.org $1782
map_control_0c1782:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
