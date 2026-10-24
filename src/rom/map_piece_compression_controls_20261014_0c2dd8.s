.setcpu "65816"
.segment "CODE"
.org $2DD8
map_control_0c2dd8:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
