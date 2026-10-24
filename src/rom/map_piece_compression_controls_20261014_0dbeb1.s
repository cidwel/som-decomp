.setcpu "65816"
.segment "CODE"
.org $BEB1
map_control_0dbeb1:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
