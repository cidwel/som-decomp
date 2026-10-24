.setcpu "65816"
.segment "CODE"
.org $955A
map_control_0d955a:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
