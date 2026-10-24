.setcpu "65816"
.segment "CODE"
.org $C08F
map_control_0dc08f:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
