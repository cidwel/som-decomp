.setcpu "65816"
.segment "CODE"
.org $CC9C
map_control_0dcc9c:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
