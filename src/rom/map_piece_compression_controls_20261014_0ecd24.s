.setcpu "65816"
.segment "CODE"
.org $CD24
map_control_0ecd24:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
