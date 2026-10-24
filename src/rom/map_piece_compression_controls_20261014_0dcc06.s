.setcpu "65816"
.segment "CODE"
.org $CC06
map_control_0dcc06:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
