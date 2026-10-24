.setcpu "65816"
.segment "CODE"
.org $CC69
map_control_0dcc69:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
