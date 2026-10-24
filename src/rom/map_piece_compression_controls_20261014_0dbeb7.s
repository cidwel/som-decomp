.setcpu "65816"
.segment "CODE"
.org $BEB7
map_control_0dbeb7:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
