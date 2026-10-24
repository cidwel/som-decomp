.setcpu "65816"
.segment "CODE"
.org $ACC1
map_control_0eacc1:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
