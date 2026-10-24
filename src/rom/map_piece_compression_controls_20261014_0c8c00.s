.setcpu "65816"
.segment "CODE"
.org $8C00
map_control_0c8c00:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
