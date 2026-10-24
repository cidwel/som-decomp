.setcpu "65816"
.segment "CODE"
.org $1611
map_control_0e1611:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
