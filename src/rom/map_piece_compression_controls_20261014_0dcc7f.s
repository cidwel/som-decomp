.setcpu "65816"
.segment "CODE"
.org $CC7F
map_control_0dcc7f:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
