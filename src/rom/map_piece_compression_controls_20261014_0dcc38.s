.setcpu "65816"
.segment "CODE"
.org $CC38
map_control_0dcc38:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
