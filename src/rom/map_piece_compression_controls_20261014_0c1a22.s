.setcpu "65816"
.segment "CODE"
.org $1A22
map_control_0c1a22:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
