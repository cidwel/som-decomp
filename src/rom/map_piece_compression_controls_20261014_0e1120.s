.setcpu "65816"
.segment "CODE"
.org $1120
map_control_0e1120:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
