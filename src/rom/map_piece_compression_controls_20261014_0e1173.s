.setcpu "65816"
.segment "CODE"
.org $1173
map_control_0e1173:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
