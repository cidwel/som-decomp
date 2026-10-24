.setcpu "65816"
.segment "CODE"
.org $288D
map_control_0e288d:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
