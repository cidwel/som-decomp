.setcpu "65816"
.segment "CODE"
.org $1CCC
map_control_0e1ccc:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
