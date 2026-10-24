.setcpu "65816"
.segment "CODE"
.org $7079
map_control_0c7079:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
