.setcpu "65816"
.segment "CODE"
.org $9918
map_control_0f9918:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
